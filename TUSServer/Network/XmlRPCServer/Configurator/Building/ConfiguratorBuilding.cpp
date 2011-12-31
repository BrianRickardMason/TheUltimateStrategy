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

#include <TUSGame/GameServer/Configuration/Configurator/Building/Building.hpp>
#include <TUSServer/Network/XmlRPCServer/Configurator/Building/ConfiguratorBuilding.hpp>
#include <string>
#include <vector>

ConfiguratorBuilding::ConfiguratorBuilding(
    IConfiguratorShrPtr const a_configurator
)
    : m_configurator(a_configurator)
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

GameServer::Configuration::IBuildingShrPtr ConfiguratorBuilding::getBuilding(
    GameServer::Configuration::IKey const a_key
) const
{
    // FIXME: find + handling.
    return m_buildings.at(a_key);
}

GameServer::Configuration::IBuildingMap const & ConfiguratorBuilding::getBuildings() const
{
    return m_buildings;
}

bool ConfiguratorBuilding::loadXml()
{
    std::string path_buildings_xml =
        m_configurator->getConfigurationPath() + m_configurator->getConfigurationSelected() + "/Building/buildings.xml";
    bool const result_buildings_xml = m_buildings_xml.load_file(path_buildings_xml.c_str());

    std::string path_costs_xml =
        m_configurator->getConfigurationPath() + m_configurator->getConfigurationSelected() + "/Building/costs.xml";
    bool const result_costs_xml = m_costs_xml.load_file(path_costs_xml.c_str());

    std::string path_humanshosted_xml =
          m_configurator->getConfigurationPath()
        + m_configurator->getConfigurationSelected()
        + "/Building/humanshosted.xml";
    bool const result_humanshosted_xml = m_humanshosted_xml.load_file(path_humanshosted_xml.c_str());

    std::string path_properties_xml =
          m_configurator->getConfigurationPath()
        + m_configurator->getConfigurationSelected()
        + "/Building/properties.xml";
    bool const result_properties_xml = m_properties_xml.load_file(path_properties_xml.c_str());

    return (result_buildings_xml and result_costs_xml and result_humanshosted_xml and result_properties_xml);
}

bool ConfiguratorBuilding::parseXml()
{
    using namespace GameServer::Configuration;
    using namespace std;
    using namespace pugi;

    // TODO: Add verification here.

    xml_node buildings = m_buildings_xml.child("buildings");

    for (xml_node_iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        IKey                                    const building_key              = it->child_value("key");
        string                                  const building_class            = it->child_value("class");
        string                                  const building_name             = it->child_value("name");
        unsigned int                                  building_capacity         = 0;
        map<IKey, GameServer::Resource::Volume>       building_costs_to_build;
        map<IKey, GameServer::Resource::Volume>       building_costs_to_destroy;

        // Get the costs.
        xml_node costs =
            m_costs_xml.child("buildings").find_child_by_attribute("key", building_key.c_str());

        if (costs)
        {
            xml_node costs_to_build = costs.child("build");

            for (xml_node::iterator it = costs_to_build.begin(); it != costs_to_build.end(); ++it)
            {
                building_costs_to_build[it->name()] = it->attribute("value").as_uint();
            }

            xml_node costs_to_destroy = costs.child("destroy");

            for (xml_node::iterator it = costs_to_destroy.begin(); it != costs_to_destroy.end(); ++it)
            {
                building_costs_to_destroy[it->name()] = it->attribute("value").as_uint();
            }
        }

        // Get the humans hosted.
        xml_node humanshosted =
            m_humanshosted_xml.child("buildings").find_child_by_attribute("key", building_key.c_str());

        std::vector<IKey> hosted_humans;

        if (humanshosted)
        {
            xml_node list_of_humans = humanshosted.child("humans");

            for (xml_node_iterator it = list_of_humans.begin(); it != list_of_humans.end(); ++it)
            {
                hosted_humans.push_back(it->child_value("key"));
            }
        }

        // Get the properties.
        xml_node properties =
            m_properties_xml.child("buildings").find_child_by_attribute("key", building_key.c_str());

        if (properties)
        {
            building_capacity = properties.child("capacity").attribute("value").as_uint();
        }

        IBuildingShrPtr building(
            new Building(building_key,
                         building_class,
                         building_name,
                         building_capacity,
                         building_costs_to_build,
                         building_costs_to_destroy,
                         hosted_humans)
        );

        m_buildings.insert(make_pair(building_key, building));
    }

    return true;
}
