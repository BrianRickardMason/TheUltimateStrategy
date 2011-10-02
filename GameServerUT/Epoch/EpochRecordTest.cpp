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

#include "../../GameServer/Epoch/EpochRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Epoch;
using namespace std;

/**
 * @brief A test class.
 */
class EpochRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    EpochRecordTest()
        : m_world_name("World"),
          m_record(EpochRecord(IDEpoch(1), m_world_name, true, false, 22))
    {
    }

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the record of the epoch.
     */
    EpochRecord m_record;
};

TEST_F(EpochRecordTest, EpochRecord)
{
    EpochRecord record(IDEpoch(1), m_world_name, true, false, 22);

    ASSERT_EQ(1, record.getIDEpoch().getValue());
    ASSERT_STREQ(m_world_name.c_str(), record.getWorldName().c_str());
    ASSERT_TRUE(record.getActive());
    ASSERT_FALSE(record.getFinished());
    ASSERT_EQ(22, record.getTicks());
}

TEST_F(EpochRecordTest, getIDEpoch)
{
    ASSERT_EQ(1, m_record.getIDEpoch().getValue());
}

TEST_F(EpochRecordTest, GetWorldNameReturnsProperValue)
{
    ASSERT_STREQ(m_world_name.c_str(), m_record.getWorldName().c_str());
}

TEST_F(EpochRecordTest, getActive)
{
    ASSERT_TRUE(m_record.getActive());
}

TEST_F(EpochRecordTest, getFinished)
{
    ASSERT_FALSE(m_record.getFinished());
}

TEST_F(EpochRecordTest, getTicks)
{
    ASSERT_EQ(22, m_record.getTicks());
}
