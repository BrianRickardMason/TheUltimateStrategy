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

#include <TUSGame/GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp>
#include <TUSGame/GameServer/Human/Operators/DismissHuman/DismissHumanOperatorFactory.hpp>
#include <TUSGame/GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp>
#include <TUSGame/GameServerCT/ComponentTest.hpp>
#include <TUSGame/GameServerCT/Helpers/Constants.hpp>
#include <TUSGame/GameServer/Human/Key.hpp>
#include <TUSGame/GameServer/Resource/Key.hpp>
#include <TUSCore/Network/XmlRPCServer/Context.hpp>
#include <boost/assign.hpp>

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace boost;
using namespace std;

namespace R = GameServer::Resource;

/**
 * @brief A test class.
 */
class DismissHumanOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    DismissHumanOperatorTest()
        : m_context(new Context),
          m_epoch_name("Epoch"),
          m_login_1("Login1"),
          m_login_2("Login2"),
          m_world_name("World"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_settlement_name_4("Settlement5"),
          m_id_holder_11(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_12(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_21(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3),
          m_id_holder_4(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_4),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql(m_context)),
          m_epoch_persistence_facade(m_persistence_facade_abstract_factory->createEpochPersistenceFacade()),
          m_human_persistence_facade(m_persistence_facade_abstract_factory->createHumanPersistenceFacade()),
          m_land_persistence_facade(m_persistence_facade_abstract_factory->createLandPersistenceFacade()),
          m_resource_persistence_facade(m_persistence_facade_abstract_factory->createResourcePersistenceFacade()),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_persistence_facade_abstract_factory->createWorldPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_persistence_facade_abstract_factory)),
          m_dismiss_human_operator(
              DismissHumanOperatorFactory::createDismissHumanOperator(m_context, m_persistence_facade_abstract_factory)
          )
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persistence_facade->createUser(transaction, "Login1", "Password");
            m_user_persistence_facade->createUser(transaction, "Login2", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login_1, m_world_name, m_land_name_1);
            m_land_persistence_facade->createLand(transaction, m_login_2, m_world_name, m_land_name_2);

            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_2);
            m_create_settlement_operator->createSettlement(transaction, m_land_name_2, m_settlement_name_3);

            transaction->commit();
        }
    }

    /**
     * @brief Compares a map of resources with expected volumes.
     *
     * @param a_resource_map The map of resources to be compared.
     * @param a_volumes      A vector of expected volumes.
     *
     * TODO: Consider moving to helpers.
     */
    void compareResourceMap(
        ResourceWithVolumeMap const & a_resource_map,
        vector<R::Volume>     const & a_vector
    )
    {
        for (ResourceWithVolumeMap::const_iterator it = a_resource_map.begin(); it != a_resource_map.end(); ++it)
        {
            // TODO: Enable this assertion.
            // ASSERT_EQ(a_vector.at(it->second->getResource()->getKey() - 1), it->second->getVolume());
        }
    }

    /**
     * @brief Asserts that database remains untouched.
     */
    void assertDatabaseUntouched()
    {
        vector<R::Volume> expected_volumes_1 = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000);
        vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ResourceWithVolumeMap
                resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
                resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
                resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

            compareResourceMap(resource_map_11, expected_volumes_1);
            compareResourceMap(resource_map_12, expected_volumes_2);
            compareResourceMap(resource_map_21, expected_volumes_1);

            ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_11).size());
            ASSERT_TRUE(m_human_persistence_facade->getHumans(transaction, m_id_holder_12).empty());
            ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_21).size());

            ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
            ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_21, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        }
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief Test constants: the name of the epoch.
     */
    string m_epoch_name;

    /**
     * @brief Test constants: the logins of the users.
     */
    string m_login_1,
           m_login_2;

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
     * @brief Test constants identifiers of a holder.
     */
    IDHolder m_id_holder_11,
             m_id_holder_12,
             m_id_holder_21,
             m_id_holder_4;

    /**
     * @brief An abstract factory used in tests.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    //@{
    /**
     * @brief A persistence facade used in tests.
     */
    IEpochPersistenceFacadeShrPtr    m_epoch_persistence_facade;
    IHumanPersistenceFacadeShrPtr    m_human_persistence_facade;
    ILandPersistenceFacadeShrPtr     m_land_persistence_facade;
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    IUserPersistenceFacadeShrPtr     m_user_persistence_facade;
    IWorldPersistenceFacadeShrPtr    m_world_persistence_facade;
    //}@

    //@{
    /**
     * @brief An operator used in tests.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;
    IDismissHumanOperatorShrPtr     m_dismiss_human_operator;
    //}@
};

/**
 * Component tests of: DismissHumanOperator::dismissHuman.
 */
TEST_F(DismissHumanOperatorTest, dismissHuman_TryingToDismissZeroHumans)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_DISMISS_ZERO_HUMANS,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 0).m_exit_code);
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_HolderDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_4, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_HumanIsNotDismissable)
{
    for (KeyVec::const_iterator it = HUMAN_IS_NOT_DISMISSABLE.begin(); it != HUMAN_IS_NOT_DISMISSABLE.end(); ++it)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_DISMISSABLE,
                      m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE, 1).m_exit_code);
        }

        assertDatabaseUntouched();
    }
}

TEST_F(DismissHumanOperatorTest, dismissHuman_ZeroEngaged)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughEngaged)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 2).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_ZeroResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_12, KEY_WORKER_BREEDER_NOVICE, 10);

        // TODO: Subtract map of resources.
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 10000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 10000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 1000);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 1000);

        transaction->commit();
    }

    vector<IDHolder> ids = assign::list_of(IDHolder(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1))
                                          (IDHolder(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2));

    for (vector<IDHolder>::const_iterator it = ids.begin(); it != ids.end(); ++it)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                      m_dismiss_human_operator->dismissHuman(transaction, *it, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
        }
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);
        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_12, KEY_WORKER_BREEDER_NOVICE, 10);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 10000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 10000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 1000);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 1000);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_AllResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        // TODO: Subtract map of resources.
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 9999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 9999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_FOOD, 9999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 9999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_IRON, 999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_ROCK, 999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_SomeResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        // TODO: Subtract map of resources.
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 9999);
        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_COAL, 999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_GOLD, 9999);
        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_NotEnoughResources_OneResource)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        m_resource_persistence_facade->subtractResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->subtractHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        m_resource_persistence_facade->addResource(transaction, m_id_holder_11, KEY_RESOURCE_WOOD, 999);

        transaction->commit();
    }

    assertDatabaseUntouched();
}

TEST_F(DismissHumanOperatorTest, dismissHuman_One)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 1).m_exit_code);

        transaction->commit();
    }

    vector<R::Volume> expected_volumes_1 = assign::list_of(990)(9990)(9990)(990)(990)(990);
    vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);
    vector<R::Volume> expected_volumes_3 = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000);

    {
        IConnectionShrPtr connection = m_persistence.getConnection();

        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap
            resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
            resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
            resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

        compareResourceMap(resource_map_11, expected_volumes_1);
        compareResourceMap(resource_map_12, expected_volumes_2);
        compareResourceMap(resource_map_21, expected_volumes_3);

        ASSERT_EQ(2, m_human_persistence_facade->getHumans(transaction, m_id_holder_11).size());
        ASSERT_TRUE(m_human_persistence_facade->getHumans(transaction, m_id_holder_12).empty());
        ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_21).size());

        ASSERT_EQ(9, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE)->getVolume());
        ASSERT_EQ(1001, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_21, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}

TEST_F(DismissHumanOperatorTest, dismissHuman_Some)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 6).m_exit_code);

        transaction->commit();
    }

    vector<R::Volume> expected_volumes_1 = assign::list_of(940)(9940)(9940)(940)(940)(940);
    vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);
    vector<R::Volume> expected_volumes_3 = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000);

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap
            resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
            resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
            resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

        compareResourceMap(resource_map_11, expected_volumes_1);
        compareResourceMap(resource_map_12, expected_volumes_2);
        compareResourceMap(resource_map_21, expected_volumes_3);

        ASSERT_EQ(2, m_human_persistence_facade->getHumans(transaction, m_id_holder_11).size());
        ASSERT_TRUE(m_human_persistence_facade->getHumans(transaction, m_id_holder_12).empty());
        ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_21).size());

        ASSERT_EQ(4, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE)->getVolume());
        ASSERT_EQ(1006, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_21, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}

TEST_F(DismissHumanOperatorTest, dismissHuman_Max_OnEngaged)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 10).m_exit_code);

        transaction->commit();
    }

    vector<R::Volume> expected_volumes_1 = assign::list_of(900)(9900)(9900)(900)(900)(900);
    vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);
    vector<R::Volume> expected_volumes_3 = assign::list_of(1000)(10000)(10000)(10000)(1000)(1000);

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap
            resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
            resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
            resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

        compareResourceMap(resource_map_11, expected_volumes_1);
        compareResourceMap(resource_map_12, expected_volumes_2);
        compareResourceMap(resource_map_21, expected_volumes_3);

        ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_11).size());
        ASSERT_TRUE(m_human_persistence_facade->getHumans(transaction, m_id_holder_12).empty());
        ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_21).size());

        ASSERT_EQ(1010, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_21, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}

TEST_F(DismissHumanOperatorTest, dismissHuman_Max_OnResources)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 200);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED,
                  m_dismiss_human_operator->dismissHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE, 100).m_exit_code);

        transaction->commit();
    }

    vector<R::Volume> expected_volumes_1 = assign::list_of(0)(9000)(9000)(0)(0)(0);
    vector<R::Volume> expected_volumes_2 = assign::list_of(0)(0)(0)(0)(0)(0);
    vector<R::Volume> expected_volumes_3 = assign::list_of(1000)(10000)(10000)(1000)(1000)(1000);

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ResourceWithVolumeMap
            resource_map_11 = m_resource_persistence_facade->getResources(transaction, m_id_holder_11),
            resource_map_12 = m_resource_persistence_facade->getResources(transaction, m_id_holder_12),
            resource_map_21 = m_resource_persistence_facade->getResources(transaction, m_id_holder_21);

        compareResourceMap(resource_map_11, expected_volumes_1);
        compareResourceMap(resource_map_12, expected_volumes_2);
        compareResourceMap(resource_map_21, expected_volumes_3);

        ASSERT_EQ(2, m_human_persistence_facade->getHumans(transaction, m_id_holder_11).size());
        ASSERT_TRUE(m_human_persistence_facade->getHumans(transaction, m_id_holder_12).empty());
        ASSERT_EQ(1, m_human_persistence_facade->getHumans(transaction, m_id_holder_21).size());

        ASSERT_EQ(100, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_BREEDER_NOVICE)->getVolume());
        ASSERT_EQ(1100, m_human_persistence_facade->getHuman(transaction, m_id_holder_11, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
        ASSERT_EQ(1000, m_human_persistence_facade->getHuman(transaction, m_id_holder_21, KEY_WORKER_JOBLESS_NOVICE)->getVolume());
    }
}
