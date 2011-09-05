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

#include "../../GameServer/Land/LandRecord.hpp"
#include "../../GameServer/Settlement/SettlementManager.hpp"
#include "../Land/LandManagerMock.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "Operators/CreateSettlement/BehaviourGiveGrantMock.hpp"
#include "SettlementManagerAccessorMock.hpp"

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 */
class SettlementManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    SettlementManagerTest()
        : m_id_epoch_1(1),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_settlement_1(1),
          m_id_settlement_2(2),
          m_id_user_1(1),
          m_id_world_1(1)
    {
    }

    /**
     * @brief Compares the settlement with expected values.
     *
     * @param a_settlement    The settlement to be compared.
     * @param a_id_land       An expected identifier of the land.
     * @param a_id_settlement An expected identifier of the settlement.
     * @param a_name          An expected name of the settlement.
     */
    void compareSettlement(
        SettlementShrPtr         a_settlement,
        IDLand           const & a_id_land,
        IDSettlement     const & a_id_settlement,
        std::string      const & a_name
    )
    {
        ASSERT_TRUE(a_id_land == a_settlement->getIDLand());
        ASSERT_TRUE(a_id_settlement == a_settlement->getIDSettlement());
        ASSERT_STREQ(a_name.c_str(), a_settlement->getName().c_str());
    }

    /**
     * @brief Test constants identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants identifiers of the land.
     */
    IDLand m_id_land_1,
           m_id_land_2;

    /**
     * @brief Test constants identifiers of the settlement.
     */
    IDSettlement m_id_settlement_1,
                 m_id_settlement_2;

    /**
     * @brief Test constants identifiers of the user.
     */
    IDUser m_id_user_1;

    /**
     * @brief Test constants identifiers of the world.
     */
    IDWorld m_id_world_1;
};

TEST_F(SettlementManagerTest, SettlementManager)
{
    ISettlementManagerAccessorAutPtr accessor(new SettlementManagerAccessorMock);

    SettlementManager manager(accessor);
}

TEST_F(SettlementManagerTest, createSettlement_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * settlement_manager_accessor_mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*settlement_manager_accessor_mock, insertRecord(transaction, m_id_land_1, "Settlement1"))
    .WillOnce(Return(m_id_settlement_1));

    ISettlementManagerAccessorAutPtr accessor(settlement_manager_accessor_mock);

    SettlementManager manager(accessor);

    ASSERT_TRUE(manager.createSettlement(transaction, m_id_land_1, "Settlement1"));
}

TEST_F(SettlementManagerTest, createSettlement_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * settlement_manager_accessor_mock = new SettlementManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*settlement_manager_accessor_mock, insertRecord(transaction, m_id_land_1, "Settlement1"))
    .WillOnce(Throw(e));

    ISettlementManagerAccessorAutPtr accessor(settlement_manager_accessor_mock);

    SettlementManager manager(accessor);

    ASSERT_FALSE(manager.createSettlement(transaction, m_id_land_1, "Settlement1"));
}

TEST_F(SettlementManagerTest, deleteSettlement_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_settlement_1));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ASSERT_TRUE(manager.deleteSettlement(transaction, m_id_settlement_1));
}

TEST_F(SettlementManagerTest, deleteSettlement_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_settlement_1))
    .WillOnce(Throw(e));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ASSERT_FALSE(manager.deleteSettlement(transaction, m_id_settlement_1));
}

TEST_F(SettlementManagerTest, getSettlement_ByIDSettlement_SettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_settlement_1))
    .WillOnce(Return(SettlementRecordShrPtr()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementShrPtr settlement = manager.getSettlement(transaction, m_id_settlement_1);

    ASSERT_TRUE(settlement == NULL);
}

TEST_F(SettlementManagerTest, getSettlement_ByIDSettlement_SettlementDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_settlement_1))
    .WillOnce(Return(make_shared<SettlementRecord>(m_id_land_1, m_id_settlement_1, "Settlement1")));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementShrPtr settlement = manager.getSettlement(transaction, m_id_settlement_1);

    ASSERT_TRUE(settlement != NULL);
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, "Settlement1", m_id_land_1))
    .WillOnce(Return(SettlementRecordShrPtr()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementShrPtr settlement = manager.getSettlement(transaction, "Settlement1", m_id_land_1);

    ASSERT_TRUE(settlement == NULL);
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, "Settlement1", m_id_land_1))
    .WillOnce(Return(make_shared<SettlementRecord>(m_id_land_1, m_id_settlement_1, "Settlement1")));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementShrPtr settlement = manager.getSettlement(transaction, "Settlement1", m_id_land_1);

    ASSERT_TRUE(settlement != NULL);
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(_))
    .WillOnce(Return(SettlementRecordMap()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction);

    ASSERT_TRUE(settlements.empty());
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoExist_OneSettlement)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    SettlementRecordMap map;
    map.insert(make_pair(m_id_settlement_1, make_shared<SettlementRecord>(m_id_land_2, m_id_settlement_1, "Settlement1")));

    EXPECT_CALL(*mock, getRecords(_))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(1, settlements.size());

    compareSettlement(settlements[m_id_settlement_1], m_id_land_2, m_id_settlement_1, "Settlement1");
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoExist_ManySettlements)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    SettlementRecordMap map;
    map.insert(make_pair(m_id_settlement_1, make_shared<SettlementRecord>(m_id_land_2, m_id_settlement_1, "Settlement1")));
    map.insert(make_pair(m_id_settlement_2, make_shared<SettlementRecord>(m_id_land_2, m_id_settlement_2, "Settlement2")));

    EXPECT_CALL(*mock, getRecords(_))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(2, settlements.size());

    compareSettlement(settlements[m_id_settlement_1], m_id_land_2, m_id_settlement_1, "Settlement1");
    compareSettlement(settlements[m_id_settlement_2], m_id_land_2, m_id_settlement_2, "Settlement2");
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_id_land_1))
    .WillOnce(Return(SettlementRecordMap()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction, m_id_land_1);

    ASSERT_TRUE(settlements.empty());
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoExist_OneSettlement)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    SettlementRecordMap map;
    map.insert(make_pair(m_id_settlement_1, make_shared<SettlementRecord>(m_id_land_1, m_id_settlement_1, "Settlement1")));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_land_1))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction, m_id_land_1);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(1, settlements.size());

    compareSettlement(settlements[m_id_settlement_1], m_id_land_1, m_id_settlement_1, "Settlement1");
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoExist_ManySettlements)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    SettlementRecordMap map;
    map.insert(make_pair(m_id_settlement_1, make_shared<SettlementRecord>(m_id_land_1, m_id_settlement_1, "Settlement1")));
    map.insert(make_pair(m_id_settlement_2, make_shared<SettlementRecord>(m_id_land_1, m_id_settlement_2, "Settlement2")));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_land_1))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    SettlementMap settlements = manager.getSettlements(transaction, m_id_land_1);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(2, settlements.size());

    compareSettlement(settlements[m_id_settlement_1], m_id_land_1, m_id_settlement_1, "Settlement1");
    compareSettlement(settlements[m_id_settlement_2], m_id_land_1, m_id_settlement_2, "Settlement2");
}
