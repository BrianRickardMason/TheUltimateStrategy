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
#include "AuthorizationManagerAccessorPostgresql.hpp"

using namespace GameServer::Land;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Authorization
{

bool AuthorizationManagerAccessorPostgresql::authorizeUserToLand(
    ITransactionShrPtr         a_transaction,
    string             const   a_login,
    IDLand             const & a_id_land
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE login = " + backbone_transaction.quote(a_login)
                   + " AND id_land = " + backbone_transaction.quote(a_id_land.getValue());

    pqxx::result result = backbone_transaction.exec(query);

    return result.size() ? true : false;
}

bool AuthorizationManagerAccessorPostgresql::authorizeUserToLand(
    ITransactionShrPtr         a_transaction,
    string             const   a_login,
    string             const & a_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE login = " + backbone_transaction.quote(a_login)
                   + " AND name = " + backbone_transaction.quote(a_name);

    pqxx::result result = backbone_transaction.exec(query);

    return result.size() ? true : false;
}

IDLand AuthorizationManagerAccessorPostgresql::getIDLandOfSettlement(
    ITransactionShrPtr               a_transaction,
    Settlement::IDSettlement const & a_id_settlement
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT id_land FROM settlements WHERE id_settlement = " + backbone_transaction.quote(a_id_settlement.getValue());

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        unsigned int id_land;
        result[0]["id_land"].to(id_land);
        return IDLand(id_land);
    }
    else
    {
        return IDLand(0);
    }
}

} // namespace Authorization
} // namespace GameServer
