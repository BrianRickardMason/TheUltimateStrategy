// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <Game/GameServer/Building/Key.hpp>
#include <Game/GameServer/Building/Operators/DestroyBuilding/DestroyBuildingOperatorFactory.hpp>
#include <Game/GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp>
#include <Game/GameServer/Resource/Key.hpp>
#include <Game/GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp>
#include <Game/GameServerCT/ComponentTest.hpp>
#include <Server/Network/XmlRPCServer/Context.hpp>
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace boost;
using namespace std;

namespace R = GameServer::Resource;

/**
 * @brief A test class.
 */
class DestroyBuildingOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    DestroyBuildingOperatorTest()
        : m_context(new Context),
          m_epoch_name("Epoch"),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_world_name("World"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_settlement_name_4("Settlement5"),
          m_id_holder_11(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_12(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_21(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3),
          m_id_holder_4(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_4),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql(m_context)),
          m_building_persistence_facade(m_persistence_facade_abstract_factory->createBuildingPersistenceFacade()),
          m_epoch_persistence_facade(m_persistence_facade_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_persistence_facade_abstract_factory->createLandPersistenceFacade()),
          m_resource_persistence_facade(m_persistence_facade_abstract_factory->createResourcePersistenceFacade()),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_persistence_facade_abstract_factory->createWorldPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_persistence_facade_abstract_factory)),
          m_destroy_building_operator(
              DestroyBuildingOperatorFactory::createDestroyBuildingOperator(
                  m_context,
                  m_persistence_facade_abstract_factory
              )
          )
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persistence_facade->createUser(transaction, m_login_1, "Password");
            m_user_persistence_facade->createUser(transaction, m_login_2, "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name, m_land_name_2);

            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_2);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_2, m_settlement_name_3);

            transaction->commit();
        }
    }

    /**
     * @brief Asserts that database remains untouched.
     */
    void assertDatabaseUntouched()
    {
        vector<R::Volume> expected_volumes_1 = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000);
        vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ASSERT_TRUE(m_building_persistence_facade->getBuildings(transaction, m_id_holder_11).empty());
            ASSERT_TRUE(m_building_persistence_facade->getBuildings(transaction, m_id_holder_12).empty());
            ASSERT_TRUE(m_building_persistence_facade->getBuildings(transaction, m_id_holder_21).empty());

            ResourceWithVolumeMap
                resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
                resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
                resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

            compareResourceMap(resource_map_11, expected_volumes_1);
            compareResourceMap(resource_map_12, expected_volumes_2);
            compareResourceMap(resource_map_21, expected_volumes_1);
        }
    }

    /**
     * @brief Compares a map of resources with expected volumes.
     *
     * @param a_resource_map The map of resources to be compared.
     * @param a_volumes      A vector of expected volumes.
     *
     * TODO: Consider moving to helpers.
     */
    void compareResourceMap(
        ResourceWithVolumeMap const & a_resource_map,
        vector<R::Volume>     const & a_vector
    )
    {
        for (ResourceWithVolumeMap::const_iterator it = a_resource_map.begin(); it != a_resource_map.end(); ++it)
        {
            // TODO: Enable this assertion.
            // ASSERT_EQ(a_vector.at(it->second->getResource()->getKey() - 1), it->second->getVolume());
        }
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
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the names of the land.
     */
    string m_land_name_1,
           m_land_name_2;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3,
           m_settlement_name_4;

    /**
     * @brief Test constants identifiers of a holder.
     */
    IDHolder m_id_holder_11,
             m_id_holder_12,
             m_id_holder_21,
             m_id_holder_4;

    /**
     * @brief An abstract factory used in tests.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    //@{
    /**
     * @brief A persistence facade used in tests.
     */
    IBuildingPersistenceFacadeShrPtr m_building_persistence_facade;
    IEpochPersistenceFacadeShrPtr    m_epoch_persistence_facade;
    ILandPersistenceFacadeShrPtr     m_land_persistence_facade;
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    IUserPersistenceFacadeShrPtr     m_user_persistence_facade;
    IWorldPersistenceFacadeShrPtr    m_world_persistence_facade;
    //@}

    //@{
    /**
     * @brief An operator used in tests.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;
    IDestroyBuildingOperatorShrPtr  m_destroy_building_operator;
    //}@
};

/**
 * Component tests of: DestroyBuildingOperator::destroyBuilding.
 */
TEST_F(DestroyBuildingOperatorTest, destroyBuilding_TryingToDestroyZeroBuildings)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 0).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_MissingIDHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_4, KEY_REGULAR_FARM, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_ZeroResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 10000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 10000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 1000);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 10000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 10000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 1000);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_AllResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 9999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 9999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(1)(1)(1)(1)(1)(1);

        compareResourceMap(resource_map, expected);
    }
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_OneResource)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(1000)(10000)(10000)(1000)(1000)(1);

        compareResourceMap(resource_map, expected);
    }
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_OneBuilding)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 200);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 1).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
        ASSERT_EQ(199, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(990)(9990)(9990)(990)(990)(990);

        compareResourceMap(resource_map, expected);
    }
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_ManyBuildings)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 200);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 63).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
        ASSERT_EQ(137, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(370)(9370)(9370)(370)(370)(370);

        compareResourceMap(resource_map, expected);
    }
}

TEST_F(DestroyBuildingOperatorTest, buildBuilding_Success_MaxNumberOfBuildings_OnBuildings)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 50);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 50).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(500)(9500)(9500)(500)(500)(500);

        compareResourceMap(resource_map, expected);
    }
}

TEST_F(DestroyBuildingOperatorTest, buildBuilding_Success_MaxNumberOfBuildings_OnResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 200);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
                  m_destroy_building_operator->destroyBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM, 100).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM) == NULL);
        ASSERT_EQ(100, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_REGULAR_FARM)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        vector<R::Volume> expected = assign::list_of(0)(9000)(9000)(0)(0)(0);

        compareResourceMap(resource_map, expected);
    }
}
