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

#ifndef GAMESERVER_CONFIGURATION_IBUILDING_HPP
#define GAMESERVER_CONFIGURATION_IBUILDING_HPP

#include <Game/GameServer/Configuration/Configurator/IKey.hpp>
#include <Game/GameServer/Configuration/Configurator/Resource/IResource.hpp>
#include <Game/GameServer/Resource/Volume.hpp>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include <vector>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief The interface of Building.
 */
class IBuilding
{
public:
    virtual ~IBuilding(){}

    /**
     * @brief Gets the key of the building.
     *
     * @return The key of the building.
     */
    virtual IKey getKey() const = 0;

    /**
     * @brief Gets the class of the building.
     *
     * @return The class of the building.
     */
    virtual std::string getClass() const = 0;

    /**
     * @brief Gets the name of the building.
     *
     * @return The name of the building.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Gets the capacity.
     *
     * @return The capacity of the building.
     */
    virtual unsigned int getCapacity() const = 0;

    /**
     * @brief Gets the costs to build the building.
     *
     * @return The costs to build the building.
     */
    virtual std::map<IKey, GameServer::Resource::Volume> const & getCostsToBuild() const = 0;

    /**
     * @brief Gets the costs to destroy the building.
     *
     * @return The costs to destroy the building.
     */
    virtual std::map<IKey, GameServer::Resource::Volume> const & getCostsToDestroy() const = 0;

    /**
     * @brief Gets the hosted humans.
     *
     * @return The hosted humans.
     */
    virtual std::vector<IKey> const & getHostedHumans() const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IBuilding const> IBuildingShrPtr;
typedef std::map<IKey, IBuildingShrPtr> IBuildingMap;
//}@

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_IBUILDING_HPP
