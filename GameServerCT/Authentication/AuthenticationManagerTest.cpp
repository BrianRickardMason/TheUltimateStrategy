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
#include "../ComponentTest.hpp"

using namespace GameServer::Authentication;
using namespace GameServer::Common;
using namespace GameServer::Persistency;
using namespace GameServer::User;

/**
 * @brief A test class.
 */
class AuthenticationManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    AuthenticationManagerTest()
        : m_id_user_1(1),
          m_id_user_2(2),
          m_id_user_5(5),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager())
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login1", "Password1");
            m_user_manager->createUser(transaction, "Login2", "Password2");

            transaction->commit();
        }
    }

    /**
     * @brief Test constants identifiers of the users.
     */
    IDUser m_id_user_1,
           m_id_user_2,
           m_id_user_5;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A user manager.
     */
    IUserManagerShrPtr m_user_manager;
};

/**
 * Component tests of: AuthenticationManager::authenticate.
 */
TEST_F(AuthenticationManagerTest, authenticate_Success)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthenticationManagerShrPtr manager = m_manager_abstract_factory->createAuthenticationManager();

    ASSERT_TRUE(manager->authenticate(transaction, m_id_user_1, "Password1"));
    ASSERT_TRUE(manager->authenticate(transaction, m_id_user_2, "Password2"));
}

TEST_F(AuthenticationManagerTest, authenticate_Failure)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    IAuthenticationManagerShrPtr manager = m_manager_abstract_factory->createAuthenticationManager();

    ASSERT_FALSE(manager->authenticate(transaction, m_id_user_1, "Password2"));
    ASSERT_FALSE(manager->authenticate(transaction, m_id_user_2, "Password1"));
    ASSERT_FALSE(manager->authenticate(transaction, m_id_user_5, "Password1"));
    ASSERT_FALSE(manager->authenticate(transaction, m_id_user_5, "Password2"));
}
