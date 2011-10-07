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
#include "PropertyManagerAccessorPostgresql.hpp"
#include <boost/make_shared.hpp>
#include <string>

using namespace GameServer::Common;
using namespace GameServer::Persistency;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Property
{

PropertyRecordShrPtr PropertyManagerAccessorPostgresql::getPropertyRecord(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash,
    IDProperty         const & a_id_property
) const
{
    // Fake types for libpqxx.
    unsigned short int unsigned_short_integer;

    TransactionPostgresqlShrPtr transaction = shared_polymorphic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM properties WHERE key_hash = " + backbone_transaction.quote(a_key_hash)
                   + " AND id_property = " + backbone_transaction.quote(a_id_property.getValue());

    pqxx::result result = backbone_transaction.exec(query);

    if (result.size() > 0)
    {
        Discriminator value_discriminator;
        bool value_boolean;
        int value_integer;
        string value_string;

        IDProperty id_property(result[0]["id_property"].as(unsigned_short_integer));
        result[0]["value_discriminator"].to(value_discriminator);
        result[0]["value_boolean"].to(value_boolean);
        result[0]["value_integer"].to(value_integer);
        result[0]["value_string"].to(value_string);

        return make_shared<PropertyRecord>(a_key_hash, id_property, value_discriminator, value_boolean, value_integer, value_string);
    }
    else
    {
        return PropertyRecordShrPtr();
    }
}

PropertyRecordMap PropertyManagerAccessorPostgresql::getPropertyRecords(
    Persistency::ITransactionShrPtr         a_transaction,
    Common::KeyHash                 const & a_key_hash
) const
{
    // Fake types for libpqxx.
    unsigned short int unsigned_short_integer;

    TransactionPostgresqlShrPtr transaction = shared_polymorphic_cast<TransactionPostgresql>(a_transaction);
    pqxx::transaction<> & backbone_transaction = transaction->getBackboneTransaction();

    string query = "SELECT * FROM properties WHERE key_hash = " + backbone_transaction.quote(a_key_hash);

    pqxx::result result = backbone_transaction.exec(query);

    PropertyRecordMap records;

    Discriminator value_discriminator;
    bool value_boolean;
    int value_integer;
    string value_string;

    for (pqxx::result::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        IDProperty id_property(it["id_property"].as(unsigned_short_integer));
        it["value_discriminator"].to(value_discriminator);
        it["value_boolean"].to(value_boolean);
        it["value_integer"].to(value_integer);
        it["value_string"].to(value_string);

        PropertyRecordShrPtr property_record_shr_ptr =
            make_shared<PropertyRecord>(a_key_hash, id_property, value_discriminator, value_boolean, value_integer, value_string);

        records.insert(PropertyRecordPair(id_property, property_record_shr_ptr));
    }

    return records;
}

} // namespace Property
} // namespace GameServer
