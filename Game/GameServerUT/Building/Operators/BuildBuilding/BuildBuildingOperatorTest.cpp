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
#include <Game/GameServer/Building/Operators/BuildBuilding/BuildBuildingOperator.hpp>
#include <Game/GameServerUT/Building/BuildingPersistenceFacadeMock.hpp>
#include <Game/GameServerUT/Helpers/Functions.hpp>
#include <Game/GameServerUT/Persistence/TransactionDummy.hpp>
#include <Game/GameServerUT/Resource/ResourcePersistenceFacadeMock.hpp>
#include <Server/Server/include/Context.hpp>
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
 * @brief The test class.
 */
class BuildBuildingOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    BuildBuildingOperatorTest()
        : m_context(new Server::Context),
          m_building_persistence_facade(new BuildingPersistenceFacadeMock),
          m_resource_persistence_facade(new ResourcePersistenceFacadeMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
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

    Server::IContextShrPtr m_context;

    BuildingPersistenceFacadeMock * m_building_persistence_facade;
    ResourcePersistenceFacadeMock * m_resource_persistence_facade;

    /**
     * @brief Test constants: identifiers of the holder.
     */
    IDHolder const m_id_holder;
};

TEST_F(BuildBuildingOperatorTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(
        BuildBuildingOperator build_building_operator(
            m_context,
            IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
            IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade)
        )
    );
}

TEST_F(BuildBuildingOperatorTest, BuildBuildingReturnsProperValueWhileTryingToBuildZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_BUILD_ZERO_BUILDINGS,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 0).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_GetResourcesThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;
    EXPECT_CALL(*m_resource_persistence_facade, getResources(_, m_id_holder))
    .WillOnce(Throw(e));

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_AllResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(9)(9)(9)(9)(9)(9);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_OneResource)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(9);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_SubtractResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    std::exception e;
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Throw(e));

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_SubtractResourceReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Return(false));

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_AddBuildinghrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;
    EXPECT_CALL(*m_building_persistence_facade, addBuilding(_, m_id_holder, KEY_REGULAR_FARM, 1))
    .WillOnce(Throw(e));

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_persistence_facade, addBuilding(_, m_id_holder, KEY_REGULAR_FARM, 1));

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10);
    resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_ManyBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_persistence_facade, addBuilding(_, m_id_holder, KEY_REGULAR_FARM, 4));

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(40)(40)(40)(40)(40)(40);
    resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 4).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_Max_OnResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_persistence_facade, addBuilding(_, m_id_holder, KEY_REGULAR_FARM, 10));

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100);
    ResourceWithVolumeMap resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForGetResources(resource_map);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100);
    resource_map = getResourceMap(m_context, resource_volumes);
    configureResourcePersistenceFacadeMockForSubtractResourceMap(resource_map);

    BuildBuildingOperator build_building_operator(m_context,
                                                  IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                                  IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_REGULAR_FARM, 10).m_exit_code);
}
