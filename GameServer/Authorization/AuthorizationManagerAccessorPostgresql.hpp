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

#ifndef GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORPOSTGRESQL_HPP
#define GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORPOSTGRESQL_HPP

#include "IAuthorizationManagerAccessor.hpp"

namespace GameServer
{
namespace Authorization
{

/**
 * @brief An PostgreSQL authorization manager accessor.
 */
class AuthorizationManagerAccessorPostgresql
    : public IAuthorizationManagerAccessor
{
public:
    /**
     * @brief Authorizes a user to the land.
     *
     * @param a_transaction A transaction.
     * @param a_id_user     An identifier of the user.
     * @param a_id_land     An identifier of the land.
     *
     * @return True if the user is authorized, false otherwise.
     */
    virtual bool authorizeUserToLand(
        Persistency::ITransactionShrPtr         a_transaction,
        User::IDUser                    const & a_id_user,
        Land::IDLand                    const & a_id_land
    ) const;

    /**
     * @brief Authorizes a user to the land.
     *
     * @param a_transaction A transaction.
     * @param a_id_user     An identifier of the user.
     * @param a_name        A name of the land.
     *
     * @return True if the user is authorized, false otherwise.
     */
    virtual bool authorizeUserToLand(
        Persistency::ITransactionShrPtr         a_transaction,
        User::IDUser                    const & a_id_user,
        std::string                     const & a_name
    ) const;

    /**
     * @brief Gets the identifier of a land of the settlement.
     *
     * @param a_transaction   A transaction.
     * @param a_id_settlement An identifier of the settlement
     *
     * @return The identifier of the land, 0 if not found.
     */
    virtual Land::IDLand getIDLandOfSettlement(
        Persistency::ITransactionShrPtr         a_transaction,
        Settlement::IDSettlement        const & a_id_settlement
    ) const;
};

} // namespace Authorization
} // namespace GameServer

#endif // GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORPOSTGRESQL_HPP
