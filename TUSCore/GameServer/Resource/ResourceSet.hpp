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

#ifndef GAMESERVER_RESOURCE_RESOURCESET_HPP
#define GAMESERVER_RESOURCE_RESOURCESET_HPP

#include "ResourceWithVolume.hpp"

namespace GameServer
{
namespace Resource
{

/**
 * @brief A resource set.
 *
 * FIXME: This implementation is fatal now.
 */
class ResourceSet
{
public:
    /**
     * @brief Constructs a resource set.
     */
    ResourceSet();

    /**
     * @brief Constructs a resource set.
     *
     * @param a_resource_with_volume_map A map of resources.
     */
    ResourceSet(
        ResourceWithVolumeMap const & a_resource_with_volume_map
    );

    /**
     * @brief Copy constructor.
     */
    ResourceSet(
        ResourceSet const & a_rhs
    );

    /**
     * @brief Arithmetic operators.
     */
    ResourceSet const operator +(
        ResourceSet const & a_rhs
    ) const;

    ResourceSet const operator *(
        unsigned int const a_factor
    ) const;

    /**
     * @brief Relational operators.
     */
    bool operator ==(
        ResourceSet const & a_rhs
    ) const;

    bool operator >=(
        ResourceSet const & a_rhs
    ) const;

    /**
     * @brief Compound assignment operators.
     */
    ResourceSet operator +=(
        ResourceSet const & a_rhs
    );

    ResourceSet operator *=(
        unsigned int const a_factor
    );

    /**
     * @brief Gets a map of resources.
     *
     * @return The map of resources.
     */
    ResourceWithVolumeMap const & getMap() const;

private:
    /**
     * @brief A map of resources.
     */
    ResourceWithVolumeMap m_map;
};

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_RESOURCESET_HPP
