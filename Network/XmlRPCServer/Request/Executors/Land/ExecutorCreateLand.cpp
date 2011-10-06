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
#include "ExecutorCreateLand.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

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

void ExecutorCreateLand::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorCreateLand.";
}

bool ExecutorCreateLand::getParameters(
    RequestShrPtr a_request
)
{
    try
    {
        m_login          = a_request->getLoginValue();
        m_password       = a_request->getPasswordValue();
        m_world_name     = a_request->getParameterValueString("world_name");
        m_value_id_epoch = a_request->getParameterValueUnsignedInteger("idepoch");
        m_name           = a_request->getParameterValueString("name");

        return true;
    }
    catch (InvalidRequestShrPtr)
    {
        return false;
    }
}

bool ExecutorCreateLand::processParameters()
{
    try
    {
        m_id_epoch = m_value_id_epoch;

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorCreateLand::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

bool ExecutorCreateLand::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    IGetEpochByWorldNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochByWorldNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        GetEpochByWorldNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByWorldName(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        if (exit_code.m_epoch)
        {
            if (exit_code.m_epoch->getIDEpoch() != m_id_epoch)
            {
                return false;
            }

            return exit_code.m_epoch->getActive();
        }
        else
        {
            return false;
        }
    }
}

bool ExecutorCreateLand::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorCreateLand::perform(
    IPersistencyShrPtr a_persistency
) const
{
    ICreateLandOperatorShrPtr land_operator = m_operator_abstract_factory->createCreateLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistency->getConnection();
        ITransactionShrPtr transaction = a_persistency->getTransaction(connection);

        CreateLandOperatorExitCode const exit_code =
            land_operator->createLand(transaction, m_user->getLogin(), m_world_name, m_id_epoch, m_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

ReplyShrPtr ExecutorCreateLand::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_CREATE_LAND);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

ReplyShrPtr ExecutorCreateLand::produceReply(
    CreateLandOperatorExitCode const & a_exit_code
) const
{
    ReplyShrPtr reply = getBasicReply(REPLY_STATUS_OK);

    IXmlNodeShrPtr node_message = reply->m_xml_document->getNode("reply")->appendNode("parameters")->appendNode("message");

    node_message->appendAttribute("type")->setValue("string");

    switch (a_exit_code.m_exit_code)
    {
        case CREATE_LAND_OPERATOR_EXIT_CODE_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS.c_str());
            break;

        case CREATE_LAND_OPERATOR_EXIT_CODE_EPOCH_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_EPOCH_DOES_NOT_EXIST.c_str());
            break;

        case CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_LAND_HAS_BEEN_CREATED.c_str());
            break;

        case CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_CREATED:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_LAND_HAS_NOT_BEEN_CREATED.c_str());
            break;

        case CREATE_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_UNEXPECTED_ERROR.c_str());
            break;

        case CREATE_LAND_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST:
            node_message->appendAttribute("value")->setValue(CREATE_LAND_WORLD_DOES_NOT_EXIST.c_str());
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
