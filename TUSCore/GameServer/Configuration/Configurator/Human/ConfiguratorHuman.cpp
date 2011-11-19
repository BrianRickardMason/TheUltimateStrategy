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
    char const * path_humans_xml =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/humans.xml";

    bool const result_humans_xml = m_humans_xml.load_file(path_humans_xml);

    // TODO: Get the path from the basic configuration.
    char const * path_properties_xml =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Human/properties.xml";

    bool const result_properties_xml = m_properties_xml.load_file(path_properties_xml);

    return (result_humans_xml and result_properties_xml);
}

bool ConfiguratorHuman::parseXml()
{
    // TODO: Add verification here.

    xml_node humans = m_humans_xml.child("humans");

    for (xml_node_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        IHumanKey    const human_key         = it->child_value("key");
        string       const human_class       = it->child_value("class");
        string       const human_name        = it->child_value("name");
        string       const human_experience  = it->child_value("experience");
        bool               human_dismissable = false;
        bool               human_engageable  = false;
        unsigned int       human_production  = 0;

        // Find the human.
        xml_node properties_human =
            m_properties_xml.child("humans").find_child_by_attribute("key", human_key.c_str());

        if (properties_human)
        {
            human_dismissable = properties_human.child("dismissable").attribute("value").as_bool();
            human_engageable  = properties_human.child("engageable").attribute("value").as_bool();
            human_production  = properties_human.child("production").attribute("value").as_uint();
        }

        IHumanShrPtr human(
            new Human(human_key,
                      human_class,
                      human_name,
                      human_experience,
                      human_dismissable,
                      human_engageable,
                      human_production)
        );

        m_humans.insert(make_pair(human_key, human));
    }

    return true;
}

} // namespace Configuration
} // namespace GameServer
