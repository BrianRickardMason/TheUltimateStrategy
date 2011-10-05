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

#include "../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../ComponentTest.hpp"
#include <boost/make_shared.hpp>

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
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
class ResourceManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    ResourceManagerTest()
        : m_id_epoch_1(1),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_resource_manager(m_manager_abstract_factory->createResourceManager()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory)),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, 1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, 2),
          m_id_holder_3(ID_HOLDER_CLASS_SETTLEMENT, 3)
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login", "Password");

            m_world_manager->createWorld(transaction, m_world_name);

            m_epoch_manager->createEpoch(transaction, m_world_name);

            m_land_manager->createLand(transaction, m_login, m_world_name, m_id_epoch_1, m_land_name);

            m_create_settlement_operator->createSettlement(transaction, m_land_name, "Settlement1");
            m_create_settlement_operator->createSettlement(transaction, m_land_name, "Settlement2");

            // Remove resources which have been added.
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 10000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 10000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_FOOD, 10000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_GOLD, 10000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_IRON, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_MANA, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_ROCK, 1000);
            m_resource_manager->subtractResource(transaction, m_id_holder_2, KEY_RESOURCE_WOOD, 1000);

            transaction->commit();
        }
    }

    /**
     * @brief Gets a prepared resource set.
     *
     * @return The prepared resource set.
     */
    ResourceSet getResourceSet()
    {
        ResourceWithVolumeMap map;

        map.insert(make_pair(ID_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
        map.insert(make_pair(ID_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
        map.insert(make_pair(ID_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
        map.insert(make_pair(ID_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
        map.insert(make_pair(ID_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
        map.insert(make_pair(ID_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
        map.insert(make_pair(ID_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

        ResourceSet resource_set(map);

        return resource_set;
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
        Key                      const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_resource->getKey());
        ASSERT_EQ(a_volume, a_resource->getVolume());
    }

    /**
     * @brief Test constants: identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1;

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
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A user manager.
     */
    IUserManagerShrPtr m_user_manager;

    /**
     * @brief A world manager.
     */
    IWorldManagerShrPtr m_world_manager;

    /**
     * @brief The epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief A land manager.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief A resource manager.
     */
    IResourceManagerShrPtr m_resource_manager;

    /**
     * @brief CreateSettlementOperator.
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
 * Component tests of: ResourceManager::addResource.
 */
TEST_F(ResourceManagerTest, addResource_ResourceIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, addResource_ResourceIsPresent)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 22);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, addResource_ResourceIsPresent_DifferentResource)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

/**
 * Component tests of: ResourceManager::subtractResource.
 */
TEST_F(ResourceManagerTest, subtractResource_ResourcesArePresent_SubtractAllOfOneResourceAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResource_ResourceIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResource_ResourceIsPresent_TryToSubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 12));
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResource_ResourceIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResource_ResourceIsNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_resource_manager->subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));
    }
}

/**
 * Component tests of: ResourceManager::subtractResourceSafely.
 */
TEST_F(ResourceManagerTest, subtractResourceSafely_ResourcesArePresent_SubtractAllOfOneResourceAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSafely_ResourceIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSafely_ResourceIsPresent_SubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 12));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSafely_ResourceIsPresent_SubtractZero)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 0));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSafely_ResourceIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSafely_ResourceIsNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSafely(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11));

        transaction->commit();
    }
}

/**
 * Component tests of: ResourceManager::subtractResourceSet.
 */
TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_SubtractEmptySet)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 100);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeMap resource_map;
        ResourceSet resource_set(resource_map);

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_SubtractAllOfManyResourcesAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_TryToSubtractTooMuch)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 299);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_FALSE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 299);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesArePresent_SubtractRest_OneTransaction)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));
        ASSERT_TRUE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSet_ResourcesAreNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_FALSE(m_resource_manager->subtractResourceSet(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

/**
 * Component tests of: ResourceManager::subtractResourceSetSafely.
 */
TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractEmptySet)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 100);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeMap resource_map;
        ResourceSet resource_set(resource_map);

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractAllOfManyResourcesAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 300);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 500);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 700);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractTooMuch)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 299);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesArePresent_SubtractRest_OneTransaction)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 400);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_GOLD, 600);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_IRON, 800);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_MANA, 1000);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_ROCK, 1200);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_WOOD, 1400);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));
        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, subtractResourceSetSafely_ResourcesAreNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = getResourceSet();

        ASSERT_NO_THROW(m_resource_manager->subtractResourceSetSafely(transaction, m_id_holder_1, resource_set));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

/**
 * Component tests of: ResourceManager::getResource.
 */
TEST_F(ResourceManagerTest, getResource_ResourceIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetPresentResource_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL);

        ASSERT_FALSE(resource == NULL);
        compareResource(resource, KEY_RESOURCE_COAL, 11);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetPresentResource_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetPresentResource_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_3, KEY_RESOURCE_COAL);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetNonPresentResource_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetNonPresentResource_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_2, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

TEST_F(ResourceManagerTest, getResource_ResourceIsPresent_GetNonPresentResource_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceWithVolumeShrPtr resource = m_resource_manager->getResource(transaction, m_id_holder_3, KEY_RESOURCE_FOOD);

        ASSERT_TRUE(resource == NULL);
    }
}

/**
 * Component tests of: ResourceManager::getResources.
 */
TEST_F(ResourceManagerTest, getResources_ResourcesAreNotPresent_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesAreNotPresent_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_3);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourceIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourceIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_2);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourceIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_3);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_2);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_3);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_manager->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_1);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 11);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 22);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_manager->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_2);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 33);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}

TEST_F(ResourceManagerTest, getResources_ResourcesArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 11);
        m_resource_manager->addResource(transaction, m_id_holder_1, KEY_RESOURCE_FOOD, 22);
        m_resource_manager->addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ResourceSet resource_set = m_resource_manager->getResources(transaction, m_id_holder_3);

        ResourceWithVolumeMap resource_map = resource_set.getMap();

        ASSERT_FALSE(resource_map.empty());

        ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

        compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
        compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
        compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
        compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
        compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
        compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
        compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
    }
}
