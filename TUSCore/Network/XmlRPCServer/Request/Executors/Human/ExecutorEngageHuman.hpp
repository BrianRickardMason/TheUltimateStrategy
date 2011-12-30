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

#ifndef NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORENGAGEHUMAN_HPP
#define NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORENGAGEHUMAN_HPP

#include <TUSGame/GameServer/Common/IDHolder.hpp>
#include <TUSGame/GameServer/Human/Operators/EngageHuman/EngageHumanOperatorExitCode.hpp>
#include <TUSGame/GameServer/Human/Volume.hpp>
#include "../Executor.hpp"

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

/**
 * @brief The ExecutorEngageHuman executor.
 *
 * <?xml version=\"1.0\"?>
 * <request id=\"REQUEST_ID_ENGAGE_HUMAN\">
 *     <user>
 *         <login    value=\"#\" />
 *         <password value=\"#\" />
 *     </user>
 *     <parameters>
 *         <idholderclass value=\"#\" />
 *         <holder_name   value=\"#\" />
 *         <humankey      value=\"#\" />
 *         <volume        value=\"#\" />
 *     </parameters>
 * </request>
 *
 * <?xml version=\"1.0\"?>
 * <reply id=\"REPLY_ID_ENGAGE_HUMAN">
 *     <status value=\"#\" />
 *     <parameters>
 *         <message value=\"#\" />
 *     </parameters>
 * </reply>
 */
class ExecutorEngageHuman
    : public Executor
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_context The context of the server.
     */
    ExecutorEngageHuman(
        IContextShrPtr const a_context
    );

private:
    /**
     * @brief Logs the start of the executor.
     */
    virtual void logExecutorStart() const;

    /**
     * @brief Gets parameters from the request.
     *
     * @param a_request The request.
     *
     * @return True if all parameters have been got, false otherwise.
     */
    virtual bool getParameters(
        XmlRPCCommon::Request::RequestShrPtr a_request
    );

    /**
     * @brief Process parameters from the request.
     *
     * @return True if all parameters have been processed, false otherwise.
     */
    virtual bool processParameters();

    /**
     * @brief Authorizes the user.
     *
     * @param a_persistence The persistence.
     *
     * @return True if user has been authorized, false otherwise.
     */
    virtual bool authorize(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    /**
     * @brief Verifies whether the epoch is active.
     *
     * @param a_persistence The persistence.
     *
     * @return True if the epoch is active, false otherwise.
     */
    virtual bool epochIsActive(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    /**
     * @brief Verifies whether the world configuration allows an action.
     *
     * @param a_persistence The persistence.
     *
     * @return True if the action is allowed, false otherwise.
     */
    virtual bool verifyWorldConfiguration(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    /**
     * @brief Performs the main operation.
     *
     * @return The reply.
     */
    virtual XmlRPCCommon::Reply::ReplyShrPtr perform(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    /**
     * @brief Produces the basic reply with a given status.
     *
     * @param a_status The status of the reply.
     *
     * @return The reply.
     */
    virtual XmlRPCCommon::Reply::ReplyShrPtr getBasicReply(
        unsigned int const a_status
    ) const;

    /**
     * @brief Produces the reply.
     *
     * @param a_exit_code The exit code.
     *
     * @return The reply.
     */
    XmlRPCCommon::Reply::ReplyShrPtr produceReply(
        GameServer::Human::EngageHumanOperatorExitCode const & a_exit_code
    ) const;

    /**
     * @brief The value of the identifier of the class of a holder.
     */
    unsigned int m_value_id_holder_class;

    /**
     * @brief The name of the holder.
     */
    std::string m_holder_name;

    /**
     * @brief The key of the human.
     */
    std::string m_key;

    /**
     * @brief The value of the volume.
     */
    unsigned int m_value_volume;

    /**
     * @brief The identifier of a holder.
     */
    GameServer::Common::IDHolder m_id_holder;

    /**
     * @brief The volume.
     */
    GameServer::Human::Volume m_volume;
};

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORENGAGEHUMAN_HPP
