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

#ifndef GAMESERVER_CONFIGURATION_IHUMAN_HPP
#define GAMESERVER_CONFIGURATION_IHUMAN_HPP

#include <GameServer/Configuration/Configurator/Key.hpp>
#include <GameServer/Configuration/Configurator/Resource/IResource.hpp>
#include <GameServer/Resource/Volume.hpp>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief The interface of Human.
 */
class IHuman
{
public:
    virtual ~IHuman(){}

    /**
     * @brief Gets the key of the human.
     *
     * @return The key of the human.
     */
    virtual IKey getKey() const = 0;

    /**
     * @brief Gets the class of the human.
     *
     * @return The class of the human.
     */
    virtual std::string getClass() const = 0;

    /**
     * @brief Gets the name of the human.
     *
     * @return The name of the human.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Gets the experience of the human.
     *
     * @return The experience of the human.
     */
    virtual std::string getExperience() const = 0;

    /**
     * @brief Checks whether a human can be dismissed.
     *
     * @return True if human can be dismissed, false otherwise.
     */
    virtual bool isDismissable() const = 0;

    /**
     * @brief Checks whether a human can be engaged.
     *
     * @return True if human can be engaged, false otherwise.
     */
    virtual bool isEngageable() const = 0;

    /**
     * @brief Defines the number of units of a resource produced per turn.
     *
     * @return The number of units of a resource produced per turn.
     *
     * TODO: To be extended: define what resource(s) is (are) produced.
     */
    virtual unsigned int getProduction() const = 0;

    /**
     * @brief Gets the costs to dismiss the human.
     *
     * @return The costs to dismiss the human.
     */
    virtual std::map<IResourceKey, GameServer::Resource::Volume> const & getCostsToDismiss() const = 0;

    /**
     * @brief Gets the costs to engage the human.
     *
     * @return The costs to engage the human.
     */
    virtual std::map<IResourceKey, GameServer::Resource::Volume> const & getCostsToEngage() const = 0;

    /**
     * @brief Gets the costs for human to live.
     *
     * @return The costs for human to live.
     */
    virtual std::map<IResourceKey, GameServer::Resource::Volume> const & getCostsToLive() const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IHuman const> IHumanShrPtr;
typedef std::map<IKey, IHumanShrPtr> IHumanMap;
//}@

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_IHUMAN_HPP
