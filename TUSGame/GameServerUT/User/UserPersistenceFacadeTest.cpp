// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <TUSGame/GameServer/User/UserPersistenceFacade.hpp>
#include <TUSGame/GameServer/User/UserRecord.hpp>
#include <TUSGame/GameServerUT/Persistence/TransactionDummy.hpp>
#include <TUSGame/GameServerUT/User/UserAccessorMock.hpp>
#include <boost/make_shared.hpp>

using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class of UserPersistenceFacade.
 */
class UserPersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class of UserPersistenceFacade.
     */
    UserPersistenceFacadeTest()
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

TEST_F(UserPersistenceFacadeTest, ConstructorDoesNotThrow)
{
    IUserAccessorAutPtr accessor(new UserAccessorMock);

    ASSERT_NO_THROW(UserPersistenceFacade persistence_facade(accessor));
}

TEST_F(UserPersistenceFacadeTest, CreateUserReturnsTrueOnSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login, m_password));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.createUser(transaction, m_login, m_password));
}

TEST_F(UserPersistenceFacadeTest, CreateUserReturnsFalseOnFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login, m_password))
    .WillOnce(Throw(e));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.createUser(transaction, m_login, m_password));
}

TEST_F(UserPersistenceFacadeTest, DeleteUserReturnsTrueOnSuccess)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_login));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.deleteUser(transaction, m_login));
}

TEST_F(UserPersistenceFacadeTest, DeleteUserReturnsFalseOnFailure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_login))
    .WillOnce(Throw(e));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deleteUser(transaction, m_login));
}

TEST_F(UserPersistenceFacadeTest, GetUserReturnsNullIfUserDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(IUserRecordShrPtr()));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    IUserShrPtr user = persistence_facade.getUser(transaction, m_login);

    ASSERT_TRUE(user == NULL);
}

TEST_F(UserPersistenceFacadeTest, GetUserReturnedUserHasProperLogin)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(m_user_record));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    IUserShrPtr user = persistence_facade.getUser(transaction, m_login);

    ASSERT_STREQ(m_login.c_str(), user->getLogin().c_str());
}

TEST_F(UserPersistenceFacadeTest, GetUserReturnedUserHasProperPassword)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserAccessorMock * mock = new UserAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_login))
    .WillOnce(Return(m_user_record));

    IUserAccessorAutPtr accessor(mock);

    UserPersistenceFacade persistence_facade(accessor);

    IUserShrPtr user = persistence_facade.getUser(transaction, m_login);

    ASSERT_STREQ(m_password.c_str(), user->getPassword().c_str());
}
