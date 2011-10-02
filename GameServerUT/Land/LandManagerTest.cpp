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

#include "../../GameServer/Land/LandManager.hpp"
#include "../Persistency/PersistencyDummy.hpp"
#include "LandManagerAccessorMock.hpp"

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class LandManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    LandManagerTest()
        : m_id_epoch_1(1),
          m_id_epoch_2(2),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_land_3(3),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_world_name_1("World1"),
          m_world_name_2("World2")
    {
    }

    /**
     * @brief Compares the land with expected values.
     *
     * @param a_land       The land to be compared.
     * @param a_login      The expected login of the user.
     * @param a_world_name The expected name of the world.
     * @param a_id_epoch   The expected identifier of the epoch.
     * @param a_id_land    An expected identifier of the land.
     * @param a_name       An expected name of the land.
     * @param a_granted    An expected state of the granted of the land.
     */
    void compareLand(
        LandShrPtr          a_land,
        string      const   a_login,
        string      const   a_world_name,
        IDEpoch     const & a_id_epoch,
        IDLand      const & a_id_land,
        std::string const & a_name,
        bool                a_granted
    )
    {
        ASSERT_STREQ(a_login.c_str(), a_land->getLogin().c_str());
        ASSERT_STREQ(a_world_name.c_str(), a_land->getWorldName().c_str());
        ASSERT_TRUE(a_id_epoch == a_land->getIDEpoch());
        ASSERT_TRUE(a_id_land == a_land->getIDLand());
        ASSERT_STREQ(a_name.c_str(), a_land->getName().c_str());
        ASSERT_EQ(a_granted, a_land->getGranted());
    }

    /**
     * @brief Test constants identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1,
            m_id_epoch_2;

    /**
     * @brief Test constants identifiers of the land.
     */
    IDLand m_id_land_1,
           m_id_land_2,
           m_id_land_3;

    /**
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2;

    /**
     * @brief Test constants: the names of the worlds.
     */
    string m_world_name_1,
           m_world_name_2;
};

TEST_F(LandManagerTest, LandManager)
{
    ILandManagerAccessorAutPtr accessor(new LandManagerAccessorMock);

    LandManager manager(accessor);
}

TEST_F(LandManagerTest, createLand_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_TRUE(manager.createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
}

TEST_F(LandManagerTest, createLand_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"))
    .WillOnce(Throw(e));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_FALSE(manager.createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, "Land1"));
}

TEST_F(LandManagerTest, deleteLand_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_land_1));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_TRUE(manager.deleteLand(transaction, m_id_land_1));
}

TEST_F(LandManagerTest, deleteLand_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_id_land_1))
    .WillOnce(Throw(e));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_FALSE(manager.deleteLand(transaction, m_id_land_1));
}

TEST_F(LandManagerTest, getLand_ByIDLand_LandDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_land_1))
    .WillOnce(Return(LandRecordShrPtr()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLand(transaction, m_id_land_1);

    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByIDLand_LandDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_id_land_1))
    .WillOnce(Return(make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", true)));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLand(transaction, m_id_land_1);

    ASSERT_TRUE(land != NULL);

    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", true);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByLogin(transaction, m_login_1, "Land1"))
    .WillOnce(Return(LandRecordShrPtr()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLandByLogin(transaction, m_login_1, "Land1");

    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByLoginAndName_LandDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByLogin(transaction, m_login_1, "Land1"))
    .WillOnce(Return(make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_3, "Land1", true)));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLandByLogin(transaction, m_login_1, "Land1");

    ASSERT_TRUE(land != NULL);

    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_3, "Land1", true);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByWorldName(transaction, m_world_name_1, "Land1"))
    .WillOnce(Return(LandRecordShrPtr()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLandByWorldName(transaction, m_world_name_1, "Land1");

    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_ByWorldNameAndName_LandDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordByWorldName(transaction, m_world_name_1, "Land1"))
    .WillOnce(Return(make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_3, "Land1", true)));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandShrPtr land = manager.getLandByWorldName(transaction, m_world_name_1, "Land1");

    ASSERT_TRUE(land != NULL);

    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_3, "Land1", true);
}

