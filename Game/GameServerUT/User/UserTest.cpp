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

#include <Game/GameServer/User/User.hpp>
#include <Game/GameServer/User/UserRecord.hpp>
#include <gmock/gmock.h>

using namespace GameServer::User;

/**
 * @brief The test class of the user.
 */
class UserTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class of the user.
     */
    UserTest()
        : m_user(IUserRecordShrPtr(new UserRecord("Login", "Password", false)))
    {
    }

    /**
     * @brief Test constants: the user.
     */
    User m_user;
};

TEST_F(UserTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(User user(IUserRecordShrPtr(new UserRecord("Login", "Password", false))));
}

TEST_F(UserTest, GetLoginReturnsProperValue)
{
    ASSERT_STREQ("Login", m_user.getLogin().c_str());
}

TEST_F(UserTest, GetPasswordReturnsProperValue)
{
    ASSERT_STREQ("Password", m_user.getPassword().c_str());
}

TEST_F(UserTest, IsModeratorReturnsProperValue)
{
    ASSERT_FALSE(m_user.isModerator());
}
