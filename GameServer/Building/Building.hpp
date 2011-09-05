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

#ifndef GAMESERVER_BUILDING_BUILDING_HPP
#define GAMESERVER_BUILDING_BUILDING_HPP

#include "Key.hpp"
#include <boost/make_shared.hpp>
#include <vector>

namespace GameServer
{
namespace Building
{

/**
 * @brief A building.
 *
 * TODO: Consider a shortcut -> building.toHash(). The same goes for human and resource.
 */
class Building
{
public:
    /**
     * @brief Constructs the building.
     *
     * @param a_key The key of the building.
     */
    explicit Building(
        Key const & a_key
    );

    /**
     * @brief Gets the key of the building.
     *
     * @return The key of the building.
     */
    Key const & getKey() const;

    /**
     * @brief Gets the identifier of the building.
     *
     * @return The identifier of the building.
     */
    IDBuilding const & getIDBuilding() const;

private:
    /**
     * @brief The key of the building.
     */
    Key m_key;
};

/**
 * @brief A shared pointer of building.
 */
typedef boost::shared_ptr<Building> BuildingShrPtr;

/**
 * @brief The available buildings.
 */
const Building BUILDING_DEFENSIVE_BARBICAN        (KEY_DEFENSIVE_BARBICAN       );
const Building BUILDING_DEFENSIVE_BATTLEMENTS     (KEY_DEFENSIVE_BATTLEMENTS    );
const Building BUILDING_DEFENSIVE_CASEMATE        (KEY_DEFENSIVE_CASEMATE       );
const Building BUILDING_DEFENSIVE_CIRCUMVALLATION (KEY_DEFENSIVE_CIRCUMVALLATION);
const Building BUILDING_DEFENSIVE_DONJON          (KEY_DEFENSIVE_DONJON         );
const Building BUILDING_DEFENSIVE_MACHICOLATION   (KEY_DEFENSIVE_MACHICOLATION  );
const Building BUILDING_DEFENSIVE_PORTCULLIS      (KEY_DEFENSIVE_PORTCULLIS     );
const Building BUILDING_DEFENSIVE_POSTERN         (KEY_DEFENSIVE_POSTERN        );
const Building BUILDING_DEFENSIVE_VIEWING_TOWER   (KEY_DEFENSIVE_VIEWING_TOWER  );

const Building BUILDING_GOLD_ALTAR_OF_WISHES      (KEY_GOLD_ALTAR_OF_WISHES     );
const Building BUILDING_GOLD_COMMUNICATION_TOWERS (KEY_GOLD_COMMUNICATION_TOWERS);
const Building BUILDING_GOLD_ETERNAL_CALENDAR     (KEY_GOLD_ETERNAL_CALENDAR    );
const Building BUILDING_GOLD_HUNTER_OF_METEORS    (KEY_GOLD_HUNTER_OF_METEORS   );
const Building BUILDING_GOLD_HUNTER_OF_RAINS      (KEY_GOLD_HUNTER_OF_RAINS     );
const Building BUILDING_GOLD_HUNTER_OF_STORMS     (KEY_GOLD_HUNTER_OF_STORMS    );
const Building BUILDING_GOLD_HUNTER_OF_WINDS      (KEY_GOLD_HUNTER_OF_WINDS     );
const Building BUILDING_GOLD_NECROPOLIS           (KEY_GOLD_NECROPOLIS          );
const Building BUILDING_GOLD_ORACLE               (KEY_GOLD_ORACLE              );
const Building BUILDING_GOLD_PORTAL_OF_ELEMENTS   (KEY_GOLD_PORTAL_OF_ELEMENTS  );
const Building BUILDING_GOLD_PSIONIC_ACADEMY      (KEY_GOLD_PSIONIC_ACADEMY     );
const Building BUILDING_GOLD_TOWER_OF_CHAOS       (KEY_GOLD_TOWER_OF_CHAOS      );

const Building BUILDING_REGULAR_BARRACKS          (KEY_REGULAR_BARRACKS         );
const Building BUILDING_REGULAR_FARM              (KEY_REGULAR_FARM             );
const Building BUILDING_REGULAR_FORGE             (KEY_REGULAR_FORGE            );
const Building BUILDING_REGULAR_GUILD             (KEY_REGULAR_GUILD            );
const Building BUILDING_REGULAR_HOUSE             (KEY_REGULAR_HOUSE            );
const Building BUILDING_REGULAR_MARKETPLACE       (KEY_REGULAR_MARKETPLACE      );
const Building BUILDING_REGULAR_MINE              (KEY_REGULAR_MINE             );
const Building BUILDING_REGULAR_QUARRY            (KEY_REGULAR_QUARRY           );
const Building BUILDING_REGULAR_SAWMILL           (KEY_REGULAR_SAWMILL          );
const Building BUILDING_REGULAR_SCHOOL            (KEY_REGULAR_SCHOOL           );
const Building BUILDING_REGULAR_STEELWORKS        (KEY_REGULAR_STEELWORKS       );
const Building BUILDING_REGULAR_TEMPLE            (KEY_REGULAR_TEMPLE           );

const Building BUILDING_SPECIAL_AQUEDUCT          (KEY_SPECIAL_AQUEDUCT         );
const Building BUILDING_SPECIAL_BAWDY_HOUSE       (KEY_SPECIAL_BAWDY_HOUSE      );
const Building BUILDING_SPECIAL_COMMERCIAL_PORT   (KEY_SPECIAL_COMMERCIAL_PORT  );
const Building BUILDING_SPECIAL_COURT             (KEY_SPECIAL_COURT            );
const Building BUILDING_SPECIAL_GRANARY           (KEY_SPECIAL_GRANARY          );
const Building BUILDING_SPECIAL_SEWERAGE          (KEY_SPECIAL_SEWERAGE         );

/**
 * @brief The array of available buildings.
 */
const Building BUILDING_ARR [] = {
    BUILDING_DEFENSIVE_BARBICAN,
    BUILDING_DEFENSIVE_BATTLEMENTS,
    BUILDING_DEFENSIVE_CASEMATE,
    BUILDING_DEFENSIVE_CIRCUMVALLATION,
    BUILDING_DEFENSIVE_DONJON,
    BUILDING_DEFENSIVE_MACHICOLATION,
    BUILDING_DEFENSIVE_PORTCULLIS,
    BUILDING_DEFENSIVE_POSTERN,
    BUILDING_DEFENSIVE_VIEWING_TOWER,

    BUILDING_GOLD_ALTAR_OF_WISHES,
    BUILDING_GOLD_COMMUNICATION_TOWERS,
    BUILDING_GOLD_ETERNAL_CALENDAR,
    BUILDING_GOLD_HUNTER_OF_METEORS,
    BUILDING_GOLD_HUNTER_OF_RAINS,
    BUILDING_GOLD_HUNTER_OF_STORMS,
    BUILDING_GOLD_HUNTER_OF_WINDS,
    BUILDING_GOLD_NECROPOLIS,
    BUILDING_GOLD_ORACLE,
    BUILDING_GOLD_PORTAL_OF_ELEMENTS,
    BUILDING_GOLD_PSIONIC_ACADEMY,
    BUILDING_GOLD_TOWER_OF_CHAOS,

    BUILDING_REGULAR_BARRACKS,
    BUILDING_REGULAR_FARM,
    BUILDING_REGULAR_FORGE,
    BUILDING_REGULAR_GUILD,
    BUILDING_REGULAR_HOUSE,
    BUILDING_REGULAR_MARKETPLACE,
    BUILDING_REGULAR_MINE,
    BUILDING_REGULAR_QUARRY,
    BUILDING_REGULAR_SAWMILL,
    BUILDING_REGULAR_SCHOOL,
    BUILDING_REGULAR_STEELWORKS,
    BUILDING_REGULAR_TEMPLE,

    BUILDING_SPECIAL_AQUEDUCT,
    BUILDING_SPECIAL_BAWDY_HOUSE,
    BUILDING_SPECIAL_COMMERCIAL_PORT,
    BUILDING_SPECIAL_COURT,
    BUILDING_SPECIAL_GRANARY,
    BUILDING_SPECIAL_SEWERAGE
};

/**
 * @brief The vector of buildings.
 */
typedef std::vector<Building> BuildingVec;

/**
 * @brief The vector of available buildings.
 */
const BuildingVec BUILDING_VEC(
    BUILDING_ARR,
    BUILDING_ARR + sizeof(BUILDING_ARR) / sizeof(BUILDING_ARR[0])
);

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_BUILDING_HPP
