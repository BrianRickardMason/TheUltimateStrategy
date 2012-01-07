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
              "Login", "Password", "SettlementSource", "SettlementDestination", "Coal", "100"))
    {
    }

    /**
     * @brief The message factory to be tested.
     */
    TUSProtocol::MessageFactory m_message_factory;

    //@{
    /**
     * @brief The message to be tested.
     */
    TUSProtocol::Message::SingleHandle m_message_echo_request,
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
                                       m_message_transport_resource_request;
    //}@
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
