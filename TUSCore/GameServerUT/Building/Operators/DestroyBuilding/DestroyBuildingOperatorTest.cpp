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

#include "../../../../GameServer/Building/Operators/DestroyBuilding/DestroyBuildingOperator.hpp"
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistence/TransactionDummy.hpp"
#include "../../../Resource/ResourcePersistenceFacadeMock.hpp"
#include "../../BuildingPersistenceFacadeMock.hpp"
#include <GameServer/Building/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 */
class DestroyBuildingOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    DestroyBuildingOperatorTest()
        : m_context(new Context("localhost", "2222", 1, 100, "postgresql")),
          m_building_persistence_facade(new BuildingPersistenceFacadeMock),
          m_resource_persistence_facade(new ResourcePersistenceFacadeMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
    }

    /**
     * @brief Configures a BuildingPersistenceFacadeMock's responses for getBuilding().
     *
     * @param a_volume A volume to be returned.
     */
    void configureBuildingPersistenceFacadeMockForGetBuilding(
        GameServer::Building::Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_building_persistence_facade, getBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN))
        .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_DEFENSIVE_BARBICAN, a_volume)));
    }

    /**
     * @brief Configures a ResourcePersistenceFacadeMock's responses for getResources().
     *
     * @param a_resource_map A map of resources to be returned.
     */
    void configureResourcePersistenceFacadeMockForGetResources(
        ResourceWithVolumeMap const & a_resource_map
    )
    {
        EXPECT_CALL(*m_resource_persistence_facade, getResources(_, m_id_holder))
        .WillOnce(Return(a_resource_map));
    }

    /**
     * @brief Configures a ResourcePersistenceFacadeMock's responses for subtractResourceMap().
     *
     * @param a_resource_map A map of resources to be subtracted.
     */
    void configureResourcePersistenceFacadeMockForSubtractResourceMap(
        ResourceWithVolumeMap const & a_resource_map
    )
    {
        EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
        .WillOnce(Return(true));
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    //@{
    /**
     * @brief A persistence facade used in tests.
     */
    BuildingPersistenceFacadeMock * m_building_persistence_facade;
    ResourcePersistenceFacadeMock * m_resource_persistence_facade;
    //}@

    /**
     * @brief Test constants: identifiers of the holder.
     */
    IDHolder const m_id_holder;
};

/**
 * Unit tests of: DestroyBuildingOperator::DestroyBuildingOperator.
 */
TEST_F(DestroyBuildingOperatorTest, DestroyBuildingOperator)
{
    ASSERT_NO_THROW(
        DestroyBuildingOperator destroy_building_operator(
            m_context,
            IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
            IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade)
        )
    );
}

/**
 * Unit tests of: DestroyBuildingOperator::destroyBuilding.
 */
TEST_F(DestroyBuildingOperatorTest, destroyBuilding_TryingToDestroyZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 0).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_ZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN))
    .WillOnce(Return(BuildingWithVolumeShrPtr()));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(1);

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 2).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_GetResourcesThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);

    std::exception e;

    EXPECT_CALL(*m_resource_persistence_facade, getResources(_, m_id_holder))
    .WillOnce(Throw(e));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_AllResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(9)(9)(9)(9)(9)(9)(9);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_OneResource)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(9)(10)(10);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);

    std::exception e;

    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Throw(e));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractResourceReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map =  getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Return(false));

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractBuildingThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);
    std::exception e;
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Throw(e));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractBuildingReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Return(false));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDINGS_MISSING_IN_THE_MEANTIME,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Return(true));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_ManyBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 5))
    .WillOnce(Return(true));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(50)(50)(50)(50)(50)(50)(50);
    resource_map = getResourceMap(m_context, resource_volumes);

    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);
    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 5).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_Max_OnBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(10);
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10))
    .WillOnce(Return(true));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1000)(1000)(1000)(1000)(1000)(1000)(1000);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    resource_map = getResourceMap(m_context, resource_volumes);

    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);
    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_Max_OnResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(20);
    EXPECT_CALL(*m_building_persistence_facade, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10))
    .WillOnce(Return(true));

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    resource_map = getResourceMap(m_context, resource_volumes);

    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);
    DestroyBuildingOperator destroy_building_operator(m_context,
                                                      IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                      IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10).m_exit_code);
}
