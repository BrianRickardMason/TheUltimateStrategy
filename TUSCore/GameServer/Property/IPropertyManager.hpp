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

#ifndef GAMESERVER_PROPERTY_IPROPERTYMANAGER_HPP
#define GAMESERVER_PROPERTY_IPROPERTYMANAGER_HPP

#include "../Common/KeyHash.hpp"
#include "../Persistency/ITransaction.hpp"
#include "Property.hpp"
#include "PropertySet.hpp"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Property
{

/**
 * @brief An interface of property manager.
 */
class IPropertyManager
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the property manager.
     */
    virtual ~IPropertyManager(){};

    /**
     * @brief Gets a property boolean.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    virtual PropertyBooleanShrPtr getPropertyBoolean(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::KeyHash                 const & a_key_hash,
        IDProperty                      const & a_id_property
    ) const = 0;

    /**
     * @brief Gets a property integer.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    virtual PropertyIntegerShrPtr getPropertyInteger(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::KeyHash                 const & a_key_hash,
        IDProperty                      const & a_id_property
    ) const = 0;

    /**
     * @brief Gets a property string.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    virtual PropertyStringShrPtr getPropertyString(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::KeyHash                 const & a_key_hash,
        IDProperty                      const & a_id_property
    ) const = 0;

    /**
     * @brief Gets a set of properties.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     *
     * @return The set of properties.
     */
    virtual PropertySet getProperties(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::KeyHash                 const & a_key_hash
    ) const = 0;
};

/**
 * @brief A shared pointer of interface of property manager.
 */
typedef boost::shared_ptr<IPropertyManager> IPropertyManagerShrPtr;

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_IPROPERTYMANAGER_HPP
