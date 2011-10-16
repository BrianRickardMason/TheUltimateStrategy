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

#ifndef GAMESERVER_TURN_TURNOPERATOR_HPP
#define GAMESERVER_TURN_TURNOPERATOR_HPP

#include "../../../Cost/ICostManager.hpp"
#include "../../../Human/IHumanManager.hpp"
#include "../../../Land/ILandManager.hpp"
#include "../../../Property/IPropertyManager.hpp"
#include "../../../Resource/IResourceManager.hpp"
#include "../../../Settlement/ISettlementManager.hpp"
#include "ITurnOperator.hpp"

namespace GameServer
{
namespace Turn
{

/**
 * @brief TurnOperator.
 */
class TurnOperator
    : public ITurnOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_cost_manager       The manager of costs.
     * @param a_human_manager      The manager of humans.
     * @param a_land_manager       The manager of lands.
     * @param a_property_manager   The manager of properties.
     * @param a_resource_manager   The manager of resources.
     * @param a_settlement_manager The manager of settlements.
     */
    TurnOperator(
        Cost::ICostManagerShrPtr             a_cost_manager,
        Human::IHumanManagerShrPtr           a_human_manager,
        Land::ILandManagerShrPtr             a_land_manager,
        Property::IPropertyManagerShrPtr     a_property_manager,
        Resource::IResourceManagerShrPtr     a_resource_manager,
        Settlement::ISettlementManagerShrPtr a_settlement_manager
    );

    /**
     * @brief Performs a turn.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The exit code.
     */
    virtual TurnOperatorExitCode turn(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

private:
    /**
     * @brief Executes a turn.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return True on success, false otherwise.
     */
    bool executeTurn(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
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

    /**
     * @brief The manager of costs.
     */
    Cost::ICostManagerShrPtr m_cost_manager;

    /**
     * @brief The manager of humans.
     */
    Human::IHumanManagerShrPtr m_human_manager;

    /**
     * @brief The manager of lands.
     */
    Land::ILandManagerShrPtr m_land_manager;

    /**
     * @brief The manager of properties.
     */
    Property::IPropertyManagerShrPtr m_property_manager;

    /**
     * @brief The manager of resources.
     */
    Resource::IResourceManagerShrPtr m_resource_manager;

    /**
     * @brief The manager of settlements.
     */
    Settlement::ISettlementManagerShrPtr m_settlement_manager;
};

/**
 * @brief The auto pointer of TurnOperator.
 */
typedef std::auto_ptr<TurnOperator> TurnOperatorAutPtr;

} // namespace Turn
} // namespace GameServer

#endif // GAMESERVER_TURN_TURNOPERATOR_HPP
