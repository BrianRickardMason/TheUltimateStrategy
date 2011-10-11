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

#ifndef GAMESERVER_WORLD_WORLDRECORD_HPP
#define GAMESERVER_WORLD_WORLDRECORD_HPP

#include "IWorldRecord.hpp"

namespace GameServer
{
namespace World
{

/**
 * @brief The record of the world.
 */
class WorldRecord
    : public IWorldRecord
{
public:
    /**
     * @brief Constructs the record of the world.
     *
     * @param a_world_name     The name of the world.
     * @param a_turn_available Whether the player can execute the turn in the world.
     */
    WorldRecord(
        std::string const a_world_name,
        bool        const a_turn_available
    );

    /**
     * @brief Gets the name of the world.
     *
     * @return The name of the world.
     */
    virtual std::string getWorldName() const;

    /**
     * @brief Whether the player can execute the turn in the world.
     *
     * @return True if the player can execute turns in the world, false otherwise (turns are performed automatically).
     */
    virtual bool getTurnAvailable() const;

private:
    /**
     * @brief The name of the world.
     */
    std::string const m_world_name;

    /**
     * @brief Whether the player can execute the turn in the world.
     */
    bool const m_turn_available;
};

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_WORLDRECORD_HPP
