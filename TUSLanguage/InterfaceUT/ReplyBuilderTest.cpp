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
        : m_command_echo_reply(m_reply_builder.buildEchoReply(1)),
          m_command_error_reply(m_reply_builder.buildErrorReply(1)),
          m_command_create_land_reply(m_reply_builder.buildCreateLandReply(1, "Message")),
          m_command_delete_land_reply(m_reply_builder.buildDeleteLandReply(1, "Message")),
          m_command_create_settlement_reply(m_reply_builder.buildCreateSettlementReply(1, "Message")),
          m_command_delete_settlement_reply(m_reply_builder.buildDeleteSettlementReply(1, "Message")),
          m_command_build_building_reply(m_reply_builder.buildBuildBuildingReply(1, "Message")),
          m_command_destroy_building_reply(m_reply_builder.buildDestroyBuildingReply(1, "Message")),
          m_command_dismiss_human_reply(m_reply_builder.buildDismissHumanReply(1, "Message")),
          m_command_engage_human_reply(m_reply_builder.buildEngageHumanReply(1, "Message")),
          m_command_create_user_reply(m_reply_builder.buildCreateUserReply(1, "Message")),
          m_command_create_world_reply(m_reply_builder.buildCreateWorldReply(1, "Message")),
          m_command_create_epoch_reply(m_reply_builder.buildCreateEpochReply(1, "Message")),
          m_command_delete_epoch_reply(m_reply_builder.buildDeleteEpochReply(1, "Message")),
          m_command_activate_epoch_reply(m_reply_builder.buildActivateEpochReply(1, "Message")),
          m_command_deactivate_epoch_reply(m_reply_builder.buildDeactivateEpochReply(1, "Message")),
          m_command_finish_epoch_reply(m_reply_builder.buildFinishEpochReply(1, "Message")),
          m_command_tick_epoch_reply(m_reply_builder.buildTickEpochReply(1, "Message")),
          m_command_transport_human_reply(m_reply_builder.buildTransportHumanReply(1, "Message")),
          m_command_transport_resource_reply(m_reply_builder.buildTransportResourceReply(1, "Message"))
    {
    }

    /**
     * @brief The reply builder to be tested.
     */
    TUSLanguage::ReplyBuilder m_reply_builder;

    //@{
    /**
     * @brief The command to be tested.
     */
    TUSLanguage::ICommand::SingleHandle m_command_echo_reply,
                                        m_command_error_reply,
                                        m_command_create_land_reply,
                                        m_command_delete_land_reply,
                                        m_command_create_settlement_reply,
                                        m_command_delete_settlement_reply,
                                        m_command_build_building_reply,
                                        m_command_destroy_building_reply,
                                        m_command_dismiss_human_reply,
                                        m_command_engage_human_reply,
                                        m_command_create_user_reply,
                                        m_command_create_world_reply,
                                        m_command_create_epoch_reply,
                                        m_command_delete_epoch_reply,
                                        m_command_activate_epoch_reply,
                                        m_command_deactivate_epoch_reply,
                                        m_command_finish_epoch_reply,
                                        m_command_tick_epoch_reply,
                                        m_command_transport_human_reply,
                                        m_command_transport_resource_reply;
    //}@
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
    ASSERT_TRUE(m_command_error_reply.get());
}

TEST_F(ReplyBuilderTest, BuildErrorReplySetsProperReplyID)
{
    ASSERT_EQ(33, m_command_error_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildErrorReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_error_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_land_reply.get());
}

