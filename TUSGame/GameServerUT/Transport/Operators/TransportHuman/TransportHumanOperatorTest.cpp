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

#include <TUSGame/GameServer/Common/IDHolder.hpp>
#include <TUSGame/GameServer/Human/Key.hpp>
#include <TUSGame/GameServer/Human/Volume.hpp>
#include <TUSGame/GameServer/Settlement/SettlementRecord.hpp>
#include <TUSGame/GameServer/Transport/Operators/TransportHuman/TransportHumanOperator.hpp>
#include <TUSGame/GameServerUT/Human/HumanPersistenceFacadeMock.hpp>
#include <TUSGame/GameServerUT/Persistence/TransactionDummy.hpp>
#include <TUSGame/GameServerUT/Settlement/SettlementPersistenceFacadeMock.hpp>
#include <boost/make_shared.hpp>

using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class.
 */
class TransportHumanOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    TransportHumanOperatorTest()
        : m_human_persistence_facade(new HumanPersistenceFacadeMock),
          m_settlement_persistence_facade(new SettlementPersistenceFacadeMock),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_settlement_1(new Settlement(ISettlementRecordShrPtr(new SettlementRecord(m_land_name_1, m_settlement_name_1)))),
          m_settlement_2(new Settlement(ISettlementRecordShrPtr(new SettlementRecord(m_land_name_1, m_settlement_name_2)))),
          m_settlement_3(new Settlement(ISettlementRecordShrPtr(new SettlementRecord(m_land_name_2, m_settlement_name_3))))
    {
    }

    /**
     * @brief The persistence facade of humans.
     */
    HumanPersistenceFacadeMock * m_human_persistence_facade;

    /**
     * @brief The persistence facade of settlements.
     */
    SettlementPersistenceFacadeMock * m_settlement_persistence_facade;

    /**
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3;

    /**
     * @brief Test constants: identifiers of holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2;

    /**
     * @brief Test constants: settlements.
     */
    ISettlementShrPtr m_settlement_1,
                      m_settlement_2,
                      m_settlement_3;
};

/**
 * Unit tests of: TransportHumanOperator::TransportHumanOperator.
 */
TEST_F(TransportHumanOperatorTest, TransportHumanOperator)
{
    ASSERT_NO_THROW(TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade))));
}

/**
 * Unit tests of: TransportHumanOperator::transportHuman.
 */
TEST_F(TransportHumanOperatorTest, transportHuman_TryingToTransportZeroHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_HUMANS,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      0).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_SourceSettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(ISettlementShrPtr()));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_DestinationSettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_2))
    .WillOnce(Return(ISettlementShrPtr()));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_SettlementsAreNotFromTheSameLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_3))
    .WillOnce(Return(m_settlement_3));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_3,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_NotEnoughHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder_1, KEY_WORKER_BREEDER_NOVICE, 10))
    .WillOnce(Return(false));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_HUMANS,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_SubtractHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_2))
    .WillOnce(Return(m_settlement_2));

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder_1, KEY_WORKER_BREEDER_NOVICE, 10))
    .WillOnce(Throw(e));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_AddHumanThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder_1, KEY_WORKER_BREEDER_NOVICE, 10))
    .WillOnce(Return(true));

    std::exception e;
    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder_2, KEY_WORKER_BREEDER_NOVICE, 10))
    .WillOnce(Throw(e));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_persistence_facade, getSettlement(transaction, m_settlement_name_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_human_persistence_facade, subtractHuman(transaction, m_id_holder_1, KEY_WORKER_BREEDER_NOVICE, 10))
    .WillOnce(Return(true));

    EXPECT_CALL(*m_human_persistence_facade, addHuman(transaction, m_id_holder_2, KEY_WORKER_BREEDER_NOVICE, 10));

    TransportHumanOperator transport_human_operator((IHumanPersistenceFacadeShrPtr(m_human_persistence_facade)),
                                                    (ISettlementPersistenceFacadeShrPtr(m_settlement_persistence_facade)));

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED,
              transport_human_operator.transportHuman(transaction,
                                                      m_settlement_name_1,
                                                      m_settlement_name_2,
                                                      KEY_WORKER_BREEDER_NOVICE,
                                                      10).m_exit_code);
}
