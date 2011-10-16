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

#include "../../../../GameServer/Human/Operators/EngageHuman/EngageHumanOperator.hpp"
#include "../../../Building/BuildingManagerMock.hpp"
#include "../../../Cost/CostManagerMock.hpp"
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistence/TransactionDummy.hpp"
#include "../../../Property/PropertyManagerMock.hpp"
#include "../../../Resource/ResourceManagerMock.hpp"
#include "../../HumanManagerMock.hpp"
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace GameServer::Resource;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 */
class EngageHumanOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    EngageHumanOperatorTest()
        : m_building_manager(new BuildingManagerMock),
          m_cost_manager(new CostManagerMock),
          m_human_manager(new HumanManagerMock),
          m_property_manager(new PropertyManagerMock),
          m_resource_manager(new ResourceManagerMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
    }

    /**
     * @brief Produces configured BuildingManagerMock.
     *
     * @return The prepared mock.
     */
    BuildingManagerMock * produceBuildingManagerMock()
    {
        // Mocks setup: BuildingManagerMock.
        configureBuildingManagerMockForGetBuilding(KEY_REGULAR_BARRACKS, 2);

        return m_building_manager;
    }

    /**
     * @brief Produces configured CostManagerMock.
     *
     * @param a_key          A human key.
     * @param a_id_cost_type An identifier of the cost type.
     *
     * @return The prepared mock.
     */
    CostManagerMock * produceCostManagerMock(
        GameServer::Human::Key const & a_key,
        IDCostType             const & a_id_cost_type
    )
    {
        // Mocks setup: CostManagerMock.
        vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
        configureCostManagerMockForGetCost(a_key, a_id_cost_type, resource_volumes);

        return m_cost_manager;
    }

    /**
     * @brief Produces configured PropertyManagerMock.
     *
     * @param a_human_key    A human key.
     * @param a_building_key A building key.
     *
     * @return The prepared mock.
     */
    PropertyManagerMock * producePropertyManagerMock(
        GameServer::Human::Key    const & a_human_key,
        GameServer::Building::Key const & a_building_key
    )
    {
        // Mocks setup: PropertyManagerMock.
        configurePropertyManagerMockForGetPropertyBoolean(a_human_key, ID_PROPERTY_HUMAN_ENGAGEABLE);

        PropertyIntegerShrPtr capacity = make_shared<PropertyInteger>(ID_PROPERTY_BUILDING_CAPACITY, 10);

        EXPECT_CALL(*m_property_manager, getPropertyInteger(_, a_building_key.toHash(), ID_PROPERTY_BUILDING_CAPACITY))
        .WillOnce(Return(capacity));

        return m_property_manager;
    }

    /**
     * @brief Produces configured PropertyManagerMock.
     *
     * @param a_key         A human key.
     * @param a_id_property An identifier of the property.
     *
     * @return The prepared mock.
     */
    PropertyManagerMock * producePropertyManagerMockShort(
        GameServer::Human::Key const & a_key,
        IDProperty             const & a_id_property
    )
    {
        // Mocks setup: PropertyManagerMock.
        configurePropertyManagerMockForGetPropertyBoolean(a_key, a_id_property);

        return m_property_manager;
    }

    /**
     * @brief Produces configured ResourceManagerMock.
     *
     * @return The prepared mock.
     */
    ResourceManagerMock * produceResourceManagerMock()
    {
        // Mocks setup: ResourceManagerMock.
        std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
        configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

        resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
        configureResourceManagerMockForSubtractResourceSet(getResourceSet(resource_volumes));

        return m_resource_manager;
    }

    /**
     * @brief Configures a BuildingManagerMock's response for getBuilding().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A key of the building.
     * @param a_volume A volume of the building.
     */
    void configureBuildingManagerMockForGetBuilding(
        GameServer::Building::Key    const & a_key,
        GameServer::Building::Volume const & a_volume
    )
    {
        BuildingWithVolumeShrPtr building_with_volume =
            (a_volume) ? make_shared<BuildingWithVolume>(a_key, a_volume) : BuildingWithVolumeShrPtr();

        EXPECT_CALL(*m_building_manager, getBuilding(_, m_id_holder, a_key))
        .WillOnce(Return(building_with_volume));
    }

    /**
     * @brief Configures a HumanManagerMock's response for addHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A human key.
     * @param a_volume A volume of jobless.
     */
    void configureHumanManagerMockForAddHuman(
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_human_manager, addHuman(_, m_id_holder, a_key, a_volume));
    }

    /**
     * @brief Configures a HumanManagerMock's response for getHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A key of the human.
     * @param a_volume A volume of jobless.
     */
    void configureHumanManagerMockForGetHuman(
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        HumanWithVolumeShrPtr human_with_volume =
            (a_volume) ? make_shared<HumanWithVolume>(a_key, a_volume) : HumanWithVolumeShrPtr();

        EXPECT_CALL(*m_human_manager, getHuman(_, m_id_holder, a_key))
        .WillOnce(Return(human_with_volume));
    }

    /**
     * @brief Configures a HumanManagerMock's response for getHumans().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_volumes A vector of human volumes
     */
    void configureHumanManagerMockForGetHumans(
        vector<GameServer::Human::Volume> const & a_volumes
    )
    {
        HumanWithVolumeMap map_archer;
        HumanWithVolumeMap map_horseman;
        HumanWithVolumeMap map_infantryman;

        HumanWithVolumeShrPtr archer_novice = make_shared<HumanWithVolume>(KEY_SOLDIER_ARCHER_NOVICE, a_volumes[0]);
        HumanWithVolumeShrPtr archer_advanced = make_shared<HumanWithVolume>(KEY_SOLDIER_ARCHER_ADVANCED, a_volumes[1]);
        HumanWithVolumeShrPtr horseman_novice = make_shared<HumanWithVolume>(KEY_SOLDIER_HORSEMAN_NOVICE, a_volumes[2]);
        HumanWithVolumeShrPtr horseman_advanced = make_shared<HumanWithVolume>(KEY_SOLDIER_HORSEMAN_ADVANCED, a_volumes[3]);
        HumanWithVolumeShrPtr infantryman_novice = make_shared<HumanWithVolume>(KEY_SOLDIER_INFANTRYMAN_ADVANCED, a_volumes[4]);
        HumanWithVolumeShrPtr infantryman_advanced = make_shared<HumanWithVolume>(KEY_SOLDIER_INFANTRYMAN_NOVICE, a_volumes[5]);

        map_archer.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_ARCHER_NOVICE, archer_novice));
        map_archer.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_ARCHER_ADVANCED, archer_advanced));
        map_horseman.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_HORSEMAN_NOVICE, horseman_novice));
        map_horseman.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_HORSEMAN_ADVANCED, horseman_advanced));
        map_infantryman.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_INFANTRYMAN_NOVICE, infantryman_novice));
        map_infantryman.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_SOLDIER_INFANTRYMAN_ADVANCED, infantryman_advanced));

        EXPECT_CALL(*m_human_manager, getHumans(_, m_id_holder, ID_HUMAN_SOLDIER_ARCHER))
        .WillOnce(Return(map_archer));

        EXPECT_CALL(*m_human_manager, getHumans(_, m_id_holder, ID_HUMAN_SOLDIER_HORSEMAN))
        .WillOnce(Return(map_horseman));

        EXPECT_CALL(*m_human_manager, getHumans(_, m_id_holder, ID_HUMAN_SOLDIER_INFANTRYMAN))
        .WillOnce(Return(map_infantryman));
    }

    /**
     * @brief Configures a HumanManagerMock's response for subtractHuman().
     *
     * @param a_key    A key of the human.
     * @param a_volume A volume of the human.
     */
    void configureHumanManagerMockForSubtractHuman(
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_human_manager, subtractHuman(_, m_id_holder, a_key, a_volume))
        .WillOnce(Return(true));
    }

    /**
     * @brief Configures a PropertyManagerMock's response for getPropertyBoolean().
     *
     * @param a_key          The key of the human.
     * @param a_id_cost_type The identifier of the cost type.
     */
    void configurePropertyManagerMockForGetPropertyBoolean(
        GameServer::Human::Key           const & a_key,
        GameServer::Property::IDProperty const & a_id_property
    )
    {
        PropertyBooleanShrPtr engageable = make_shared<PropertyBoolean>(a_id_property, true);

        EXPECT_CALL(*m_property_manager, getPropertyBoolean(_, a_key.toHash(), a_id_property))
        .WillOnce(Return(engageable));
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
     * @param a_resource_set A resource set to be returned.
     */
    void configureResourceManagerMockForSubtractResourceSet(
        ResourceSet const & a_resource_set
    )
    {
        EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, a_resource_set))
        .WillOnce(Return(true));
    }

    /**
     * @brief A building manager.
     */
    BuildingManagerMock * m_building_manager;

    /**
     * @brief A cost manager.
     */
    CostManagerMock * m_cost_manager;

    /**
     * @brief A human manager.
     */
    HumanManagerMock * m_human_manager;

    /**
     * @brief A property manager.
     */
    PropertyManagerMock * m_property_manager;

    /**
     * @brief A resource manager.
     */
    ResourceManagerMock * m_resource_manager;

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;

