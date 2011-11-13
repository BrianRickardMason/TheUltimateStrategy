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

#ifndef GAMESERVER_COST_COST_HPP
#define GAMESERVER_COST_COST_HPP

//#include "../Resource/Key.hpp"
#include "CostRecord.hpp"
#include "Volume.hpp"
#include <map>

namespace GameServer
{
namespace Cost
{

/**
 * @brief The cost.
 */
class Cost
{
public:
    /**
     * @brief Constructs the cost.
     *
     * @param a_record A record of the cost.
     */
    explicit Cost(
        CostRecord const & a_record
    );

    /**
     * @brief Arithmetic operators.
     *
     * TODO: RHS should be of universal volume type.
     * TODO: Will be obsolete.
     */
    Cost operator*(unsigned int const & a_rhs) const
    {
        Cost cost(*this);
        cost.m_volume *= a_rhs;
        return cost;
    };

    /**
     * @brief Compound-assignment operators.
     *
     * TODO: RHS should be of universal volume type.
     */
    Cost & operator*=(unsigned int const & a_rhs)
    {
        m_volume *= a_rhs;
        return *this;
    };

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
     * @brief Gets the key of the resource.
     *
     * @return The key of the resource.
     */
    std::string getKey() const;

    /**
     * @brief Gets the volume of the resource.
     *
     * @return The volume of the resource.
     */
    Volume const & getVolume() const;

    /**
     * @brief Returns a key associated with the cost.
     *
     * @return The key associated with the cost.
     *
     * TODO: To be removed.
     */
    std::string toKey() const;

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
     * @brief The key of the resource.
     */
    std::string m_key;

    /**
     * @brief The volume of the resource.
     */
    Volume m_volume;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<Cost> CostShrPtr;
typedef std::pair<std::string, CostShrPtr> CostPair;
typedef std::map<std::string, CostShrPtr> CostMap;
//}@

} // namespace Cost
} // namespace GameServer

#endif // GAMESERVER_COST_COST_HPP
