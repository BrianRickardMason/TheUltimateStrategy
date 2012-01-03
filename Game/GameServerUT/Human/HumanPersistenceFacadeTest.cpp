// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <Server/Network/XmlRPCServer/Context.hpp>
#include <Game/GameServer/Human/HumanPersistenceFacade.hpp>
#include <Game/GameServer/Human/Key.hpp>
#include <Game/GameServerUT/Human/HumanAccessorMock.hpp>
#include <Game/GameServerUT/Persistence/TransactionDummy.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 */
class HumanPersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    HumanPersistenceFacadeTest()
        : m_context(new Context),
          m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
    {
    }

    /**
     * @brief Compares the human with expected values.
     *
     * @param a_human  The human to be compared.
     * @param a_key    An expected key of the human.
     * @param a_volume An expected volume of the human.
     */
    void compareHuman(
        HumanWithVolumeShrPtr         a_human,
        IKey                  const & a_key,
        Volume                const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_human->getHuman()->getKey());
        ASSERT_EQ(a_volume, a_human->getVolume());
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;
};

TEST_F(HumanPersistenceFacadeTest, CtorDoesNotThrow)
{
    IHumanAccessorAutPtr accessor(new HumanAccessorMock);

    ASSERT_NO_THROW(HumanPersistenceFacade persistence_facade(m_context, accessor));
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, insertRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(persistence_facade.addHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsNotPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 5))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
   ASSERT_THROW(persistence_facade.addHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5), std::exception);
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    EXPECT_CALL(*mock, increaseVolume(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(persistence_facade.addHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    EXPECT_CALL(*mock, increaseVolume(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 5))
    .WillOnce(Throw(e));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.addHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5), std::exception);
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_FALSE(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_SubtractPart)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    EXPECT_CALL(*mock, decreaseVolume(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 3));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 3));
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_SubtractPart_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    EXPECT_CALL(*mock, decreaseVolume(_, m_id_holder, KEY_WORKER_MINER_NOVICE, 3))
    .WillOnce(Throw(e));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 3), std::exception);
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_SubtractAll)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_TRUE(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5));
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_SubtractAll_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_THROW(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 5), std::exception);
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_TryToSubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands and assertions.
    ASSERT_FALSE(persistence_facade.subtractHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE, 6));
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands.
    HumanWithVolumeShrPtr human = persistence_facade.getHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE);

    // Test assertions.
    ASSERT_TRUE(human == NULL);
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_WORKER_MINER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands.
    HumanWithVolumeShrPtr human = persistence_facade.getHuman(transaction, m_id_holder, KEY_WORKER_MINER_NOVICE);

    // Test assertions.
    ASSERT_TRUE(human != NULL);

    compareHuman(human, KEY_WORKER_MINER_NOVICE, 5);
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(HumanWithVolumeRecordMap()));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands.
    HumanWithVolumeMap humans = persistence_facade.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_TRUE(humans.empty());
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_OneHuman)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_WORKER_MINER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands.
    HumanWithVolumeMap humans = persistence_facade.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(1, humans.size());

    compareHuman(humans[KEY_WORKER_MINER_NOVICE], KEY_WORKER_MINER_NOVICE, 5);
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_TwoHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanAccessorMock.
    HumanAccessorMock * mock = new HumanAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_WORKER_MINER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_MINER_NOVICE, 5)));
    map.insert(make_pair(KEY_WORKER_FARMER_ADVANCED, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_WORKER_FARMER_ADVANCED, 9)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanPersistenceFacade persistence_facade(m_context, accessor);

    // Test commands.
    HumanWithVolumeMap humans = persistence_facade.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(2, humans.size());

    compareHuman(humans[KEY_WORKER_MINER_NOVICE], KEY_WORKER_MINER_NOVICE, 5);
    compareHuman(humans[KEY_WORKER_FARMER_ADVANCED], KEY_WORKER_FARMER_ADVANCED, 9);
}
