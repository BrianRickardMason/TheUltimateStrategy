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

#include "../Persistency/TransactionPostgresql.hpp"
#include "UserManagerAccessorPostgresql.hpp"
#include "UserRecord.hpp"

using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace User
{

void UserManagerAccessorPostgresql::insertRecord(
    ITransactionShrPtr         a_transaction,
    string             const & a_login,
    string             const & a_password
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO users(login, password) VALUES("
                   + backbone_transaction.quote(a_login) + ", "
                   + backbone_transaction.quote(a_password) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void UserManagerAccessorPostgresql::deleteRecord(
    ITransactionShrPtr         a_transaction,
    IDUser             const & a_id_user
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM users WHERE id_user = "
                   + backbone_transaction.quote(a_id_user.getValue());

    pqxx::result result = backbone_transaction.exec(query);
}

IUserRecordShrPtr UserManagerAccessorPostgresql::getRecordByLogin(
    ITransactionShrPtr         a_transaction,
    string             const & a_login
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM users WHERE login = "
                   + backbone_transaction.quote(a_login);

    return prepareResultGetRecord(backbone_transaction.exec(query));
}

IUserRecordShrPtr UserManagerAccessorPostgresql::prepareResultGetRecord(
    pqxx::result const & a_result
) const
{
    // Fake types for libpqxx.
    unsigned int unsigned_integer;

    if (a_result.size() > 0)
    {
        IDUser id_user;
        string login,
               password;

        id_user = a_result[0]["id_user"].as(unsigned_integer);
        a_result[0]["login"].to(login);
        a_result[0]["password"].to(password);

        return IUserRecordShrPtr(new UserRecord(id_user, login, password));
    }
    else
    {
        return IUserRecordShrPtr();
    }
}

} // namespace User
} // namespace GameServer
