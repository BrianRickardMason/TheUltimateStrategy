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

#ifndef GAMESERVER_COST_COSTRECORD_HPP
#define GAMESERVER_COST_COSTRECORD_HPP

#include "../Common/KeyHash.hpp"
#include "../Resource/Key.hpp"
#include "IDCostType.hpp"
#include "Volume.hpp"
#include <boost/make_shared.hpp>
#include <vector>

namespace GameServer
{
namespace Cost
{

/**
 * @brief A cost with volume record.
 */
class CostRecord
{
public:
    /**
     * @brief Constructs the cost record.
     *
     * @param a_key_hash     The key hash.
     * @param a_id_cost_type The identifier of the cost type.
     * @param a_id_resource  The identifier of the resource.
     * @param a_volume       The volume of the resource.
     */
    CostRecord(
        Common::KeyHash      const & a_key_hash,
        IDCostType           const & a_id_cost_type,
        Resource::IDResource const & a_id_resource,
        Volume               const & a_volume
    );

    /**
     * @brief Relational operators.
     */
    bool operator==(
        CostRecord const & a_rhs
    ) const
    {
        return (    m_key_hash     == a_rhs.m_key_hash
                 && m_id_cost_type == a_rhs.m_id_cost_type
                 && m_id_resource  == a_rhs.m_id_resource
                 && m_volume       == a_rhs.m_volume);
    }

    /**
     * @brief Gets the key hash.
     *
     * @return The key hash.
     */
    Common::KeyHash const & getKeyHash() const;

    /**
     * @brief Gets the identifier of the cost type.
     *
     * @return The identifier of the cost type .
     */
    IDCostType const & getIDCostType() const;

    /**
     * @brief Gets the identifier of the resource.
     *
     * @return The identifier of the resource.
     */
    Resource::IDResource const & getIDResource() const;

    /**
     * @brief Gets the volume of the resource.
     *
     * @return The volume of the resource.
     */
    Volume const & getVolume() const;

private:
    /**
     * @brief The key hash.
     */
    Common::KeyHash m_key_hash;

    /**
     * @brief The identifier of the cost type.
     */
    IDCostType m_id_cost_type;

    /**
     * @brief The identifier of the resource.
     */
    Resource::IDResource m_id_resource;

    /**
     * @brief The volume of the resource.
     */
    Volume m_volume;
};

/**
 * @brief A shared pointer of cost record.
 */
typedef boost::shared_ptr<CostRecord> CostRecordShrPtr;

/**
 * @brief A vector of cost record.
 */
typedef std::vector<CostRecordShrPtr> CostRecordVec;

} // namespace Cost
} // namespace GameServer

#endif // GAMESERVER_COST_COSTRECORD_HPP