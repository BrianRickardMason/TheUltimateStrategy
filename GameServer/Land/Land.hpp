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

#ifndef GAMESERVER_LAND_LAND_HPP
#define GAMESERVER_LAND_LAND_HPP

#include "LandRecord.hpp"

namespace GameServer
{
namespace Land
{

/**
 * @brief A land.
 */
class Land
{
public:
    /**
     * @brief Constructs the land.
     *
     * @param a_record A corresponding record.
     */
    explicit Land(
        LandRecord const & a_record
    );

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user.
     */
    std::string getLogin() const;

    /**
     * @brief Gets an identifier of the world.
     *
     * @return The identifier of the world.
     */
    World::IDWorld const & getIDWorld() const;

    /**
     * @brief Gets an identifier of the epoch.
     *
     * @return The identifier of the epoch.
     */
    Epoch::IDEpoch const & getIDEpoch() const;

    /**
     * @brief Gets an identifier of the land.
     *
     * @return The identifier of the land.
     */
    IDLand const & getIDLand() const;

    /**
     * @brief Gets a name of the land.
     *
     * @return The name of the land.
     */
    std::string const & getName() const;

    /**
     * @brief Gets a granted of the land.
     *
     * @return The granted of the land.
     */
    bool getGranted() const;

private:
    /**
     * @brief The login of the user.
     */
    std::string const m_login;

    /**
     * @brief An identifier of the world.
     */
    World::IDWorld const m_id_world;

    /**
     * @brief An identifier of the epoch.
     */
    Epoch::IDEpoch const m_id_epoch;

    /**
     * @brief An identifier of the land.
     */
    IDLand const m_id_land;

    /**
     * @brief A name of the land.
     */
    std::string const m_name;

    /**
     * @brief Defines whether resources and humans has been granted to the land.
     *
     * True if resources and humans has been granted, false otherwise.
     */
    bool const m_granted;
};

/**
 * @brief A shared pointer of land.
 */
typedef boost::shared_ptr<Land> LandShrPtr;

/**
 * @brief A pair of land.
 */
typedef std::pair<IDLand, LandShrPtr> LandPair;

/**
 * @brief A map of land.
 */
typedef std::map<IDLand, LandShrPtr> LandMap;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LAND_HPP
