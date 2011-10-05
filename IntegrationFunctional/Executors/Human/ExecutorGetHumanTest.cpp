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
// ARE DISCLAIMED. IN NO EVENT SHALL T,HE PROJECT OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include "../../../GameServer/Common/IDHolder.hpp"
#include "../../../GameServer/Human/Experience.hpp"
#include "../../../GameServer/Human/IDHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioActivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioCreateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioDeactivateEpoch.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Human/ScenarioEngageHuman.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/Human/ScenarioGetHuman.hpp"
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
 * Integration functional tests of: ExecutorGetHuman.
 */
TEST_F(IntegrationFunctionalTest, GetHuman_SettlementDoesNotExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_Unauthorized)
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
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login1", "Password1", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login1", "Password1", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login1", "Password1", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login1", "Password1", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login1", "Password1", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login2", "Password2",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationUnauthorized))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_ManyHumansExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioEngageHuman(
            client,
            IScenarioActionShrPtr(new ScenarioEngageHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_DRUID.getValue1(), ID_HUMAN_WORKER_DRUID.getValue2(),
                1)),
            IScenarioVerificationShrPtr(new ScenarioEngageHumanVerificationHumanHasBeenEngaged))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationHumanHasBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_OneHumanExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationHumanHasBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_ZeroHumansExist)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement2")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 2,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationHumanHasBeenGot))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_InvalidRequest)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionInvalidRequest(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationInvalidRequest))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_InvalidRange)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_ADVANCED.getValue() + 1)),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationInvalidRange))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_Unauthenticated)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "BadPassword",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationUnauthenticated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, GetHuman_EpochIsNotActive)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", 1, "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateSettlement(
            client,
            IScenarioActionShrPtr(new ScenarioCreateSettlementActionSuccess("Login", "Password", "Land", "Settlement1")),
            IScenarioVerificationShrPtr(new ScenarioCreateSettlementVerificationSettlementHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioDeactivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioDeactivateEpochActionSuccess("Login", "Password", "World")),
            IScenarioVerificationShrPtr(new ScenarioDeactivateEpochVerificationEpochHasBeenDeactivated))))
        (IScenarioShrPtr(new ScenarioGetHuman(
            client,
            IScenarioActionShrPtr(new ScenarioGetHumanActionSuccess(
                "Login", "Password",
                ID_HOLDER_CLASS_SETTLEMENT, 1,
                ID_HUMAN_WORKER_JOBLESS.getValue1(), ID_HUMAN_WORKER_JOBLESS.getValue2(), EXPERIENCE_NOVICE.getValue())),
            IScenarioVerificationShrPtr(new ScenarioGetHumanVerificationEpochIsNotActive))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}
