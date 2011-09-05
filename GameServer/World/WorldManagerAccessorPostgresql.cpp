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

#include "WorldManagerAccessorPostgresql.hpp"

#include "../Persistency/TransactionPostgresql.hpp"

using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace World
{

void WorldManagerAccessorPostgresql::insertRecord(
    ITransactionShrPtr         a_transaction,
    string             const & a_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO worlds(name) VALUES("
                   + backbone_transaction.quote(a_name) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

WorldRecordShrPtr WorldManagerAccessorPostgresql::getRecord(
    ITransactionShrPtr         a_transaction,
    IDWorld            const & a_id_world
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM worlds WHERE id_world = " + backbone_transaction.quote(a_id_world.getValue());

    pqxx::result result = backbone_transaction.exec(query);

    // Fake types for libpqxx.
    unsigned int unsigned_integer;

    if (result.size() > 0)
    {
        IDWorld id_world;
        string name;

        id_world = result[0]["id_world"].as(unsigned_integer);
        result[0]["name"].to(name);

        return make_shared<WorldRecord>(id_world, name);
    }
    else
    {
        return WorldRecordShrPtr();
    }
}

WorldRecordMap WorldManagerAccessorPostgresql::getRecords(
    ITransactionShrPtr a_transaction
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM worlds";

    pqxx::result result = backbone_transaction.exec(query);

    WorldRecordMap records;

    // Fake types for libpqxx.
    unsigned int unsigned_integer;

    IDWorld id_world;
    string name;

    for (pqxx::result::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        id_world = it["id_world"].as(unsigned_integer);
        it["name"].to(name);

        WorldRecordShrPtr record = make_shared<WorldRecord>(id_world, name);
        WorldRecordPair pair(id_world, record);
        records.insert(pair);
    }

    return records;
}

IDWorld WorldManagerAccessorPostgresql::getIDWorldOfLand(
    Persistency::ITransactionShrPtr         a_transaction,
    Land::IDLand                    const & a_id_land
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT id_world FROM lands WHERE id_land = " + backbone_transaction.quote(a_id_land.getValue());

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        unsigned int id_world;
        result[0]["id_world"].to(id_world);
        return IDWorld(id_world);
    }
    else
    {
        return IDWorld(0);
    }
}

} // namespace World
} // namespace GameServer
