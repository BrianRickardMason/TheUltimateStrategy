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

#include <Game/GameServer/Configuration/Configurator/Resource/Resource.hpp>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/NodeList.h>
#include <Server/Server/include/ConfiguratorResource.hpp>

namespace Server
{

ConfiguratorResource::ConfiguratorResource(
    IConfiguratorShrPtr const aConfigurator
)
    : mConfigurator(aConfigurator)
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
    GameServer::Configuration::IKey const aKey
) const
{
    // FIXME: Use find and provide the exception handling.
    return mResources.at(aKey);
}

GameServer::Configuration::IResourceMap const & ConfiguratorResource::getResources() const
{
    return mResources;
}

bool ConfiguratorResource::loadXml()
{
    Poco::XML::DOMParser parser;

    std::string path =
        mConfigurator->getConfigurationPath() + mConfigurator->getConfigurationSelected() + "/Resource/resources.xml";

    mResourcesXml = parser.parse(path);

    return true;
}

bool ConfiguratorResource::parseXml()
{
    // TODO: Add verification here.

    typedef GameServer::Configuration::IKey IKey;
    typedef Poco::XML::Element * Element;
    typedef Poco::XML::NodeList * NodeList;

    Element documentElement = mResourcesXml->documentElement();

    NodeList resources = documentElement->getElementsByTagName("resource");

    for (int i = 0; i < resources->length(); ++i)
    {
        Element resource = static_cast<Poco::XML::Element *>(resources->item(i));

        IKey        const resourceKey  = resource->getChildElement("key")->innerText();
        std::string const resourceName = resource->getChildElement("name")->innerText();

        GameServer::Configuration::IResourceShrPtr createdResource(
            new GameServer::Configuration::Resource(resourceKey, resourceName)
        );

        mResources.insert(std::make_pair(resourceKey, createdResource));
    }
}

} // namespace Server
