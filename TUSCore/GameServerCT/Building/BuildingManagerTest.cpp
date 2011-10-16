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

using namespace GameServer::Building;
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
class BuildingManagerTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    BuildingManagerTest()
        : m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
          m_user_manager(m_manager_abstract_factory->createUserManager()),
          m_world_manager(m_manager_abstract_factory->createWorldManager()),
          m_epoch_manager(m_manager_abstract_factory->createEpochManager()),
          m_land_manager(m_manager_abstract_factory->createLandManager()),
          m_building_persistence_facade(m_manager_abstract_factory->createBuildingPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory)),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_3(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_manager->createUser(transaction, "Login", "Password");

            m_world_manager->createWorld(transaction, m_world_name);

            m_epoch_manager->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_manager->createLand(transaction, m_login, m_world_name, m_land_name);

            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_1);
            m_create_settlement_operator->createSettlement(transaction, m_land_name, m_settlement_name_2);

            transaction->commit();
        }
    }

    /**
     * @brief Compares the building with expected values.
     *
     * @param a_building The building to be compared.
     * @param a_key      An expected key of the building.
     * @param a_volume   An expected volume of the building.
     */
    void compareBuilding(
        BuildingWithVolumeShrPtr         a_building,
        Key                      const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_building->getKey());
        ASSERT_EQ(a_volume, a_building->getVolume());
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
     * @brief A building persistence facade.
     */
    IBuildingPersistenceFacadeShrPtr m_building_persistence_facade;

    /**
     * @brief CreateSettlementOperator.
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
 * Component tests of: BuildingManager::addBuilding.
 */
TEST_F(BuildingManagerTest, addBuilding_BuildingIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 22);
    }
}

TEST_F(BuildingManagerTest, addBuilding_BuildingIsPresent_DifferentBuilding)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
        compareBuilding(buildings[KEY_GOLD_ALTAR_OF_WISHES], KEY_GOLD_ALTAR_OF_WISHES, 22);
    }

}
/**
 * Component tests of: BuildingManager::subtractBuilding.
 */
TEST_F(BuildingManagerTest, subtractBuilding_BuildingsArePresent_SubtractAllOfOneBuildingAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingsIsPresent_TryToSubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 12));
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingsIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingManagerTest, subtractBuilding_BuildingsIsNotPresent_TryToSubtract)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_FALSE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11));
}

/**
 * Component tests of: BuildingManager::getBuilding.
 */
TEST_F(BuildingManagerTest, getBuilding_BuildingIsNotPresent)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN);

    ASSERT_TRUE(building == NULL);
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN);

        ASSERT_FALSE(building == NULL);
        compareBuilding(building, KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_2, KEY_DEFENSIVE_BARBICAN);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_3, KEY_DEFENSIVE_BARBICAN);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_2, KEY_GOLD_ALTAR_OF_WISHES);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingManagerTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_3, KEY_GOLD_ALTAR_OF_WISHES);

        ASSERT_TRUE(building == NULL);
    }
}

/**
 * Component tests of: BuildingManager::getBuildings.
 */
TEST_F(BuildingManagerTest, getBuildings_BuildingsAreNotPresent_ExistentHolder)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsAreNotPresent_NonExistentHolder)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingManagerTest, getBuildings_BuildingIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
        compareBuilding(buildings[KEY_GOLD_ALTAR_OF_WISHES], KEY_GOLD_ALTAR_OF_WISHES, 22);
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_DEFENSIVE_BARBICAN, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 11);
        compareBuilding(buildings[KEY_GOLD_ALTAR_OF_WISHES], KEY_GOLD_ALTAR_OF_WISHES, 22);
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_DEFENSIVE_BARBICAN, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_DEFENSIVE_BARBICAN], KEY_DEFENSIVE_BARBICAN, 33);
    }
}

TEST_F(BuildingManagerTest, getBuildings_BuildingsArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_DEFENSIVE_BARBICAN, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_GOLD_ALTAR_OF_WISHES, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_DEFENSIVE_BARBICAN, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}
