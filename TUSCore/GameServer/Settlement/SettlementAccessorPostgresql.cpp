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

#include "../Persistence/TransactionPostgresql.hpp"
#include "SettlementAccessorPostgresql.hpp"
#include "SettlementRecord.hpp"

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Settlement
{

void SettlementAccessorPostgresql::insertRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name,
    string             const a_settlement_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO settlements(land_name, settlement_name) VALUES("
                   + backbone_transaction.quote(a_land_name) + ", "
                   + backbone_transaction.quote(a_settlement_name) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void SettlementAccessorPostgresql::deleteRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM settlements WHERE settlement_name = "
                   + backbone_transaction.quote(a_settlement_name);

    pqxx::result result = backbone_transaction.exec(query);
}

ISettlementRecordShrPtr SettlementAccessorPostgresql::getRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM settlements WHERE settlement_name = "
                   + backbone_transaction.quote(a_settlement_name);

    return prepareResultGetRecord(backbone_transaction.exec(query));
}

ISettlementRecordMap SettlementAccessorPostgresql::getRecords(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM settlements WHERE land_name = " + backbone_transaction.quote(a_land_name);

    return prepareResultGetRecords(backbone_transaction.exec(query));
}

ISettlementRecordShrPtr SettlementAccessorPostgresql::prepareResultGetRecord(
    pqxx::result const & a_result
) const
{
    if (a_result.size() > 0)
    {
        string land_name;
        string settlement_name;

        a_result[0]["land_name"].to(land_name);
        a_result[0]["settlement_name"].to(settlement_name);

        return ISettlementRecordShrPtr(new SettlementRecord(land_name, settlement_name));
    }
    else
    {
        return ISettlementRecordShrPtr();
    }
}

ISettlementRecordMap SettlementAccessorPostgresql::prepareResultGetRecords(
    pqxx::result const & a_result
) const
{
    string land_name;
    string settlement_name;

    ISettlementRecordMap records;

    for (pqxx::result::const_iterator it = a_result.begin(); it != a_result.end(); ++it)
    {
        it["land_name"].to(land_name);
        it["settlement_name"].to(settlement_name);

        ISettlementRecordShrPtr record = ISettlementRecordShrPtr(new SettlementRecord(land_name, settlement_name));
        ISettlementRecordPair pair(settlement_name, record);
        records.insert(pair);
    }

    return records;
}

} // namespace Settlement
} // namespace GameServer