TEST_F(ReplyBuilderTest, BuildCreateLandReplySetsProperReplyID)
{
    ASSERT_EQ(34, m_command_create_land_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildCreateLandReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_create_land_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateLandReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_create_land_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildDeleteLandReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_land_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDeleteLandReplySetsProperReplyID)
{
    ASSERT_EQ(35, m_command_delete_land_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDeleteLandReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_delete_land_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDeleteLandReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_delete_land_reply->getMessage().c_str());
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
    ASSERT_TRUE(m_command_create_settlement_reply.get());
}

TEST_F(ReplyBuilderTest, BuildCreateSettlementReplySetsProperReplyID)
{
    ASSERT_EQ(38, m_command_create_settlement_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildCreateSettlementReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_create_settlement_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateSettlementReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_create_settlement_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildDeleteSettlementReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_settlement_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDeleteSettlementReplySetsProperReplyID)
{
    ASSERT_EQ(39, m_command_delete_settlement_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDeleteSettlementReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_delete_settlement_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDeleteSettlementReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_delete_settlement_reply->getMessage().c_str());
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
    ASSERT_TRUE(m_command_build_building_reply.get());
}

TEST_F(ReplyBuilderTest, BuildBuildBuildingReplySetsProperReplyID)
{
    ASSERT_EQ(42, m_command_build_building_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildBuildBuildingReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_build_building_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildBuildBuildingReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_build_building_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildDestroyBuildingReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_destroy_building_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDestroyBuildingReplySetsProperReplyID)
{
    ASSERT_EQ(43, m_command_destroy_building_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDestroyBuildingReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_destroy_building_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDestroyBuildingReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_destroy_building_reply->getMessage().c_str());
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
    ASSERT_TRUE(m_command_dismiss_human_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDismissHumanReplySetsProperReplyID)
{
    ASSERT_EQ(46, m_command_dismiss_human_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDismissHumanReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_dismiss_human_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDismissHumanReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_dismiss_human_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildEngageHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_engage_human_reply.get());
}

TEST_F(ReplyBuilderTest, BuildEngageHumanReplySetsProperReplyID)
{
    ASSERT_EQ(47, m_command_engage_human_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildEngageHumanReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_engage_human_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildEngageHumanReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_engage_human_reply->getMessage().c_str());
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
    ASSERT_TRUE(m_command_create_user_reply.get());
}

TEST_F(ReplyBuilderTest, BuildCreateUserReplySetsProperReplyID)
{
    ASSERT_EQ(52, m_command_create_user_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildCreateUserReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_create_user_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateUserReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_create_user_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildCreateWorldReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_world_reply.get());
}

TEST_F(ReplyBuilderTest, BuildCreateWorldReplySetsProperReplyID)
{
    ASSERT_EQ(53, m_command_create_world_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildCreateWorldReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_create_world_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateWorldReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_create_world_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildCreateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_create_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildCreateEpochReplySetsProperReplyID)
{
    ASSERT_EQ(54, m_command_create_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildCreateEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_create_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildCreateEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_create_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildDeleteEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_delete_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDeleteEpochReplySetsProperReplyID)
{
    ASSERT_EQ(55, m_command_delete_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDeleteEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_delete_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDeleteEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_delete_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildActivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_activate_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildActivateEpochReplySetsProperReplyID)
{
    ASSERT_EQ(56, m_command_activate_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildActivateEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_activate_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildActivateEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_activate_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildDeactivateEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_deactivate_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildDeactivateEpochReplySetsProperReplyID)
{
    ASSERT_EQ(57, m_command_deactivate_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildDeactivateEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_deactivate_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildDeactivateEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_deactivate_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildFinishEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_finish_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildFinishEpochReplySetsProperReplyID)
{
    ASSERT_EQ(58, m_command_finish_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildFinishEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_finish_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildFinishEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_finish_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildTickEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_tick_epoch_reply.get());
}

TEST_F(ReplyBuilderTest, BuildTickEpochReplySetsProperReplyID)
{
    ASSERT_EQ(59, m_command_tick_epoch_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildTickEpochReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_tick_epoch_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildTickEpochReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_tick_epoch_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplyReturnsNotNull)
{
    ASSERT_TRUE(m_reply_builder.buildGetEpochReply().get());
}

TEST_F(ReplyBuilderTest, BuildTransportHumanReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_transport_human_reply.get());
}

TEST_F(ReplyBuilderTest, BuildTransportHumanReplySetsProperReplyID)
{
    ASSERT_EQ(61, m_command_transport_human_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildTransportHumanReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_transport_human_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildTransportHumanReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_transport_human_reply->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildTransportResourceReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command_transport_resource_reply.get());
}

TEST_F(ReplyBuilderTest, BuildTransportResourceReplySetsProperReplyID)
{
    ASSERT_EQ(62, m_command_transport_resource_reply->getID());
}

TEST_F(ReplyBuilderTest, BuildTransportResourceReplySetsProperCode)
{
    ASSERT_EQ(1, m_command_transport_resource_reply->getCode());
}

TEST_F(ReplyBuilderTest, BuildTransportResourceReplySetsProperMessage)
{
    ASSERT_STREQ("Message", m_command_transport_resource_reply->getMessage().c_str());
}
