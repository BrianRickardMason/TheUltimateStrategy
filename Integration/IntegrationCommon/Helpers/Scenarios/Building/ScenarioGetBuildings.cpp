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
#include <Integration/IntegrationCommon/Helpers/Commands/Building/BuildingCommands.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/Building/ScenarioGetBuildings.hpp>

using namespace IntegrationCommon::Helpers::Commands::Building;
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
namespace Building
{

ScenarioGetBuildings::ScenarioGetBuildings(
    IClientShrPtr               a_client,
    IScenarioActionShrPtr       a_action,
    IScenarioVerificationShrPtr a_verification
)
    : m_client(a_client),
      m_action(a_action),
      m_verification(a_verification)
{
}

char const * ScenarioGetBuildings::execute()
{
    ReplyShrPtr reply = m_action->perform(m_client);

    return m_verification->verify(reply);
}

ScenarioGetBuildingsActionSuccess::ScenarioGetBuildingsActionSuccess(
    string       const a_login,
    string       const a_password,
    unsigned int const a_id_holder_class,
    string       const a_holder_name
)
    : m_login(a_login),
      m_password(a_password),
      m_id_holder_class(a_id_holder_class),
      m_holder_name(a_holder_name)
{
}

ReplyShrPtr ScenarioGetBuildingsActionSuccess::perform(
    IClientShrPtr a_client
)
{
    return GetBuildings(a_client,
                        m_login,
                        m_password,
                        m_id_holder_class,
                        m_holder_name);
}

ScenarioGetBuildingsActionInvalidRequest::ScenarioGetBuildingsActionInvalidRequest(
    string       const a_login,
    string       const a_password,
    unsigned int const a_id_holder_class,
    string       const a_holder_name
)
    : m_login(a_login),
      m_password(a_password),
      m_id_holder_class(a_id_holder_class),
      m_holder_name(a_holder_name)
{
}

ReplyShrPtr ScenarioGetBuildingsActionInvalidRequest::perform(
    IClientShrPtr a_client
)
{
    RequestShrPtr request(new Request);

    request->m_xml_document->appendNode("request")->appendAttribute("id")->setValue(REQUEST_ID_GET_BUILDINGS);
    IXmlNodeShrPtr parameters = request->m_xml_document->getNode("request")->appendNode("parameters");

    IXmlNodeShrPtr user_node = request->m_xml_document->getNode("request")->appendNode("user");

    user_node->appendNode("login")->appendAttribute("value")->setValue(m_login.c_str());
    user_node->appendNode("password")->appendAttribute("value")->setValue(m_password.c_str());

    IXmlNodeShrPtr idholderclass = parameters->appendNode("idholderclass");
    idholderclass->appendAttribute("value")->setValue(m_id_holder_class);

    IXmlNodeShrPtr holder_name = parameters->appendNode("holder_name");
    holder_name->appendAttribute("valve")->setValue(m_holder_name.c_str());

    return a_client->sendRequest(request);
}

const char * ScenarioGetBuildingsVerificationBuildingsHaveBeenGot::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(GET_BUILDINGS_BUILDINGS_HAVE_BEEN_GOT.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioGetBuildingsVerificationUnexpectedError::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_OK, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    I_ASSERT_STREQ(GET_BUILDINGS_UNEXPECTED_ERROR.c_str(),
                   node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                   "Invalid node value.");

    return "";
}

const char * ScenarioGetBuildingsVerificationInvalidRequest::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_INVALID_REQUEST,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioGetBuildingsVerificationInvalidRange::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_INVALID_RANGE, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    return "";
}

const char * ScenarioGetBuildingsVerificationUnauthenticated::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_UNAUTHENTICATED,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

const char * ScenarioGetBuildingsVerificationUnauthorized::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_UNAUTHORIZED, node_reply->getNode("status")->getAttribute("value")->asInt(), "Invalid status.");

    return "";
}

const char * ScenarioGetBuildingsVerificationEpochIsNotActive::verify(
    ReplyShrPtr a_reply
)
{
    IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

    I_ASSERT_EQ(REPLY_ID_GET_BUILDINGS, node_reply->getAttribute("id")->asInt(), "Invalid reply ID.");
    I_ASSERT_EQ(REPLY_STATUS_EPOCH_IS_NOT_ACTIVE,
                node_reply->getNode("status")->getAttribute("value")->asInt(),
                "Invalid status.");

    return "";
}

} // namespace Building
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon
