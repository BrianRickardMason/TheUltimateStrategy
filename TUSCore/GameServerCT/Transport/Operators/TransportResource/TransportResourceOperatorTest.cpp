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
#include "../../../../GameServer/Transport/Operators/TransportResource/TransportResourceOperatorFactory.hpp"
#include "../../../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief The test class.
 */
class TransportResourceOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    TransportResourceOperatorTest()
        : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_persistence_facade(m_manager_abstract_factory->createLandPersistenceFacade()),
          m_resource_manager(m_manager_abstract_factory->createResourceManager()),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory)),
          m_transport_resource_operator(TransportResourceOperatorFactory::createTransportResourceOperator(m_manager_abstract_factory)),
          m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_settlement_name_4("Settlement4"),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login", "Password");

            m_world_manager->createWorld(transaction, m_world_name);

            m_epoch_manager->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name_2);

            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_2);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_2, m_settlement_name_3);

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
     * @brief The persistence facade of lands.
     */
    ILandPersistenceFacadeShrPtr m_land_persistence_facade;

    /**
     * @brief The manager of resources.
     */
    IResourceManagerShrPtr m_resource_manager;

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
     * @brief TransportResourceOperator.
     */
    TransportResourceOperatorAutPtr m_transport_resource_operator;

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
     * @brief Test constants: the names of the lands.
     */
    string m_land_name_1,
           m_land_name_2;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3,
           m_settlement_name_4;

    /**
     * @brief Test constants: identifiers of holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2;
};

/**
 * Component tests of: TransportResourceOperator::transportResource.
 */
TEST_F(TransportResourceOperatorTest, transportResource_TryingToTransportZeroResources)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_TRYING_TO_TRANSPORT_ZERO_RESOURCES,
              m_transport_resource_operator->transportResource(transaction,
                                                               m_settlement_name_1,
                                                               m_settlement_name_2,
                                                               KEY_RESOURCE_COAL,
                                                               0).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_SourceSettlementDoesNotExist)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SOURCE_SETTLEMENT_DOES_NOT_EXIST,
              m_transport_resource_operator->transportResource(transaction,
                                                               m_settlement_name_4,
                                                               m_settlement_name_2,
                                                               KEY_RESOURCE_COAL,
                                                               10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_DestinationSettlementDoesNotExist)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST,
              m_transport_resource_operator->transportResource(transaction,
                                                               m_settlement_name_1,
                                                               m_settlement_name_4,
                                                               KEY_RESOURCE_COAL,
                                                               10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_SettlementsAreNotFromTheSameLand)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND,
              m_transport_resource_operator->transportResource(transaction,
                                                               m_settlement_name_1,
                                                               m_settlement_name_3,
                                                               KEY_RESOURCE_COAL,
                                                               10).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_NotEnoughResources)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
              m_transport_resource_operator->transportResource(transaction,
                                                               m_settlement_name_1,
                                                               m_settlement_name_2,
                                                               KEY_RESOURCE_COAL,
                                                               1001).m_exit_code);
}

TEST_F(TransportResourceOperatorTest, transportResource_Success_OneResource)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_TRANSPORTED,
                  m_transport_resource_operator->transportResource(transaction,
                                                                   m_settlement_name_1,
                                                                   m_settlement_name_2,
                                                                   KEY_RESOURCE_COAL,
                                                                   1).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(999, m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL)->getVolume());
        ASSERT_EQ(1, m_resource_manager->getResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL)->getVolume());
    }
}

TEST_F(TransportResourceOperatorTest, transportResource_Success_ManyResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_TRANSPORTED,
                  m_transport_resource_operator->transportResource(transaction,
                                                                   m_settlement_name_1,
                                                                   m_settlement_name_2,
                                                                   KEY_RESOURCE_COAL,
                                                                   500).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(500, m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL)->getVolume());
        ASSERT_EQ(500, m_resource_manager->getResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL)->getVolume());
    }
}

TEST_F(TransportResourceOperatorTest, transportResource_Success_AllResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(TRANSPORT_RESOURCE_OPERATOR_EXIT_CODE_RESOURCE_HAS_BEEN_TRANSPORTED,
                  m_transport_resource_operator->transportResource(transaction,
                                                                   m_settlement_name_1,
                                                                   m_settlement_name_2,
                                                                   KEY_RESOURCE_COAL,
                                                                   1000).m_exit_code);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_resource_manager->getResource(transaction, m_id_holder_1, KEY_RESOURCE_COAL) == NULL);
        ASSERT_EQ(1000, m_resource_manager->getResource(transaction, m_id_holder_2, KEY_RESOURCE_COAL)->getVolume());
    }
}