TEST_F(LandManagerTest, getLands_LandsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(LandRecordMap()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction);

    ASSERT_TRUE(lands.empty());
}

TEST_F(LandManagerTest, getLands_LandsDoExist_OneLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(1, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
}

TEST_F(LandManagerTest, getLands_LandsDoExist_ManyLands)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));
    map.insert(make_pair(m_id_land_2, make_shared<LandRecord>(m_login_2, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2", true)));

    EXPECT_CALL(*mock, getRecords(transaction))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(2, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
    compareLand(lands[m_id_land_2], m_login_2, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2", true);
}

TEST_F(LandManagerTest, getLands_ByLogin_LandsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordsByLogin(transaction, m_login_1))
    .WillOnce(Return(LandRecordMap()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByLogin(transaction, m_login_1);

    ASSERT_TRUE(lands.empty());
}

TEST_F(LandManagerTest, getLands_ByLogin_LandsDoExist_OneLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));

    EXPECT_CALL(*mock, getRecordsByLogin(transaction, m_login_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByLogin(transaction, m_login_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(1, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
}

TEST_F(LandManagerTest, getLands_ByLogin_LandsDoExist_ManyLands)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));
    map.insert(make_pair(m_id_land_2, make_shared<LandRecord>(m_login_1, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2", true)));

    EXPECT_CALL(*mock, getRecordsByLogin(transaction, m_login_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByLogin(transaction, m_login_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(2, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
    compareLand(lands[m_id_land_2], m_login_1, m_world_name_2, m_id_epoch_2, m_id_land_2, "Land2", true);
}

TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecordsByWorldName(transaction, m_world_name_1))
    .WillOnce(Return(LandRecordMap()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByWorldName(transaction, m_world_name_1);

    ASSERT_TRUE(lands.empty());
}

TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoExist_OneLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));

    EXPECT_CALL(*mock, getRecordsByWorldName(transaction, m_world_name_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByWorldName(transaction, m_world_name_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(1, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
}

TEST_F(LandManagerTest, getLands_ByWorldName_LandsDoExist_ManyLands)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));
    map.insert(make_pair(m_id_land_2, make_shared<LandRecord>(m_login_2, m_world_name_1, m_id_epoch_1, m_id_land_2, "Land2", true)));

    EXPECT_CALL(*mock, getRecordsByWorldName(transaction, m_world_name_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLandsByWorldName(transaction, m_world_name_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(2, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
    compareLand(lands[m_id_land_2], m_login_2, m_world_name_1, m_id_epoch_1, m_id_land_2, "Land2", true);
}

TEST_F(LandManagerTest, getLands_ByLoginAndWorld_LandsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1, m_world_name_1))
    .WillOnce(Return(LandRecordMap()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction, m_login_1, m_world_name_1);

    ASSERT_TRUE(lands.empty());
}

TEST_F(LandManagerTest, getLands_ByLoginAndWorldName_LandsDoExist_OneLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1, m_world_name_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction, m_login_1, m_world_name_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(1, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
}

TEST_F(LandManagerTest, getLands_ByLoginAndWorldName_LandsDoExist_ManyLands)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    LandRecordMap map;
    map.insert(make_pair(m_id_land_1, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false)));
    map.insert(make_pair(m_id_land_2, make_shared<LandRecord>(m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_2, "Land2", true)));

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1, m_world_name_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    LandMap lands = manager.getLands(transaction, m_login_1, m_world_name_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(2, lands.size());

    compareLand(lands[m_id_land_1], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_1, "Land1", false);
    compareLand(lands[m_id_land_2], m_login_1, m_world_name_1, m_id_epoch_1, m_id_land_2, "Land2", true);
}

TEST_F(LandManagerTest, markGranted)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, markGranted(transaction, m_id_land_1));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_NO_THROW(manager.markGranted(transaction, m_id_land_1));
}
