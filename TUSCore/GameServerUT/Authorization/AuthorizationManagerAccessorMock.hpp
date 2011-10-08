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

#ifndef GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORMOCK_HPP
#define GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORMOCK_HPP

#include "../../GameServer/Authorization/IAuthorizationManagerAccessor.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Authorization
{

/**
 * @brief A mock of the interface of the authorization manager accessor.
 */
class AuthorizationManagerAccessorMock
    : public IAuthorizationManagerAccessor
{
public:
    /**
     * @brief Authorizes a user to the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_land_name   The name of the land.
     *
     * @return True if the user is authorized, false otherwise.
     */
    MOCK_CONST_METHOD3(
        authorizeUserToLand,
        bool(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_login,
            std::string                     const a_land_name
        )
    );

    /**
     * @brief Gets the name of the land of the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement
     *
     * @return The name of the land, an empty string if not found.
     */
    MOCK_CONST_METHOD2(
        getLandNameOfSettlement,
        std::string(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_settlement_name
        )
    );
};

} // namespace Authorization
} // namespace GameServer

#endif // GAMESERVER_AUTHORIZATION_AUTHORIZATIONMANAGERACCESSORMOCK_HPP