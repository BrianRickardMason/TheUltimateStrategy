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

#include "PropertyManager.hpp"

#include <boost/make_shared.hpp>

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace boost;

namespace GameServer
{
namespace Property
{

PropertyManager::PropertyManager(
    IPropertyManagerAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

PropertyBooleanShrPtr PropertyManager::getPropertyBoolean(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash,
    IDProperty         const & a_id_property
) const
{
    PropertyRecordShrPtr property_record_shr_ptr = m_accessor->getPropertyRecord(a_transaction, a_key_hash, a_id_property);

    BOOST_ASSERT(DISCRIMINATOR_BOOLEAN == property_record_shr_ptr->getDiscriminator());

    if (property_record_shr_ptr)
    {
        return make_shared<PropertyBoolean>(property_record_shr_ptr);
    }
    else
    {
        BOOST_ASSERT(false);
    }
}

PropertyIntegerShrPtr PropertyManager::getPropertyInteger(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash,
    IDProperty         const & a_id_property
) const
{
    PropertyRecordShrPtr property_record_shr_ptr = m_accessor->getPropertyRecord(a_transaction, a_key_hash, a_id_property);

    BOOST_ASSERT(DISCRIMINATOR_INTEGER == property_record_shr_ptr->getDiscriminator());

    if (property_record_shr_ptr)
    {
        return make_shared<PropertyInteger>(property_record_shr_ptr);
    }
    else
    {
        BOOST_ASSERT(false);
    }
}

PropertyStringShrPtr PropertyManager::getPropertyString(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash,
    IDProperty         const & a_id_property
) const
{
    PropertyRecordShrPtr property_record_shr_ptr = m_accessor->getPropertyRecord(a_transaction, a_key_hash, a_id_property);

    BOOST_ASSERT(DISCRIMINATOR_STRING == property_record_shr_ptr->getDiscriminator());

    if (property_record_shr_ptr)
    {
        return make_shared<PropertyString>(property_record_shr_ptr);
    }
    else
    {
        BOOST_ASSERT(false);
    }
}

PropertySet PropertyManager::getProperties(
    ITransactionShrPtr         a_transaction,
    KeyHash            const & a_key_hash
) const
{
    PropertyRecordMap records = m_accessor->getPropertyRecords(a_transaction, a_key_hash);

    PropertyMap result;

    for (PropertyRecordMap::const_iterator it = records.begin(); it != records.end(); ++it)
    {
        if (it->second)
        {
            PropertyShrPtr property;

            switch (it->second->getDiscriminator())
            {
                case DISCRIMINATOR_BOOLEAN:
                    property = make_shared<PropertyBoolean>(it->second);
                    break;
                case DISCRIMINATOR_INTEGER:
                    property = make_shared<PropertyInteger>(it->second);
                    break;
                case DISCRIMINATOR_STRING:
                    property = make_shared<PropertyString>(it->second);
                    break;
                default:
                    BOOST_ASSERT(false);
            }

            PropertyPair pair(it->second->getIDProperty(), property);

            result.insert(pair);
        }
        // This should never happen.
        else
        {
            BOOST_ASSERT(false);
        }
    }

    PropertySet set(result);

    return set;
}

} // namespace Property
} // namespace GameServer
