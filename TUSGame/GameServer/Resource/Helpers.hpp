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

#ifndef GAMESERVER_RESOURCE_HELPERS_HPP
#define GAMESERVER_RESOURCE_HELPERS_HPP

#include <TUSGame/GameServer/Resource/ResourceWithVolume.hpp>

namespace GameServer
{
namespace Resource
{

/**
 * FIXME: Dear future me. This is as ugly as it gets... Please invent the time machine and slap me.
 */

/**
 * @brief Adds two maps of resources.
 *
 * @param a_context The context of the server.
 * @param a_map_1   The map to be added.
 * @param a_map_2   The map to be added.
 *
 * @return The sum of two maps.
 */
ResourceWithVolumeMap add(
    IContextShrPtr        const   a_context,
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
);

/**
 * @brief Multiplies the map by a given factor.
 *
 * @param a_context The context of the server.
 * @param a_map     The map to be multiplied.
 * @param a_factor  The factor.
 *
 * @return The sum of two maps.
 */
ResourceWithVolumeMap multiply(
    IContextShrPtr        const   a_context,
    ResourceWithVolumeMap const & a_map,
    unsigned int          const   a_factor
);

/**
 * @brief Checks if two maps are the same.
 *
 * @param a_map_1 The map to be compared.
 * @param a_map_2 The map to be compared.
 *
 * @return True if two maps are the same, false otherwise.
 */
bool areEqual(
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
);

/**
 * @brief Checks if the first map is greater than the second one.
 *
 * @param a_map_1 The map to be compared.
 * @param a_map_2 The map to be compared.
 *
 * @return True if the first map is greater, false otherwise.
 */
bool isFirstGreaterOrEqual(
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
);

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_HELPERS_HPP
