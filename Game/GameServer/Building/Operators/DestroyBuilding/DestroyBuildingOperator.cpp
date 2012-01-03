// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <Game/GameServer/Building/Operators/DestroyBuilding/DestroyBuildingOperator.hpp>
#include <Game/GameServer/Configuration/Configurator/Building/IBuilding.hpp>
#include <Game/GameServer/Resource/Helpers.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Building
{

DestroyBuildingOperator::DestroyBuildingOperator(
    IContextShrPtr                   const a_context,
    IBuildingPersistenceFacadeShrPtr       a_building_persistence_facade,
    IResourcePersistenceFacadeShrPtr       a_resource_persistence_facade
)
    : m_context(a_context),
      m_building_persistence_facade(a_building_persistence_facade),
      m_resource_persistence_facade(a_resource_persistence_facade)
{
}

DestroyBuildingOperatorExitCode DestroyBuildingOperator::destroyBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
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
        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(a_transaction, a_id_holder);

        // Get total cost.
        std::map<IKey, GameServer::Resource::Volume> const & cost_map =
            m_context->getConfiguratorBuilding()->getBuilding(a_key)->getCostsToDestroy();

        // FIXME: Workaround to get the ResourceWithVolumeMap.
        ResourceWithVolumeMap cost;

        for (std::map<IKey, Volume>::const_iterator it = cost_map.begin();it != cost_map.end(); ++it)
        {
            ResourceWithVolumeShrPtr resource(new ResourceWithVolume(m_context, it->first, it->second));

            cost[it->first] = resource;
        }

        // Multiply total cost.
        cost = multiply(m_context, cost, a_volume);

        // Verify if there is enough resources.
        if (!isFirstGreaterOrEqual(resource_map, cost))
        {
            return DestroyBuildingOperatorExitCode(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Subtract the resources.
        bool const result_subtract_resource =
            m_resource_persistence_facade->subtractResources(a_transaction, a_id_holder, cost);

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
