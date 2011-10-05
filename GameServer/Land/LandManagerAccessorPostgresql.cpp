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
#include "LandManagerAccessorPostgresql.hpp"

using namespace GameServer::Epoch;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Land
{

void LandManagerAccessorPostgresql::insertRecord(
    ITransactionShrPtr         a_transaction,
    string             const   a_login,
    string             const   a_world_name,
    IDEpoch            const & a_id_epoch,
    string             const   a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO lands(login, world_name, id_epoch, land_name) VALUES("
                   + backbone_transaction.quote(a_login) + ", "
                   + backbone_transaction.quote(a_world_name) + ", "
                   + backbone_transaction.quote(a_id_epoch.getValue()) + ", "
                   + backbone_transaction.quote(a_land_name) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void LandManagerAccessorPostgresql::deleteRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM lands WHERE land_name = "
                   + backbone_transaction.quote(a_land_name);

    pqxx::result result = backbone_transaction.exec(query);
}

LandRecordShrPtr LandManagerAccessorPostgresql::getRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE land_name = "
                   + backbone_transaction.quote(a_land_name);

    return prepareResultGetRecord(backbone_transaction.exec(query));
}

LandRecordShrPtr LandManagerAccessorPostgresql::getRecordByLogin(
    ITransactionShrPtr       a_transaction,
    string             const a_login,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE land_name = "
                   + backbone_transaction.quote(a_land_name)
                   + " AND login = " + backbone_transaction.quote(a_login);

    return prepareResultGetRecord(backbone_transaction.exec(query));
}

LandRecordShrPtr LandManagerAccessorPostgresql::getRecordByWorldName(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE land_name = "
                   + backbone_transaction.quote(a_land_name)
                   + " AND world_name = " + backbone_transaction.quote(a_world_name);

    return prepareResultGetRecord(backbone_transaction.exec(query));
}

LandRecordMap LandManagerAccessorPostgresql::getRecords(
    ITransactionShrPtr a_transaction
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands";

    return prepareResultGetRecords(backbone_transaction.exec(query));
}

LandRecordMap LandManagerAccessorPostgresql::getRecordsByLogin(
    ITransactionShrPtr       a_transaction,
    string             const a_login
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE login = "
                   + backbone_transaction.quote(a_login);

    return prepareResultGetRecords(backbone_transaction.exec(query));
}

LandRecordMap LandManagerAccessorPostgresql::getRecordsByWorldName(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE world_name = "
                   + backbone_transaction.quote(a_world_name);

    return prepareResultGetRecords(backbone_transaction.exec(query));
}

LandRecordMap LandManagerAccessorPostgresql::getRecords(
    ITransactionShrPtr       a_transaction,
    string             const a_login,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM lands WHERE login = "
                   + backbone_transaction.quote(a_login)
                   + " AND world_name = " + backbone_transaction.quote(a_world_name);

    return prepareResultGetRecords(backbone_transaction.exec(query));
}

void LandManagerAccessorPostgresql::markGranted(
    Persistency::ITransactionShrPtr       a_transaction,
    string                          const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE lands SET granted = true WHERE land_name = "
                   + backbone_transaction.quote(a_land_name);

    pqxx::result result = backbone_transaction.exec(query);
}

LandRecordShrPtr LandManagerAccessorPostgresql::prepareResultGetRecord(
    pqxx::result const & a_result
) const
{
    // Fake types for libpqxx.
    unsigned int unsigned_integer;

    if (a_result.size() > 0)
    {
        string login;
        string world_name;
        IDEpoch id_epoch;
        string land_name;
        bool granted;

        a_result[0]["login"].to(login);
        a_result[0]["world_name"].to(world_name);
        id_epoch = a_result[0]["id_epoch"].as(unsigned_integer);
        a_result[0]["land_name"].to(land_name);
        a_result[0]["granted"].to(granted);

        return make_shared<LandRecord>(login, world_name, id_epoch, land_name, granted);
    }
    else
    {
        return LandRecordShrPtr();
    }
}

LandRecordMap LandManagerAccessorPostgresql::prepareResultGetRecords(
    pqxx::result const & a_result
) const
{
    // Fake types for libpqxx.
    // TODO: Fake types should reflect the types of the policy of the ConstrainedValue.
    unsigned int unsigned_integer;

    string login;
    string world_name;
    IDEpoch id_epoch;
    string land_name;
    bool granted;

    LandRecordMap records;

    for (pqxx::result::const_iterator it = a_result.begin(); it != a_result.end(); ++it)
    {
        it["login"].to(login);
        it["world_name"].to(world_name);
        id_epoch = it["id_epoch"].as(unsigned_integer);
        it["land_name"].to(land_name);
        it["granted"].to(granted);

        LandRecordShrPtr record = make_shared<LandRecord>(login, world_name, id_epoch, land_name, granted);
        LandRecordPair pair(land_name, record);
        records.insert(pair);
    }

    return records;
}

} // namespace Land
} // namespace GameServer
