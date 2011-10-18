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

#include "EngageHumanOperator.hpp"

#include "../../../Building/BuildingToHumanTranslator.hpp"
#include "../../HumanToBuildingTranslator.hpp"

using namespace GameServer::Building;
using namespace GameServer::Common;
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
    ICostManagerShrPtr               a_cost_manager,
    IHumanPersistenceFacadeShrPtr    a_human_persistence_facade,
    IPropertyManagerShrPtr           a_property_manager,
    IResourceManagerShrPtr           a_resource_manager
)
    : m_building_persistence_facade(a_building_persistence_facade),
      m_cost_manager(a_cost_manager),
      m_human_persistence_facade(a_human_persistence_facade),
      m_property_manager(a_property_manager),
      m_resource_manager(a_resource_manager)
{
}

/**
 * TODO: Check if holder exists.
 */
EngageHumanOperatorExitCode EngageHumanOperator::engageHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
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
        ResourceSet resource_set = m_resource_manager->getResources(a_transaction, a_id_holder);

        // Get total cost.
        ResourceSet cost = m_cost_manager->getCost(a_transaction, a_key.toHash(), ID_COST_TYPE_HUMAN_ENGAGE);

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
        bool const result_subtract_resource = m_resource_manager->subtractResourceSet(a_transaction, a_id_holder, cost);

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
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    // Verify space in buildings.
    HumanToBuildingTranslator translator;
    BuildingShrPtr building = translator.getPlaceOfWork(a_key);
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
        IDHumanVec humans = BuildingToHumanTranslator::getHumansHostedForWork(building->getKey());

        // The building is a place of work for at least one human.
        BOOST_ASSERT(!humans.empty());

        // A sum of humans.
        Volume sum(0);

        // Get humans engaged in buildings.
        for (IDHumanVec::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // Get a human by identifier of a human.
            HumanWithVolumeMap map = m_human_persistence_facade->getHumans(a_transaction, a_id_holder, *it);

            // Calculate humans.
            for (HumanWithVolumeMap::const_iterator it = map.begin(); it != map.end(); ++it)
            {
                sum += it->second->getVolume();
            }
        }

        // Check if there is enough place.
        {
            // Get building's capacity.
            PropertyIntegerShrPtr capacity =
                // TODO: Fast and clean getKey().toHash() improvement by a shortcut.
                m_property_manager->getPropertyInteger(a_transaction, building->getKey().toHash(), ID_PROPERTY_BUILDING_CAPACITY);

            // Check if there is enough capacity.
            if (building_with_volume->getVolume() * capacity->getValue() - sum < a_volume)
            {
                return false;
            }
        }
    }

    return true;
}

bool EngageHumanOperator::verifyEngageable(
    ITransactionShrPtr         a_transaction,
    Key                const & a_key
) const
{
    // Check if human is engageable.
    PropertyBooleanShrPtr engageable =
        m_property_manager->getPropertyBoolean(a_transaction, a_key.toHash(), ID_PROPERTY_HUMAN_ENGAGEABLE);

    return engageable->getValue();
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
