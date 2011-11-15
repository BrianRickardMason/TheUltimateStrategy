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

#ifndef GAMESERVER_CONFIGURATION_CONFIGURATORHUMAN_HPP
#define GAMESERVER_CONFIGURATION_CONFIGURATORHUMAN_HPP

#include <3rdParty/pugixml/src/pugixml.hpp>
#include <GameServer/Configuration/Configurator/Human/IHuman.hpp>
#include <boost/noncopyable.hpp>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief ConfiguratorHuman.
 */
class ConfiguratorHuman
    : private boost::noncopyable
{
public:
    ConfiguratorHuman();

    /**
     * @brief Gets the configuration.
     *
     * @return True on success, false otherwise.
     */
    bool configure();

    /**
     * @brief Gets the human.
     *
     * @param a_key The key of the human.
     *
     * @return The human, null if not found.
     */
    IHumanShrPtr getHuman(
        IHumanKey const a_key
    ) const;

    /**
     * @brief Gets the map of humans.
     *
     * @return The map of humans.
     */
    IHumanMap const & getHumans() const;

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
     * @brief The xml document.
     *
     * TODO: Add the abstraction.
     */
    pugi::xml_document m_humans_xml;

    /**
     * @brief The map of available humans.
     */
    IHumanMap m_humans;
};

static ConfiguratorHuman const CONFIGURATOR_HUMAN;

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_CONFIGURATORHUMAN_HPP
