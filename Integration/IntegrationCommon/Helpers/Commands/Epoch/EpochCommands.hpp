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

#ifndef INTEGRATIONCOMMON_HELPERS_COMMANDS_EPOCH_EPOCHCOMMANDS_HPP
#define INTEGRATIONCOMMON_HELPERS_COMMANDS_EPOCH_EPOCHCOMMANDS_HPP

#include <Server/Network/XmlRPCCommon/Reply/Reply.hpp>
#include <Integration/IntegrationCommon/Helpers/XmlRPCClient/ClientSynchronous/IClientSynchronous.hpp>

namespace IntegrationCommon
{
namespace Helpers
{
namespace Commands
{
namespace Epoch
{

/**
 * @brief Creates a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr CreateEpoch(
    IClientShrPtr       a_client,
    std::string   const a_login,
    std::string   const a_password,
    std::string   const a_world_name,
    std::string   const a_epoch_name
);

/**
 * @brief Deletes a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr DeleteEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

/**
 * @brief Gets a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr GetEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

/**
 * @brief Activates a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr ActivateEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

/**
 * @brief Deactivates a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr DeactivateEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

/**
 * @brief Finishes a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr FinishEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

/**
 * @brief Ticks a epoch.
 *
 * @param a_client     The client.
 * @param a_login      The login of the user.
 * @param a_password   The password of the user.
 * @param a_world_name The name of the world.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr TickEpoch(
    IClientShrPtr         a_client,
    std::string   const & a_login,
    std::string   const & a_password,
    std::string   const   a_world_name
);

} // namespace Epoch
} // namespace Commands
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_COMMANDS_EPOCH_EPOCHCOMMANDS_HPP
