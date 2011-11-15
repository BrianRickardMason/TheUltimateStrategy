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

#ifndef GAMESERVER_HUMAN_HUMANWITHVOLUMERECORD_HPP
#define GAMESERVER_HUMAN_HUMANWITHVOLUMERECORD_HPP

#include <GameServer/Common/IDHolder.hpp>
#include <GameServer/Configuration/Configurator/Human/IHuman.hpp>
#include <GameServer/Human/Volume.hpp>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Human
{

/**
 * @brief HumanWithVolumeRecord.
 */
class HumanWithVolumeRecord
{
public:
    /**
     * @brief Constructs the human with volume record.
     *
     * @param a_id_holder The identifier of the holder.
     * @param a_key       The key of the human.
     * @param a_volume    The volume of the human.
     */
    HumanWithVolumeRecord(
        Common::IDHolder         const a_id_holder,
        Configuration::IHumanKey const a_key,
        Volume                   const a_volume
    );

    /**
     * @brief Gets the identifier of the holder.
     *
     * @return The identifier of the holder.
     */
    Common::IDHolder const & getIDHolder() const;

    /**
     * @brief Gets the key of the human.
     *
     * @return The key of the human.
     */
    Configuration::IHumanKey getKey() const;

    /**
     * @brief Gets the volume of the human.
     *
     * @return The volume of the human.
     */
    Volume getVolume() const;

private:
    /**
     * @brief The identifier of holder.
     */
    Common::IDHolder m_id_holder;

    /**
     * @brief The key of the human.
     */
    Configuration::IHumanKey m_key;

    /**
     * @brief The volume of the human.
     */
    Volume m_volume;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<HumanWithVolumeRecord> HumanWithVolumeRecordShrPtr;
typedef std::pair<Configuration::IHumanKey, HumanWithVolumeRecordShrPtr> HumanWithVolumeRecordPair;
typedef std::map<Configuration::IHumanKey, HumanWithVolumeRecordShrPtr> HumanWithVolumeRecordMap;
//}@

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANWITHVOLUMERECORD_HPP
