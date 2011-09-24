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

#ifndef INTEGRATIONCOMMON_HELPERS_COMMANDS_SETTLEMENT_SETTLEMENTCOMMANDS_HPP
#define INTEGRATIONCOMMON_HELPERS_COMMANDS_SETTLEMENT_SETTLEMENTCOMMANDS_HPP

#include "../../../../Network/XmlRPCCommon/Reply/Reply.hpp"
#include "../../XmlRPCClient/ClientSynchronous/IClientSynchronous.hpp"

namespace IntegrationCommon
{
namespace Helpers
{
namespace Commands
{
namespace Settlement
{

/**
 * @brief Creates a settlement.
 *
 * @param a_client   The client.
 * @param a_login    The login of the user.
 * @param a_password The password of the user.
 * @param a_id_land  The identifier of a land.
 * @param a_name     The name of a settlement.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr CreateSettlement(
    IClientShrPtr        a_client,
    std::string  const & a_login,
    std::string  const & a_password,
    unsigned int const   a_id_land,
    std::string  const & a_name
);

/**
 * @brief Deletes a settlement.
 *
 * @param a_client        The client.
 * @param a_login         The login of the user.
 * @param a_password      The password of the user.
 * @param a_id_settlement The identifier of the settlement.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr DeleteSettlement(
    IClientShrPtr        a_client,
    std::string  const & a_login,
    std::string  const & a_password,
    unsigned int const   a_id_settlement
);

/**
 * @brief Gets a settlement by id land and name.
 *
 * @param a_client   The client.
 * @param a_login    The login of the user.
 * @param a_password The password of the user.
 * @param a_id_land  The identifier of a land.
 * @param a_name     The name of the settlement.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr GetSettlementByIDLandAndName(
    IClientShrPtr        a_client,
    std::string  const & a_login,
    std::string  const & a_password,
    unsigned int const   a_id_land,
    std::string  const & a_name
);

/**
 * @brief Gets a settlement by id settlement.
 *
 * @param a_client        The client.
 * @param a_login         The login of the user.
 * @param a_password      The password of the user.
 * @param a_id_settlement The identifier of the settlement.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr GetSettlementByIDSettlement(
    IClientShrPtr        a_client,
    std::string  const & a_login,
    std::string  const & a_password,
    unsigned int const   a_id_settlement
);

/**
 * @brief Gets settlements.
 *
 * @param a_client   The client.
 * @param a_login    The login of the user.
 * @param a_password The password of the user.
 * @param a_id_land  The identifier of a land.
 *
 * @return The reply.
 */
Network::XmlRPCCommon::Reply::ReplyShrPtr GetSettlements(
    IClientShrPtr        a_client,
    std::string  const & a_login,
    std::string  const & a_password,
    unsigned int const   a_id_land
);

} // namespace Settlement
} // namespace Commands
} // namespace Helpers
} // namespace IntegrationCommon

#endif // INTEGRATIONCOMMON_HELPERS_COMMANDS_SETTLEMENT_SETTLEMENTCOMMANDS_HPP
