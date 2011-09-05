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

#include "../../GameServer/Property/Property.hpp"
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace boost;
using namespace GameServer::Property;

/**
 * @brief A test class.
 */
class PropertyTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyTest()
        : m_property(ID_PROPERTY_HUMAN_ENGAGEABLE)
    {
    }

    /**
     * @brief A property to be tested.
     */
    Property m_property;
};

/**
 * Unit tests of: Property::Property.
 */
TEST_F(PropertyTest, Property)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(Property property(ID_PROPERTY_HUMAN_ENGAGEABLE));

    // Test commands.
    Property property(ID_PROPERTY_HUMAN_ENGAGEABLE);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
}

/**
 * Unit tests of: Property::getIDProperty.
 */
TEST_F(PropertyTest, getIDProperty)
{
    // Test commands and assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == m_property.getIDProperty());
}

/**
 * @brief A test class.
 */
class PropertyBooleanTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyBooleanTest()
        : m_property(ID_PROPERTY_HUMAN_ENGAGEABLE, true)
    {
    }

    /**
     * @brief A property to be tested.
     */
    PropertyBoolean m_property;
};

/**
 * Unit tests of: PropertyBoolean::PropertyBoolean based on record.
 */
TEST_F(PropertyBooleanTest, PropertyBoolean_BasedOnRecord)
{
    // Preconditions.
    PropertyRecordShrPtr property_record_shr_ptr =
        make_shared<PropertyRecord>(1, ID_PROPERTY_HUMAN_ENGAGEABLE, DISCRIMINATOR_BOOLEAN, true, 0, "");

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyBoolean property(property_record_shr_ptr));

    // Test commands.
    PropertyBoolean property(property_record_shr_ptr);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_EQ(true, property.getValue());
}

/**
 * Unit tests of: PropertyBoolean::PropertyBoolean based on arguments.
 */
TEST_F(PropertyBooleanTest, PropertyBoolean_BasedOnArguments)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyBoolean property(ID_PROPERTY_HUMAN_ENGAGEABLE, true));

    // Test commands.
    PropertyBoolean property(ID_PROPERTY_HUMAN_ENGAGEABLE, true);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_EQ(true, property.getValue());
}

/**
 * Unit tests of: PropertyBoolean::getIDProperty.
 */
TEST_F(PropertyBooleanTest, getIDProperty)
{
    // Test commands and assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == m_property.getIDProperty());
}

/**
 * Unit tests of: PropertyBoolean::getValue.
 */
TEST_F(PropertyBooleanTest, getValue)
{
    // Test commands and assertions.
    ASSERT_EQ(true, m_property.getValue());
}

/**
 * @brief A test class.
 */
class PropertyIntegerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyIntegerTest()
        : m_property(ID_PROPERTY_HUMAN_ENGAGEABLE, 22)
    {
    }

    /**
     * @brief A property to be tested.
     */
    PropertyInteger m_property;
};

/**
 * Unit tests of: PropertyInteger::PropertyInteger based on record.
 */
TEST_F(PropertyIntegerTest, PropertyInteger_BasedOnRecord)
{
    // Preconditions.
    PropertyRecordShrPtr property_record_shr_ptr =
        make_shared<PropertyRecord>(1, ID_PROPERTY_HUMAN_ENGAGEABLE, DISCRIMINATOR_INTEGER, false, 22, "");

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyInteger property(property_record_shr_ptr));

    // Test commands.
    PropertyInteger property(property_record_shr_ptr);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_EQ(22, property.getValue());
}

/**
 * Unit tests of: PropertyInteger::PropertyInteger based on arguments.
 */
TEST_F(PropertyIntegerTest, PropertyInteger_BasedOnArguments)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyInteger property(ID_PROPERTY_HUMAN_ENGAGEABLE, 22));

    // Test commands.
    PropertyInteger property(ID_PROPERTY_HUMAN_ENGAGEABLE, 22);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_EQ(22, property.getValue());
}

/**
 * Unit tests of: PropertyInteger::getIDProperty.
 */
TEST_F(PropertyIntegerTest, getIDProperty)
{
    // Test commands and assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == m_property.getIDProperty());
}

/**
 * Unit tests of: PropertyInteger::getValue.
 */
TEST_F(PropertyIntegerTest, getValue)
{
    // Test commands and assertions.
    ASSERT_EQ(22, m_property.getValue());
}

/**
 * @brief A test class.
 */
class PropertyStringTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertyStringTest()
        : m_property(ID_PROPERTY_HUMAN_ENGAGEABLE, "AN.US")
    {
    }

    /**
     * @brief A property to be tested.
     */
    PropertyString m_property;
};

/**
 * Unit tests of: PropertyString::PropertyString based on record.
 */
TEST_F(PropertyStringTest, PropertyString_BasedOnRecord)
{
    // Preconditions.
    PropertyRecordShrPtr property_record_shr_ptr =
        make_shared<PropertyRecord>(1, ID_PROPERTY_HUMAN_ENGAGEABLE, DISCRIMINATOR_STRING, false, 0, "AN.US");

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyString property(property_record_shr_ptr));

    // Test commands.
    PropertyString property(property_record_shr_ptr);

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_STREQ("AN.US", property.getValue().c_str());
}

/**
 * Unit tests of: PropertyString::PropertyString based on arguments.
 */
TEST_F(PropertyStringTest, PropertyString_BasedOnArguments)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(PropertyString property(ID_PROPERTY_HUMAN_ENGAGEABLE, "AN.US"));

    // Test commands.
    PropertyString property(ID_PROPERTY_HUMAN_ENGAGEABLE, "AN.US");

    // Test assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == property.getIDProperty());
    ASSERT_STREQ("AN.US", property.getValue().c_str());
}

/**
 * Unit tests of: PropertyString::getIDProperty.
 */
TEST_F(PropertyStringTest, getIDProperty)
{
    // Test commands and assertions.
    ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == m_property.getIDProperty());
}

/**
 * Unit tests of: PropertyString::getValue.
 */
TEST_F(PropertyStringTest, getValue)
{
    // Test commands and assertions.
    ASSERT_STREQ("AN.US", m_property.getValue().c_str());
}
