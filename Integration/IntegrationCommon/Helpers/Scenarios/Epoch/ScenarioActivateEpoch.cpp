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
#include <Integration/IntegrationCommon/Helpers/Commands/Epoch/EpochCommands.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioActivateEpoch.hpp>

using namespace IntegrationCommon::Helpers::Commands::Epoch;
using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace Network::XmlRPCCommon::Xml;
using namespace Network::XmlRPCServer::Request::Executors;
using namespace std;

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Epoch
{

ScenarioActivateEpoch::ScenarioActivateEpoch(
    IClientShrPtr               a_client,
    IScenarioActionShrPtr       a_action,
    IScenarioVerificationShrPtr a_verification
)
    : m_client(a_client),
      m_action(a_action),
      m_verification(a_verification)
{
}

char const * ScenarioActivateEpoch::execute()
{
    ReplyShrPtr reply = m_action->perform(m_client);

    return m_verification->verify(reply);
}

ScenarioActivateEpochActionSuccess::ScenarioActivateEpochActionSuccess(
    string const & a_login,
    string const & a_password,
    string const   a_world_name
)
    : m_login(a_login),
      m_password(a_password),
      m_world_name(a_world_name)
{
}

ReplyShrPtr ScenarioActivateEpochActionSuccess::perform(
    IClientShrPtr a_client
)
{
    return ActivateEpoch(a_client, m_login, m_password, m_world_name);
}

ScenarioActivateEpochActionInvalidRequest::ScenarioActivateEpochActionInvalidRequest(
    string const & a_login,
    string const & a_password,
    string const   a_world_name
)
    : m_login(a_login),
      m_password(a_password),
      m_world_name(a_world_name)
{
}

ReplyShrPtr ScenarioActivateEpochActionInvalidRequest::perform(
    IClientShrPtr a_client
)
{
    RequestShrPtr request(new Request);

    request->m_xml_document->appendNode("request")->appendAttribute("id")->setValue(REQUEST_ID_ACTIVATE_EPOCH);
    IXmlNodeShrPtr parameters = request->m_xml_document->getNode("request")->appendNode("parameters");

    IXmlNodeShrPtr user_node = request->m_xml_document->getNode("request")->appendNode("user");

    user_node->appendNode("login")->appendAttribute("value")->setValue(m_login.c_str());
    user_node->appendNode("password")->appendAttribute("value")->setValue(m_password.c_str());

    IXmlNodeShrPtr world_name = parameters->appendNode("world_name");
    world_name->appendAttribute("valve")->setValue(m_world_name.c_str());

    return a_client->sendRequest(request);
}

const char * ScenarioActivateEpochVerificationEpochDoesNotExist::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_EPOCH_DOES_NOT_EXIST.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationEpochHasBeenActivated::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_EPOCH_HAS_BEEN_ACTIVATED.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationEpochHasBeenFinished::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationEpochHasNotBeenActivated::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_EPOCH_HAS_NOT_BEEN_ACTIVATED.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationEpochIsActive::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_EPOCH_IS_ACTIVE.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationUnexpectedError::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_UNEXPECTED_ERROR.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationWorldDoesNotExist::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(ACTIVATE_EPOCH_WORLD_DOES_NOT_EXIST.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioActivateEpochVerificationInvalidRequest::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_INVALID_REQUEST,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioActivateEpochVerificationInvalidRange::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_INVALID_RANGE,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioActivateEpochVerificationUnauthenticated::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_UNAUTHENTICATED,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioActivateEpochVerificationUnauthorized::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_UNAUTHORIZED,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioActivateEpochVerificationEpochIsNotActive::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_ACTIVATE_EPOCH, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_EPOCH_IS_NOT_ACTIVE,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

} // namespace Epoch
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon
