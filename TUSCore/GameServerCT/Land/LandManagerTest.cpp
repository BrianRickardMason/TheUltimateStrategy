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
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class LandManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    LandManagerTest()
        : m_epoch_name_1("Epoch1"),
          m_epoch_name_2("Epoch2"),
          m_epoch_name_3("Epoch3"),
          m_epoch_name_5("Epoch5"),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_login_3("Login3"),
          m_login_5("Login5"),
          m_world_name_1("World1"),
          m_world_name_2("World2"),
          m_world_name_3("World3"),
          m_world_name_5("World4"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_land_name_3("Land3"),
          m_land_name_4("Land4"),
          m_land_name_5("Land5"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_persistence_facade(m_manager_abstract_factory->createLandPersistenceFacade())
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_world_manager->createWorld(transaction, m_world_name_1);
            m_world_manager->createWorld(transaction, m_world_name_2);
            m_world_manager->createWorld(transaction, m_world_name_3);

            m_epoch_manager->createEpoch(transaction, m_world_name_1, m_epoch_name_1);
            m_epoch_manager->createEpoch(transaction, m_world_name_2, m_epoch_name_2);
            m_epoch_manager->createEpoch(transaction, m_world_name_3, m_epoch_name_3);

            m_user_manager->createUser(transaction, "Login1", "Password1");
            m_user_manager->createUser(transaction, "Login2", "Password2");
            m_user_manager->createUser(transaction, "Login3", "Password3");

            transaction->commit();
        }
    }

    /**
     * @brief Compares the land with expected values.
     *
     * @param a_land       The land to be compared.
     * @param a_login      The expected login of the user.
     * @param a_world_name The expected name of the world.
     * @param a_land_name  The expected name of the land.
     */
    void compareLand(
        ILandShrPtr       a_land,
        string      const a_login,
        string      const a_world_name,
        string      const a_land_name
    )
    {
        ASSERT_STREQ(a_login.c_str(), a_land->getLogin().c_str());
        ASSERT_STREQ(a_world_name.c_str(), a_land->getWorldName().c_str());
        ASSERT_STREQ(a_land_name.c_str(), a_land->getLandName().c_str());
    }

    /**
     * @brief Test constants: the names of the epochs.
     */
    string m_epoch_name_1,
           m_epoch_name_2,
           m_epoch_name_3,
           m_epoch_name_5;

    /**
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2,
           m_login_3,
           m_login_5;

    /**
     * @brief Test constants: the names of the worlds.
     */
    string m_world_name_1,
           m_world_name_2,
           m_world_name_3,
           m_world_name_5;

    /**
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2,
           m_land_name_3,
           m_land_name_4,
           m_land_name_5;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A user manager.
     */
    IUserManagerShrPtr m_user_manager;

    /**
     * @brief A world manager.
     */
    IWorldManagerShrPtr m_world_manager;

    /**
     * @brief A epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief A land persistence facade.
     */
    ILandPersistenceFacadeShrPtr m_land_persistence_facade;
};

/**
 * Component tests of: LandManager::createLand.
 */
TEST_F(LandManagerTest, createLand_LandDoesNotExist_FirstLandOfUser)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfUser)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_2));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_FirstLandOfAnotherUser)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_2));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_3));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfAnotherUser)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_2));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_3));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_4));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_ThirdLandOfAnotherUserInAnotherWorld)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_2));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_3));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_4));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_2, m_land_name_1));
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfAnotherUserInAnotherWorld)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_2));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_3));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_4));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_2, m_land_name_5));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_2, m_land_name_1));
}

TEST_F(LandManagerTest, createLand_LandDoesExist_UserAndWorld)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
}

TEST_F(LandManagerTest, createLand_LandDoesExist_User)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_2, m_land_name_1));
}

TEST_F(LandManagerTest, createLand_LandDoesExist_World)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name_1, m_land_name_1));
}

/**
 * Component tests of: LandManager::deleteLand.
 */
TEST_F(LandManagerTest, deleteLand_LandDoesNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Test commands and assertions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->deleteLand(transaction, m_land_name_1));
    transaction->commit();
}

TEST_F(LandManagerTest, deleteLand_LandDoesExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->deleteLand(transaction, m_land_name_1));
    transaction->commit();
}

/**
 * Component tests of: LandManager::getLand.
 */
TEST_F(LandManagerTest, getLand_LandDoesNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Test.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ILandShrPtr land = m_land_persistence_facade->getLand(transaction, m_land_name_1);
    transaction->commit();

    // Test commands and assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_LandDoesExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands.
    transaction = persistence.getTransaction(connection);
    ILandShrPtr land = m_land_persistence_facade->getLand(transaction, m_land_name_1);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land != NULL);
    compareLand(land, m_login_1, m_world_name_1, m_land_name_1);
}

TEST_F(LandManagerTest, getLand_LandDoesExist_MissingLandName)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    // Test commands.
    transaction = persistence.getTransaction(connection);
    ILandShrPtr land = m_land_persistence_facade->getLand(transaction, m_land_name_2);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

/**
 * Component tests of: LandManager::getLands.
 */
TEST_F(LandManagerTest, getLands_LandsDoNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ILandMap lands = m_land_persistence_facade->getLands(transaction, m_login_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(0, lands.size());
}

TEST_F(LandManagerTest, getLands_LandsDoExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_2, m_land_name_2));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_3, m_world_name_3, m_land_name_3));
    transaction->commit();

    // Test commands.
    transaction = persistence.getTransaction(connection);
    ILandMap lands = m_land_persistence_facade->getLands(transaction, m_login_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(2, lands.size());
    ASSERT_TRUE(lands[m_land_name_1] != NULL);
    ASSERT_TRUE(lands[m_land_name_2] != NULL);
    compareLand(lands[m_land_name_1], m_login_1, m_world_name_1, m_land_name_1);
    compareLand(lands[m_land_name_2], m_login_1, m_world_name_2, m_land_name_2);
}

TEST_F(LandManagerTest, getLands_LandsDoExist_MissingLogin)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_1, m_land_name_1));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name_2, m_land_name_2));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_land_persistence_facade->createLand(transaction, m_login_3, m_world_name_3, m_land_name_3));
    transaction->commit();

    // Test commands.
    transaction = persistence.getTransaction(connection);
    ILandMap lands = m_land_persistence_facade->getLands(transaction, m_login_5);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(lands.empty());
}
