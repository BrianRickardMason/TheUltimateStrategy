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

#ifndef GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP
#define GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP

#include <TUSGame/GameServer/Configuration/Configurator/Human/IHuman.hpp>
#include <TUSGame/GameServer/Human/HumanWithVolumeRecord.hpp>
#include <TUSServer/Network/XmlRPCServer/IContext.hpp>

namespace GameServer
{
namespace Human
{

/**
 * @brief HumanWithVolume.
 */
class HumanWithVolume
{
public:
    /**
     * @brief Constructs the human with volume.
     *
     * @param a_context The context of the server.
     * @param a_key     The key of the human.
     * @param a_volume  The volume of the human.
     */
    HumanWithVolume(
        IContextShrPtr      const a_context,
        Configuration::IKey const a_key,
        Volume              const a_volume
    );

    /**
     * @brief Constructs the human with volume.
     *
     * @param a_context The context of the server.
     * @param a_record  The record of human with volume.
     */
    HumanWithVolume(
        IContextShrPtr        const   a_context,
        HumanWithVolumeRecord const & a_record
    );

    /**
     * @brief Gets the human.
     *
     * @return The human.
     */
    Configuration::IHumanShrPtr getHuman() const;

    /**
     * @brief Gets the volume of the human.
     *
     * @return The volume of the human.
     */
    Volume getVolume() const;

private:
    /**
     * @brief The human.
     */
    Configuration::IHumanShrPtr m_human;

    /**
     * @brief The volume of the human.
     */
    Volume m_volume;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<HumanWithVolume> HumanWithVolumeShrPtr;
typedef std::pair<Configuration::IKey, HumanWithVolumeShrPtr> HumanWithVolumePair;
typedef std::map<Configuration::IKey, HumanWithVolumeShrPtr> HumanWithVolumeMap;
//}@

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP
