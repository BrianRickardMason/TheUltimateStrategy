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

#ifndef NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORDELETELAND_HPP
#define NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORDELETELAND_HPP

#include "../../../../../GameServer/Land/Operators/DeleteLand/DeleteLandOperatorExitCode.hpp"
#include "../../../../../GameServer/Land/IDLand.hpp"
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
 * @brief The ExecutorDeleteLand executor.
 *
 * <?xml version=\"1.0\"?>
 * <request id=\"REQUEST_ID_DELETE_LAND\">
 *     <user>
 *         <iduser   value=\"#\" />
 *         <password value=\"#\" />
 *     </user>
 *     <parameters>
 *         <idland type=\"unsigned integer\" value=\"#\" />
 *     </parameters>
 * </request>
 *
 * <?xml version=\"1.0\"?>
 * <reply id=\"REPLY_ID_DELETE_LAND">
 *     <status value=\"#\" />
 *     <parameters>
 *         <message type=\"string"\ value=\"#\" />
 *     </parameters>
 * </reply>
 */
class ExecutorDeleteLand
    : public Executor
{
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
     * @brief Authenticates the user.
     *
     * @param a_persistency The persistency.
     *
     * @return True if user has been authenticated, false otherwise.
     */
    virtual bool authenticate(
        GameServer::Persistency::IPersistencyShrPtr a_persistency
    ) const;

    /**
     * @brief Authorizes the user.
     *
     * @param a_persistency The persistency.
     *
     * @return True if user has been authorized, false otherwise.
     */
    virtual bool authorize(
        GameServer::Persistency::IPersistencyShrPtr a_persistency
    ) const;

    /**
     * @brief Verifies whether the epoch is active.
     *
     * @param a_persistency The persistency.
     *
     * @return True if the epoch is active, false otherwise.
     */
    virtual bool epochIsActive(
        GameServer::Persistency::IPersistencyShrPtr a_persistency
    ) const;

    /**
     * @brief Verifies whether the world configuration allows an action.
     *
     * @param a_persistency The persistency.
     *
     * @return True if the action is allowed, false otherwise.
     */
    virtual bool verifyWorldConfiguration(
        GameServer::Persistency::IPersistencyShrPtr a_persistency
    ) const;

    /**
     * @brief Performs the main operation.
     *
     * @return The reply.
     */
    virtual XmlRPCCommon::Reply::ReplyShrPtr perform(
        GameServer::Persistency::IPersistencyShrPtr a_persistency
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
        GameServer::Land::DeleteLandOperatorExitCode const & a_exit_code
    ) const;

    /**
     * @brief The value of the identifier of a user.
     */
    unsigned int m_value_id_user;

    /**
     * @brief The value of the identifier of a land.
     */
    unsigned int m_value_id_land;

    /**
     * @brief The password of the user.
     */
    std::string m_password;

    /**
     * @brief The identifier of the land.
     */
    GameServer::Land::IDLand m_id_land;
};

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_EXECUTORDELETELAND_HPP
