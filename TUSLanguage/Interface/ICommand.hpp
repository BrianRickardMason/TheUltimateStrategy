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

#ifndef TUSLANG_ICOMMAND_HPP
#define TUSLANG_ICOMMAND_HPP

#include <memory>
#include <string>

namespace TUSLang
{

class ICommand
{
public:
    typedef std::auto_ptr<ICommand> SingleHandle;

    virtual ~ICommand(){}

    /**
     * @brief Gets the identifier of the command.
     *
     * @return The identifier of the command.
     */
    virtual unsigned short int getID() const = 0;

    /**
     * @brief Sets the identifier of the command.
     *
     * @param a_id The identifier of the command.
     */
    virtual void setID(
        unsigned short int a_id
    ) = 0;

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user, an empty string if not set.
     */
    virtual std::string getLogin() const = 0;

    /**
     * @brief Sets the login of the user.
     *
     * @param a_login The login of the user.
     */
    virtual void setLogin(
        std::string a_login
    ) = 0;

    /**
     * @brief Gets the password of the user.
     *
     * @return The password of the user, an empty string if not set.
     */
    virtual std::string getPassword() const = 0;

    /**
     * @brief Sets the password of the user.
     *
     * @param a_password The password of the user.
     */
    virtual void setPassword(
        std::string a_password
    ) = 0;
};

} // namespace TUSLang

#endif // TUSLANG_ICOMMAND_HPP