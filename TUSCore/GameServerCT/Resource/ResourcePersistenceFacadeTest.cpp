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

#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../ComponentTest.hpp"
#include <GameServer/Resource/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <boost/make_shared.hpp>

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace boost;
using namespace std;

/**
 * @brief A test class.
 *
 * TODO: Refactoring needed.
 */
class ResourcePersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    ResourcePersistenceFacadeTest()
        : m_context(new Context),
          m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql(m_context)),
          m_epoch_persistence_facade(m_persistence_facade_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_persistence_facade_abstract_factory->createLandPersistenceFacade()),
          m_resource_persistence_facade(m_persistence_facade_abstract_factory->createResourcePersistenceFacade()),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_persistence_facade_abstract_factory->createWorldPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_persistence_facade_abstract_factory)),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_3(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persistence_facade->createUser(transaction, "Login", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name);

            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_2);

            // Remove resources which have been added.
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 10000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 10000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_FOOD, 10000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_GOLD, 10000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_IRON, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_MANA, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_ROCK, 1000);
            m_resource_persistence_facade->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_WOOD, 1000);

            transaction->commit();
        }
    }

    /**
     * @brief Gets a prepared map of resources.
     *
     * @return The prepared map of resources.
     */
    ResourceWithVolumeMap getResourceMap()
    {
        ResourceWithVolumeMap map;

        map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_COAL, 100)));
        map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
        map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 300)));
        map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_IRON, 400)));
        map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_MANA, 500)));
        map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_ROCK, 600)));
        map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_WOOD, 700)));

        return map;
    }

    /**
     * @brief Compares the resource with expected values.
     *
     * @param a_resource The resource to be compared.
     * @param a_key      An expected key of the resource.
     * @param a_volume   An expected volume of the resource.
     */
    void compareResource(
        ResourceWithVolumeShrPtr         a_resource,
        string                   const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_resource->getResource()->getKey());
        ASSERT_EQ(a_volume, a_resource->getVolume());
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief Test constants: the name of the epoch.
     */
    string m_epoch_name;

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3;

    /**
     * @brief An abstract factory used in tests.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    //@{
    /**
     * @brief A persistence facade used in tests.
     */
    IEpochPersistenceFacadeShrPtr    m_epoch_persistence_facade;
    ILandPersistenceFacadeShrPtr     m_land_persistence_facade;
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    IUserPersistenceFacadeShrPtr     m_user_persistence_facade;
    IWorldPersistenceFacadeShrPtr    m_world_persistence_facade;
    //}@

    /**
     * @brief An operator used in tests.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;

    /**
     * @brief Exemplary id holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2,
             m_id_holder_3;
};

/**
 * Component tests of: ResourcePersistenceFacade::addResource.
 */
TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 22);
    }
}

TEST_F(ResourcePersistenceFacadeTest, addResource_ResourceIsPresent_DifferentResource)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(2, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourcesArePresent_SubtractAllOfOneResourceAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_TryToSubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 12));
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResource_ResourceIsNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourcesArePresent_SubtractAllOfOneResourceAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 12));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractZero)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 0));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourceSafely_ResourceIsNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_SubtractEmptySet)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 100);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map;

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(7, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_SubtractAllOfManyResourcesAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(7, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_TryToSubtractTooMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 299);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_FALSE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(7, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 299);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesArePresent_SubtractRest_OneTransaction)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));
        ASSERT_TRUE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResources_ResourcesAreNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_FALSE(m_resource_persistence_facade->subtractResources(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractEmptySet)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 100);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map;

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractAllOfManyResourcesAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractTooMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 299);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(6, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesArePresent_SubtractRest_OneTransaction)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));
        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, subtractResourcesSafely_ResourcesAreNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = getResourceMap();

        ASSERT_NO_THROW(m_resource_persistence_facade->subtractResourcesSafely(transaction, m_id_holder_1, resource_map));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetPresentResource_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL);

        ASSERT_FALSE(resource == NULL);
        compareResource(resource, KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetPresentResource_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetPresentResource_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_3, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetNonPresentResource_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetNonPresentResource_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_2, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResource_ResourceIsPresent_GetNonPresentResource_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_persistence_facade->getResource(transaction, m_id_holder_3, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesAreNotPresent_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesAreNotPresent_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourceIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourceIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_2);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourceIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_3);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(2, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_2);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_3);

        ASSERT_TRUE(resource_map.empty());
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_1);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(2, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_2);

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(1, resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 33);
    }
}

TEST_F(ResourcePersistenceFacadeTest, getResources_ResourcesArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_3);

        ASSERT_TRUE(resource_map.empty());
    }
}
