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

#include <GameServer/Achievement/Managers/AchievementManager.hpp>

using namespace GameServer::Epoch;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::World;

namespace GameServer
{
namespace Achievement
{

AchievementManager::AchievementManager(
    IEpochPersistenceFacadeShrPtr a_epoch_persistence_facade,
    ILandPersistenceFacadeShrPtr  a_land_persistence_facade,
    IWorldPersistenceFacadeShrPtr a_world_persistence_facade
)
    : m_epoch_persistence_facade(a_epoch_persistence_facade),
      m_land_persistence_facade(a_land_persistence_facade),
      m_world_persistence_facade(a_world_persistence_facade)
{
}

bool AchievementManager::grantAchievements(
    ITransactionShrPtr       a_transaction,
    IWorldShrPtr       const a_world
) const
{
    try
    {
        // Get the epoch of the world.
        EpochShrPtr epoch = m_epoch_persistence_facade->getEpoch(a_transaction, a_world->getWorldName());

        if (!epoch)
        {
            return false;
        }

        // Get the lands of the world.
        ILandMap lands = m_land_persistence_facade->getLands(a_transaction, a_world);

        // Grant achievements to every land.
        for (ILandMap::const_iterator it = lands.begin(); it != lands.end(); ++it)
        {
            // TODO: grantToLand().
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

} // namespace Achievement
} // namespace GameServer
