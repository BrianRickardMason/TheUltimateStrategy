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

#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Settlement/SettlementPersistenceFacadeFactory.hpp"
#include "../ComponentTest.hpp"

using namespace GameServer::Authorization;
using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class AuthorizationPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    AuthorizationPersistenceFacadeTest()
        : m_epoch_name("Epoch"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_land_name_5("Land5"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_5("Settlement5"),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_login_5("Login5"),
          m_world_name("World"),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_persistence_facade_abstract_factory->createWorldPersistenceFacade()),
          m_epoch_persistence_facade(m_persistence_facade_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_persistence_facade_abstract_factory->createLandPersistenceFacade()),
          m_settlement_persistence_facade(m_persistence_facade_abstract_factory->createSettlementPersistenceFacade())
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_user_persistence_facade->createUser(transaction, "Login1", "Password1");
            m_user_persistence_facade->createUser(transaction, "Login2", "Password2");

            m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name, m_land_name_2);

            m_land_1 = m_land_persistence_facade->getLand(transaction, m_land_name_1);
            m_land_2 = m_land_persistence_facade->getLand(transaction, m_land_name_2);

            m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);
            m_settlement_persistence_facade->createSettlement(transaction, m_land_2, m_settlement_name_2);

            transaction->commit();
        }
    }

    /**
     * @brief Test constants: the name of the epoch.
     */
    string m_epoch_name;

    /**
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2,
           m_land_name_5;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_5;

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
     * @brief Test constants: the lands.
     */
    ILandShrPtr m_land_1,
                m_land_2,
                m_land_5;

    /**
     * @brief The abstract factory of managers.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief The persistence facade of users.
     */
    IUserPersistenceFacadeShrPtr m_user_persistence_facade;

    /**
     * @brief The world persistence facade.
     */
    IWorldPersistenceFacadeShrPtr m_world_persistence_facade;

    /**
     * @brief The epoch persistence facade.
     */
    IEpochPersistenceFacadeShrPtr m_epoch_persistence_facade;

    /**
     * @brief The land persistence facade.
     */
    ILandPersistenceFacadeShrPtr m_land_persistence_facade;

    /**
     * @brief A settlement persistence facade.
     */
    ISettlementPersistenceFacadeShrPtr m_settlement_persistence_facade;
};

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandSuccess)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_TRUE(persistence_facade->authorizeUserToLand(transaction, m_login_1, m_land_name_1));
    ASSERT_TRUE(persistence_facade->authorizeUserToLand(transaction, m_login_2, m_land_name_2));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandFailure)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToLand(transaction, m_login_2, m_land_name_1));
    ASSERT_FALSE(persistence_facade->authorizeUserToLand(transaction, m_login_1, m_land_name_2));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandFailureMissingLogin)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToLand(transaction, m_login_5, m_land_name_1));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandFailureMissingLandName)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToLand(transaction, m_login_1, m_land_name_5));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementSuccess)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_TRUE(persistence_facade->authorizeUserToSettlement(transaction, m_login_1, m_settlement_name_1));
    ASSERT_TRUE(persistence_facade->authorizeUserToSettlement(transaction, m_login_2, m_settlement_name_2));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementFailure)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToSettlement(transaction, m_login_1, m_settlement_name_2));
    ASSERT_FALSE(persistence_facade->authorizeUserToSettlement(transaction, m_login_2, m_settlement_name_1));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementFailureMissingLogin)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToSettlement(transaction, m_login_5, m_settlement_name_1));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementFailureMissingSettlementName)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthorizationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthorizationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authorizeUserToSettlement(transaction, m_login_1, m_settlement_name_5));
}
