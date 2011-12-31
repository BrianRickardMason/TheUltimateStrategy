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

#include <TUSServer/Network/XmlRPCServer/Request/Executors/Constants.hpp>
#include <TUSServer/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorFinishEpoch.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authentication;
using namespace GameServer::Epoch;
using namespace GameServer::Persistence;
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

ExecutorFinishEpoch::ExecutorFinishEpoch(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorFinishEpoch::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorFinishEpoch.";
}

bool ExecutorFinishEpoch::getParameters(
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

bool ExecutorFinishEpoch::processParameters()
{
    return true;
}

bool ExecutorFinishEpoch::filterOutNonModerator() const
{
    return m_user->isModerator();
}

bool ExecutorFinishEpoch::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorFinishEpoch::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorFinishEpoch::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorFinishEpoch::perform(
    IPersistenceShrPtr a_persistence
) const
{
    IFinishEpochOperatorShrPtr epoch_operator = m_operator_abstract_factory->createFinishEpochOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        FinishEpochOperatorExitCode const exit_code = epoch_operator->finishEpoch(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorFinishEpoch::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_FINISH_EPOCH);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorFinishEpoch::produceReply(
    FinishEpochOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_EPOCH_DOES_NOT_EXIST.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_FINISHED:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_EPOCH_HAS_NOT_BEEN_FINISHED.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_IS_ACTIVE:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_EPOCH_IS_ACTIVE.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_UNEXPECTED_ERROR.c_str());
            break;

        case FINISH_EPOCH_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(FINISH_EPOCH_WORLD_DOES_NOT_EXIST.c_str());
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
