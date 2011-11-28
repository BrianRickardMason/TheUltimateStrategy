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

#include <GameServer/Configuration/Configurator/Resource/Resource.hpp>
#include <Network/XmlRPCServer/Configurator/Resource/ConfiguratorResource.hpp>

ConfiguratorResource::ConfiguratorResource()
{
    configure();
}

bool ConfiguratorResource::configure()
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

GameServer::Configuration::IResourceShrPtr ConfiguratorResource::getResource(
    GameServer::Configuration::IResourceKey const a_key
) const
{
    return m_resources.at(a_key);
}

GameServer::Configuration::IResourceMap const & ConfiguratorResource::getResources() const
{
    return m_resources;
}

bool ConfiguratorResource::loadXml()
{
    // TODO: Get the path from the basic configuration.
    char const * path =
        "/home/brian/workspace/theultimatestrategy/TUSCore/GameServer/Configuration/Data/Test/Resource/resources.xml";

    return m_resources_xml.load_file(path);
}

bool ConfiguratorResource::parseXml()
{
    using namespace GameServer::Configuration;
    using namespace pugi;
    using namespace std;

    // TODO: Add verification here.

    xml_node resources = m_resources_xml.child("resources");

    for (xml_node_iterator it = resources.begin(); it != resources.end(); ++it)
    {
        IResourceKey const key  = it->child_value("key");
        string       const name = it->child_value("name");

        IResourceShrPtr resource(new Resource(key, name));

        m_resources.insert(make_pair(key, resource));
    }

    return true;
}
