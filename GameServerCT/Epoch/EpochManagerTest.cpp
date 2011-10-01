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
#include "../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
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
 * @brief The test class.
 */
class EpochManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    EpochManagerTest()
        : m_id_epoch_1(1),
          m_id_land_1(1),
          m_id_settlement_1(1),
          m_login("Login"),
          m_id_world_1(1),
          m_id_world_2(2),
          m_id_world_3(3),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory))
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_world_manager->createWorld(transaction, "World1");
            m_world_manager->createWorld(transaction, "World2");

            transaction->commit();
        }
    }

    /**
     * @brief Compares the epoch with expected values.
     *
     * @param a_epoch    The epoch to be compared.
     * @param a_id_epoch The expected identifier of the epoch.
     * @param a_id_world The expected identifier of the world.
     * @param a_active   The expected "active" state.
     * @param a_finished The expected "finished" state.
     * @parma a_ticks    The expected number of ticks.
     */
    void compareEpoch(
        EpochShrPtr          a_epoch,
        IDEpoch      const & a_id_epoch,
        IDWorld      const & a_id_world,
        bool         const   a_active,
        bool         const   a_finished,
        unsigned int const   a_ticks
    )
    {
        ASSERT_TRUE(a_id_epoch == a_epoch->getIDEpoch());
        ASSERT_TRUE(a_id_world == a_epoch->getIDWorld());
        ASSERT_TRUE(a_active == a_epoch->getActive());
        ASSERT_TRUE(a_finished == a_epoch->getFinished());
        ASSERT_EQ(a_ticks, a_epoch->getTicks());
    }

    /**
     * @brief Test constants: identifiers of the epoch.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants: identifiers of the land.
     */
    IDLand m_id_land_1;

    /**
     * @brief Test constants: identifiers of the settlement.
     */
    IDSettlement m_id_settlement_1;

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: identifiers of the world.
     */
    IDWorld m_id_world_1,
            m_id_world_2,
            m_id_world_3;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief The user manager.
     */
    IUserManagerShrPtr m_user_manager;

    /**
     * @brief The world manager.
     */
    IWorldManagerShrPtr m_world_manager;

    /**
     * @brief The epoch manager.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief The land manager.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief CreateSettlementOperator.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;
};

/**
 * Component tests of: EpochManager::createEpoch.
 */
TEST_F(EpochManagerTest, createEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->createEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, createEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->createEpoch(transaction, m_id_world_1));

        transaction->commit();
    }
}

TEST_F(EpochManagerTest, createEpoch_WorldDoesExist_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->createEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, createEpoch_WorldDoesExist_EpochDoesExist_DifferentWorld)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->createEpoch(transaction, m_id_world_2));

        transaction->commit();
    }
}

/**
 * Component tests of: EpochManager::deleteEpoch.
 */
TEST_F(EpochManagerTest, deleteEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deleteEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, deleteEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deleteEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, deleteEpoch_WorldDoesExist_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deleteEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, deleteEpoch_WorldDoesExist_EpochDoesExist_Finished)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->finishEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->deleteEpoch(transaction, m_id_world_1));

        transaction->commit();
    }
}

/**
 * Component tests of: EpochManager::getEpoch.
 */
TEST_F(EpochManagerTest, getEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpoch(transaction, m_id_world_3);

        transaction->commit();

        ASSERT_TRUE(epoch == NULL);
    }
}

TEST_F(EpochManagerTest, getEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpoch(transaction, m_id_world_1);

        transaction->commit();

        ASSERT_TRUE(epoch == NULL);
    }
}

TEST_F(EpochManagerTest, getEpoch_WorldDoesExist_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpoch(transaction, m_id_world_1);

        transaction->commit();

        ASSERT_FALSE(epoch == NULL);
        compareEpoch(epoch, m_id_epoch_1, m_id_world_1, false, false, 0);
    }
}

/**
 * Component tests of: EpochManager::getEpochByIDLand.
 */
TEST_F(EpochManagerTest, getEpochByIDLand_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_user_manager->createUser(transaction, "Login", "Password");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_land_manager->createLand(transaction, m_login, m_id_world_1, m_id_epoch_1, "Land");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpochByIDLand(transaction, m_id_land_1);

        transaction->commit();

        ASSERT_FALSE(epoch == NULL);
        compareEpoch(epoch, m_id_epoch_1, m_id_world_1, true, false, 0);
    }
}

