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

#ifndef GAMESERVER_USER_USERMANAGERACCESSORMOCK_HPP
#define GAMESERVER_USER_USERMANAGERACCESSORMOCK_HPP

#include "../../GameServer/User/IUserManagerAccessor.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace User
{

/**
 * @brief A mock of user manager accessor.
 */
class UserManagerAccessorMock
    : public IUserManagerAccessor
{
public:
    /**
     * @brief Inserts a user record.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of a user.
     * @param a_password    The password of a user.
     */
    MOCK_CONST_METHOD3(
        insertRecord,
        void(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const & a_login,
            std::string                     const & a_password
        )
    );

    /**
     * @brief Deletes a user record.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of a user.
     */
    MOCK_CONST_METHOD2(
        deleteRecord,
        void(
            Persistency::ITransactionShrPtr         a_transaction,
            IDUser                          const & a_id_user
        )
    );

    /**
     * @brief Gets a user record by the login of the user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of a user.
     *
     * @return The user record, null if not found.
     */
    MOCK_CONST_METHOD2(
        getRecordByLogin,
        IUserRecordShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const & a_login
        )
    );

    /**
     * @brief Gets the record of the user.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of the user.
     *
     * @return The record of the user, null if not found.
     */
    MOCK_CONST_METHOD2(
        getRecord,
        IUserRecordShrPtr(
            Persistency::ITransactionShrPtr a_transaction,
            IDUser                          a_id_user
        )
    );
};

} // namespace User
} // namespace GameServer

#endif // GAMESERVER_USER_USERMANAGERACCESSORMOCK_HPP
