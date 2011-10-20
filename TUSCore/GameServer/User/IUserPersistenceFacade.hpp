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

#ifndef GAMESERVER_USER_IUSERPERSISTENCEFACADE_HPP
#define GAMESERVER_USER_IUSERPERSISTENCEFACADE_HPP

#include "../Persistence/ITransaction.hpp"
#include "IUser.hpp"
#include <boost/noncopyable.hpp>

namespace GameServer
{
namespace User
{

/**
 * @brief The interface of a user persistence facade.
 */
class IUserPersistenceFacade
    : boost::noncopyable
{
public:
    virtual ~IUserPersistenceFacade(){};

    /**
     * @brief Creates a user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_password    The password of the user.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createUser(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_password
    ) = 0;

    /**
     * @brief Deletes a user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deleteUser(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) = 0;

    /**
     * @brief Gets the user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return The user, null if not found.
     */
    virtual IUserShrPtr getUser(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) = 0;
};

/**
 * @brief A shared pointer of interface of user persistence facade.
 */
typedef boost::shared_ptr<IUserPersistenceFacade> IUserPersistenceFacadeShrPtr;

} // namespace User
} // namespace GameServer

#endif // GAMESERVER_USER_IUSERPERSISTENCEFACADE_HPP
