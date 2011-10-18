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

#include "../../../GameServer/Building/Operators/BuildBuilding/BuildBuildingOperatorFactory.hpp"
#include "../../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../../ComponentTest.hpp"
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Cost;
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
 */
class BuildBuildingOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    BuildBuildingOperatorTest()
        : m_epoch_name("Epoch"),
          m_login("Login"),
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
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_building_persistence_facade(m_manager_abstract_factory->createBuildingPersistenceFacade()),
          m_cost_manager(m_manager_abstract_factory->createCostManager()),
          m_epoch_persistence_facade(m_manager_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_manager_abstract_factory->createLandPersistenceFacade()),
          m_resource_persistence_facade(m_manager_abstract_factory->createResourcePersistenceFacade()),
          m_user_persitence_facade(m_manager_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_manager_abstract_factory->createWorldPersistenceFacade()),
          m_build_building_operator(BuildBuildingOperatorFactory::createBuildBuildingOperator(m_manager_abstract_factory)),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory))
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persitence_facade->createUser(transaction, "Login", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_2);

            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_2);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_2, m_settlement_name_3);

            transaction->commit();
        }
    }

    /**
     * @brief Compares a resource set with expected volumes.
     *
     * @param a_resource_set The resource set to be compared.
     * @param a_volumes      A vector of expected volumes.
     *
     * TODO: Consider moving to helpers.
     */
    void compareResourceSet(
        ResourceSet                               const & a_resource_set,
        std::vector<GameServer::Resource::Volume> const & a_vector
    )
    {
        ResourceWithVolumeMap resources_map = a_resource_set.getMap();

        for (ResourceWithVolumeMap::iterator it = resources_map.begin(); it != resources_map.end(); ++it)
        {
            ASSERT_EQ(a_vector.at(it->second->getIDResource().getValue() - 1), it->second->getVolume());
        }
    }

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
     * @brief Abstract factories used in tests.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    //@{
    /**
     * @brief Persistence facades used in tests.
     */
    IBuildingPersistenceFacadeShrPtr m_building_persistence_facade;
    ICostManagerShrPtr               m_cost_manager;
    IEpochPersistenceFacadeShrPtr    m_epoch_persistence_facade;
    ILandPersistenceFacadeShrPtr     m_land_persistence_facade;
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    IUserPersistenceFacadeShrPtr     m_user_persitence_facade;
    IWorldPersistenceFacadeShrPtr    m_world_persistence_facade;
    //}@

    //@{
    /**
     * @brief Operators used in tests.
     */
    IBuildBuildingOperatorShrPtr    m_build_building_operator;
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;
    //}@
};

/**
 * Component tests of: BuildBuildingOperator::buildBuilding.
 */
TEST_F(BuildBuildingOperatorTest, buildBuilding_TryingToBuildZeroBuildings)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_BUILD_ZERO_BUILDINGS,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 0).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000)(1000);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_MissingIDHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_4, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000)(1000);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_AllResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 101).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000)(1000);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_OneResource)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 1));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 100).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(999)(10000)(10000)(1000)(1000)(1000)(1000);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_OneBuilding)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
        ASSERT_EQ(1, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(990)(9990)(9990)(990)(990)(990)(990);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_ManyBuildings)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 7).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
        ASSERT_EQ(7, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(930)(9930)(9930)(930)(930)(930)(930);

        compareResourceSet(resource_set, expected);
    }
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_Max_OnResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
                  m_build_building_operator->buildBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN, 100).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN) == NULL);
        ASSERT_EQ(100, m_building_persistence_facade->getBuilding(transaction, m_id_holder_11, KEY_DEFENSIVE_BARBICAN)->getVolume());
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, m_id_holder_11);
        std::vector<GameServer::Resource::Volume> expected = assign::list_of(0)(9000)(9000)(0)(0)(0)(0);

        compareResourceSet(resource_set, expected);
    }
}
