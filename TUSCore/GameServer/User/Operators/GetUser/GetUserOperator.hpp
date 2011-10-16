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

#ifndef GAMESERVER_USER_GETUSEROPERATOR_HPP
#define GAMESERVER_USER_GETUSEROPERATOR_HPP

#include "../../IUserManager.hpp"
#include "IGetUserOperator.hpp"

namespace GameServer
{
namespace User
{

/**
 * @brief GetUserOperator.
 */
class GetUserOperator
    : public IGetUserOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_user_manager The manager of users.
     */
    GetUserOperator(
        IUserManagerShrPtr a_user_manager
    );

    /**
     * @brief Gets the user.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return The exit code.
     */
    virtual GetUserOperatorExitCode getUser(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) const;

private:
    /**
     * @brief The manager of users.
     */
    IUserManagerShrPtr m_user_manager;
};

/**
 * @brief The auto pointer of GetUserOperator.
 */
typedef std::auto_ptr<GetUserOperator> GetUserOperatorAutPtr;

} // namespace User
} // namespace GameServer

#endif // GAMESERVER_USER_GETUSEROPERATOR_HPP
