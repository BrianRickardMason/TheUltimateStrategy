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
#include "../../../../GameServer/Common/OperatorAbstractFactoryPostgresql.hpp"
#include "../../../ComponentTest.hpp"

using namespace GameServer::Common;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief The test class.
 */
class CreateSettlementOperatorTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    CreateSettlementOperatorTest()
        : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_operator_abstract_factory(new OperatorAbstractFactoryPostgresql),
          m_human_persistence_facade(m_manager_abstract_factory->createHumanPersistenceFacade()),
          m_resource_persistence_facade(m_manager_abstract_factory->createResourcePersistenceFacade()),
          m_create_epoch_operator(m_operator_abstract_factory->createCreateEpochOperator()),
          m_create_land_operator(m_operator_abstract_factory->createCreateLandOperator()),
          m_create_settlement_operator(m_operator_abstract_factory->createCreateSettlementOperator()),
          m_create_user_operator(m_operator_abstract_factory->createCreateUserOperator()),
          m_create_world_operator(m_operator_abstract_factory->createCreateWorldOperator()),
          m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name_1("Land1"),
          m_land_name_2("Land2"),
          m_land_name_3("Land3"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2")
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_create_user_operator->createUser(transaction, "Login", "Password");

            m_create_world_operator->createWorld(transaction, m_world_name);

            m_create_epoch_operator->createEpoch(transaction, m_world_name, m_epoch_name);

            m_create_land_operator->createLand(transaction, m_login, m_world_name, m_land_name_1);
            m_create_land_operator->createLand(transaction, m_login, m_world_name, m_land_name_2);

            transaction->commit();
        }
    }

    /**
     * @brief Compares the human with expected values.
     *
     * @param a_human  The human to be compared.
     * @param a_key    An expected key of the human.
     * @param a_volume An expected volume of the human.
     */
    void compareHuman(
        HumanWithVolumeShrPtr             a_human,
        GameServer::Human::Key    const & a_key,
        GameServer::Human::Volume const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_human->getKey());
        ASSERT_EQ(a_volume, a_human->getVolume());
    }

    /**
     * @brief Compares the resource with expected values.
     *
     * @param a_resource The resource to be compared.
     * @param a_key      An expected key of the resource.
     * @param a_volume   An expected volume of the resource.
     */
    void compareResource(
        ResourceWithVolumeShrPtr             a_resource,
        GameServer::Resource::Key    const & a_key,
        GameServer::Resource::Volume const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_resource->getKey());
        ASSERT_EQ(a_volume, a_resource->getVolume());
    }

    /**
     * @brief Checks whether the grant has been given.
     *
     * @param a_settlement_name The name of the settlement.
     */
    void checkGrantHasBeenGiven(
        string a_settlement_name
    )
    {
        GameServer::Human::Key key(ID_HUMAN_WORKER_JOBLESS, EXPERIENCE_NOVICE);

        IDResource coal(ID_RESOURCE_COAL),
                   food(ID_RESOURCE_FOOD),
                   gold(ID_RESOURCE_GOLD),
                   iron(ID_RESOURCE_IRON),
                   mana(ID_RESOURCE_MANA),
                   rock(ID_RESOURCE_ROCK),
                   wood(ID_RESOURCE_WOOD);

        GameServer::Resource::Key key_coal(coal),
                                  key_food(food),
                                  key_gold(gold),
                                  key_iron(iron),
                                  key_mana(mana),
                                  key_rock(rock),
                                  key_wood(wood);

        IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, id_holder);

            ASSERT_FALSE(humans.empty());
            ASSERT_EQ(1, humans.size());
            compareHuman(humans[key], key, 1000);
        }

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, id_holder);

            ResourceWithVolumeMap resource_map = resource_set.getMap();

            ASSERT_FALSE(resource_map.empty());
            ASSERT_EQ(7, resource_map.size());
            compareResource(resource_map[key_coal], key_coal, 1000);
            compareResource(resource_map[key_food], key_food, 10000);
            compareResource(resource_map[key_gold], key_gold, 10000);
            compareResource(resource_map[key_iron], key_iron, 1000);
            compareResource(resource_map[key_mana], key_mana, 1000);
            compareResource(resource_map[key_rock], key_rock, 1000);
            compareResource(resource_map[key_wood], key_wood, 1000);
        }
    }

    /**
     * @brief Checks whether the grant has not been given.
     *
     * @param a_settlement_name The name of the settlement.
     */
    void checkGrantHasNotBeenGiven(
        string a_settlement_name
    )
    {
        IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, id_holder);

            ASSERT_TRUE(humans.empty());
        }

        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            ResourceSet resource_set = m_resource_persistence_facade->getResources(transaction, id_holder);

            ResourceWithVolumeMap resource_map = resource_set.getMap();

            ASSERT_FALSE(resource_map.empty());

            ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

            compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
            compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
            compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
            compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
            compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
            compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
            compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
        }
    }

    //@{
    /**
     * @brief An abstract factory used in tests.
     */
    IManagerAbstractFactoryShrPtr  m_manager_abstract_factory;
    IOperatorAbstractFactoryShrPtr m_operator_abstract_factory;
    //}@

    //@{
    /**
     * @brief A persistence facade used in tests.
     */
    IHumanPersistenceFacadeShrPtr    m_human_persistence_facade;
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    //}@

    //@{
    /**
     * @brief An operator used in tests.
     */
    ICreateEpochOperatorShrPtr      m_create_epoch_operator;
    ICreateLandOperatorShrPtr       m_create_land_operator;
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;
    ICreateUserOperatorShrPtr       m_create_user_operator;
    ICreateWorldOperatorShrPtr      m_create_world_operator;
    //}@

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
           m_land_name_2,
           m_land_name_3;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2;
};

/**
 * Component tests of: CreateSettlementOperator::createSettlement.
 */
TEST_F(CreateSettlementOperatorTest, createSettlement_LandDoesNotExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST,
                  m_create_settlement_operator->createSettlement(transaction, m_land_name_3, m_settlement_name_1).m_exit_code);
    }
}

TEST_F(CreateSettlementOperatorTest, createSettlement_SettlementDoesExist)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_DOES_EXIST,
                  m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1).m_exit_code);
    }
}

TEST_F(CreateSettlementOperatorTest, createSettlement_FirstSettlementOfLand)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_CREATED,
                  m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1).m_exit_code);

        transaction->commit();
    }

    checkGrantHasBeenGiven(m_settlement_name_1);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_SecondSettlementOfLand)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_CREATED,
                  m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_2).m_exit_code);

        transaction->commit();
    }

    checkGrantHasNotBeenGiven(m_settlement_name_2);
}

TEST_F(CreateSettlementOperatorTest, createSettlement_FirstSettlmentOfAnotherLandTheSameNames)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_create_settlement_operator->createSettlement(transaction, m_land_name_1, m_settlement_name_1);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_EQ(CREATE_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_DOES_EXIST,
                  m_create_settlement_operator->createSettlement(transaction, m_land_name_2, m_settlement_name_1).m_exit_code);

        transaction->commit();
    }

    checkGrantHasBeenGiven(m_settlement_name_1);
}
