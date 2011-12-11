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

#include <GameServer/Human/HumanAccessorPostgresql.hpp>
#include <GameServer/Persistence/TransactionPostgresql.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Human
{

void HumanAccessorPostgresql::insertRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO "
                   + getTableName(a_id_holder)
                   + "(holder_name, human_key, volume) VALUES("
                   + backbone_transaction.quote(a_id_holder.getValue2()) + ", "
                   + backbone_transaction.quote(a_key.c_str()) + ", "
                   + backbone_transaction.quote(a_volume) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void HumanAccessorPostgresql::deleteRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND human_key = " + backbone_transaction.quote(a_key.c_str());

    pqxx::result result = backbone_transaction.exec(query);
}

HumanWithVolumeRecordShrPtr HumanAccessorPostgresql::getRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT volume FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND human_key = " + backbone_transaction.quote(a_key.c_str());

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        Volume volume;
        result[0]["volume"].to(volume);
        return make_shared<HumanWithVolumeRecord>(a_id_holder, a_key, volume);
    }
    else
    {
        return HumanWithVolumeRecordShrPtr();
    }
}

HumanWithVolumeRecordMap HumanAccessorPostgresql::getRecords(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2());

    return prepareResultGetRecords(backbone_transaction.exec(query), a_id_holder);
}

void HumanAccessorPostgresql::increaseVolume(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE "
                   + getTableName(a_id_holder)
                   + " SET volume = volume + " + backbone_transaction.quote(a_volume)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND human_key = " + backbone_transaction.quote(a_key.c_str());

    pqxx::result result = backbone_transaction.exec(query);
}

void HumanAccessorPostgresql::decreaseVolume(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE "
                   + getTableName(a_id_holder)
                   + " SET volume = volume - " + backbone_transaction.quote(a_volume)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND human_key = " + backbone_transaction.quote(a_key.c_str());

    pqxx::result result = backbone_transaction.exec(query);
}


Volume HumanAccessorPostgresql::countHumans(
    Persistence::ITransactionShrPtr       a_transaction,
    std::string                     const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT SUM(volume) AS volume FROM humans_settlement "
                   "WHERE holder_name IN (SELECT settlement_name FROM settlements WHERE land_name = "
                   + backbone_transaction.quote(a_land_name.c_str()) +
                   ")";

    pqxx::result result = backbone_transaction.exec(query);

    Volume volume;
    result[0]["volume"].to(volume);

    return volume;
}

HumanWithVolumeRecordMap HumanAccessorPostgresql::prepareResultGetRecords(
    pqxx::result const & a_result,
    IDHolder     const & a_id_holder
) const
{
    // Create a result map.
    HumanWithVolumeRecordMap records;

    // Prepare types for the values to be written to.
    string key;
    Volume volume;

    for (pqxx::result::const_iterator it = a_result.begin(); it != a_result.end(); ++it)
    {
        // Get the values.
        it["human_key"].to(key);
        it["volume"].to(volume);

        // Create a corresponding record.
        HumanWithVolumeRecordShrPtr record = make_shared<HumanWithVolumeRecord>(a_id_holder, key, volume);

        // Create a pair.
        HumanWithVolumeRecordPair pair(key, record);

        // Add record to the result.
        records.insert(pair);
    }

    return records;
}

string HumanAccessorPostgresql::getTableName(
    IDHolder const & a_id_holder
) const
{
    return string("humans_settlement");
}

} // namespace Human
} // namespace GameServer
