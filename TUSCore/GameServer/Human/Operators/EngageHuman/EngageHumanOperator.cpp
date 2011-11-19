// Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include "../../../Building/BuildingToHumanTranslator.hpp"
#include "../../HumanToBuildingTranslator.hpp"
#include "EngageHumanOperator.hpp"
#include <GameServer/Configuration/Configurator/Human/ConfiguratorHuman.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Cost;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Human
{

EngageHumanOperator::EngageHumanOperator(
    IBuildingPersistenceFacadeShrPtr a_building_persistence_facade,
    ICostPersistenceFacadeShrPtr     a_cost_persistence_facade,
    IHumanPersistenceFacadeShrPtr    a_human_persistence_facade,
    IPropertyPersistenceFacadeShrPtr a_property_persistence_facade,
    IResourcePersistenceFacadeShrPtr a_resource_persistence_facade
)
    : m_building_persistence_facade(a_building_persistence_facade),
      m_cost_persistence_facade(a_cost_persistence_facade),
      m_human_persistence_facade(a_human_persistence_facade),
      m_property_persistence_facade(a_property_persistence_facade),
      m_resource_persistence_facade(a_resource_persistence_facade)
{
}

/**
 * TODO: Check if holder exists.
 */
EngageHumanOperatorExitCode EngageHumanOperator::engageHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IHumanKey          const & a_key,
    Volume             const & a_volume
) const
{
    try
    {
        // Trying to engage zero humans.
        if (a_volume == 0)
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_ENGAGE_ZERO_HUMANS);
        }

        // Human is not engageable.
        if (!verifyEngageable(a_transaction, a_key))
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_ENGAGEABLE);
        }

        // There are not enough jobless.
        if (!verifyJobless(a_transaction, a_id_holder, a_volume))
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS);
        }

        // Get available resources.
        ResourceSet resource_set = m_resource_persistence_facade->getResources(a_transaction, a_id_holder);

        // Get total cost.
        ResourceSet cost = m_cost_persistence_facade->getCost(a_transaction, a_key, ID_COST_TYPE_HUMAN_ENGAGE);

        // Multiply total cost.
        cost *= a_volume;

        // Check if there is enough resources.
        if (!(resource_set >= cost))
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Verifies if all possible dependencies on buildings are fulfilled.
        if (!verifyDependencyOfEngagementOnBuilding(a_transaction, a_id_holder, a_key, a_volume))
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS);
        }

        // Subtract the resources.
        bool const result_subtract_resource =
            m_resource_persistence_facade->subtractResourceSet(a_transaction, a_id_holder, cost);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough resources and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_resource)
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME);
        }

        // Subtract the jobless.
        bool const result_subtract_human =
            m_human_persistence_facade->subtractHuman(a_transaction, a_id_holder, KEY_WORKER_JOBLESS_NOVICE, a_volume);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough jobless and trying to subtract them.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_human)
        {
            return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_JOBLESS_MISSING_IN_THE_MEANTIME);
        }

        // Add the humans.
        m_human_persistence_facade->addHuman(a_transaction, a_id_holder, a_key, a_volume);

        // Everything went fine.
        return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED);
    }
    catch (...)
    {
        return EngageHumanOperatorExitCode(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

bool EngageHumanOperator::verifyDependencyOfEngagementOnBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IHumanKey          const & a_key,
    Volume             const & a_volume
) const
{
    // Verify space in buildings.
    HumanToBuildingTranslator translator;
    IBuildingShrPtr building = translator.getPlaceOfWork(a_key);
    if (building)
    {
        // Get available buildings.
        BuildingWithVolumeShrPtr building_with_volume =
            m_building_persistence_facade->getBuilding(a_transaction, a_id_holder, building->getKey());

        // Building does not exist.
        if (!building_with_volume)
        {
            return false;
        }

        // Get a vector of identifiers of a human to check if building is a place of work for some humans.
        KeyVec humans = BuildingToHumanTranslator::getHumansHostedForWork(building->getKey());

        // The building is a place of work for at least one human.
        BOOST_ASSERT(!humans.empty());

        // A sum of humans.
        Volume sum(0);

        // Get humans engaged in buildings.
        for (KeyVec::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // Get a human by identifier of a human.
            HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(a_transaction, a_id_holder, *it);

            if (human)
            {
                sum += human->getVolume();
            }
        }

        // Check if there is enough place.
        {
            // Check if there is enough capacity.
            if (building_with_volume->getVolume() * building_with_volume->getBuilding()->getCapacity() - sum < a_volume)
            {
                return false;
            }
        }
    }

    return true;
}

bool EngageHumanOperator::verifyEngageable(
    ITransactionShrPtr         a_transaction,
    IHumanKey          const & a_key
) const
{
    IHumanShrPtr human = CONFIGURATOR_HUMAN.getHuman(a_key);

    BOOST_ASSERT(human);

    return human->isEngageable();
}

bool EngageHumanOperator::verifyJobless(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Volume             const & a_volume
) const
{
    // Get the jobless.
    HumanWithVolumeShrPtr jobless =
        m_human_persistence_facade->getHuman(a_transaction, a_id_holder, KEY_WORKER_JOBLESS_NOVICE);

    // There are no jobless.
    if (!jobless)
    {
        return false;
    }

    return (jobless->getVolume() >= a_volume);
}

} // namespace Human
} // namespace GameServer
