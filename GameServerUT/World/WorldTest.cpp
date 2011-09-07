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

#include "../../GameServer/World/World.hpp"
#include "../../GameServer/World/WorldRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::World;

/**
 * @brief The test class of the world.
 */
class WorldTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class of the world.
     */
    WorldTest()
        : m_world_record(new WorldRecord(IDWorld(1), "World1")),
          m_world(m_world_record)
    {
    }

    /**
     * @brief Test constants: the record of the world.
     */
    IWorldRecordShrPtr m_world_record;

    /**
     * @brief Test constants: the world.
     */
    World m_world;
};

TEST_F(WorldTest, ConstructorSetsProperIDWorldValue)
{
    World world(m_world_record);

    ASSERT_EQ(1, world.getIDWorld().getValue());
}

TEST_F(WorldTest, ConstuctorSetsProperNameValue)
{
    World world(m_world_record);

    ASSERT_STREQ("World1", world.getName().c_str());
}

TEST_F(WorldTest, GetIDWorldReturnsProperValue)
{
    ASSERT_EQ(1, m_world.getIDWorld().getValue());
}

TEST_F(WorldTest, GetNameReturnsProperValue)
{
    ASSERT_STREQ("World1", m_world.getName().c_str());
}