private:
    /**
     * @brief Configures a CostManagerMock's responses for getCost().
     *
     * @param a_key          The key of the human.
     * @param a_volumes      A vector of resource volumes.
     * @param a_id_cost_type An identifier of the cost type.
     */
    void configureCostManagerMockForGetCost(
        GameServer::Human::Key               const & a_key,
        IDCostType                           const & a_id_cost_type,
        vector<GameServer::Resource::Volume> const & a_volumes
    )
    {
        ResourceSet resource_set = getResourceSet(a_volumes);

        EXPECT_CALL(*m_cost_manager, getCost(_, a_key.toHash(), a_id_cost_type))
        .WillOnce(Return(resource_set));
    }
};

/**
 * Unit tests of: EngageHumanOperator::EngageHumanOperator.
 */
TEST_F(EngageHumanOperatorTest, EngageHumanOperator)
{
    ASSERT_NO_THROW(EngageHumanOperator engage_human_operator((IBuildingManagerShrPtr(m_building_manager)),
                                                              (ICostManagerShrPtr(m_cost_manager)),
                                                              (IHumanManagerShrPtr(m_human_manager)),
                                                              (IPropertyManagerShrPtr(m_property_manager)),
                                                              (IResourceManagerShrPtr(m_resource_manager))));
}

