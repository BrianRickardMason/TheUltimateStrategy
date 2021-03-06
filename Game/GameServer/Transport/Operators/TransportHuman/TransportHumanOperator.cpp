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

#include <Game/GameServer/Common/IDHolder.hpp>
#include <Game/GameServer/Transport/Operators/TransportHuman/TransportHumanOperator.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Settlement;
using namespace std;

namespace GameServer
{
namespace Transport
{

TransportHumanOperator::TransportHumanOperator(
    IHumanPersistenceFacadeShrPtr      a_human_persistence_facade,
    ISettlementPersistenceFacadeShrPtr a_settlement_persistence_facade
)
    : m_human_persistence_facade(a_human_persistence_facade),
      m_settlement_persistence_facade(a_settlement_persistence_facade)
{
}

TransportHumanOperatorExitCode TransportHumanOperator::transportHuman(
    ITransactionShrPtr          a_transaction,
    string              const   a_settlement_name_source,
    string              const   a_settlement_name_destination,
    IKey                const & a_key,
    Volume              const & a_volume
) const
{
    try
    {
        // Trying to transport zero humans.
        if (a_volume == 0)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_HUMANS);
        }

        // Verify if the source settlement exists.
        ISettlementShrPtr settlement_source =
            m_settlement_persistence_facade->getSettlement(a_transaction, a_settlement_name_source);

        if (!settlement_source)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST);
        }

        // Verify if the destination settlement exists.
        ISettlementShrPtr settlement_destination =
            m_settlement_persistence_facade->getSettlement(a_transaction, a_settlement_name_destination);

        if (!settlement_destination)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST);
        }

        // Verify if the settlements are from the same land.
        if (settlement_source->getLandName() != settlement_destination->getLandName())
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND);
        }

        IDHolder id_holder_source(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name_source);
        IDHolder id_holder_destination(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name_destination);

        bool const result = m_human_persistence_facade->subtractHuman(a_transaction, id_holder_source, a_key, a_volume);

        if (!result)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_HUMANS);
        }

        m_human_persistence_facade->addHuman(a_transaction, id_holder_destination, a_key, a_volume);

        return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED);
    }
    catch (...)
    {
        return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Transport
} // namespace GameServer
