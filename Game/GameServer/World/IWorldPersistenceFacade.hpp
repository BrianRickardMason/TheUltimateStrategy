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

#ifndef GAMESERVER_WORLD_IWORLDPERSISTENCEFACADE_HPP
#define GAMESERVER_WORLD_IWORLDPERSISTENCEFACADE_HPP

#include <Game/GameServer/Persistence/ITransaction.hpp>
#include <Game/GameServer/World/IWorld.hpp>
#include <boost/noncopyable.hpp>

namespace GameServer
{
namespace World
{

/**
 * @brief The interface of the world persistence facade.
 */
class IWorldPersistenceFacade
    : boost::noncopyable
{
public:
    virtual ~IWorldPersistenceFacade(){}

    /**
     * @brief Creates a world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createWorld(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world, null if not found.
     */
    virtual IWorldShrPtr getWorld(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the world.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The world, null if not found.
     */
    virtual IWorldShrPtr getWorldByLandName(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets worlds.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of worlds, an empty map if not found.
     */
    virtual IWorldMap getWorlds(
        Persistence::ITransactionShrPtr a_transaction
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of the world persistence facade.
 */
typedef boost::shared_ptr<IWorldPersistenceFacade> IWorldPersistenceFacadeShrPtr;

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_IWORLDPERSISTENCEFACADE_HPP
