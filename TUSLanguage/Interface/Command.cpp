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

#include "Command.hpp"

namespace TUSLanguage
{

Command::Command()
    : m_id(0)
{
}

unsigned short int Command::getID() const
{
    return m_id;
}

void Command::setID(
    unsigned short int a_id
)
{
    m_id = a_id;
}

std::string Command::getLogin() const
{
    return m_login;
}

void Command::setLogin(
    std::string a_login
)
{
    m_login = a_login;
}

std::string Command::getPassword() const
{
    return m_password;
}

void Command::setPassword(
    std::string a_password
)
{
    m_password = a_password;
}

std::string Command::getParam(
    std::string a_param_name
) const
{
    return m_parameters.at(a_param_name);
}

void Command::setParam(
    std::string a_param_name,
    std::string a_param_value
)
{
    m_parameters[a_param_name] = a_param_value;
}

} // namespace TUSLanguage
