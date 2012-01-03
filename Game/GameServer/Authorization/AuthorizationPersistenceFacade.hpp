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

#ifndef GAMESERVER_AUTHORIZATION_AUTHORIZATIONPERSISTENCEFACADE_HPP
#define GAMESERVER_AUTHORIZATION_AUTHORIZATIONPERSISTENCEFACADE_HPP

#include <Game/GameServer/Authorization/IAuthorizationAccessor.hpp>
#include <Game/GameServer/Authorization/IAuthorizationPersistenceFacade.hpp>
#include <Game/GameServer/Common/IDHolder.hpp>
#include <Game/GameServer/Persistence/IPersistence.hpp>

namespace GameServer
{
namespace Authorization
{

/**
 * @brief An authorization persistence facade.
 */
class AuthorizationPersistenceFacade
    : public IAuthorizationPersistenceFacade
{
public:
    /**
     * @brief Constructs the authorization persistence facade.
     *
     * @param a_accessor An accessor to be injected.
     */
    AuthorizationPersistenceFacade(
        IAuthorizationAccessorAutPtr a_accessor
    );

    /**
     * @brief Authorizes the user to the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_name        The name of the land.
     *
     * @return True if authorized, false otherwise.
     */
    virtual bool authorizeUserToLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Authorizes a user to a holder.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return True if authorized, false otherwise.
     */
    virtual bool authorizeUserToHolder(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        Common::IDHolder                const & a_id_holder
    ) const;

    /**
     * @brief Authorizes the user to the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_login           The login of the user.
     * @param a_settlement_name The name of the settlement.
     *
     * @return True if authorized, false otherwise.
     */
    virtual bool authorizeUserToSettlement(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_settlement_name
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IAuthorizationAccessorScpPtr m_accessor;
};

/**
 * @brief Typedef of auto pointer.
 */
typedef std::auto_ptr<AuthorizationPersistenceFacade> AuthorizationPersistenceFacadeAutPtr;

} // namespace Authorization
} // namespace GameServer

#endif // GAMESERVER_AUTHORIZATION_AUTHORIZATIONPERSISTENCEFACADE_HPP
