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

#include "../../GameServer/Property/PropertyRecord.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Property;

/**
 * @brief A test class.
 */
class PropertyRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyRecordTest()
        : m_record(1001, ID_PROPERTY_HUMAN_ENGAGEABLE, DISCRIMINATOR_BOOLEAN, false, 42, "dummy")
    {
    }

    /**
     * @brief A record to be tested.
     */
    PropertyRecord m_record;
};

/**
 * Unit tests of: PropertyRecord::PropertyRecord.
 */
TEST_F(PropertyRecordTest, PropertyRecord)
{
    IDProperty id_property(ID_PROPERTY_HUMAN_ENGAGEABLE);

    PropertyRecord record(1001, id_property, DISCRIMINATOR_BOOLEAN, false, 42, "dummy");

    ASSERT_EQ(1001, record.getKeyHash());
    ASSERT_TRUE(id_property == record.getIDProperty());
    ASSERT_EQ(DISCRIMINATOR_BOOLEAN, record.getDiscriminator());
    ASSERT_FALSE(record.getValueBoolean());
    ASSERT_EQ(42, record.getValueInteger());
    ASSERT_EQ("dummy", record.getValueString());
}

/**
 * Unit tests of: PropertyRecord::getKeyHash.
 */
TEST_F(PropertyRecordTest, getKeyHash)
{
    ASSERT_EQ(1001, m_record.getKeyHash());
}

/**
 * Unit tests of: PropertyRecord::getIDProperty.
 */
TEST_F(PropertyRecordTest, getIDProperty)
{
    IDProperty id_property(ID_PROPERTY_HUMAN_ENGAGEABLE);

    ASSERT_TRUE(id_property == m_record.getIDProperty());
}

/**
 * Unit tests of: PropertyRecord::getDiscriminator.
 */
TEST_F(PropertyRecordTest, getDiscriminator)
{
    ASSERT_EQ(DISCRIMINATOR_BOOLEAN, m_record.getDiscriminator());
}

/**
 * Unit tests of: PropertyRecord::getValueBoolean.
 */
TEST_F(PropertyRecordTest, getValueBoolean)
{
    ASSERT_FALSE(m_record.getValueBoolean());
}

/**
 * Unit tests of: PropertyRecord::getValueInteger.
 */
TEST_F(PropertyRecordTest, getValueInteger)
{
    ASSERT_EQ(42, m_record.getValueInteger());
}

/**
 * Unit tests of: PropertyRecord::getValueString.
 */
TEST_F(PropertyRecordTest, getValueString)
{
    ASSERT_STREQ("dummy", m_record.getValueString().c_str());
}
