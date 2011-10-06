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

#include "../../GameServer/Human/HumanManager.hpp"
#include "../Persistency/TransactionDummy.hpp"
#include "HumanManagerAccessorMock.hpp"

using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;
using testing::_;

/**
 * @brief A test class.
 */
class HumanManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    HumanManagerTest()
        : m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement")
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
        Key                   const & a_key,
        Volume                const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_human->getKey());
        ASSERT_EQ(a_volume, a_human->getVolume());
    }

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;
};

/**
 * Unit tests of: HumanManager::HumanManager.
 */
TEST_F(HumanManagerTest, HumanManager)
{
    // Preconditions.
    IHumanManagerAccessorAutPtr accessor(new HumanManagerAccessorMock);

    // Test commands and assertions.
    HumanManager manager(accessor);
}

/**
 * Unit tests of: HumanManager::addHuman.
 */
TEST_F(HumanManagerTest, addHuman_HumanIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(manager.addHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));
}

TEST_F(HumanManagerTest, addHuman_HumanIsNotPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
   ASSERT_THROW(manager.addHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5), std::exception);
}

TEST_F(HumanManagerTest, addHuman_HumanIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, increaseVolume(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_NO_THROW(manager.addHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));
}

TEST_F(HumanManagerTest, addHuman_HumanIsPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, increaseVolume(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5))
    .WillOnce(Throw(e));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_THROW(manager.addHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5), std::exception);
}

/**
 * Unit tests of: HumanManager::subtractHuman.
 */
TEST_F(HumanManagerTest, subtractHuman_HumanIsNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_FALSE(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));
}

TEST_F(HumanManagerTest, subtractHuman_HumanIsPresent_SubtractPart)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, decreaseVolume(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 3));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 3));
}

TEST_F(HumanManagerTest, subtractHuman_HumanIsPresent_SubtractPart_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, decreaseVolume(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 3))
    .WillOnce(Throw(e));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_THROW(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 3), std::exception);
}

TEST_F(HumanManagerTest, subtractHuman_HumanIsPresent_SubtractAll)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_TRUE(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5));
}

TEST_F(HumanManagerTest, subtractHuman_HumanIsPresent_SubtractAll_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_THROW(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5), std::exception);
}

TEST_F(HumanManagerTest, subtractHuman_HumanIsPresent_TryToSubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands and assertions.
    ASSERT_FALSE(manager.subtractHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 6));
}

/**
 * Unit tests of: HumanManager::getHuman.
 */
TEST_F(HumanManagerTest, getHuman_HumanIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(HumanWithVolumeRecordShrPtr()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeShrPtr human = manager.getHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE);

    // Test assertions.
    ASSERT_TRUE(human == NULL);
}

TEST_F(HumanManagerTest, getHuman_HumanIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(_, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE))
    .WillOnce(Return(make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeShrPtr human = manager.getHuman(transaction, m_id_holder, KEY_SOLDIER_ARCHER_NOVICE);

    // Test assertions.
    ASSERT_TRUE(human != NULL);

    compareHuman(human, KEY_SOLDIER_ARCHER_NOVICE, 5);
}

/**
 * Unit tests of: HumanManager::getHumans by short key.
 */
TEST_F(HumanManagerTest, getHumans_ByShortKey_HumansAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(_, m_id_holder, ID_HUMAN_SOLDIER_ARCHER))
    .WillOnce(Return(HumanWithVolumeRecordMap()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_ARCHER);

    // Test assertions.
    ASSERT_TRUE(humans.empty());
}

TEST_F(HumanManagerTest, getHumans_ByShortKey_HumansArePresent_OneHuman)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_SOLDIER_ARCHER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder, ID_HUMAN_SOLDIER_ARCHER))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_ARCHER);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(1, humans.size());

    compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 5);
}

TEST_F(HumanManagerTest, getHumans_ByShortKey_HumansArePresent_TwoHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_SOLDIER_ARCHER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));
    map.insert(make_pair(KEY_SOLDIER_ARCHER_ADVANCED, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_ADVANCED, 9)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder, ID_HUMAN_SOLDIER_ARCHER))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder, ID_HUMAN_SOLDIER_ARCHER);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(2, humans.size());

    compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 5);
    compareHuman(humans[KEY_SOLDIER_ARCHER_ADVANCED], KEY_SOLDIER_ARCHER_ADVANCED, 9);
}

/**
 * Unit tests of: HumanManager::getHumans all humans.
 */
TEST_F(HumanManagerTest, getHumans_AllHumans_HumansAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(HumanWithVolumeRecordMap()));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_TRUE(humans.empty());
}

TEST_F(HumanManagerTest, getHumans_AllHumans_HumansArePresent_OneHuman)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_SOLDIER_ARCHER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(1, humans.size());

    compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 5);
}

TEST_F(HumanManagerTest, getHumans_AllHumans_HumansArePresent_TwoHumans)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    // Mocks setup: HumanManagerAccessorMock.
    HumanManagerAccessorMock * mock = new HumanManagerAccessorMock;

    HumanWithVolumeRecordMap map;
    map.insert(make_pair(KEY_SOLDIER_ARCHER_NOVICE, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SOLDIER_ARCHER_NOVICE, 5)));
    map.insert(make_pair(KEY_SORCERER_EARTH_ADVANCED, make_shared<HumanWithVolumeRecord>(m_id_holder, KEY_SORCERER_EARTH_ADVANCED, 9)));

    EXPECT_CALL(*mock, getRecords(_, m_id_holder))
    .WillOnce(Return(map));

    // Mocks setup: Wrapping around.
    IHumanManagerAccessorAutPtr accessor(mock);

    // Preconditions.
    HumanManager manager(accessor);

    // Test commands.
    HumanWithVolumeMap humans = manager.getHumans(transaction, m_id_holder);

    // Test assertions.
    ASSERT_FALSE(humans.empty());

    ASSERT_EQ(2, humans.size());

    compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 5);
    compareHuman(humans[KEY_SORCERER_EARTH_ADVANCED], KEY_SORCERER_EARTH_ADVANCED, 9);
}
