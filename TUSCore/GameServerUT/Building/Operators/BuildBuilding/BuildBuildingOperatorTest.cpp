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

#include "../../../../GameServer/Building/Operators/BuildBuilding/BuildBuildingOperator.hpp"
#include "../../../Cost/CostManagerMock.hpp"
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistency/TransactionDummy.hpp"
#include "../../../Resource/ResourceManagerMock.hpp"
#include "../../BuildingManagerMock.hpp"
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Persistency;
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
        : m_building_manager(new BuildingManagerMock),
          m_cost_manager(new CostManagerMock),
          m_resource_manager(new ResourceManagerMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
    }

    /**
     * @brief Configures a BuildingManagerMock's responses for getBuilding().
     *
     * @param a_volume A volume to be returned.
     */
    void configureBuildingManagerMockForGetBuilding(
        GameServer::Building::Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_building_manager, getBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN))
        .WillOnce(Return(make_shared<BuildingWithVolume>(KEY_DEFENSIVE_BARBICAN, a_volume)));
    }

    /**
     * @brief Configures a CostManagerMock's response for getCost().
     */
    void configureCostManagerMockForGetCost()
    {
        vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
        ResourceSet resource_set = getResourceSet(resource_volumes);

        EXPECT_CALL(*m_cost_manager, getCost(_, KEY_DEFENSIVE_BARBICAN.toHash(), ID_COST_TYPE_BUILDING_BUILD))
        .WillOnce(Return(resource_set));
    }

    /**
     * @brief Configures a ResourceManagerMock's responses for getResources().
     *
     * @param a_resource_set A resource set to be returned.
     */
    void configureResourceManagerMockForGetResources(
        ResourceSet const & a_resource_set
    )
    {
        EXPECT_CALL(*m_resource_manager, getResources(_, m_id_holder))
        .WillOnce(Return(a_resource_set));
    }

    /**
     * @brief Configures a ResourceManagerMock's responses for subtractResourceSet().
     *
     * @param a_resource_set A resource set to be subtracted.
     */
    void configureResourceManagerMockForSubtractResourceSet(
        ResourceSet const & a_resource_set
    )
    {
        EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, a_resource_set))
        .WillOnce(Return(true));
    }

    /**
     * @brief The manager of buildings.
     */
    BuildingManagerMock * m_building_manager;

    /**
     * @brief The manager of costs.
     */
    CostManagerMock * m_cost_manager;

    /**
     * @brief The manager of resources.
     */
    ResourceManagerMock * m_resource_manager;

    /**
     * @brief Test constants: identifiers of the holder.
     */
    IDHolder const m_id_holder;
};

/**
 * Unit tests of: BuildBuildingOperator::BuildBuildingOperator.
 */
TEST_F(BuildBuildingOperatorTest, BuildBuildingOperator)
{
    ASSERT_NO_THROW(BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                                  (IResourceManagerShrPtr(m_resource_manager))));
}

/**
 * Unit tests of: BuildBuildingOperator::buildBuilding.
 */
TEST_F(BuildBuildingOperatorTest, buildBuilding_TryingToBuildZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_BUILD_ZERO_BUILDINGS,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 0).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_GetResourcesThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;
    EXPECT_CALL(*m_resource_manager, getResources(_, m_id_holder))
    .WillOnce(Throw(e));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_GetCostThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;
    EXPECT_CALL(*m_cost_manager, getCost(_, KEY_DEFENSIVE_BARBICAN.toHash(), ID_COST_TYPE_BUILDING_BUILD))
    .WillOnce(Throw(e));

    vector<GameServer::Resource::Volume> resource_volumes;
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_AllResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(9)(9)(9)(9)(9)(9)(9);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_NotEnoughResources_OneResource)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(9);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_SubtractResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    std::exception e;
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, resource_set))
    .WillOnce(Throw(e));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_SubtractResourceReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, resource_set))
    .WillOnce(Return(false));

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_AddBuildinghrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;
    EXPECT_CALL(*m_building_manager, addBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Throw(e));

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_manager, addBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1));

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_ManyBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_manager, addBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 4));

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(40)(40)(40)(40)(40)(40)(40);
    resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 4).m_exit_code);
}

TEST_F(BuildBuildingOperatorTest, buildBuilding_Success_Max_OnResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_manager, addBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10));

    configureCostManagerMockForGetCost();

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    BuildBuildingOperator build_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                  (ICostManagerShrPtr(m_cost_manager)),
                                                  (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(BUILD_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_BUILT,
              build_building_operator.buildBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10).m_exit_code);
}