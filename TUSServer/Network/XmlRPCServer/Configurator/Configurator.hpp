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

#ifndef CONFIGURATOR_HPP
#define CONFIGURATOR_HPP

#include <3rdParty/pugixml/src/pugixml.hpp>
#include <TUSServer/Network/XmlRPCServer/Configurator/IConfigurator.hpp>

/**
 * @brief Configurator.
 */
class Configurator
    : public IConfigurator
{
public:
    Configurator();

    /**
     * @brief Gets the configuration.
     *
     * @brief True on success, false otherwise.
     */
    virtual bool configure();

    /**
     * @brief Gets the host's address.
     *
     * @brief The host's address.
     */
    virtual std::string getHost() const;

    /**
     * @brief Gets the host's port.
     *
     * @brief The host's port.
     */
    virtual std::string getPort() const;

    /**
     * @brief Gets the number of threads.
     *
     * @brief The number of threads.
     */
    virtual unsigned short int getThreads() const;

    /**
     * @brief Gets the logger's priority.
     *
     * @brief The logger's priority.
     */
    virtual int getLoggerPriority() const;

    /**
     * @brief Gets the name of the persistence.
     *
     * @brief The name of the persistence.
     */
    virtual std::string getPersistence() const;

    /**
     * @brief Gets the path to the configuration files.
     *
     * @brief The path to the configuration files.
     */
    virtual std::string getConfigurationPath() const;

    /**
     * @brief Gets the name of the selected configuration.
     *
     * @brief The name of the selected configuration.
     */
    virtual std::string getConfigurationSelected() const;

private:
    /**
     * @brief Loads the data from an xml configuration file into the xml document.
     *
     * brief True on success, false otherwise.
     */
    bool loadXml();

    /**
     * @brief Loads the data from an xml document into the map.
     *
     * @brief true on success false otherwise.
     */
    bool parseXml();

    /**
     * @brief The xml document.
     *
     * TODO: Add the abstraction.
     */
    pugi::xml_document m_serverconfig_xml;

    /**
     * @brief The host's address.
     */
    std::string m_host;

    /**
     * @brief The host's port.
     */
    std::string m_port;

    /**
     * @brief The number of threads.
     */
    unsigned short int m_threads;

    /**
     * @brief The logger's priority.
     */
    int m_logger_priority;

    /**
     * @brief The name of the persistence.
     */
    std::string m_persistence;

    /**
     * @brief The path to the configuration files.
     */
    std::string m_configuration_path;

    /**
     * @brief The name of the selected configuration.
     */
    std::string m_configuration_selected;
};

#endif // CONFIGURATOR_HPP
