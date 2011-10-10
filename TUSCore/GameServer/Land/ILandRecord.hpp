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

#ifndef GAMESERVER_LAND_ILANDRECORD_HPP
#define GAMESERVER_LAND_ILANDRECORD_HPP

#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Land
{

/**
 * @brief The interface of the record of the land.
 */
class ILandRecord
{
public:
    /**
     * @brief Destructs the interface of the record of the land.
     */
    virtual ~ILandRecord(){}

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user.
     */
    virtual std::string getLogin() const = 0;

    /**
     * @brief Gets the name of the world.
     *
     * @return The name of the world.
     */
    virtual std::string getWorldName() const = 0;

    /**
     * @brief Gets the name of the epoch.
     *
     * @return The name of the epoch.
     */
    virtual std::string getEpochName() const = 0;

    /**
     * @brief Gets the name of the land.
     *
     * @return The name of the land.
     */
    virtual std::string getLandName() const = 0;

    /**
     * @brief Gets the state of the "granted" value of the land.
     *
     * @return The state of the "granted" value of the land.
     */
    virtual bool getGranted() const = 0;
};

/**
 * @brief The shared pointer of the interface of the record of the land.
 */
typedef boost::shared_ptr<ILandRecord> ILandRecordShrPtr;

/**
 * @brief The pair of the interface of the record of the land.
 */
typedef std::pair<std::string, ILandRecordShrPtr> ILandRecordPair;

/**
 * @brief The map of the interface of the record of the land.
 */
typedef std::map<std::string, ILandRecordShrPtr> ILandRecordMap;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_ILANDRECORD_HPP
