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

#include <Game/GameServer/Configuration/Configurator/Building/Building.hpp>

using namespace GameServer::Resource;
using namespace std;

namespace GameServer
{
namespace Configuration
{

Building::Building(
    IKey                                    const   a_key,
    string                                  const   a_class,
    string                                  const   a_name,
    unsigned int                            const   a_capacity,
    map<IKey, GameServer::Resource::Volume> const & a_costs_to_build,
    map<IKey, GameServer::Resource::Volume> const & a_costs_to_destroy,
    std::vector<IKey>                       const & a_hosted_humans
)
    : m_key(a_key),
      m_class(a_class),
      m_name(a_name),
      m_capacity(a_capacity),
      m_costs_to_build(a_costs_to_build),
      m_costs_to_destroy(a_costs_to_destroy),
      m_hosted_humans(a_hosted_humans)
{
}

IKey Building::getKey() const
{
    return m_key;
}

string Building::getClass() const
{
    return m_class;
}

string Building::getName() const
{
    return m_name;
}

unsigned int Building::getCapacity() const
{
    return m_capacity;
}

std::map<IKey, GameServer::Resource::Volume> const & Building::getCostsToBuild() const
{
    return m_costs_to_build;
}

std::map<IKey, GameServer::Resource::Volume> const & Building::getCostsToDestroy() const
{
    return m_costs_to_destroy;
}

std::vector<IKey> const & Building::getHostedHumans() const
{
    return m_hosted_humans;
}

} // namespace Configuration
} // namespace GameServer
