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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_EPOCH_SCENARIOACTIVATEEPOCH_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_EPOCH_SCENARIOACTIVATEEPOCH_HPP

#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenario.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenarioAction.hpp>
#include <Integration/IntegrationCommon/Helpers/Scenarios/IScenarioVerification.hpp>

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Epoch
{

/**
 * @brief The "ActivateEpoch" scenario.
 */
class ScenarioActivateEpoch
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
    ScenarioActivateEpoch(
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
 * @brief The "ScenarioActivateEpochActionSuccess" action.
 */
class ScenarioActivateEpochActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     */
    ScenarioActivateEpochActionSuccess(
        std::string const & a_login,
        std::string const & a_password,
        std::string const   a_world_name
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
     * @brief The name of the world.
     */
    std::string const m_world_name;
};

/**
 * @brief The "ScenarioActivateEpochActionInvalidRequest" action.
 */
class ScenarioActivateEpochActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     */
    ScenarioActivateEpochActionInvalidRequest(
        std::string const & a_login,
        std::string const & a_password,
        std::string const   a_world_name
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
     * @brief The name of the world.
     */
    std::string const m_world_name;
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochDoesNotExist" verification.
 */
class ScenarioActivateEpochVerificationEpochDoesNotExist
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochHasBeenActivated" verification.
 */
class ScenarioActivateEpochVerificationEpochHasBeenActivated
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochHasBeenFinished" verification.
 */
class ScenarioActivateEpochVerificationEpochHasBeenFinished
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochHasNotBeenActivated" verification.
 */
class ScenarioActivateEpochVerificationEpochHasNotBeenActivated
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochIsActive" verification.
 */
class ScenarioActivateEpochVerificationEpochIsActive
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationUnexpectedError" verification.
 */
class ScenarioActivateEpochVerificationUnexpectedError
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationWorldDoesNotExist" verification.
 */
class ScenarioActivateEpochVerificationWorldDoesNotExist
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationInvalidRequest" verification.
 */
class ScenarioActivateEpochVerificationInvalidRequest
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationInvalidRange" verification.
 */
class ScenarioActivateEpochVerificationInvalidRange
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationUnauthenticated" verification.
 */
class ScenarioActivateEpochVerificationUnauthenticated
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationUnauthorized" verification.
 */
class ScenarioActivateEpochVerificationUnauthorized
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

/**
 * @brief The "ScenarioActivateEpochVerificationEpochIsNotActive" verification.
 */
class ScenarioActivateEpochVerificationEpochIsNotActive
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
    virtual char const * verify(
        Network::XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );
};

} // namespace Epoch
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_EPOCH_SCENARIOACTIVATEEPOCH_HPP
