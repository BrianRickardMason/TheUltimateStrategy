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

#include "../../GameServer/Cost/Cost.hpp"
#include "../../GameServer/Resource/Key.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Cost;
using namespace GameServer::Resource;

/**
 * @brief A test class.
 */
class CostTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    CostTest()
        : m_cost(CostRecord("Brandy", 1, KEY_RESOURCE_COAL, 100))
    {
    }

    /**
     * @brief A cost to be tested.
     */
    Cost m_cost;
};

TEST_F(CostTest, CtorDoesNotThrow)
{
    CostRecord record("Brandy", 1, KEY_RESOURCE_COAL, 100);

    ASSERT_NO_THROW(Cost cost(record));
}

/**
 * Unit tests of: Cost::operator*.
 */
TEST_F(CostTest, operator_mul)
{
    // Preconditions.
    CostRecord record("Brandy", 1, KEY_RESOURCE_COAL, 100);

    Cost cost_0(record),
         cost_1(record),
         cost_2(record);

    // Test commands.
    cost_0 = cost_0 * 0;
    cost_1 = cost_1 * 1;
    cost_2 = cost_2 * 2;

    // Test assertions.
    ASSERT_EQ(0, cost_0.getVolume());
    ASSERT_EQ(100, cost_1.getVolume());
    ASSERT_EQ(200, cost_2.getVolume());

    // Test commands.
    cost_2 = cost_1 * 3;

    // Test assertions.
    ASSERT_EQ(100, cost_1.getVolume());
    ASSERT_EQ(300, cost_2.getVolume());

    // Test commands and assertions.
    ASSERT_EQ(600, cost_2.operator *(2).getVolume());
}

/**
 * Unit tests of: Cost::operator*=.
 */
TEST_F(CostTest, operator_mul_assign)
{
    // Preconditions.
    CostRecord record("Brandy", 1, KEY_RESOURCE_COAL, 100);

    Cost cost_0(record),
         cost_1(record),
         cost_2(record);

    // Test commands.
    cost_0 *= 0;
    cost_1 *= 1;
    cost_2 *= 2;

    // Test assertions.
    ASSERT_EQ(0, cost_0.getVolume());
    ASSERT_EQ(100, cost_1.getVolume());
    ASSERT_EQ(200, cost_2.getVolume());

    // Test commands and assertions.
    ASSERT_EQ(300, cost_1.operator *=(3).getVolume());
    ASSERT_EQ(300, cost_1.getVolume());
}

/**
 * Unit tests of: Cost::getKey.
 */
TEST_F(CostTest, getKey)
{
    // Test commands and assertions.
    ASSERT_EQ("Brandy", m_cost.getKey());
}

/**
 * Unit tests of: Cost::getIDCostType.
 */
TEST_F(CostTest, getIDCostType)
{
    // Test commands and assertions.
    ASSERT_EQ(1, m_cost.getIDCostType());
}

TEST_F(CostTest, GetResourceKeyReturnsProperValue)
{
    ASSERT_TRUE(KEY_RESOURCE_COAL == m_cost.getResourceKey());
}

/**
 * Unit tests of: Cost::getVolume.
 */
TEST_F(CostTest, getVolume)
{
    // Test commands and assertions.
    ASSERT_EQ(100, m_cost.getVolume());
}

TEST_F(CostTest, getKey_Equal)
{
    ASSERT_TRUE(KEY_RESOURCE_COAL == m_cost.toResourceKey());
}

TEST_F(CostTest, getKey_NotEqual)
{
    ASSERT_FALSE(KEY_RESOURCE_FOOD == m_cost.toResourceKey());
}
