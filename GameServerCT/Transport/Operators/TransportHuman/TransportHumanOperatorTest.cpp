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

#include "../../../../GameServer/Common/ManagerAbstractFactoryPostgresql.hpp"
#include "../../../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../../../../GameServer/Transport/Operators/TransportHuman/TransportHumanOperatorFactory.hpp"
#include "../../../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief The test class.
 */
class TransportHumanOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    TransportHumanOperatorTest()
        : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_human_manager(m_manager_abstract_factory->createHumanManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory)),
          m_transport_human_operator(TransportHumanOperatorFactory::createTransportHumanOperator(m_manager_abstract_factory)),
          m_id_epoch_1(1),
          m_id_land_1(1),
          m_id_land_2(2),
          m_id_settlement_1(1),
          m_id_settlement_2(2),
          m_id_settlement_3(3),
          m_id_settlement_4(4),
          m_login("Login"),
          m_id_world_1(1),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, 1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, 2)
    {
        {
            IConnectionShrPtr connection = m_persistency.getConnection();
            ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login", "Password");

            m_world_manager->createWorld(transaction, "World1");

            m_epoch_manager->createEpoch(transaction, m_id_world_1);

            m_land_manager->createLand(transaction, m_login, m_id_world_1, m_id_epoch_1, "Land1");
            m_land_manager->createLand(transaction, m_login, m_id_world_1, m_id_epoch_1, "Land2");

            m_create_settlement_operator->createSettlement(transaction, m_id_land_1, "Settlement1");
            m_create_settlement_operator->createSettlement(transaction, m_id_land_1, "Settlement2");
            m_create_settlement_operator->createSettlement(transaction, m_id_land_2, "Settlement3");

            transaction->commit();
        }
    }

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief The manager of epochs.
     */
    IEpochManagerShrPtr m_epoch_manager;

    /**
     * @brief The manager of humans.
     */
    IHumanManagerShrPtr m_human_manager;

    /**
     * @brief The manager of lands.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief The manager of users.
     */
    IUserManagerShrPtr m_user_manager;

    /**
     * @brief The manager of worlds.
     */
    IWorldManagerShrPtr m_world_manager;

    /**
     * @brief CreateSettlementOperator.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;

    /**
     * @brief TransportHumanOperator.
     */
    TransportHumanOperatorAutPtr m_transport_human_operator;

    /**
     * @brief Test constants: identifiers of epochs.
     */
    IDEpoch m_id_epoch_1;

    /**
     * @brief Test constants: identifiers of lands.
     */
    IDLand m_id_land_1,
           m_id_land_2;

    /**
     * @brief Test constants: identifiers of settlements.
     */
    IDSettlement m_id_settlement_1,
                 m_id_settlement_2,
                 m_id_settlement_3,
                 m_id_settlement_4;

    /**
     * @brief Test constants: the login of the user.
     */
    string m_login;

    /**
     * @brief Test constants: identifiers of worlds.
     */
    IDWorld m_id_world_1;

    /**
     * @brief Test constants: identifiers of holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2;

};

/**
 * Component tests of: TransportHumanOperator::transportHuman.
 */
TEST_F(TransportHumanOperatorTest, transportHuman_TryingToTransportZeroHumans)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_HUMANS,
              m_transport_human_operator->transportHuman(transaction,
                                                         m_id_settlement_1,
                                                         m_id_settlement_2,
                                                         KEY_WORKER_JOBLESS_NOVICE,
                                                         0).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_SourceSettlementDoesNotExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST,
              m_transport_human_operator->transportHuman(transaction,
                                                         m_id_settlement_4,
                                                         m_id_settlement_2,
                                                         KEY_WORKER_JOBLESS_NOVICE,
                                                         10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_DestinationSettlementDoesNotExist)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST,
              m_transport_human_operator->transportHuman(transaction,
                                                         m_id_settlement_1,
                                                         m_id_settlement_4,
                                                         KEY_WORKER_JOBLESS_NOVICE,
                                                         10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_SettlementsAreNotFromTheSameLand)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND,
              m_transport_human_operator->transportHuman(transaction,
                                                         m_id_settlement_1,
                                                         m_id_settlement_3,
                                                         KEY_WORKER_JOBLESS_NOVICE,
                                                         10).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_NotEnoughHumans)
{
    IConnectionShrPtr connection = m_persistency.getConnection();
    ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_HUMANS,
              m_transport_human_operator->transportHuman(transaction,
                                                         m_id_settlement_1,
                                                         m_id_settlement_2,
                                                         KEY_WORKER_JOBLESS_NOVICE,
                                                         1001).m_exit_code);
}

TEST_F(TransportHumanOperatorTest, transportHuman_Success_OneHuman)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED,
                  m_transport_human_operator->transportHuman(transaction,
                                                             m_id_settlement_1,
                                                             m_id_settlement_2,
                                                             KEY_WORKER_JOBLESS_NOVICE,
                                                             1).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_EQ(999, m_human_manager->getHuman(transaction, m_id_holder_1, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(1, m_human_manager->getHuman(transaction, m_id_holder_2, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}

TEST_F(TransportHumanOperatorTest, transportHuman_Success_ManyHumans)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED,
                  m_transport_human_operator->transportHuman(transaction,
                                                             m_id_settlement_1,
                                                             m_id_settlement_2,
                                                             KEY_WORKER_JOBLESS_NOVICE,
                                                             500).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_EQ(500, m_human_manager->getHuman(transaction, m_id_holder_1, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(500, m_human_manager->getHuman(transaction, m_id_holder_2, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}

TEST_F(TransportHumanOperatorTest, transportHuman_Success_AllHumans)
{
    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_TRANSPORTED,
                  m_transport_human_operator->transportHuman(transaction,
                                                             m_id_settlement_1,
                                                             m_id_settlement_2,
                                                             KEY_WORKER_JOBLESS_NOVICE,
                                                             1000).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistency.getConnection();
        ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        ASSERT_TRUE(m_human_manager->getHuman(transaction, m_id_holder_1, KEY_WORKER_JOBLESS_NOVICE) == NULL);
        ASSERT_EQ(1000, m_human_manager->getHuman(transaction, m_id_holder_2, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}
