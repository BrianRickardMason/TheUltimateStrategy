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
 * @brief A test class.
 */
class UserManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    UserManagerTest()
        : m_id_user_1(1)
    {
    }

    /**
     * @brief Test constants identifiers of the user.
     */
    IDUser m_id_user_1;
};

TEST_F(UserManagerTest, UserManager)
{
    IUserManagerAccessorAutPtr accessor(new UserManagerAccessorMock);

    ASSERT_NO_THROW(UserManager manager(accessor));
}

TEST_F(UserManagerTest, createUser_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, "Login", "Password"));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_TRUE(manager.createUser(transaction, "Login", "Password"));
}

TEST_F(UserManagerTest, createUser_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, "Login", "Password"))
    .WillOnce(Throw(e));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_FALSE(manager.createUser(transaction, "Login", "Password"));
}

TEST_F(UserManagerTest, deleteUser_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, IDUser(1)));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_TRUE(manager.deleteUser(transaction, IDUser(1)));
}

TEST_F(UserManagerTest, deleteUser_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, IDUser(1)))
    .WillOnce(Throw(e));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    ASSERT_FALSE(manager.deleteUser(transaction, IDUser(1)));
}

TEST_F(UserManagerTest, getUserByIDUser_UserDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByLogin(transaction, "Login"))
    .WillOnce(Return(UserRecordShrPtr()));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    UserShrPtr user = manager.getUserByLogin(transaction, "Login");

    ASSERT_TRUE(user == NULL);
}

TEST_F(UserManagerTest, getUserByLogin_UserDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    UserManagerAccessorMock * mock = new UserManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByLogin(transaction, "Login"))
    .WillOnce(Return(make_shared<UserRecord>(m_id_user_1, "Login", "Password")));

    IUserManagerAccessorAutPtr accessor(mock);

    UserManager manager(accessor);

    UserShrPtr user = manager.getUserByLogin(transaction, "Login");

    ASSERT_TRUE(user != NULL);

    ASSERT_TRUE(m_id_user_1 == user->getIDUser());
    ASSERT_STREQ("Login", user->getLogin().c_str());
    ASSERT_STREQ("Password", user->getPassword().c_str());
}
