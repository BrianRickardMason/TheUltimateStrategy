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

#include <TUSServer/Network/XmlRPCServer/Configurator/Base/ConfiguratorBase.hpp>
#include <boost/lexical_cast.hpp>

ConfiguratorBase::ConfiguratorBase(
    IConfiguratorShrPtr const a_configurator
)
    : m_configurator(a_configurator)
{
    configure();
}

bool ConfiguratorBase::configure()
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

unsigned short int ConfiguratorBase::getFamineDeathFactor() const
{
    return m_famine_death_factor;
}

unsigned short int ConfiguratorBase::getHumanExperienceFactor() const
{
    return m_human_experience_factor;
}

unsigned short int ConfiguratorBase::getHumanReproduceFactor() const
{
    return m_human_reproduce_factor;
}

unsigned short int ConfiguratorBase::getPovertyDismissFactor() const
{
    return m_poverty_dismiss_factor;
}

bool ConfiguratorBase::loadXml()
{
    std::string path_base_xml =
        m_configurator->getConfigurationPath() + m_configurator->getConfigurationSelected() + "/Base/base.xml";

    return m_base_xml.load_file(path_base_xml.c_str());
}

bool ConfiguratorBase::parseXml()
{
    using boost::lexical_cast;

    // TODO: Add verification here.

    pugi::xml_node base = m_base_xml.child("base");

    m_famine_death_factor     = lexical_cast<unsigned short int>(base.child_value("faminedeathfactor"));
    m_human_experience_factor = lexical_cast<unsigned short int>(base.child_value("humanexperiencefactor"));
    m_human_reproduce_factor  = lexical_cast<unsigned short int>(base.child_value("humanreproducefactor"));
    m_poverty_dismiss_factor  = lexical_cast<unsigned short int>(base.child_value("povertydismissfactor"));

    return true;
}
