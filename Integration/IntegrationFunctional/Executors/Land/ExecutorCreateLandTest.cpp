// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <Integration/IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioActivateEpoch.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/Epoch/ScenarioCreateEpoch.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/Land/ScenarioCreateLand.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/User/ScenarioCreateUser.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/World/ScenarioCreateWorld.hpp>
#include <Integration/IntegrationFunctional/Helpers/IntegrationFunctionalTest.hpp>
#include <Integration/IntegrationFunctional/Helpers/XmlRPCClient/ClientSynchronous/ClientSynchronous.hpp>

using namespace IntegrationCommon::Helpers::Scenarios::Epoch;
using namespace IntegrationCommon::Helpers::Scenarios::Land;
using namespace IntegrationCommon::Helpers::Scenarios::User;
using namespace IntegrationCommon::Helpers::Scenarios::World;
using namespace IntegrationCommon::Helpers::Scenarios;
using namespace boost::assign;
using namespace std;

/**
 * Integration functional tests of: ExecutorCreateLand.
 */
TEST_F(IntegrationFunctionalTest, CreateLand)
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
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLandTwoLandsOfDifferentNames)
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
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login1", "Password", "World", "Land1")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login2", "Password", "World", "Land2")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_TwoLandsOfTheSameName)
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
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationAnotherLandOfTheGivenNameExists))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_TwoLandsOfTheSameNameDifferentUsers)
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
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login1", "Password1", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login2", "Password2", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationAnotherLandOfTheGivenNameExists))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_TwoLandsOfTheSameNameDifferentWorlds)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateUser(
            client,
            IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess("Login", "Password")),
            IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World1")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World2")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World1", "Epoch1")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World2", "Epoch2")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World1")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World2")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World1", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World2", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationAnotherLandOfTheGivenNameExists))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_TwoLandsOfTheSameNameDifferentUsersDifferentWorlds)
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
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World1")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateWorld(
            client,
            IScenarioActionShrPtr(new ScenarioCreateWorldActionSuccess("modbot", "modbotpass", "World2")),
            IScenarioVerificationShrPtr(new ScenarioCreateWorldVerificationWorldHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World1", "Epoch1")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World2", "Epoch2")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World1")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World2")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login1", "Password1", "World1", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationLandHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login2", "Password2", "World2", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationAnotherLandOfTheGivenNameExists))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_Unauthenticated)
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
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioActivateEpoch(
            client,
            IScenarioActionShrPtr(new ScenarioActivateEpochActionSuccess("modbot", "modbotpass", "World")),
            IScenarioVerificationShrPtr(new ScenarioActivateEpochVerificationEpochHasBeenActivated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "BadPassword", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationUnauthenticated))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_InvalidRequest)
{
    IClientShrPtr client(new Client(m_io_service, "localhost", "2222"));

    m_scenarios = list_of
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionInvalidRequest("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationInvalidRequest))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}

TEST_F(IntegrationFunctionalTest, CreateLand_EpochIsNotActive)
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
            IScenarioActionShrPtr(new ScenarioCreateEpochActionSuccess("modbot", "modbotpass", "World", "Epoch")),
            IScenarioVerificationShrPtr(new ScenarioCreateEpochVerificationEpochHasBeenCreated))))
        (IScenarioShrPtr(new ScenarioCreateLand(
            client,
            IScenarioActionShrPtr(new ScenarioCreateLandActionSuccess("Login", "Password", "World", "Land")),
            IScenarioVerificationShrPtr(new ScenarioCreateLandVerificationEpochIsNotActive))));

    for (vector<IScenarioShrPtr>::iterator it = m_scenarios.begin(); it != m_scenarios.end(); ++it)
    {
        ASSERT_STREQ("", (*it)->execute());
    }
}
