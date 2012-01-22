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

#ifndef GAME_EXECUTOR_HPP
#define GAME_EXECUTOR_HPP

#include <Game/GameServer/Common/IExecutor.hpp>
#include <Game/GameServer/Common/IOperatorAbstractFactory.hpp>
#include <Game/GameServer/Persistence/IPersistence.hpp>
#include <Game/GameServer/User/IUser.hpp>
#include <Server/Server/include/IContext.hpp>

namespace Game
{

class Executor
    : public IExecutor
{
public:
    Executor(
        Server::IContextShrPtr const a_context
    );

    /**
     * @brief Executes the action.
     *
     * @param a_request The request.
     *
     * @return The reply.
     */
    virtual TUSLanguage::ICommand::Handle execute(
        TUSLanguage::ICommand::Handle a_request
    );

private:
    /**
     * @brief Logs the start of the executor.
     */
    virtual void logExecutorStart() const = 0;

    /**
     * @brief Verifies whether the server is listening.
     *
     * @return True if the server is listening, false otherwise.
     */
    bool serverIsListening() const;

    /**
     * @brief Gets parameters from the request.
     *
     * @param a_request The request.
     *
     * @return True if all parameters have been got, false otherwise.
     */
    virtual bool getParameters(
       TUSLanguage::ICommand::Handle a_request
    ) = 0;

    /**
     * @brief Process parameters from the request.
     *
     * @return True if all parameters have been processed, false otherwise.
     */
    virtual bool processParameters() = 0;

    /**
     * @brief Authenticates the user.
     *
     * @param a_persistence The persistence.
     *
     * @return True if user has been authenticated, false otherwise.
     */
    virtual bool authenticate(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    /**
     * @brief Gets the acting user.
     *
     * @param a_persistence The persistence.
     *
     * @return True if the acting user has been got, false otherwise.
     */
    virtual bool getActingUser(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    );

    /**
     * @brief Filters out non moderator.
     *
     * @return True if user is a moderator or moderator's rights are not required, false otherwise.
     */
    virtual bool filterOutNonModerator() const;

    /**
     * @brief Authorizes the user.
     *
     * @param a_persistence The persistence.
     *
     * @return True if user has been authorized, false otherwise.
     */
    virtual bool authorize(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const = 0;

    /**
     * @brief Verifies whether the epoch is active.
     *
     * @param a_persistence The persistence.
     *
     * @return True if the epoch is active, false otherwise.
     */
    virtual bool epochIsActive(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const = 0;

    /**
     * @brief Verifies whether the world configuration allows an action.
     *
     * @param a_persistence The persistence.
     *
     * @return True if the action is allowed, false otherwise.
     */
    virtual bool verifyWorldConfiguration(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const = 0;

    /**
     * @brief Performs the main operation.
     *
     * @param a_persistence The persistence.
     *
     * @return The reply.
     */
    virtual TUSLanguage::ICommand::Handle perform(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const = 0;

    /**
     * @brief Produces the basic reply with a given status.
     *
     * @param a_status The status of the reply.
     *
     * @return The reply.
     */
    virtual TUSLanguage::ICommand::Handle getBasicReply(
        unsigned int const a_status
    ) const = 0;

    //@{
    /**
     * @brief Produces the reply.
     *
     * @return The reply.
     */
    TUSLanguage::ICommand::Handle produceReplyServerIsNotListening()    const;
    TUSLanguage::ICommand::Handle produceReplyInvalidRequest()          const;
    TUSLanguage::ICommand::Handle produceReplyInvalidRange()            const;
    TUSLanguage::ICommand::Handle produceReplyUnauthenticated()         const;
    TUSLanguage::ICommand::Handle produceReplyActingUserHasNotBeenGot() const;
    TUSLanguage::ICommand::Handle produceReplyNonModeratorFilteredOut() const;
    TUSLanguage::ICommand::Handle produceReplyUnauthorized()            const;
    TUSLanguage::ICommand::Handle produceReplyEpochIsNotActive()        const;
    TUSLanguage::ICommand::Handle produceReplyActionUnavailable()       const;
    //}@

protected:
    /**
     * @brief Persistence.
     *
     * TODO: Should be constant again someday.
     */
    GameServer::Persistence::IPersistenceShrPtr m_persistence;

    /**
     * @brief OperatorAbstractFactory.
     *
     * TODO: Should be constant again someday.
     */
    GameServer::Common::IOperatorAbstractFactoryShrPtr m_operator_abstract_factory;

    /**
     * @brief The login of the user.
     *
     * Used in a different way in ExecutorCreateUser.
     */
    std::string m_login;

    /**
     * @brief The password of the user.
     *
     * Used in a different way in ExecutorCreateUser.
     */
    std::string m_password;

    /**
     * @brief The acting user.
     */
    GameServer::User::IUserShrPtr m_user;

    /**
     * @brief The context of the server.
     */
    Server::IContextShrPtr const m_context;
};

} // namespace Game

#endif // GAME_EXECUTOR_HPP
