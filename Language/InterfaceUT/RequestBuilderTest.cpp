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

#include <Language/Interface/RequestBuilder.hpp>
#include <gtest/gtest.h>

class RequestBuilderTest
    : public ::testing::Test
{
protected:
    /**
     * @brief Ctor.
     */
    RequestBuilderTest()
        : m_command_create_land(m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land")),
          m_command_delete_land(m_request_builder.buildDeleteLandRequest("Login", "Password", "Land")),
          m_command_get_land(m_request_builder.buildGetLandRequest("Login", "Password", "Land")),
          m_command_get_lands(m_request_builder.buildGetLandsRequest("Login", "Password")),
          m_command_create_settlement(m_request_builder.buildCreateSettlementRequest(
              "Login", "Password", "Land", "Settlement")),
          m_command_delete_settlement(m_request_builder.buildDeleteSettlementRequest(
              "Login", "Password", "Settlement")),
          m_command_get_settlement(m_request_builder.buildGetSettlementRequest("Login", "Password", "Settlement")),
          m_command_get_settlements(m_request_builder.buildGetSettlementsRequest("Login", "Password", "Land")),
          m_command_build_building(m_request_builder.buildBuildBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100")),
          m_command_destroy_building(m_request_builder.buildDestroyBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge", "100")),
          m_command_get_building(m_request_builder.buildGetBuildingRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "RegularForge")),
          m_command_get_buildings(m_request_builder.buildGetBuildingsRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_command_dismiss_human(m_request_builder.buildDismissHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100")),
          m_command_engage_human(m_request_builder.buildEngageHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice", "100")),
          m_command_get_human(m_request_builder.buildGetHumanRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "WorkerBlacksmithNovice")),
          m_command_get_humans(m_request_builder.buildGetHumansRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_command_get_resource(m_request_builder.buildGetResourceRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement", "Coal")),
          m_command_get_resources(m_request_builder.buildGetResourcesRequest(
              "Login", "Password", "HolderClassSettlement", "Settlement")),
          m_command_create_user(m_request_builder.buildCreateUserRequest("Login", "Password")),
          m_command_create_world(m_request_builder.buildCreateWorldRequest("Login", "Password", "World")),
          m_command_create_epoch(m_request_builder.buildCreateEpochRequest("Login", "Password", "World", "Epoch")),
          m_command_delete_epoch(m_request_builder.buildDeleteEpochRequest("Login", "Password", "World")),
          m_command_activate_epoch(m_request_builder.buildActivateEpochRequest("Login", "Password", "World")),
          m_command_deactivate_epoch(m_request_builder.buildDeactivateEpochRequest("Login", "Password", "World")),
          m_command_finish_epoch(m_request_builder.buildFinishEpochRequest("Login", "Password", "World")),
          m_command_tick_epoch(m_request_builder.buildTickEpochRequest("Login", "Password", "World")),
          m_command_get_epoch(m_request_builder.buildGetEpochRequest("Login", "Password", "World")),
          m_command_transport_human(m_request_builder.buildTransportHumanRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "WorkerBlacksmithNovice", "100")),
          m_command_transport_resource(m_request_builder.buildTransportResourceRequest(
              "Login", "Password", "SettlementSource", "SettlementDestination", "Coal", "100"))
    {
    }

    /**
     * @brief The request builder to be tested.
     */
    TUSLanguage::RequestBuilder m_request_builder;

    //@{
    /**
     * @brief The command to be tested.
     */
    TUSLanguage::ICommand::SingleHandle m_command_create_land,
                                        m_command_delete_land,
                                        m_command_get_land,
                                        m_command_get_lands,
                                        m_command_create_settlement,
                                        m_command_delete_settlement,
                                        m_command_get_settlement,
                                        m_command_get_settlements,
                                        m_command_build_building,
                                        m_command_destroy_building,
                                        m_command_get_building,
                                        m_command_get_buildings,
                                        m_command_dismiss_human,
                                        m_command_engage_human,
                                        m_command_get_human,
                                        m_command_get_humans,
                                        m_command_get_resource,
                                        m_command_get_resources,
                                        m_command_create_user,
                                        m_command_create_world,
                                        m_command_create_epoch,
                                        m_command_delete_epoch,
                                        m_command_activate_epoch,
                                        m_command_deactivate_epoch,
                                        m_command_finish_epoch,
                                        m_command_tick_epoch,
                                        m_command_get_epoch,
                                        m_command_transport_human,
                                        m_command_transport_resource;
    //}@
};

TEST_F(RequestBuilderTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(TUSLanguage::RequestBuilder request_builder);
}

TEST_F(RequestBuilderTest, BuildEchoRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildEchoRequest().get());
}

TEST_F(RequestBuilderTest, BuildEchoRequestSetsProperID)
{
    ASSERT_EQ(1, m_request_builder.buildEchoRequest()->getID());
}

TEST_F(RequestBuilderTest, BuildErrorRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildErrorRequest().get());
}

TEST_F(RequestBuilderTest, BuildErrorRequestSetsProperID)
{
    ASSERT_EQ(2, m_request_builder.buildErrorRequest()->getID());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_land.get());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperID)
{
    ASSERT_EQ(3, m_command_create_land->getID());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_create_land->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_create_land->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_create_land->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperLandName)
{
    ASSERT_STREQ("Land", m_command_create_land->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_land.get());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperID)
{
    ASSERT_EQ(4, m_command_delete_land->getID());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_delete_land->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_delete_land->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperLandName)
{
    ASSERT_STREQ("Land", m_command_delete_land->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_land.get());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperID)
{
    ASSERT_EQ(5, m_command_get_land->getID());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_land->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_land->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperLandName)
{
    ASSERT_STREQ("Land", m_command_get_land->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_lands.get());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperID)
{
    ASSERT_EQ(6, m_command_get_lands->getID());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_lands->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_lands->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_settlement.get());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperID)
{
    ASSERT_EQ(7, m_command_create_settlement->getID());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_create_settlement->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_create_settlement->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperLandName)
{
    ASSERT_STREQ("Land", m_command_create_settlement->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command_create_settlement->getParam("settlement_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_settlement.get());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestSetsProperID)
{
    ASSERT_EQ(8, m_command_delete_settlement->getID());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_delete_settlement->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_delete_settlement->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestSetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command_delete_settlement->getParam("settlement_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_settlement.get());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestSetsProperID)
{
    ASSERT_EQ(9, m_command_get_settlement->getID());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_settlement->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_settlement->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestSetsProperSettlementName)
{
    ASSERT_STREQ("Settlement", m_command_get_settlement->getParam("settlement_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_settlements.get());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestSetsProperID)
{
    ASSERT_EQ(10, m_command_get_settlements->getID());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_settlements->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_settlements->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestSetsProperLandName)
{
    ASSERT_STREQ("Land", m_command_get_settlements->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_build_building.get());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperID)
{
    ASSERT_EQ(11, m_command_build_building->getID());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_build_building->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_build_building->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_build_building->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_build_building->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command_build_building->getParam("buildingkey").c_str());
}

TEST_F(RequestBuilderTest, BuildBuildBuildingRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_build_building->getParam("volume").c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_destroy_building.get());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperID)
{
    ASSERT_EQ(12, m_command_destroy_building->getID());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_destroy_building->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_destroy_building->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_destroy_building->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_destroy_building->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command_destroy_building->getParam("buildingkey").c_str());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_destroy_building->getParam("volume").c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_building.get());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperID)
{
    ASSERT_EQ(13, m_command_get_building->getID());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_building->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_building->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_building->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_building->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestSetsProperBuildingKey)
{
    ASSERT_STREQ("RegularForge", m_command_get_building->getParam("buildingkey").c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_buildings.get());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestSetsProperID)
{
    ASSERT_EQ(14, m_command_get_buildings->getID());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_buildings->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_buildings->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_buildings->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_buildings->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_dismiss_human.get());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperID)
{
    ASSERT_EQ(15, m_command_dismiss_human->getID());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_dismiss_human->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_dismiss_human->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_dismiss_human->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_dismiss_human->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command_dismiss_human->getParam("humankey").c_str());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_dismiss_human->getParam("volume").c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_engage_human.get());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperID)
{
    ASSERT_EQ(16, m_command_engage_human->getID());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_engage_human->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_engage_human->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_engage_human->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_engage_human->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command_engage_human->getParam("humankey").c_str());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_engage_human->getParam("volume").c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_human.get());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperID)
{
    ASSERT_EQ(17, m_command_get_human->getID());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_human->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_human->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_human->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_human->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestSetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command_get_human->getParam("humankey").c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_humans.get());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestSetsProperID)
{
    ASSERT_EQ(18, m_command_get_humans->getID());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_humans->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_humans->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_humans->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_humans->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_resource.get());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperID)
{
    ASSERT_EQ(19, m_command_get_resource->getID());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_resource->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_resource->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_resource->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_resource->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestSetsProperResourceKey)
{
    ASSERT_STREQ("Coal", m_command_get_resource->getParam("resourcekey").c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_resources.get());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestSetsProperID)
{
    ASSERT_EQ(20, m_command_get_resources->getID());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_resources->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_resources->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestSetsProperIDHolderClass)
{
    ASSERT_STREQ("HolderClassSettlement", m_command_get_resources->getParam("idholderclass").c_str());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestSetsProperHolderName)
{
    ASSERT_STREQ("Settlement", m_command_get_resources->getParam("holder_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_user.get());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestSetsProperID)
{
    ASSERT_EQ(21, m_command_create_user->getID());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestDoesNotSetLogin)
{
    ASSERT_STREQ("", m_command_create_user->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestDoesNotSetPassword)
{
    ASSERT_STREQ("", m_command_create_user->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_create_user->getParam("login").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_create_user->getParam("password").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_world.get());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestSetsProperID)
{
    ASSERT_EQ(22, m_command_create_world->getID());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_create_world->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_create_world->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_create_world->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_epoch.get());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestSetsProperID)
{
    ASSERT_EQ(23, m_command_create_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_create_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_create_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_create_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateEpochRequestSetsProperEpochName)
{
    ASSERT_STREQ("Epoch", m_command_create_epoch->getParam("epoch_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_epoch.get());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestSetsProperID)
{
    ASSERT_EQ(24, m_command_delete_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_delete_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_delete_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_delete_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_activate_epoch.get());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestSetsProperID)
{
    ASSERT_EQ(25, m_command_activate_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_activate_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_activate_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_activate_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_deactivate_epoch.get());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestSetsProperID)
{
    ASSERT_EQ(26, m_command_deactivate_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_deactivate_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_deactivate_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_deactivate_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_finish_epoch.get());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestSetsProperID)
{
    ASSERT_EQ(27, m_command_finish_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_finish_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_finish_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_finish_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_tick_epoch.get());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestSetsProperID)
{
    ASSERT_EQ(28, m_command_tick_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_tick_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_tick_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_tick_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_get_epoch.get());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestSetsProperID)
{
    ASSERT_EQ(29, m_command_get_epoch->getID());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_get_epoch->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_get_epoch->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestSetsProperWorldName)
{
    ASSERT_STREQ("World", m_command_get_epoch->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_transport_human.get());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperID)
{
    ASSERT_EQ(30, m_command_transport_human->getID());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_transport_human->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_transport_human->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperSettlementNameSource)
{
    ASSERT_STREQ("SettlementSource", m_command_transport_human->getParam("settlement_name_source").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperSettlementNameDestination)
{
    ASSERT_STREQ("SettlementDestination", m_command_transport_human->getParam("settlement_name_destination").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperHumanKey)
{
    ASSERT_STREQ("WorkerBlacksmithNovice", m_command_transport_human->getParam("humankey").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_transport_human->getParam("volume").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_transport_resource.get());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperID)
{
    ASSERT_EQ(31, m_command_transport_resource->getID());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperLogin)
{
    ASSERT_STREQ("Login", m_command_transport_resource->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperPassword)
{
    ASSERT_STREQ("Password", m_command_transport_resource->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperSettlementNameSource)
{
    ASSERT_STREQ("SettlementSource", m_command_transport_resource->getParam("settlement_name_source").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperSettlementNameDestination)
{
    ASSERT_STREQ("SettlementDestination", m_command_transport_resource->getParam("settlement_name_destination").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperResourceKey)
{
    ASSERT_STREQ("Coal", m_command_transport_resource->getParam("resourcekey").c_str());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestSetsProperVolume)
{
    ASSERT_STREQ("100", m_command_transport_resource->getParam("volume").c_str());
}
