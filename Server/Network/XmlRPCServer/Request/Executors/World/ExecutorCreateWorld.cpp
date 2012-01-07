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

#include <Server/Network/XmlRPCServer/Request/Executors/Constants.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/World/ExecutorCreateWorld.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace GameServer::World;
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

ExecutorCreateWorld::ExecutorCreateWorld(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorCreateWorld::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorCreateWorld.";
}

bool ExecutorCreateWorld::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login      = a_request->getLoginValue();
        m_password   = a_request->getPasswordValue();
        m_world_name = a_request->getParameterValueString("world_name");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorCreateWorld::processParameters()
{
    return true;
}

bool ExecutorCreateWorld::filterOutNonModerator() const
{
    return m_user->isModerator();
}

bool ExecutorCreateWorld::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateWorld::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateWorld::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorCreateWorld::perform(
    IPersistenceShrPtr a_persistence
) const
{
    ICreateWorldOperatorShrPtr world_operator = m_operator_abstract_factory->createCreateWorldOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        CreateWorldOperatorExitCode const exit_code = world_operator->createWorld(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorCreateWorld::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_CREATE_WORLD);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorCreateWorld::produceReply(
    CreateWorldOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case CREATE_WORLD_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(CREATE_WORLD_UNEXPECTED_ERROR.c_str());
            break;

        case CREATE_WORLD_OPERATOR_EXIT_CODE_WORLD_DOES_EXIST:
            node_message->appendAttribute("value")->setValue(CREATE_WORLD_WORLD_DOES_EXIST.c_str());
            break;

        case CREATE_WORLD_OPERATOR_EXIT_CODE_WORLD_HAS_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_WORLD_WORLD_HAS_BEEN_CREATED.c_str());
            break;

        case CREATE_WORLD_OPERATOR_EXIT_CODE_WORLD_HAS_NOT_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_WORLD_WORLD_HAS_NOT_BEEN_CREATED.c_str());
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