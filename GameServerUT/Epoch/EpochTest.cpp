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

#include "../../GameServer/Epoch/Epoch.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Epoch;
using namespace GameServer::World;

/**
 * @brief A test class.
 */
class EpochTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    EpochTest()
        : m_epoch(EpochRecord(IDEpoch(1), IDWorld(2), true, false, 22))
    {
    }

    /**
     * @brief The epoch to be tested.
     */
    Epoch m_epoch;
};

TEST_F(EpochTest, Epoch)
{
    EpochRecord record(IDEpoch(1), IDWorld(2), true, false, 22);

    Epoch epoch(record);

    ASSERT_EQ(1, epoch.getIDEpoch().getValue());
    ASSERT_EQ(2, epoch.getIDWorld().getValue());
    ASSERT_TRUE(epoch.getActive());
    ASSERT_FALSE(epoch.getFinished());
    ASSERT_EQ(22, epoch.getTicks());
}

TEST_F(EpochTest, getIDEpoch)
{
    ASSERT_EQ(1, m_epoch.getIDEpoch().getValue());
}

TEST_F(EpochTest, getIDWorld)
{
    ASSERT_EQ(2, m_epoch.getIDWorld().getValue());
}

TEST_F(EpochTest, getActive)
{
    ASSERT_TRUE(m_epoch.getActive());
}

TEST_F(EpochTest, getFinished)
{
    ASSERT_FALSE(m_epoch.getFinished());
}

TEST_F(EpochTest, getTicks)
{
    ASSERT_EQ(22, m_epoch.getTicks());
}
