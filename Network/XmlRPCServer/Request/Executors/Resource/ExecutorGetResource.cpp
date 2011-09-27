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

#include "../../../../../GameServer/Settlement/IDSettlement.hpp"
#include "../Constants.hpp"
#include "ExecutorGetResource.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Persistency;
using namespace GameServer::Resource;
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

void ExecutorGetResource::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetResource.";
}

bool ExecutorGetResource::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login                 = a_request->getLoginValue();
        m_password              = a_request->getPasswordValue();
        m_value_id_holder_class = a_request->getParameterValueUnsignedInteger("holderclass"); // TODO: Rename.
        m_value_id_holder       = a_request->getParameterValueUnsignedInteger("idholder");
        m_value_id_resource     = a_request->getParameterValueUnsignedInteger("idresource");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetResource::processParameters()
{
    try
    {
        m_id_holder.assign(m_value_id_holder_class, m_value_id_holder);
        m_id_resource = m_value_id_resource;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorGetResource::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthorizeUserToHolderOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToHolderOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToHolderOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToHolder(transaction, m_user->getIDUser(), m_id_holder);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetResource::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochByIDSettlementOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochByIDSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        IDSettlement id_settlement(m_id_holder.getValue2());

        GetEpochByIDSettlementOperatorExitCode const exit_code =
            epoch_operator->getEpochByIDSettlement(transaction, id_settlement);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetResource::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorGetResource::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IGetResourceOperatorShrPtr get_resource_operator = m_operator_abstract_factory->createGetResourceOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetResourceOperatorExitCode const exit_code =
            get_resource_operator->getResource(transaction, m_id_holder, GameServer::Resource::Key(m_id_resource));

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetResource::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_RESOURCE);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetResource::produceReply(
    GetResourceOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_message = node_reply->appendNode("parameters")->appendNode("message");

    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case GET_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_RESOURCE_RESOURCE_HAS_BEEN_GOT.c_str());
            break;

        case GET_RESOURCE_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_RESOURCE_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    IXmlNodeShrPtr node_objects = node_reply->appendNode("objects");

    if (a_exit_code.m_resource)
    {
        IXmlNodeShrPtr node_object = node_objects->appendNode("object");

        IXmlNodeShrPtr node_idresource = node_object->appendNode("idresource");
        node_idresource->appendAttribute("type")->setValue("unsigned integer");
        node_idresource->appendAttribute("value")->setValue(a_exit_code.m_resource->getIDResource().getValue());

        IXmlNodeShrPtr node_volume = node_object->appendNode("volume");
        node_volume->appendAttribute("type")->setValue("unsigned integer");
        node_volume->appendAttribute("value")->setValue(a_exit_code.m_resource->getVolume());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
