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
using namespace GameServer::Persistency;
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
        : m_id_epoch_1(1),
          m_id_epoch_2(2),
          m_id_epoch_3(3),
          m_id_epoch_5(5),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_land_3(3),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_login_3("Login3"),
          m_login_5("Login5"),
          m_world_name_1("World1"),
          m_world_name_2("World2"),
          m_world_name_3("World3"),
          m_world_name_5("World4"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager())
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_world_manager->createWorld(transaction, m_world_name_1);
            m_world_manager->createWorld(transaction, m_world_name_2);
            m_world_manager->createWorld(transaction, m_world_name_3);

            m_epoch_manager->createEpoch(transaction, m_world_name_1);
            m_epoch_manager->createEpoch(transaction, m_world_name_2);
            m_epoch_manager->createEpoch(transaction, m_world_name_3);

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
     * @param a_id_epoch   The expected identifier of the epoch.
     * @param a_id_land    An expected identifier of the land.
     * @param a_name       An expected name of the land.
     */
    void compareLand(
        LandShrPtr         a_land,
        string     const   a_login,
        string     const   a_world_name,
        IDEpoch    const & a_id_epoch,
        IDLand     const & a_id_land,
        string     const & a_name
    )
    {
        ASSERT_STREQ(a_login.c_str(), a_land->getLogin().c_str());
        ASSERT_STREQ(a_world_name.c_str(), a_land->getWorldName().c_str());
        ASSERT_TRUE(a_id_epoch == a_land->getIDEpoch());
        ASSERT_TRUE(a_id_land == a_land->getIDLand());
        ASSERT_STREQ(a_name.c_str(), a_land->getName().c_str());
    }

    /**
     * @brief Test constants identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1,
            m_id_epoch_2,
            m_id_epoch_3,
            m_id_epoch_5;

    /**
     * @brief Test constants identifiers of the land.
     */
    IDLand m_id_land_1,
           m_id_land_2,
           m_id_land_3;

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
     * @brief A manager.
     */
    ILandManagerShrPtr m_land_manager;
};

/**
 * Component tests of: LandManager::createLand.
 */
TEST_F(LandManagerTest, createLand_LandDoesNotExist_FirstLandOfUser)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfUser)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_FirstLandOfAnotherUser)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land3"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfAnotherUser)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land3"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land4"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_ThirdLandOfAnotherUserInAnotherWorld)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land3"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land4"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_2, m_id_epoch_2, "Land1"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesNotExist_SecondLandOfAnotherUserInAnotherWorld)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land3"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land4"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_2, m_id_epoch_2, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();
}

TEST_F(LandManagerTest, createLand_LandDoesExist_UserAndWorld)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_FALSE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
}

TEST_F(LandManagerTest, createLand_LandDoesExist_User)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_FALSE(m_land_manager->createLand(transaction, m_login_1, m_world_name_2, m_id_epoch_2, "Land1"));
}

TEST_F(LandManagerTest, createLand_LandDoesExist_World)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_FALSE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land1"));
}

/**
 * Component tests of: LandManager::deleteLand.
 */
TEST_F(LandManagerTest, deleteLand_LandDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands and assertions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->deleteLand(transaction, m_id_land_1));
    transaction->commit();
}

TEST_F(LandManagerTest, deleteLand_LandDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands and assertions.
    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->deleteLand(transaction, m_id_land_1));
    transaction->commit();
}

/**
 * Component tests of: LandManager::getLand.
 */
TEST_F(LandManagerTest, getLand_ByIDLand_LandDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLand(transaction, m_id_land_1);
    transaction->commit();

    // Test commands and assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByIDLand_LandDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLand(transaction, m_id_land_1);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land != NULL);
    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
}

TEST_F(LandManagerTest, getLand_ByIDLand_LandDoesExist_MissingIDLand)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLand(transaction, m_id_land_2);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

/**
 * Component tests of: LandManager::getLand.
 */
TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_1, "Land1");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_1, "Land1");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land != NULL);
    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist_MissingNameMissingLogin)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_5, "Land5");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist_MissingNameCorrectLogin)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_5, "Land5");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist_CorrectNameMissingLogin)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_5, "Land1");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist_WrongLoginNameCombination)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByLogin(transaction, m_login_1, "Land2");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

/**
 * Component tests of: LandManager::getLand.
 */
TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_5, "Land5");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_1, "Land1");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land != NULL);
    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist_MissingNameMissingWorldName)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_5, "Land5");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist_MissingNameCorrectWorldName)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_1, "Land5");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist_CorrectNameMissingWorldName)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_5, "Land1");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist_WrongNameWorldNameCombination)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandShrPtr land = m_land_manager->getLandByWorldName(transaction, m_world_name_1, "Land2");
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(land == NULL);
}

/**
 * Component tests of: LandManager::getLands.
 */
TEST_F(LandManagerTest, getLands_LandsDoNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLands(transaction);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(0, lands.size());
}

TEST_F(LandManagerTest, getLands_LandsDoExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_3, m_world_name_3, m_id_epoch_3, "Land3"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLands(transaction);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(3, lands.size());
    ASSERT_TRUE(lands[m_id_land_1] != NULL);
    ASSERT_TRUE(lands[m_id_land_2] != NULL);
    ASSERT_TRUE(lands[m_id_land_3] != NULL);
    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
    compareLand(lands[m_id_land_2], m_login_2, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2");
    compareLand(lands[m_id_land_3], m_login_3, m_world_name_3, m_id_epoch_3, m_id_land_3, "Land3");
}

/**
 * Component tests of: LandManager::getLands.
 */
TEST_F(LandManagerTest, getLands_ByLogin_LandsDoNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByLogin(transaction, m_login_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(0, lands.size());
}

TEST_F(LandManagerTest, getLands_ByLogin_LandsDoExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_3, m_world_name_3, m_id_epoch_3, "Land3"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByLogin(transaction, m_login_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(2, lands.size());
    ASSERT_TRUE(lands[m_id_land_1] != NULL);
    ASSERT_TRUE(lands[m_id_land_2] != NULL);
    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
    compareLand(lands[m_id_land_2], m_login_1, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2");
}

TEST_F(LandManagerTest, getLands_ByLogin_LandsDoExist_MissingLogin)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_3, m_world_name_3, m_id_epoch_3, "Land3"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByLogin(transaction, m_login_5);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(lands.empty());
}

/**
 * Component tests of: LandManager::getLands.
 */
TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Test commands.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByWorldName(transaction, m_world_name_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(0, lands.size());
}

TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_2, m_world_name_1, m_id_epoch_1, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_3, m_world_name_3, m_id_epoch_3, "Land3"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByWorldName(transaction, m_world_name_1);
    transaction->commit();

    // Test assertions.
    ASSERT_EQ(2, lands.size());
    ASSERT_TRUE(lands[m_id_land_1] != NULL);
    ASSERT_TRUE(lands[m_id_land_2] != NULL);
    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1");
    compareLand(lands[m_id_land_2], m_login_2, m_world_name_1, m_id_epoch_1, m_id_land_2, "Land2");
}

TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoExist_MissingWorldName)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    // Preconditions.
    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_1, m_world_name_2, m_id_epoch_2, "Land2"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_land_manager->createLand(transaction, m_login_3, m_world_name_3, m_id_epoch_3, "Land3"));
    transaction->commit();

    // Test commands.
    transaction = persistency.getTransaction(connection);
    LandMap lands = m_land_manager->getLandsByWorldName(transaction, m_world_name_5);
    transaction->commit();

    // Test assertions.
    ASSERT_TRUE(lands.empty());
}
