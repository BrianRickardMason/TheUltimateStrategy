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

    //@{
    /**
     * @brief The building to be inserted.
     */
    TUSLanguage::ICommand::Object m_building_1,
                                  m_building_2;
    //}@

    /**
     * @brief The buildings to be tested.
     */
    TUSLanguage::ICommand::Objects m_buildings;

    /**
     * @brief The epoch to be inserted.
     */
    TUSLanguage::ICommand::Object m_epoch;

    //@{
    /**
     * @brief The human to be inserted.
     */
    TUSLanguage::ICommand::Object m_human_1,
                                  m_human_2;
    //}@

    /**
     * @brief The humans to be tested.
     */
    TUSLanguage::ICommand::Objects m_humans;

    //@{
    /**
     * @brief The resource to be inserted.
     */
    TUSLanguage::ICommand::Object m_resource_1,
                                  m_resource_2;
    //}@

    /**
     * @brief The resources to be tested.
     */
    TUSLanguage::ICommand::Objects m_resources;

    //@{
    /**
     * @brief The settlement to be inserted.
     */
    TUSLanguage::ICommand::Object m_settlement_1,
                                  m_settlement_2;
    //}@

    /**
     * @brief The settlements to be tested.
     */
    TUSLanguage::ICommand::Objects m_settlements;
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

TEST_F(ReplyBuilderTest, BuildGetSettlementReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    ASSERT_EQ(40, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    ASSERT_EQ(1, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementReplySetsProperObject)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementReply(1, "Message", m_settlement_1);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Land1", object.at("land_name").c_str());
    ASSERT_STREQ("Settlement1", object.at("settlement_name").c_str());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    ASSERT_EQ(41, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    ASSERT_EQ(2, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetSettlementsReplySetsProperObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetSettlementsReply(1, "Message", m_settlements);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
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

TEST_F(ReplyBuilderTest, BuildGetBuildingReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    ASSERT_EQ(44, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    ASSERT_EQ(1, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingReplySetsProperObject)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingReply(1, "Message", m_building_1);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Regular", object.at("buildingclass").c_str());
    ASSERT_STREQ("Farm", object.at("buildingname").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    ASSERT_EQ(45, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    ASSERT_EQ(2, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetBuildingsReplySetsProperObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetBuildingsReply(1, "Message", m_buildings);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
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

TEST_F(ReplyBuilderTest, BuildGetHumanReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    ASSERT_EQ(48, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    ASSERT_EQ(1, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetHumanReplySetsProperObject)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumanReply(1, "Message", m_human_1);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Worker", object.at("humanclass").c_str());
    ASSERT_STREQ("Farmer", object.at("humanname").c_str());
    ASSERT_STREQ("Novice", object.at("experience").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    ASSERT_EQ(49, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    ASSERT_EQ(2, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetHumansReplySetsProperObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetHumansReply(1, "Message", m_humans);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
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

TEST_F(ReplyBuilderTest, BuildGetResourceReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    ASSERT_EQ(50, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    ASSERT_EQ(1, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetResourceReplySetsProperObject)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourceReply(1, "Message", m_resource_1);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
    TUSLanguage::ICommand::Object object = objects.front();
    ASSERT_STREQ("Coal", object.at("resourcename").c_str());
    ASSERT_STREQ("10", object.at("volume").c_str());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    ASSERT_EQ(51, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    ASSERT_EQ(2, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetResourcesReplySetsProperObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetResourcesReply(1, "Message", m_resources);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
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

TEST_F(ReplyBuilderTest, BuildGetEpochReplyReturnsNotNull)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    ASSERT_TRUE(command.get());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplySetsProperID)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    ASSERT_EQ(60, command->getID());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplySetsProperCode)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    ASSERT_EQ(1, command->getCode());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplySetsProperMessage)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    ASSERT_STREQ("Message", command->getMessage().c_str());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplySetsProperNumberOfObjects)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    ASSERT_EQ(1, command->getObjects().size());
}

TEST_F(ReplyBuilderTest, BuildGetEpochReplySetsProperObject)
{
    TUSLanguage::ICommand::Handle command = m_reply_builder.buildGetEpochReply(1, "Message", m_epoch);
    TUSLanguage::ICommand::Objects objects = command->getObjects();
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
