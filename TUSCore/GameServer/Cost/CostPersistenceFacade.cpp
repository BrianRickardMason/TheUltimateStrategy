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

#include "CostPersistenceFacade.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Cost
{

CostPersistenceFacade::CostPersistenceFacade(
    ICostAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

ResourceSet CostPersistenceFacade::getCost(
    ITransactionShrPtr         a_transaction,
    string             const & a_key,
    IDCostType         const & a_id_cost_type
) const
{
    ResourceWithVolumeMap resource_map;

    CostRecordVec cost_record_vec = m_accessor->getCosts(a_transaction, a_key, a_id_cost_type);

    for (CostRecordVec::const_iterator it = cost_record_vec.begin(); it != cost_record_vec.end(); ++it)
    {
        string resource_key = (*it)->getResourceKey();

        ResourceWithVolumeShrPtr resource(new ResourceWithVolume(resource_key, (*it)->getVolume()));

        ResourceWithVolumePair resource_pair(resource_key, resource);

        resource_map.insert(resource_pair);
    }

    ResourceSet resource_set(resource_map);

    return resource_set;
}

} // namespace Cost
} // namespace GameServer
