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

#include "../../GameServer/Building/Building.hpp"
#include "../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Human/Human.hpp"
#include "../ComponentTest.hpp"
#include "../Helpers/Constants.hpp"
#include <algorithm>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace boost;
using namespace std;

/**
 * @brief A test class.
 */
class PropertyManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    PropertyManagerTest()
        : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_property_manager(m_manager_abstract_factory->createPropertyManager())
    {
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_DISMISSABLE property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_DISMISSABLE(
        PropertyBooleanShrPtr         a_property,
        Human                 const & a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_DISMISSABLE == a_property->getIDProperty());

        KeyVec::const_iterator found = find(HUMAN_IS_NOT_DISMISSABLE.begin(), HUMAN_IS_NOT_DISMISSABLE.end(), a_human.getKey());

        ASSERT_EQ(found == HUMAN_IS_NOT_DISMISSABLE.end(), a_property->getValue());
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_ENGAGEABLE property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_ENGAGEABLE(
        PropertyBooleanShrPtr         a_property,
        Human                 const & a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == a_property->getIDProperty());

        KeyVec::const_iterator found = find(HUMAN_IS_NOT_ENGAGEABLE.begin(), HUMAN_IS_NOT_ENGAGEABLE.end(), a_human.getKey());

        ASSERT_EQ(found == HUMAN_IS_NOT_ENGAGEABLE.end(), a_property->getValue());
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_PRODUCTION property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_PRODUCTION(
        PropertyIntegerShrPtr         a_property,
        Human                 const & a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_PRODUCTION == a_property->getIDProperty());

        KeyVec::const_iterator found = find(HUMAN_DOES_NOT_PRODUCE.begin(), HUMAN_DOES_NOT_PRODUCE.end(), a_human.getKey());

        if (found == HUMAN_DOES_NOT_PRODUCE.end())
        {
            ASSERT_EQ(10, a_property->getValue());
        }
        else
        {
            ASSERT_EQ(0, a_property->getValue());
        }
    }

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A property manager.
     */
    IPropertyManagerShrPtr m_property_manager;
};

/**
 * Component tests of: PropertyManager::getPropertyBoolean.
 */
TEST_F(PropertyManagerTest, getProperty_ID_PROPERTY_HUMAN_DISMISSABLE)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyBooleanShrPtr property = m_property_manager->getPropertyBoolean(transaction, it->getKey().toHash(), ID_PROPERTY_HUMAN_DISMISSABLE);

        check_ID_PROPERTY_HUMAN_DISMISSABLE(property, *it);
    }
}

TEST_F(PropertyManagerTest, getProperty_ID_PROPERTY_HUMAN_ENGAGEABLE)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyBooleanShrPtr property = m_property_manager->getPropertyBoolean(transaction, it->getKey().toHash(), ID_PROPERTY_HUMAN_ENGAGEABLE);

        check_ID_PROPERTY_HUMAN_ENGAGEABLE(property, *it);
    }
}

/**
 * Component tests of: PropertyManager::getPropertyInteger.
 */
TEST_F(PropertyManagerTest, getProperty_ID_PROPERTY_BUILDING_CAPACITY)
{
    for (BuildingVec::const_iterator it = BUILDING_VEC.begin(); it != BUILDING_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyIntegerShrPtr property = m_property_manager->getPropertyInteger(transaction, it->getKey().toHash(), ID_PROPERTY_BUILDING_CAPACITY);

        ASSERT_EQ(10, property->getValue());
    }
}

TEST_F(PropertyManagerTest, getProperty_ID_PROPERTY_HUMAN_PRODUCTION)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyIntegerShrPtr property = m_property_manager->getPropertyInteger(transaction, it->getKey().toHash(), ID_PROPERTY_HUMAN_PRODUCTION);

        check_ID_PROPERTY_HUMAN_PRODUCTION(property, *it);
    }
}

/**
 * Component tests of: PropertyManager::getProperties.
 */
TEST_F(PropertyManagerTest, getProperties_Buildings)
{
    for (BuildingVec::const_iterator it = BUILDING_VEC.begin(); it != BUILDING_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertySet properties = m_property_manager->getProperties(transaction, it->getKey().toHash());

        ASSERT_EQ(10, properties.getIntegerProperty(ID_PROPERTY_BUILDING_CAPACITY)->getValue());
    }
}

TEST_F(PropertyManagerTest, getProperties_Humans)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertySet properties = m_property_manager->getProperties(transaction, it->getKey().toHash());

        check_ID_PROPERTY_HUMAN_DISMISSABLE(properties.getBooleanProperty(ID_PROPERTY_HUMAN_DISMISSABLE), *it);
        check_ID_PROPERTY_HUMAN_ENGAGEABLE(properties.getBooleanProperty(ID_PROPERTY_HUMAN_ENGAGEABLE), *it);
        check_ID_PROPERTY_HUMAN_PRODUCTION(properties.getIntegerProperty(ID_PROPERTY_HUMAN_PRODUCTION), *it);
    }
}
