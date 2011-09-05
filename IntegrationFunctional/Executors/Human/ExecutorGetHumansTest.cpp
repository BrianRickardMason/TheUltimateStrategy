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

#include "../../../GameServer/Common/IDHolder.hpp"
#include "../../../GameServer/Human/IDHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioActivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioCreateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioDeactivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Human/ScenarioEngageHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Human/ScenarioGetHumans.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Land/ScenarioCreateLand.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Settlement/ScenarioCreateSettlement.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/User/ScenarioCreateUser.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/World/ScenarioCreateWorld.hpp"
#include "../../Helpers/IntegrationFunctionalTest.hpp"
#include "../../Helpers/XmlRPCClient/ClientSynchronous/ClientSynchronous.hpp"

using namespace GameServer::Common;
using namespace GameServer::Human;
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
 * Integration functional tests of: ExecutorGetLands.
 */
TEST_F(IntegrationFunctionalTest, GetHumans_SettlementDoesNotExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_Unauthorized)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login1", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login2", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(2, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_ManyHumans)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                1, "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationHumanHasBeenEngaged))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationHumansHaveBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_OneHuman)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationHumansHaveBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_ZeroHumans)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement2")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 2)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationHumansHaveBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_InvalidRequest)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionInvalidRequest(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationInvalidRequest))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_InvalidRange)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_TROOP + 1, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationInvalidRange))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_Unauthenticated)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password2", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationUnauthenticated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHumans_EpochIsNotActive)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess(1, "Password", 1, 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess(1, "Password", 1, "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioDeactivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioDeactivateEpochActionSuccess(1)),
            IScenarioVerificationShrPtr(new ScenarioDeactivateEpochVerificationEpochHasBeenDeactivated))))
        (IScenarioShrPtr(new ScenarioGetHumans(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumansActionSuccess(1, "Password", ID_HOLDER_CLASS_SETTLEMENT, 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumansVerificationEpochIsNotActive))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}
