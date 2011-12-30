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

#include <TUSGame/GameServer/Achievement/Managers/AchievementManager.hpp>

using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace GameServer::World;

namespace GameServer
{
namespace Achievement
{

AchievementManager::AchievementManager(
    IAchievementPersistenceFacadeShrPtr a_achievement_persistence_facade,
    IEpochPersistenceFacadeShrPtr       a_epoch_persistence_facade,
    IHumanPersistenceFacadeShrPtr       a_human_persistence_facade,
    ILandPersistenceFacadeShrPtr        a_land_persistence_facade,
    IUserPersistenceFacadeShrPtr        a_user_persistence_facade,
    IWorldPersistenceFacadeShrPtr       a_world_persistence_facade
)
    : m_achievement_persistence_facade(a_achievement_persistence_facade),
      m_epoch_persistence_facade(a_epoch_persistence_facade),
      m_human_persistence_facade(a_human_persistence_facade),
      m_land_persistence_facade(a_land_persistence_facade),
      m_user_persistence_facade(a_user_persistence_facade),
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
        IEpochShrPtr epoch = m_epoch_persistence_facade->getEpoch(a_transaction, a_world->getWorldName());

        if (!epoch)
        {
            return false;
        }

        // Get the lands of the world.
        ILandMap lands = m_land_persistence_facade->getLands(a_transaction, a_world);

        // Grant achievements to every land.
        for (ILandMap::const_iterator it = lands.begin(); it != lands.end(); ++it)
        {
            bool const result = grantAchievements(a_transaction, epoch, it->second);

            if (!result)
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool AchievementManager::grantAchievements(
    Persistence::ITransactionShrPtr       a_transaction,
    Epoch::IEpochShrPtr             const a_epoch,
    Land::ILandShrPtr               const a_land
) const
{
    int const turns = a_land->getTurns();

    if (turns == 88 or turns == 44 or turns == 22)
    {
        // TODO: Hardcoded human number.
        if (m_human_persistence_facade->countHumans(a_transaction, a_land->getLandName()) > 500)
        {
            IUserShrPtr user = m_user_persistence_facade->getUser(a_transaction, a_land->getLogin());

            if (!user)
            {
                return false;
            }

            switch (turns)
            {
                case 88:
                    return m_achievement_persistence_facade->grantAchievement(a_transaction, a_epoch, user, "survived88");
                case 44:
                    return m_achievement_persistence_facade->grantAchievement(a_transaction, a_epoch, user, "survived44");
                case 22:
                    return m_achievement_persistence_facade->grantAchievement(a_transaction, a_epoch, user, "survived22");
                default:
                    BOOST_ASSERT(false);
            }
        }
    }

    return true;
}

} // namespace Achievement
} // namespace GameServer
