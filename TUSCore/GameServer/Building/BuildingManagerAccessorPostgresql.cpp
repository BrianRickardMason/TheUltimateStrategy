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
#include "BuildingManagerAccessorPostgresql.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Building
{

void BuildingManagerAccessorPostgresql::insertRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO "
                   + getTableName(a_id_holder)
                   + "(holder_name, id_building_class, id_building, volume) VALUES("
                   + backbone_transaction.quote(a_id_holder.getValue2()) + ", "
                   + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue1()) + ", "
                   + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue2()) + ", "
                   + backbone_transaction.quote(a_volume) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void BuildingManagerAccessorPostgresql::deleteRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND id_building_class = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue1())
                   + " AND id_building = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue2());

    pqxx::result result = backbone_transaction.exec(query);
}

BuildingWithVolumeRecordShrPtr BuildingManagerAccessorPostgresql::getRecord(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT volume FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND id_building_class = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue1())
                   + " AND id_building = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue2());

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        Volume volume;
        result[0]["volume"].to(volume);
        return make_shared<BuildingWithVolumeRecord>(a_id_holder, a_key, volume);
    }
    else
    {
        return BuildingWithVolumeRecordShrPtr();
    }
}

BuildingWithVolumeRecordMap BuildingManagerAccessorPostgresql::getRecords(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder
) const
{
    // Fake types for libpqxx.
    unsigned int unsigned_integer;

    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM "
                   + getTableName(a_id_holder)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2());

    pqxx::result result = backbone_transaction.exec(query);

    BuildingWithVolumeRecordMap records;

    Volume volume;

    for (pqxx::result::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        IDBuilding id_building(it["id_building_class"].as(unsigned_integer), it["id_building"].as(unsigned_integer));
        it["volume"].to(volume);

        Key key(id_building);

        BuildingWithVolumeRecordShrPtr record = make_shared<BuildingWithVolumeRecord>(a_id_holder, key, volume);

        BuildingWithVolumeRecordPair pair(key, record);

        records.insert(pair);
    }

    return records;
}

void BuildingManagerAccessorPostgresql::increaseVolume(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE "
                   + getTableName(a_id_holder)
                   + " SET volume = volume + " + backbone_transaction.quote(a_volume)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND id_building_class = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue1())
                   + " AND id_building = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue2());

    pqxx::result result = backbone_transaction.exec(query);
}

void BuildingManagerAccessorPostgresql::decreaseVolume(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE "
                   + getTableName(a_id_holder)
                   + " SET volume = volume - " + backbone_transaction.quote(a_volume)
                   + " WHERE holder_name = " + backbone_transaction.quote(a_id_holder.getValue2())
                   + " AND id_building_class = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue1())
                   + " AND id_building = " + backbone_transaction.quote(a_key.getInternalKey().get<0>().getValue2());

    pqxx::result result = backbone_transaction.exec(query);
}

string BuildingManagerAccessorPostgresql::getTableName(
    IDHolder const & a_id_holder
) const
{
    return string("buildings_settlement");
}

} // namespace Building
} // namespace GameServer
