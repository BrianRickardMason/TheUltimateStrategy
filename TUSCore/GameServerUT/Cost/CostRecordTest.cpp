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

#include "../../GameServer/Cost/CostRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Cost;
using namespace GameServer::Resource;

/**
 * @brief A test class.
 */
class CostRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    CostRecordTest()
        : m_record(1001, 1, ID_RESOURCE_COAL, 100)
    {
    }

    /**
     * @brief A record to be tested.
     */
    CostRecord m_record;
};

/**
 * Unit tests of: CostRecord::CostRecord.
 */
TEST_F(CostRecordTest, CostRecord)
{
    // Test commands.
    CostRecord record(1001, 1, ID_RESOURCE_COAL, 100);

    // Test assertions.
    ASSERT_EQ(1001, record.getKeyHash());
    ASSERT_EQ(1, record.getIDCostType());
    ASSERT_TRUE(ID_RESOURCE_COAL == record.getIDResource());
    ASSERT_EQ(100, record.getVolume());
}

/**
 * Unit tests of: CostRecord::operator==.
 */
TEST_F(CostRecordTest, operator_cmp)
{
    // Preconditions.
    CostRecord cost_record_1(1001, 1, ID_RESOURCE_COAL, 100),
               cost_record_2(1001, 1, ID_RESOURCE_COAL, 100),
               cost_record_3(1002, 1, ID_RESOURCE_COAL, 100),
               cost_record_4(1001, 2, ID_RESOURCE_COAL, 100),
               cost_record_5(1001, 1, ID_RESOURCE_FOOD, 100),
               cost_record_6(1001, 1, ID_RESOURCE_COAL, 101);

    // Test commands and assertions.
    ASSERT_TRUE (cost_record_1 == cost_record_2);
    ASSERT_FALSE(cost_record_1 == cost_record_3);
    ASSERT_FALSE(cost_record_1 == cost_record_4);
    ASSERT_FALSE(cost_record_1 == cost_record_5);
    ASSERT_FALSE(cost_record_1 == cost_record_6);
}

/**
 * Unit tests of: CostRecord::getKeyHash.
 */
TEST_F(CostRecordTest, getKeyHash)
{
    // Test commands and assertions.
    ASSERT_EQ(1001, m_record.getKeyHash());
}

/**
 * Unit tests of: CostRecord::getIDCostType.
 */
TEST_F(CostRecordTest, getIDCostType)
{
    // Test commands and assertions.
    ASSERT_EQ(1, m_record.getIDCostType());
}

/**
 * Unit tests of: CostRecord::getIDResource.
 */
TEST_F(CostRecordTest, getIDResource)
{
    // Test commands and assertions.
    ASSERT_TRUE(ID_RESOURCE_COAL == m_record.getIDResource());
}

/**
 * Unit tests of: CostRecord::getVolume.
 */
TEST_F(CostRecordTest, getVolume)
{
    // Test commands and assertions.
    ASSERT_EQ(100, m_record.getVolume());
}
