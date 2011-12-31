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

#include <TUSGame/GameServer/Building/Key.hpp>
#include <TUSGame/GameServer/Resource/Key.hpp>
#include <TUSGame/GameServerUT/Helpers/Functions.hpp>

using namespace GameServer::Building;
using namespace GameServer::Resource;
using namespace boost;
using namespace std;

namespace R = GameServer::Resource;

ResourceWithVolumeMap getResourceMap(
    IContextShrPtr    const   a_context,
    vector<R::Volume> const & a_volumes
)
{
    ResourceWithVolumeMap resource_map;

    if (!a_volumes.empty())
    {
        ResourceWithVolumeShrPtr
            resource_with_volume_coal = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_COAL, a_volumes[0]),
            resource_with_volume_food = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_FOOD, a_volumes[1]),
            resource_with_volume_gold = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_GOLD, a_volumes[2]),
            resource_with_volume_iron = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_IRON, a_volumes[3]),
            resource_with_volume_rock = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_ROCK, a_volumes[4]),
            resource_with_volume_wood = make_shared<ResourceWithVolume>(a_context, KEY_RESOURCE_WOOD, a_volumes[5]);

        resource_map.insert(make_pair(KEY_RESOURCE_COAL, resource_with_volume_coal));
        resource_map.insert(make_pair(KEY_RESOURCE_FOOD, resource_with_volume_food));
        resource_map.insert(make_pair(KEY_RESOURCE_GOLD, resource_with_volume_gold));
        resource_map.insert(make_pair(KEY_RESOURCE_IRON, resource_with_volume_iron));
        resource_map.insert(make_pair(KEY_RESOURCE_ROCK, resource_with_volume_rock));
        resource_map.insert(make_pair(KEY_RESOURCE_WOOD, resource_with_volume_wood));
    }

    return resource_map;
}
