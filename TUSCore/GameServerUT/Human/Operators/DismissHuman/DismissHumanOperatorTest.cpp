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
#include "../../../Helpers/Functions.hpp"
#include "../../../Persistence/TransactionDummy.hpp"
#include "../../../Resource/ResourcePersistenceFacadeMock.hpp"
#include "../../HumanPersistenceFacadeMock.hpp"
#include <GameServer/Human/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <boost/assign.hpp>

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
class DismissHumanOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    DismissHumanOperatorTest()
        : m_context(new Context),
          m_human_persistence_facade(new HumanPersistenceFacadeMock),
          m_resource_persistence_facade(new ResourcePersistenceFacadeMock),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
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
     * @brief Configures a HumanPersistenceFacadeMock's response for addHuman().
     *
     * If volume equals 0 then null pointer is returned.
     *
     * @param a_key    A human key.
     * @param a_volume A volume of jobless.
     */
    void configureHumanPersistenceFacadeMockForAddHuman(
        IKey                      const & a_key,
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
        IKey                      const & a_key,
        GameServer::Human::Volume const & a_volume
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
        IKey                      const & a_key,
        GameServer::Human::Volume const & a_volume
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
    HumanPersistenceFacadeMock    * m_human_persistence_facade;
    ResourcePersistenceFacadeMock * m_resource_persistence_facade;
    //}@

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;
};

/**
 * Unit tests of: DismissHumanOperator::DismissHumanOperator.
 */
TEST_F(DismissHumanOperatorTest, DismissHumanOperator)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(
        DismissHumanOperator dismiss_human_operator(
            m_context,
            IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
            IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade)
        )
    );
}

/**
 * Unit tests of: DismissHumanOperator::dismissHuman.
 */
TEST_F(DismissHumanOperatorTest, dismissHuman_TryingToDismissZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_DISMISS_ZERO_HUMANS,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 0).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_HumanIsNotDismissable)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_DISMISSABLE,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_ZeroEngaged)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 0);

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughEngaged)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 5);

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_NoResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes_empty;
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes_empty));

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_ZeroVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(0)(0)(0)(0)(0)(0)(0);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_LowerVolumes)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(1)(1)(1)(1)(1)(1)(1);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);
    configureHumanPersistenceFacadeMockForSubtractHuman(KEY_WORKER_BREEDER_NOVICE, 1);
    configureHumanPersistenceFacadeMockForAddHuman(KEY_WORKER_JOBLESS_NOVICE, 1);

    DismissHumanOperator dismiss_human_operator(
        m_context,
        IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
        IResourcePersistenceFacadeShrPtr(produceResourcePersistenceFacadeMock())
    );

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractResourceMapThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    std::exception e;
    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractResourceMapReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    std::vector<GameServer::Resource::Volume> resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    configureResourcePersistenceFacadeMockForGetResources(getResourceMap(m_context, resource_volumes));

    resource_volumes = assign::list_of(100)(100)(100)(100)(100)(100)(100);
    EXPECT_CALL(*m_resource_persistence_facade, subtractResources(_, m_id_holder, _))
    .WillOnce(Return(false));

    DismissHumanOperator dismiss_human_operator(m_context,
                                                IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
                                                IResourcePersistenceFacadeShrPtr(m_resource_persistence_facade));

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(
        m_context,
        IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
        IResourcePersistenceFacadeShrPtr(produceResourcePersistenceFacadeMock())
    );

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_SubtractHumanReturnsFalse)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(_, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1))
    .WillOnce(Return(false));

    DismissHumanOperator dismiss_human_operator(
        m_context,
        IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
        IResourcePersistenceFacadeShrPtr(produceResourcePersistenceFacadeMock())
    );

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMANS_MISSING_IN_THE_MEANTIME,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
}

TEST_F(DismissHumanOperatorTest, dismissHuman_AddHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    configureHumanPersistenceFacadeMockForGetHuman(KEY_WORKER_BREEDER_NOVICE, 10);
    configureHumanPersistenceFacadeMockForSubtractHuman(KEY_WORKER_BREEDER_NOVICE, 1);

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, addHuman(_, m_id_holder, KEY_WORKER_JOBLESS_NOVICE, 1))
    .WillOnce(Throw(e));

    DismissHumanOperator dismiss_human_operator(
        m_context,
        IHumanPersistenceFacadeShrPtr(m_human_persistence_facade),
        IResourcePersistenceFacadeShrPtr(produceResourcePersistenceFacadeMock())
    );

    ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              dismiss_human_operator.dismissHuman(transaction, m_id_holder, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
}
