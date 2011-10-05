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
#include "ExecutorGetSettlementByLandNameAndName.hpp"
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

void ExecutorGetSettlementByLandNameAndName::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetSettlementByLandNameAndName.";
}

bool ExecutorGetSettlementByLandNameAndName::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login     = a_request->getLoginValue();
        m_password  = a_request->getPasswordValue();
        m_land_name = a_request->getParameterValueString("land_name");
        m_name      = a_request->getParameterValueString("name");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetSettlementByLandNameAndName::processParameters()
{
    return true;
}

bool ExecutorGetSettlementByLandNameAndName::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthorizeUserToLandOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToLandOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToLand(transaction, m_user->getLogin(), m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetSettlementByLandNameAndName::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochByLandNameOperatorShrPtr epoch_operator = m_operator_abstract_factory->createGetEpochByLandNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetEpochByLandNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByLandName(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetSettlementByLandNameAndName::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorGetSettlementByLandNameAndName::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IGetSettlementByLandNameAndNameOperatorShrPtr settlement_operator =
        m_operator_abstract_factory->createGetSettlementByLandNameAndNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetSettlementByLandNameAndNameOperatorExitCode const exit_code =
            settlement_operator->getSettlementByLandNameAndName(transaction, m_land_name, m_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetSettlementByLandNameAndName::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_SETTLEMENT_BY_LAND_NAME_AND_NAME);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetSettlementByLandNameAndName::produceReply(
    GetSettlementByLandNameAndNameOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_parameters = reply->m_xml_document->getNode("reply")->appendNode("parameters");

    IXmlNodeShrPtr node_message = node_parameters->appendNode("message");
    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case GET_SETTLEMENT_BY_LANDNAME_AND_NAME_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_LANDNAME_AND_NAME_LAND_DOES_NOT_EXIST.c_str());
            break;

        case GET_SETTLEMENT_BY_LANDNAME_AND_NAME_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_LANDNAME_AND_NAME_SETTLEMENT_HAS_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENT_BY_LANDNAME_AND_NAME_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_LANDNAME_AND_NAME_SETTLEMENT_HAS_NOT_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENT_BY_LANDNAME_AND_NAME_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENT_BY_LANDNAME_AND_NAME_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    if (a_exit_code.m_settlement)
    {
        IXmlNodeShrPtr land_name = node_parameters->appendNode("land_name");
        land_name->appendAttribute("type")->setValue("string");
        land_name->appendAttribute("value")->setValue(a_exit_code.m_settlement->getLandName().c_str());

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