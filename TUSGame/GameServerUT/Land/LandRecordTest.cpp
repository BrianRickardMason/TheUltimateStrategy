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

#include <TUSGame/GameServer/Land/LandRecord.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Land;
using namespace std;

/**
 * @brief A test class.
 */
class LandRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    LandRecordTest()
        : m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_record(LandRecord(m_login, m_world_name, m_land_name, 1, false))
    {
    }

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief A land record to be tested.
     */
    LandRecord m_record;
};

TEST_F(LandRecordTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(LandRecord record(m_login, m_world_name, m_land_name, 1, false));
}

TEST_F(LandRecordTest, GetLoginReturnsProperValue)
{
    ASSERT_STREQ(m_login.c_str(), m_record.getLogin().c_str());
}

TEST_F(LandRecordTest, GetWorldNameReturnsProperValue)
{
    ASSERT_STREQ(m_world_name.c_str(), m_record.getWorldName().c_str());
}

TEST_F(LandRecordTest, GetLandNameReturnsProperValue)
{
    ASSERT_STREQ(m_land_name.c_str(), m_record.getLandName().c_str());
}

TEST_F(LandRecordTest, GetTurnsReturnsProperValue)
{
    ASSERT_EQ(1, m_record.getTurns());
}

TEST_F(LandRecordTest, GetGrantedReturnsProperValue)
{
    ASSERT_FALSE(m_record.getGranted());
}
