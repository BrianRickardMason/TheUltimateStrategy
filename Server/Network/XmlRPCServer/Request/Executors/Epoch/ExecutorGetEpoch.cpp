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
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorGetEpoch.hpp>
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

ExecutorGetEpoch::ExecutorGetEpoch(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorGetEpoch::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetEpoch.";
}

bool ExecutorGetEpoch::getParameters(
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

bool ExecutorGetEpoch::processParameters()
{
    return true;
}

bool ExecutorGetEpoch::filterOutNonModerator() const
{
    return true;
}

bool ExecutorGetEpoch::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorGetEpoch::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorGetEpoch::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorGetEpoch::perform(
    IPersistenceShrPtr a_persistence
) const
{
    IGetEpochByWorldNameOperatorShrPtr epoch_operator = m_operator_abstract_factory->createGetEpochByWorldNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GetEpochByWorldNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByWorldName(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetEpoch::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_EPOCH);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetEpoch::produceReply(
    GetEpochByWorldNameOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_parameters = reply->m_xml_document->getNode("reply")->appendNode("parameters");

    IXmlNodeShrPtr node_message = node_parameters->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case GET_EPOCH_BY_WORLD_NAME_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_EPOCH_EPOCH_HAS_BEEN_GOT.c_str());
            break;

        case GET_EPOCH_BY_WORLD_NAME_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_EPOCH_EPOCH_HAS_NOT_BEEN_GOT.c_str());
            break;

        case GET_EPOCH_BY_WORLD_NAME_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_EPOCH_UNEXPECTED_ERROR.c_str());
            break;

        case GET_EPOCH_BY_WORLD_NAME_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(GET_EPOCH_WORLD_DOES_NOT_EXIST.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    if (a_exit_code.m_epoch)
    {
        IXmlNodeShrPtr node_epoch_name = node_parameters->appendNode("epoch_name");
        node_epoch_name->appendAttribute("value")->setValue(a_exit_code.m_epoch->getEpochName().c_str());

        IXmlNodeShrPtr node_world_name = node_parameters->appendNode("world_name");
        node_world_name->appendAttribute("value")->setValue(a_exit_code.m_epoch->getWorldName().c_str());

        IXmlNodeShrPtr node_active = node_parameters->appendNode("active");
        node_active->appendAttribute("value")->setValue(a_exit_code.m_epoch->getActive());

        IXmlNodeShrPtr node_finished = node_parameters->appendNode("finished");
        node_finished->appendAttribute("value")->setValue(a_exit_code.m_epoch->getFinished());

        IXmlNodeShrPtr node_ticks = node_parameters->appendNode("ticks");
        node_ticks->appendAttribute("value")->setValue(a_exit_code.m_epoch->getTicks());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
