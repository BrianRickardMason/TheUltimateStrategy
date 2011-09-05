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

#ifndef GAMESERVER_RESOURCE_RESOURCE_HPP
#define GAMESERVER_RESOURCE_RESOURCE_HPP

#include "Key.hpp"
#include <vector>

namespace GameServer
{
namespace Resource
{

/**
 * @brief A resource.
 */
class Resource
{
public:
    /**
     * @brief Constructs the resource.
     *
     * @param a_key The key of the resource.
     */
    explicit Resource(
        Key const & a_key
    );

    /**
     * @brief Gets the key of the resource.
     *
     * @return The key of the resource.
     */
    Key const & getKey() const;

    /**
     * @brief Gets the identifier of the resource.
     *
     * @return The identifier of the resource.
     */
    IDResource const & getIDResource() const;

private:
    /**
     * @brief The key of the resource.
     */
    Key m_key;
};


/**
 * @brief The available resources.
 */
const Resource RESOURCE_COAL (KEY_RESOURCE_COAL);
const Resource RESOURCE_FOOD (KEY_RESOURCE_FOOD);
const Resource RESOURCE_GOLD (KEY_RESOURCE_GOLD);
const Resource RESOURCE_IRON (KEY_RESOURCE_IRON);
const Resource RESOURCE_MANA (KEY_RESOURCE_MANA);
const Resource RESOURCE_ROCK (KEY_RESOURCE_ROCK);
const Resource RESOURCE_WOOD (KEY_RESOURCE_WOOD);

/**
 * @brief The array of available resources.
 */
const Resource RESOURCE_ARR [] = {
    RESOURCE_COAL,
    RESOURCE_FOOD,
    RESOURCE_GOLD,
    RESOURCE_IRON,
    RESOURCE_MANA,
    RESOURCE_ROCK,
    RESOURCE_WOOD
};

/**
 * @brief The vector of resources.
 */
typedef std::vector<Resource> ResourceVec;

/**
 * @brief The vector of available resources.
 *
 * TODO: Use in UT and CT.
 */
const ResourceVec RESOURCE_VEC(
    RESOURCE_ARR,
    RESOURCE_ARR + sizeof(RESOURCE_ARR) / sizeof(RESOURCE_ARR[0])
);

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_RESOURCE_HPP
