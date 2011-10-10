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

#include "../../GameServer/Land/Land.hpp"
#include "../../GameServer/Settlement/SettlementManager.hpp"
#include "../../GameServer/Settlement/SettlementRecord.hpp"
#include "../Land/LandManagerMock.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "Operators/CreateSettlement/BehaviourGiveGrantMock.hpp"
#include "SettlementManagerAccessorMock.hpp"

using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
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
        : m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_land_record_1(new LandRecord("Login", "World", m_land_name_1, false)),
          m_land_record_2(new LandRecord("Login", "World", m_land_name_2, false)),
          m_land_1(new Land(m_land_record_1)),
          m_land_2(new Land(m_land_record_2))
    {
    }

    /**
     * @brief Compares the settlement with expected values.
     *
     * @param a_settlement      The settlement to be compared.
     * @param a_land_name       The expected name of the land.
     * @param a_settlement_name The expected name of the settlement.
     */
    void compareSettlement(
        ISettlementShrPtr       a_settlement,
        string            const a_land_name,
        string            const a_settlement_name
    )
    {
        ASSERT_STREQ(a_land_name.c_str(), a_settlement->getLandName().c_str());
        ASSERT_STREQ(a_settlement_name.c_str(), a_settlement->getSettlementName().c_str());
    }

    /**
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2;

    /**
     * @brief Test constants: the records of the lands.
     */
    ILandRecordShrPtr m_land_record_1,
                      m_land_record_2;

    /**
     * @brief Test constants: the lands.
     */
    ILandShrPtr m_land_1,
                m_land_2;
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

    EXPECT_CALL(*settlement_manager_accessor_mock, insertRecord(transaction, m_land_name_1, m_settlement_name_1));

    ISettlementManagerAccessorAutPtr accessor(settlement_manager_accessor_mock);

    SettlementManager manager(accessor);

    ASSERT_TRUE(manager.createSettlement(transaction, m_land_1, m_settlement_name_1));
}

TEST_F(SettlementManagerTest, createSettlement_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * settlement_manager_accessor_mock = new SettlementManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*settlement_manager_accessor_mock, insertRecord(transaction, m_land_name_1, m_settlement_name_1))
    .WillOnce(Throw(e));

    ISettlementManagerAccessorAutPtr accessor(settlement_manager_accessor_mock);

    SettlementManager manager(accessor);

    ASSERT_FALSE(manager.createSettlement(transaction, m_land_1, m_settlement_name_1));
}

TEST_F(SettlementManagerTest, deleteSettlement_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_settlement_name_1));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ASSERT_TRUE(manager.deleteSettlement(transaction, m_settlement_name_1));
}

TEST_F(SettlementManagerTest, deleteSettlement_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_settlement_name_1))
    .WillOnce(Throw(e));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ASSERT_FALSE(manager.deleteSettlement(transaction, m_settlement_name_1));
}

TEST_F(SettlementManagerTest, getSettlement_SettlementDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_settlement_name_1))
    .WillOnce(Return(ISettlementRecordShrPtr()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ISettlementShrPtr settlement = manager.getSettlement(transaction, m_settlement_name_1);

    ASSERT_TRUE(settlement == NULL);
}

TEST_F(SettlementManagerTest, getSettlement_SettlementDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_settlement_name_1))
    .WillOnce(Return(ISettlementRecordShrPtr(new SettlementRecord(m_land_name_1, m_settlement_name_1))));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ISettlementShrPtr settlement = manager.getSettlement(transaction, m_settlement_name_1);

    ASSERT_TRUE(settlement != NULL);
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_land_name_1))
    .WillOnce(Return(ISettlementRecordMap()));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ISettlementMap settlements = manager.getSettlements(transaction, m_land_1);

    ASSERT_TRUE(settlements.empty());
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoExist_OneSettlement)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    ISettlementRecordMap map;
    map.insert(make_pair(m_settlement_name_1, ISettlementRecordShrPtr(new SettlementRecord(m_land_name_1, m_settlement_name_1))));

    EXPECT_CALL(*mock, getRecords(transaction, m_land_name_1))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);

    SettlementManager manager(accessor);

    ISettlementMap settlements = manager.getSettlements(transaction, m_land_1);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(1, settlements.size());

    compareSettlement(settlements[m_settlement_name_1], m_land_name_1, m_settlement_name_1);
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoExist_ManySettlements)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    SettlementManagerAccessorMock * mock = new SettlementManagerAccessorMock;

    ISettlementRecordMap map;
    map.insert(make_pair(m_settlement_name_1, ISettlementRecordShrPtr(new SettlementRecord(m_land_name_2, m_settlement_name_1))));
    map.insert(make_pair(m_settlement_name_2, ISettlementRecordShrPtr(new SettlementRecord(m_land_name_2, m_settlement_name_2))));

    EXPECT_CALL(*mock, getRecords(transaction, m_land_name_2))
    .WillOnce(Return(map));

    ISettlementManagerAccessorAutPtr accessor(mock);


    SettlementManager manager(accessor);
    ISettlementMap settlements = manager.getSettlements(transaction, m_land_2);

    ASSERT_FALSE(settlements.empty());

    ASSERT_EQ(2, settlements.size());

    compareSettlement(settlements[m_settlement_name_1], m_land_name_2, m_settlement_name_1);
    compareSettlement(settlements[m_settlement_name_2], m_land_name_2, m_settlement_name_2);
}
