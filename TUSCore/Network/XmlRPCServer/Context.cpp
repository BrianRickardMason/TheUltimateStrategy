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

#include <Network/XmlRPCServer/Configurator/Building/ConfiguratorBuilding.hpp>
#include <Network/XmlRPCServer/Context.hpp>

Context::Context(
    std::string        const a_host,
    std::string        const a_port,
    unsigned short int const a_threads,
    int                const a_logger_priority,
    std::string        const a_persistence
)
    : m_host(a_host),
      m_port(a_port),
      m_threads(a_threads),
      m_logger_priority(a_logger_priority),
      m_persistence(a_persistence),
      m_configurator_building(new ConfiguratorBuilding)
{
}

std::string Context::getHost() const
{
    return m_host;
}

std::string Context::getPort() const
{
    return m_port;
}

unsigned short int Context::getThreads() const
{
    return m_threads;
}

int Context::getLoggerPriority() const
{
    return m_logger_priority;
}

std::string Context::getPersistence() const
{
    return m_persistence;
}

IConfiguratorBuildingShrPtr Context::getConfiguratorBuilding() const
{
    return m_configurator_building;
}
