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
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include "../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Settlement/SettlementManagerFactory.hpp"
#include "../ComponentTest.hpp"

using namespace GameServer::Authorization;
using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class AuthorizationManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    AuthorizationManagerTest()
        : m_id_epoch_1(1),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_land_5(5),
          m_name_1("Land1"),
          m_name_2("Land2"),
          m_name_5("Land5"),
          m_id_settlement_1(1),
          m_id_settlement_2(2),
          m_id_settlement_5(5),
          m_name_settlement_1("Settlement1"),
          m_name_settlement_2("Settlement2"),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_login_5("Login5"),
          m_world_name("World"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_settlement_manager(m_manager_abstract_factory->createSettlementManager())
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_world_manager->createWorld(transaction, m_world_name);

            m_epoch_manager->createEpoch(transaction, m_world_name),

            m_user_manager->createUser(transaction, "Login1", "Password1");
            m_user_manager->createUser(transaction, "Login2", "Password2");

            m_land_manager->createLand(transaction, m_login_1, m_world_name, m_id_epoch_1, m_name_1);
            m_land_manager->createLand(transaction, m_login_2, m_world_name, m_id_epoch_1, m_name_2);

            m_settlement_manager->createSettlement(transaction, m_id_land_1, m_name_settlement_1);
            m_settlement_manager->createSettlement(transaction, m_id_land_2, m_name_settlement_2);

            transaction->commit();
        }
    }

    /**
     * @brief Test constants identifiers of the epochs.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants identifiers of the lands.
     */
    IDLand m_id_land_1,
           m_id_land_2,
           m_id_land_5;

    /**
     * @brief Test constants names of the lands.
     */
    string m_name_1,
           m_name_2,
           m_name_5;

    /**
     * @brief Test constants identifiers of the settlements.
     */
    IDSettlement m_id_settlement_1,
                 m_id_settlement_2,
                 m_id_settlement_5;

    /**
     * @brief Test constants names of the settlements.
     */
    string m_name_settlement_1,
           m_name_settlement_2;

    /**
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2,
           m_login_5;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

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
     * @brief The epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief A land manager.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief A settlement manager.
     */
    ISettlementManagerShrPtr m_settlement_manager;
};

/**
 * Component tests of: AuthorizationManager::authorizeUserToLand by Login and IDLand.
 */
TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByLoginAndIDLand_Authorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_TRUE(manager->authorizeUserToLand(transaction, m_login_1, m_id_land_1));
    ASSERT_TRUE(manager->authorizeUserToLand(transaction, m_login_2, m_id_land_2));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByLoginAndIDLand_NotAuthorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_2, m_id_land_1));
    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_1, m_id_land_2));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByLoginAndIDLand_NotAuthorized_MissingLogin)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_5, m_id_land_1));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByLoginAndIDLand_NotAuthorized_MissingIDLand)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_1, m_id_land_5));
}

/**
 * Component tests of: AuthorizationManager::authorizeUserToLand by IDLand and Name.
 */
TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByIDLandAndName_Authorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_TRUE(manager->authorizeUserToLand(transaction, m_login_1, m_name_1));
    ASSERT_TRUE(manager->authorizeUserToLand(transaction, m_login_2, m_name_2));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByIDLandAndName_NotAuthorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_2, m_name_1));
    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_1, m_name_2));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByIDLandAndName_NotAuthorized_MissingLogin)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_5, m_name_1));
}

TEST_F(AuthorizationManagerTest, authorizeUserToLand_ByIDLandAndNanme_NotAuthorized_MissingName)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToLand(transaction, m_login_1, m_name_5));
}

/**
 * Component tests of: AuthorizationManager::authorizeUserToSettlement.
 */
TEST_F(AuthorizationManagerTest, authorizeUserToSettlement_Authorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_TRUE(manager->authorizeUserToSettlement(transaction, m_login_1, m_id_settlement_1));
    ASSERT_TRUE(manager->authorizeUserToSettlement(transaction, m_login_2, m_id_settlement_2));
}

TEST_F(AuthorizationManagerTest, authorizeUserToSettlement_NotAuthorized)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToSettlement(transaction, m_login_1, m_id_settlement_2));
    ASSERT_FALSE(manager->authorizeUserToSettlement(transaction, m_login_2, m_id_settlement_1));
}

TEST_F(AuthorizationManagerTest, authorizeUserToSettlement_NotAuthorized_MissingLogin)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToSettlement(transaction, m_login_5, m_id_settlement_1));
}

TEST_F(AuthorizationManagerTest, authorizeUserToSettlement_NotAuthorized_MissingIDSettlement)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthorizationManagerShrPtr manager = m_manager_abstract_factory->createAuthorizationManager();

    ASSERT_FALSE(manager->authorizeUserToSettlement(transaction, m_login_1, m_id_settlement_5));
}
