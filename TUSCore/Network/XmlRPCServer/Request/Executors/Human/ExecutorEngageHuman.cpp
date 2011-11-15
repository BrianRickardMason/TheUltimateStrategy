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
#include "ExecutorEngageHuman.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
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

void ExecutorEngageHuman::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorEngageHuman.";
}

bool ExecutorEngageHuman::getParameters(
    RequestShrPtr a_request
)
{
    // TODO: One should not need to introduce key _NOVICE. It must be guessed that only novices can be engaged.
    try
    {
        m_login                 = a_request->getLoginValue();
        m_password              = a_request->getPasswordValue();
        m_value_id_holder_class = a_request->getParameterValueUnsignedInteger("idholderclass");
        m_holder_name           = a_request->getParameterValueString("holder_name");
        m_key                   = a_request->getParameterValueString("humankey");
        m_value_volume          = a_request->getParameterValueUnsignedInteger("volume");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorEngageHuman::processParameters()
{
    try
    {
        m_id_holder.assign(m_value_id_holder_class, m_holder_name);
        m_volume = m_value_volume;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorEngageHuman::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    IAuthorizeUserToHolderOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToHolderOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        AuthorizeUserToHolderOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToHolder(transaction, m_user->getLogin(), m_id_holder);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorEngageHuman::epochIsActive(
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
            epoch_operator->getEpochBySettlementName(transaction, m_holder_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorEngageHuman::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorEngageHuman::perform(
    IPersistenceShrPtr a_persistence
) const
{
    IEngageHumanOperatorShrPtr engage_human_operator = m_operator_abstract_factory->createEngageHumanOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        EngageHumanOperatorExitCode const exit_code =
            engage_human_operator->engageHuman(transaction, m_id_holder, m_key, m_volume);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorEngageHuman::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_ENGAGE_HUMAN);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorEngageHuman::produceReply(
    EngageHumanOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    switch (a_exit_code.m_exit_code)
    {
        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_HUMAN_HAS_BEEN_ENGAGED.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_ENGAGEABLE:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_HUMAN_IS_NOT_ENGAGEABLE.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_JOBLESS_MISSING_IN_THE_MEANTIME:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_JOBLESS_MISSING_IN_THE_MEANTIME.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_NOT_ENOUGH_BUILDINGS.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_NOT_ENOUGH_JOBLESS.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_NOT_ENOUGH_RESOURCES.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_RESOURCES_MISSING_IN_THE_MEANTIME.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_ENGAGE_ZERO_HUMANS:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_TRYING_TO_ENGAGE_ZERO_HUMANS.c_str());
            break;

        case ENGAGE_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(ENGAGE_HUMAN_UNEXPECTED_ERROR.c_str());
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
