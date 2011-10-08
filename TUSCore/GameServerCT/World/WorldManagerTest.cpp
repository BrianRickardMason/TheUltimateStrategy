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

#include "../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistency;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class WorldManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    WorldManagerTest()
        : m_world_name_1("World1"),
          m_world_name_2("World2"),
          m_world_name_3("World3"),
          m_world_name_4("World4"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_manager(m_manager_abstract_factory->createWorldManager())
    {
    }

    /**
     * @brief Compares the world with expected values.
     *
     * @param a_world      The world to be compared.
     * @param a_world_name The expected name of the world.
     */
    void compareWorld(
        IWorldShrPtr       a_world,
        string       const a_world_name
    )
    {
        ASSERT_STREQ(a_world_name.c_str(), a_world->getWorldName().c_str());
    }

    /**
     * @brief Test constants: the names of the worlds.
     */
    string m_world_name_1,
           m_world_name_2,
           m_world_name_3,
           m_world_name_4;


    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A manager.
     */
    IWorldManagerShrPtr m_manager;
};

/**
 * Component tests of: WorldManager::createWorld.
 */
TEST_F(WorldManagerTest, createWorld_WorldDoesNotExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_TRUE(m_manager->createWorld(transaction, m_world_name_1));

    IWorldShrPtr world = m_manager->getWorld(transaction, m_world_name_1);

    ASSERT_TRUE(world != NULL);
    compareWorld(world, m_world_name_1);
}

TEST_F(WorldManagerTest, createWorld_WorldDoesExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_TRUE(m_manager->createWorld(transaction, m_world_name_1));
    ASSERT_FALSE(m_manager->createWorld(transaction, m_world_name_1));
}

/**
 * Component tests of: WorldManager::getWorld.
 */
TEST_F(WorldManagerTest, getWorld_WorldDoesNotExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IWorldShrPtr world = m_manager->getWorld(transaction, m_world_name_4);

    ASSERT_TRUE(world == NULL);
}

TEST_F(WorldManagerTest, getWorld_WorldDoesExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    m_manager->createWorld(transaction, m_world_name_1);
    m_manager->createWorld(transaction, m_world_name_2);
    m_manager->createWorld(transaction, m_world_name_3);

    IWorldShrPtr world_1 = m_manager->getWorld(transaction, m_world_name_1);
    IWorldShrPtr world_2 = m_manager->getWorld(transaction, m_world_name_2);
    IWorldShrPtr world_3 = m_manager->getWorld(transaction, m_world_name_3);

    ASSERT_TRUE(world_1 != NULL);
    ASSERT_TRUE(world_2 != NULL);
    ASSERT_TRUE(world_3 != NULL);
    compareWorld(world_1, m_world_name_1);
    compareWorld(world_2, m_world_name_2);
    compareWorld(world_3, m_world_name_3);
}

/**
 * Component tests of: WorldManager::getWorlds.
 */
TEST_F(WorldManagerTest, getWorlds)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    m_manager->createWorld(transaction, m_world_name_1);
    m_manager->createWorld(transaction, m_world_name_2);
    m_manager->createWorld(transaction, m_world_name_3);

    IWorldMap worlds = m_manager->getWorlds(transaction);

    ASSERT_FALSE(worlds.empty());
    ASSERT_EQ(3, worlds.size());
    compareWorld(worlds[m_world_name_1], m_world_name_1);
    compareWorld(worlds[m_world_name_2], m_world_name_2);
    compareWorld(worlds[m_world_name_3], m_world_name_3);
}