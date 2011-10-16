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

#include "../../GameServer/Authorization/AuthorizationPersistenceFacade.hpp"
#include "../Persistence/TransactionDummy.hpp"
#include "AuthorizationManagerAccessorMock.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Authorization;
using namespace GameServer::Persistence;
using namespace std;

using testing::Return;

/**
 * @brief A test class.
 */
class AuthorizationPersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    AuthorizationPersistenceFacadeTest()
        : m_login("Login"),
          m_land_name("Land"),
          m_settlement_name("Settlement")
    {
    }

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the name of the settlement.
     */
    string m_settlement_name;
};

TEST_F(AuthorizationPersistenceFacadeTest, CtorDoesNotThrow)
{
    IAuthorizationManagerAccessorAutPtr accessor(new AuthorizationManagerAccessorMock);

    ASSERT_NO_THROW(AuthorizationPersistenceFacade persistence_facade(accessor));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthorizationManagerAccessorMock * mock = new AuthorizationManagerAccessorMock;
    EXPECT_CALL(*mock, authorizeUserToLand(transaction, m_login, m_land_name))
    .WillOnce(Return(true));

    IAuthorizationManagerAccessorAutPtr accessor(mock);

    AuthorizationPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.authorizeUserToLand(transaction, m_login, m_land_name));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToLandFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthorizationManagerAccessorMock * mock = new AuthorizationManagerAccessorMock;
    EXPECT_CALL(*mock, authorizeUserToLand(transaction, m_login, m_land_name))
    .WillOnce(Return(false));

    IAuthorizationManagerAccessorAutPtr accessor(mock);

    AuthorizationPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.authorizeUserToLand(transaction, m_login, m_land_name));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthorizationManagerAccessorMock * mock = new AuthorizationManagerAccessorMock;
    EXPECT_CALL(*mock, getLandNameOfSettlement(transaction, m_settlement_name))
    .WillOnce(Return(m_land_name));
    EXPECT_CALL(*mock, authorizeUserToLand(transaction, m_login, m_land_name))
    .WillOnce(Return(true));

    IAuthorizationManagerAccessorAutPtr accessor(mock);

    AuthorizationPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.authorizeUserToSettlement(transaction, m_login, m_settlement_name));
}

TEST_F(AuthorizationPersistenceFacadeTest, AuthorizeUserToSettlementFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthorizationManagerAccessorMock * mock = new AuthorizationManagerAccessorMock;
    EXPECT_CALL(*mock, getLandNameOfSettlement(transaction, m_settlement_name))
    .WillOnce(Return(m_land_name));
    EXPECT_CALL(*mock, authorizeUserToLand(transaction, m_login, m_land_name))
    .WillOnce(Return(false));

    IAuthorizationManagerAccessorAutPtr accessor(mock);

    AuthorizationPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.authorizeUserToSettlement(transaction, m_login, m_settlement_name));
}
