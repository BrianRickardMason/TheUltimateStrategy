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

#include "../Interface/ReplyBuilder.hpp"
#include <gtest/gtest.h>

class ReplyBuilderTest
    : public ::testing::Test
{
protected:
    /**
     * @brief Ctor.
     */
    ReplyBuilderTest()
        : m_command_echo_reply(m_reply_builder.buildEchoReply(1))
    {
    }

    /**
     * @brief The reply builder to be tested.
     */
    TUSLanguage::ReplyBuilder m_reply_builder;

    /**
     * @brief The command to be tested.
     */
    TUSLanguage::ICommand::SingleHandle m_command_echo_reply;
};

TEST_F(ReplyBuilderTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(TUSLanguage::ReplyBuilder reply_builder);
}

TEST_F(ReplyBuilderTest, BuildEchoReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_echo_reply.get());
}

TEST_F(ReplyBuilderTest, BuildEchoReplySetsProperReplyID)
{
    ASSERT_EQ(32, m_command_echo_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildEchoReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_echo_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildErrorReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildErrorReply().get());
}

TEST_F(ReplyBuilderTest, BuildCreateLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildCreateLandReply().get());
}

TEST_F(ReplyBuilderTest, BuildDeleteLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDeleteLandReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetLandReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetLandsReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetLandsReply().get());
}

TEST_F(ReplyBuilderTest, BuildCreateSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildCreateSettlementReply().get());
}

TEST_F(ReplyBuilderTest, BuildDeleteSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDeleteSettlementReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetSettlementReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetSettlementsReply().get());
}

TEST_F(ReplyBuilderTest, BuildBuildBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildBuildBuildingReply().get());
}

TEST_F(ReplyBuilderTest, BuildDestroyBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDestroyBuildingReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetBuildingReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetBuildingsReply().get());
}

TEST_F(ReplyBuilderTest, BuildDismissHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDismissHumanReply().get());
}

TEST_F(ReplyBuilderTest, BuildEngageHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildEngageHumanReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetHumanReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetHumansReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetResourceReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetResourcesReply().get());
}

TEST_F(ReplyBuilderTest, BuildCreateUserReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildCreateUserReply().get());
}

TEST_F(ReplyBuilderTest, BuildCreateWorldReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildCreateWorldReply().get());
}

TEST_F(ReplyBuilderTest, BuildDeleteEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDeleteEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildActivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildActivateEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildDeactivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildDeactivateEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildFinishEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildFinishEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildTickEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildTickEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildTransportHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildTransportHumanReply().get());
}

TEST_F(ReplyBuilderTest, BuildTransportResourceReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildTransportResourceReply().get());
}
