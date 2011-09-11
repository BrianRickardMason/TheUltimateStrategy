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

#ifndef GAMESERVER_USER_USERMANAGERACCESSORPOSTGRESQL_HPP
#define GAMESERVER_USER_USERMANAGERACCESSORPOSTGRESQL_HPP

#include "IUserManagerAccessor.hpp"
#include <pqxx/result.hxx>

namespace GameServer
{
namespace User
{

/**
 * @brief A PostgreSQL user manager accessor.
 */
class UserManagerAccessorPostgresql
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
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const & a_login,
        std::string                     const & a_password
    ) const;

    /**
     * @brief Deletes a user record.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of a user.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        IDUser                          const & a_id_user
    ) const;

    /**
     * @brief Gets a user record by the login of the user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of a user.
     *
     * @return The user record, null if not found.
     */
    virtual IUserRecordShrPtr getRecordByLogin(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const & a_login
    ) const;

    /**
     * @brief Gets the record of the user.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of the user.
     *
     * @return The record of the user, null if not found.
     */
    virtual IUserRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr a_transaction,
        IDUser                          a_id_user
    ) const;

private:
    /**
     * @brief Prepares the result for getRecord* methods.
     *
     * @param a_result A postgresql result.
     *
     * @return A user record.
     */
    IUserRecordShrPtr prepareResultGetRecord(
        pqxx::result const & a_result
    ) const;
};

} // namespace User
} // namespace GameServer

#endif // GAMESERVER_USER_USERMANAGERACCESSORPOSTGRESQL_HPP
