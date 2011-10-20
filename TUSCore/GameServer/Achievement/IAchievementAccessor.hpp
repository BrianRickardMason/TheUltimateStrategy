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

#ifndef GAMESERVER_ACHIEVEMENT_IACHIEVEMENTACCESSOR_HPP
#define GAMESERVER_ACHIEVEMENT_IACHIEVEMENTACCESSOR_HPP

#include <GameServer/Persistence/ITransaction.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>
#include <string>

namespace GameServer
{
namespace Achievement
{

/**
 * @brief The interface of AchievementAccessor.
 */
class IAchievementAccessor
    : boost::noncopyable
{
public:
    virtual ~IAchievementAccessor(){};

    /**
     * @brief Inserts a achievement record.
     *
     * @param a_transaction      The transaction.
     * @param a_world_name       The name of the world.
     * @param a_epoch_name       The name of the epoch.
     * @param a_login            The login of the user.
     * @param a_achievement_name The name of the achievement.
     */
    virtual void insertRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const a_world_name,
        std::string                     const a_epoch_name,
        std::string                     const a_login,
        std::string                     const a_achievement_name
    ) const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<IAchievementAccessor> IAchievementAccessorAutPtr;
typedef boost::scoped_ptr<IAchievementAccessor> IAchievementAccessorScpPtr;
//}@

} // namespace Achievement
} // namespace GameServer

#endif // GAMESERVER_ACHIEVEMENT_IACHIEVEMENTACCESSOR_HPP
