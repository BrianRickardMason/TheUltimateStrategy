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

#include <TUSGame/GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp>
#include <TUSGame/GameServerCT/ComponentTest.hpp>
#include <TUSCore/Network/XmlRPCServer/Context.hpp>

using namespace GameServer::Authentication;
using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace std;

/**
 * @brief A test class.
 */
class AuthenticationPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    AuthenticationPersistenceFacadeTest()
        : m_context(new Context),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_login_5("Login5"),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql(m_context)),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade())
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persistence_facade->createUser(transaction, "Login1", "Password1");
            m_user_persistence_facade->createUser(transaction, "Login2", "Password2");

            transaction->commit();
        }
    }

    /**
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2,
           m_login_5;

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief The abstract factory of persistence facades.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief The persistence facade of users.
     */
    IUserPersistenceFacadeShrPtr m_user_persistence_facade;
};

// TODO: More specific tests, more granularity.
TEST_F(AuthenticationPersistenceFacadeTest, AuthenticateSuccess)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthenticationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthenticationPersistenceFacade();

    ASSERT_TRUE(persistence_facade->authenticate(transaction, m_login_1, "Password1"));
    ASSERT_TRUE(persistence_facade->authenticate(transaction, m_login_2, "Password2"));
}

TEST_F(AuthenticationPersistenceFacadeTest, AuthenticateFailure)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    IAuthenticationPersistenceFacadeShrPtr persistence_facade =
        m_persistence_facade_abstract_factory->createAuthenticationPersistenceFacade();

    ASSERT_FALSE(persistence_facade->authenticate(transaction, m_login_1, "Password2"));
    ASSERT_FALSE(persistence_facade->authenticate(transaction, m_login_2, "Password1"));
    ASSERT_FALSE(persistence_facade->authenticate(transaction, m_login_5, "Password1"));
    ASSERT_FALSE(persistence_facade->authenticate(transaction, m_login_5, "Password2"));
}
