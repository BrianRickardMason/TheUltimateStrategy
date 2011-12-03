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
#include "../../../Building/BuildingPersistenceFacadeMock.hpp"
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistence/TransactionDummy.hpp"
#include "../../../Resource/ResourcePersistenceFacadeMock.hpp"
#include "../../HumanPersistenceFacadeMock.hpp"
#include <GameServer/Building/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <boost/assign.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Human;
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
class EngageHumanOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    EngageHumanOperatorTest()
        : m_context(new Context),
          m_building_persistence_facade(new BuildingPersistenceFacadeMock),
          m_human_persistence_facade(new HumanPersistenceFacadeMock),
          m_resource_persistence_facade(new ResourcePersistenceFacadeMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
    }

    /**
     * @brief Produces configured BuildingPersistenceFacadeMock.
     *
     * @return The prepared mock.
     */
    BuildingPersistenceFacadeMock * produceBuildingPersistenceFacadeMock()
    {
        // Mocks setup: BuildingPersistenceFacadeMock.
        configureBuildingPersistenceFacadeMockForGetBuilding(KEY_REGULAR_BARRACKS, 2);

        return m_building_persistence_facade;
    }

    /**
     * @brief Produces configured ResourcePersistenceFacadeMock.
     *
     * @return The prepared mock.
     */
    ResourcePersistenceFacadeMock * produceResourcePersistenceFacadeMock()
    {
        // Mocks setup: ResourcePersistenceFacadeMock.
        std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
        configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

        resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
        configureResourcePersistenceFacadeMockForSubtractResourceMap(getResourceMap(m_context, resource_volumes));

        return m_resource_persistence_facade;
    }

    /**
     * @brief Configures a BuildingPersistenceFacadeMock's response for getBuilding().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A key of the building.
     * @param a_volume A volume of the building.
     */
    void configureBuildingPersistenceFacadeMockForGetBuilding(
        IBuildingKey const & a_key,
        Volume       const & a_volume
    )
    {
        BuildingWithVolumeShrPtr building_with_volume =
            (a_volume) ? make_shared<BuildingWithVolume>(m_context, a_key, a_volume) : BuildingWithVolumeShrPtr();

        EXPECT_CALL(*m_building_persistence_facade, getBuilding(_, m_id_holder, a_key))
        .WillOnce(Return(building_with_volume));
    }

    /**
     * @brief Configures a HumanPersistenceFacadeMock's response for addHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A human key.
     * @param a_volume A volume of jobless.
     */
    void configureHumanPersistenceFacadeMockForAddHuman(
        IKey   const & a_key,
        Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_human_persistence_facade, addHuman(_, m_id_holder, a_key, a_volume));
    }

    /**
     * @brief Configures a HumanPersistenceFacadeMock's response for getHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A key of the human.
     * @param a_volume A volume of jobless.
     */
    void configureHumanPersistenceFacadeMockForGetHuman(
        IKey   const & a_key,
        Volume const & a_volume
    )
    {
        HumanWithVolumeShrPtr human_with_volume =
            (a_volume) ? make_shared<HumanWithVolume>(m_context, a_key, a_volume) : HumanWithVolumeShrPtr();

        EXPECT_CALL(*m_human_persistence_facade, getHuman(_, m_id_holder, a_key))
        .WillOnce(Return(human_with_volume));
    }

    /**
     * @brief Configures a HumanPersistenceFacadeMock's response for subtractHuman().
     *
     * @param a_key    A key of the human.
     * @param a_volume A volume of the human.
     */
    void configureHumanPersistenceFacadeMockForSubtractHuman(
        IKey   const & a_key,
        Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, a_key, a_volume))
        .WillOnce(Return(true));
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
     * @param a_resource_map A map of resources to be returned.
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
    HumanPersistenceFacadeMock    * m_human_persistence_facade;
    ResourcePersistenceFacadeMock * m_resource_persistence_facade;
    //}@

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;
};

/**
 * Unit tests of: EngageHumanOperator::EngageHumanOperator.
 */
TEST_F(EngageHumanOperatorTest, EngageHumanOperator)
{
    ASSERT_NO_THROW(
        EngageHumanOperator engage_human_operator(
            m_context,
            IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
            IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
            IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade)
        )
    );
}

/**
 * Unit tests of: EngageHumanOperator::engageHuman.
 */
