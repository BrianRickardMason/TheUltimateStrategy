// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#ifndef GAMESERVER_ACHIEVEMENT_ACHIEVEMENTPERSISTENCEFACADE_HPP
#define GAMESERVER_ACHIEVEMENT_ACHIEVEMENTPERSISTENCEFACADE_HPP

#include <Game/GameServer/Achievement/IAchievementAccessor.hpp>
#include <Game/GameServer/Achievement/IAchievementPersistenceFacade.hpp>

namespace GameServer
{
namespace Achievement
{

/**
 * @brief The AchievementPersistenceFacade.
 */
class AchievementPersistenceFacade
    : public IAchievementPersistenceFacade
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_accessor An accessor to be injected.
     */
    AchievementPersistenceFacade(
        IAchievementAccessorAutPtr a_accessor
    );

    /**
     * @brief Grants an achievement to the user.
     *
     * @param a_transaction      The transaction.
     * @param a_epoch            The epoch.
     * @param a_user             The user.
     * @param a_achievement_name The name of the achievement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool grantAchievement(
        Persistence::ITransactionShrPtr       a_transaction,
        Epoch::IEpochShrPtr             const a_epoch,
        User::IUserShrPtr               const a_user,
        std::string                     const a_achievement_name
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IAchievementAccessorScpPtr m_accessor;
};

/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<AchievementPersistenceFacade> AchievementPersistenceFacadeAutPtr;

} // namespace Achievement
} // namespace GameServer

#endif // GAMESERVER_ACHIEVEMENT_ACHIEVEMENTPERSISTENCEFACADE_HPP