/**
 * Component tests of: EpochManager::getEpochByLandName.
 */
TEST_F(EpochManagerTest, getEpochByLandName_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_user_manager->createUser(transaction, "Login", "Password");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_land_manager->createLand(transaction, m_login, m_id_world_1, m_id_epoch_1, "Land");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpochByLandName(transaction, "Land");

        transaction->commit();

        ASSERT_FALSE(epoch == NULL);
        compareEpoch(epoch, m_id_epoch_1, m_id_world_1, true, false, 0);
    }
}

/**
 * Component tests of: EpochManager::getEpochByIDSettlement.
 */
TEST_F(EpochManagerTest, getEpochByIDSettlement_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_user_manager->createUser(transaction, "Login", "Password");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_land_manager->createLand(transaction, m_login, m_id_world_1, m_id_epoch_1, "Land");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_create_settlement_operator->createSettlement(transaction, m_id_land_1, "Settlement");

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpochByIDSettlement(transaction, m_id_settlement_1);

        transaction->commit();

        ASSERT_FALSE(epoch == NULL);
        compareEpoch(epoch, m_id_epoch_1, m_id_world_1, true, false, 0);
    }
}

/**
 * Component tests of: EpochManager::activateEpoch.
 */
TEST_F(EpochManagerTest, activateEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->activateEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, activateEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->activateEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, activateEpoch_WorldDoesExist_EpochDoesExist_Finished)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->finishEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->activateEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, activateEpoch_WorldDoesExist_EpochDoesExist_Active)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->activateEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, activateEpoch_WorldDoesExist_EpochDoesExist_Unactive)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->activateEpoch(transaction, m_id_world_1));

        transaction->commit();
    }
}

/**
 * Component tests of: EpochManager::deactivateEpoch.
 */
TEST_F(EpochManagerTest, deactivateEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deactivateEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, deactivateEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->activateEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, deactivateEpoch_WorldDoesExist_EpochDoesExist_Finished)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->finishEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deactivateEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, deactivateEpoch_WorldDoesExist_EpochDoesExist_Active)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->deactivateEpoch(transaction, m_id_world_1));

        transaction->commit();
    }
}

TEST_F(EpochManagerTest, deactivateEpoch_WorldDoesExist_EpochDoesExist_Unactive)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->deactivateEpoch(transaction, m_id_world_1));
    }
}


/**
 * Component tests of: EpochManager::finishEpoch.
 */
TEST_F(EpochManagerTest, finishEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->finishEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, finishEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->finishEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, finishEpoch_WorldDoesExist_EpochDoesExist_Finished)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->finishEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->finishEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, finishEpoch_WorldDoesExist_EpochDoesExist_Active)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->finishEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, finishEpoch_WorldDoesExist_EpochDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->finishEpoch(transaction, m_id_world_1));

        transaction->commit();
    }
}

/**
 * Component tests of: EpochManager::tickEpoch.
 */
TEST_F(EpochManagerTest, tickEpoch_WorldDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->tickEpoch(transaction, m_id_world_3));
    }
}

TEST_F(EpochManagerTest, tickEpoch_WorldDoesExist_EpochDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->tickEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, tickEpoch_WorldDoesExist_EpochDoesExist_Finished)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->finishEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->tickEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, tickEpoch_WorldDoesExist_EpochDoesExist_Active)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->activateEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_FALSE(m_epoch_manager->tickEpoch(transaction, m_id_world_1));
    }
}

TEST_F(EpochManagerTest, tickEpoch_WorldDoesExist_EpochDoesExist_Unactive)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        m_epoch_manager->createEpoch(transaction, m_id_world_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_epoch_manager->tickEpoch(transaction, m_id_world_1));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        EpochShrPtr epoch = m_epoch_manager->getEpoch(transaction, m_id_world_1);

        transaction->commit();

        ASSERT_FALSE(epoch == NULL);
        compareEpoch(epoch, m_id_epoch_1, m_id_world_1, false, false, 1);
    }
}
