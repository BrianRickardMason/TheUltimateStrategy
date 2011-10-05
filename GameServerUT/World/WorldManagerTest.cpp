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

#include "../../GameServer/World/WorldManager.hpp"
#include "../../GameServer/World/WorldRecord.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "WorldManagerAccessorMock.hpp"

using namespace GameServer::Persistency;
using namespace GameServer::World;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class WorldManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    WorldManagerTest()
        : m_world_name_1("World2"),
          m_world_name_2("World1"),
          m_land_name("Land")
    {
    }

    /**
     * @brief Compares the world with expected values.
     *
     * @param a_world      The world to be compared.
     * @param a_world_name The expected name of the world.
     */
    void compareWorld(
        IWorldShrPtr      a_world,
        std::string const a_world_name
    )
    {
        ASSERT_STREQ(a_world_name.c_str(), a_world->getWorldName().c_str());
    }

    /**
     * @brief Test constants: the names of the worlds.
     */
    string m_world_name_1,
           m_world_name_2;

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;
};

TEST_F(WorldManagerTest, WorldManager)
{
    IWorldManagerAccessorAutPtr accessor(new WorldManagerAccessorMock);

    ASSERT_NO_THROW(WorldManager manager(accessor));
}

TEST_F(WorldManagerTest, createWorld_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, "World"));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    ASSERT_TRUE(manager.createWorld(transaction, "World"));
}

TEST_F(WorldManagerTest, createWorld_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, "World"))
    .WillOnce(Throw(e));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    ASSERT_FALSE(manager.createWorld(transaction, "World"));
}

TEST_F(WorldManagerTest, getWorld_WorldDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name_1))
    .WillOnce(Return(IWorldRecordShrPtr()));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorld(transaction, m_world_name_1);

    ASSERT_TRUE(world == NULL);
}

TEST_F(WorldManagerTest, getWorld_WorldDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name_1))
    .WillOnce(Return(IWorldRecordShrPtr(new WorldRecord(m_world_name_1))));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorld(transaction, m_world_name_1);

    ASSERT_TRUE(world != NULL);

    compareWorld(world, m_world_name_1);
}

TEST_F(WorldManagerTest, getWorldByLandName_WorldDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name_1))
    .WillOnce(Return(IWorldRecordShrPtr()));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorldByLandName(transaction, m_land_name);

    ASSERT_TRUE(world == NULL);
}

TEST_F(WorldManagerTest, getWorldByLandName_WorldDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name_1))
    .WillOnce(Return(IWorldRecordShrPtr(new WorldRecord(m_world_name_1))));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorldByLandName(transaction, m_land_name);

    ASSERT_TRUE(world != NULL);

    compareWorld(world, m_world_name_1);
}

TEST_F(WorldManagerTest, getWorlds_WorldsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    IWorldRecordMap map;

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldMap worlds = manager.getWorlds(transaction);

    ASSERT_TRUE(worlds.empty());
}

TEST_F(WorldManagerTest, getWorlds_WorldsDoExist_OneWorld)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    IWorldRecordMap map;
    map.insert(make_pair(m_world_name_1, IWorldRecordShrPtr(new WorldRecord(m_world_name_1))));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldMap worlds = manager.getWorlds(transaction);

    ASSERT_FALSE(worlds.empty());

    ASSERT_EQ(1, worlds.size());

    compareWorld(worlds[m_world_name_1], m_world_name_1);
}

TEST_F(WorldManagerTest, getWorlds_WorldsDoExist_ManyWorlds)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    IWorldRecordMap map;
    map.insert(make_pair(m_world_name_1, IWorldRecordShrPtr(new WorldRecord(m_world_name_1))));
    map.insert(make_pair(m_world_name_2, IWorldRecordShrPtr(new WorldRecord(m_world_name_2))));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldMap worlds = manager.getWorlds(transaction);

    ASSERT_FALSE(worlds.empty());

    ASSERT_EQ(2, worlds.size());

    compareWorld(worlds[m_world_name_1], m_world_name_1);
    compareWorld(worlds[m_world_name_2], m_world_name_2);
}
