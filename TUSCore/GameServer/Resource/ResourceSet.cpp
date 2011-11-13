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

#include "ResourceSet.hpp"
#include <GameServer/Configuration/Configurator/Resource/ConfiguratorResource.hpp>
#include <GameServer/Configuration/Configurator/Resource/IResource.hpp>
#include <boost/make_shared.hpp>

using namespace boost;
using namespace std;

namespace GameServer
{
namespace Resource
{

ResourceSet::ResourceSet()
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    for (std::map<std::string, GameServer::Configuration::IResourceShrPtr>::const_iterator it = resources.begin();
         it != resources.end();
         ++it)
    {
        m_map.insert(make_pair(it->second->getKey(), make_shared<ResourceWithVolume>(it->second->getKey(), 0)));
    }

    BOOST_ASSERT(m_map.size() == resources.size());
}

ResourceSet::ResourceSet(
    ResourceWithVolumeMap const & a_resource_with_volume_map
)
    : m_map(a_resource_with_volume_map)
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    for (std::map<std::string, GameServer::Configuration::IResourceShrPtr>::const_iterator it = resources.begin();
         it != resources.end();
         ++it)
    {
        try
        {
            m_map.at(it->second->getKey());
        }
        catch (out_of_range const &)
        {
            m_map.insert(make_pair(it->second->getKey(), make_shared<ResourceWithVolume>(it->second->getKey(), 0)));
        }
    }

    BOOST_ASSERT(m_map.size() == resources.size());
}

ResourceSet::ResourceSet(
    ResourceSet const & a_rhs
)
    : m_map(a_rhs.m_map)
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());
}

ResourceSet const ResourceSet::operator +(
    ResourceSet const & a_rhs
) const
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    return ResourceSet(*this) += a_rhs;
}

ResourceSet const ResourceSet::operator *(
    unsigned int const a_factor
) const
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    return ResourceSet(*this) *= a_factor;
}

bool ResourceSet::operator ==(
    ResourceSet const & a_rhs
) const
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    for (ResourceWithVolumeMap::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        if (it->second->getVolume() != a_rhs.m_map.at(it->first)->getVolume())
        {
            return false;
        }
    }

    return true;
}

bool ResourceSet::operator >=(
    ResourceSet const & a_rhs
) const
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    for (ResourceWithVolumeMap::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        if (it->second->getVolume() < a_rhs.m_map.at(it->first)->getVolume())
        {
            return false;
        }
    }

    return true;
}

ResourceSet ResourceSet::operator +=(
    ResourceSet const & a_rhs
)
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    ResourceWithVolumeMap new_map;

    for (ResourceWithVolumeMap::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        string key = it->second->getResource()->getKey();

        Volume volume = it->second->getVolume() + a_rhs.m_map.at(it->first)->getVolume();

        ResourceWithVolumeShrPtr resource = make_shared<ResourceWithVolume>(key, volume);

        ResourceWithVolumePair resource_pair(key, resource);

        new_map.insert(resource_pair);
    }

    m_map = new_map;

    return *this;
}

ResourceSet ResourceSet::operator *=(
    unsigned int const a_factor
)
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    ResourceWithVolumeMap new_map;

    for (ResourceWithVolumeMap::const_iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        string key = it->second->getResource()->getKey();

        Volume volume = it->second->getVolume() * a_factor;

        ResourceWithVolumeShrPtr resource = make_shared<ResourceWithVolume>(key, volume);

        ResourceWithVolumePair resource_pair(key, resource);

        new_map.insert(resource_pair);
    }

    m_map = new_map;

    return *this;
}

ResourceWithVolumeMap const & ResourceSet::getMap() const
{
    GameServer::Configuration::ConfiguratorResource CONFIGURATOR_RESOURCE;
    CONFIGURATOR_RESOURCE.configure();
    std::map<std::string, GameServer::Configuration::IResourceShrPtr> resources = CONFIGURATOR_RESOURCE.getResources();

    BOOST_ASSERT(m_map.size() == resources.size());

    return m_map;
}

} // namespace Resource
} // namespace GameServer
