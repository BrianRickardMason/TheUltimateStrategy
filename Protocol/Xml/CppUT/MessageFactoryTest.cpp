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
    }

    /**
     * @brief The message factory to be tested.
     */
    Protocol::MessageFactory m_message_factory;

    //@{
    /**
     * @brief The message to be tested.
     */
    Protocol::Message::Handle m_message_echo_request,
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
                                 m_message_build_building_reply,
                                 m_message_destroy_building_reply,
                                 m_message_dismiss_human_reply,
                                 m_message_engage_human_reply,
                                 m_message_create_user_reply,
                                 m_message_create_world_reply,
                                 m_message_create_epoch_reply,
                                 m_message_delete_epoch_reply,
                                 m_message_activate_epoch_reply,
                                 m_message_deactivate_epoch_reply,
                                 m_message_finish_epoch_reply,
                                 m_message_tick_epoch_reply,
                                 m_message_transport_human_reply,
                                 m_message_transport_resource_reply;
    //}@
};

TEST_F(MessageFactoryTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(Protocol::MessageFactory message_factory);
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
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetLandReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
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
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object land;
        land.insert(std::make_pair("login", "Login1"));
        land.insert(std::make_pair("world_name", "World1"));
        land.insert(std::make_pair("land_name", "Land1"));
        land.insert(std::make_pair("granted", "false"));
        m_message = message_factory.createGetLandReply("1", "Message", land);
    }

    Protocol::Message::Handle m_message;
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
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetLandsReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
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
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object land_1, land_2;
        Protocol::Message::Objects lands;
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

    Protocol::Message::Handle m_message;
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

class MessageFactoryTestCreateGetSettlementReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetSettlementReplyWithoutObject()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetSettlementReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("40", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply")->getChildElement("settlement");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetSettlementReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetSettlementReplyWithObject()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object settlement;
        settlement.insert(std::make_pair("land_name", "Land1"));
        settlement.insert(std::make_pair("settlement_name", "Settlement1"));
        m_message = message_factory.createGetSettlementReply("1", "Message", settlement);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("40", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply")->getChildElement("settlement");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetSettlementReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlement_reply")->getChildElement("settlement");
    ASSERT_STREQ("Land1", element->getChildElement("land_name")->innerText().c_str());
    ASSERT_STREQ("Settlement1", element->getChildElement("settlement_name")->innerText().c_str());
}

class MessageFactoryTestCreateGetSettlementsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetSettlementsReplyWithoutObjects()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetSettlementsReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("41", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithoutObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply")->getChildElement("settlements");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetSettlementsReplyWithObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetSettlementsReplyWithObjects()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object settlement_1, settlement_2;
        Protocol::Message::Objects settlements;
        settlement_1.insert(std::make_pair("land_name", "Land1"));
        settlement_1.insert(std::make_pair("settlement_name", "Settlement1"));
        settlement_2.insert(std::make_pair("land_name", "Land2"));
        settlement_2.insert(std::make_pair("settlement_name", "Settlement2"));
        settlements.push_back(settlement_1);
        settlements.push_back(settlement_2);
        m_message = message_factory.createGetSettlementsReply("1", "Message", settlements);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("41", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_settlements_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetSettlementsReplyWithObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
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

class MessageFactoryTestCreateGetBuildingReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetBuildingReplyWithoutObject()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetBuildingReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("44", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply")->getChildElement("building");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetBuildingReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetBuildingReplyWithObject()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object building;
        building.insert(std::make_pair("buildingclass", "Regular"));
        building.insert(std::make_pair("buildingname", "Farm"));
        building.insert(std::make_pair("volume", "10"));
        m_message = message_factory.createGetBuildingReply("1", "Message", building);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("44", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply")->getChildElement("building");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetBuildingReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_building_reply")->getChildElement("building");
    ASSERT_STREQ("Regular", element->getChildElement("buildingclass")->innerText().c_str());
    ASSERT_STREQ("Farm", element->getChildElement("buildingname")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class MessageFactoryTestCreateGetBuildingsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetBuildingsReplyWithoutObjects()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetBuildingsReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("45", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithoutObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply")->getChildElement("buildings");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetBuildingsReplyWithObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetBuildingsReplyWithObjects()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object building_1, building_2;
        Protocol::Message::Objects buildings;
        building_1.insert(std::make_pair("buildingclass", "Regular"));
        building_1.insert(std::make_pair("buildingname", "Farm"));
        building_1.insert(std::make_pair("volume", "10"));
        building_2.insert(std::make_pair("buildingclass", "Regular"));
        building_2.insert(std::make_pair("buildingname", "Sawmill"));
        building_2.insert(std::make_pair("volume", "20"));
        buildings.push_back(building_1);
        buildings.push_back(building_2);
        m_message = message_factory.createGetBuildingsReply("1", "Message", buildings);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("45", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_buildings_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetBuildingsReplyWithObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
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

class MessageFactoryTestCreateGetHumanReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetHumanReplyWithoutObject()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetHumanReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("48", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply")->getChildElement("human");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetHumanReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetHumanReplyWithObject()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object human;
        human.insert(std::make_pair("humanclass", "Worker"));
        human.insert(std::make_pair("humanname", "Farmer"));
        human.insert(std::make_pair("experience", "Novice"));
        human.insert(std::make_pair("volume", "10"));
        m_message = message_factory.createGetHumanReply("1", "Message", human);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("48", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply")->getChildElement("human");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetHumanReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_human_reply")->getChildElement("human");
    ASSERT_STREQ("Worker", element->getChildElement("humanclass")->innerText().c_str());
    ASSERT_STREQ("Farmer", element->getChildElement("humanname")->innerText().c_str());
    ASSERT_STREQ("Novice", element->getChildElement("experience")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class MessageFactoryTestCreateGetHumansReplyWithoutObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetHumansReplyWithoutObjects()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetHumansReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("49", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithoutObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply")->getChildElement("humans");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetHumansReplyWithObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetHumansReplyWithObjects()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object human_1, human_2;
        Protocol::Message::Objects humans;
        human_1.insert(std::make_pair("humanclass", "Worker"));
        human_1.insert(std::make_pair("humanname", "Farmer"));
        human_1.insert(std::make_pair("experience", "Novice"));
        human_1.insert(std::make_pair("volume", "10"));
        human_2.insert(std::make_pair("humanclass", "Worker"));
        human_2.insert(std::make_pair("humanname", "Steelworker"));
        human_2.insert(std::make_pair("experience", "Advanced"));
        human_2.insert(std::make_pair("volume", "20"));
        humans.push_back(human_1);
        humans.push_back(human_2);
        m_message = message_factory.createGetHumansReply("1", "Message", humans);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("49", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetHumansReplyWithObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_humans_reply")->getChildElement("humans");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetResourceReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetResourceReplyWithoutObject()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetResourceReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("50", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply")->getChildElement("resource");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetResourceReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetResourceReplyWithObject()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object resource;
        resource.insert(std::make_pair("resourcename", "Coal"));
        resource.insert(std::make_pair("volume", "10"));
        m_message = message_factory.createGetResourceReply("1", "Message", resource);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("50", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply")->getChildElement("resource");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetResourceReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resource_reply")->getChildElement("resource");
    ASSERT_STREQ("Coal", element->getChildElement("resourcename")->innerText().c_str());
    ASSERT_STREQ("10", element->getChildElement("volume")->innerText().c_str());
}

class MessageFactoryTestCreateGetResourcesReplyWithoutObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetResourcesReplyWithoutObjects()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetResourcesReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("51", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithoutObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply")->getChildElement("resources");

    // TODO: Extend testing.
}

class MessageFactoryTestCreateGetResourcesReplyWithObjects
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetResourcesReplyWithObjects()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object resource_1, resource_2;
        Protocol::Message::Objects resources;
        resource_1.insert(std::make_pair("resourcename", "Coal"));
        resource_1.insert(std::make_pair("volume", "10"));
        resource_2.insert(std::make_pair("resourcename", "Wood"));
        resource_2.insert(std::make_pair("volume", "20"));
        resources.push_back(resource_1);
        resources.push_back(resource_2);
        m_message = message_factory.createGetResourcesReply("1", "Message", resources);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("51", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_resources_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetResourcesReplyWithObjects, SetsProperObjects)
{
    Poco::XML::Element * element = m_message->documentElement()->
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

class MessageFactoryTestCreateGetEpochReplyWithoutObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetEpochReplyWithoutObject()
    {
        Protocol::MessageFactory message_factory;
        m_message = message_factory.createGetEpochReply("1", "Message");
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("60", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithoutObject, DoesNotSetObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply")->getChildElement("epoch");
    ASSERT_TRUE(element == NULL);
}

class MessageFactoryTestCreateGetEpochReplyWithObject
    : public ::testing::Test
{
protected:
    MessageFactoryTestCreateGetEpochReplyWithObject()
    {
        Protocol::MessageFactory message_factory;
        Protocol::Message::Object epoch;
        epoch.insert(std::make_pair("epoch_name", "Epoch"));
        epoch.insert(std::make_pair("world_name", "World"));
        epoch.insert(std::make_pair("active", "true"));
        epoch.insert(std::make_pair("finished", "false"));
        epoch.insert(std::make_pair("ticks", "22"));
        m_message = message_factory.createGetEpochReply("1", "Message", epoch);
    }

    Protocol::Message::Handle m_message;
};

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_message.get());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsProperID)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("header")->getChildElement("id");
    ASSERT_STREQ("60", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsProperCode)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("code");
    ASSERT_STREQ("1", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsProperMessage)
{
    Poco::XML::Element * element = m_message->documentElement()->getChildElement("reply")->getChildElement("message");
    ASSERT_STREQ("Message", element->innerText().c_str());
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsSpecificReply)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
        getChildElement("reply")->getChildElement("get_epoch_reply")->getChildElement("epoch");
    ASSERT_TRUE(element != NULL);
}

TEST_F(MessageFactoryTestCreateGetEpochReplyWithObject, SetsProperObject)
{
    Poco::XML::Element * element = m_message->documentElement()->
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
