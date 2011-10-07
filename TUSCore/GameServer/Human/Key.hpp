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

#ifndef GAMESERVER_HUMAN_KEY_HPP
#define GAMESERVER_HUMAN_KEY_HPP

#include "../Common/KeyHash.hpp"
#include "Experience.hpp"
#include "IDHuman.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <vector>

namespace GameServer
{
namespace Human
{

/**
 * @brief The key.
 *
 * Uniquely identifies a human object.
 *
 * TODO: Use boost::operators.
 * TODO: Consider facilitators/stabilizators of the interface (getIdHumanClass, getIdHuman, getExperience).
 *       First step to unification (base and derived classes/specialization).
 */
class Key
{
public:
    /**
     * @brief The internal key.
     */
    typedef boost::tuple<IDHuman, Experience> InternalKey;

    /**
     * @brief Constructs the key.
     *
     * @param a_id_human   The identifier of the human.
     * @param a_experience The experience of the human.
     */
    Key(
        IDHuman    const & a_id_human,
        Experience const & a_experience
    )
        : m_internal_key(a_id_human, a_experience)
    {
    }

    /**
     * @brief Constructs the key.
     *
     * @param a_key_hash A key hash.
     */
    explicit Key(
        Common::KeyHash const & a_key_hash
    )
        : m_internal_key(IDHuman((a_key_hash % 1000000) / 10000, (a_key_hash % 10000) / 100), Experience(a_key_hash % 100))
    {
    }

    /**
     * @brief Relational operators.
     */
    bool operator==(Key const & a_rhs) const { return m_internal_key == a_rhs.m_internal_key; }
    bool operator< (Key const & a_rhs) const { return m_internal_key <  a_rhs.m_internal_key; }

    /**
     * @brief Gets the internal key.
     *
     * @return The internal key.
     */
    InternalKey const & getInternalKey() const
    {
        return m_internal_key;
    }

