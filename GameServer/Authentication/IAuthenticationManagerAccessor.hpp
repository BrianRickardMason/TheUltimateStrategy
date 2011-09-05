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

#ifndef GAMESERVER_AUTHENTICATION_IAUTHENTICATIONMANAGERACCESSOR_HPP
#define GAMESERVER_AUTHENTICATION_IAUTHENTICATIONMANAGERACCESSOR_HPP

#include "../Persistency/ITransaction.hpp"
#include "../User/IDUser.hpp"
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Authentication
{

/**
 * @brief An interface of the authentication manager accessor.
 */
class IAuthenticationManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the accessor.
     */
    virtual ~IAuthenticationManagerAccessor(){};

    /**
     * @brief Authenticates a user.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of the user.
     * @param a_password    The password of the user.
     *
     * @return True if authenticated, false otherwise.
     */
    virtual bool authenticate(
        Persistency::ITransactionShrPtr         a_transaction,
        User::IDUser                    const & a_id_user,
        std::string                     const & a_password
    ) const = 0;
};

/**
 * @brief An auto pointer of the interface of the authentication manager accessor.
 */
typedef std::auto_ptr<IAuthenticationManagerAccessor> IAuthenticationManagerAccessorAutPtr;

/**
 * @brief A scoped pointer of the interface of the authentication manager accessor.
 */
typedef boost::scoped_ptr<IAuthenticationManagerAccessor> IAuthenticationManagerAccessorScpPtr;

} // namespace Authentication
} // namespace GameServer

#endif // GAMESERVER_AUTHENTICATION_IAUTHENTICATIONMANAGERACCESSOR_HPP
