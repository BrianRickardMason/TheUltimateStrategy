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

#include "../../GameServer/Authentication/AuthenticationPersistencyFacade.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "AuthenticationManagerAccessorMock.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Authentication;
using namespace GameServer::Persistency;
using namespace std;

using testing::Return;

/**
 * @brief A test class.
 */
class AuthenticationPersistencyFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    AuthenticationPersistencyFacadeTest()
        : m_login("Login"),
          m_password("Password")
    {
    }

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the password of the user.
     */
    string m_password;
};

TEST_F(AuthenticationPersistencyFacadeTest, CtorDoesNotThrow)
{
    IAuthenticationManagerAccessorAutPtr accessor(new AuthenticationManagerAccessorMock);

    ASSERT_NO_THROW(AuthenticationPersistencyFacade persistency_facade(accessor));
}

/**
 * Unit tests of: AuthenticationPersistencyFacade::authenticate.
 */
TEST_F(AuthenticationPersistencyFacadeTest, AuthenticateReturnsTrueOnSuccessfulAuthentication)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthenticationManagerAccessorMock * mock = new AuthenticationManagerAccessorMock;
    EXPECT_CALL(*mock, authenticate(transaction, m_login, m_password))
    .WillOnce(Return(true));

    IAuthenticationManagerAccessorAutPtr accessor(mock);

    AuthenticationPersistencyFacade persistency_facade(accessor);

    ASSERT_TRUE(persistency_facade.authenticate(transaction, m_login, m_password));
}

TEST_F(AuthenticationPersistencyFacadeTest, AuthenticateReturnsFalseOnUnsuccessfulAuthentication)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    AuthenticationManagerAccessorMock * mock = new AuthenticationManagerAccessorMock;
    EXPECT_CALL(*mock, authenticate(transaction, m_login, m_password))
    .WillOnce(Return(false));

    IAuthenticationManagerAccessorAutPtr accessor(mock);

    AuthenticationPersistencyFacade persistency_facade(accessor);

    ASSERT_FALSE(persistency_facade.authenticate(transaction, m_login, m_password));
}
