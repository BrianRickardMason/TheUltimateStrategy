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

#ifndef GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOR_HPP
#define GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOR_HPP

#include "../../../Cost/ICostPersistenceFacade.hpp"
#include "../../../Resource/IResourcePersistenceFacade.hpp"
#include "../../IBuildingPersistenceFacade.hpp"
#include "IDestroyBuildingOperator.hpp"

namespace GameServer
{
namespace Building
{

/**
 * @brief DestroyBuildingOperator.
 */
class DestroyBuildingOperator
    : public IDestroyBuildingOperator
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_building_persistence_facade The persistence facade of buildings.
     * @param a_cost_persistence_facade     The persistence facade of costs.
     * @param a_resource_persitence_facade  The persistence facade of resources.
     */
    DestroyBuildingOperator(
        IBuildingPersistenceFacadeShrPtr           a_building_persistence_facade,
        Cost::ICostPersistenceFacadeShrPtr         a_cost_persistence_facade,
        Resource::IResourcePersistenceFacadeShrPtr a_resource_persitence_facade
    );

    /**
     * @brief Destroys a building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the building.
     * @param a_volume      The volume of the building.
     *
     * @returns The exit code.
     */
    virtual DestroyBuildingOperatorExitCode destroyBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

private:
    //@{
    /**
     * @brief A persistence facade.
     */
    IBuildingPersistenceFacadeShrPtr           m_building_persistence_facade;
    Cost::ICostPersistenceFacadeShrPtr         m_cost_persistence_facade;
    Resource::IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    //@}
};

/**
 * @brief Typedef of auto pointer.
 */
typedef std::auto_ptr<DestroyBuildingOperator> DestroyBuildingOperatorAutPtr;

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOR_HPP
