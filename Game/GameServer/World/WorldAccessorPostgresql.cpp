// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#include <Game/GameServer/Persistence/TransactionPostgresql.hpp>
#include <Game/GameServer/World/WorldAccessorPostgresql.hpp>
#include <Game/GameServer/World/WorldRecord.hpp>

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace World
{

void WorldAccessorPostgresql::insertRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO worlds(world_name) VALUES("
                   + backbone_transaction.quote(a_world_name) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

IWorldRecordShrPtr WorldAccessorPostgresql::getRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM worlds WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        string world_name;

        result[0]["world_name"].to(world_name);

        return IWorldRecordShrPtr(new WorldRecord(world_name));
    }
    else
    {
        return IWorldRecordShrPtr();
    }
}

IWorldRecordMap WorldAccessorPostgresql::getRecords(
    ITransactionShrPtr a_transaction
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM worlds";

    pqxx::result result = backbone_transaction.exec(query);

    IWorldRecordMap records;

    string world_name;

    for (pqxx::result::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        it["world_name"].to(world_name);

        IWorldRecordShrPtr record = IWorldRecordShrPtr(new WorldRecord(world_name));
        IWorldRecordPair pair(world_name, record);
        records.insert(pair);
    }

    return records;
}

string WorldAccessorPostgresql::getWorldNameOfLand(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT world_name FROM lands WHERE land_name = " + backbone_transaction.quote(a_land_name);

    pqxx::result result = backbone_transaction.exec(query);

    string world_name;

    if (result.size() > 0)
    {
        result[0]["world_name"].to(world_name);

        return world_name;
    }
    else
    {
        return "";
    }
}

} // namespace World
} // namespace GameServer
