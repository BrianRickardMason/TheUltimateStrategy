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

#ifndef GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP
#define GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP

#include "Human.hpp"
#include "HumanWithVolumeRecord.hpp"

namespace GameServer
{
namespace Human
{

/**
 * @brief A human with volume.
 */
class HumanWithVolume
{
public:
    /**
     * @brief Constructs the human with volume.
     *
     * @param a_key    The key of the human.
     * @param a_volume The volume of the human.
     */
    HumanWithVolume(
        Key    const & a_key,
        Volume const & a_volume
    );

    /**
     * @brief Constructs the human with volume.
     *
     * @param a_record The record of human with volume.
     */
    explicit HumanWithVolume(
        HumanWithVolumeRecord const & a_record
    );

    /**
     * @brief Gets the key of the human.
     *
     * @return The key of the human.
     */
    Key const & getKey() const;

    /**
     * @brief Gets the identifier of the human.
     *
     * @return The identifier of the human.
     */
    IDHuman const & getIDHuman() const;

    /**
     * @brief Gets the experience of the human.
     *
     * @return The experience of the human.
     */
    Experience const & getExperience() const;

    /**
     * @brief Gets the volume of the human.
     *
     * @return The volume of the human.
     */
    Volume const & getVolume() const;

private:
    /**
     * @brief The human.
     */
    Human m_human;

    /**
     * @brief The volume of the human.
     */
    Volume m_volume;
};

/**
 * @brief A shared pointer of human with volume.
 */
typedef boost::shared_ptr<HumanWithVolume> HumanWithVolumeShrPtr;

/**
 * @brief A pair of human with volume.
 */
typedef std::pair<Key, HumanWithVolumeShrPtr> HumanWithVolumePair;

/**
 * @brief A map of human with volume.
 */
typedef std::map<Key, HumanWithVolumeShrPtr> HumanWithVolumeMap;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANWITHVOLUME_HPP
