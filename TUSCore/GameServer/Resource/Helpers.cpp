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

#include <GameServer/Resource/Helpers.hpp>
#include <boost/make_shared.hpp>
#include <Network/XmlRPCServer/IContext.hpp>

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
        Configuration::IResourceKey key = it->second->getResource()->getKey();

        Volume volume = it->second->getVolume() + a_map_2.at(it->first)->getVolume();

        ResourceWithVolumeShrPtr resource = boost::make_shared<ResourceWithVolume>(a_context, key, volume);

        ResourceWithVolumePair resource_pair(key, resource);

        new_map.insert(resource_pair);
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
        Configuration::IResourceKey key = it->second->getResource()->getKey();

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
        if (it->second->getVolume() != a_map_2.at(it->first)->getVolume())
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
    // FIXME: A nasty workaround! This will not work fine for long.
    // TODO: Please make sure that ResourcePersistency returns non-empty maps (maps with 0).
    // TODO: Add assertions on size of the maps here.
    if (a_map_1.empty())
    {
        return false;
    }

    for (ResourceWithVolumeMap::const_iterator it = a_map_1.begin(); it != a_map_1.end(); ++it)
    {
        if (it->second->getVolume() < a_map_2.at(it->first)->getVolume())
        {
            return false;
        }
    }

    return true;
}

} // namespace Resource
} // namespace GameServer
