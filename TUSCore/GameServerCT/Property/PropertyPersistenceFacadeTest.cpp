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
#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Human/Human.hpp"
#include "../ComponentTest.hpp"
#include "../Helpers/Constants.hpp"
#include <GameServer/Configuration/Configurator/Building/ConfiguratorBuilding.hpp>
#include <GameServer/Configuration/Configurator/Human/ConfiguratorHuman.hpp>
#include <algorithm>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace boost;
using namespace std;

/**
 * @brief A test class.
 */
class PropertyPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    PropertyPersistenceFacadeTest()
        : m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
          m_property_persistence_facade(m_persistence_facade_abstract_factory->createPropertyPersistenceFacade())
    {
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_DISMISSABLE property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_DISMISSABLE(
        PropertyBooleanShrPtr       a_property,
        IHumanShrPtr          const a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_DISMISSABLE == a_property->getIDProperty());

        KeyVec::const_iterator found =
            find(HUMAN_IS_NOT_DISMISSABLE.begin(), HUMAN_IS_NOT_DISMISSABLE.end(), a_human->getKey());

        ASSERT_EQ(found == HUMAN_IS_NOT_DISMISSABLE.end(), a_property->getValue());
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_ENGAGEABLE property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_ENGAGEABLE(
        PropertyBooleanShrPtr       a_property,
        IHumanShrPtr          const a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_ENGAGEABLE == a_property->getIDProperty());

        KeyVec::const_iterator found =
            find(HUMAN_IS_NOT_ENGAGEABLE.begin(), HUMAN_IS_NOT_ENGAGEABLE.end(), a_human->getKey());

        ASSERT_EQ(found == HUMAN_IS_NOT_ENGAGEABLE.end(), a_property->getValue());
    }

    /**
     * @brief Checks the ID_PROPERTY_HUMAN_PRODUCTION property with expected results.
     *
     * @param a_property A property to be tested.
     * @param a_human    A human.
     */
    void check_ID_PROPERTY_HUMAN_PRODUCTION(
        PropertyIntegerShrPtr       a_property,
        IHumanShrPtr          const a_human
    )
    {
        ASSERT_TRUE(ID_PROPERTY_HUMAN_PRODUCTION == a_property->getIDProperty());

        KeyVec::const_iterator found =
            find(HUMAN_DOES_NOT_PRODUCE.begin(), HUMAN_DOES_NOT_PRODUCE.end(), a_human->getKey());

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
     * @brief An abstract factory used in tests.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief A persistence facade used in tests.
     */
    IPropertyPersistenceFacadeShrPtr m_property_persistence_facade;
};

/**
 * Component tests of: PropertyPersistenceFacade::getPropertyBoolean.
 */
TEST_F(PropertyPersistenceFacadeTest, getProperty_ID_PROPERTY_HUMAN_DISMISSABLE)
{
    IHumanMap const & humans = CONFIGURATOR_HUMAN.getHumans();

    for (IHumanMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyBooleanShrPtr property =
            m_property_persistence_facade->getPropertyBoolean(transaction, it->first, ID_PROPERTY_HUMAN_DISMISSABLE);

        check_ID_PROPERTY_HUMAN_DISMISSABLE(property, it->second);
    }
}

TEST_F(PropertyPersistenceFacadeTest, getProperty_ID_PROPERTY_HUMAN_ENGAGEABLE)
{
    IHumanMap const & humans = CONFIGURATOR_HUMAN.getHumans();

    for (IHumanMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyBooleanShrPtr property =
                m_property_persistence_facade->getPropertyBoolean(transaction, it->first, ID_PROPERTY_HUMAN_ENGAGEABLE);

        check_ID_PROPERTY_HUMAN_ENGAGEABLE(property, it->second);
    }
}

/**
 * Component tests of: PropertyPersistenceFacade::getPropertyInteger.
 */
TEST_F(PropertyPersistenceFacadeTest, getProperty_ID_PROPERTY_BUILDING_CAPACITY)
{
    IBuildingMap const & buildings = CONFIGURATOR_BUILDING.getBuildings();

    for (IBuildingMap::const_iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyIntegerShrPtr property =
                m_property_persistence_facade->getPropertyInteger(transaction, it->first, ID_PROPERTY_BUILDING_CAPACITY);

        ASSERT_EQ(10, property->getValue());
    }
}

TEST_F(PropertyPersistenceFacadeTest, getProperty_ID_PROPERTY_HUMAN_PRODUCTION)
{
    IHumanMap const & humans = CONFIGURATOR_HUMAN.getHumans();

    for (IHumanMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertyIntegerShrPtr property =
                m_property_persistence_facade->getPropertyInteger(transaction, it->first, ID_PROPERTY_HUMAN_PRODUCTION);

        check_ID_PROPERTY_HUMAN_PRODUCTION(property, it->second);
    }
}

TEST_F(PropertyPersistenceFacadeTest, getProperties_Buildings)
{
    IBuildingMap const & buildings = CONFIGURATOR_BUILDING.getBuildings();

    for (IBuildingMap::const_iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertySet properties = m_property_persistence_facade->getProperties(transaction, it->first);

        ASSERT_EQ(10, properties.getIntegerProperty(ID_PROPERTY_BUILDING_CAPACITY)->getValue());
    }
}

TEST_F(PropertyPersistenceFacadeTest, getProperties_Humans)
{
    IHumanMap const & humans = CONFIGURATOR_HUMAN.getHumans();

    for (IHumanMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        PropertySet properties = m_property_persistence_facade->getProperties(transaction, it->first);

        check_ID_PROPERTY_HUMAN_DISMISSABLE(properties.getBooleanProperty(ID_PROPERTY_HUMAN_DISMISSABLE), it->second);
        check_ID_PROPERTY_HUMAN_ENGAGEABLE(properties.getBooleanProperty(ID_PROPERTY_HUMAN_ENGAGEABLE), it->second);
        check_ID_PROPERTY_HUMAN_PRODUCTION(properties.getIntegerProperty(ID_PROPERTY_HUMAN_PRODUCTION), it->second);
    }
}
