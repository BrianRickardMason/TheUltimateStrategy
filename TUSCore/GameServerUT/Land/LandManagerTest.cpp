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
#include "../../GameServer/Land/LandRecord.hpp"
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
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
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
     * @param a_land_name  The expected name of the land.
     * @param a_granted    An expected state of the granted of the land.
     */
    void compareLand(
        ILandShrPtr         a_land,
        string      const   a_login,
        string      const   a_world_name,
        IDEpoch     const & a_id_epoch,
        string      const   a_land_name,
        bool                a_granted
    )
    {
        ASSERT_STREQ(a_login.c_str(), a_land->getLogin().c_str());
        ASSERT_STREQ(a_world_name.c_str(), a_land->getWorldName().c_str());
        ASSERT_TRUE(a_id_epoch == a_land->getIDEpoch());
        ASSERT_STREQ(a_land_name.c_str(), a_land->getLandName().c_str());
        ASSERT_EQ(a_granted, a_land->getGranted());
    }

    /**
     * @brief Test constants identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1,
            m_id_epoch_2;

    /**
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2;

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

    EXPECT_CALL(*mock, insertRecord(transaction, m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_TRUE(manager.createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1));
}

TEST_F(LandManagerTest, createLand_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, insertRecord(transaction, m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1))
    .WillOnce(Throw(e));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_FALSE(manager.createLand(transaction, m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1));
}

TEST_F(LandManagerTest, deleteLand_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_land_name_1));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_TRUE(manager.deleteLand(transaction, m_land_name_1));
}

TEST_F(LandManagerTest, deleteLand_Failure)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, deleteRecord(transaction, m_land_name_1))
    .WillOnce(Throw(e));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_FALSE(manager.deleteLand(transaction, m_land_name_1));
}

TEST_F(LandManagerTest, getLand_LandDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_land_name_1))
    .WillOnce(Return(ILandRecordShrPtr()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ILandShrPtr land = manager.getLand(transaction, m_land_name_1);

    ASSERT_TRUE(land == NULL);
}

TEST_F(LandManagerTest, getLand_LandDoesExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecord(transaction, m_land_name_1))
    .WillOnce(Return(ILandRecordShrPtr(new LandRecord(m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, true))));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ILandShrPtr land = manager.getLand(transaction, m_land_name_1);

    ASSERT_TRUE(land != NULL);

    compareLand(land, m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, true);
}

TEST_F(LandManagerTest, getLands_LandsDoNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1))
    .WillOnce(Return(ILandRecordMap()));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ILandMap lands = manager.getLands(transaction, m_login_1);

    ASSERT_TRUE(lands.empty());
}

TEST_F(LandManagerTest, getLands_LandsDoExist_OneLand)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    ILandRecordMap map;
    map.insert(make_pair(m_land_name_1, ILandRecordShrPtr(new LandRecord(m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, false))));

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ILandMap lands = manager.getLands(transaction, m_login_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(1, lands.size());

    compareLand(lands[m_land_name_1], m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, false);
}

TEST_F(LandManagerTest, getLands_LandsDoExist_ManyLands)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    ILandRecordMap map;
    map.insert(make_pair(m_land_name_1, ILandRecordShrPtr(new LandRecord(m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, false))));
    map.insert(make_pair(m_land_name_2, ILandRecordShrPtr(new LandRecord(m_login_1, m_world_name_2, m_id_epoch_2, m_land_name_2, true))));

    EXPECT_CALL(*mock, getRecords(transaction, m_login_1))
    .WillOnce(Return(map));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ILandMap lands = manager.getLands(transaction, m_login_1);

    ASSERT_FALSE(lands.empty());

    ASSERT_EQ(2, lands.size());

    compareLand(lands[m_land_name_1], m_login_1, m_world_name_1, m_id_epoch_1, m_land_name_1, false);
    compareLand(lands[m_land_name_2], m_login_1, m_world_name_2, m_id_epoch_2, m_land_name_2, true);
}

TEST_F(LandManagerTest, markGranted)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    LandManagerAccessorMock * mock = new LandManagerAccessorMock;

    EXPECT_CALL(*mock, markGranted(transaction, m_land_name_1));

    ILandManagerAccessorAutPtr accessor(mock);

    LandManager manager(accessor);

    ASSERT_NO_THROW(manager.markGranted(transaction, m_land_name_1));
}
