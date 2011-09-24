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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_LAND_SCENARIOGETLANDBYNAME_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_LAND_SCENARIOGETLANDBYNAME_HPP

#include "../IScenario.hpp"
#include "../IScenarioAction.hpp"
#include "../IScenarioVerification.hpp"

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Land
{

/**
 * @brief The "GetLandByName" scenario.
 */
class ScenarioGetLandByName
    : public IScenario
{
public:
    /**
     * @brief Constructs the scenario.
     *
     * @param a_client       The client.
     * @param a_action       The action object.
     * @param a_verification The verification object.
     */
    ScenarioGetLandByName(
        IClientShrPtr               a_client,
        IScenarioActionShrPtr       a_action,
        IScenarioVerificationShrPtr a_verification
    );

    /**
     * @brief Executes the scenario.
     */
    virtual char const * execute();

private:
    /**
     * @brief The client.
     */
    IClientShrPtr m_client;

    /**
     * @brief The action object.
     */
    IScenarioActionShrPtr m_action;

    /**
     * @brief The verification object.
     */
    IScenarioVerificationShrPtr m_verification;
};

/**
 * @brief The "ScenarioGetLandByNameActionSuccess" action.
 */
class ScenarioGetLandByNameActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     * @param a_name     The name of the land.
     */
    ScenarioGetLandByNameActionSuccess(
        std::string const & a_login,
        std::string const & a_password,
        std::string const   a_name
    );

    /**
     * @brief Performs the action.
     *
     * @param a_client The client.
     *
     * @return The reply.
     */
    virtual Network::XmlRPCCommon::Reply::ReplyShrPtr perform(
        IClientShrPtr a_client
    );

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The name of the land.
     */
    std::string const m_name;
};

/**
 * @brief The "ScenarioGetLandByNameActionInvalidRequest" action.
 */
class ScenarioGetLandByNameActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     * @param a_name     The name of the land.
     */
    ScenarioGetLandByNameActionInvalidRequest(
        std::string const & a_login,
        std::string const & a_password,
        std::string const   a_name
    );

    /**
     * @brief Performs the action.
     *
     * @param a_client The client.
     *
     * @return The reply.
     */
    virtual Network::XmlRPCCommon::Reply::ReplyShrPtr perform(
        IClientShrPtr a_client
    );

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The name of the land.
     */
    std::string const m_name;
};

/**
 * @brief The "ScenarioGetLandByNameVerificationLandHasBeenGot" verification.
 */
class ScenarioGetLandByNameVerificationLandHasBeenGot
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationLandHasNotBeenGot" verification.
 */
class ScenarioGetLandByNameVerificationLandHasNotBeenGot
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationUnexpectedError" verification.
 */
class ScenarioGetLandByNameVerificationUnexpectedError
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationInvalidRequest" verification.
 */
class ScenarioGetLandByNameVerificationInvalidRequest
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationInvalidRange" verification.
 */
class ScenarioGetLandByNameVerificationInvalidRange
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationUnauthenticated" verification.
 */
class ScenarioGetLandByNameVerificationUnauthenticated
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationUnauthorized" verification.
 */
class ScenarioGetLandByNameVerificationUnauthorized
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioGetLandByNameVerificationEpochIsNotActive" verification.
 */
class ScenarioGetLandByNameVerificationEpochIsNotActive
    : public IScenarioVerification
{
public:
    /**
     * @brief Performs the verification.
     *
     * @param a_reply The reply to be verified.
     *
     * @return An empty "string" on success, a message otherwise.
     */
    virtual std::string verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};


} // namespace Land
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_LAND_SCENARIOGETLANDBYNAME_HPP
