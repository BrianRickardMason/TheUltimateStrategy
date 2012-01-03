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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIODESTROYBUILDING_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIODESTROYBUILDING_HPP

#include <Server/Network/XmlRPCCommon/Xml/IXmlNode.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Constants.hpp>
#include <Integration/IntegrationCommon/Helpers/Commands/Building/BuildingCommands.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenario.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenarioAction.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenarioVerification.hpp>

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Building
{

/**
 * @brief The "DestroyBuilding" scenario.
 */
class ScenarioDestroyBuilding
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
    ScenarioDestroyBuilding(
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

        return m_verification->verify(reply);
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
 * @brief The "ScenarioDestroyBuildingActionSuccess" action.
 */
class ScenarioDestroyBuildingActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_key             The key of the building.
     * @param a_volume          The volume.
     */
    ScenarioDestroyBuildingActionSuccess(
        std::string  const a_login,
        std::string  const a_password,
        unsigned int const a_id_holder_class,
        std::string  const a_holder_name,
        std::string  const a_key,
        unsigned int const a_volume
    )
        : m_login(a_login),
          m_password(a_password),
          m_id_holder_class(a_id_holder_class),
          m_holder_name(a_holder_name),
          m_key(a_key),
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
        return Commands::Building::DestroyBuilding(a_client,
                                                   m_login,
                                                   m_password,
                                                   m_id_holder_class,
                                                   m_holder_name,
                                                   m_key,
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
     * @brief The identifier of the class of the holder.
     */
    unsigned int const m_id_holder_class;

    /**
     * @brief The name of the holder.
     */
    std::string const m_holder_name;

    /**
     * @brief The key of the building.
     */
    std::string const m_key;

    /**
     * @brief The volume.
     */
    unsigned int const m_volume;
};

/**
 * @brief The "ScenarioDestroyBuildingActionInvalidRequest" action.
 */
class ScenarioDestroyBuildingActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_key             The key of the building.
     * @param a_volume          The volume.
     */
    ScenarioDestroyBuildingActionInvalidRequest(
        std::string  const a_login,
        std::string  const a_password,
        unsigned int const a_id_holder_class,
        std::string  const a_holder_name,
        std::string  const a_key,
        unsigned int const a_volume
    )
        : m_login(a_login),
          m_password(a_password),
          m_id_holder_class(a_id_holder_class),
          m_holder_name(a_holder_name),
          m_key(a_key),
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

        request->m_xml_document->appendNode("request")->appendAttribute("id")->setValue(Network::XmlRPCCommon::Request::REQUEST_ID_DESTROY_BUILDING);
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr parameters = request->m_xml_document->getNode("request")->appendNode("parameters");

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr user_node = request->m_xml_document->getNode("request")->appendNode("user");

        user_node->appendNode("login")->appendAttribute("value")->setValue(m_login.c_str());
        user_node->appendNode("password")->appendAttribute("value")->setValue(m_password.c_str());

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr idholderclass = parameters->appendNode("idholderclass");
        idholderclass->appendAttribute("value")->setValue(m_id_holder_class);

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr holder_name = parameters->appendNode("holder_name");
        holder_name->appendAttribute("value")->setValue(m_holder_name.c_str());

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr humankey = parameters->appendNode("humankey");
        humankey->appendAttribute("value")->setValue(m_key.c_str());

        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr volume = parameters->appendNode("volume");
        volume->appendAttribute("valve")->setValue(m_volume);

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
     * @brief The identifier of the class of the holder.
     */
    unsigned int const m_id_holder_class;

    /**
     * @brief The name of the holder.
     */
    std::string const m_holder_name;

    /**
     * @brief The key of the building.
     */
    std::string const m_key;

    /**
     * @brief The volume.
     */
    unsigned int const m_volume;
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationBuildingsMissingInTheMeantime" verification.
 */
class ScenarioDestroyBuildingVerificationBuildingsMissingInTheMeantime
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_BUILDINGS_MISSING_IN_THE_MEANTIME.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationBuildingHasBeenDestroyed" verification.
 */
class ScenarioDestroyBuildingVerificationBuildingHasBeenDestroyed
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationNotEnoughBuildings" verification.
 */
class ScenarioDestroyBuildingVerificationNotEnoughBuildings
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_NOT_ENOUGH_BUILDINGS.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationNotEnoughResources" verification.
 */
class ScenarioDestroyBuildingVerificationNotEnoughResources
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_NOT_ENOUGH_RESOURCES.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationResourcesMissingInTheMeantime" verification.
 */
class ScenarioDestroyBuildingVerificationResourcesMissingInTheMeantime
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_RESOURCES_MISSING_IN_THE_MEANTIME.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationThereAreNoBuildings" verification.
 */
class ScenarioDestroyBuildingVerificationThereAreNoBuildings
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_THERE_ARE_NO_BUILDINGS.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationTryingToDestroyZeroBuildings" verification.
 */
class ScenarioDestroyBuildingVerificationTryingToDestroyZeroBuildings
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_TRYING_TO_DESTROY_ZERO_BUILDINGS.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationUnexpectedError" verification.
 */
class ScenarioDestroyBuildingVerificationUnexpectedError
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_OK,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        I_ASSERT_STREQ(Network::XmlRPCServer::Request::Executors::DESTROY_BUILDING_UNEXPECTED_ERROR.c_str(),
                       node_reply->getNode("parameters")->getNode("message")->getAttribute("value")->getValue(),
                       "Invalid node value.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationInvalidRequest" verification.
 */
class ScenarioDestroyBuildingVerificationInvalidRequest
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_REQUEST,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationInvalidRange" verification.
 */
class ScenarioDestroyBuildingVerificationInvalidRange
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_INVALID_RANGE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationUnauthenticated" verification.
 */
class ScenarioDestroyBuildingVerificationUnauthenticated
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHENTICATED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationUnauthorized" verification.
 */
class ScenarioDestroyBuildingVerificationUnauthorized
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_UNAUTHORIZED,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};

/**
 * @brief The "ScenarioDestroyBuildingVerificationEpochIsNotActive" verification.
 */
class ScenarioDestroyBuildingVerificationEpochIsNotActive
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    )
    {
        Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node_reply = a_reply->m_xml_document->getNode("reply");

        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_ID_DESTROY_BUILDING,
                    node_reply->getAttribute("id")->asInt(),
                    "Invalid reply ID.");
        I_ASSERT_EQ(Network::XmlRPCCommon::Reply::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE,
                    node_reply->getNode("status")->getAttribute("value")->asInt(),
                    "Invalid status.");

        return "";
    }
};


} // namespace Building
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIODESTROYBUILDING_HPP
