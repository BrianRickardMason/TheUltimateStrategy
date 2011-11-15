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

#ifndef GAMESERVER_PROPERTY_IPROPERTYACCESSOR_HPP
#define GAMESERVER_PROPERTY_IPROPERTYACCESSOR_HPP

#include "../Common/KeyHash.hpp"
#include "../Persistence/IPersistence.hpp"
#include "PropertyRecord.hpp"
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>
#include <string>

namespace GameServer
{
namespace Property
{

/**
 * @brief An interface of property accessor.
 */
class IPropertyAccessor
    : boost::noncopyable
{
public:
    virtual ~IPropertyAccessor(){};

    /**
     * @brief Gets a property record.
     *
     * @param a_transaction A transaction.
     * @param a_key         A key.
     * @param a_id_property An identifier of the property
     *
     * @return The property record, null if not found.
     */
    virtual PropertyRecordShrPtr getPropertyRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const & a_key,
        IDProperty                      const & a_id_property
    ) const = 0;

    /**
     * @brief Gets a set of property records.
     *
     * @param a_transaction A transaction.
     * @param a_key         A key.
     *
     * @return A map of property records, an empty map if not found.
     */
    virtual PropertyRecordMap getPropertyRecords(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const & a_key
    ) const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<IPropertyAccessor> IPropertyAccessorAutPtr;
typedef boost::scoped_ptr<IPropertyAccessor> IPropertyAccessorScpPtr;
//}@

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_IPROPERTYACCESSOR_HPP
