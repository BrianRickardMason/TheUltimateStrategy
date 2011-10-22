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

#ifndef GAMESERVER_TURN_TURNMANAGER_HPP
#define GAMESERVER_TURN_TURNMANAGER_HPP

#include <GameServer/Cost/ICostPersistenceFacade.hpp>
#include <GameServer/Human/IHumanPersistenceFacade.hpp>
#include <GameServer/Land/ILandPersistenceFacade.hpp>
#include <GameServer/Property/IPropertyPersistenceFacade.hpp>
#include <GameServer/Resource/IResourcePersistenceFacade.hpp>
#include <GameServer/Settlement/ISettlementPersistenceFacade.hpp>
#include <GameServer/Turn/Managers/ITurnManager.hpp>

namespace GameServer
{
namespace Turn
{

/**
 * @brief TurnManager.
 */
class TurnManager
    : public ITurnManager
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_cost_persistence_facade       The persistence facade of costs.
     * @param a_human_persistence_facade      The persistence facade of humans.
     * @param a_land_persistence_facade       The persistence facade of lands.
     * @param a_property_persistence_facade   The persistence facade of properties.
     * @param a_resource_persistence_facade   The persistence facade of resources.
     * @param a_settlement_persistence_facade The persistence facade of settlements.
     */
    TurnManager(
        Cost::ICostPersistenceFacadeShrPtr             a_cost_persistence_facade,
        Human::IHumanPersistenceFacadeShrPtr           a_human_persistence_facade,
        Land::ILandPersistenceFacadeShrPtr             a_land_persistence_facade,
        Property::IPropertyPersistenceFacadeShrPtr     a_property_persistence_facade,
        Resource::IResourcePersistenceFacadeShrPtr     a_resource_persistence_facade,
        Settlement::ISettlementPersistenceFacadeShrPtr a_settlement_persistence_facade
    );

    /**
     * @brief Performs a turn.
     *
     * @param a_transaction The transaction.
     * @param a_world       The world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool turn(
        Persistence::ITransactionShrPtr       a_transaction,
        World::IWorldShrPtr             const a_world
    ) const;

private:
    /**
     * @brief Executes a turn in land.
     *
     * @param a_transaction The transaction.
     * @param a_land        The land.
     *
     * @return True on success, false otherwise.
     */
    bool executeTurn(
        Persistence::ITransactionShrPtr       a_transaction,
        Land::ILandShrPtr               const a_land
    ) const;

    /**
     * @brief Executes a turn in settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of a settlement.
     *
     * @return True on success, false otherwise.
     */
    bool executeTurnSettlement(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;

    /**
     * @brief Gets the total cost of living humans in the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of a settlement.
     *
     * @return The total cost of living humans in the settlement.
     */
    Resource::ResourceSet getCostOfLiving(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;

    //@{
    /**
     * @brief A persistence facade.
     */
    Cost::ICostPersistenceFacadeShrPtr             m_cost_persistence_facade;
    Human::IHumanPersistenceFacadeShrPtr           m_human_persistence_facade;
    Land::ILandPersistenceFacadeShrPtr             m_land_persistence_facade;
    Property::IPropertyPersistenceFacadeShrPtr     m_property_persistence_facade;
    Resource::IResourcePersistenceFacadeShrPtr     m_resource_persistence_facade;
    Settlement::ISettlementPersistenceFacadeShrPtr m_settlement_persistence_facade;
    //}@
};

/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<TurnManager> TurnManagerAutPtr;

} // namespace Turn
} // namespace GameServer

#endif // GAMESERVER_TURN_TURNMANAGER_HPP
