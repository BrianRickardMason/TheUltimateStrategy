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

#include "../Interface/RequestBuilder.hpp"
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
          m_command_create_settlement(m_request_builder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement")),
          m_command_delete_settlement(m_request_builder.buildDeleteSettlementRequest("Login", "Password", "Settlement")),
          m_command_get_settlement(m_request_builder.buildGetSettlementRequest("Login", "Password", "Settlement")),
          m_command_get_settlements(m_request_builder.buildGetSettlementsRequest("Login", "Password", "Land"))
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
                                        m_command_get_settlements;
};

TEST_F(RequestBuilderTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(TUSLanguage::RequestBuilder request_builder);
}

TEST_F(RequestBuilderTest, BuildEchoRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildEchoRequest().get());
}

TEST_F(RequestBuilderTest, BuildEchoRequestSetsProperRequestID)
{
    ASSERT_EQ(1, m_request_builder.buildEchoRequest()->getID());
}

TEST_F(RequestBuilderTest, BuildErrorRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildErrorRequest().get());
}

TEST_F(RequestBuilderTest, BuildErrorRequestSetsProperRequestID)
{
    ASSERT_EQ(2, m_request_builder.buildErrorRequest()->getID());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_land.get());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildGetSettlementRequestSetsProperRequestID)
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

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestSetsProperRequestID)
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
    ASSERT_TRUE(m_request_builder.buildBuildBuildingRequest().get());
}

TEST_F(RequestBuilderTest, BuildDestroyBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildDestroyBuildingRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetBuildingRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetBuildingRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetBuildingsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetBuildingsRequest().get());
}

TEST_F(RequestBuilderTest, BuildDismissHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildDismissHumanRequest().get());
}

TEST_F(RequestBuilderTest, BuildEngageHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildEngageHumanRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetHumanRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetHumansRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetHumansRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetResourceRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetResourcesRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetResourcesRequest().get());
}

TEST_F(RequestBuilderTest, BuildCreateUserRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildCreateUserRequest().get());
}

TEST_F(RequestBuilderTest, BuildCreateWorldRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildCreateWorldRequest().get());
}

TEST_F(RequestBuilderTest, BuildDeleteEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildDeleteEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildActivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildActivateEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildDeactivateEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildDeactivateEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildFinishEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildFinishEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildTickEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildTickEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetEpochRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetEpochRequest().get());
}

TEST_F(RequestBuilderTest, BuildTransportHumanRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildTransportHumanRequest().get());
}

TEST_F(RequestBuilderTest, BuildTransportResourceRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildTransportResourceRequest().get());
}
