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

#include "../Constants.hpp"
#include "ExecutorGetSettlementByIDSettlement.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace Network::XmlRPCCommon::Xml;
using namespace boost;
using namespace log4cpp;

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

void ExecutorGetSettlementByIDSettlement::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetSettlementByIDSettlement.";
}

bool ExecutorGetSettlementByIDSettlement::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login               = a_request->getLoginValue();
        m_password            = a_request->getPasswordValue();
        m_value_id_settlement = a_request->getParameterValueUnsignedInteger("idsettlement");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetSettlementByIDSettlement::processParameters()
{
    try
    {
        m_id_settlement = m_value_id_settlement;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorGetSettlementByIDSettlement::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthorizeUserToSettlementOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getIDUser(), m_id_settlement);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetSettlementByIDSettlement::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochByIDSettlementOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochByIDSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetEpochByIDSettlementOperatorExitCode const exit_code =
            epoch_operator->getEpochByIDSettlement(transaction, m_id_settlement);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetSettlementByIDSettlement::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorGetSettlementByIDSettlement::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IGetSettlementByIDSettlementOperatorShrPtr settlement_operator =
        m_operator_abstract_factory->createGetSettlementByIDSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetSettlementByIDSettlementOperatorExitCode const exit_code =
            settlement_operator->getSettlementByIDSettlement(transaction, m_id_settlement);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetSettlementByIDSettlement::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetSettlementByIDSettlement::produceReply(
    GetSettlementByIDSettlementOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_parameters = reply->m_xml_document->getNode("reply")->appendNode("parameters");

    IXmlNodeShrPtr node_message = node_parameters->appendNode("message");
    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case GET_SETTLEMENT_BY_IDSETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENT_BY_IDSETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENT_BY_IDSETTLEMENT_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_IDSETTLEMENT_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    if (a_exit_code.m_settlement)
    {
        IXmlNodeShrPtr node_idland = node_parameters->appendNode("idland");
        node_idland->appendAttribute("type")->setValue("unsigned integer");
        node_idland->appendAttribute("value")->setValue(a_exit_code.m_settlement->getIDLand().getValue());

        IXmlNodeShrPtr node_idsettlement = node_parameters->appendNode("idsettlement");
        node_idsettlement->appendAttribute("type")->setValue("unsigned integer");
        node_idsettlement->appendAttribute("value")->setValue(a_exit_code.m_settlement->getIDSettlement().getValue());

        IXmlNodeShrPtr node_name = node_parameters->appendNode("name");
        node_name->appendAttribute("type")->setValue("string");
        node_name->appendAttribute("value")->setValue(a_exit_code.m_settlement->getName().c_str());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
