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

#include <Language/Interface/ReplyBuilder.hpp>
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
    TUSLanguage::ICommand::Handle m_command_echo_reply,
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

class ReplyBuilderTestBuildGetLandReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetLandReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetLandReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetLandReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(36, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetLandReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetLandReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object land;
        land.insert(std::make_pair("login", "Login1"));
        land.insert(std::make_pair("world_name", "World1"));
        land.insert(std::make_pair("land_name", "Land1"));
        land.insert(std::make_pair("granted", "false"));
        m_command = reply_builder.buildGetLandReply(1, "Message", land);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, SetsProperID)
{
    ASSERT_EQ(36, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetLandReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Login1", object.at("login").c_str());
    ASSERT_STREQ("World1", object.at("world_name").c_str());
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
}

class ReplyBuilderTestBuildGetLandsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetLandsReplyWithoutObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetLandsReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithoutObjects, SetsProperID)
{
    ASSERT_EQ(37, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithoutObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithoutObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithoutObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetLandsReplyWithObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetLandsReplyWithObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object land_1, land_2;
        TUSLanguage::ICommand::Objects lands;
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
        m_command = reply_builder.buildGetLandsReply(1, "Message", lands);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, SetsProperID)
{
    ASSERT_EQ(37, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetLandsReplyWithObjects, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Login1", object.at("login").c_str());
    ASSERT_STREQ("World1", object.at("world_name").c_str());
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
    object = objects.back();
    ASSERT_STREQ("Login2", object.at("login").c_str());
    ASSERT_STREQ("World2", object.at("world_name").c_str());
    ASSERT_STREQ("Land2", object.at("land_name").c_str());
    ASSERT_STREQ("false", object.at("granted").c_str());
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

class ReplyBuilderTestBuildGetSettlementReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetSettlementReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object settlement;
        m_command = reply_builder.buildGetSettlementReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(40, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetSettlementReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetSettlementReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object settlement;
        settlement.insert(std::make_pair("land_name", "Land1"));
        settlement.insert(std::make_pair("settlement_name", "Settlement1"));
        m_command = reply_builder.buildGetSettlementReply(1, "Message", settlement);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, SetsProperID)
{
    ASSERT_EQ(40, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetSettlementReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement1", object.at("settlement_name").c_str());
}

class ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetSettlementsReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects, SetsProperID)
{
    ASSERT_EQ(41, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithoutObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetSettlementsReplyWithObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetSettlementsReplyWithObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object settlement_1, settlement_2;
        TUSLanguage::ICommand::Objects settlements;
        settlement_1.insert(std::make_pair("land_name", "Land1"));
        settlement_1.insert(std::make_pair("settlement_name", "Settlement1"));
        settlement_2.insert(std::make_pair("land_name", "Land2"));
        settlement_2.insert(std::make_pair("settlement_name", "Settlement2"));
        settlements.push_back(settlement_1);
        settlements.push_back(settlement_2);
        m_command = reply_builder.buildGetSettlementsReply(1, "Message", settlements);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, SetsProperID)
{
    ASSERT_EQ(41, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetSettlementsReplyWithObjects, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement1", object.at("settlement_name").c_str());
    object = objects.back();
    ASSERT_STREQ("Land2", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement2", object.at("settlement_name").c_str());
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

class ReplyBuilderTestBuildGetBuildingReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetBuildingReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetBuildingReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(44, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetBuildingReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetBuildingReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object building;
        building.insert(std::make_pair("buildingclass", "Regular"));
        building.insert(std::make_pair("buildingname", "Farm"));
        building.insert(std::make_pair("volume", "10"));
        m_command = reply_builder.buildGetBuildingReply(1, "Message", building);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, SetsProperID)
{
    ASSERT_EQ(44, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetBuildingReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Farm", object.at("buildingname").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetBuildingsReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects, ReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects, SetsProperID)
{
    ASSERT_EQ(45, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithoutObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetBuildingsReplyWithObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetBuildingsReplyWithObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object building_1, building_2;
        TUSLanguage::ICommand::Objects buildings;
        building_1.insert(std::make_pair("buildingclass", "Regular"));
        building_1.insert(std::make_pair("buildingname", "Farm"));
        building_1.insert(std::make_pair("volume", "10"));
        building_2.insert(std::make_pair("buildingclass", "Regular"));
        building_2.insert(std::make_pair("buildingname", "Sawmill"));
        building_2.insert(std::make_pair("volume", "20"));
        buildings.push_back(building_1);
        buildings.push_back(building_2);
        m_command = reply_builder.buildGetBuildingsReply(1, "Message", buildings);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, ReplyReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, SetsProperID)
{
    ASSERT_EQ(45, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetBuildingsReplyWithObjects, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Farm", object.at("buildingname").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Sawmill", object.at("buildingname").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
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

class ReplyBuilderTestBuildGetHumanReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetHumanReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetHumanReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(48, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetHumanReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetHumanReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object human;
        human.insert(std::make_pair("humanclass", "Worker"));
        human.insert(std::make_pair("humanname", "Farmer"));
        human.insert(std::make_pair("experience", "Novice"));
        human.insert(std::make_pair("volume", "10"));
        m_command = reply_builder.buildGetHumanReply(1, "Message", human);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, SetsProperID)
{
    ASSERT_EQ(48, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetHumanReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Farmer", object.at("humanname").c_str());
    ASSERT_STREQ("Novice", object.at("experience").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ReplyBuilderTestBuildGetHumansReplyWithoutObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetHumansReplyWithoutObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetHumansReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithoutObjects, SetsProperID)
{
    ASSERT_EQ(49, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithoutObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithoutObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithoutObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetHumansReplyWithObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetHumansReplyWithObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object human_1, human_2;
        TUSLanguage::ICommand::Objects humans;
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
        m_command = reply_builder.buildGetHumansReply(1, "Message", humans);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, SetsProperID)
{
    ASSERT_EQ(49, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetHumansReplyWithObjects, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Farmer", object.at("humanname").c_str());
    ASSERT_STREQ("Novice", object.at("experience").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Steelworker", object.at("humanname").c_str());
    ASSERT_STREQ("Advanced", object.at("experience").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
}

class ReplyBuilderTestBuildGetResourceReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetResourceReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object resource;
        m_command = reply_builder.buildGetResourceReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(50, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetResourceReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetResourceReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object resource;
        resource.insert(std::make_pair("resourcename", "Coal"));
        resource.insert(std::make_pair("volume", "10"));
        m_command = reply_builder.buildGetResourceReply(1, "Message", resource);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, SetsProperID)
{
    ASSERT_EQ(50, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetResourceReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Coal", object.at("resourcename").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

class ReplyBuilderTestBuildGetResourcesReplyWithoutObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetResourcesReplyWithoutObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetResourcesReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithoutObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithoutObjects, SetsProperID)
{
    ASSERT_EQ(51, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithoutObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithoutObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithoutObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetResourcesReplyWithObjects
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetResourcesReplyWithObjects()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object resource_1, resource_2;
        TUSLanguage::ICommand::Objects resources;
        resource_1.insert(std::make_pair("resourcename", "Coal"));
        resource_1.insert(std::make_pair("volume", "10"));
        resource_2.insert(std::make_pair("resourcename", "Wood"));
        resource_2.insert(std::make_pair("volume", "20"));
        resources.push_back(resource_1);
        resources.push_back(resource_2);
        m_command = reply_builder.buildGetResourcesReply(1, "Message", resources);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, SetsProperID)
{
    ASSERT_EQ(51, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, SetsProperNumberOfObjects)
{
    ASSERT_EQ(2, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetResourcesReplyWithObjects, SetsProperObjects)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Coal", object.at("resourcename").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
    object = objects.back();
    ASSERT_STREQ("Wood", object.at("resourcename").c_str());
    ASSERT_STREQ("20", object.at("volume").c_str());
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

class ReplyBuilderTestBuildGetEpochReplyWithoutObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetEpochReplyWithoutObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        m_command = reply_builder.buildGetEpochReply(1, "Message");
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithoutObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithoutObject, SetsProperID)
{
    ASSERT_EQ(60, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithoutObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithoutObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithoutObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(0, m_command->getObjects().size());
}

class ReplyBuilderTestBuildGetEpochReplyWithObject
    : public ::testing::Test
{
protected:
    ReplyBuilderTestBuildGetEpochReplyWithObject()
    {
        TUSLanguage::ReplyBuilder reply_builder;
        TUSLanguage::ICommand::Object epoch;
        epoch.insert(std::make_pair("epoch_name", "Epoch"));
        epoch.insert(std::make_pair("world_name", "World"));
        epoch.insert(std::make_pair("active", "true"));
        epoch.insert(std::make_pair("finished", "false"));
        epoch.insert(std::make_pair("ticks", "22"));
        m_command = reply_builder.buildGetEpochReply(1, "Message", epoch);
    }

    TUSLanguage::ICommand::Handle m_command;
};

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, ReturnsNotNull)
{
    ASSERT_TRUE(m_command.get());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, SetsProperID)
{
    ASSERT_EQ(60, m_command->getID());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, SetsProperCode)
{
    ASSERT_EQ(1, m_command->getCode());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, SetsProperMessage)
{
    ASSERT_STREQ("Message", m_command->getMessage().c_str());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, SetsProperNumberOfObjects)
{
    ASSERT_EQ(1, m_command->getObjects().size());
}

TEST_F(ReplyBuilderTestBuildGetEpochReplyWithObject, SetsProperObject)
{
    TUSLanguage::ICommand::Objects objects = m_command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Epoch", object.at("epoch_name").c_str());
    ASSERT_STREQ("World", object.at("world_name").c_str());
    ASSERT_STREQ("true", object.at("active").c_str());
    ASSERT_STREQ("false", object.at("finished").c_str());
    ASSERT_STREQ("22", object.at("ticks").c_str());
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
