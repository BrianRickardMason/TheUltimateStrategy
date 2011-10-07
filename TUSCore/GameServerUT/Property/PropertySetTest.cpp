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

#include "../../GameServer/Property/PropertySet.hpp"
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>
#include <stdexcept>

using namespace boost;
using namespace GameServer::Property;

/**
 * @brief A test class.
 */
class PropertySetTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    PropertySetTest()
        : m_id_property_1(1),
          m_id_property_2(2),
          m_id_property_3(3),
          m_property_boolean(make_shared<PropertyBoolean>(m_id_property_1, true)),
          m_property_integer(make_shared<PropertyInteger>(m_id_property_2, 22)),
          m_property_string (make_shared<PropertyString>(m_id_property_3, "dummy"))
    {
    }

    /**
     * @brief Gets a property set for testing.
     *
     * @return The property set to be tested.
     */
    PropertySet getPropertySet()
    {
        PropertyMap map;

        map.insert(PropertyPair(m_id_property_1, m_property_boolean));
        map.insert(PropertyPair(m_id_property_2, m_property_integer));
        map.insert(PropertyPair(m_id_property_3, m_property_string));

        PropertySet property_set(map);

        return property_set;
    }

    /**
     * @brief Test constants: identifiers of property.
     */
    IDProperty m_id_property_1,
               m_id_property_2,
               m_id_property_3;

    /**
     * @brief Test constants: a boolean property.
     */
    PropertyBooleanShrPtr m_property_boolean;

    /**
     * @brief Test constants: an integer property.
     */
    PropertyIntegerShrPtr m_property_integer;

    /**
     * @brief Test constants: a string property.
     */
    PropertyStringShrPtr m_property_string;
};

/**
 * Unit tests of: PropertySet::PropertySet.
 */
TEST_F(PropertySetTest, PropertySet_ByValue)
{
    // Preconditions.
    PropertyMap map;

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertySet property_set(map));
}

TEST_F(PropertySetTest, PropertySet_ByPointer)
{
    // Preconditions.
    PropertyMap * map = new PropertyMap;

    // Test commands and assertions.
    ASSERT_NO_THROW(PropertySet property_set(*map));

    // Postconditions.
    delete map;
}

/**
 * Unit tests of: PropertySet::getBooleanProperty.
 */
TEST_F(PropertySetTest, getBooleanProperty)
{
    // Preconditions.
    PropertySet property_set = getPropertySet();

    // Test commands and assertions.
    ASSERT_NO_THROW(property_set.getBooleanProperty(m_id_property_1));
    ASSERT_THROW(property_set.getBooleanProperty(m_id_property_2), std::bad_cast);
    ASSERT_THROW(property_set.getBooleanProperty(m_id_property_3), std::bad_cast);

    // Test commands.
    PropertyBooleanShrPtr property_boolean_shr_ptr = property_set.getBooleanProperty(m_id_property_1);

    ASSERT_TRUE(m_id_property_1 == property_boolean_shr_ptr->getIDProperty());
    ASSERT_EQ(true, property_boolean_shr_ptr->getValue());
}

/**
 * Unit tests of: PropertySet::getIntegerProperty.
 */
TEST_F(PropertySetTest, getIntegerProperty)
{
    // Preconditions.
    PropertySet property_set = getPropertySet();

    // Test commands and assertions.
    ASSERT_NO_THROW(property_set.getIntegerProperty(m_id_property_2));
    ASSERT_THROW(property_set.getIntegerProperty(m_id_property_1), std::bad_cast);
    ASSERT_THROW(property_set.getIntegerProperty(m_id_property_3), std::bad_cast);

    // Test commands.
    PropertyIntegerShrPtr property_integer_shr_ptr = property_set.getIntegerProperty(m_id_property_2);

    ASSERT_TRUE(m_id_property_2 == property_integer_shr_ptr->getIDProperty());
    ASSERT_EQ(22, property_integer_shr_ptr->getValue());
}

/**
 * Unit tests of: PropertySet::getStringProperty.
 */
TEST_F(PropertySetTest, getStringProperty)
{
    // Preconditions.
    PropertySet property_set = getPropertySet();

    // Test commands and assertions.
    ASSERT_NO_THROW(property_set.getStringProperty(m_id_property_3));
    ASSERT_THROW(property_set.getStringProperty(m_id_property_1), std::bad_cast);
    ASSERT_THROW(property_set.getStringProperty(m_id_property_2), std::bad_cast);

    // Test commands.
    PropertyStringShrPtr property_string_shr_ptr = property_set.getStringProperty(m_id_property_3);

    ASSERT_TRUE(m_id_property_3 == property_string_shr_ptr->getIDProperty());
    ASSERT_STREQ("dummy", property_string_shr_ptr->getValue().c_str());
}
