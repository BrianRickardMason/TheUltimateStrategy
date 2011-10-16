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
#include "CostManagerAccessorPostgresql.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

using GameServer::Resource::IDResource;

namespace GameServer
{
namespace Cost
{

CostRecordVec CostManagerAccessorPostgresql::getCosts(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash,
    IDCostType         const & a_id_cost_type
) const
{
    TransactionPostgresqlShrPtr transaction = shared_dynamic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM costs WHERE key_hash = " + backbone_transaction.quote(a_key_hash)
                   + " AND id_cost_type = " + backbone_transaction.quote(a_id_cost_type);

    pqxx::result result = backbone_transaction.exec(query);

    CostRecordVec records;

    // Fake types for libpqxx.
    int integer;

    IDResource id_resource;
    Volume volume;

    for (pqxx::result::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        id_resource = it["id_resource"].as(integer); // TODO: Verify "as" method handling.
        volume = it["volume"].as(integer);

        CostRecordShrPtr cost_record_shr_ptr = make_shared<CostRecord>(a_key_hash, a_id_cost_type, id_resource, volume);

        records.push_back(cost_record_shr_ptr);
    }

    return records;
}

} // namespace Cost
} // namespace GameServer
