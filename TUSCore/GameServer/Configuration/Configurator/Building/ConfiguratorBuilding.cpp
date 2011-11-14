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

#include <GameServer/Configuration/Configurator/Building/ConfiguratorBuilding.hpp>
#include <GameServer/Configuration/Configurator/Building/Building.hpp>

using namespace pugi;
using namespace std;

namespace GameServer
{
namespace Configuration
{

ConfiguratorBuilding::ConfiguratorBuilding()
{
    configure();
}

bool ConfiguratorBuilding::configure()
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

IBuildingShrPtr ConfiguratorBuilding::getBuilding(
    IBuildingKey const a_key
) const
{
    return m_buildings.at(a_key);
}

IBuildingMap const & ConfiguratorBuilding::getBuildings() const
{
    return m_buildings;
}

bool ConfiguratorBuilding::loadXml()
{
    // TODO: Get the path from the basic configuration.
    char const * path =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Building/buildings.xml";

    return m_buildings_xml.load_file(path);
}

bool ConfiguratorBuilding::parseXml()
{
    // TODO: Add verification here.

    xml_node buildings = m_buildings_xml.child("buildings");

    for (xml_node_iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        IBuildingKey const value_key   = it->child_value("key");
        string       const value_class = it->child_value("class");
        string       const value_name  = it->child_value("name");

        IBuildingShrPtr building(new Building(value_key, value_class, value_name));

        m_buildings.insert(make_pair(value_key, building));
    }

    return true;
}

} // namespace Configuration
} // namespace GameServer
