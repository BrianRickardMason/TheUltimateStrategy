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
#include <Game/GameServer/Building/BuildingPersistenceFacade.hpp>
#include <Game/GameServer/Building/Key.hpp>
#include <Game/GameServerUT/Building/BuildingAccessorMock.hpp>
#include <Game/GameServerUT/Persistence/TransactionDummy.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class BuildingPersistenceFacadeTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    BuildingPersistenceFacadeTest()
        : m_context(new Context),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"),
          m_key_1(KEY_REGULAR_FARM),
          m_key_2(KEY_REGULAR_MARKETPLACE)
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
        IKey                     const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_building->getBuilding()->getKey());
        ASSERT_EQ(a_volume, a_building->getVolume());
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief Test constants id holders.
     */
    IDHolder m_id_holder_1;

    /**
     * @brief Test constants keys.
     */
    IKey m_key_1,
         m_key_2;
};

TEST_F(BuildingPersistenceFacadeTest, CtorDoesNotThrow)
{
    IBuildingAccessorAutPtr accessor(new BuildingAccessorMock);

    ASSERT_NO_THROW(BuildingPersistenceFacade persistence_facade(m_context, accessor));
}

TEST_F(BuildingPersistenceFacadeTest, AddBuildingBuildingIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder_1, m_key_1, 5));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    persistence_facade.addBuilding(transaction, m_id_holder_1, m_key_1, 5);
}

TEST_F(BuildingPersistenceFacadeTest, AddBuildingBuildingIsNotPresentThrowFromAccessorIsPropagatedProperly)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_id_holder_1, m_key_1, 5))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_THROW(persistence_facade.addBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingPersistenceFacadeTest, AddBuildingBuildingIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder_1, m_key_1, 5));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    persistence_facade.addBuilding(transaction, m_id_holder_1, m_key_1, 5);
}

TEST_F(BuildingPersistenceFacadeTest, AddBuildingBuildingIsPresentThrowFromAccessorIsPropagatedProperly)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, increaseVolume(transaction, m_id_holder_1, m_key_1, 5))
    .WillOnce(Throw(e));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_THROW(persistence_facade.addBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsNotPresentReturnsFalseWhileTryingToSubtract)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_FALSE(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5));
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsPresentSubtractPartReturnsTrue)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder_1, m_key_1, 3));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_TRUE(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 3));
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsPresentSubtractPartThrowFromAccessorIsPropagatedProperly)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, decreaseVolume(transaction, m_id_holder_1, m_key_1, 3))
    .WillOnce(Throw(e));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_THROW(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 3), std::exception);
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsPresentSubtractAllReturnsTrue)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder_1, m_key_1));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_TRUE(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5));
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsPresentSubtractAllThrowFromAccessorIsPropagatedPropely)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Throw(e));

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_THROW(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 5), std::exception);
}

TEST_F(BuildingPersistenceFacadeTest, SubtractBuildingBuildingIsPresentReturnsFalseWhileTryingToSubtractTooMuch)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    ASSERT_FALSE(persistence_facade.subtractBuilding(transaction, m_id_holder_1, m_key_1, 6));
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(BuildingWithVolumeRecordShrPtr()));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    BuildingWithVolumeShrPtr building = persistence_facade.getBuilding(transaction, m_id_holder_1, m_key_1);

    ASSERT_TRUE(building == NULL);
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_holder_1, m_key_1))
    .WillOnce(Return(make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    BuildingWithVolumeShrPtr building = persistence_facade.getBuilding(transaction, m_id_holder_1, m_key_1);

    ASSERT_TRUE(building != NULL);

    compareBuilding(building, m_key_1, 5);
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsAreNotPresent)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(BuildingWithVolumeRecordMap()));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    BuildingWithVolumeMap buildings = persistence_facade.getBuildings(transaction, m_id_holder_1);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_OneBuilding)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    BuildingWithVolumeRecordMap map;
    map.insert(make_pair(m_key_1, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(map));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    BuildingWithVolumeMap buildings = persistence_facade.getBuildings(transaction, m_id_holder_1);

    ASSERT_FALSE(buildings.empty());

    ASSERT_EQ(1, buildings.size());

    compareBuilding(buildings[m_key_1], m_key_1, 5);
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_TwoBuildings)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    BuildingAccessorMock * mock = new BuildingAccessorMock;

    BuildingWithVolumeRecordMap map;
    map.insert(make_pair(m_key_1, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_1, 5)));
    map.insert(make_pair(m_key_2, make_shared<BuildingWithVolumeRecord>(m_id_holder_1, m_key_2, 9)));

    EXPECT_CALL(*mock, getRecords(transaction, m_id_holder_1))
    .WillOnce(Return(map));

    IBuildingAccessorAutPtr accessor(mock);

    BuildingPersistenceFacade persistence_facade(m_context, accessor);

    BuildingWithVolumeMap buildings = persistence_facade.getBuildings(transaction, m_id_holder_1);

    ASSERT_FALSE(buildings.empty());

    ASSERT_EQ(2, buildings.size());

    compareBuilding(buildings[m_key_1], m_key_1, 5);
    compareBuilding(buildings[m_key_2], m_key_2, 9);
}
