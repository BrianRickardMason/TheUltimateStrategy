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
        : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_manager(m_manager_abstract_factory->createUserManager())
    {
    }

    /**
     * @brief Test constants identifiers of the user.
     */
    IDUser m_id_user_1;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A manager.
     */
    IUserManagerShrPtr m_manager;
};

/**
 * Component tests of: UserManager::createUser.
 */
TEST_F(UserManagerTest, createUser_UserDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, "Login", "Password"));
    transaction->commit();
}

TEST_F(UserManagerTest, createUser_UserDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, "Login", "Password"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_FALSE(m_manager->createUser(transaction, "Login", "Password"));
}

TEST_F(UserManagerTest, createUser_UserDoesExistDifferentPassword)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, "Login", "Password1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_FALSE(m_manager->createUser(transaction, "Login", "Password2"));
}

/**
 * Component tests of: UserManager::deleteUser.
 */
TEST_F(UserManagerTest, deleteUser_UserDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->deleteUser(transaction, m_id_user_1));
    transaction->commit();
}

TEST_F(UserManagerTest, deleteUser_UserDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->createUser(transaction, "Login", "Password1"));
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    ASSERT_TRUE(m_manager->deleteUser(transaction, m_id_user_1));
    transaction->commit();
}

/**
 * Component tests of: UserManager::getUserByLogin.
 */
TEST_F(UserManagerTest, getUserByLogin_UserDoesNotExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    IUserShrPtr user = m_manager->getUserByLogin(transaction, "Login");
    transaction->commit();

    ASSERT_TRUE(user == NULL);
}

TEST_F(UserManagerTest, getUserByLogin_UserDoesExist)
{
    PersistencyPostgresql persistency;
    IConnectionShrPtr connection = persistency.getConnection();

    ITransactionShrPtr transaction = persistency.getTransaction(connection);
    m_manager->createUser(transaction, "Login", "Password1");
    transaction->commit();

    transaction = persistency.getTransaction(connection);
    IUserShrPtr user = m_manager->getUserByLogin(transaction, "Login");
    transaction->commit();

    ASSERT_FALSE(user == NULL);
}
