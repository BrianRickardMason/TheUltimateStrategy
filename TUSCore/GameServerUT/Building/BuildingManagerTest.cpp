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

#include "../../GameServer/Building/BuildingManager.hpp"
#include "../Persistence/TransactionDummy.hpp"
#include "BuildingManagerAccessorMock.hpp"

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class BuildingManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    BuildingManagerTest()
        : m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"),
          m_key_1(ID_BUILDING_DEFENSIVE_BARBICAN),
          m_key_2(ID_BUILDING_GOLD_ALTAR_OF_WISHES)
    {
    }

    /**
     * @brief Compares the building with expected values.
     *
     * @param a_building The building to be compared.
     * @param a_key      An expected key of the building.
     * @param a_volume   An expected volume of the building.
     */
    void compareBuilding(
        BuildingWithVolumeShrPtr         a_building,
        Key                      const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_building->getKey());
        ASSERT_EQ(a_volume, a_building->getVolume());
    }

    /**
     * @brief Test constants id holders.
     */
    IDHolder m_id_holder_1;

    /**
     * @brief Test constants keys.
     */
    Key m_key_1;
    Key m_key_2;
};

TEST_F(BuildingManagerTest, BuildingManager)
{
    IBuildingManagerAccessorAutPtr accessor(new BuildingManagerAccessorMock);

    BuildingManager manager(accessor);
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder_1, m_key_1, 5));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    manager.addBuilding(transaction, m_id_holder_1, m_key_1, 5);
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsNotPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder_1, m_key_1, 5))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_THROW(manager.addBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder_1, m_key_1, 5));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    manager.addBuilding(transaction, m_id_holder_1, m_key_1, 5);
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsPresent_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder_1, m_key_1, 5))
    .WillOnce(Throw(e));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_THROW(manager.addBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsNotPresent_TryToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_FALSE(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5));
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_SubtractPart)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder_1, m_key_1, 3));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_TRUE(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 3));
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_SubtractPart_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder_1, m_key_1, 3))
    .WillOnce(Throw(e));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_THROW(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 3), std::exception);
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_SubtractAll)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder_1, m_key_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_TRUE(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5));
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_SubtractAll_Throw)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_THROW(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_TryToSubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    ASSERT_FALSE(manager.subtractBuilding(transaction, m_id_holder_1, m_key_1, 6));
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    BuildingWithVolumeShrPtr building = manager.getBuilding(transaction, m_id_holder_1, m_key_1);

    ASSERT_TRUE(building == NULL);
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    BuildingWithVolumeShrPtr building = manager.getBuilding(transaction, m_id_holder_1, m_key_1);

    ASSERT_TRUE(building != NULL);

    compareBuilding(building, m_key_1, 5);
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(BuildingWithVolumeRecordMap()));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    BuildingWithVolumeMap buildings = manager.getBuildings(transaction, m_id_holder_1);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    BuildingWithVolumeRecordMap map;
    map.insert(make_pair(m_key_1, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(map));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    BuildingWithVolumeMap buildings = manager.getBuildings(transaction, m_id_holder_1);

    ASSERT_FALSE(buildings.empty());

    ASSERT_EQ(1, buildings.size());

    compareBuilding(buildings[m_key_1], m_key_1, 5);
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_TwoBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingManagerAccessorMock * mock = new BuildingManagerAccessorMock;

    BuildingWithVolumeRecordMap map;
    map.insert(make_pair(m_key_1, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));
    map.insert(make_pair(m_key_2, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_2, 9)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(map));

    IBuildingManagerAccessorAutPtr accessor(mock);

    BuildingManager manager(accessor);

    BuildingWithVolumeMap buildings = manager.getBuildings(transaction, m_id_holder_1);

    ASSERT_FALSE(buildings.empty());

    ASSERT_EQ(2, buildings.size());

    compareBuilding(buildings[m_key_1], m_key_1, 5);
    compareBuilding(buildings[m_key_2], m_key_2, 9);
}
