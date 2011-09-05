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

#ifndef INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIOGETBUILDINGS_HPP
#define INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIOGETBUILDINGS_HPP

#include "../IScenario.hpp"
#include "../IScenarioAction.hpp"
#include "../IScenarioVerification.hpp"

namespace IntegrationCommon
{
namespace Helpers
{
namespace Scenarios
{
namespace Building
{

/**
 * @brief The "GetBuildings" scenario.
 */
class ScenarioGetBuildings
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
    ScenarioGetBuildings(
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
 * @brief The "ScenarioGetBuildingsActionSuccess" action.
 */
class ScenarioGetBuildingsActionSuccess
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_id_user         The identifier of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_id_holder       The identifier of the holder.
     */
    ScenarioGetBuildingsActionSuccess(
        unsigned int const   a_id_user,
        std::string  const & a_password,
        unsigned int const   a_id_holder_class,
        unsigned int const   a_id_holder
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
     * @brief The identifier of the user.
     */
    unsigned int const m_id_user;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The identifier of the class of the holder.
     */
    unsigned int const m_id_holder_class;

    /**
     * @brief The identifier of the holder.
     */
    unsigned int const m_id_holder;
};

/**
 * @brief The "ScenarioGetBuildingsActionInvalidRequest" action.
 */
class ScenarioGetBuildingsActionInvalidRequest
    : public IScenarioAction
{
public:
    /**
     * @brief Constructs the action.
     *
     * @param a_id_user         The identifier of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_id_holder       The identifier of the holder.
     */
    ScenarioGetBuildingsActionInvalidRequest(
        unsigned int const   a_id_user,
        std::string  const & a_password,
        unsigned int const   a_id_holder_class,
        unsigned int const   a_id_holder
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
     * @brief The identifier of the user.
     */
    unsigned int const m_id_user;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief The identifier of the class of the holder.
     */
    unsigned int const m_id_holder_class;

    /**
     * @brief The identifier of the holder.
     */
    unsigned int const m_id_holder;
};

/**
 * @brief The "ScenarioGetBuildingsVerificationBuildingsHaveBeenGot" verification.
 */
class ScenarioGetBuildingsVerificationBuildingsHaveBeenGot
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
 * @brief The "ScenarioGetBuildingsVerificationUnexpectedError" verification.
 */
class ScenarioGetBuildingsVerificationUnexpectedError
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
 * @brief The "ScenarioGetBuildingsVerificationInvalidRequest" verification.
 */
class ScenarioGetBuildingsVerificationInvalidRequest
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
 * @brief The "ScenarioGetBuildingsVerificationInvalidRange" verification.
 */
class ScenarioGetBuildingsVerificationInvalidRange
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
 * @brief The "ScenarioGetBuildingsVerificationUnauthenticated" verification.
 */
class ScenarioGetBuildingsVerificationUnauthenticated
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
 * @brief The "ScenarioGetBuildingsVerificationUnauthorized" verification.
 */
class ScenarioGetBuildingsVerificationUnauthorized
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
 * @brief The "ScenarioGetBuildingsVerificationEpochIsNotActive" verification.
 */
class ScenarioGetBuildingsVerificationEpochIsNotActive
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

} // namespace Building
} // namespace Scenarios
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_SCENARIOS_BUILDING_SCENARIOGETBUILDINGS_HPP
