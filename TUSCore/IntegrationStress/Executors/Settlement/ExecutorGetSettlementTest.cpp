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

#include "../../../IntegrationCommon/Helpers/Scenarios/Settlement/ScenarioGetSettlement.hpp"
#include "../../../IntegrationCommon/Helpers/Scenarios/User/ScenarioCreateUser.hpp"
#include "../../Helpers/IntegrationStressTest.hpp"
#include "../../Helpers/XmlRPCClient/ClientSynchronous/ClientSynchronous.hpp"

using namespace IntegrationCommon::Helpers::Scenarios::Settlement;
using namespace IntegrationCommon::Helpers::Scenarios::User;
using namespace IntegrationCommon::Helpers::Scenarios;
using namespace boost::assign;
using namespace boost;
using namespace std;

/**
 * @brief A base test class.
 */
class IntegrationStressExecutorGetSettlementTest
    : public IntegrationStressTest
{
public:
    /**
     * @brief A method to be passed to the thread.
     *
     * @param a_thread_seq_number The sequential number of the thread.
     * @param a_thread_iterations The number of iterations the thread will run.
     */
    void runThread_GetSettlement_LandDoesNotExist(
        unsigned short int const a_thread_seq_number,
        unsigned short int const a_thread_iterations
    )
    {
        asio::io_service io_service;

        try
        {
            IClientShrPtr client(new Client(io_service, "localhost", "2222"));

            for (unsigned short int i = 0; i < a_thread_iterations; ++i)
            {
                char login[14];
                char password[17];

                BOOST_ASSERT(sprintf(login, "%s%d%s%d", "Login_", a_thread_seq_number, "_", i) > 0);
                BOOST_ASSERT(sprintf(password, "%s%d%s%d", "Password_", a_thread_seq_number, "_", i) > 0);

                vector<IScenarioShrPtr> scenarios = list_of
                    (IScenarioShrPtr(new ScenarioCreateUser(
                        client,
                        IScenarioActionShrPtr(new ScenarioCreateUserActionSuccess(login, password)),
                        IScenarioVerificationShrPtr(new ScenarioCreateUserVerificationUserHasBeenCreated))))
                    (IScenarioShrPtr(new ScenarioGetSettlement(
                        client,
                        IScenarioActionShrPtr(new ScenarioGetSettlementActionSuccess(login, password, "Settlement")),
                        IScenarioVerificationShrPtr(new ScenarioGetSettlementVerificationUnauthorized))));

                for (vector<IScenarioShrPtr>::iterator it = scenarios.begin(); it != scenarios.end(); ++it)
                {
                    ASSERT_STREQ("", (*it)->execute());
                }
            }
        }
        catch (std::exception const &)
        {
            BOOST_ASSERT(false);
        }
    }

    /**
     * @brief A method to be passed to the thread.
     *
     * @param a_thread_seq_number The sequential number of the thread.
     * @param a_thread_iterations The number of iterations the thread will run.
     */
    void runThread_GetSettlement_InvalidRequest(
        unsigned short int const a_thread_seq_number,
        unsigned short int const a_thread_iterations
    )
    {
        asio::io_service io_service;

        try
        {
            IClientShrPtr client(new Client(io_service, "localhost", "2222"));

            for (unsigned short int i = 0; i < a_thread_iterations; ++i)
            {
                vector<IScenarioShrPtr> scenarios = list_of
                    (IScenarioShrPtr(new ScenarioGetSettlement(
                        client,
                        IScenarioActionShrPtr(new ScenarioGetSettlementActionInvalidRequest(
                            "Login1", "Password1",
                            "Settlement")),
                        IScenarioVerificationShrPtr(new ScenarioGetSettlementVerificationInvalidRequest))));

                for (vector<IScenarioShrPtr>::iterator it = scenarios.begin(); it != scenarios.end(); ++it)
                {
                    ASSERT_STREQ("", (*it)->execute());
                }
            }
        }
        catch (std::exception const &)
        {
            BOOST_ASSERT(false);
        }
    }
};

/**
 * Integration stress tests of: ExecutorGetSettlement.
 */
TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x1x1)
{
    runTest(1, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x1x10)
{
    runTest(1, 1, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x1x100)
{
    runTest(1, 1, 100, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x10x1)
{
    runTest(1, 10, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x10x10)
{
    runTest(1, 10, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_1x100x1)
{
    runTest(1, 100, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_10x1x1)
{
    runTest(10, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_10x1x10)
{
    runTest(10, 1, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_10x10x1)
{
    runTest(10, 10, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_LandDoesNotExist_100x1x1)
{
    runTest(100, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_LandDoesNotExist, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x1x1)
{
    runTest(1, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x1x10)
{
    runTest(1, 1, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x1x100)
{
    runTest(1, 1, 100, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x10x1)
{
    runTest(1, 10, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x10x10)
{
    runTest(1, 10, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_1x100x1)
{
    runTest(1, 100, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_10x1x1)
{
    runTest(10, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_10x1x10)
{
    runTest(10, 1, 10, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_10x10x1)
{
    runTest(10, 10, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}

TEST_F(IntegrationStressExecutorGetSettlementTest, GetSettlement_InvalidRequest_100x1x1)
{
    runTest(100, 1, 1, bind(&IntegrationStressExecutorGetSettlementTest::runThread_GetSettlement_InvalidRequest, this, _1, _2));
}
