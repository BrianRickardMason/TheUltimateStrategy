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

#ifndef GAMESERVER_RESOURCE_KEY_HPP
#define GAMESERVER_RESOURCE_KEY_HPP

#include "../Common/KeyHash.hpp"
#include "IDResource.hpp"
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple.hpp>

namespace GameServer
{
namespace Resource
{

/**
 * @brief The key.
 *
 * Uniquely identifies a resource object.
 *
 * TODO: Use boost::operators.
 * TODO: Consider facilitators/stabilizators of the interface (getIdResource).
 *       First step to unification (base and derived classes/specialization).
 */
class Key
{
public:
    /**
     * @brief The internal key.
     */
    typedef boost::tuple<IDResource> InternalKey;

    /**
     * @brief Constructs the key.
     *
     * @param a_id_resource The identifier of the resource.
     */
    explicit Key(
        IDResource const & a_id_resource
    )
        : m_internal_key(a_id_resource)
    {
    }

    /**
     * @brief Constructs the key.
     *
     * @param a_key_hash A key hash.
     */
    explicit Key(
        Common::KeyHash const & a_key_hash
    )
        : m_internal_key(IDResource(a_key_hash % 100))
    {
    }

    /**
     * @brief Relational operators.
     */
    bool operator==(Key const & a_rhs) const { return m_internal_key == a_rhs.m_internal_key; }
    bool operator< (Key const & a_rhs) const { return m_internal_key <  a_rhs.m_internal_key; }

    /**
     * @brief Gets the internal key.
     *
     * @return The internal key.
     */
    InternalKey const & getInternalKey() const
    {
        return m_internal_key;
    }

    /**
     * @brief Translates the key to "hash" value.
     *
     * @return The "hash" value.
     */
    Common::KeyHash toHash() const
    {
        return   Common::KEY_HASH_MAGIC_VALUE_RESOURCE * 1000000
               + 0                                     * 10000
               + 0                                     * 100
               + m_internal_key.get<0>().getValue()    * 1;
    }

private:
    /**
     * @brief The internal key.
     */
    InternalKey m_internal_key;
};

/**
 * @brief The available keys.
 */
const Key KEY_RESOURCE_COAL (ID_RESOURCE_COAL);
const Key KEY_RESOURCE_FOOD (ID_RESOURCE_FOOD);
const Key KEY_RESOURCE_GOLD (ID_RESOURCE_GOLD);
const Key KEY_RESOURCE_IRON (ID_RESOURCE_IRON);
const Key KEY_RESOURCE_MANA (ID_RESOURCE_MANA);
const Key KEY_RESOURCE_ROCK (ID_RESOURCE_ROCK);
const Key KEY_RESOURCE_WOOD (ID_RESOURCE_WOOD);

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_KEY_HPP
