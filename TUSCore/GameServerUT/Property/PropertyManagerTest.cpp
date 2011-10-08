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

#include "../../GameServer/Property/PropertyManager.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "PropertyManagerAccessorMock.hpp"
#include <boost/make_shared.hpp>
#include <stdexcept>

using namespace GameServer::Common;
using namespace GameServer::Persistency;
using namespace GameServer::Property;
using namespace boost;
using namespace std;

using testing::Return;

/**
 * @brief A test class.
 */
class PropertyManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyManagerTest()
        : m_key_hash_1(1),
          m_id_property_1(1),
          m_id_property_2(2),
          m_id_property_3(3)
    {
    }

    /**
     * @brief Test constants: key hashes.
     */
    KeyHash m_key_hash_1;

    /**
     * @brief Test constants: identifiers of properties.
     */
    IDProperty m_id_property_1,
               m_id_property_2,
               m_id_property_3;
};

/**
 * Unit tests of: PropertyManager::PropertyManager.
 */
TEST_F(PropertyManagerTest, PropertyManager)
{
    IPropertyManagerAccessorAutPtr accessor(new PropertyManagerAccessorMock);

    ASSERT_NO_THROW(PropertyManager manager(accessor));
}

/**
 * Unit tests of: PropertyManager::getPropertyBoolean.
 */
TEST_F(PropertyManagerTest, getPropertyBoolean)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordShrPtr property_record =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_1, DISCRIMINATOR_BOOLEAN, true, 0, "");

    EXPECT_CALL(*mock, getPropertyRecord(transaction, m_key_hash_1, m_id_property_1))
    .WillOnce(Return(property_record))
    .WillOnce(Return(property_record));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyBooleanShrPtr property = manager.getPropertyBoolean(transaction, m_key_hash_1, m_id_property_1));

    // Test commands.
    PropertyBooleanShrPtr property = manager.getPropertyBoolean(transaction, m_key_hash_1, m_id_property_1);

    // Test assertions.
    ASSERT_TRUE(m_id_property_1 == property->getIDProperty());
    ASSERT_EQ(true, property->getValue());
}

TEST_F(PropertyManagerTest, getPropertyInteger)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordShrPtr property_record =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_1, DISCRIMINATOR_INTEGER, false, 22, "");

    EXPECT_CALL(*mock, getPropertyRecord(transaction, m_key_hash_1, m_id_property_1))
    .WillOnce(Return(property_record))
    .WillOnce(Return(property_record));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyIntegerShrPtr property = manager.getPropertyInteger(transaction, m_key_hash_1, m_id_property_1));

    // Test commands.
    PropertyIntegerShrPtr property = manager.getPropertyInteger(transaction, m_key_hash_1, m_id_property_1);

    // Test assertions.
    ASSERT_TRUE(m_id_property_1 == property->getIDProperty());
    ASSERT_EQ(22, property->getValue());
}

TEST_F(PropertyManagerTest, getPropertyString)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordShrPtr property_record =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_1, DISCRIMINATOR_STRING, false, 0, "RTFM");

    EXPECT_CALL(*mock, getPropertyRecord(transaction, m_key_hash_1, m_id_property_1))
    .WillOnce(Return(property_record))
    .WillOnce(Return(property_record));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyStringShrPtr property = manager.getPropertyString(transaction, m_key_hash_1, m_id_property_1));

    // Test commands.
    PropertyStringShrPtr property = manager.getPropertyString(transaction, m_key_hash_1, m_id_property_1);

    // Test assertions.
    ASSERT_TRUE(m_id_property_1 == property->getIDProperty());
    ASSERT_STREQ("RTFM", property->getValue().c_str());
}

/**
 * Unit tests of: PropertyManager::getProperties.
 */
TEST_F(PropertyManagerTest, getProperties_ZeroProperties)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordMap map;

    EXPECT_CALL(*mock, getPropertyRecords(transaction, m_key_hash_1))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands.
    PropertySet properties = manager.getProperties(transaction, m_key_hash_1);

    // Test assertions.
    ASSERT_THROW(properties.getBooleanProperty(m_id_property_1), out_of_range);
    ASSERT_THROW(properties.getIntegerProperty(m_id_property_1), out_of_range);
    ASSERT_THROW(properties.getStringProperty(m_id_property_1), out_of_range);
}