TEST_F(EngageHumanOperatorTest, engageHuman_TryingToEngageZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_ENGAGE_ZERO_HUMANS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 0).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_HumanIsNotEngageable)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_ENGAGEABLE,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_ZeroJobless)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 0);

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughJobless)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 5);

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_JOBLESS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_NoResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes;
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_ZeroVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(0)(0)(0)(0)(0)(0)(0);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_NotEnoughResources_LowerVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1)(1)(1)(1)(1)(1)(1);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNotNeeded)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);
    configureHumanPersistenceFacadeMockForSubtractHuman(KEY_WORKER_JOBLESS_NOVICE, 1);
    configureHumanPersistenceFacadeMockForAddHuman(KEY_WORKER_DRUID_NOVICE, 1);

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(produceResourcePersistenceFacadeMock()));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_DRUID_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesNotExist_HostingOneHuman)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureBuildingPersistenceFacadeMockForGetBuilding(KEY_REGULAR_FORGE, 0);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_JOBLESS_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              engage_human_operator.engageHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_ZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Test constants.
    string engage_human_key = KEY_WORKER_BLACKSMITH_NOVICE;
    unsigned int engage_human_volume = 1;
    unsigned int building_volume = 1;
    unsigned int jobless_available = 10;

    // Verify if there is enough jobless.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_JOBLESS_NOVICE, jobless_available)));

    // Get resources.
    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, getResources(transaction, m_id_holder))
    .WillOnce(Return(getResourceMap(m_context, resource_volumes)));

    // Get the building.
    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_REGULAR_FORGE))
    .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_REGULAR_FORGE, building_volume)));

    // Get the humans occupying the building.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, engage_human_key))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    // Subtract resources.
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(transaction, m_id_holder, _))
    .WillOnce(Return(true));

    // Subtract human.
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, engage_human_volume))
    .WillOnce(Return(true));

    // Add human.
    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder, engage_human_key, engage_human_volume));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, engage_human_key, engage_human_volume).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxPossibleHumans_NotMixed)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Test constants.
    string engage_human_key = KEY_WORKER_BLACKSMITH_NOVICE;
    unsigned int engage_human_volume = 1;
    unsigned int building_volume = 2;
    unsigned int jobless_available = 10;

    // Verify if there is enough jobless.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_JOBLESS_NOVICE, jobless_available)));

    // Get resources.
    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, getResources(transaction, m_id_holder))
    .WillOnce(Return(getResourceMap(m_context, resource_volumes)));

    // Get the building.
    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_REGULAR_FORGE))
    .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_REGULAR_FORGE, building_volume)));

    // Get the humans occupying the building.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, engage_human_key))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_BLACKSMITH_NOVICE, 19)));

    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    // Subtract resources.
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(transaction, m_id_holder, _))
    .WillOnce(Return(true));

    // Subtract human.
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, engage_human_volume))
    .WillOnce(Return(true));

    // Add human.
    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder, engage_human_key, engage_human_volume));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, engage_human_key, engage_human_volume).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxPossibleHumans_Mixed)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Test constants.
    string engage_human_key = KEY_WORKER_BLACKSMITH_NOVICE;
    unsigned int engage_human_volume = 1;
    unsigned int building_volume = 2;
    unsigned int jobless_available = 10;

    // Verify if there is enough jobless.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_JOBLESS_NOVICE, jobless_available)));

    // Get resources.
    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, getResources(transaction, m_id_holder))
    .WillOnce(Return(getResourceMap(m_context, resource_volumes)));

    // Get the building.
    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_REGULAR_FORGE))
    .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_REGULAR_FORGE, building_volume)));

    // Get the humans occupying the building.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, engage_human_key))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_BLACKSMITH_NOVICE, 10)));

    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_BLACKSMITH_NOVICE, 9)));

    // Subtract resources.
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(transaction, m_id_holder, _))
    .WillOnce(Return(true));

    // Subtract human.
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, engage_human_volume))
    .WillOnce(Return(true));

    // Add human.
    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder, engage_human_key, engage_human_volume));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, engage_human_key, engage_human_volume).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingOneHuman_MaxHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Test constants.
    string engage_human_key = KEY_WORKER_BLACKSMITH_NOVICE;
    unsigned int engage_human_volume = 1;
    unsigned int building_volume = 2;
    unsigned int jobless_available = 10;

    // Verify if there is enough jobless.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_JOBLESS_NOVICE, jobless_available)));

    // Get resources.
    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, getResources(transaction, m_id_holder))
    .WillOnce(Return(getResourceMap(m_context, resource_volumes)));

    // Get the building.
    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_REGULAR_FORGE))
    .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_REGULAR_FORGE, building_volume)));

    // Get the humans occupying the building.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, engage_human_key))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_BLACKSMITH_NOVICE, 20)));

    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS,
              engage_human_operator.engageHuman(transaction, m_id_holder, engage_human_key, engage_human_volume).m_exit_code);
}

TEST_F(EngageHumanOperatorTest, engageHuman_BuildingNeeded_BuildingDoesExist_HostingManyHumans_ZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Test constants.
    string engage_human_key = KEY_WORKER_BLACKSMITH_NOVICE;
    unsigned int engage_human_volume = 1;
    unsigned int building_volume = 2;
    unsigned int jobless_available = 10;

    // Verify if there is enough jobless.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolume>(m_context, KEY_WORKER_JOBLESS_NOVICE, jobless_available)));

    // Get resources.
    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, getResources(transaction, m_id_holder))
    .WillOnce(Return(getResourceMap(m_context, resource_volumes)));

    // Get the building.
    EXPECT_CALL(*m_building_persistence_facade, getBuilding(transaction, m_id_holder, KEY_REGULAR_FORGE))
    .WillOnce(Return(make_shared<BuildingWithVolume>(m_context, KEY_REGULAR_FORGE, building_volume)));

    // Get the humans occupying the building.
    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, engage_human_key))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    EXPECT_CALL(*m_human_persistence_facade, getHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_ADVANCED))
    .WillOnce(Return(HumanWithVolumeShrPtr()));

    // Subtract resources.
    resource_volumes = assign::list_of(10)(10)(10)(10)(10)(10)(10);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(transaction, m_id_holder, _))
    .WillOnce(Return(true));

    // Subtract human.
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, engage_human_volume))
    .WillOnce(Return(true));

    // Add human.
    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder, engage_human_key, engage_human_volume));

    EngageHumanOperator engage_human_operator(m_context,
                                              IBuildingPersistenceFacadeShrPtr(m_building_persistence_facade),
                                              IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                              IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(ENGAGE_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_ENGAGED,
              engage_human_operator.engageHuman(transaction, m_id_holder, engage_human_key, engage_human_volume).m_exit_code);
}
