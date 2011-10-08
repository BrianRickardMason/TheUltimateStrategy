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

#include "Cost.hpp"

using namespace GameServer::Resource;

using GameServer::Common::KeyHash;

namespace GameServer
{
namespace Cost
{

Cost::Cost(
    CostRecord const & a_record
)
    : m_key_hash(a_record.getKeyHash()),
      m_id_cost_type(a_record.getIDCostType()),
      m_id_resource(a_record.getIDResource()),
      m_volume(a_record.getVolume())
{
}

KeyHash const & Cost::getKeyHash() const
{
    return m_key_hash;
}

IDCostType const & Cost::getIDCostType() const
{
    return m_id_cost_type;
}

IDResource const & Cost::getIDResource() const
{
    return m_id_resource;
}

Volume const & Cost::getVolume() const
{
    return m_volume;
}

Key Cost::toKey() const
{
    return (Key)(m_id_resource);
}

} // namespace Cost
} // namespace GameServer