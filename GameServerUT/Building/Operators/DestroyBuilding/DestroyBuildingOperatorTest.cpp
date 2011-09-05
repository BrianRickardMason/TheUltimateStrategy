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
        : m_building_manager(new BuildingManagerMock),
          m_cost_manager(new CostManagerMock),
          m_resource_manager(new ResourceManagerMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, 1)
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
        std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
        ResourceSet resource_set = getResourceSet(resource_volumes);

        EXPECT_CALL(*m_cost_manager, getCost(_, KEY_DEFENSIVE_BARBICAN.toHash(), ID_COST_TYPE_BUILDING_DESTROY))
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
 * Unit tests of: DestroyBuildingOperator::DestroyBuildingOperator.
 */
TEST_F(DestroyBuildingOperatorTest, DestroyBuildingOperator)
{
    ASSERT_NO_THROW(DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                                      (IResourceManagerShrPtr(m_resource_manager))));
}

/**
 * Unit tests of: DestroyBuildingOperator::destroyBuilding.
 */
TEST_F(DestroyBuildingOperatorTest, destroyBuilding_TryingToDestroyZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 0).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_ZeroBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_building_manager, getBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN))
    .WillOnce(Return(BuildingWithVolumeShrPtr()));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(1);

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 2).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_GetResourcesThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    std::exception e;

    EXPECT_CALL(*m_resource_manager, getResources(_, m_id_holder))
    .WillOnce(Throw(e));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_GetCostThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    std::exception e;

    EXPECT_CALL(*m_cost_manager, getCost(_, KEY_DEFENSIVE_BARBICAN.toHash(), ID_COST_TYPE_BUILDING_DESTROY))
    .WillOnce(Throw(e));

    std::vector<GameServer::Resource::Volume> resource_volumes;
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_AllResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(9)(9)(9)(9)(9)(9)(9);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_NotEnoughResources_OneResource)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(9)(10)(10);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);

    std::exception e;

    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, resource_set))
    .WillOnce(Throw(e));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractResourceReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set =     getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, resource_set))
    .WillOnce(Return(false));

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractBuildingThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);
    std::exception e;
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Throw(e));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_SubtractBuildingReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Return(false));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDINGS_MISSING_IN_THE_MEANTIME,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1))
    .WillOnce(Return(true));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForSubtractResourceSet(resource_set);

    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 1).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_ManyBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 5))
    .WillOnce(Return(true));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(50)(50)(50)(50)(50)(50)(50);
    resource_set = getResourceSet(resource_volumes);

    configureResourceManagerMockForSubtractResourceSet(resource_set);
    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 5).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_Max_OnBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(10);
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10))
    .WillOnce(Return(true));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1000)(1000)(1000)(1000)(1000)(1000)(1000);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    resource_set = getResourceSet(resource_volumes);

    configureResourceManagerMockForSubtractResourceSet(resource_set);
    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10).m_exit_code);
}

TEST_F(DestroyBuildingOperatorTest, destroyBuilding_Success_Max_OnResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(20);
    EXPECT_CALL(*m_building_manager, subtractBuilding(_, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10))
    .WillOnce(Return(true));

    configureCostManagerMockForGetCost();

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    ResourceSet resource_set = getResourceSet(resource_volumes);
    configureResourceManagerMockForGetResources(resource_set);
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    resource_set = getResourceSet(resource_volumes);

    configureResourceManagerMockForSubtractResourceSet(resource_set);
    DestroyBuildingOperator destroy_building_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                      (ICostManagerShrPtr(m_cost_manager)),
                                                      (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED,
              destroy_building_operator.destroyBuilding(transaction, m_id_holder, KEY_DEFENSIVE_BARBICAN, 10).m_exit_code);
}
