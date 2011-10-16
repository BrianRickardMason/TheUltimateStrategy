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
#include "ExecutorCreateUser.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace GameServer::User;
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

void ExecutorCreateUser::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorCreateUser.";
}

bool ExecutorCreateUser::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login    = a_request->getParameterValueString("login");
        m_password = a_request->getParameterValueString("password");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorCreateUser::processParameters()
{
    return true;
}

bool ExecutorCreateUser::authenticate(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateUser::getActingUser(
    IPersistenceShrPtr a_persistence
)
{
    return true;
}

bool ExecutorCreateUser::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateUser::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateUser::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorCreateUser::perform(
    IPersistenceShrPtr a_persistence
) const
{
    ICreateUserOperatorShrPtr user_operator = m_operator_abstract_factory->createCreateUserOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        CreateUserOperatorExitCode const exit_code = user_operator->createUser(transaction, m_login, m_password);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorCreateUser::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_CREATE_USER);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorCreateUser::produceReply(
    CreateUserOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case CREATE_USER_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(CREATE_USER_UNEXPECTED_ERROR.c_str());
            break;

        case CREATE_USER_OPERATOR_EXIT_CODE_USER_DOES_EXIST:
            node_message->appendAttribute("value")->setValue(CREATE_USER_USER_DOES_EXIST.c_str());
            break;

        case CREATE_USER_OPERATOR_EXIT_CODE_USER_HAS_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_USER_USER_HAS_BEEN_CREATED.c_str());
            break;

        case CREATE_USER_OPERATOR_EXIT_CODE_USER_HAS_NOT_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_USER_USER_HAS_NOT_BEEN_CREATED.c_str());
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
