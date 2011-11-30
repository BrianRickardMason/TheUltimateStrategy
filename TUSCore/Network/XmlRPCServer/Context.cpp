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
#include <Network/XmlRPCServer/Configurator/Configurator.hpp>
#include <Network/XmlRPCServer/Configurator/Human/ConfiguratorHuman.hpp>
#include <Network/XmlRPCServer/Configurator/Resource/ConfiguratorResource.hpp>
#include <Network/XmlRPCServer/Context.hpp>

Context::Context()
    : m_configurator(new Configurator),
      m_configurator_building(new ConfiguratorBuilding(m_configurator)),
      m_configurator_human(new ConfiguratorHuman(m_configurator)),
      m_configurator_resource(new ConfiguratorResource(m_configurator))
{
}

IConfiguratorShrPtr Context::getConfigurator() const
{
    return m_configurator;
}

IConfiguratorBuildingShrPtr Context::getConfiguratorBuilding() const
{
    return m_configurator_building;
}

IConfiguratorHumanShrPtr Context::getConfiguratorHuman() const
{
    return m_configurator_human;
}

IConfiguratorResourceShrPtr Context::getConfiguratorResource() const
{
    return m_configurator_resource;
}
