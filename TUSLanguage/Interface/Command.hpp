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

#ifndef TUSLANG_COMMAND_HPP
#define TUSLANG_COMMAND_HPP

#include "ICommand.hpp"
#include <map>

namespace TUSLang
{

class Command
    : public ICommand
{
public:
    Command();

    /**
     * @brief Gets the identifier of the command.
     *
     * @return The identifier of the command.
     */
    virtual unsigned short int getID() const;

    /**
     * @brief Sets the identifier of the command.
     *
     * @param a_id The identifier of the command.
     */
    virtual void setID(
        unsigned short int a_id
    );

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user, an empty string if not set.
     */
    virtual std::string getLogin() const;

    /**
     * @brief Sets the login of the user.
     *
     * @param a_login The login of the user.
     */
    virtual void setLogin(
        std::string a_login
    );

    /**
     * @brief Gets the password of the user.
     *
     * @return The password of the user, an empty string if not set.
     */
    virtual std::string getPassword() const;

    /**
     * @brief Sets the password of the user.
     *
     * @param a_password The password of the user.
     */
    virtual void setPassword(
        std::string a_password
    );

    /**
     * @brief Gets the value of the parameter.
     *
     * @param a_param_name The name of the parameter.
     *
     * @return The value of the parameter.
     *
     * @throw std::out_of_range If no such parameter is present.
     */
    virtual std::string getParam(
        std::string a_param_name
    ) const;

    /**
     * @brief Sets the parameter.
     *
     * @param a_param_name  The name of the parameter.
     * @param a_param_value The value of the parameter.
     */
    virtual void setParam(
        std::string a_param_name,
        std::string a_param_value
    );

private:
    /**
     * @brief The identifier of the command.
     */
    unsigned short int m_id;

    /**
     * @brief The login of the user, an empty string if not set.
     */
    std::string m_login;

    /**
     * @brief The password of the user, an empty string if not set.
     */
    std::string m_password;

    /**
     * @brief The map of parameters.
     */
    std::map<std::string, std::string> m_parameters;
};

} // namespace TUSLang

#endif // TUSLANG_COMMAND_HPP
