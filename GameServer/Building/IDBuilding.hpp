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

#ifndef GAMESERVER_BUILDING_IDBUILDING_HPP
#define GAMESERVER_BUILDING_IDBUILDING_HPP

#include "../Common/ConstrainedPair.hpp"

namespace GameServer
{
namespace Building
{

/**
 * @brief The identifier of a building.
 */
typedef Common::ConstrainedPair<Common::RangedPairUnsignedShortIntPolicy<1, 9, 1, 12, 1, 12, 1, 6> > IDBuilding;

/**
 * @brief The available classes of a building.
 */
unsigned short int const ID_BUILDING_CLASS_DEFENSIVE(1);
unsigned short int const ID_BUILDING_CLASS_GOLD     (2);
unsigned short int const ID_BUILDING_CLASS_REGULAR  (3);
unsigned short int const ID_BUILDING_CLASS_SPECIAL  (4);

/**
 * @brief The available identifiers of the buildings.
 */
IDBuilding const ID_BUILDING_DEFENSIVE_BARBICAN       (1, 1);
IDBuilding const ID_BUILDING_DEFENSIVE_BATTLEMENTS    (1, 2);
IDBuilding const ID_BUILDING_DEFENSIVE_CASEMATE       (1, 3);
IDBuilding const ID_BUILDING_DEFENSIVE_CIRCUMVALLATION(1, 4);
IDBuilding const ID_BUILDING_DEFENSIVE_DONJON         (1, 5);
IDBuilding const ID_BUILDING_DEFENSIVE_MACHICOLATION  (1, 6);
IDBuilding const ID_BUILDING_DEFENSIVE_PORTCULLIS     (1, 7);
IDBuilding const ID_BUILDING_DEFENSIVE_POSTERN        (1, 8);
IDBuilding const ID_BUILDING_DEFENSIVE_VIEWING_TOWER  (1, 9);

IDBuilding const ID_BUILDING_GOLD_ALTAR_OF_WISHES     (2, 1);
IDBuilding const ID_BUILDING_GOLD_COMMUNICATION_TOWERS(2, 2);
IDBuilding const ID_BUILDING_GOLD_ETERNAL_CALENDAR    (2, 3);
IDBuilding const ID_BUILDING_GOLD_HUNTER_OF_METEORS   (2, 4);
IDBuilding const ID_BUILDING_GOLD_HUNTER_OF_RAINS     (2, 5);
IDBuilding const ID_BUILDING_GOLD_HUNTER_OF_STORMS    (2, 6);
IDBuilding const ID_BUILDING_GOLD_HUNTER_OF_WINDS     (2, 7);
IDBuilding const ID_BUILDING_GOLD_NECROPOLIS          (2, 8);
IDBuilding const ID_BUILDING_GOLD_ORACLE              (2, 9);
IDBuilding const ID_BUILDING_GOLD_PORTAL_OF_ELEMENTS  (2, 10);
IDBuilding const ID_BUILDING_GOLD_PSIONIC_ACADEMY     (2, 11);
IDBuilding const ID_BUILDING_GOLD_TOWER_OF_CHAOS      (2, 12);

IDBuilding const ID_BUILDING_REGULAR_BARRACKS         (3, 1);
IDBuilding const ID_BUILDING_REGULAR_FARM             (3, 2);
IDBuilding const ID_BUILDING_REGULAR_FORGE            (3, 3);
IDBuilding const ID_BUILDING_REGULAR_GUILD            (3, 4);
IDBuilding const ID_BUILDING_REGULAR_HOUSE            (3, 5);
IDBuilding const ID_BUILDING_REGULAR_MARKETPLACE      (3, 6);
IDBuilding const ID_BUILDING_REGULAR_MINE             (3, 7);
IDBuilding const ID_BUILDING_REGULAR_QUARRY           (3, 8);
IDBuilding const ID_BUILDING_REGULAR_SAWMILL          (3, 9);
IDBuilding const ID_BUILDING_REGULAR_SCHOOL           (3, 10);
IDBuilding const ID_BUILDING_REGULAR_STEELWORKS       (3, 11);
IDBuilding const ID_BUILDING_REGULAR_TEMPLE           (3, 12);

IDBuilding const ID_BUILDING_SPECIAL_AQUEDUCT         (4, 1);
IDBuilding const ID_BUILDING_SPECIAL_BAWDY_HOUSE      (4, 2);
IDBuilding const ID_BUILDING_SPECIAL_COMMERCIAL_PORT  (4, 3);
IDBuilding const ID_BUILDING_SPECIAL_COURT            (4, 4);
IDBuilding const ID_BUILDING_SPECIAL_GRANARY          (4, 5);
IDBuilding const ID_BUILDING_SPECIAL_SEWERAGE         (4, 6);

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_IDBUILDING_HPP
