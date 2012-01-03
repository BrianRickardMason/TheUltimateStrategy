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

#include <Game/GameServer/Resource/Helpers.hpp>
#include <boost/make_shared.hpp>
#include <Server/Network/XmlRPCServer/IContext.hpp>

namespace GameServer
{
namespace Resource
{

/**
 * FIXME: Dear future me. This is as ugly as it gets... Please invent the time machine and slap me.
 */

ResourceWithVolumeMap add(
    IContextShrPtr        const   a_context,
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
)
{
    ResourceWithVolumeMap new_map;

    for (ResourceWithVolumeMap::const_iterator it = a_map_1.begin(); it != a_map_1.end(); ++it)
    {
        Configuration::IKey key = it->second->getResource()->getKey();

        ResourceWithVolumeMap::const_iterator found = a_map_2.find(key);

        Volume volume(0);

        if (found != a_map_2.end())
        {
            volume = it->second->getVolume() + a_map_2.at(it->first)->getVolume();
        }
        else
        {
            volume = it->second->getVolume();
        }

        ResourceWithVolumeShrPtr resource = boost::make_shared<ResourceWithVolume>(a_context, key, volume);

        ResourceWithVolumePair resource_pair(key, resource);

        new_map.insert(resource_pair);
    }

    for (ResourceWithVolumeMap::const_iterator it = a_map_2.begin(); it != a_map_2.end(); ++it)
    {
        Configuration::IKey key = it->second->getResource()->getKey();

        ResourceWithVolumeMap::const_iterator found = a_map_1.find(key);

        if (found == a_map_1.end())
        {
            ResourceWithVolumeShrPtr resource =
                boost::make_shared<ResourceWithVolume>(a_context, key, it->second->getVolume());

            ResourceWithVolumePair resource_pair(key, resource);

            new_map.insert(resource_pair);
        }

    }

    return new_map;
}

ResourceWithVolumeMap multiply(
    IContextShrPtr        const   a_context,
    ResourceWithVolumeMap const & a_map,
    unsigned int          const   a_factor
)
{
    ResourceWithVolumeMap new_map;

    for (ResourceWithVolumeMap::const_iterator it = a_map.begin(); it != a_map.end(); ++it)
    {
        Configuration::IKey key = it->second->getResource()->getKey();

        Volume volume = it->second->getVolume() * a_factor;

        ResourceWithVolumeShrPtr resource = boost::make_shared<ResourceWithVolume>(a_context, key, volume);

        ResourceWithVolumePair resource_pair(key, resource);

        new_map.insert(resource_pair);
    }

    return new_map;
}

bool areEqual(
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
)
{
    for (ResourceWithVolumeMap::const_iterator it = a_map_1.begin(); it != a_map_1.end(); ++it)
    {
        ResourceWithVolumeMap::const_iterator found = a_map_2.find(it->first);

        if (found != a_map_2.end())
        {
            if (it->second->getVolume() != a_map_2.at(it->first)->getVolume())
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    for (ResourceWithVolumeMap::const_iterator it = a_map_2.begin(); it != a_map_2.end(); ++it)
    {
        ResourceWithVolumeMap::const_iterator found = a_map_1.find(it->first);

        if (found == a_map_1.end())
        {
            return false;
        }
    }

    return true;
}

bool isFirstGreaterOrEqual(
    ResourceWithVolumeMap const & a_map_1,
    ResourceWithVolumeMap const & a_map_2
)
{
    if (a_map_1.empty())
    {
        return a_map_2.empty() ? true : false;
    }

    for (ResourceWithVolumeMap::const_iterator it = a_map_1.begin(); it != a_map_1.end(); ++it)
    {
        ResourceWithVolumeMap::const_iterator found = a_map_2.find(it->first);

        if (found != a_map_2.end())
        {
            if (it->second->getVolume() < found->second->getVolume())
            {
                return false;
            }
        }
    }

    for (ResourceWithVolumeMap::const_iterator it = a_map_2.begin(); it != a_map_2.end(); ++it)
    {
        ResourceWithVolumeMap::const_iterator found = a_map_1.find(it->first);

        if (found == a_map_1.end())
        {
            if (it->second->getVolume() > 0)
            {
                return false;
            }
        }
    }

    return true;
}

} // namespace Resource
} // namespace GameServer
