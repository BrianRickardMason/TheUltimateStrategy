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

#ifndef GAMESERVER_PROPERTY_PROPERTYMANAGERMOCK_HPP
#define GAMESERVER_PROPERTY_PROPERTYMANAGERMOCK_HPP

#include "../../GameServer/Property/IPropertyManager.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Property
{

class PropertySet;

/**
 * @brief A mock of property manager.
 */
class PropertyManagerMock
    : public IPropertyManager
{
public:
    /**
     * @brief Gets a property boolean.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    MOCK_CONST_METHOD3(
        getPropertyBoolean,
        PropertyBooleanShrPtr(
            Persistence::ITransactionShrPtr        a_transaction,
            Common::KeyHash                const & a_key_hash,
            IDProperty                     const & a_id_property
        )
    );

    /**
     * @brief Gets a property integer.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    MOCK_CONST_METHOD3(
        getPropertyInteger,
        PropertyIntegerShrPtr(
            Persistence::ITransactionShrPtr        a_transaction,
            Common::KeyHash                const & a_key_hash,
            IDProperty                     const & a_id_property
        )
    );

    /**
     * @brief Gets a property string.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     * @param a_id_property An identifier of the property
     *
     * @return The property.
     */
    MOCK_CONST_METHOD3(
        getPropertyString,
        PropertyStringShrPtr(
            Persistence::ITransactionShrPtr        a_transaction,
            Common::KeyHash                const & a_key_hash,
            IDProperty                     const & a_id_property
        )
    );

    /**
     * @brief Gets a set of properties.
     *
     * @param a_transaction The transaction.
     * @param a_key_hash    A key hash.
     *
     * @return The set of properties.
     */
    MOCK_CONST_METHOD2(
        getProperties,
        PropertySet(
            Persistence::ITransactionShrPtr        a_transaction,
            Common::KeyHash                const & a_key_hash
        )
    );
};

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_PROPERTYMANAGERMOCK_HPP
