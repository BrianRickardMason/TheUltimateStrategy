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

#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace std;

/**
 * @brief A test class.
 */
class UserManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    UserManagerTest()
        : m_login("Login"),
          m_password("Password"),
          m_different_password("DifferentPassword"),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
          m_manager(m_persistence_facade_abstract_factory->createUserPersistenceFacade())
    {
    }

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the passwords of the users.
     */
    string m_password,
           m_different_password;

    /**
     * @brief The abstract factory of managers.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief A manager.
     */
    IUserPersistenceFacadeShrPtr m_manager;
};

/**
 * Component tests of: UserManager::createUser.
 */
TEST_F(UserManagerTest, createUser_UserDoesNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, m_login, m_password));
    transaction->commit();
}

TEST_F(UserManagerTest, createUser_UserDoesExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, m_login, m_password));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_manager->createUser(transaction, m_login, m_password));
}

TEST_F(UserManagerTest, createUser_UserDoesExistDifferentPassword)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, m_login, m_password));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_FALSE(m_manager->createUser(transaction, m_login, m_different_password));
}

/**
 * Component tests of: UserManager::deleteUser.
 */
TEST_F(UserManagerTest, deleteUser_UserDoesNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->deleteUser(transaction, m_login));
    transaction->commit();
}

TEST_F(UserManagerTest, deleteUser_UserDoesExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, m_login, m_password));
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    ASSERT_TRUE(m_manager->deleteUser(transaction, m_login));
    transaction->commit();
}

/**
 * Component tests of: UserManager::getUser.
 */
TEST_F(UserManagerTest, getUser_UserDoesNotExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    IUserShrPtr user = m_manager->getUser(transaction, m_login);
    transaction->commit();

    ASSERT_TRUE(user == NULL);
}

TEST_F(UserManagerTest, getUser_UserDoesExist)
{
    PersistencePostgresql persistence;
    IConnectionShrPtr connection = persistence.getConnection();

    ITransactionShrPtr transaction = persistence.getTransaction(connection);
    m_manager->createUser(transaction, m_login, "m_password");
    transaction->commit();

    transaction = persistence.getTransaction(connection);
    IUserShrPtr user = m_manager->getUser(transaction, m_login);
    transaction->commit();

    ASSERT_FALSE(user == NULL);
}
