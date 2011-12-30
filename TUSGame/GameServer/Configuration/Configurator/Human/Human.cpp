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

#include <TUSGame/GameServer/Configuration/Configurator/Human/Human.hpp>

using namespace GameServer::Resource;
using namespace std;

namespace GameServer
{
namespace Configuration
{

Human::Human(
    IKey                                    const   a_key,
    string                                  const   a_class,
    string                                  const   a_name,
    string                                  const   a_experience,
    bool                                    const   a_dismissable,
    bool                                    const   a_engageable,
    unsigned int                            const   a_production,
    map<IKey, GameServer::Resource::Volume> const & a_costs_to_dismiss,
    map<IKey, GameServer::Resource::Volume> const & a_costs_to_engage,
    map<IKey, GameServer::Resource::Volume> const & a_costs_to_live,
    IKey                                    const   a_resource_produced,
    IKey                                    const   a_place_of_work
)
    : m_key(a_key),
      m_class(a_class),
      m_name(a_name),
      m_experience(a_experience),
      m_dismissable(a_dismissable),
      m_engageable(a_engageable),
      m_production(a_production),
      m_costs_to_dismiss(a_costs_to_dismiss),
      m_costs_to_engage(a_costs_to_engage),
      m_costs_to_live(a_costs_to_live),
      m_resource_produced(a_resource_produced),
      m_place_of_work(a_place_of_work)
{
}

IKey Human::getKey() const
{
    return m_key;
}

string Human::getClass() const
{
    return m_class;
}

string Human::getName() const
{
    return m_name;
}

string Human::getExperience() const
{
    return m_experience;
}

bool Human::isDismissable() const
{
    return m_dismissable;
}

bool Human::isEngageable() const
{
    return m_engageable;
}

unsigned int Human::getProduction() const
{
    return m_production;
}

std::map<IKey, GameServer::Resource::Volume> const & Human::getCostsToDismiss() const
{
    return m_costs_to_dismiss;
}

std::map<IKey, GameServer::Resource::Volume> const & Human::getCostsToEngage() const
{
    return m_costs_to_engage;
}

std::map<IKey, GameServer::Resource::Volume> const & Human::getCostsToLive() const
{
    return m_costs_to_live;
}

IKey Human::getResourceProduced() const
{
    return m_resource_produced;
}

IKey Human::getPlaceOfWork() const
{
    return m_place_of_work;
}

} // namespace Configuration
} // namespace GameServer
