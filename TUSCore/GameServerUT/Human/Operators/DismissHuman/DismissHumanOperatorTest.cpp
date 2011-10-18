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

#include "../../../../GameServer/Human/Operators/DismissHuman/DismissHumanOperator.hpp"
#include "../../../Cost/CostManagerMock.hpp"
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistence/TransactionDummy.hpp"
#include "../../../Property/PropertyManagerMock.hpp"
#include "../../../Resource/ResourceManagerMock.hpp"
#include "../../HumanPersistenceFacadeMock.hpp"
#include <boost/assign.hpp>

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
class DismissHumanOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    DismissHumanOperatorTest()
        : m_cost_manager(new CostManagerMock),
          m_human_persistence_facade(new HumanPersistenceFacadeMock),
          m_property_manager(new PropertyManagerMock),
          m_resource_manager(new ResourceManagerMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
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
     * @brief Configures a HumanPersistenceFacadeMock's response for addHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A human key.
     * @param a_volume A volume of jobless.
     */
    void configureHumanPersistenceFacadeMockForAddHuman(
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
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
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        HumanWithVolumeShrPtr human_with_volume =
            (a_volume) ? make_shared<HumanWithVolume>(a_key, a_volume) : HumanWithVolumeShrPtr();

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
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, a_key, a_volume))
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
     * @brief A cost manager.
     */
    CostManagerMock * m_cost_manager;

    /**
     * @brief The persistence facade of humans.
     */
    HumanPersistenceFacadeMock * m_human_persistence_facade;

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
 * Unit tests of: DismissHumanOperator::DismissHumanOperator.
 */
TEST_F(DismissHumanOperatorTest, DismissHumanOperator)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(DismissHumanOperator dismiss_human_operator((ICostManagerShrPtr(m_cost_manager)),
                                                                (IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                                (IPropertyManagerShrPtr(m_property_manager)),
                                                                (IResourceManagerShrPtr(m_resource_manager))));
}

/**
 * Unit tests of: DismissHumanOperator::dismissHuman.
 */
TEST_F(DismissHumanOperatorTest, dismissHuman_TryingToDismissZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    DismissHumanOperator dismiss_human_operator((ICostManagerShrPtr(m_cost_manager)),
                                                (IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                (IPropertyManagerShrPtr(m_property_manager)),
                                                (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_DISMISS_ZERO_HUMANS,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 0).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_HumanIsNotDismissable)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    PropertyBooleanShrPtr engageable = make_shared<PropertyBoolean>(ID_PROPERTY_HUMAN_DISMISSABLE, false);

    EXPECT_CALL(*m_property_manager, getPropertyBoolean(transaction, KEY_WORKER_JOBLESS_NOVICE.toHash(), ID_PROPERTY_HUMAN_DISMISSABLE))
    .WillOnce(Return(engageable));

    DismissHumanOperator dismiss_human_operator((ICostManagerShrPtr(m_cost_manager)),
                                                (IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                (IPropertyManagerShrPtr(m_property_manager)),
                                                (IResourceManagerShrPtr(m_resource_manager)));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_DISMISSABLE,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_ZeroEngaged)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 0);

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(m_cost_manager),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughEngaged)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 5);

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(m_cost_manager),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_NoResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes_empty;
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes_empty));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_ZeroVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(0)(0)(0)(0)(0)(0)(0);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_LowerVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1)(1)(1)(1)(1)(1)(1);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);
    configureHumanPersistenceFacadeMockForSubtractHuman(KEY_WORKER_BLACKSMITH_NOVICE, 1);
    configureHumanPersistenceFacadeMockForAddHuman(KEY_WORKER_JOBLESS_NOVICE, 1);

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractResourceSetThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    std::exception e;
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, getResourceSet(resource_volumes)))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractResourceSetReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourceManagerMockForGetResources(getResourceSet(resource_volumes));

    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_manager, subtractResourceSet(_, m_id_holder, getResourceSet(resource_volumes)))
    .WillOnce(Return(false));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(m_resource_manager));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractHumanReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1))
    .WillOnce(Return(false));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMANS_MISSING_IN_THE_MEANTIME,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_AddHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BLACKSMITH_NOVICE, 10);
    configureHumanPersistenceFacadeMockForSubtractHuman(KEY_WORKER_BLACKSMITH_NOVICE, 1);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, addHuman(_, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(ICostManagerShrPtr(produceCostManagerMock(KEY_WORKER_BLACKSMITH_NOVICE, ID_COST_TYPE_HUMAN_DISMISS)),
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IPropertyManagerShrPtr(producePropertyManagerMockShort(KEY_WORKER_BLACKSMITH_NOVICE, ID_PROPERTY_HUMAN_DISMISSABLE)),
                                                IResourceManagerShrPtr(produceResourceManagerMock()));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BLACKSMITH_NOVICE, 1).m_exit_code);
}
