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
#include "../ComponentTest.hpp"

using namespace GameServer::Cost;
using namespace GameServer::Common;
using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

/**
 * @brief A test class.
 */
class CostPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    CostPersistenceFacadeTest()
        : m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
          m_cost_persistence_facade(m_persistence_facade_abstract_factory->createCostPersistenceFacade())
    {
    }

    /**
     * @brief The abstract factory of persistence facades.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief A persistence facade used in tests.
     */
    ICostPersistenceFacadeShrPtr m_cost_persistence_facade;
};

/**
 * Component tests of: CostPersistenceFacade::getCosts.
 */
TEST_F(CostPersistenceFacadeTest, getCosts_ID_COST_TYPE_BUILDING_BUILD)
{
    for (BuildingVec::const_iterator it = BUILDING_VEC.begin(); it != BUILDING_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        // Test commands.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(transaction, it->getKey().toHash(), ID_COST_TYPE_BUILDING_BUILD);

        // Test assertions.
        ResourceWithVolumeMap resource_map = cost.getMap();
        // TODO: Enable this assertion.
        // ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

        unsigned short int i(0);
        for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
        {
            ASSERT_EQ(10, it->second->getVolume());
        }
    }
}

TEST_F(CostPersistenceFacadeTest, getCosts_ID_COST_TYPE_BUILDING_DESTROY)
{
    for (BuildingVec::const_iterator it = BUILDING_VEC.begin(); it != BUILDING_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        // Test commands.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(transaction, it->getKey().toHash(), ID_COST_TYPE_BUILDING_DESTROY);

        // Test assertions.
        ResourceWithVolumeMap resource_map = cost.getMap();
        // TODO: Enable this assertion.
        // ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

        unsigned short int i(0);
        for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
        {
            ASSERT_EQ(10, it->second->getVolume());
        }
    }
}

TEST_F(CostPersistenceFacadeTest, getCosts_ID_COST_TYPE_HUMAN_DISMISS)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        // Test commands.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(transaction, it->getKey().toHash(), ID_COST_TYPE_HUMAN_DISMISS);

        // Test assertions.
        ResourceWithVolumeMap resource_map = cost.getMap();
        // TODO: Enable this assertion.
        // ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

        unsigned short int i(0);
        for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
        {
            ASSERT_EQ(10, it->second->getVolume());
        }
    }
}

TEST_F(CostPersistenceFacadeTest, getCosts_ID_COST_TYPE_HUMAN_ENGAGE)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        // Test commands.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(transaction, it->getKey().toHash(), ID_COST_TYPE_HUMAN_ENGAGE);

        // Test assertions.
        ResourceWithVolumeMap resource_map = cost.getMap();
        // TODO: Enable this assertion.
        // ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

        unsigned short int i(0);
        for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
        {
            ASSERT_EQ(10, it->second->getVolume());
        }
    }
}

TEST_F(CostPersistenceFacadeTest, getCosts_ID_COST_TYPE_HUMAN_LIVING)
{
    for (HumanVec::const_iterator it = HUMAN_VEC.begin(); it != HUMAN_VEC.end(); ++it)
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        // Test commands.
        ResourceSet cost =
            m_cost_persistence_facade->getCost(transaction, it->getKey().toHash(), ID_COST_TYPE_HUMAN_LIVING);

        // Test assertions.
        ResourceWithVolumeMap resource_map = cost.getMap();
        // TODO: Enable this assertion.
        // ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

        unsigned short int i(0);
        for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
        {
            ASSERT_EQ(1, it->second->getVolume());
        }
    }
}
