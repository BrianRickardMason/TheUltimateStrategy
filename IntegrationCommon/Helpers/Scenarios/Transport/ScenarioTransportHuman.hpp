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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_TRANSPORT_SCENARIOTRANSPORTHUMAN_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_TRANSPORT_SCENARIOTRANSPORTHUMAN_HPP

#include "../../../Network/XmlRPCCommon/Xml/IXmlNode.hpp"
#include "../../../Network/XmlRPCServer/Request/Executors/Constants.hpp"
#include "../../Commands/Transport/TransportCommands.hpp"
#include "../IScenario.hpp"
#include "../IScenarioAction.hpp"
#include "../IScenarioVerification.hpp"

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Transport
{

/**
 * @brief The "TransportHuman" scenario.
 */
class ScenarioTransportHuman
    : public IScenario
{
public:
    /**
     * @brief Constructs the scenario.
     *
     * @param a_client       The client.
     * @param a_action       The action object.
     * @param a_verification The verification object.
     */
    ScenarioTransportHuman(
        IClientShrPtr               a_client,
        IScenarioActionShrPtr       a_action,
        IScenarioVerificationShrPtr a_verification
    )
        : m_client(a_client),
          m_action(a_action),
          m_verification(a_verification)
    {
    }

    /**
     * @brief Executes the scenario.
     */
    virtual char const * execute()
    {
        Network::XmlRPCCommon::Reply::ReplyShrPtr reply = m_action->perform(m_client);

        return m_verification->verify(reply).c_str();
    }

private:
    /**
     * @brief The client.
     */
    IClientShrPtr m_client;

    /**
     * @brief The action object.
     */
    IScenarioActionShrPtr m_action;

    /**
     * @brief The verification object.
     */
    IScenarioVerificationShrPtr m_verification;
};

/**
 * @brief The "ScenarioTransportHumanActionSuccess" action.
 */
class ScenarioTransportHumanActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login                     The login of the user.
     * @param a_password                  The password of the user.
     * @param a_id_settlement_source      The identifier of the source settlement.
     * @param a_id_settlement_destination The identifier of the destination settlement.
     * @param a_id_human_class            The identifier of the class of the human.
     * @param a_id_human                  The identifier of the human.
     * @param a_experience                The experience of the human.
     * @param a_volume                    The volume of the human.
     */
    ScenarioTransportHumanActionSuccess(
        std::string  const & a_login,
        std::string  const & a_password,
        unsigned int const   a_id_settlement_source,
        unsigned int const   a_id_settlement_destination,
        unsigned int const   a_id_human_class,
        unsigned int const   a_id_human,
        unsigned int const   a_experience,
        unsigned int const   a_volume
    )
        : m_login(a_login),
          m_password(a_password),
          m_id_settlement_source(a_id_settlement_source),
          m_id_settlement_destination(a_id_settlement_destination),
          m_id_human_class(a_id_human_class),
          m_id_human(a_id_human),
          m_experience(a_experience),
          m_volume(a_volume)
    {
    }

    /**
     * @brief Performs the action.
     *
     * @param a_client The client.
     *
     * @return The reply.
     */
    virtual Network::XmlRPCCommon::Reply::ReplyShrPtr perform(
        IClientShrPtr a_client
    )
    {
        return Commands::Transport::TransportHuman(a_client,
                                                   m_login,
                                                   m_password,
                                                   m_id_settlement_source,
                                                   m_id_settlement_destination,
                                                   m_id_human_class,
                                                   m_id_human,
                                                   m_experience,
                                                   m_volume);
    }

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The identifier of the source settlement.
     */
    unsigned int const m_id_settlement_source;

    /**
     * @brief The identifier of the destination settlement.
     */
    unsigned int const m_id_settlement_destination;

    /**
     * @brief The identifier of the class of the human.
     */
    unsigned int const m_id_human_class;

    /**
     * @brief The identifier of the human.
     */
    unsigned int const m_id_human;

    /**
     * @brief The experience of the human.
     */
    unsigned int const m_experience;

    /**
     * @brief The volume of the human.
     */
    unsigned int const m_volume;
};

/**
 * @brief The "ScenarioTransportHumanActionInvalidRequest" action.
 */
class ScenarioTransportHumanActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login                     The login of the user.
     * @param a_password                  The password of the user.
     * @param a_id_settlement_source      The identifier of the source settlement.
     * @param a_id_settlement_destination The identifier of the destination settlement.
     * @param a_id_human_class            The identifier of the class of the human.
     * @param a_id_human                  The identifier of the human.
     * @param a_experience                The experience of the human.
     * @param a_volume                    The volume of the human.
     */
    ScenarioTransportHumanActionInvalidRequest(
        std::string  const & a_login,
        std::string  const & a_password,
        unsigned int const   a_id_settlement_source,
        unsigned int const   a_id_settlement_destination,
        unsigned int const   a_id_human_class,
        unsigned int const   a_id_human,
        unsigned int const   a_experience,
        unsigned int const   a_volume
    )
        : m_login(a_login),
          m_password(a_password),
          m_id_settlement_source(a_id_settlement_source),
          m_id_settlement_destination(a_id_settlement_destination),
          m_id_human_class(a_id_human_class),
          m_id_human(a_id_human),
          m_experience(a_experience),
          m_volume(a_volume)
    {
    }

    /**
     * @brief Performs the action.
     *
     * @param a_client The client.
     *
     * @return The reply.
     */
    virtual Network::XmlRPCCommon::Reply::ReplyShrPtr perform(
        IClientShrPtr a_client
    )
    {
        Network::XmlRPCCommon::Request::RequestShrPtr request(new Network::XmlRPCCommon::Request::Request);

        request->m_xml_document->appendNode("request")->appendAttribute("id")->setValue(Network::XmlRPCCommon::Request::REQUEST_ID_TRANSPORT_HUMAN);
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr parameters = request->m_xml_document->getNode("request")->appendNode("parameters");

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr user_node = request->m_xml_document->getNode("request")->appendNode("user");

        user_node->appendNode("iduser")->appendAttribute("value")->setValue(m_login.c_str());
        user_node->appendNode("password")->appendAttribute("value")->setValue(m_password.c_str());

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idsettlementsource = parameters->appendNode("idsettlementsource");
        idsettlementsource->appendAttribute("type")->setValue("unsigned integer");
        idsettlementsource->appendAttribute("value")->setValue(m_id_settlement_source);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idsettlementdestination = parameters->appendNode("idsettlementdestination");
        idsettlementdestination->appendAttribute("type")->setValue("unsigned integer");
        idsettlementdestination->appendAttribute("value")->setValue(m_id_settlement_destination);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idhumanclass = parameters->appendNode("idhumanclass");
        idhumanclass->appendAttribute("type")->setValue("unsigned integer");
        idhumanclass->appendAttribute("value")->setValue(m_id_human_class);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idhuman = parameters->appendNode("idhuman");
        idhuman->appendAttribute("type")->setValue("unsigned integer");
        idhuman->appendAttribute("value")->setValue(m_id_human);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr experience = parameters->appendNode("experience");
        experience->appendAttribute("type")->setValue("unsigned integer");
        experience->appendAttribute("value")->setValue(m_experience);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr volume = parameters->appendNode("volume");
        volume->appendAttribute("type")->setValue("integer");
        volume->appendAttribute("value")->setValue(m_volume);

        return a_client->sendRequest(request);
    }

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The identifier of the source settlement.
     */
    unsigned int const m_id_settlement_source;

    /**
     * @brief The identifier of the destination settlement.
     */
    unsigned int const m_id_settlement_destination;

    /**
     * @brief The identifier of the class of the human.
     */
    unsigned int const m_id_human_class;

    /**
     * @brief The identifier of the human.
     */
    unsigned int const m_id_human;

    /**
     * @brief The experience of the human.
     */
    unsigned int const m_experience;

    /**
     * @brief The volume of the human.
     */
    unsigned int const m_volume;
};

/**
 * @brief The "ScenarioTransportHumanVerificationDestinationSettlementDoesNotExist" verification.
 */
class ScenarioTransportHumanVerificationDestinationSettlementDoesNotExist
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_DESTINATION_SETTLEMENT_DOES_NOT_EXIST.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationHumanHasBeenTransported" verification.
 */
class ScenarioTransportHumanVerificationHumanHasBeenTransported
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_HUMAN_HAS_BEEN_TRANSPORTED.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationNotEnoughHumans" verification.
 */
class ScenarioTransportHumanVerificationNotEnoughHumans
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_NOT_ENOUGH_HUMANS.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationSettlementsAreNotFromTheSameLand" verification.
 */
class ScenarioTransportHumanVerificationSettlementsAreNotFromTheSameLand
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationSourceSettlementDoesNotExist" verification.
 */
class ScenarioTransportHumanVerificationSourceSettlementDoesNotExist
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_SOURCE_SETTLEMENT_DOES_NOT_EXIST.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationTryingToTransportZeroHumans" verification.
 */
class ScenarioTransportHumanVerificationTryingToTransportZeroHumans
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::TRANSPORT_HUMAN_TRYING_TO_TRANSPORT_ZERO_HUMANS.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationInvalidRequest" verification.
 */
class ScenarioTransportHumanVerificationInvalidRequest
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_REQUEST,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationInvalidRange" verification.
 */
class ScenarioTransportHumanVerificationInvalidRange
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_RANGE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationUnauthenticated" verification.
 */
class ScenarioTransportHumanVerificationUnauthenticated
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHENTICATED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationUnauthorized" verification.
 */
class ScenarioTransportHumanVerificationUnauthorized
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHORIZED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioTransportHumanVerificationEpochIsNotActive" verification.
 */
class ScenarioTransportHumanVerificationEpochIsNotActive
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_TRANSPORT_HUMAN,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};


} // namespace Transport
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_TRANSPORT_SCENARIOTRANSPORTHUMAN_HPP
