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

#ifndef GAMESERVER_RESOURCE_RESOURCEWITHVOLUME_HPP
#define GAMESERVER_RESOURCE_RESOURCEWITHVOLUME_HPP

#include <TUSGame/GameServer/Configuration/Configurator/Resource/IResource.hpp>
#include <TUSGame/GameServer/Resource/ResourceWithVolumeRecord.hpp>
#include <TUSCore/Network/XmlRPCServer/IContext.hpp>

namespace GameServer
{
namespace Resource
{

/**
 * @brief ResourceWithVolume.
 */
class ResourceWithVolume
{
public:
    /**
     * @brief Constructs the resource with volume.
     *
     * @param a_context The context of the server.
     * @param a_key     The key of the human.
     * @param a_volume  The volume of the resource.
     */
    ResourceWithVolume(
        IContextShrPtr      const a_context,
        Configuration::IKey const a_key,
        Volume              const a_volume
    );

    /**
     * @brief Constructs the resource with volume.
     *
     * @param a_context The context of the server.
     * @param a_record  The record of resource with volume.
     */
    explicit ResourceWithVolume(
        IContextShrPtr           const   a_context,
        ResourceWithVolumeRecord const & a_record
    );

    /**
     * @brief Gets the resource.
     *
     * @return The resource.
     */
    Configuration::IResourceShrPtr getResource() const;

    /**
     * @brief Gets the volume of the resource.
     *
     * @return The volume of the resource.
     */
    Volume getVolume() const;

private:
    /**
     * @brief The resource.
     */
    Configuration::IResourceShrPtr m_resource;

    /**
     * @brief The volume of the resource.
     */
    Volume m_volume;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<ResourceWithVolume> ResourceWithVolumeShrPtr;
typedef std::pair<std::string, ResourceWithVolumeShrPtr> ResourceWithVolumePair; // TODO: A key.
typedef std::map<std::string, ResourceWithVolumeShrPtr> ResourceWithVolumeMap; // TODO: A key.
//}@

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_RESOURCEWITHVOLUME_HPP
