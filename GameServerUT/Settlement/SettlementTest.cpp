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

#include "../../GameServer/Settlement/Settlement.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Settlement;
using namespace std;

/**
 * @brief A test class.
 */
class SettlementTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    SettlementTest()
        : m_land_name("Land"),
          m_settlement(SettlementRecord(m_land_name, IDSettlement(11), "Settlement1"))
    {
    }

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the settlement.
     */
    Settlement m_settlement;
};

TEST_F(SettlementTest, Settlement)
{
    SettlementRecord record(m_land_name, IDSettlement(11), "Settlement1");
    Settlement settlement(record);

    ASSERT_STREQ(m_land_name.c_str(), record.getLandName().c_str());
    ASSERT_EQ(11, settlement.getIDSettlement().getValue());
    ASSERT_STREQ("Settlement1", settlement.getName().c_str());
}

TEST_F(SettlementTest, GetLandNameReturnsProperValue)
{
    ASSERT_STREQ(m_land_name.c_str(), m_settlement.getLandName().c_str());
}

TEST_F(SettlementTest, GetIDSettlementReturnsProperValue)
{
    ASSERT_EQ(11, m_settlement.getIDSettlement().getValue());
}

TEST_F(SettlementTest, GetNameReturnsProperValue)
{
    ASSERT_STREQ("Settlement1", m_settlement.getName().c_str());
}
