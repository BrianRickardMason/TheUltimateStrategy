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

#include "../../GameServer/User/UserManager.hpp"
#include "../../GameServer/User/UserRecord.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "UserManagerAccessorMock.hpp"
#include <boost/make_shared.hpp>

using namespace GameServer::Persistency;
using namespace GameServer::User;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class of UserManager.
 */
class UserManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class of UserManager.
     */
    UserManagerTest()
        : m_login("Login"),
          m_password("Password"),
          m_user_record(new UserRecord(m_login, m_password, false))
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

    /**
     * @brief Test constants: the record of the user.
     */
    IUserRecordShrPtr m_user_record;
};

TEST_F(UserManagerTest, ConstructorDoesNotThrow)
{
    IUserManagerAccessorAutPtr accessor(new UserManagerAccessorMock);

    ASSERT_NO_THROW(UserManager manager(accessor));
}

TEST_F(UserManagerTest, CreateUserReturnsTrueOnSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login, m_password));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_TRUE(manager.createUser(transaction, m_login, m_password));
}

TEST_F(UserManagerTest, CreateUserReturnsFalseOnFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login, m_password))
    .WillOnce(Throw(e));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_FALSE(manager.createUser(transaction, m_login, m_password));
}

TEST_F(UserManagerTest, DeleteUserReturnsTrueOnSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_login));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_TRUE(manager.deleteUser(transaction, m_login));
}

TEST_F(UserManagerTest, DeleteUserReturnsFalseOnFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_login))
    .WillOnce(Throw(e));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_FALSE(manager.deleteUser(transaction, m_login));
}

TEST_F(UserManagerTest, GetUserReturnsNullIfUserDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(IUserRecordShrPtr()));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    IUserShrPtr user = manager.getUser(transaction, m_login);

    ASSERT_TRUE(user == NULL);
}

TEST_F(UserManagerTest, GetUserReturnedUserHasProperLogin)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(m_user_record));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    IUserShrPtr user = manager.getUser(transaction, m_login);

    ASSERT_STREQ(m_login.c_str(), user->getLogin().c_str());
}

TEST_F(UserManagerTest, GetUserReturnedUserHasProperPassword)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(m_user_record));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    IUserShrPtr user = manager.getUser(transaction, m_login);

    ASSERT_STREQ(m_password.c_str(), user->getPassword().c_str());
}
