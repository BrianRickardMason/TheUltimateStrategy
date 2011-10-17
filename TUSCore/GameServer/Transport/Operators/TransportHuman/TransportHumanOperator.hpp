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

#ifndef GAMESERVER_TRANSPORT_TRANSPORTHUMANOPERATOR_HPP
#define GAMESERVER_TRANSPORT_TRANSPORTHUMANOPERATOR_HPP

#include "../../../Human/IHumanManager.hpp"
#include "../../../Settlement/ISettlementPersistenceFacade.hpp"
#include "ITransportHumanOperator.hpp"

namespace GameServer
{
namespace Transport
{

/**
 * @brief TransportHumanOperator.
 */
class TransportHumanOperator
    : public ITransportHumanOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_human_manager                 The manager of humans.
     * @param a_settlement_persistence_facade The persistence facade of settlements.
     */
    TransportHumanOperator(
        Human::IHumanManagerShrPtr                     a_human_manager,
        Settlement::ISettlementPersistenceFacadeShrPtr a_settlement_persistence_facade
    );

    /**
     * @brief Transports a human from one settlement to another.
     *
     * @param a_transaction                 The transaction.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_key                         The key of the human.
     * @param a_volume                      The volume of the human.
     *
     * @returns The exit code.
     */
    virtual TransportHumanOperatorExitCode transportHuman(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const   a_settlement_name_source,
        std::string                     const   a_settlement_name_destination,
        Human::Key                      const & a_key,
        Human::Volume                   const & a_volume
    ) const;

private:
    /**
     * @brief The manager of humans.
     */
    Human::IHumanManagerShrPtr m_human_manager;

    /**
     * @brief The persistence facade of settlements.
     */
    Settlement::ISettlementPersistenceFacadeShrPtr m_settlement_persistence_facade;
};

/**
 * @brief The auto pointer of TransportHumanOperator.
 */
typedef std::auto_ptr<TransportHumanOperator> TransportHumanOperatorAutPtr;

} // namespace Transport
} // namespace GameServer

#endif // GAMESERVER_TRANSPORT_TRANSPORTHUMANOPERATOR_HPP
