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
#include <Game/GameServer/Epoch/EpochAccessorPostgresql.hpp>

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Epoch
{

void EpochAccessorPostgresql::insertRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name,
    string             const a_epoch_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "INSERT INTO epochs(epoch_name, world_name) VALUES("
                   + backbone_transaction.quote(a_epoch_name) + ", "
                   + backbone_transaction.quote(a_world_name) + ")";

    pqxx::result result = backbone_transaction.exec(query);
}

void EpochAccessorPostgresql::deleteRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "DELETE FROM epochs WHERE world_name = "
                   + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);
}

IEpochRecordShrPtr EpochAccessorPostgresql::getRecord(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM epochs WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);

    // Fake types for libpqxx.
    unsigned int unsigned_integer;
    bool boolean;

    if (result.size() > 0)
    {
        string epoch_name;
        string world_name;
        bool active, finished;
        unsigned int ticks;

        result[0]["epoch_name"].to(epoch_name);
        result[0]["world_name"].to(world_name);
        active   = result[0]["active"  ].as(boolean);
        finished = result[0]["finished"].as(boolean);
        ticks    = result[0]["ticks"   ].as(unsigned_integer);

        return make_shared<EpochRecord>(epoch_name, world_name, active, finished, ticks);
    }
    else
    {
        return IEpochRecordShrPtr();
    }
}

void EpochAccessorPostgresql::markActive(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE epochs SET active = true WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);
}

void EpochAccessorPostgresql::markUnactive(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE epochs SET active = false WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);
}

void EpochAccessorPostgresql::markFinished(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE epochs SET finished = true WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);
}

void EpochAccessorPostgresql::incrementTicks(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "UPDATE epochs SET ticks  = ticks + 1 WHERE world_name = " + backbone_transaction.quote(a_world_name);

    pqxx::result result = backbone_transaction.exec(query);
}

string EpochAccessorPostgresql::getWorldNameOfLand(
    Persistence::ITransactionShrPtr       a_transaction,
    string                          const a_land_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT world_name FROM lands WHERE land_name = " + backbone_transaction.quote(a_land_name);

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        string world_name;
        result[0]["world_name"].to(world_name);
        return world_name;
    }
    else
    {
        return "";
    }
}

string EpochAccessorPostgresql::getLandNameOfSettlement(
    Persistence::ITransactionShrPtr       a_transaction,
    string                          const a_settlement_name
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT land_name FROM settlements WHERE settlement_name = " + backbone_transaction.quote(a_settlement_name);

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        string land_name;
        result[0]["land_name"].to(land_name);
        return land_name;
    }
    else
    {
        return "";
    }
}

} // namespace Epoch
} // namespace GameServer
