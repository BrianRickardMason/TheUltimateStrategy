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

#ifndef GAMESERVER_PROPERTY_PROPERTY_HPP
#define GAMESERVER_PROPERTY_PROPERTY_HPP

#include "PropertyRecord.hpp"

namespace GameServer
{
namespace Property
{

/**
 * @brief The property.
 *
 * TODO: Add global available properties.
 */
class Property
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_id_property An identifier of the property.
     */
    Property(
        IDProperty const & a_id_property
    );

    virtual ~Property(){}

    /**
     * @brief Gets the identifier of the property.
     *
     * @return The identifier of the property.
     */
    IDProperty const & getIDProperty() const;

private:
    /**
     * @brief An identifier of the property.
     */
    IDProperty m_id_property;
};

/**
 * @brief A shared pointer of property.
 */
typedef boost::shared_ptr<Property> PropertyShrPtr;

/**
 * @brief A pair of property.
 */
typedef std::pair<IDProperty, PropertyShrPtr> PropertyPair;

/**
 * @brief A map of property.
 */
typedef std::map<IDProperty, PropertyShrPtr> PropertyMap;

/**
 * @brief The boolean property.
 */
class PropertyBoolean
    : public Property
{
public:
    /**
     * @brief Constructs the property.
     *
     * @param a_property_record A property record.
     */
    explicit PropertyBoolean(
        PropertyRecordShrPtr a_property_record
    );

    /**
     * @brief Constructs the property.
     *
     * @param a_id_property An identifier of the property.
     * @param a_value       A value of the property.
     */
    PropertyBoolean(
        IDProperty const & a_id_property,
        bool       const & a_value
    );

    /**
     * @brief Gets the value of the property.
     *
     * @return The value of the property.
     */
    bool const & getValue() const;

private:
    /**
     * @brief A value of the property.
     */
    bool m_value;
};

/**
 * @brief A shared pointer of boolean property.
 */
typedef boost::shared_ptr<PropertyBoolean> PropertyBooleanShrPtr;

/**
 * @brief The integer property.
 */
class PropertyInteger
    : public Property
{
public:
    /**
     * @brief Constructs the property.
     *
     * @param a_property_record A property record.
     */
    explicit PropertyInteger(
        PropertyRecordShrPtr a_property_record
    );

    /**
     * @brief Constructs the property.
     *
     * @param a_id_property An identifier of the property.
     * @param a_value       A value of the property.
     */
    PropertyInteger(
        IDProperty const & a_id_property,
        int        const & a_value
    );

    /**
     * @brief Gets the value of the property.
     *
     * @return The value of the property.
     */
    int const & getValue() const;

private:
    /**
     * @brief A value of the property.
     */
    int m_value;
};

/**
 * @brief A shared pointer of integer property.
 */
typedef boost::shared_ptr<PropertyInteger> PropertyIntegerShrPtr;

/**
 * @brief The string property.
 */
class PropertyString
    : public Property
{
public:
    /**
     * @brief Constructs the property.
     *
     * @param a_property_record A property record.
     */
    explicit PropertyString(
        PropertyRecordShrPtr a_property_record
    );

    /**
     * @brief Constructs the property.
     *
     * @param a_id_property An identifier of the property.
     * @param a_value       A value of the property.
     */
    PropertyString(
        IDProperty  const & a_id_property,
        std::string const & a_value
    );

    /**
     * @brief Gets the value of the property.
     *
     * @return The value of the property.
     */
    std::string const & getValue() const;

private:
    /**
     * @brief A value of the property.
     */
    std::string m_value;
};

/**
 * @brief A shared pointer of string property.
 */
typedef boost::shared_ptr<PropertyString> PropertyStringShrPtr;

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_PROPERTY_HPP
