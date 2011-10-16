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

#include "DestroyBuildingOperator.hpp"

using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Building
{

DestroyBuildingOperator::DestroyBuildingOperator(
    IBuildingPersistenceFacadeShrPtr a_building_persistence_facade,
    ICostManagerShrPtr               a_cost_manager,
    IResourceManagerShrPtr           a_resource_manager
)
    : m_building_persistence_facade(a_building_persistence_facade),
      m_cost_manager(a_cost_manager),
      m_resource_manager(a_resource_manager)
{
}

DestroyBuildingOperatorExitCode DestroyBuildingOperator::destroyBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    try
    {
        // Trying to destroy zero buildings.
        if (a_volume == 0)
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS);
        }

        // Verify if the building exists.
        BuildingWithVolumeShrPtr building_with_volume = m_building_persistence_facade->getBuilding(a_transaction, a_id_holder, a_key);

        // The building does not exist.
        if (!building_with_volume)
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS);
        }

        // Verify if there is enough buildings.
        if (building_with_volume->getVolume() < a_volume)
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS);
        }

        // Get available resources.
        ResourceSet resource_set = m_resource_manager->getResources(a_transaction, a_id_holder);

        // Get total cost.
        ResourceSet cost = m_cost_manager->getCost(a_transaction, a_key.toHash(), ID_COST_TYPE_BUILDING_DESTROY);

        // Multiply total cost.
        cost *= a_volume;

        // Verify if there is enough resources.
        if (!(resource_set >= cost))
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Subtract the resources.
        bool const result_subtract_resource = m_resource_manager->subtractResourceSet(a_transaction, a_id_holder, cost);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough resources and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_resource)
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME);
        }

        // Subtract the building.
        bool const result_subtract_building =
            m_building_persistence_facade->subtractBuilding(a_transaction, a_id_holder, a_key, a_volume);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough buildings and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_building)
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDINGS_MISSING_IN_THE_MEANTIME);
        }

        // TODO: Behaviour dismiss humans.

        // Everything went fine.
        return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED);
    }
    catch (...)
    {
        return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Building
} // namespace GameServer
