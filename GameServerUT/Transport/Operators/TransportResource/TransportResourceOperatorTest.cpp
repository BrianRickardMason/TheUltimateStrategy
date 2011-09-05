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

#include "../../../../GameServer/Common/IDHolder.hpp"
#include "../../../../GameServer/Land/IDLand.hpp"
#include "../../../../GameServer/Resource/Key.hpp"
#include "../../../../GameServer/Resource/Volume.hpp"
#include "../../../../GameServer/Transport/Operators/TransportResource/TransportResourceOperator.hpp"
#include "../../../Resource/ResourceManagerMock.hpp"
#include "../../../Persistency/TransactionDummy.hpp"
#include "../../../Settlement/SettlementManagerMock.hpp"
#include <boost/make_shared.hpp>

using namespace GameServer::Common;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace boost;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class.
 */
class TransportResourceOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    TransportResourceOperatorTest()
        : m_resource_manager(new ResourceManagerMock),
          m_settlement_manager(new SettlementManagerMock),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_settlement_1(1),
          m_id_settlement_2(2),
          m_id_settlement_3(3),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, 1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, 2),
          m_settlement_1(make_shared<Settlement>(SettlementRecord(m_id_land_1, m_id_settlement_1, "Settlement1"))),
          m_settlement_2(make_shared<Settlement>(SettlementRecord(m_id_land_1, m_id_settlement_2, "Settlement2"))),
          m_settlement_3(make_shared<Settlement>(SettlementRecord(m_id_land_2, m_id_settlement_3, "Settlement3")))
    {
    }

    /**
     * @brief The manager of resources.
     */
    ResourceManagerMock * m_resource_manager;

    /**
     * @brief The manager of settlements.
     */
    SettlementManagerMock * m_settlement_manager;

    /**
     * @brief Test constants: identifiers of lands.
     */
    IDLand m_id_land_1,
           m_id_land_2;

    /**
     * @brief Test constants: identifiers of settlements.
     */
    IDSettlement m_id_settlement_1,
                 m_id_settlement_2,
                 m_id_settlement_3;

    /**
     * @brief Test constants: identifiers of holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2;

    /**
     * @brief Test constants: settlements.
     */
    SettlementShrPtr m_settlement_1,
                     m_settlement_2,
                     m_settlement_3;
};

/**
 * Unit tests of: TransportResourceOperator::TransportResourceOperator.
 */
TEST_F(TransportResourceOperatorTest, TransportResourceOperator)
{
    ASSERT_NO_THROW(TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                                          (ISettlementManagerShrPtr(m_settlement_manager))));
}

/**
 * Unit tests of: TransportResourceOperator::transportResource.
 */
TEST_F(TransportResourceOperatorTest, transportResource_TryingToTransportZeroResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_RESOURCES,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            0).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_SourceSettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(SettlementShrPtr()));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_DestinationSettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_2))
    .WillOnce(Return(SettlementShrPtr()));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_SettlementsAreNotFromTheSameLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_3))
    .WillOnce(Return(m_settlement_3));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_3,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_NotEnoughResources)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_resource_manager, subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 10))
    .WillOnce(Return(false));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_SubtractResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_2))
    .WillOnce(Return(m_settlement_2));

    std::exception e;
    EXPECT_CALL(*m_resource_manager, subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 10))
    .WillOnce(Throw(e));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_AddResourceThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_resource_manager, subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 10))
    .WillOnce(Return(true));

    std::exception e;
    EXPECT_CALL(*m_resource_manager, addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 10))
    .WillOnce(Throw(e));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_settlement_1));

    EXPECT_CALL(*m_settlement_manager, getSettlement(transaction, m_id_settlement_2))
    .WillOnce(Return(m_settlement_2));

    EXPECT_CALL(*m_resource_manager, subtractResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL, 10))
    .WillOnce(Return(true));

    EXPECT_CALL(*m_resource_manager, addResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL, 10));

    TransportResourceOperator transport_resource_operator((IResourceManagerShrPtr(m_resource_manager)),
                                                          (ISettlementManagerShrPtr(m_settlement_manager)));

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_TRANSPORTED,
              transport_resource_operator.transportResource(transaction,
                                                            m_id_settlement_1,
                                                            m_id_settlement_2,
                                                            KEY_RESOURCE_COAL,
                                                            10).m_exit_code);
}
