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
#include "ExecutorGetLandByName.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Authentication;
using namespace GameServer::Authorization;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
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


void ExecutorGetLandByName::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorGetLandByName.";
}

bool ExecutorGetLandByName::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_value_id_user = a_request->getParameterValueUnsignedInteger("iduser");
        m_password      = a_request->getParameterValueString("password");
        m_name          = a_request->getParameterValueString("name");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorGetLandByName::processParameters()
{
    try
    {
        m_id_user = m_value_id_user;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorGetLandByName::authenticate(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthenticateOperatorShrPtr authenticate_operator = m_operator_abstract_factory->createAuthenticateOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthenticateOperatorExitCode const exit_code =
            authenticate_operator->authenticate(transaction, m_id_user, m_password);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authenticated;
    }
}

bool ExecutorGetLandByName::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    IAuthorizeUserToLandByNameOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToLandByNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        AuthorizeUserToLandByNameOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToLandByName(transaction, m_id_user, m_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetLandByName::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochByLandNameOperatorShrPtr epoch_operator = m_operator_abstract_factory->createGetEpochByLandNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetEpochByLandNameOperatorExitCode const exit_code = epoch_operator->getEpochByLandName(transaction, m_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetLandByName::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorGetLandByName::perform(
    IPersistencyShrPtr a_persistency
) const
{
    IGetLandByIDUserAndNameOperatorShrPtr land_operator =
        m_operator_abstract_factory->createGetLandByIDUserAndNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetLandByIDUserAndNameOperatorExitCode const exit_code =
            land_operator->getLandByIDUserAndName(transaction, m_id_user, m_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorGetLandByName::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_GET_LAND_BY_NAME);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorGetLandByName::produceReply(
    GetLandByIDUserAndNameOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_reply = reply->m_xml_document->getNode("reply");

    IXmlNodeShrPtr node_parameters = reply->m_xml_document->getNode("reply")->appendNode("parameters");

    IXmlNodeShrPtr node_message = node_parameters->appendNode("message");
    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case GET_LAND_BY_IDUSER_AND_NAME_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_LAND_BY_IDUSER_AND_NAME_LAND_HAS_BEEN_GOT.c_str());
            break;

        case GET_LAND_BY_IDUSER_AND_NAME_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_GOT:
            node_message->appendAttribute("value")->setValue(GET_LAND_BY_IDUSER_AND_NAME_LAND_HAS_NOT_BEEN_GOT.c_str());
            break;

        case GET_LAND_BY_IDUSER_AND_NAME_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(GET_LAND_BY_IDUSER_AND_NAME_UNEXPECTED_ERROR.c_str());
            break;

        default:
            node_message->appendAttribute("value")->setValue(METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE.c_str());
    }

    if (a_exit_code.m_land)
    {
        IXmlNodeShrPtr node_iduser = node_parameters->appendNode("iduser");
        node_iduser->appendAttribute("type")->setValue("unsigned integer");
        node_iduser->appendAttribute("value")->setValue(a_exit_code.m_land->getIDUser().getValue());

        IXmlNodeShrPtr node_idworld = node_parameters->appendNode("idworld");
        node_idworld->appendAttribute("type")->setValue("unsigned integer");
        node_idworld->appendAttribute("value")->setValue(a_exit_code.m_land->getIDWorld().getValue());

        IXmlNodeShrPtr node_idland = node_parameters->appendNode("idland");
        node_idland->appendAttribute("type")->setValue("unsigned integer");
        node_idland->appendAttribute("value")->setValue(a_exit_code.m_land->getIDLand().getValue());

        IXmlNodeShrPtr node_name = node_parameters->appendNode("name");
        node_name->appendAttribute("type")->setValue("string");
        node_name->appendAttribute("value")->setValue(a_exit_code.m_land->getName().c_str());

        IXmlNodeShrPtr node_granted = node_parameters->appendNode("granted");
        node_granted->appendAttribute("type")->setValue("boolean");
        node_granted->appendAttribute("value")->setValue(a_exit_code.m_land->getGranted());
    }

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
