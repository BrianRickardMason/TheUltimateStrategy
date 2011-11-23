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
#include "ExecutorTransportResource.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Transport;
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

ExecutorTransportResource::ExecutorTransportResource(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorTransportResource::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorTransportResource.";
}

bool ExecutorTransportResource::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login                       = a_request->getLoginValue();
        m_password                    = a_request->getPasswordValue();
        m_settlement_name_source      = a_request->getParameterValueString("settlement_name_source");
        m_settlement_name_destination = a_request->getParameterValueString("settlement_name_destination");
        m_key                         = a_request->getParameterValueString("resourcekey");
        m_value_volume                = a_request->getParameterValueUnsignedInteger("volume");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorTransportResource::processParameters()
{
    try
    {
        m_volume = m_value_volume;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorTransportResource::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    IAuthorizeUserToSettlementOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToSettlementOperator();

    bool authorized_source(false), authorized_destination(false);

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getLogin(), m_settlement_name_source);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        authorized_source = exit_code.m_authorized;
    }

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getLogin(), m_settlement_name_destination);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        authorized_destination = exit_code.m_authorized;
    }

    return authorized_source && authorized_destination;
}

bool ExecutorTransportResource::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    IGetEpochBySettlementNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochBySettlementNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GetEpochBySettlementNameOperatorExitCode const exit_code =
            epoch_operator->getEpochBySettlementName(transaction, m_settlement_name_source);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorTransportResource::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorTransportResource::perform(
    IPersistenceShrPtr a_persistence
) const
{
    ITransportResourceOperatorShrPtr transport_resource_operator =
        m_operator_abstract_factory->createTransportResourceOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        TransportResourceOperatorExitCode const exit_code =
            transport_resource_operator->transportResource(transaction,
                                                           m_settlement_name_source,
                                                           m_settlement_name_destination,
                                                           m_key,
                                                           m_volume);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorTransportResource::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_TRANSPORT_RESOURCE);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorTransportResource::produceReply(
    TransportResourceOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_NOT_ENOUGH_RESOURCES.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_TRANSPORTED:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_RESOURCE_HAS_BEEN_TRANSPORTED.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_SOURCE_SETTLEMENT_DOES_NOT_EXIST.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_RESOURCES:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_TRYING_TO_TRANSPORT_ZERO_RESOURCES.c_str());
            break;

        case TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(TRANSPORT_RESOURCE_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
