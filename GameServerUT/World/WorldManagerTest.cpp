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

using namespace GameServer::Land;
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
        : m_id_world_1(1),
          m_id_land_1(1)
    {
    }

    /**
     * @brief Compares the world with expected values.
     *
     * @param a_world    The world to be compared.
     * @param a_id_world An expected identifier of the world.
     * @param a_name     An expected name of the world.
     */
    void compareWorld(
        IWorldShrPtr        a_world,
        IDWorld     const & a_id_world,
        std::string const & a_name
    )
    {
        ASSERT_TRUE(a_id_world == a_world->getIDWorld());
        ASSERT_STREQ(a_name.c_str(), a_world->getName().c_str());
    }

    /**
     * @brief Test constants: identifiers of worlds.
     */
    IDWorld m_id_world_1;

    /**
     * @brief Test constants: identifiers of lands.
     */
    IDLand m_id_land_1;
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

    IDWorld id_world(1);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, id_world))
    .WillOnce(Return(IWorldRecordShrPtr()));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorld(transaction, id_world);

    ASSERT_TRUE(world == NULL);
}

TEST_F(WorldManagerTest, getWorld_WorldDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    IDWorld id_world(1);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, id_world))
    .WillOnce(Return(IWorldRecordShrPtr(new WorldRecord(id_world, "World1"))));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorld(transaction, id_world);

    ASSERT_TRUE(world != NULL);

    compareWorld(world, id_world, "World1");
}

TEST_F(WorldManagerTest, getWorldByIDLand_WorldDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(IWorldRecordShrPtr()));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorldByIDLand(transaction, m_id_land_1);

    ASSERT_TRUE(world == NULL);
}

TEST_F(WorldManagerTest, getWorldByIDLand_WorldDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(IWorldRecordShrPtr(new WorldRecord(m_id_world_1, "World1"))));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldShrPtr world = manager.getWorldByIDLand(transaction, m_id_land_1);

    ASSERT_TRUE(world != NULL);

    compareWorld(world, m_id_world_1, "World1");
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

    IDWorld id_world(1);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    IWorldRecordMap map;
    map.insert(make_pair(id_world, IWorldRecordShrPtr(new WorldRecord(id_world, "World1"))));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldMap worlds = manager.getWorlds(transaction);

    ASSERT_FALSE(worlds.empty());

    ASSERT_EQ(1, worlds.size());

    compareWorld(worlds[id_world], id_world, "World1");
}

TEST_F(WorldManagerTest, getWorlds_WorldsDoExist_ManyWorlds)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    IDWorld id_world_1(1);
    IDWorld id_world_2(2);

    WorldManagerAccessorMock * mock = new WorldManagerAccessorMock;

    IWorldRecordMap map;
    map.insert(make_pair(id_world_1, IWorldRecordShrPtr(new WorldRecord(id_world_1, "World1"))));
    map.insert(make_pair(id_world_2, IWorldRecordShrPtr(new WorldRecord(id_world_2, "World2"))));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    IWorldManagerAccessorAutPtr accessor(mock);

    WorldManager manager(accessor);

    IWorldMap worlds = manager.getWorlds(transaction);

    ASSERT_FALSE(worlds.empty());

    ASSERT_EQ(2, worlds.size());

    compareWorld(worlds[id_world_1], id_world_1, "World1");
    compareWorld(worlds[id_world_2], id_world_2, "World2");
}
