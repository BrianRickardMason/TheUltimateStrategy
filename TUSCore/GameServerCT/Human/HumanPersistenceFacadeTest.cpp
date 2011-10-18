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
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

/**
 * @brief A test class.
 */
class HumanPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    HumanPersistenceFacadeTest()
        : m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_epoch_persistence_facade(m_manager_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_manager_abstract_factory->createLandPersistenceFacade()),
          m_user_persitence_facade(m_manager_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_manager_abstract_factory->createWorldPersistenceFacade()),
          m_human_persistence_facade(m_manager_abstract_factory->createHumanPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory)),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_3(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persitence_facade->createUser(transaction, "Login", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name);

            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_2);

            // Remove humans that have been added.
            m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_WORKER_JOBLESS_NOVICE, 1000);
            m_human_persistence_facade->subtractHuman(transaction, m_id_holder_2, KEY_WORKER_JOBLESS_NOVICE, 1000);

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
        HumanWithVolumeShrPtr        a_human,
        Key                  const & a_key,
        Volume               const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_human->getKey());
        ASSERT_EQ(a_volume, a_human->getVolume());
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
     * @brief Test constants: the name of the land.
     */
    string m_land_name;

    /**
     * @brief Test constants: the names of the settlements.
     */
    string m_settlement_name_1,
           m_settlement_name_2,
           m_settlement_name_3;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    //@{
    /**
     * @brief Persistence facades used in tests.
     */
    IEpochPersistenceFacadeShrPtr m_epoch_persistence_facade;
    IHumanPersistenceFacadeShrPtr m_human_persistence_facade;
    ILandPersistenceFacadeShrPtr  m_land_persistence_facade;
    IUserPersistenceFacadeShrPtr  m_user_persitence_facade;
    IWorldPersistenceFacadeShrPtr m_world_persistence_facade;
    //}@

    /**
     * @brief Operators used in tests.
     */
    ICreateSettlementOperatorShrPtr m_create_settlement_operator;

    /**
     * @brief Exemplary id holders.
     */
    IDHolder m_id_holder_1,
             m_id_holder_2,
             m_id_holder_3;
};

/**
 * Component tests of: HumanPersistenceFacade::addHuman.
 */
TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 22);
    }
}

TEST_F(HumanPersistenceFacadeTest, addHuman_HumanIsPresent_DifferentHuman)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(2, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
        compareHuman(humans[KEY_SORCERER_EARTH_ADVANCED], KEY_SORCERER_EARTH_ADVANCED, 22);
    }
}

/**
 * Component tests of: HumanPersistenceFacade::subtractHuman.
 */
TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumansArePresent_SubtractAllOfOneHumanAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumanIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumansIsPresent_TryToSubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 12));
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumansIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, subtractHuman_HumansIsNotPresent_TryToSubtract)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_human_persistence_facade->subtractHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11));
    }
}

/**
 * Component tests of: HumanPersistenceFacade::getHuman.
 */
TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE);

        ASSERT_TRUE(human == NULL);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetPresentHuman_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE);

        ASSERT_FALSE(human == NULL);
        compareHuman(human, KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetPresentHuman_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE);

        ASSERT_TRUE(human == NULL);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetPresentHuman_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_3, KEY_SOLDIER_ARCHER_NOVICE);

        ASSERT_TRUE(human == NULL);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetNonPresentHuman_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED);

        ASSERT_TRUE(human == NULL);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetNonPresentHuman_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_2, KEY_SORCERER_EARTH_ADVANCED);

        ASSERT_TRUE(human == NULL);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHuman_HumanIsPresent_GetNonPresentHuman_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeShrPtr human = m_human_persistence_facade->getHuman(transaction, m_id_holder_3, KEY_SORCERER_EARTH_ADVANCED);

        ASSERT_TRUE(human == NULL);
    }
}

/**
 * Component tests of: HumanPersistenceFacade::getHumans by short key.
 */
TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansAreNotPresent_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansAreNotPresent_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumanIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumanIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumanIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfHolder_BothOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(2, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
        compareHuman(humans[KEY_SOLDIER_ARCHER_ADVANCED], KEY_SOLDIER_ARCHER_ADVANCED, 22);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfHolder_OneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfHolder_NoneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_HORSEMAN_ADVANCED, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfDifferentHolder_BothOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfDifferentHolder_OneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_OfDifferentHolder_NoneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_HORSEMAN_ADVANCED, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_NonExistentHolder_BothOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_NonExistentHolder_OneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_NonExistentHolder_NoneOfGivenShortKey)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_HORSEMAN_ADVANCED, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(2, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
        compareHuman(humans[KEY_SOLDIER_ARCHER_ADVANCED], KEY_SOLDIER_ARCHER_ADVANCED, 22);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 33);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_ByShortKey_HumansArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3, ID_HUMAN_SOLDIER_ARCHER);

        ASSERT_TRUE(humans.empty());
    }
}

/**
 * Component tests of: HumanPersistenceFacade::getHumans all humans.
 */
TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansAreNotPresent_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansAreNotPresent_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumanIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumanIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumanIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(2, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
        compareHuman(humans[KEY_SORCERER_EARTH_ADVANCED], KEY_SORCERER_EARTH_ADVANCED, 22);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3);

        ASSERT_TRUE(humans.empty());
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_1);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(2, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 11);
        compareHuman(humans[KEY_SORCERER_EARTH_ADVANCED], KEY_SORCERER_EARTH_ADVANCED, 22);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_2);

        ASSERT_FALSE(humans.empty());
        ASSERT_EQ(1, humans.size());
        compareHuman(humans[KEY_SOLDIER_ARCHER_NOVICE], KEY_SOLDIER_ARCHER_NOVICE, 33);
    }
}

TEST_F(HumanPersistenceFacadeTest, getHumans_AllHumans_HumansArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SOLDIER_ARCHER_NOVICE, 11);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_1, KEY_SORCERER_EARTH_ADVANCED, 22);
        m_human_persistence_facade->addHuman(transaction, m_id_holder_2, KEY_SOLDIER_ARCHER_NOVICE, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(transaction, m_id_holder_3);

        ASSERT_TRUE(humans.empty());
    }
}
