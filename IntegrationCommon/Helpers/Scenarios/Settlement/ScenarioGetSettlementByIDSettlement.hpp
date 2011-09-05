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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_SETTLEMENT_SCENARIOGETSETTLEMENTBYIDSETTLEMENT_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_SETTLEMENT_SCENARIOGETSETTLEMENTBYIDSETTLEMENT_HPP

#include "../../../Network/XmlRPCCommon/Xml/IXmlNode.hpp"
#include "../../../Network/XmlRPCServer/Request/Executors/Constants.hpp"
#include "../../Commands/Settlement/SettlementCommands.hpp"
#include "../IScenario.hpp"
#include "../IScenarioAction.hpp"
#include "../IScenarioVerification.hpp"

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Settlement
{

/**
 * @brief The "GetSettlementByIDSettlement" scenario.
 */
class ScenarioGetSettlementByIDSettlement
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
    ScenarioGetSettlementByIDSettlement(
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
 * @brief The "ScenarioGetSettlementByIDSettlementActionSuccess" action.
 */
class ScenarioGetSettlementByIDSettlementActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_id_user       The identifier of the user.
     * @param a_password      The password of the user.
     * @param a_id_settlement The identifier of the settlement.
     */
    ScenarioGetSettlementByIDSettlementActionSuccess(
        unsigned int const   a_id_user,
        std::string  const & a_password,
        unsigned int const   a_id_settlement
    )
        : m_id_user(a_id_user),
          m_password(a_password),
          m_id_settlement(a_id_settlement)
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
        return Commands::Settlement::GetSettlementByIDSettlement(a_client, m_id_user, m_password, m_id_settlement);
    }

private:
    /**
     * @brief The identifier of the user.
     */
    unsigned int m_id_user;

    /**
     * @brief The password of the user.
     */
    std::string m_password;

    /**
     * @brief The identifier of the settlement.
     */
    unsigned int m_id_settlement;
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementActionInvalidRequest" action.
 */
class ScenarioGetSettlementByIDSettlementActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_id_user       The identifier of the user.
     * @param a_password      The password of the user.
     * @param a_id_settlement The identifier of the settlement.
     */
    ScenarioGetSettlementByIDSettlementActionInvalidRequest(
        unsigned int const   a_id_user,
        std::string  const & a_password,
        unsigned int const   a_id_settlement
    )
        : m_id_user(a_id_user),
          m_password(a_password),
          m_id_settlement(a_id_settlement)
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

        request->m_xml_document->appendNode("request")->appendAttribute("id")->setValue(Network::XmlRPCCommon::Request::REQUEST_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT);
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr parameters = request->m_xml_document->getNode("request")->appendNode("parameters");

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr iduser = parameters->appendNode("iduser");
        iduser->appendAttribute("type")->setValue("unsigned integer");
        iduser->appendAttribute("value")->setValue(m_id_user);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr password = parameters->appendNode("password");
        password->appendAttribute("type")->setValue("unsigned integer");
        password->appendAttribute("value")->setValue(m_password.c_str());

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idsettlement = parameters->appendNode("idsettlement");
        idsettlement->appendAttribute("type")->setValue("integer");
        idsettlement->appendAttribute("value")->setValue(m_id_settlement);

        return a_client->sendRequest(request);
    }

private:
    /**
     * @brief The identifier of the user.
     */
    unsigned int m_id_user;

    /**
     * @brief The password of the user.
     */
    std::string m_password;

    /**
     * @brief The identifier of the settlement.
     */
    unsigned int m_id_settlement;
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationSettlementHasBeenGot" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationSettlementHasBeenGot
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_BEEN_GOT.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationSettlementHasNotBeenGot" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationSettlementHasNotBeenGot
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_GOT.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationUnexpectedError" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationUnexpectedError
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ("string",
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("type")->getValue(),
                       "Invalid node type.");
        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DELETE_SETTLEMENT_UNEXPECTED_ERROR.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationInvalidRequest" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationInvalidRequest
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_REQUEST,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationInvalidRange" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationInvalidRange
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_RANGE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationUnauthenticated" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationUnauthenticated
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHENTICATED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationUnauthorized" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationUnauthorized
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHORIZED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioGetSettlementByIDSettlementVerificationEpochIsNotActive" verification.
 */
class ScenarioGetSettlementByIDSettlementVerificationEpochIsNotActive
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

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};


} // namespace Settlement
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_SETTLEMENT_SCENARIOGETSETTLEMENTBYIDSETTLEMENT_HPP
