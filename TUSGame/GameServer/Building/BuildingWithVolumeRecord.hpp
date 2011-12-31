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

#ifndef GAMESERVER_BUILDING_BUILDINGWITHVOLUMERECORD_HPP
#define GAMESERVER_BUILDING_BUILDINGWITHVOLUMERECORD_HPP

#include <TUSGame/GameServer/Building/Volume.hpp>
#include <TUSGame/GameServer/Common/IDHolder.hpp>
#include <TUSGame/GameServer/Configuration/Configurator/Building/IBuilding.hpp>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Building
{

/**
 * @brief BuildingWithVolumeRecord.
 */
class BuildingWithVolumeRecord
{
public:
    /**
     * @brief Constructs the building with volume record.
     *
     * @param a_id_holder The identifier of the holder.
     * @param a_key       The key of the building.
     * @param a_volume    The volume of the building.
     */
    BuildingWithVolumeRecord(
        Common::IDHolder    const a_id_holder,
        Configuration::IKey const a_key,
        Volume              const a_volume
    );

    /**
     * @brief Gets the identifier of the holder.
     *
     * @return The identifier of the holder.
     */
    Common::IDHolder const & getIDHolder() const;

    /**
     * @brief Gets the key of the building.
     *
     * @return The key of the building.
     */
    Configuration::IKey getKey() const;

    /**
     * @brief Gets the volume of the building.
     *
     * @return The volume of the building.
     */
    Volume getVolume() const;

private:
    /**
     * @brief The identifier of holder.
     */
    Common::IDHolder m_id_holder;

    /**
     * @brief The key of the building.
     */
    Configuration::IKey m_key;

    /**
     * @brief The volume of the building.
     */
    Volume m_volume;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<BuildingWithVolumeRecord> BuildingWithVolumeRecordShrPtr;
typedef std::pair<Configuration::IKey, BuildingWithVolumeRecordShrPtr> BuildingWithVolumeRecordPair;
typedef std::map<Configuration::IKey, BuildingWithVolumeRecordShrPtr> BuildingWithVolumeRecordMap;
//}@

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_BUILDINGWITHVOLUMERECORD_HPP
