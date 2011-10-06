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
#include "ExecutorDismissHuman.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
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

void ExecutorDismissHuman::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorDismissHuman.";
}

bool ExecutorDismissHuman::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login                 = a_request->getLoginValue();
        m_password              = a_request->getPasswordValue();
        m_value_id_holder_class = a_request->getParameterValueUnsignedInteger("idholderclass");
        m_holder_name           = a_request->getParameterValueString("holder_name");
        m_value_id_human_class  = a_request->getParameterValueUnsignedInteger("idhumanclass");
        m_value_id_human        = a_request->getParameterValueUnsignedInteger("idhuman");
        m_value_experience      = a_request->getParameterValueUnsignedInteger("experience");
        m_value_volume          = a_request->getParameterValueUnsignedInteger("volume");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorDismissHuman::processParameters()
{
    try
    {
        m_id_holder.assign(m_value_id_holder_class, m_holder_name);
        m_id_human.assign(m_value_id_human_class, m_value_id_human);
        m_experience = m_value_experience;
        m_volume = m_value_volume;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorDismissHuman::authorize(
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
            authorize_operator->authorizeUserToHolder(transaction, m_user->getLogin(), m_id_holder);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorDismissHuman::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochBySettlementNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochBySettlementNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetEpochBySettlementNameOperatorExitCode const exit_code =
            epoch_operator->getEpochBySettlementName(transaction, m_holder_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorDismissHuman::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorDismissHuman::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IDismissHumanOperatorShrPtr dismiss_human_operator = m_operator_abstract_factory->createDismissHumanOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        DismissHumanOperatorExitCode const exit_code =
            dismiss_human_operator->dismissHuman(transaction, m_id_holder, GameServer::Human::Key(m_id_human, m_experience), m_volume);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorDismissHuman::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_DISMISS_HUMAN);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorDismissHuman::produceReply(
    DismissHumanOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMANS_MISSING_IN_THE_MEANTIME:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_HUMANS_MISSING_IN_THE_MEANTIME.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_DISMISSABLE:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_HUMAN_IS_NOT_DISMISSABLE.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_NOT_ENOUGH_ENGAGED.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_NOT_ENOUGH_RESOURCES.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_RESOURCES_MISSING_IN_THE_MEANTIME.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_DISMISS_ZERO_HUMANS:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_TRYING_TO_DISMISS_ZERO_HUMANS.c_str());
            break;

        case DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(DISMISS_HUMAN_UNEXPECTED_ERROR.c_str());
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
