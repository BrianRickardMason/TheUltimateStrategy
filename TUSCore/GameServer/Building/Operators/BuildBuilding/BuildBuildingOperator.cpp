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

#include "BuildBuildingOperator.hpp"

using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Building
{

BuildBuildingOperator::BuildBuildingOperator(
    IBuildingPersistenceFacadeShrPtr a_building_persistence_facade,
    ICostPersistenceFacadeShrPtr     a_cost_persistence_facade,
    IResourcePersistenceFacadeShrPtr a_resource_persitence_facade
)
    : m_building_persistence_facade(a_building_persistence_facade),
      m_cost_persistence_facade(a_cost_persistence_facade),
      m_resource_persistence_facade(a_resource_persitence_facade)
{
}

BuildBuildingOperatorExitCode BuildBuildingOperator::buildBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    try
    {
        // Trying to build zero buildings.
        if (a_volume == 0)
        {
            return BuildBuildingOperatorExitCode(BUILD_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_BUILD_ZERO_BUILDINGS);
        }

        // Get available resources.
        ResourceSet resource_set = m_resource_persistence_facade->getResources(a_transaction, a_id_holder);

        // Get total cost.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(a_transaction, a_key.toHash(), ID_COST_TYPE_BUILDING_BUILD);

        // Multiply total cost.
        cost *= a_volume;

        // Verify if there is enough resources.
        if (!(resource_set >= cost))
        {
            return BuildBuildingOperatorExitCode(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Subtract the resources.
        bool const result = m_resource_persistence_facade->subtractResourceSet(a_transaction, a_id_holder, cost);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough resources and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result)
        {
            return BuildBuildingOperatorExitCode(BUILD_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME);
        }

        // Add the building.
        m_building_persistence_facade->addBuilding(a_transaction, a_id_holder, a_key, a_volume);

        return BuildBuildingOperatorExitCode(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT);
    }
    catch (...)
    {
        return BuildBuildingOperatorExitCode(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Building
} // namespace GameServer
