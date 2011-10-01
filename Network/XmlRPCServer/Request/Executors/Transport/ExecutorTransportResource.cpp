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
using namespace GameServer::Persistency;
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
        m_login                           = a_request->getLoginValue();
        m_password                        = a_request->getPasswordValue();
        m_value_id_settlement_source      = a_request->getParameterValueUnsignedInteger("idsettlementsource");
        m_value_id_settlement_destination = a_request->getParameterValueUnsignedInteger("idsettlementdestination");
        m_value_id_resource               = a_request->getParameterValueUnsignedInteger("idresource");
        m_value_volume                    = a_request->getParameterValueUnsignedInteger("volume");

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
        m_id_settlement_source = m_value_id_settlement_source;
        m_id_settlement_destination = m_value_id_settlement_destination;
        m_id_resource = m_value_id_resource;
        m_volume = m_value_volume;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorTransportResource::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthorizeUserToSettlementOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToSettlementOperator();

    bool authorized_source(false), authorized_destination(false);

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getLogin(), m_id_settlement_source);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        authorized_source = exit_code.m_authorized;
    }

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getLogin(), m_id_settlement_destination);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        authorized_destination = exit_code.m_authorized;
    }

    return authorized_source && authorized_destination;
}

bool ExecutorTransportResource::epochIsActive(
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
            epoch_operator->getEpochByIDSettlement(transaction, m_id_settlement_source);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorTransportResource::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorTransportResource::perform(
    IPersistencyShrPtr a_persistency
) const
{
    ITransportResourceOperatorShrPtr transport_resource_operator =
        m_operator_abstract_factory->createTransportResourceOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        TransportResourceOperatorExitCode const exit_code =
            transport_resource_operator->transportResource(transaction,
                                                           m_id_settlement_source,
                                                           m_id_settlement_destination,
                                                           Key(m_id_resource),
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

    node_message->appendAttribute("type")->setValue("string");

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
