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

#include "TransportHumanOperator.hpp"

#include "../../../Common/IDHolder.hpp"

using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;

namespace GameServer
{
namespace Transport
{

TransportHumanOperator::TransportHumanOperator(
    IHumanManagerShrPtr      a_human_manager,
    ISettlementManagerShrPtr a_settlement_manager
)
    : m_human_manager(a_human_manager),
      m_settlement_manager(a_settlement_manager)
{
}

TransportHumanOperatorExitCode TransportHumanOperator::transportHuman(
    ITransactionShrPtr          a_transaction,
    IDSettlement        const & a_id_settlement_source,
    IDSettlement        const & a_id_settlement_destination,
    Key                 const & a_key,
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
        SettlementShrPtr settlement_source = m_settlement_manager->getSettlement(a_transaction, a_id_settlement_source);

        if (!settlement_source)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST);
        }

        // Verify if the destination settlement exists.
        SettlementShrPtr settlement_destination =
            m_settlement_manager->getSettlement(a_transaction, a_id_settlement_destination);

        if (!settlement_destination)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST);
        }

        // Verify if the settlements are from the same land.
        if (settlement_source->getIDLand() != settlement_destination->getIDLand())
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND);
        }

        IDHolder id_holder_source(ID_HOLDER_CLASS_SETTLEMENT, a_id_settlement_source.getValue());
        IDHolder id_holder_destination(ID_HOLDER_CLASS_SETTLEMENT, a_id_settlement_destination.getValue());

        bool const result = m_human_manager->subtractHuman(a_transaction, id_holder_source, a_key, a_volume);

        if (!result)
        {
            return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_HUMANS);
        }

        m_human_manager->addHuman(a_transaction, id_holder_destination, a_key, a_volume);

        return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED);
    }
    catch (...)
    {
        return TransportHumanOperatorExitCode(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Transport
} // namespace GameServer
