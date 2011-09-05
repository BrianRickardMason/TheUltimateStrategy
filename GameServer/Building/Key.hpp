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

#ifndef GAMESERVER_BUILDING_KEY_HPP
#define GAMESERVER_BUILDING_KEY_HPP

#include "../Common/KeyHash.hpp"
#include "IDBuilding.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>

namespace GameServer
{
namespace Building
{

/**
 * @brief The key.
 *
 * Uniquely identifies a building object.
 *
 * TODO: Use boost::operators.
 * TODO: Consider facilitators/stabilizators of the interface (getIdBuildingClass, getIdBuilding).
 *       First step to unification (base and derived classes/specialization).
 */
class Key
{
public:
    /**
     * @brief The internal key.
     */
    typedef boost::tuple<IDBuilding> InternalKey;

    /**
     * @brief Constructs the key.
     *
     * @param a_id_building The identifier of the building.
     */
    Key(
        IDBuilding const & a_id_building
    )
        : m_internal_key(a_id_building)
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
        : m_internal_key(IDBuilding((a_key_hash % 10000) / 100, a_key_hash % 100))
    {
    }

    /**
     * @brief Operators.
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
        return   Common::KEY_HASH_MAGIC_VALUE_BUILDING * 1000000
               + 0                                     * 10000
               + m_internal_key.get<0>().getValue1()   * 100
               + m_internal_key.get<0>().getValue2()   * 1;
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
const Key KEY_DEFENSIVE_BARBICAN        (ID_BUILDING_DEFENSIVE_BARBICAN       );
const Key KEY_DEFENSIVE_BATTLEMENTS     (ID_BUILDING_DEFENSIVE_BATTLEMENTS    );
const Key KEY_DEFENSIVE_CASEMATE        (ID_BUILDING_DEFENSIVE_CASEMATE       );
const Key KEY_DEFENSIVE_CIRCUMVALLATION (ID_BUILDING_DEFENSIVE_CIRCUMVALLATION);
const Key KEY_DEFENSIVE_DONJON          (ID_BUILDING_DEFENSIVE_DONJON         );
const Key KEY_DEFENSIVE_MACHICOLATION   (ID_BUILDING_DEFENSIVE_MACHICOLATION  );
const Key KEY_DEFENSIVE_PORTCULLIS      (ID_BUILDING_DEFENSIVE_PORTCULLIS     );
const Key KEY_DEFENSIVE_POSTERN         (ID_BUILDING_DEFENSIVE_POSTERN        );
const Key KEY_DEFENSIVE_VIEWING_TOWER   (ID_BUILDING_DEFENSIVE_VIEWING_TOWER  );

const Key KEY_GOLD_ALTAR_OF_WISHES      (ID_BUILDING_GOLD_ALTAR_OF_WISHES     );
const Key KEY_GOLD_COMMUNICATION_TOWERS (ID_BUILDING_GOLD_COMMUNICATION_TOWERS);
const Key KEY_GOLD_ETERNAL_CALENDAR     (ID_BUILDING_GOLD_ETERNAL_CALENDAR    );
const Key KEY_GOLD_HUNTER_OF_METEORS    (ID_BUILDING_GOLD_HUNTER_OF_METEORS   );
const Key KEY_GOLD_HUNTER_OF_RAINS      (ID_BUILDING_GOLD_HUNTER_OF_RAINS     );
const Key KEY_GOLD_HUNTER_OF_STORMS     (ID_BUILDING_GOLD_HUNTER_OF_STORMS    );
const Key KEY_GOLD_HUNTER_OF_WINDS      (ID_BUILDING_GOLD_HUNTER_OF_WINDS     );
const Key KEY_GOLD_NECROPOLIS           (ID_BUILDING_GOLD_NECROPOLIS          );
const Key KEY_GOLD_ORACLE               (ID_BUILDING_GOLD_ORACLE              );
const Key KEY_GOLD_PORTAL_OF_ELEMENTS   (ID_BUILDING_GOLD_PORTAL_OF_ELEMENTS  );
const Key KEY_GOLD_PSIONIC_ACADEMY      (ID_BUILDING_GOLD_PSIONIC_ACADEMY     );
const Key KEY_GOLD_TOWER_OF_CHAOS       (ID_BUILDING_GOLD_TOWER_OF_CHAOS      );

const Key KEY_REGULAR_BARRACKS          (ID_BUILDING_REGULAR_BARRACKS         );
const Key KEY_REGULAR_FARM              (ID_BUILDING_REGULAR_FARM             );
const Key KEY_REGULAR_FORGE             (ID_BUILDING_REGULAR_FORGE            );
const Key KEY_REGULAR_GUILD             (ID_BUILDING_REGULAR_GUILD            );
const Key KEY_REGULAR_HOUSE             (ID_BUILDING_REGULAR_HOUSE            );
const Key KEY_REGULAR_MARKETPLACE       (ID_BUILDING_REGULAR_MARKETPLACE      );
const Key KEY_REGULAR_MINE              (ID_BUILDING_REGULAR_MINE             );
const Key KEY_REGULAR_QUARRY            (ID_BUILDING_REGULAR_QUARRY           );
const Key KEY_REGULAR_SAWMILL           (ID_BUILDING_REGULAR_SAWMILL          );
const Key KEY_REGULAR_SCHOOL            (ID_BUILDING_REGULAR_SCHOOL           );
const Key KEY_REGULAR_STEELWORKS        (ID_BUILDING_REGULAR_STEELWORKS       );
const Key KEY_REGULAR_TEMPLE            (ID_BUILDING_REGULAR_TEMPLE           );

const Key KEY_SPECIAL_AQUEDUCT          (ID_BUILDING_SPECIAL_AQUEDUCT         );
const Key KEY_SPECIAL_BAWDY_HOUSE       (ID_BUILDING_SPECIAL_BAWDY_HOUSE      );
const Key KEY_SPECIAL_COMMERCIAL_PORT   (ID_BUILDING_SPECIAL_COMMERCIAL_PORT  );
const Key KEY_SPECIAL_COURT             (ID_BUILDING_SPECIAL_COURT            );
const Key KEY_SPECIAL_GRANARY           (ID_BUILDING_SPECIAL_GRANARY          );
const Key KEY_SPECIAL_SEWERAGE          (ID_BUILDING_SPECIAL_SEWERAGE         );

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_KEY_HPP
