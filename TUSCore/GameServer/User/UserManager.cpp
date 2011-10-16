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

#include "User.hpp"
#include "UserManager.hpp"

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace User
{

UserManager::UserManager(
    IUserManagerAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

bool UserManager::createUser(
    ITransactionShrPtr       a_transaction,
    string             const a_login,
    string             const a_password
)
{
    try
    {
        m_accessor->insertRecord(a_transaction, a_login, a_password);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool UserManager::deleteUser(
    ITransactionShrPtr       a_transaction,
    string             const a_login
)
{
    try
    {
        m_accessor->deleteRecord(a_transaction, a_login);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

IUserShrPtr UserManager::getUser(
    ITransactionShrPtr       a_transaction,
    string             const a_login
)
{
    IUserRecordShrPtr user_record = m_accessor->getRecord(a_transaction, a_login);

    return user_record ? IUserShrPtr(new User(user_record)) : IUserShrPtr();
}

} // namespace User
} // namespace GameServer
