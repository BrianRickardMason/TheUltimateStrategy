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

#ifndef GAMESERVER_LAND_LAND_HPP
#define GAMESERVER_LAND_LAND_HPP

#include <TUSGame/GameServer/Land/ILand.hpp>
#include <TUSGame/GameServer/Land/ILandRecord.hpp>

namespace GameServer
{
namespace Land
{

/**
 * @brief The land.
 */
class Land
   : public ILand
{
public:
    /**
     * @brief Constructs the land.
     *
     * @param a_record A corresponding record.
     */
    explicit Land(
        ILandRecordShrPtr a_record
    );

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user.
     */
    virtual std::string getLogin() const;

    /**
     * @brief Gets the name of the world.
     *
     * @return The name of the world.
     */
    virtual std::string getWorldName() const;

    /**
     * @brief Gets the name of the land.
     *
     * @return The name of the land.
     */
    virtual std::string getLandName() const;

    /**
     * @brief Gets the age of the land expressed in the number of turns.
     *
     * @return The age of the land expressed in the number of turns.
     */
    virtual int getTurns() const;

    /**
     * @brief Gets a granted of the land.
     *
     * @return The granted of the land.
     */
    virtual bool getGranted() const;

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief The name of the world.
     */
    std::string const m_world_name;

    /**
     * @brief The name of the land.
     */
    std::string const m_land_name;

    /**
     * @brief Stores the age of the land expressed in turns.
     *
     * The information on how long does land exists.
     */
    int const m_turns;

    /**
     * @brief Defines whether resources and humans has been granted to the land.
     *
     * True if resources and humans has been granted, false otherwise.
     */
    bool const m_granted;
};

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LAND_HPP
