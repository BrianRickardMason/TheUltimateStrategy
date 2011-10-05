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

#ifndef GAMESERVER_SETTLEMENT_CREATESETTLEMENTOPERATOR_HPP
#define GAMESERVER_SETTLEMENT_CREATESETTLEMENTOPERATOR_HPP

#include "../../../Land/ILandManager.hpp"
#include "../../ISettlementManager.hpp"
#include "IBehaviourGiveGrant.hpp"
#include "ICreateSettlementOperator.hpp"

namespace GameServer
{
namespace Settlement
{

/**
 * @brief CreateSettlementOperator.
 */
class CreateSettlementOperator
    : public ICreateSettlementOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_land_manager         The manager of lands.
     * @param a_settlement_manager   The manager of settlements.
     * @param a_behaviour_give_grant The behaviour "GiveGrant".
     */
    CreateSettlementOperator(
        Land::ILandManagerShrPtr  a_land_manager,
        ISettlementManagerShrPtr  a_settlement_manager,
        IBehaviourGiveGrantShrPtr a_behaviour_give_grant
    );

    /**
     * @brief Creates a settlement.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     * @param a_name        The name of the settlement.
     *
     * @return The exit code.
     */
    virtual CreateSettlementOperatorExitCode createSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name,
        std::string                     const a_name
    ) const;

private:
    /**
     * @brief The manager of lands.
     */
    Land::ILandManagerShrPtr m_land_manager;

    /**
     * @brief The manager of settlements.
     */
    ISettlementManagerShrPtr m_settlement_manager;

    /**
     * @brief The behaviour "GiveGrant".
     */
    IBehaviourGiveGrantShrPtr m_behaviour_give_grant;
};

/**
 * @brief The auto pointer of CreateSettlementOperator.
 */
typedef std::auto_ptr<CreateSettlementOperator> CreateSettlementOperatorAutPtr;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_CREATESETTLEMENTOPERATOR_HPP
