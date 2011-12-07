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

#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../../GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../ComponentTest.hpp"
#include <GameServer/Building/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
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
class BuildingPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    BuildingPersistenceFacadeTest()
        : m_context(new Context),
          m_epoch_name("Epoch"),
          m_login("Login"),
          m_world_name("World"),
          m_land_name("Land"),
          m_settlement_name_1("Settlement1"),
          m_settlement_name_2("Settlement2"),
          m_settlement_name_3("Settlement3"),
          m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql(m_context)),
          m_user_persistence_facade(m_persistence_facade_abstract_factory->createUserPersistenceFacade()),
          m_world_persistence_facade(m_persistence_facade_abstract_factory->createWorldPersistenceFacade()),
          m_epoch_persistence_facade(m_persistence_facade_abstract_factory->createEpochPersistenceFacade()),
          m_land_persistence_facade(m_persistence_facade_abstract_factory->createLandPersistenceFacade()),
          m_building_persistence_facade(m_persistence_facade_abstract_factory->createBuildingPersistenceFacade()),
          m_create_settlement_operator(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_persistence_facade_abstract_factory)),
          m_id_holder_1(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_1),
          m_id_holder_2(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_2),
          m_id_holder_3(ID_HOLDER_CLASS_SETTLEMENT, m_settlement_name_3)
    {
        {
            IConnectionShrPtr connection = m_persistence.getConnection();
            ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

            m_user_persistence_facade->createUser(transaction, "Login", "Password");

            m_world_persistence_facade->createWorld(transaction, m_world_name);

            m_epoch_persistence_facade->createEpoch(transaction, m_world_name, m_epoch_name);

            m_land_persistence_facade->createLand(transaction, m_login, m_world_name, m_land_name);

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
        IKey                     const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_building->getBuilding()->getKey());
        ASSERT_EQ(a_volume, a_building->getVolume());
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
     * @brief The abstract factory of persistence facades.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief The persistence facade of users.
     */
    IUserPersistenceFacadeShrPtr m_user_persistence_facade;

    /**
     * @brief The world persistence facade.
     */
    IWorldPersistenceFacadeShrPtr m_world_persistence_facade;

    /**
     * @brief The epoch persistence facade.
     */
    IEpochPersistenceFacadeShrPtr m_epoch_persistence_facade;

    /**
     * @brief The land persistence facade.
     */
    ILandPersistenceFacadeShrPtr m_land_persistence_facade;

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
 * Component tests of: BuildingPersistenceFacade::addBuilding.
 */
TEST_F(BuildingPersistenceFacadeTest, addBuilding_BuildingIsNotPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, addBuilding_BuildingIsPresent)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 22);
    }
}

TEST_F(BuildingPersistenceFacadeTest, addBuilding_BuildingIsPresent_DifferentBuilding)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
        compareBuilding(buildings[KEY_REGULAR_MARKETPLACE], KEY_REGULAR_MARKETPLACE, 22);
    }

}
/**
 * Component tests of: BuildingPersistenceFacade::subtractBuilding.
 */
TEST_F(BuildingPersistenceFacadeTest, subtractBuilding_BuildingsArePresent_SubtractAllOfOneBuildingAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, subtractBuilding_BuildingIsPresent_SubtractHalfAtOnce)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, subtractBuilding_BuildingsIsPresent_TryToSubtractToMuch)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_FALSE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 12));
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, subtractBuilding_BuildingsIsPresent_SubtractRest)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        ASSERT_TRUE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11));

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingPersistenceFacadeTest, subtractBuilding_BuildingsIsNotPresent_TryToSubtract)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    ASSERT_FALSE(m_building_persistence_facade->subtractBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11));
}

/**
 * Component tests of: BuildingPersistenceFacade::getBuilding.
 */
TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsNotPresent)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM);

    ASSERT_TRUE(building == NULL);
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM);

        ASSERT_FALSE(building == NULL);
        compareBuilding(building, KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_2, KEY_REGULAR_FARM);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetPresentBuilding_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_3, KEY_REGULAR_FARM);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_2, KEY_REGULAR_MARKETPLACE);

        ASSERT_TRUE(building == NULL);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuilding_BuildingIsPresent_GetNonPresentBuilding_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeShrPtr building = m_building_persistence_facade->getBuilding(transaction, m_id_holder_3, KEY_REGULAR_MARKETPLACE);

        ASSERT_TRUE(building == NULL);
    }
}

/**
 * Component tests of: BuildingPersistenceFacade::getBuildings.
 */
TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsAreNotPresent_ExistentHolder)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsAreNotPresent_NonExistentHolder)
{
    IConnectionShrPtr connection = m_persistence.getConnection();
    ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

    BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

    ASSERT_TRUE(buildings.empty());
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingIsPresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingIsPresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingIsPresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_OfHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
        compareBuilding(buildings[KEY_REGULAR_MARKETPLACE], KEY_REGULAR_MARKETPLACE, 22);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_OfDifferentHolder_ExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_OfDifferentHolder_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_TwoHolders_OfFirstHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_REGULAR_FARM, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_1);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(2, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 11);
        compareBuilding(buildings[KEY_REGULAR_MARKETPLACE], KEY_REGULAR_MARKETPLACE, 22);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_TwoHolders_OfSecondHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_REGULAR_FARM, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_2);

        ASSERT_FALSE(buildings.empty());
        ASSERT_EQ(1, buildings.size());
        compareBuilding(buildings[KEY_REGULAR_FARM], KEY_REGULAR_FARM, 33);
    }
}

TEST_F(BuildingPersistenceFacadeTest, getBuildings_BuildingsArePresent_TwoHolders_NonExistentHolder)
{
    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_FARM, 11);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_1, KEY_REGULAR_MARKETPLACE, 22);
        m_building_persistence_facade->addBuilding(transaction, m_id_holder_2, KEY_REGULAR_FARM, 33);

        transaction->commit();
    }

    {
        IConnectionShrPtr connection = m_persistence.getConnection();
        ITransactionShrPtr transaction = m_persistence.getTransaction(connection);

        BuildingWithVolumeMap buildings = m_building_persistence_facade->getBuildings(transaction, m_id_holder_3);

        ASSERT_TRUE(buildings.empty());
    }
}
