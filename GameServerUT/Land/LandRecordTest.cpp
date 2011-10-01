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

#include "../../GameServer/Land/LandRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::World;
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
          m_record(LandRecord(m_login, IDWorld(1), IDEpoch(1), IDLand(1), "Land1", false))
    {
    }

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief A land record to be tested.
     */
    LandRecord m_record;
};

TEST_F(LandRecordTest, LandRecord)
{
    LandRecord record(m_login, IDWorld(1), IDEpoch(1), IDLand(1), "Land1", false);

    ASSERT_STREQ(m_login.c_str(), record.getLogin().c_str());
    ASSERT_EQ(1, record.getIDWorld().getValue());
    ASSERT_EQ(1, record.getIDEpoch().getValue());
    ASSERT_EQ(1, record.getIDLand().getValue());
    ASSERT_STREQ("Land1", record.getName().c_str());
    ASSERT_FALSE(record.getGranted());
}

TEST_F(LandRecordTest, getLogin)
{
    ASSERT_STREQ(m_login.c_str(), m_record.getLogin().c_str());
}

TEST_F(LandRecordTest, getIDWorld)
{
    ASSERT_EQ(1, m_record.getIDWorld().getValue());
}

TEST_F(LandRecordTest, getIDEpoch)
{
    ASSERT_EQ(1, m_record.getIDEpoch().getValue());
}

TEST_F(LandRecordTest, getIDLand)
{
    ASSERT_EQ(1, m_record.getIDLand().getValue());
}

TEST_F(LandRecordTest, getName)
{
    ASSERT_STREQ("Land1", m_record.getName().c_str());
}

TEST_F(LandRecordTest, getGranted)
{
    ASSERT_FALSE(m_record.getGranted());
}
