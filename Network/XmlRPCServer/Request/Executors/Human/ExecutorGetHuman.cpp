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
#include "ExecutorGetHuman.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authentication;
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

void ExecutorGetHuman::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetHuman.";
}

bool ExecutorGetHuman::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login                 = a_request->getLoginValue();
        m_password              = a_request->getPasswordValue();
        m_value_id_holder_class = a_request->getParameterValueUnsignedInteger("idholderclass");
        m_value_id_holder       = a_request->getParameterValueUnsignedInteger("idholder");
        m_value_id_human_class  = a_request->getParameterValueUnsignedInteger("idhumanclass");
        m_value_id_human        = a_request->getParameterValueUnsignedInteger("idhuman");
        m_value_experience      = a_request->getParameterValueUnsignedInteger("experience");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetHuman::processParameters()
{
    try
    {
        m_id_holder.assign(m_value_id_holder_class, m_value_id_holder);
        m_id_human.assign(m_value_id_human_class, m_value_id_human);
        m_experience = m_value_experience;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorGetHuman::authenticate(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthenticateOperatorShrPtr authenticate_operator = m_operator_abstract_factory->createAuthenticateOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthenticateOperatorExitCode const exit_code =
            authenticate_operator->authenticate(transaction, m_login, m_password);    

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authenticated;
    }
}

bool ExecutorGetHuman::authorize(
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

bool ExecutorGetHuman::epochIsActive(
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

bool ExecutorGetHuman::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorGetHuman::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IGetHumanOperatorShrPtr get_human_operator = m_operator_abstract_factory->createGetHumanOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetHumanOperatorExitCode const exit_code =
            get_human_operator->getHuman(transaction, m_id_holder, GameServer::Human::Key(m_id_human, m_experience));

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetHuman::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_HUMAN);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetHuman::produceReply(
    GetHumanOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_message = node_reply->appendNode("parameters")->appendNode("message");

    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case GET_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_HUMAN_HUMAN_HAS_BEEN_GOT.c_str());
            break;

        case GET_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_HUMAN_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    IXmlNodeShrPtr node_objects = node_reply->appendNode("objects");

    if (a_exit_code.m_human)
    {
        IXmlNodeShrPtr node_object = node_objects->appendNode("object");

        IXmlNodeShrPtr node_idhumanclass = node_object->appendNode("idhumanclass");
        node_idhumanclass->appendAttribute("type")->setValue("unsigned integer");
        node_idhumanclass->appendAttribute("value")->setValue(a_exit_code.m_human->getIDHuman().getValue1());

        IXmlNodeShrPtr node_idhuman = node_object->appendNode("idhuman");
        node_idhuman->appendAttribute("type")->setValue("unsigned integer");
        node_idhuman->appendAttribute("value")->setValue(a_exit_code.m_human->getIDHuman().getValue2());

        IXmlNodeShrPtr node_experience = node_object->appendNode("experience");
        node_experience->appendAttribute("type")->setValue("unsigned integer");
        node_experience->appendAttribute("value")->setValue(a_exit_code.m_human->getExperience().getValue());

        IXmlNodeShrPtr node_volume = node_object->appendNode("volume");
        node_volume->appendAttribute("type")->setValue("unsigned integer");
        node_volume->appendAttribute("value")->setValue(a_exit_code.m_human->getVolume());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
