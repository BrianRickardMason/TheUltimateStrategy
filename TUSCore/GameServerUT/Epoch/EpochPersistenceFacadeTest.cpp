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

#include "../../GameServer/Epoch/EpochPersistenceFacade.hpp"
#include "../Persistence/TransactionDummy.hpp"
#include "EpochAccessorMock.hpp"

using namespace GameServer::Epoch;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class.
 */
class EpochPersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    EpochPersistenceFacadeTest()
        : m_epoch_name("Epoch"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name("Settlement")
    {
    }

    /**
     * @brief Test constants: the name of the epoch.
     */
    string m_epoch_name;

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

TEST_F(EpochPersistenceFacadeTest, CtorDoesNotThrow)
{
    IEpochAccessorAutPtr accessor(new EpochAccessorMock);

    ASSERT_NO_THROW(EpochPersistenceFacade persistence_facade(accessor));
}

TEST_F(EpochPersistenceFacadeTest, createEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_world_name, m_epoch_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.createEpoch(transaction, m_world_name, m_epoch_name));
}

TEST_F(EpochPersistenceFacadeTest, createEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_world_name, m_epoch_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.createEpoch(transaction, m_world_name, m_epoch_name));
}

TEST_F(EpochPersistenceFacadeTest, deleteEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deleteEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deleteEpoch_EpochHasNotBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deleteEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deleteEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    EXPECT_CALL(*mock, deleteRecord(transaction, m_world_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.deleteEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deleteEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_world_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deleteEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, getEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpoch(transaction, m_world_name);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochPersistenceFacadeTest, getEpoch_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpoch(transaction, m_world_name);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_STREQ(m_epoch_name.c_str(), epoch->getEpochName().c_str());
    ASSERT_STREQ(m_world_name.c_str(), epoch->getWorldName().c_str());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochPersistenceFacadeTest, getEpochByLandName_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpochByLandName(transaction, m_land_name);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochPersistenceFacadeTest, getEpochByLandName_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpochByLandName(transaction, m_land_name);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_STREQ(m_epoch_name.c_str(), epoch->getEpochName().c_str());
    ASSERT_STREQ(m_world_name.c_str(), epoch->getWorldName().c_str());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochPersistenceFacadeTest, getEpochBySettlementName_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getLandNameOfSettlement(transaction, m_settlement_name))
    .WillOnce(Return(m_land_name));

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpochBySettlementName(transaction, m_settlement_name);

    ASSERT_TRUE(epoch == NULL);
}

TEST_F(EpochPersistenceFacadeTest, getEpochBySettlementName_EpochDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getLandNameOfSettlement(transaction, m_settlement_name))
     .WillOnce(Return(m_land_name));

    EXPECT_CALL(*mock, getWorldNameOfLand(transaction, m_land_name))
    .WillOnce(Return(m_world_name));

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    EpochShrPtr epoch = persistence_facade.getEpochBySettlementName(transaction, m_settlement_name);

    ASSERT_TRUE(epoch != NULL);

    ASSERT_STREQ(m_epoch_name.c_str(), epoch->getEpochName().c_str());
    ASSERT_STREQ(m_world_name.c_str(), epoch->getWorldName().c_str());
    ASSERT_TRUE(epoch->getActive());
    ASSERT_FALSE(epoch->getFinished());
    ASSERT_EQ(22, epoch->getTicks());
}

TEST_F(EpochPersistenceFacadeTest, activateEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.activateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, activateEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.activateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, activateEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.activateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, activateEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    EXPECT_CALL(*mock, markActive(transaction, m_world_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.activateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, activateEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markActive(transaction, m_world_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.activateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deactivateEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deactivateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deactivateEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deactivateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deactivateEpoch_EpochHasNotBeenAactivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deactivateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, deactivateEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    EXPECT_CALL(*mock, markUnactive(transaction, m_world_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.deactivateEpoch(transaction, m_world_name));
}


TEST_F(EpochPersistenceFacadeTest, deactivateEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markUnactive(transaction, m_world_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.deactivateEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, finishEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.finishEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, finishEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.finishEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, finishEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.finishEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, finishEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    EXPECT_CALL(*mock, markFinished(transaction, m_world_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.finishEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, finishEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, markFinished(transaction, m_world_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.finishEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, tickEpoch_EpochDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(EpochRecordShrPtr()));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.tickEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, tickEpoch_EpochHasBeenFinished)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, true, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.tickEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, tickEpoch_EpochHasBeenActivated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, true, false, 22)));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.tickEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, tickEpoch_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    EXPECT_CALL(*mock, incrementTicks(transaction, m_world_name));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_TRUE(persistence_facade.tickEpoch(transaction, m_world_name));
}

TEST_F(EpochPersistenceFacadeTest, tickEpoch_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EpochAccessorMock * mock = new EpochAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_world_name))
    .WillOnce(Return(make_shared<EpochRecord>(m_epoch_name, m_world_name, false, false, 22)));

    std::exception e;

    EXPECT_CALL(*mock, incrementTicks(transaction, m_world_name))
    .WillOnce(Throw(e));

    IEpochAccessorAutPtr accessor(mock);

    EpochPersistenceFacade persistence_facade(accessor);

    ASSERT_FALSE(persistence_facade.tickEpoch(transaction, m_world_name));
}
