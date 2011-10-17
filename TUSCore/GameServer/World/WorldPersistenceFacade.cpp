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

#include "World.hpp"
#include "WorldPersistenceFacade.hpp"

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace World
{

WorldPersistenceFacade::WorldPersistenceFacade(
    IWorldManagerAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

bool WorldPersistenceFacade::createWorld(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    try
    {
        m_accessor->insertRecord(a_transaction, a_world_name);

        return true;
    }
    catch (std::exception const & e)
    {
        return false;
    }
}

IWorldShrPtr WorldPersistenceFacade::getWorld(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IWorldRecordShrPtr record = m_accessor->getRecord(a_transaction, a_world_name);

    return record ? IWorldShrPtr(new World(record)) : IWorldShrPtr();
}

IWorldShrPtr WorldPersistenceFacade::getWorldByLandName(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    string world_name = m_accessor->getWorldNameOfLand(a_transaction, a_land_name);

    return getWorld(a_transaction, world_name);
}

IWorldMap WorldPersistenceFacade::getWorlds(
    ITransactionShrPtr a_transaction
) const
{
    IWorldRecordMap records = m_accessor->getRecords(a_transaction);

    IWorldMap worlds;

    for (IWorldRecordMap::iterator it = records.begin(); it != records.end(); ++it)
    {
        if (it->second)
        {
            IWorldShrPtr world = IWorldShrPtr(new World(it->second));
            IWorldPair pair(it->second->getWorldName(), world);
            worlds.insert(pair);
        }
    }

    return worlds;
}

} // namespace World
} // namespace GameServer
