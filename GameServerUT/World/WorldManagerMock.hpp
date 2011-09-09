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

#ifndef GAMESERVER_WORLD_WORLDMANAGERMOCK_HPP
#define GAMESERVER_WORLD_WORLDMANAGERMOCK_HPP

#include "../../GameServer/World/IWorldManager.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace World
{

/**
 * @brief The mock of the manager of the worlds.
 */
class WorldManagerMock
    : public IWorldManager
{
public:
    /**
     * @brief Creates a world.
     *
     * @param a_transaction The transaction.
     * @param a_name        The name of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        createWorld,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Gets a world by an identifier of the world.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return The world, null if not found.
     */
    MOCK_CONST_METHOD2(
        getWorld,
        IWorldShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            IDWorld                         const & a_id_world
        )
    );

    /**
     * @brief Gets the world.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The world, null if not found.
     */
    MOCK_CONST_METHOD2(
        getWorldByIDLand,
        IWorldShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            Land::IDLand                    const & a_id_land
        )
    );

    /**
     * @brief Gets worlds.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of worlds, an empty map if not found.
     */
    MOCK_CONST_METHOD1(
        getWorlds,
        IWorldMap(
            Persistency::ITransactionShrPtr a_transaction
        )
    );
};

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_WORLDMANAGERMOCK_HPP
