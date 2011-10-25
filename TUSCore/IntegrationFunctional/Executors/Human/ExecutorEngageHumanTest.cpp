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

#include "../../../GameServer/Building/IDBuilding.hpp"
#include "../../../GameServer/Common/IDHolder.hpp"
#include "../../../GameServer/Human/IDHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Building/ScenarioBuildBuilding.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioActivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioCreateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioDeactivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Human/ScenarioEngageHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Land/ScenarioCreateLand.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Settlement/ScenarioCreateSettlement.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/User/ScenarioCreateUser.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/World/ScenarioCreateWorld.hpp"
#include "../../Helpers/IntegrationFunctionalTest.hpp"
#include "../../Helpers/XmlRPCClient/ClientSynchronous/ClientSynchronous.hpp"

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace IntegrationCommon::Helpers::Scenarios::Building;
using namespace IntegrationCommon::Helpers::Scenarios::Epoch;
using namespace IntegrationCommon::Helpers::Scenarios::Human;
using namespace IntegrationCommon::Helpers::Scenarios::Land;
using namespace IntegrationCommon::Helpers::Scenarios::Settlement;
using namespace IntegrationCommon::Helpers::Scenarios::User;
using namespace IntegrationCommon::Helpers::Scenarios::World;
using namespace IntegrationCommon::Helpers::Scenarios;
using namespace boost::assign;
using namespace std;

/**
 * Integration functional tests of: ExecutorEngageHuman.
 */
TEST_F(IntegrationFunctionalTest, EngageHuman_SettlementDoesNotExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_SOLDIER_ARCHER.getValue1(), ID_HUMAN_SOLDIER_ARCHER.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

// TODO: Implement me!
//TEST_F(IntegrationFunctionalTest, EngageHuman_NotEnoughJobless)
//{
//}

TEST_F(IntegrationFunctionalTest, EngageHuman_NotEnoughResources)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioBuildBuilding(
            client,
            IScenarioActionShrPtr(new ScenarioBuildBuildingActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_BUILDING_DEFENSIVE_BARBICAN.getValue1(), ID_BUILDING_DEFENSIVE_BARBICAN.getValue2(),
                50)),
            IScenarioVerificationShrPtr(new ScenarioBuildBuildingVerificationBuildingHasBeenBuilt))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                90)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationNotEnoughResources))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_NotEnoughBuildings)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioBuildBuilding(
            client,
            IScenarioActionShrPtr(new ScenarioBuildBuildingActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_BUILDING_DEFENSIVE_BARBICAN.getValue1(), ID_BUILDING_DEFENSIVE_BARBICAN.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioBuildBuildingVerificationBuildingHasBeenBuilt))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_SOLDIER_ARCHER.getValue1(), ID_HUMAN_SOLDIER_ARCHER.getValue2(),
                11)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationNotEnoughBuildings))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_MaxHumans)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                100)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationHumanHasBeenEngaged))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_ManyHumans)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                80)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationHumanHasBeenEngaged))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_OneHuman)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationHumanHasBeenEngaged))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_ZeroHumans)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                0)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationTryingToEngageZeroHumans))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_InvalidRequest)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionInvalidRequest(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationInvalidRequest))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_InvalidRange)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_TROOP + 1, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationInvalidRange))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_Unauthenticated)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "BadPassword",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationUnauthenticated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_Unauthorized)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login1", "Password1")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login2", "Password2")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login1", "Password1", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login1", "Password1", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login1", "Password1", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login1", "Password1", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login2", "Password2",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_SOLDIER_ARCHER.getValue1(), ID_HUMAN_SOLDIER_ARCHER.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, EngageHuman_EpochIsNotActive)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioDeactivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioDeactivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioDeactivateEpochVerificationEpochHasBeenDeactivated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, "Settlement",
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationEpochIsNotActive))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}
