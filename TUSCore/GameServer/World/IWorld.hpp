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

#ifndef GAMESERVER_WORLD_IWORLD_HPP
#define GAMESERVER_WORLD_IWORLD_HPP

#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace World
{

/**
 * @brief The interface of the world.
 */
class IWorld
{
public:
    virtual ~IWorld(){}

    /**
     * @brief Gets the name of the world.
     *
     * @return The name of the world.
     */
    virtual std::string getWorldName() const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IWorld> IWorldShrPtr;
typedef std::pair<std::string, IWorldShrPtr> IWorldPair;
typedef std::map<std::string, IWorldShrPtr> IWorldMap;
//}@

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_IWORLD_HPP
