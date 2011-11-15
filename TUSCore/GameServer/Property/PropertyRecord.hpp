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

#ifndef GAMESERVER_PROPERTY_PROPERTYRECORD_HPP
#define GAMESERVER_PROPERTY_PROPERTYRECORD_HPP

#include "IDProperty.hpp"
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Property
{

/**
 * @brief A discriminator of property type.
 */
typedef unsigned short int Discriminator;

/**
 * @brief The discriminators of the property types.
 */
const Discriminator DISCRIMINATOR_BOOLEAN = 1;
const Discriminator DISCRIMINATOR_INTEGER = 2;
const Discriminator DISCRIMINATOR_STRING  = 3;

/**
 * @brief A property record.
 */
class PropertyRecord
{
public:
    /**
     * @brief Constructs a property record.
     *
     * @param a_key           A key.
     * @param a_id_property   An identifier of the property.
     * @param a_discriminator A discriminator of the property.
     * @param a_value_boolean A boolean value.
     * @param a_value_integer A integer value.
     * @param a_value_string  A string value.
     */
    PropertyRecord(
        std::string     const & a_key,
        IDProperty      const & a_id_property,
        Discriminator   const & a_discriminator,
        bool            const   a_value_boolean,
        int             const   a_value_integer,
        std::string     const & a_value_string
    );

    /**
     * @brief Gets the key.
     *
     * @return The key.
     */
    std::string const & getKey() const;

    /**
     * @brief Gets the identifier of the property.
     *
     * @return The identifier of the property.
     */
    IDProperty const & getIDProperty() const;

    /**
     * @brief Gets the property discriminator.
     *
     * @return The property discriminator.
     */
    Discriminator const & getDiscriminator() const;

    /**
     * @brief Gets the boolean value.
     *
     * @return The boolean value.
     */
    bool getValueBoolean() const;

    /**
     * @brief Gets the integer value.
     *
     * @return The integer value.
     */
    int getValueInteger() const;

    /**
     * @brief Gets the string value.
     *
     * @return The string value.
     */
    std::string const & getValueString() const;

private:
    /**
     * @brief The key.
     */
    std::string m_key;

    /**
     * @brief The identifier of the property.
     */
    IDProperty m_id_property;

    /**
     * @brief A discriminator of the property.
     */
    Discriminator m_discriminator;

    /**
     * @brief A boolean value.
     */
    bool m_value_boolean;

    /**
     * @brief An integer value.
     */
    int m_value_integer;

    /**
     * @brief A string value.
     */
    std::string m_value_string;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<PropertyRecord> PropertyRecordShrPtr;
typedef std::pair<IDProperty, PropertyRecordShrPtr> PropertyRecordPair;
typedef std::map<IDProperty, PropertyRecordShrPtr> PropertyRecordMap;
//}@

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_PROPERTYRECORD_HPP
