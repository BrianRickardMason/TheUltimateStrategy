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

#ifndef GAMESERVER_USER_USER_HPP
#define GAMESERVER_USER_USER_HPP

#include <TUSGame/GameServer/User/IUser.hpp>
#include <TUSGame/GameServer/User/IUserRecord.hpp>

namespace GameServer
{
namespace User
{

/**
 * @brief User.
 */
class User
    : public IUser
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_record The corresponding record.
     */
    explicit User(
        IUserRecordShrPtr const a_record
    );

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user.
     */
    virtual std::string getLogin() const;

    /**
     * @brief Gets the password of the user.
     *
     * @return The password of the user.
     */
    virtual std::string getPassword() const;

    /**
     * @brief Checks if the user is a moderator.
     *
     * @return True if the user is the moderator, false otherwise.
     */
    virtual bool isModerator() const;

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The password of the user.
     */
    std::string const m_password;

    /**
     * @brief True if the user is a moderator, false otherwise.
     */
    bool const m_moderator;
};

} // namespace User
} // namespace GameServer

#endif // GAMESERVER_USER_USER_HPP
