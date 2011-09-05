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

#ifndef GAMESERVER_PROPERTY_PROPERTYSET_HPP
#define GAMESERVER_PROPERTY_PROPERTYSET_HPP

#include "Property.hpp"

namespace GameServer
{
namespace Property
{

/**
 * @brief A property set.
 */
class PropertySet
{
public:
    /**
     * @brief Constructs a property set.
     *
     * @param a_property_map A map of properties.
     */
    PropertySet(
        PropertyMap const & a_property_map
    );

    /**
     * @brief Gets a given boolean property.
     *
     * @param a_id_property An identifier of the property.
     *
     * @return The boolean property.
     *
     * @throws std::out_of_range If property has not been found in the map.
     * @throws std::bad_cast     If an attempt to invalid cast has been noticed.
     */
    PropertyBooleanShrPtr const getBooleanProperty(
        IDProperty const & a_id_property
    ) const;

    /**
     * @brief Gets a given integer property.
     *
     * @param a_id_property An identifier of the property.
     *
     * @return The integer property.
     *
     * @throws std::out_of_range If property has not been found in the map.
     * @throws std::bad_cast     If an attempt to invalid cast has been noticed.
     */
    PropertyIntegerShrPtr const getIntegerProperty(
        IDProperty const & a_id_property
    ) const;

    /**
     * @brief Gets a given string property.
     *
     * @param a_id_property An identifier of the property.
     *
     * @return The string property.
     *
     * @throws std::out_of_range If property has not been found in the map.
     * @throws std::bad_cast     If an attempt to invalid cast has been noticed.
     */
    PropertyStringShrPtr const getStringProperty(
        IDProperty const & a_id_property
    ) const;

private:
    /**
     * @brief A map of properties.
     */
    PropertyMap m_map;
};

} // namespace Property
} // namespace GameServer

#endif // GAMESERVER_PROPERTY_PROPERTYSET_HPP
