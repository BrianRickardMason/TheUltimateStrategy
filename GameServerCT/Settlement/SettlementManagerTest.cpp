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

#include "../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class SettlementManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    SettlementManagerTest()
        : m_id_epoch_1(1),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_land_3(3),
          m_id_settlement_1(1),
          m_id_settlement_2(2),
          m_id_settlement_3(3),
          m_id_user_1(1),
          m_id_world_1(1),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_settlement_manager(m_manager_abstract_factory->createSettlementManager())
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login", "Password");

            m_world_manager->createWorld(transaction, "World1");

            m_epoch_manager->createEpoch(transaction, m_id_world_1);

            m_land_manager->createLand(transaction, m_id_user_1, m_id_world_1, m_id_epoch_1, "Land1");
            m_land_manager->createLand(transaction, m_id_user_1, m_id_world_1, m_id_epoch_1, "Land2");

            transaction->commit();
        }
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
        string           const & a_name
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
           m_id_land_2,
           m_id_land_3;

    /**
     * @brief Test constants identifiers of the settlement.
     */
    IDSettlement m_id_settlement_1,
                 m_id_settlement_2,
                 m_id_settlement_3;

    /**
     * @brief Test constants identifiers of the user.
     */
    IDUser m_id_user_1;

    /**
     * @brief Test constants identifiers of the world.
     */
    IDWorld m_id_world_1;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief A user manager.
     */
    IUserManagerShrPtr m_user_manager;

    /**
     * @brief A world manager.
     */
    IWorldManagerShrPtr m_world_manager;

    /**
     * @brief The epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief A land manager.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief The manager of settlements.
     */
    ISettlementManagerShrPtr m_settlement_manager;
};

/**
 * Component tests of: SettlementManager::createSettlement.
 */
TEST_F(SettlementManagerTest, createSettlement_FirstSettlement)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement"));

        transaction->commit();
    }
}

TEST_F(SettlementManagerTest, createSettlement_SecondSettlement)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement2"));

        transaction->commit();
    }
}

TEST_F(SettlementManagerTest, createSettlement_SecondSettlementWithTheSameName)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement"));
    }
}

TEST_F(SettlementManagerTest, createSettlement_TwoSettlementsOfTheSameNameInDifferentLands)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_settlement_manager->createSettlement(transaction, m_id_land_2, "Settlement"));

        transaction->commit();
    }
}

TEST_F(SettlementManagerTest, createSettlement_MissingLandReference)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_settlement_manager->createSettlement(transaction, m_id_land_3, "Settlement"));
    }
}

/**
 * Component tests of: SettlementManager::deleteSettlement.
 */
TEST_F(SettlementManagerTest, deleteSettlement_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_settlement_manager->deleteSettlement(transaction, m_id_settlement_1));

        transaction->commit();
    }
}

TEST_F(SettlementManagerTest, deleteSettlement_SettlementDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_settlement_manager->deleteSettlement(transaction, m_id_settlement_1));

        transaction->commit();
    }
}

/**
 * Component tests of: SettlementManager::getSettlement.
 */
TEST_F(SettlementManagerTest, getSettlement_ByIDSettlement_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, m_id_settlement_1);

        ASSERT_TRUE(settlement != NULL);
        compareSettlement(settlement, m_id_land_1, m_id_settlement_1, "Settlement");
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByIDSettlement_SettlementDoesExist_MissingIDSettlement)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, m_id_settlement_2);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByIDSettlement_SettlementDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, m_id_settlement_1);

        ASSERT_TRUE(settlement == NULL);
    }
}

/**
 * Component tests of: SettlementManager::getSettlement.
 */
TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement", m_id_land_1);

        ASSERT_TRUE(settlement != NULL);
        compareSettlement(settlement, m_id_land_1, m_id_settlement_1, "Settlement");
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist_MissingNameMissingIDLand)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement3", m_id_land_3);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist_MissingNameCorrectIDLand)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement3", m_id_land_1);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist_CorrectNameMissingIDLand)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement", m_id_land_3);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesExist_WrongNameIDLandCombination)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");
        m_settlement_manager->createSettlement(transaction, m_id_land_2, "Settlement2");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement2", m_id_land_1);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementManagerTest, getSettlement_ByNameAndIDLand_SettlementDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementShrPtr settlement = m_settlement_manager->getSettlement(transaction, "Settlement", m_id_land_1);

        ASSERT_TRUE(settlement == NULL);
    }
}

/**
 * Component tests of: SettlementManager::getSettlements.
 */
TEST_F(SettlementManagerTest, getSettlements_SettlementsDoNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction);

        transaction->commit();
    }
}

TEST_F(SettlementManagerTest, getSettlements_SettlementsDoExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");
        m_settlement_manager->createSettlement(transaction, m_id_land_2, "Settlement2");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction);

        ASSERT_FALSE(settlements.empty());
        ASSERT_EQ(2, settlements.size());
        ASSERT_TRUE(settlements[m_id_settlement_1] != NULL);
        ASSERT_TRUE(settlements[m_id_settlement_2] != NULL);
        compareSettlement(settlements[m_id_settlement_1], m_id_land_1, m_id_settlement_1, "Settlement1");
        compareSettlement(settlements[m_id_settlement_2], m_id_land_2, m_id_settlement_2, "Settlement2");
    }
}

/**
 * Component tests of: SettlementManager::getSettlements.
 */
TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction, m_id_land_1);

        ASSERT_TRUE(settlements.empty());
    }
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");
        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement2");
        m_settlement_manager->createSettlement(transaction, m_id_land_2, "Settlement3");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction, m_id_land_1);

        ASSERT_FALSE(settlements.empty());
        ASSERT_EQ(2, settlements.size());
        ASSERT_TRUE(settlements[m_id_settlement_1] != NULL);
        ASSERT_TRUE(settlements[m_id_settlement_2] != NULL);
        compareSettlement(settlements[m_id_settlement_1], m_id_land_1, m_id_settlement_1, "Settlement1");
        compareSettlement(settlements[m_id_settlement_2], m_id_land_1, m_id_settlement_2, "Settlement2");
    }
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoExist_LandDoesNotHaveAnySettlements)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");
        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement2");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction, m_id_land_2);

        ASSERT_TRUE(settlements.empty());
    }
}

TEST_F(SettlementManagerTest, getSettlements_ByIDLand_SettlementsDoExist_MissingIDLand)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement1");
        m_settlement_manager->createSettlement(transaction, m_id_land_1, "Settlement2");
        m_settlement_manager->createSettlement(transaction, m_id_land_2, "Settlement3");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        SettlementMap settlements = m_settlement_manager->getSettlements(transaction, m_id_land_3);

        ASSERT_TRUE(settlements.empty());
    }
}
