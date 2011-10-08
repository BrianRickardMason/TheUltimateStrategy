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

#include "../../../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperator.hpp"
#include "../../../Land/LandManagerMock.hpp"
#include "../../../Persistency/TransactionDummy.hpp"
#include "../../SettlementManagerMock.hpp"
#include "BehaviourGiveGrantMock.hpp"
#include <boost/make_shared.hpp>

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class CreateSettlementOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    CreateSettlementOperatorTest()
        : m_land_manager(new LandManagerMock),
          m_settlement_manager(new SettlementManagerMock),
          m_behaviour_give_grant(new BehaviourGiveGrantMock),
          m_id_epoch_1(1),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name("Settlement")
    {
    }

    /**
     * @brief The manager of lands.
     */
    LandManagerMock * m_land_manager;

    /**
     * @brief The manager of settlements.
     */
    SettlementManagerMock * m_settlement_manager;

    /**
     * @brief The behaviour "GiveGrant".
     */
    BehaviourGiveGrantMock * m_behaviour_give_grant;

    /**
     * @brief Test constants: the identifier of the epoch.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the name of the settlement.
     */
    string m_settlement_name;
};

TEST_F(CreateSettlementOperatorTest, CreateSettlementOperator)
{
    ASSERT_NO_THROW(CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant))));
}

TEST_F(CreateSettlementOperatorTest, createSettlement_LandDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr()));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_SettlementDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, false));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    SettlementRecord settlement_record(m_land_name, m_settlement_name);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(make_shared<Settlement>(settlement_record)));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_DOES_EXIST,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_SettlementHasNotBeenCreated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, false));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(SettlementShrPtr()));

    EXPECT_CALL(*m_settlement_manager, createSettlement(transaction, m_land_name, m_settlement_name))
    .WillOnce(Return(false));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_CREATED,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_GrantHasBeenGivenSettlementHasBeenCreated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, true));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(SettlementShrPtr()));

    EXPECT_CALL(*m_settlement_manager, createSettlement(transaction, m_land_name, m_settlement_name))
    .WillOnce(Return(true));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_CREATED,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_GrantHasNotBeenGivenGetSettlementFails)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, false));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(SettlementShrPtr()))
    .WillOnce(Return(SettlementShrPtr()));

    EXPECT_CALL(*m_settlement_manager, createSettlement(transaction, m_land_name, m_settlement_name))
    .WillOnce(Return(true));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_CREATED,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_GrantHasNotBeenGivenGiveTheGrantFails)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, false));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    SettlementRecord settlement_record(m_land_name, m_settlement_name);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(SettlementShrPtr()))
    .WillOnce(Return(make_shared<Settlement>(settlement_record)));

    EXPECT_CALL(*m_settlement_manager, createSettlement(transaction, m_land_name, m_settlement_name))
    .WillOnce(Return(true));

    EXPECT_CALL(*m_behaviour_give_grant, giveGrant(transaction, m_settlement_name))
    .WillOnce(Return(false));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_CREATED,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_GrantHasNotBeenGivenSettlementHasBeenCreated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    ILandRecordShrPtr land_record =
        ILandRecordShrPtr(new LandRecord(m_login, m_world_name, m_id_epoch_1, m_land_name, false));

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Return(ILandShrPtr(new Land(land_record))));

    SettlementRecord settlement_record(m_land_name, m_settlement_name);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_settlement_name))
    .WillOnce(Return(SettlementShrPtr()))
    .WillOnce(Return(make_shared<Settlement>(settlement_record)));

    EXPECT_CALL(*m_settlement_manager, createSettlement(transaction, m_land_name, m_settlement_name))
    .WillOnce(Return(true));

    EXPECT_CALL(*m_behaviour_give_grant, giveGrant(transaction, m_settlement_name))
    .WillOnce(Return(true));

    EXPECT_CALL(*m_land_manager, markGranted(transaction, m_land_name));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_CREATED,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_UnexpectedError)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;

    EXPECT_CALL(*m_land_manager, getLand(transaction, m_land_name))
    .WillOnce(Throw(e));

    CreateSettlementOperator create_settlement_operator((ILandManagerShrPtr(m_land_manager)),
                                                        (ISettlementManagerShrPtr(m_settlement_manager)),
                                                        (IBehaviourGiveGrantShrPtr(m_behaviour_give_grant)));

    ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              create_settlement_operator.createSettlement(transaction, m_land_name, m_settlement_name).m_exit_code);
}