/**
 * Unit tests of: EngageHumanOperator::engageHuman.
 */
TEST_F(EngageHumanOperatorTest, engageHuman_TryingToEngageZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EngageHumanOperator engage_human_operator((IBuildingManagerShrPtr(m_building_manager)),
                                              (ICostManagerShrPtr(m_cost_manager)),
                                              (IHumanManagerShrPtr(m_human_manager)),
                                              (IPropertyManagerShrPtr(m_property_manager)),
                                              (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_ENGAGE_ZERO_HUMANS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 0).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_HumanIsNotEngageable)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    PropertyBooleanShrPtr engageable = make_shared<PropertyBoolean>(ID_PROPERTY_HUMAN_ENGAGEABLE, false);
    EXPECT_CALL(*m_property_manager, getPropertyBoolean(_, KEY_WORKER_BLACKSMITH_NOVICE.toHash(), ID_PROPERTY_HUMAN_ENGAGEABLE))
    .WillOnce(Return(engageable));

    EngageHumanOperator engage_human_operator((IBuildingManagerShrPtr(m_building_manager)),
                                              (ICostManagerShrPtr(m_cost_manager)),
                                              (IHumanManagerShrPtr(m_human_manager)),
                                              (IPropertyManagerShrPtr(m_property_manager)),
                                              (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_ENGAGEABLE,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_ZeroJobless)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 0);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(m_cost_manager),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughJobless)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 5);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(m_cost_manager),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_NoResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes;
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_ZeroVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(0)(0)(0)(0)(0)(0)(0);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_LowerVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1)(1)(1)(1)(1)(1)(1);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNotNeeded)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);
    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_WORKER_DRUID_NOVICE, 1);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_DRUID_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_DRUID_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_DRUID_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesNotExist_HostingOneHuman)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(KEY_REGULAR_FORGE, 0);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_ENGAGEABLE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_ZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(KEY_REGULAR_FORGE, 1);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);
    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_WORKER_BLACKSMITH_NOVICE, 1);

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_WORKER_BLACKSMITH))
    .WillOnce(Return(HumanWithVolumeMap()));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, KEY_REGULAR_FORGE)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxPossibleHumans_NotMixed)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(KEY_REGULAR_FORGE, 2);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    HumanWithVolumeMap map;

    HumanWithVolumeShrPtr human_with_volume = make_shared<HumanWithVolume>(KEY_WORKER_BLACKSMITH_NOVICE, 19);
    map.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_WORKER_BLACKSMITH_NOVICE, human_with_volume));

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_WORKER_BLACKSMITH))
    .WillOnce(Return(map));

    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_WORKER_BLACKSMITH_NOVICE, 1);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, KEY_REGULAR_FORGE)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxPossibleHumans_Mixed)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(KEY_REGULAR_FORGE, 2);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    HumanWithVolumeMap map;

    HumanWithVolumeShrPtr human_with_volume_advanced = make_shared<HumanWithVolume>(KEY_WORKER_BLACKSMITH_NOVICE, 10);
    HumanWithVolumeShrPtr human_with_volume_novice = make_shared<HumanWithVolume>(KEY_WORKER_BLACKSMITH_ADVANCED, 9);
    map.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_WORKER_BLACKSMITH_NOVICE, human_with_volume_novice));
    map.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_WORKER_BLACKSMITH_ADVANCED, human_with_volume_advanced));

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_WORKER_BLACKSMITH))
    .WillOnce(Return(map));

    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_WORKER_BLACKSMITH_NOVICE, 1);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, KEY_REGULAR_FORGE)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingManagerMockForGetBuilding(KEY_REGULAR_FORGE, 2);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    HumanWithVolumeMap map;

    HumanWithVolumeShrPtr human_with_volume = make_shared<HumanWithVolume>(KEY_WORKER_BLACKSMITH_NOVICE, 20);
    map.insert(make_pair<GameServer::Human::Key, HumanWithVolumeShrPtr>(KEY_WORKER_BLACKSMITH_NOVICE, human_with_volume));

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_WORKER_BLACKSMITH))
    .WillOnce(Return(map));

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(m_building_manager),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, KEY_REGULAR_FORGE)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_ZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    HumanWithVolumeMap map_archer;
    HumanWithVolumeMap map_horseman;
    HumanWithVolumeMap map_infantryman;

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_ARCHER))
    .WillOnce(Return(map_archer));

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_HORSEMAN))
    .WillOnce(Return(map_horseman));

    EXPECT_CALL(*m_human_manager, getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_INFANTRYMAN))
    .WillOnce(Return(map_infantryman));

    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_SOLDIER_ARCHER_NOVICE, 1);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanManagerMockForAddHuman(KEY_SOLDIER_ARCHER_NOVICE, 1);

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans_SubtractResourceSetThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    std::exception e;
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, getResourceSet(resource_volumes)))
    .WillOnce(Throw(e));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans_SubtractResourceSetReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, getResourceSet(resource_volumes)))
    .WillOnce(Return(false));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans_SubtractHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    std::exception e;
    EXPECT_CALL(*m_human_manager, subtractHuman(_, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1))
    .WillOnce(Throw(e));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans_SubtractHumanReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    EXPECT_CALL(*m_human_manager, subtractHuman(_, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1))
    .WillOnce(Return(false));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_JOBLESS_MISSING_IN_THE_MEANTIME,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxPossibleHumans_AddHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(4)(5);
    configureHumanManagerMockForGetHumans(human_volumes);
    configureHumanManagerMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);

    std::exception e;
    EXPECT_CALL(*m_human_manager, addHuman(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1))
    .WillOnce(Throw(e));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_MaxHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanManagerMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Human::Volume> human_volumes = assign::list_of(1)(2)(3)(4)(5)(5);
    configureHumanManagerMockForGetHumans(human_volumes);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    EngageHumanOperator engage_human_operator(IBuildingManagerShrPtr(produceBuildingManagerMock()),
                                              ICostManagerShrPtr(produceCostManagerMock(KEY_SOLDIER_ARCHER_NOVICE, ID_COST_TYPE_HUMAN_ENGAGE)),
                                              IHumanManagerShrPtr(m_human_manager),
                                              IPropertyManagerShrPtr(producePropertyManagerMock(KEY_SOLDIER_ARCHER_NOVICE, KEY_REGULAR_BARRACKS)),
                                              IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 1).m_exit_code);
}
