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

#include <GameServer/Configuration/Configurator/Human/ConfiguratorHuman.hpp>
#include <GameServer/Configuration/Configurator/Human/Human.hpp>

using namespace pugi;
using namespace std;

namespace GameServer
{
namespace Configuration
{

ConfiguratorHuman::ConfiguratorHuman()
{
    configure();
}

bool ConfiguratorHuman::configure()
{
    if (!loadXml())
    {
        return false;
    }

    if (!parseXml())
    {
        return false;
    }

    return true;
}

IHumanShrPtr ConfiguratorHuman::getHuman(
    IHumanKey const a_key
) const
{
    return m_humans.at(a_key);
}

IHumanMap const & ConfiguratorHuman::getHumans() const
{
    return m_humans;
}

bool ConfiguratorHuman::loadXml()
{
    // TODO: Get the path from the basic configuration.
    char const * path =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/humans.xml";

    return m_humans_xml.load_file(path);
}

bool ConfiguratorHuman::parseXml()
{
    // TODO: Add verification here.

    xml_node humans = m_humans_xml.child("humans");

    for (xml_node_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IHumanKey const value_key        = it->child_value("key");
        string    const value_class      = it->child_value("class");
        string    const value_name       = it->child_value("name");
        string    const value_experience = it->child_value("experience");

        IHumanShrPtr human(new Human(value_key, value_class, value_name, value_experience));

        m_humans.insert(make_pair(value_key, human));
    }

    return true;
}

} // namespace Configuration
} // namespace GameServer
