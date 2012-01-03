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

#include <Server/Network/XmlRPCServer/Configurator/Configurator.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace pugi;
using namespace std;

Configurator::Configurator()
{
    configure();
}

bool Configurator::configure()
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

string Configurator::getHost() const
{
    return m_host;
}

string Configurator::getPort() const
{
    return m_port;
}

unsigned short int Configurator::getThreads() const
{
    return m_threads;
}

int Configurator::getLoggerPriority() const
{
    return m_logger_priority;
}

string Configurator::getPersistence() const
{
    return m_persistence;
}

string Configurator::getConfigurationPath() const
{
    return m_configuration_path;
}

string Configurator::getConfigurationSelected() const
{
    return m_configuration_selected;
}

bool Configurator::loadXml()
{
    // TODO: Guess the path.
    char const * path_serverconfig_xml =
        "/home/brian/workspace/theultimatestrategy/TUSServer/Network/XmlRPCServer/serverconfig.xml";

    return m_serverconfig_xml.load_file(path_serverconfig_xml);
}

bool Configurator::parseXml()
{
    xml_node server = m_serverconfig_xml.child("server");

    m_host                   = server.child_value("host");
    m_port                   = server.child_value("port");
    m_threads                = lexical_cast<unsigned short int>(server.child_value("threads"));
    m_logger_priority        = lexical_cast<int>(server.child("logger").child_value("priority"));
    m_persistence            = server.child_value("persistence");
    m_configuration_path     = server.child("configuration").child_value("path");
    m_configuration_selected = server.child("configuration").child_value("selected");

    return true;
}
