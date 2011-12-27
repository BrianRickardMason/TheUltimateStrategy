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
     * @brief The request builder to be tested.
     */
    TUSLanguage::RequestBuilder m_request_builder;
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
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_TRUE(command.get());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperRequestID)
{
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_EQ(3, command->getID());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperLogin)
{
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_STREQ("Login", command->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperPassword)
{
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_STREQ("Password", command->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperWorldName)
{
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_STREQ("World", command->getParam("world_name").c_str());
}

TEST_F(RequestBuilderTest, BuildCreateLandRequestSetsProperLandName)
{
    TUSLanguage::ICommand::SingleHandle command =
        m_request_builder.buildCreateLandRequest("Login", "Password", "World", "Land");
    ASSERT_STREQ("Land", command->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestReturnsNotNull)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildDeleteLandRequest("Login", "Password", "Land");
    ASSERT_TRUE(command.get());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperRequestID)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildDeleteLandRequest("Login", "Password", "Land");
    ASSERT_EQ(4, command->getID());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperLogin)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildDeleteLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Login", command->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperPassword)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildDeleteLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Password", command->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildDeleteLandRequestSetsProperLandName)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildDeleteLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Land", command->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestReturnsNotNull)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandRequest("Login", "Password", "Land");
    ASSERT_TRUE(command.get());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperRequestID)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandRequest("Login", "Password", "Land");
    ASSERT_EQ(5, command->getID());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperLogin)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Login", command->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperPassword)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Password", command->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandRequestSetsProperLandName)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandRequest("Login", "Password", "Land");
    ASSERT_STREQ("Land", command->getParam("land_name").c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperRequestID)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandsRequest("Login", "Password");
    ASSERT_EQ(6, command->getID());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperLogin)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandsRequest("Login", "Password");
    ASSERT_STREQ("Login", command->getLogin().c_str());
}

TEST_F(RequestBuilderTest, BuildGetLandsRequestSetsProperPassword)
{
    TUSLanguage::ICommand::SingleHandle command = m_request_builder.buildGetLandsRequest("Login", "Password");
    ASSERT_STREQ("Password", command->getPassword().c_str());
}

TEST_F(RequestBuilderTest, BuildCreateSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildCreateSettlementRequest().get());
}

TEST_F(RequestBuilderTest, BuildDeleteSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildDeleteSettlementRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetSettlementRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetSettlementRequest().get());
}

TEST_F(RequestBuilderTest, BuildGetSettlementsRequestReturnsNotNull)
{
    ASSERT_TRUE(m_request_builder.buildGetSettlementsRequest().get());
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
