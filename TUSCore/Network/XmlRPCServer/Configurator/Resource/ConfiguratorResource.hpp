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

#ifndef CONFIGURATORRESOURCE_HPP
#define CONFIGURATORRESOURCE_HPP

#include <3rdParty/pugixml/src/pugixml.hpp>
#include <TUSCore/Network/XmlRPCServer/Configurator/Resource/IConfiguratorResource.hpp>
#include <TUSCore/Network/XmlRPCServer/Configurator/IConfigurator.hpp>

/**
 * @brief ConfiguratorResource.
 */
class ConfiguratorResource
    : public IConfiguratorResource
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_configurator Configurator.
     */
    ConfiguratorResource(
        IConfiguratorShrPtr const a_configurator
    );

    /**
     * @brief Gets the configuration.
     *
     * @return True on success, false otherwise.
     */
    virtual bool configure();

    /**
     * @brief Gets the resource.
     *
     * @param a_key The key of the resource.
     *
     * @return The resource, null if not found.
     */
    virtual GameServer::Configuration::IResourceShrPtr getResource(
        GameServer::Configuration::IKey const a_key
    ) const;

    /**
     * @brief Gets the map of resources.
     *
     * @return The map of resources.
     */
    virtual GameServer::Configuration::IResourceMap const & getResources() const;

private:
    /**
     * @brief Loads the data from an xml configuration file into the xml document.
     *
     * return True on success, false otherwise.
     */
    bool loadXml();

    /**
     * @brief Loads the data from an xml document into the map.
     *
     * @return true on success false otherwise.
     */
    bool parseXml();

    /**
     * @brief Configurator.
     */
    IConfiguratorShrPtr const m_configurator;

    /**
     * @brief The xml document.
     *
     * TODO: Add the abstraction.
     */
    pugi::xml_document m_resources_xml;

    /**
     * @brief The map of available resources.
     */
    GameServer::Configuration::IResourceMap m_resources;
};

#endif // CONFIGURATORRESOURCE_HPP
