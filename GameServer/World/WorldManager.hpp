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

#ifndef GAMESERVER_WORLD_WORLDMANAGER_HPP
#define GAMESERVER_WORLD_WORLDMANAGER_HPP

#include "IWorldManager.hpp"
#include "IWorldManagerAccessor.hpp"

namespace GameServer
{
namespace World
{

/**
 * @brief The world manager.
 */
class WorldManager
    : public IWorldManager
{
public:
    /**
     * @brief Constructs a world manager.
     *
     * @param a_accessor The accessor to be injected.
     */
    WorldManager(
        IWorldManagerAccessorAutPtr a_accessor
    );

    /**
     * @brief Creates a world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createWorld(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world, null if not found.
     */
    virtual IWorldShrPtr getWorld(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the world.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The world, null if not found.
     */
    virtual IWorldShrPtr getWorldByIDLand(
        Persistency::ITransactionShrPtr         a_transaction,
        Land::IDLand                    const & a_id_land
    ) const;

    /**
     * @brief Gets worlds.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of worlds, an empty map if not found.
     */
    virtual IWorldMap getWorlds(
        Persistency::ITransactionShrPtr a_transaction
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IWorldManagerAccessorScpPtr m_accessor;
};

/**
 * @brief An auto pointer of world manager.
 */
typedef std::auto_ptr<WorldManager> WorldManagerAutPtr;

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_WORLDMANAGER_HPP
