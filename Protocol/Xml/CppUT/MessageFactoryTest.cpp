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

#include <Poco/DOM/Element.h>
#include <Protocol/Xml/Cpp/MessageFactory.hpp>
#include <gtest/gtest.h>

class MessageFactoryTest
    : public ::testing::Test
{
protected:
    /**
     * @brief Ctor.
     */
    MessageFactoryTest()
        : m_message_echo_request(m_message_factory.createEchoRequest()),
          m_message_error_request(m_message_factory.createErrorRequest()),
          m_message_create_land_request(m_message_factory.createCreateLandRequest(
              "Login", "Password", "World", "Land")),
          m_message_delete_land_request(m_message_factory.createDeleteLandRequest("Login", "Password", "Land")),
          m_message_get_land_request(m_message_factory.createGetLandRequest("Login", "Password", "Land")),
          m_message_get_lands_request(m_message_factory.createGetLandsRequest("Login", "Password")),
          m_message_create_settlement_request(m_message_factory.createCreateSettlementRequest(
              "Login", "Password", "Land", "Settlement")),
          m_message_delete_settlement_request(m_message_factory.createDeleteSettlementRequest(
              "Login", "Password", "Settlement")),
          m_message_get_settlement_request(m_message_factory.createGetSettlementRequest(
              "Login", "Password", "Settlement")),
          m_message_get_settlements_request(m_message_factory.createGetSettlementsRequest("Login", "Password", "Land")),
          m_message_build_building_request(m_message_factory.createBuildBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100")),
          m_message_destroy_building_request(m_message_factory.createDestroyBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100")),
          m_message_get_building_request(m_message_factory.createGetBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge")),
          m_message_get_buildings_request(m_message_factory.createGetBuildingsRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_message_dismiss_human_request(m_message_factory.createDismissHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100")),
          m_message_engage_human_request(m_message_factory.createEngageHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100")),
          m_message_get_human_request(m_message_factory.createGetHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice")),
          m_message_get_humans_request(m_message_factory.createGetHumansRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_message_get_resource_request(m_message_factory.createGetResourceRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "Coal")),
          m_message_get_resources_request(m_message_factory.createGetResourcesRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_message_create_user_request(m_message_factory.createCreateUserRequest("Login", "Password")),
          m_message_create_world_request(m_message_factory.createCreateWorldRequest("Login", "Password", "World")),
          m_message_create_epoch_request(m_message_factory.createCreateEpochRequest(
              "Login", "Password", "World", "Epoch")),
          m_message_delete_epoch_request(m_message_factory.createDeleteEpochRequest("Login", "Password", "World")),
          m_message_activate_epoch_request(m_message_factory.createActivateEpochRequest("Login", "Password", "World")),
          m_message_deactivate_epoch_request(m_message_factory.createDeactivateEpochRequest(
              "Login", "Password", "World")),
          m_message_finish_epoch_request(m_message_factory.createFinishEpochRequest("Login", "Password", "World")),
          m_message_tick_epoch_request(m_message_factory.createTickEpochRequest("Login", "Password", "World")),
          m_message_get_epoch_request(m_message_factory.createGetEpochRequest("Login", "Password", "World")),
          m_message_transport_human_request(m_message_factory.createTransportHumanRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "WorkerBlacksmithNovice", "100")),
          m_message_transport_resource_request(m_message_factory.createTransportResourceRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "Coal", "100")),
          m_message_echo_reply(m_message_factory.createEchoReply("1")),
          m_message_error_reply(m_message_factory.createErrorReply("1")),
          m_message_create_land_reply(m_message_factory.createCreateLandReply("1", "Message")),
          m_message_delete_land_reply(m_message_factory.createDeleteLandReply("1", "Message")),
          m_message_create_settlement_reply(m_message_factory.createCreateSettlementReply("1", "Message")),
          m_message_delete_settlement_reply(m_message_factory.createDeleteSettlementReply("1", "Message")),
          m_message_build_building_reply(m_message_factory.createBuildBuildingReply("1", "Message")),
          m_message_destroy_building_reply(m_message_factory.createDestroyBuildingReply("1", "Message")),
          m_message_dismiss_human_reply(m_message_factory.createDismissHumanReply("1", "Message")),
          m_message_engage_human_reply(m_message_factory.createEngageHumanReply("1", "Message")),
          m_message_create_user_reply(m_message_factory.createCreateUserReply("1", "Message")),
          m_message_create_world_reply(m_message_factory.createCreateWorldReply("1", "Message")),
          m_message_create_epoch_reply(m_message_factory.createCreateEpochReply("1", "Message")),
          m_message_delete_epoch_reply(m_message_factory.createDeleteEpochReply("1", "Message")),
          m_message_activate_epoch_reply(m_message_factory.createActivateEpochReply("1", "Message")),
          m_message_deactivate_epoch_reply(m_message_factory.createDeactivateEpochReply("1", "Message")),
          m_message_finish_epoch_reply(m_message_factory.createFinishEpochReply("1", "Message")),
          m_message_tick_epoch_reply(m_message_factory.createTickEpochReply("1", "Message")),
          m_message_transport_human_reply(m_message_factory.createTransportHumanReply("1", "Message")),
          m_message_transport_resource_reply(m_message_factory.createTransportResourceReply("1", "Message"))
    {
        m_building_1.insert(std::make_pair("buildingclass", "Regular"));
        m_building_1.insert(std::make_pair("buildingname", "Farm"));
        m_building_1.insert(std::make_pair("volume", "10"));
        m_building_2.insert(std::make_pair("buildingclass", "Regular"));
        m_building_2.insert(std::make_pair("buildingname", "Sawmill"));
        m_building_2.insert(std::make_pair("volume", "20"));
        m_buildings.push_back(m_building_1);
        m_buildings.push_back(m_building_2);

        m_epoch.insert(std::make_pair("epoch_name", "Epoch"));
        m_epoch.insert(std::make_pair("world_name", "World"));
        m_epoch.insert(std::make_pair("active", "true"));
        m_epoch.insert(std::make_pair("finished", "false"));
        m_epoch.insert(std::make_pair("ticks", "22"));

        m_human_1.insert(std::make_pair("humanclass", "Worker"));
        m_human_1.insert(std::make_pair("humanname", "Farmer"));
        m_human_1.insert(std::make_pair("experience", "Novice"));
        m_human_1.insert(std::make_pair("volume", "10"));
        m_human_2.insert(std::make_pair("humanclass", "Worker"));
        m_human_2.insert(std::make_pair("humanname", "Steelworker"));
        m_human_2.insert(std::make_pair("experience", "Advanced"));
        m_human_2.insert(std::make_pair("volume", "20"));
        m_humans.push_back(m_human_1);
        m_humans.push_back(m_human_2);

        m_resource_1.insert(std::make_pair("resourcename", "Coal"));
        m_resource_1.insert(std::make_pair("volume", "10"));
        m_resource_2.insert(std::make_pair("resourcename", "Wood"));
        m_resource_2.insert(std::make_pair("volume", "20"));
        m_resources.push_back(m_resource_1);
        m_resources.push_back(m_resource_2);

        m_settlement_1.insert(std::make_pair("land_name", "Land1"));
        m_settlement_1.insert(std::make_pair("settlement_name", "Settlement1"));
        m_settlement_2.insert(std::make_pair("land_name", "Land2"));
        m_settlement_2.insert(std::make_pair("settlement_name", "Settlement2"));
        m_settlements.push_back(m_settlement_1);
        m_settlements.push_back(m_settlement_2);
    }

    /**
     * @brief The message factory to be tested.
     */
    TUSProtocol::MessageFactory m_message_factory;

    //@{
    /**
     * @brief The message to be tested.
     */
    TUSProtocol::Message::Handle m_message_echo_request,
                                 m_message_error_request,
                                 m_message_create_land_request,
                                 m_message_delete_land_request,
                                 m_message_get_land_request,
                                 m_message_get_lands_request,
                                 m_message_create_settlement_request,
                                 m_message_delete_settlement_request,
                                 m_message_get_settlement_request,
                                 m_message_get_settlements_request,
                                 m_message_build_building_request,
                                 m_message_destroy_building_request,
                                 m_message_get_building_request,
                                 m_message_get_buildings_request,
                                 m_message_dismiss_human_request,
                                 m_message_engage_human_request,
                                 m_message_get_human_request,
                                 m_message_get_humans_request,
                                 m_message_get_resource_request,
                                 m_message_get_resources_request,
                                 m_message_create_user_request,
                                 m_message_create_world_request,
                                 m_message_create_epoch_request,
                                 m_message_delete_epoch_request,
                                 m_message_activate_epoch_request,
                                 m_message_deactivate_epoch_request,
                                 m_message_finish_epoch_request,
                                 m_message_tick_epoch_request,
                                 m_message_get_epoch_request,
                                 m_message_transport_human_request,
                                 m_message_transport_resource_request,
                                 m_message_echo_reply,
                                 m_message_error_reply,
                                 m_message_create_land_reply,
                                 m_message_delete_land_reply,
                                 m_message_create_settlement_reply,
                                 m_message_delete_settlement_reply,
                                 m_message_get_settlement_reply,
                                 m_message_get_settlements_reply,
                                 m_message_build_building_reply,
                                 m_message_destroy_building_reply,
                                 m_message_get_building_reply,
                                 m_message_get_buildings_reply,
                                 m_message_dismiss_human_reply,
                                 m_message_engage_human_reply,
                                 m_message_get_human_reply,
                                 m_message_get_humans_reply,
                                 m_message_get_resource_reply,
                                 m_message_get_resources_reply,
                                 m_message_create_user_reply,
                                 m_message_create_world_reply,
                                 m_message_create_epoch_reply,
                                 m_message_delete_epoch_reply,
                                 m_message_activate_epoch_reply,
                                 m_message_deactivate_epoch_reply,
                                 m_message_finish_epoch_reply,
                                 m_message_tick_epoch_reply,
                                 m_message_get_epoch_reply,
                                 m_message_transport_human_reply,
                                 m_message_transport_resource_reply;
    //}@

    //@{
    /**
     * @brief The building to be inserted.
     */
    TUSProtocol::Message::Object m_building_1,
                                 m_building_2;
    //}@

    /**
     * @brief The buildings to be tested.
     */
    TUSProtocol::Message::Objects m_buildings;

    /**
     * @brief The epoch to be inserted.
     */
    TUSProtocol::Message::Object m_epoch;

    //@{
    /**
     * @brief The human to be inserted.
     */
    TUSProtocol::Message::Object m_human_1,
                                 m_human_2;
    //}@

    /**
     * @brief The humans to be tested.
     */
    TUSProtocol::Message::Objects m_humans;

    //@{
    /**
     * @brief The resource to be inserted.
     */
    TUSProtocol::Message::Object m_resource_1,
                                 m_resource_2;
    //}@

    /**
     * @brief The resources to be tested.
     */
    TUSProtocol::Message::Objects m_resources;

    //@{
    /**
     * @brief The settlement to be inserted.
     */
    TUSProtocol::Message::Object m_settlement_1,
                                 m_settlement_2;
    //}@

    /**
     * @brief The settlements to be tested.
     */
    TUSProtocol::Message::Objects m_settlements;
};

TEST_F(MessageFactoryTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(TUSProtocol::MessageFactory message_factory);
}

TEST_F(MessageFactoryTest, CreateEchoRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_factory.createEchoRequest().get());
}

TEST_F(MessageFactoryTest, CreateEchoRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_echo_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateErrorRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_factory.createErrorRequest().get());
}

TEST_F(MessageFactoryTest, CreateErrorRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_error_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("2", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_land_request.get());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_create_land_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("3", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_create_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_create_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_create_land_request->documentElement()->
        getChildElement("request")->getChildElement("create_land_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandRequestSetsProperLandName)
{
    Poco::XML::Element * element = m_message_create_land_request->documentElement()->
        getChildElement("request")->getChildElement("create_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_land_request.get());
}

TEST_F(MessageFactoryTest, CreateDeleteLandRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_delete_land_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("4", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_delete_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_delete_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandRequestSetsProperLandName)
{
    Poco::XML::Element * element = m_message_delete_land_request->documentElement()->
        getChildElement("request")->getChildElement("delete_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_land_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("5", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_land_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandRequestSetsProperLandName)
{
    Poco::XML::Element * element = m_message_get_land_request->documentElement()->
        getChildElement("request")->getChildElement("get_land_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandsRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_lands_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("6", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandsRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_lands_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetLandsRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_lands_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_settlement_request.get());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_create_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("7", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_create_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_create_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestSetsProperLandName)
{
    Poco::XML::Element * element = m_message_create_settlement_request->documentElement()->
        getChildElement("request")->getChildElement("create_settlement_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementRequestSetsProperSettlementName)
{
    Poco::XML::Element * element = m_message_create_settlement_request->documentElement()->
        getChildElement("request")->getChildElement("create_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_settlement_request.get());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_delete_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("8", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_delete_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_delete_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementRequestSetsProperSettlementName)
{
    Poco::XML::Element * element = m_message_delete_settlement_request->documentElement()->
        getChildElement("request")->getChildElement("delete_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("9", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_settlement_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementRequestSetsProperSettlementName)
{
    Poco::XML::Element * element = m_message_get_settlement_request->documentElement()->
        getChildElement("request")->getChildElement("get_settlement_request")->getChildElement("settlement_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_settlements_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("10", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_settlements_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_settlements_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsRequestSetsProperLandName)
{
    Poco::XML::Element * element = m_message_get_settlements_request->documentElement()->
        getChildElement("request")->getChildElement("get_settlements_request")->getChildElement("land_name");
    ASSERT_STREQ("Land", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_build_building_request.get());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("11", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_build_building_request->documentElement()->
        getChildElement("request")->getChildElement("build_building_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_destroy_building_request.get());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("12", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_destroy_building_request->documentElement()->
        getChildElement("request")->getChildElement("destroy_building_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_building_request.get());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("13", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingRequestSetsProperBuildingKey)
{
    Poco::XML::Element * element = m_message_get_building_request->documentElement()->
        getChildElement("request")->getChildElement("get_building_request")->getChildElement("buildingkey");
    ASSERT_STREQ("RegularForge", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_buildings_request.get());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_buildings_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("14", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_buildings_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_buildings_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_buildings_request->documentElement()->
        getChildElement("request")->getChildElement("get_buildings_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_buildings_request->documentElement()->
        getChildElement("request")->getChildElement("get_buildings_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_dismiss_human_request.get());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("15", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperHumanKey)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_dismiss_human_request->documentElement()->
        getChildElement("request")->getChildElement("dismiss_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_engage_human_request.get());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("16", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperHumanKey)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_engage_human_request->documentElement()->
        getChildElement("request")->getChildElement("engage_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_human_request.get());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("17", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanRequestSetsProperHumanKey)
{
    Poco::XML::Element * element = m_message_get_human_request->documentElement()->
        getChildElement("request")->getChildElement("get_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_humans_request.get());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_humans_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("18", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_humans_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_humans_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_humans_request->documentElement()->
        getChildElement("request")->getChildElement("get_humans_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_humans_request->documentElement()->
        getChildElement("request")->getChildElement("get_humans_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_resources_request.get());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("19", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceRequestSetsProperResourceKey)
{
    Poco::XML::Element * element = m_message_get_resource_request->documentElement()->
        getChildElement("request")->getChildElement("get_resource_request")->getChildElement("resourcekey");
    ASSERT_STREQ("Coal", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_resources_request.get());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_resources_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("20", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_resources_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_resources_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestSetsProperIDHolderClass)
{
    Poco::XML::Element * element = m_message_get_resources_request->documentElement()->
        getChildElement("request")->getChildElement("get_resources_request")->getChildElement("idholderclass");
    ASSERT_STREQ("HolderClassSettlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesRequestSetsProperHolderName)
{
    Poco::XML::Element * element = m_message_get_resources_request->documentElement()->
        getChildElement("request")->getChildElement("get_resources_request")->getChildElement("holder_name");
    ASSERT_STREQ("Settlement", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_user_request.get());
}

TEST_F(MessageFactoryTest, CreateCreateUserRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_create_user_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("21", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_create_user_request->documentElement()->
        getChildElement("request")->getChildElement("create_user_request")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_create_user_request->documentElement()->
        getChildElement("request")->getChildElement("create_user_request")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_world_request.get());
}

TEST_F(MessageFactoryTest, CreateCreateWorldRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_create_world_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("22", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_create_world_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_create_world_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_create_world_request->documentElement()->
        getChildElement("request")->getChildElement("create_world_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_create_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("23", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_create_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_create_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_create_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("create_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochRequestSetsProperEpochName)
{
    Poco::XML::Element * element = m_message_create_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("create_epoch_request")->getChildElement("epoch_name");
    ASSERT_STREQ("Epoch", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_delete_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("24", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_delete_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_delete_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_delete_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("delete_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_activate_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateActivateEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_activate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("25", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_activate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_activate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_activate_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("activate_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_deactivate_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("26", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("deactivate_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_finish_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateFinishEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_finish_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("27", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_finish_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_finish_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_finish_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("finish_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_tick_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateTickEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_tick_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("28", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_tick_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_tick_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_tick_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("tick_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_get_epoch_request.get());
}

TEST_F(MessageFactoryTest, CreateGetEpochRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_get_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("29", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_get_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_get_epoch_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochRequestSetsProperWorldName)
{
    Poco::XML::Element * element = m_message_get_epoch_request->documentElement()->
        getChildElement("request")->getChildElement("get_epoch_request")->getChildElement("world_name");
    ASSERT_STREQ("World", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_transport_human_request.get());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("30", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperSettlementNameSource)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->
        getChildElement("settlement_name_source");
    ASSERT_STREQ("SettlementSource", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperSettlementNameDestination)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->
        getChildElement("settlement_name_destination");
    ASSERT_STREQ("SettlementDestination", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperHumanKey)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->getChildElement("humankey");
    ASSERT_STREQ("WorkerBlacksmithNovice", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_transport_human_request->documentElement()->
        getChildElement("request")->getChildElement("transport_human_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_message_transport_resource_request.get());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperID)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("31", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperLogin)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("login");
    ASSERT_STREQ("Login", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperPassword)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("header")->getChildElement("user")->getChildElement("password");
    ASSERT_STREQ("Password", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperSettlementNameSource)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->
        getChildElement("settlement_name_source");
    ASSERT_STREQ("SettlementSource", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperSettlementNameDestination)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->
        getChildElement("settlement_name_destination");
    ASSERT_STREQ("SettlementDestination", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperResourceKey)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->getChildElement("resourcekey");
    ASSERT_STREQ("Coal", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceRequestSetsProperVolume)
{
    Poco::XML::Element * element = m_message_transport_resource_request->documentElement()->
        getChildElement("request")->getChildElement("transport_resource_request")->getChildElement("volume");
    ASSERT_STREQ("100", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEchoReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_echo_reply.get());
}

TEST_F(MessageFactoryTest, CreateEchoReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_echo_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("32", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEchoReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_echo_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEchoReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_echo_reply->documentElement()->
        getChildElement("reply")->getChildElement("echo_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateErrorReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_error_reply.get());
}

TEST_F(MessageFactoryTest, CreateErrorReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_error_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("33", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateErrorReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_error_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateErrorReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_error_reply->documentElement()->
        getChildElement("reply")->getChildElement("error_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateCreateLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_land_reply.get());
}

TEST_F(MessageFactoryTest, CreateCreateLandReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_create_land_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("34", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_create_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateLandReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_create_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("create_land_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateDeleteLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_land_reply.get());
}

TEST_F(MessageFactoryTest, CreateDeleteLandReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_delete_land_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("35", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_delete_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteLandReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_delete_land_reply->documentElement()->
        getChildElement("reply")->getChildElement("delete_land_reply");
    ASSERT_TRUE(element != NULL);
}

class MessageFactoryTestCreateGetLandReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetLandReplyWithoutObject()
    {
        TUSProtocol::MessageFactory message_factory;
        m_message = message_factory.createGetLandReply("1", "Message");
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("36", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetLandReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetLandReplyWithObject()
    {
        TUSProtocol::MessageFactory message_factory;
        TUSProtocol::Message::Object land;
        land.insert(std::make_pair("login", "Login1"));
        land.insert(std::make_pair("world_name", "World1"));
        land.insert(std::make_pair("land_name", "Land1"));
        land.insert(std::make_pair("granted", "false"));
        m_message = message_factory.createGetLandReply("1", "Message", land);
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("36", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetLandReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_land_reply")->getChildElement("land");
    ASSERT_STREQ("Login1", element->getChildElement("login")->innerText().c_str());
    ASSERT_STREQ("World1", element->getChildElement("world_name")->innerText().c_str());
    ASSERT_STREQ("Land1", element->getChildElement("land_name")->innerText().c_str());
    ASSERT_STREQ("false", element->getChildElement("granted")->innerText().c_str());
}

class MessageFactoryTestCreateGetLandsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetLandsReplyWithoutObjects()
    {
        TUSProtocol::MessageFactory message_factory;
        m_message = message_factory.createGetLandsReply("1", "Message");
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("37", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithoutObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply")->getChildElement("lands");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetLandsReplyWithObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetLandsReplyWithObjects()
    {
        TUSProtocol::MessageFactory message_factory;
        TUSProtocol::Message::Object land_1, land_2;
        TUSProtocol::Message::Objects lands;
        land_1.insert(std::make_pair("login", "Login1"));
        land_1.insert(std::make_pair("world_name", "World1"));
        land_1.insert(std::make_pair("land_name", "Land1"));
        land_1.insert(std::make_pair("granted", "false"));
        land_2.insert(std::make_pair("login", "Login2"));
        land_2.insert(std::make_pair("world_name", "World2"));
        land_2.insert(std::make_pair("land_name", "Land2"));
        land_2.insert(std::make_pair("granted", "false"));
        lands.push_back(land_1);
        lands.push_back(land_2);
        m_message = message_factory.createGetLandsReply("1", "Message", lands);
    }

    TUSProtocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("37", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetLandsReplyWithObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_lands_reply")->getChildElement("lands");

    // TODO: Extend testing.
}

TEST_F(MessageFactoryTest, CreateCreateSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_settlement_reply.get());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_create_settlement_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("38", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_create_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateSettlementReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_create_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("create_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_settlement_reply.get());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_delete_settlement_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("39", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_delete_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_delete_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteSettlementReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_delete_settlement_reply->documentElement()->
        getChildElement("reply")->getChildElement("delete_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplySetsProperID)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("40", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplySetsProperCode)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetSettlementReplySetsProperObject)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementReply("1", "Message", m_settlement_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply")->getChildElement("settlement");
    ASSERT_STREQ("Land1", element->getChildElement("land_name")->innerText().c_str());
    ASSERT_STREQ("Settlement1", element->getChildElement("settlement_name")->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplySetsProperID)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("41", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplySetsProperCode)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetSettlementsReplySetsProperObjects)
{
    TUSProtocol::Message::Handle message =
        m_message_factory.createGetSettlementsReply("1", "Message", m_settlements);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply")->getChildElement("settlements");

    // TODO: Extend testing.
}

TEST_F(MessageFactoryTest, CreateBuildBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_build_building_reply.get());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_build_building_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("42", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_build_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_build_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateBuildBuildingReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_build_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("build_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_destroy_building_reply.get());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_destroy_building_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("43", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_destroy_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_destroy_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDestroyBuildingReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_destroy_building_reply->documentElement()->
        getChildElement("reply")->getChildElement("destroy_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("44", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetBuildingReplySetsProperObject)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingReply("1", "Message", m_building_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply")->getChildElement("building");
    ASSERT_STREQ("Regular", element->getChildElement("buildingclass")->innerText().c_str());
    ASSERT_STREQ("Farm", element->getChildElement("buildingname")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("45", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetBuildingsReplySetsProperObjects)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetBuildingsReply("1", "Message", m_buildings);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply")->getChildElement("buildings");

    // TODO: Extend testing.
}

TEST_F(MessageFactoryTest, CreateDismissHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_dismiss_human_reply.get());
}

TEST_F(MessageFactoryTest, CreateDismissHumanReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_dismiss_human_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("46", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_dismiss_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_dismiss_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDismissHumanReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_dismiss_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("dismiss_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateEngageHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_engage_human_reply.get());
}

TEST_F(MessageFactoryTest, CreateEngageHumanReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_engage_human_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("47", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_engage_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_engage_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateEngageHumanReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_engage_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("engage_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetHumanReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetHumanReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("48", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumanReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetHumanReplySetsProperObject)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumanReply("1", "Message", m_human_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply")->getChildElement("human");
    ASSERT_STREQ("Worker", element->getChildElement("humanclass")->innerText().c_str());
    ASSERT_STREQ("Farmer", element->getChildElement("humanname")->innerText().c_str());
    ASSERT_STREQ("Novice", element->getChildElement("experience")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetHumansReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("49", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetHumansReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetHumansReplySetsProperObjects)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetHumansReply("1", "Message", m_humans);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply")->getChildElement("humans");

    // TODO: Extend testing.
}

TEST_F(MessageFactoryTest, CreateGetResourceReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetResourceReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("50", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourceReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetResourceReplySetsProperObject)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourceReply("1", "Message", m_resource_1);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply")->getChildElement("resource");
    ASSERT_STREQ("Coal", element->getChildElement("resourcename")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("51", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetResourcesReplySetsProperObjects)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetResourcesReply("1", "Message", m_resources);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply")->getChildElement("resources");

    // TODO: Extend testing.
}

TEST_F(MessageFactoryTest, CreateCreateUserReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_user_reply.get());
}

TEST_F(MessageFactoryTest, CreateCreateUserReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_create_user_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("52", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_user_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_create_user_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateUserReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_create_user_reply->documentElement()->
        getChildElement("reply")->getChildElement("create_user_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateCreateWorldReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_world_reply.get());
}

TEST_F(MessageFactoryTest, CreateCreateWorldReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_create_world_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("53", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_world_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_create_world_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateWorldReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_create_world_reply->documentElement()->
        getChildElement("reply")->getChildElement("create_world_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateCreateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_create_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateCreateEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_create_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("54", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_create_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_create_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateCreateEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_create_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("create_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateDeleteEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_delete_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_delete_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("55", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_delete_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_delete_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeleteEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_delete_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("delete_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateActivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_activate_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateActivateEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_activate_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("56", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_activate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_activate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateActivateEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_activate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("activate_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_deactivate_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("57", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateDeactivateEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_deactivate_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("deactivate_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateFinishEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_finish_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateFinishEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_finish_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("58", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_finish_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_finish_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateFinishEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_finish_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("finish_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateTickEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_tick_epoch_reply.get());
}

TEST_F(MessageFactoryTest, CreateTickEpochReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_tick_epoch_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("59", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_tick_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_tick_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTickEpochReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_tick_epoch_reply->documentElement()->
        getChildElement("reply")->getChildElement("tick_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetEpochReplyReturnsNotNull)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    ASSERT_TRUE(message.get());
}

TEST_F(MessageFactoryTest, CreateGetEpochReplySetsProperID)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    Poco::XML::Element * element = message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("60", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochReplySetsProperCode)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochReplySetsProperMessage)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    Poco::XML::Element * element = message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateGetEpochReplySetsSpecificReply)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateGetEpochReplySetsProperObject)
{
    TUSProtocol::Message::Handle message = m_message_factory.createGetEpochReply("1", "Message", m_epoch);
    Poco::XML::Element * element = message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply")->getChildElement("epoch");
    ASSERT_STREQ("Epoch", element->getChildElement("epoch_name")->innerText().c_str());
    ASSERT_STREQ("World", element->getChildElement("world_name")->innerText().c_str());
    ASSERT_STREQ("true", element->getChildElement("active")->innerText().c_str());
    ASSERT_STREQ("false", element->getChildElement("finished")->innerText().c_str());
    ASSERT_STREQ("22", element->getChildElement("ticks")->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_transport_human_reply.get());
}

TEST_F(MessageFactoryTest, CreateTransportHumanReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_transport_human_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("61", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_transport_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_transport_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportHumanReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_transport_human_reply->documentElement()->
        getChildElement("reply")->getChildElement("transport_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTest, CreateTransportResourceReplyReturnsNotNull)
{
    ASSERT_TRUE(m_message_transport_resource_reply.get());
}

TEST_F(MessageFactoryTest, CreateTransportResourceReplySetsProperReplyID)
{
    Poco::XML::Element * element = m_message_transport_resource_reply->documentElement()->
        getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("62", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceReplySetsProperCode)
{
    Poco::XML::Element * element = m_message_transport_resource_reply->documentElement()->
        getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceReplySetsProperMessage)
{
    Poco::XML::Element * element = m_message_transport_resource_reply->documentElement()->
        getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTest, CreateTransportResourceReplySetsSpecificReply)
{
    Poco::XML::Element * element = m_message_transport_resource_reply->documentElement()->
        getChildElement("reply")->getChildElement("transport_resource_reply");
    ASSERT_TRUE(element != NULL);
}