    /**
     * @brief Translates the key to "hash" value.
     *
     * @return The "hash" value.
     */
    Common::KeyHash toHash() const
    {
        return   Common::KEY_HASH_MAGIC_VALUE_HUMAN  * 1000000
               + m_internal_key.get<0>().getValue1() * 10000
               + m_internal_key.get<0>().getValue2() * 100
               + m_internal_key.get<1>().getValue()  * 1;
    }

private:
    /**
     * @brief The internal key.
     */
    InternalKey m_internal_key;
};

/**
 * @brief The available keys.
 */
const Key KEY_SOLDIER_ARCHER_NOVICE       (ID_HUMAN_SOLDIER_ARCHER,      EXPERIENCE_NOVICE  );
const Key KEY_SOLDIER_ARCHER_ADVANCED     (ID_HUMAN_SOLDIER_ARCHER,      EXPERIENCE_ADVANCED);
const Key KEY_SOLDIER_HORSEMAN_NOVICE     (ID_HUMAN_SOLDIER_HORSEMAN,    EXPERIENCE_NOVICE  );
const Key KEY_SOLDIER_HORSEMAN_ADVANCED   (ID_HUMAN_SOLDIER_HORSEMAN,    EXPERIENCE_ADVANCED);
const Key KEY_SOLDIER_INFANTRYMAN_NOVICE  (ID_HUMAN_SOLDIER_INFANTRYMAN, EXPERIENCE_NOVICE  );
const Key KEY_SOLDIER_INFANTRYMAN_ADVANCED(ID_HUMAN_SOLDIER_INFANTRYMAN, EXPERIENCE_ADVANCED);

const Key KEY_SORCERER_EARTH_NOVICE       (ID_HUMAN_SORCERER_EARTH, EXPERIENCE_NOVICE  );
const Key KEY_SORCERER_EARTH_ADVANCED     (ID_HUMAN_SORCERER_EARTH, EXPERIENCE_ADVANCED);
const Key KEY_SORCERER_FIRE_NOVICE        (ID_HUMAN_SORCERER_FIRE,  EXPERIENCE_NOVICE  );
const Key KEY_SORCERER_FIRE_ADVANCED      (ID_HUMAN_SORCERER_FIRE,  EXPERIENCE_ADVANCED);
const Key KEY_SORCERER_WATER_NOVICE       (ID_HUMAN_SORCERER_WATER, EXPERIENCE_NOVICE  );
const Key KEY_SORCERER_WATER_ADVANCED     (ID_HUMAN_SORCERER_WATER, EXPERIENCE_ADVANCED);
const Key KEY_SORCERER_WIND_NOVICE        (ID_HUMAN_SORCERER_WIND,  EXPERIENCE_NOVICE  );
const Key KEY_SORCERER_WIND_ADVANCED      (ID_HUMAN_SORCERER_WIND,  EXPERIENCE_ADVANCED);

const Key KEY_SPY_AGENT_NOVICE            (ID_HUMAN_SPY_AGENT, EXPERIENCE_NOVICE  );
const Key KEY_SPY_AGENT_ADVANCED          (ID_HUMAN_SPY_AGENT, EXPERIENCE_ADVANCED);
const Key KEY_SPY_SPY_NOVICE              (ID_HUMAN_SPY_SPY,   EXPERIENCE_NOVICE  );
const Key KEY_SPY_SPY_ADVANCED            (ID_HUMAN_SPY_SPY,   EXPERIENCE_ADVANCED);
const Key KEY_SPY_THUG_NOVICE             (ID_HUMAN_SPY_THUG,  EXPERIENCE_NOVICE  );
const Key KEY_SPY_THUG_ADVANCED           (ID_HUMAN_SPY_THUG,  EXPERIENCE_ADVANCED);

const Key KEY_WORKER_BLACKSMITH_NOVICE    (ID_HUMAN_WORKER_BLACKSMITH,  EXPERIENCE_NOVICE  );
const Key KEY_WORKER_BLACKSMITH_ADVANCED  (ID_HUMAN_WORKER_BLACKSMITH,  EXPERIENCE_ADVANCED);
const Key KEY_WORKER_BREEDER_NOVICE       (ID_HUMAN_WORKER_BREEDER,     EXPERIENCE_NOVICE  );
const Key KEY_WORKER_BREEDER_ADVANCED     (ID_HUMAN_WORKER_BREEDER,     EXPERIENCE_ADVANCED);
const Key KEY_WORKER_DRUID_NOVICE         (ID_HUMAN_WORKER_DRUID,       EXPERIENCE_NOVICE  );
const Key KEY_WORKER_DRUID_ADVANCED       (ID_HUMAN_WORKER_DRUID,       EXPERIENCE_ADVANCED);
const Key KEY_WORKER_FARMER_NOVICE        (ID_HUMAN_WORKER_FARMER,      EXPERIENCE_NOVICE  );
const Key KEY_WORKER_FARMER_ADVANCED      (ID_HUMAN_WORKER_FARMER,      EXPERIENCE_ADVANCED);
const Key KEY_WORKER_FISHERMAN_NOVICE     (ID_HUMAN_WORKER_FISHERMAN,   EXPERIENCE_NOVICE  );
const Key KEY_WORKER_FISHERMAN_ADVANCED   (ID_HUMAN_WORKER_FISHERMAN,   EXPERIENCE_ADVANCED);
const Key KEY_WORKER_JOBLESS_NOVICE       (ID_HUMAN_WORKER_JOBLESS,     EXPERIENCE_NOVICE  );
const Key KEY_WORKER_JOBLESS_ADVANCED     (ID_HUMAN_WORKER_JOBLESS,     EXPERIENCE_ADVANCED);
const Key KEY_WORKER_LUMBERJACK_NOVICE    (ID_HUMAN_WORKER_LUMBERJACK,  EXPERIENCE_NOVICE  );
const Key KEY_WORKER_LUMBERJACK_ADVANCED  (ID_HUMAN_WORKER_LUMBERJACK,  EXPERIENCE_ADVANCED);
const Key KEY_WORKER_MERCHANT_NOVICE      (ID_HUMAN_WORKER_MERCHANT,    EXPERIENCE_NOVICE  );
const Key KEY_WORKER_MERCHANT_ADVANCED    (ID_HUMAN_WORKER_MERCHANT,    EXPERIENCE_ADVANCED);
const Key KEY_WORKER_MINER_NOVICE         (ID_HUMAN_WORKER_MINER,       EXPERIENCE_NOVICE  );
const Key KEY_WORKER_MINER_ADVANCED       (ID_HUMAN_WORKER_MINER,       EXPERIENCE_ADVANCED);
const Key KEY_WORKER_OFFICIAL_NOVICE      (ID_HUMAN_WORKER_OFFICIAL,    EXPERIENCE_NOVICE  );
const Key KEY_WORKER_OFFICIAL_ADVANCED    (ID_HUMAN_WORKER_OFFICIAL,    EXPERIENCE_ADVANCED);
const Key KEY_WORKER_PRIEST_NOVICE        (ID_HUMAN_WORKER_PRIEST,      EXPERIENCE_NOVICE  );
const Key KEY_WORKER_PRIEST_ADVANCED      (ID_HUMAN_WORKER_PRIEST,      EXPERIENCE_ADVANCED);
const Key KEY_WORKER_STEELWORKER_NOVICE   (ID_HUMAN_WORKER_STEELWORKER, EXPERIENCE_NOVICE  );
const Key KEY_WORKER_STEELWORKER_ADVANCED (ID_HUMAN_WORKER_STEELWORKER, EXPERIENCE_ADVANCED);
const Key KEY_WORKER_STONE_MASON_NOVICE   (ID_HUMAN_WORKER_STONE_MASON, EXPERIENCE_NOVICE  );
const Key KEY_WORKER_STONE_MASON_ADVANCED (ID_HUMAN_WORKER_STONE_MASON, EXPERIENCE_ADVANCED);
const Key KEY_WORKER_TEACHER_NOVICE       (ID_HUMAN_WORKER_TEACHER,     EXPERIENCE_NOVICE  );
const Key KEY_WORKER_TEACHER_ADVANCED     (ID_HUMAN_WORKER_TEACHER,     EXPERIENCE_ADVANCED);

/**
 * @brief The vector of keys.
 */
typedef std::vector<Key> KeyVec;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_KEY_HPP
