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

#include "../../GameServer/Epoch/EpochManager.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "EpochManagerAccessorMock.hpp"

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace GameServer::World;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class.
 */
class EpochManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    EpochManagerTest()
        : m_id_epoch_1(1),
          m_id_world_1(1),
          m_id_land_1(1),
          m_id_settlement_1(1),
          m_name("Land")
    {
    }

    /**
     * @brief Test constants: identifiers of epochs.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants: identifiers of worlds.
     */
    IDWorld m_id_world_1;

    /**
     * @brief Test constants: identifiers of lands.
     */
    IDLand m_id_land_1;

    /**
     * @brief Test constants: identifiers of settlements.
     */
    IDSettlement m_id_settlement_1;

    /**
     * @brief Test constants: names of lands.
     */
    string m_name;
};

TEST_F(EpochManagerTest, EpochManager)
{
    IEpochManagerAccessorAutPtr accessor(new EpochManagerAccessorMock);

    ASSERT_NO_THROW(EpochManager manager(accessor));
}

TEST_F(EpochManagerTest, createEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.createEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, createEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.createEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deleteEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deleteEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deleteEpoch_EpochHasNotBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deleteEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deleteEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.deleteEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deleteEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deleteEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, getEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpoch(transaction, m_id_world_1);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochManagerTest, getEpoch_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpoch(transaction, m_id_world_1);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_TRUE(m_id_epoch_1 == epoch->getIDEpoch());
    ASSERT_TRUE(m_id_world_1 == epoch->getIDWorld());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochManagerTest, getEpochByIDLand_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByIDLand(transaction, m_id_land_1);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochManagerTest, getEpochByIDLand_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByIDLand(transaction, m_id_land_1);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_TRUE(m_id_epoch_1 == epoch->getIDEpoch());
    ASSERT_TRUE(m_id_world_1 == epoch->getIDWorld());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochManagerTest, getEpochByLandName_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_name))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByLandName(transaction, m_name);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochManagerTest, getEpochByLandName_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_name))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByLandName(transaction, m_name);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_TRUE(m_id_epoch_1 == epoch->getIDEpoch());
    ASSERT_TRUE(m_id_world_1 == epoch->getIDWorld());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochManagerTest, getEpochByIDSettlement_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDLandOfSettlement(transaction, m_id_settlement_1))
    .WillOnce(Return(m_id_land_1));

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByIDSettlement(transaction, m_id_settlement_1);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochManagerTest, getEpochByIDSettlement_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getIDLandOfSettlement(transaction, m_id_settlement_1))
     .WillOnce(Return(m_id_land_1));

    EXPECT_CALL(*mock, getIDWorldOfLand(transaction, m_id_land_1))
    .WillOnce(Return(m_id_world_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    EpochShrPtr epoch = manager.getEpochByIDSettlement(transaction, m_id_settlement_1);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_TRUE(m_id_epoch_1 == epoch->getIDEpoch());
    ASSERT_TRUE(m_id_world_1 == epoch->getIDWorld());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochManagerTest, activateEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.activateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, activateEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.activateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, activateEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.activateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, activateEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    EXPECT_CALL(*mock, markActive(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.activateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, activateEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markActive(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.activateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deactivateEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deactivateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deactivateEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deactivateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deactivateEpoch_EpochHasNotBeenAactivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deactivateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, deactivateEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    EXPECT_CALL(*mock, markUnactive(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.deactivateEpoch(transaction, m_id_world_1));
}


TEST_F(EpochManagerTest, deactivateEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markUnactive(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.deactivateEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, finishEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.finishEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, finishEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.finishEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, finishEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.finishEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, finishEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    EXPECT_CALL(*mock, markFinished(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.finishEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, finishEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markFinished(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.finishEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, tickEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.tickEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, tickEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, true, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.tickEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, tickEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, true, false, 22)));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.tickEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, tickEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    EXPECT_CALL(*mock, incrementTicks(transaction, m_id_world_1));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_TRUE(manager.tickEpoch(transaction, m_id_world_1));
}

TEST_F(EpochManagerTest, tickEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochManagerAccessorMock * mock = new EpochManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_world_1))
    .WillOnce(Return(make_shared<EpochRecord>(m_id_epoch_1, m_id_world_1, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, incrementTicks(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    IEpochManagerAccessorAutPtr accessor(mock);

    EpochManager manager(accessor);

    ASSERT_FALSE(manager.tickEpoch(transaction, m_id_world_1));
}
