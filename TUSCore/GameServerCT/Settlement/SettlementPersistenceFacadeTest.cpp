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
using namespace GameServer::Persistence;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class SettlementPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    SettlementPersistenceFacadeTest()
        : m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_land_name_3("Land3"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_persitence_facade(m_manager_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_manager_abstract_factory->createWorldPersistenceFacade()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_persistence_facade(m_manager_abstract_factory->createLandPersistenceFacade()),
          m_settlement_persistence_facade(m_manager_abstract_factory->createSettlementPersistenceFacade())
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persitence_facade->createUser(transaction, "Login", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_manager->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_2);

            m_land_1 = m_land_persistence_facade->getLand(transaction, m_land_name_1);
            m_land_2 = m_land_persistence_facade->getLand(transaction, m_land_name_2);

            transaction->commit();
        }
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
     * @brief Test constants: the name of the epoch.
     */
    string m_epoch_name;

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: the name of the world.
     */
    string m_world_name;

    /**
     * @brief Test constants: the names of the land.
     */
    string m_land_name_1,
           m_land_name_2,
           m_land_name_3;

    /**
     * @brief Test constants: the names of the settlement.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3;

    /**
     * @brief Test constants: the lands.
     */
    ILandShrPtr m_land_1,
                m_land_2,
                m_land_3;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief The persistence facade of users.
     */
    IUserPersistenceFacadeShrPtr m_user_persitence_facade;

    /**
     * @brief A world manager.
     */
    IWorldPersistenceFacadeShrPtr m_world_persistence_facade;

    /**
     * @brief The epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief A land persistence facade.
     */
    ILandPersistenceFacadeShrPtr m_land_persistence_facade;

    /**
     * @brief The persistence facade of settlements.
     */
    ISettlementPersistenceFacadeShrPtr m_settlement_persistence_facade;
};

/**
 * Component tests of: SettlementPersistenceFacade::createSettlement.
 */
TEST_F(SettlementPersistenceFacadeTest, createSettlement_FirstSettlement)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1));

        transaction->commit();
    }
}

TEST_F(SettlementPersistenceFacadeTest, createSettlement_SecondSettlement)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_2));

        transaction->commit();
    }
}

TEST_F(SettlementPersistenceFacadeTest, createSettlement_SecondSettlementWithTheSameName)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1));
    }
}

TEST_F(SettlementPersistenceFacadeTest, createSettlement_TwoSettlementsOfTheSameNameInDifferentLands)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_settlement_persistence_facade->createSettlement(transaction, m_land_2, m_settlement_name_1));
    }
}

TEST_F(SettlementPersistenceFacadeTest, createSettlement_MissingLandReference)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_settlement_persistence_facade->createSettlement(transaction, m_land_3, m_settlement_name_1));
    }
}

/**
 * Component tests of: SettlementPersistenceFacade::deleteSettlement.
 */
TEST_F(SettlementPersistenceFacadeTest, deleteSettlement_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_settlement_persistence_facade->deleteSettlement(transaction, m_settlement_name_1));

        transaction->commit();
    }
}

TEST_F(SettlementPersistenceFacadeTest, deleteSettlement_SettlementDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_settlement_persistence_facade->deleteSettlement(transaction, m_settlement_name_1));

        transaction->commit();
    }
}

/**
 * Component tests of: SettlementPersistenceFacade::getSettlement.
 */
TEST_F(SettlementPersistenceFacadeTest, getSettlement_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementShrPtr settlement = m_settlement_persistence_facade->getSettlement(transaction, m_settlement_name_1);

        ASSERT_TRUE(settlement != NULL);
        compareSettlement(settlement, m_land_name_1, m_settlement_name_1);
    }
}

TEST_F(SettlementPersistenceFacadeTest, getSettlement_SettlementDoesExist_MissingSettlementName)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementShrPtr settlement = m_settlement_persistence_facade->getSettlement(transaction, m_settlement_name_2);

        ASSERT_TRUE(settlement == NULL);
    }
}

TEST_F(SettlementPersistenceFacadeTest, getSettlement_SettlementDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementShrPtr settlement = m_settlement_persistence_facade->getSettlement(transaction, m_settlement_name_1);

        ASSERT_TRUE(settlement == NULL);
    }
}

/**
 * Component tests of: SettlementPersistenceFacade::getSettlements.
 */
TEST_F(SettlementPersistenceFacadeTest, getSettlements_SettlementsDoNotExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(transaction, m_land_1);

        ASSERT_TRUE(settlements.empty());
    }
}

TEST_F(SettlementPersistenceFacadeTest, getSettlements_SettlementsDoExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);
        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_2);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(transaction, m_land_1);

        ASSERT_FALSE(settlements.empty());
        ASSERT_EQ(2, settlements.size());
        ASSERT_TRUE(settlements[m_settlement_name_1] != NULL);
        ASSERT_TRUE(settlements[m_settlement_name_2] != NULL);
        compareSettlement(settlements[m_settlement_name_1], m_land_name_1, m_settlement_name_1);
        compareSettlement(settlements[m_settlement_name_2], m_land_name_1, m_settlement_name_2);
    }
}

TEST_F(SettlementPersistenceFacadeTest, getSettlements_SettlementsDoExist_LandDoesNotHaveAnySettlements)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);
        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_2);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(transaction, m_land_2);

        ASSERT_TRUE(settlements.empty());
    }
}

TEST_F(SettlementPersistenceFacadeTest, getSettlements_SettlementsDoExist_MissingLandName)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_1);
        m_settlement_persistence_facade->createSettlement(transaction, m_land_1, m_settlement_name_2);
        m_settlement_persistence_facade->createSettlement(transaction, m_land_2, m_settlement_name_3);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(transaction, m_land_3);

        ASSERT_TRUE(settlements.empty());
    }
}
