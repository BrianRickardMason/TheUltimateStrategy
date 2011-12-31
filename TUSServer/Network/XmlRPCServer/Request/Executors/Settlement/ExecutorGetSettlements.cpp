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

#include <TUSServer/Network/XmlRPCServer/Request/Executors/Constants.hpp>
#include <TUSServer/Network/XmlRPCServer/Request/Executors/Settlement/ExecutorGetSettlements.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Persistence;
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

ExecutorGetSettlements::ExecutorGetSettlements(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorGetSettlements::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetSettlements.";
}

bool ExecutorGetSettlements::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login     = a_request->getLoginValue();
        m_password  = a_request->getPasswordValue();
        m_land_name = a_request->getParameterValueString("land_name");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetSettlements::processParameters()
{
    return true;
}

bool ExecutorGetSettlements::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    IAuthorizeUserToLandOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        AuthorizeUserToLandOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToLand(transaction, m_user->getLogin(), m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetSettlements::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    IGetEpochByLandNameOperatorShrPtr epoch_operator = m_operator_abstract_factory->createGetEpochByLandNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GetEpochByLandNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByLandName(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetSettlements::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorGetSettlements::perform(
    IPersistenceShrPtr a_persistence
) const
{
    IGetSettlementsOperatorShrPtr settlement_operator =
        m_operator_abstract_factory->createGetSettlementsOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GetSettlementsOperatorExitCode const exit_code =
            settlement_operator->getSettlements(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetSettlements::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_SETTLEMENTS);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetSettlements::produceReply(
    GetSettlementsOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_message = node_reply->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case GET_SETTLEMENTS_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENTS_BY_LANDNAME_LAND_DOES_NOT_EXIST.c_str());
            break;

        case GET_SETTLEMENTS_OPERATOR_EXIT_CODE_SETTLEMENTS_HAVE_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENTS_OPERATOR_EXIT_CODE_SETTLEMENTS_HAVE_NOT_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_NOT_BEEN_GOT.c_str());
            break;

        case GET_SETTLEMENTS_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_SETTLEMENTS_BY_LANDNAME_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    IXmlNodeShrPtr node_objects = node_reply->appendNode("objects");

    for (ISettlementMap::const_iterator it = a_exit_code.m_settlements.begin();
         it != a_exit_code.m_settlements.end();
         ++it)
    {
        IXmlNodeShrPtr node_object = node_objects->appendNode("object");

        IXmlNodeShrPtr node_land_name = node_object->appendNode("land_name");
        node_land_name->appendAttribute("value")->setValue(it->second->getLandName().c_str());

        IXmlNodeShrPtr node_settlement_name = node_object->appendNode("settlement_name");
        node_settlement_name->appendAttribute("value")->setValue(it->second->getSettlementName().c_str());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
