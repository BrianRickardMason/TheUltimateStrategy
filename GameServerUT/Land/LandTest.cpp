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

#include "../../GameServer/Land/Land.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace std;

/**
 * @brief A test class.
 */
class LandTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    LandTest()
        : m_login("Login"),
          m_world_name("World"),
          m_land(LandRecord(m_login, m_world_name, IDEpoch(4), IDLand(3), "Land1", false))
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
     * @brief Test constants: the land.
     */
    Land m_land;
};

TEST_F(LandTest, Land)
{
    LandRecord record(m_login, m_world_name, IDEpoch(4), IDLand(3), "Land1", false);
    Land land(record);

    ASSERT_STREQ(m_login.c_str(), land.getLogin().c_str());
    ASSERT_STREQ(m_world_name.c_str(), land.getWorldName().c_str());
    ASSERT_EQ(4, land.getIDEpoch().getValue());
    ASSERT_EQ(3, land.getIDLand().getValue());
    ASSERT_STREQ("Land1", land.getName().c_str());
    ASSERT_FALSE(land.getGranted());
}

TEST_F(LandTest, getLogin)
{
    ASSERT_EQ(m_login.c_str(), m_land.getLogin().c_str());
}

TEST_F(LandTest, GetWorldNameReturnsProperValue)
{
    ASSERT_STREQ(m_world_name.c_str(), m_land.getWorldName().c_str());
}

TEST_F(LandTest, getIDEpoch)
{
    ASSERT_EQ(4, m_land.getIDEpoch().getValue());
}

TEST_F(LandTest, getIDLand)
{
    ASSERT_EQ(3, m_land.getIDLand().getValue());
}

TEST_F(LandTest, getName)
{
    ASSERT_STREQ("Land1", m_land.getName().c_str());
}

TEST_F(LandTest, getGranted)
{
    ASSERT_FALSE(m_land.getGranted());
}
