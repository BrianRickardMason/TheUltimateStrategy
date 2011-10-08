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

#include "../../GameServer/Settlement/SettlementRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Settlement;
using namespace std;

/**
 * @brief A test class.
 */
class SettlementRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    SettlementRecordTest()
        : m_land_name("Land"),
          m_settlement_name("Settlement"),
          m_record(SettlementRecord(m_land_name, m_settlement_name))
    {
    }

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the name of the settlement.
     */
    string m_settlement_name;

    /**
     * @brief Test constants: the record of the settlement.
     */
    SettlementRecord m_record;
};

TEST_F(SettlementRecordTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(SettlementRecord record(m_land_name, m_settlement_name));
}

TEST_F(SettlementRecordTest, GetLandNameReturnsProperValue)
{
    ASSERT_STREQ(m_land_name.c_str(), m_record.getLandName().c_str());
}

TEST_F(SettlementRecordTest, GetSettlementNameReturnsProperValue)
{
    ASSERT_STREQ(m_settlement_name.c_str(), m_record.getSettlementName().c_str());
}
