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

#include <TUSGame/GameServer/User/UserRecord.hpp>
#include <gmock/gmock.h>

using namespace GameServer::User;

/**
 * @brief The test class of the record of the user.
 */
class UserRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    UserRecordTest()
        : m_record(UserRecord("Login", "Password", true))
    {
    }

    /**
     * @brief Test constants: the record of the user.
     */
    UserRecord m_record;
};

TEST_F(UserRecordTest, ConstructorSetsProperLoginValue)
{
    ASSERT_STREQ("Login", m_record.getLogin().c_str());
}

TEST_F(UserRecordTest, ConstructorSetsProperPasswordValue)
{
    ASSERT_STREQ("Password", m_record.getPassword().c_str());
}

TEST_F(UserRecordTest, ConstructorSetsProperModeratorValue)
{
    ASSERT_EQ(true, m_record.isModerator());
}

TEST_F(UserRecordTest, GetLoginReturnsProperValue)
{
    ASSERT_STREQ("Login", m_record.getLogin().c_str());
}

TEST_F(UserRecordTest, GetPasswordReturnsProperValue)
{
    ASSERT_STREQ("Password", m_record.getPassword().c_str());
}

TEST_F(UserRecordTest, IsModeratorReturnsProperValue)
{
    ASSERT_EQ(true, m_record.isModerator());
}