TEST_F(PropertyManagerTest, getProperties_OneProperty)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordMap map;

    PropertyRecordShrPtr property_record =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_1, DISCRIMINATOR_BOOLEAN, true, 0, "");

    map.insert(PropertyRecordPair(m_id_property_1, property_record));

    EXPECT_CALL(*mock, getPropertyRecords(transaction, m_key_hash_1))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands.
    PropertySet properties = manager.getProperties(transaction, m_key_hash_1);

    // Test assertions.
    ASSERT_NO_THROW(properties.getBooleanProperty(m_id_property_1));
    ASSERT_THROW(properties.getIntegerProperty(m_id_property_1), bad_cast);
    ASSERT_THROW(properties.getStringProperty(m_id_property_1), bad_cast);

    PropertyBooleanShrPtr property = properties.getBooleanProperty(m_id_property_1);

    ASSERT_TRUE(m_id_property_1 == property->getIDProperty());
    ASSERT_EQ(true, property->getValue());
}

TEST_F(PropertyManagerTest, getProperties_ManyProperties)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: PropertyManagerAccessorMock.
    PropertyManagerAccessorMock * mock = new PropertyManagerAccessorMock;

    PropertyRecordMap map;

    PropertyRecordShrPtr property_record_boolean =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_1, DISCRIMINATOR_BOOLEAN, true, 0, "");
    PropertyRecordShrPtr property_record_integer =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_2, DISCRIMINATOR_INTEGER, false, 22, "");
    PropertyRecordShrPtr property_record_string =
        make_shared<PropertyRecord>(m_key_hash_1, m_id_property_3, DISCRIMINATOR_STRING, false, 0, "RTFM");

    map.insert(PropertyRecordPair(m_id_property_1, property_record_boolean));
    map.insert(PropertyRecordPair(m_id_property_2, property_record_integer));
    map.insert(PropertyRecordPair(m_id_property_3, property_record_string));

    EXPECT_CALL(*mock, getPropertyRecords(transaction, m_key_hash_1))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IPropertyManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    PropertyManager manager(accessor);

    // Test commands.
    PropertySet properties = manager.getProperties(transaction, m_key_hash_1);

    // Test assertions.
    ASSERT_NO_THROW(properties.getBooleanProperty(m_id_property_1));
    ASSERT_THROW(properties.getIntegerProperty(m_id_property_1), bad_cast);
    ASSERT_THROW(properties.getStringProperty(m_id_property_1), bad_cast);

    ASSERT_THROW(properties.getBooleanProperty(m_id_property_2), bad_cast);
    ASSERT_NO_THROW(properties.getIntegerProperty(m_id_property_2));
    ASSERT_THROW(properties.getStringProperty(m_id_property_2), bad_cast);

    ASSERT_THROW(properties.getBooleanProperty(m_id_property_3), bad_cast);
    ASSERT_THROW(properties.getIntegerProperty(m_id_property_3), bad_cast);
    ASSERT_NO_THROW(properties.getStringProperty(m_id_property_3));

    PropertyBooleanShrPtr property_boolean = properties.getBooleanProperty(m_id_property_1);
    PropertyIntegerShrPtr property_integer = properties.getIntegerProperty(m_id_property_2);
    PropertyStringShrPtr property_string = properties.getStringProperty(m_id_property_3);

    ASSERT_TRUE(m_id_property_1 == property_boolean->getIDProperty());
    ASSERT_EQ(true, property_boolean->getValue());

    ASSERT_TRUE(m_id_property_2 == property_integer->getIDProperty());
    ASSERT_EQ(22, property_integer->getValue());

    ASSERT_TRUE(m_id_property_3 == property_string->getIDProperty());
    ASSERT_STREQ("RTFM", property_string->getValue().c_str());
}