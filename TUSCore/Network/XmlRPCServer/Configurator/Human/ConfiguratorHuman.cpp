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

#include <GameServer/Configuration/Configurator/Human/Human.hpp>
#include <Network/XmlRPCServer/Configurator/Human/ConfiguratorHuman.hpp>

ConfiguratorHuman::ConfiguratorHuman(
    IConfiguratorShrPtr const a_configurator
)
    : m_configurator(a_configurator)
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

GameServer::Configuration::IHumanShrPtr ConfiguratorHuman::getHuman(
    GameServer::Configuration::IHumanKey const a_key
) const
{
    return m_humans.at(a_key);
}

GameServer::Configuration::IHumanMap const & ConfiguratorHuman::getHumans() const
{
    return m_humans;
}

bool ConfiguratorHuman::loadXml()
{
    // TODO: Get the path from the basic configuration.
    char const * path_humans_xml =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/humans.xml";

    bool const result_humans_xml = m_humans_xml.load_file(path_humans_xml);

    // TODO: Get the path from the basic configuration.
    char const * path_costs_xml =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/costs.xml";

    bool const result_costs_xml = m_costs_xml.load_file(path_costs_xml);

    // TODO: Get the path from the basic configuration.
    char const * path_properties_xml =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/properties.xml";

    bool const result_properties_xml = m_properties_xml.load_file(path_properties_xml);

    return (result_humans_xml and result_costs_xml and result_properties_xml);
}

bool ConfiguratorHuman::parseXml()
{
    using namespace GameServer::Configuration;
    using namespace std;
    using namespace pugi;

    // TODO: Add verification here.

    xml_node humans = m_humans_xml.child("humans");

    for (xml_node_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IHumanKey                                       const human_key              = it->child_value("key");
        string                                          const human_class            = it->child_value("class");
        string                                          const human_name             = it->child_value("name");
        string                                          const human_experience       = it->child_value("experience");
        bool                                                  human_dismissable      = false;
        bool                                                  human_engageable       = false;
        unsigned int                                          human_production       = 0;
        map<IResourceKey, GameServer::Resource::Volume>       human_costs_to_dismiss;
        map<IResourceKey, GameServer::Resource::Volume>       human_costs_to_engage;
        map<IResourceKey, GameServer::Resource::Volume>       human_costs_to_live;

        // Get the costs.
        xml_node costs =
            m_costs_xml.child("humans").find_child_by_attribute("key", human_key.c_str());

        if (costs)
        {
            xml_node costs_to_dismiss = costs.child("dismiss");

            for (xml_node::iterator it = costs_to_dismiss.begin(); it != costs_to_dismiss.end(); ++it)
            {
                human_costs_to_dismiss[it->name()] = it->attribute("value").as_uint();
            }

            xml_node costs_to_engage = costs.child("engage");

            for (xml_node::iterator it = costs_to_engage.begin(); it != costs_to_engage.end(); ++it)
            {
                human_costs_to_engage[it->name()] = it->attribute("value").as_uint();
            }

            xml_node costs_to_live = costs.child("live");

            for (xml_node::iterator it = costs_to_live.begin(); it != costs_to_live.end(); ++it)
            {
                human_costs_to_live[it->name()] = it->attribute("value").as_uint();
            }
        }

        // Get the properties.
        xml_node properties =
            m_properties_xml.child("humans").find_child_by_attribute("key", human_key.c_str());

        if (properties)
        {
            human_dismissable = properties.child("dismissable").attribute("value").as_bool();
            human_engageable  = properties.child("engageable").attribute("value").as_bool();
            human_production  = properties.child("production").attribute("value").as_uint();
        }

        IHumanShrPtr human(
            new Human(human_key,
                      human_class,
                      human_name,
                      human_experience,
                      human_dismissable,
                      human_engageable,
                      human_production,
                      human_costs_to_dismiss,
                      human_costs_to_engage,
                      human_costs_to_live)
        );

        m_humans.insert(make_pair(human_key, human));
    }

    return true;
}
