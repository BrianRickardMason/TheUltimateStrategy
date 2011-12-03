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

#ifndef GAMESERVER_BUILDING_BUILDINGTOHUMANTRANSLATOR_HPP
#define GAMESERVER_BUILDING_BUILDINGTOHUMANTRANSLATOR_HPP

#include <GameServer/Building/Key.hpp>
#include <GameServer/Configuration/Configurator/Building/IBuilding.hpp>
#include <GameServer/Human/Key.hpp>
#include <map>

namespace GameServer
{
namespace Building
{

/**
 * @brief A "building to human" translator.
 *
 * TODO: Move configuration to xml after successful proof of concept on HumanOperator::engageHuman().
 */
class BuildingToHumanTranslator
{
public:
    /**
     * @brief Gets a vector of short keys of humans for which the building is a place of work.
     *
     * @param a_key A key of the building.
     *
     * @return The vector of human short keys, an empty vector if building is not a place for anyone to work.
     */
    static Human::KeyVec getHumansHostedForWork(
        Configuration::IBuildingKey const & a_key
    );
};

/**
 * @brief Arrays mapping humans to buildings.
 *
 * The arrays describe for which humans is a given building a place of work.
 */
Configuration::IKey const DEFENSIVE_BARBICAN_HOSTING_ARR        [] = {};
Configuration::IKey const DEFENSIVE_BATTLEMENTS_HOSTING_ARR     [] = {};
Configuration::IKey const DEFENSIVE_CASEMATE_HOSTING_ARR        [] = {};
Configuration::IKey const DEFENSIVE_CIRCUMVALLATION_HOSTING_ARR [] = {};
Configuration::IKey const DEFENSIVE_DONJON_HOSTING_ARR          [] = {};
Configuration::IKey const DEFENSIVE_MACHICOLATION_HOSTING_ARR   [] = {};
Configuration::IKey const DEFENSIVE_PORTCULLIS_HOSTING_ARR      [] = {};
Configuration::IKey const DEFENSIVE_POSTERN_HOSTING_ARR         [] = {};
Configuration::IKey const DEFENSIVE_VIEWING_TOWER_HOSTING_ARR   [] = {};

Configuration::IKey const GOLD_ALTAR_OF_WISHES_HOSTING_ARR      [] = {};
Configuration::IKey const GOLD_COMMUNICATION_TOWERS_HOSTING_ARR [] = {};
Configuration::IKey const GOLD_ETERNAL_CALENDAR_HOSTING_ARR     [] = {};
Configuration::IKey const GOLD_HUNTER_OF_METEORS_HOSTING_ARR    [] = {};
Configuration::IKey const GOLD_HUNTER_OF_RAINS_HOSTING_ARR      [] = {};
Configuration::IKey const GOLD_HUNTER_OF_STORMS_HOSTING_ARR     [] = {};
Configuration::IKey const GOLD_HUNTER_OF_WINDS_HOSTING_ARR      [] = {};
Configuration::IKey const GOLD_NECROPOLIS_HOSTING_ARR           [] = {};
Configuration::IKey const GOLD_ORACLE_HOSTING_ARR               [] = {};
Configuration::IKey const GOLD_PORTAL_OF_ELEMENTS_HOSTING_ARR   [] = {};
Configuration::IKey const GOLD_PSIONIC_ACADEMY_HOSTING_ARR      [] = {};
Configuration::IKey const GOLD_TOWER_OF_CHAOS_HOSTING_ARR       [] = {};

Configuration::IKey const REGULAR_BARRACKS_HOSTING_ARR          [] = { Human::KEY_SOLDIER_ARCHER_NOVICE,
                                                                       Human::KEY_SOLDIER_ARCHER_ADVANCED,
                                                                       Human::KEY_SOLDIER_HORSEMAN_NOVICE,
                                                                       Human::KEY_SOLDIER_HORSEMAN_ADVANCED,
                                                                       Human::KEY_SOLDIER_INFANTRYMAN_NOVICE,
                                                                       Human::KEY_SOLDIER_INFANTRYMAN_ADVANCED };
Configuration::IKey const REGULAR_FARM_HOSTING_ARR              [] = { Human::KEY_WORKER_FARMER_NOVICE,
                                                                       Human::KEY_WORKER_FARMER_ADVANCED };
Configuration::IKey const REGULAR_FORGE_HOSTING_ARR             [] = { Human::KEY_WORKER_BLACKSMITH_NOVICE,
                                                                       Human::KEY_WORKER_BLACKSMITH_ADVANCED};
Configuration::IKey const REGULAR_GUILD_HOSTING_ARR             [] = { Human::KEY_SORCERER_EARTH_NOVICE,
                                                                       Human::KEY_SORCERER_EARTH_ADVANCED,
                                                                       Human::KEY_SORCERER_FIRE_NOVICE,
                                                                       Human::KEY_SORCERER_FIRE_ADVANCED,
                                                                       Human::KEY_SORCERER_WATER_NOVICE,
                                                                       Human::KEY_SORCERER_WATER_ADVANCED,
                                                                       Human::KEY_SORCERER_WIND_NOVICE,
                                                                       Human::KEY_SORCERER_WIND_ADVANCED };
Configuration::IKey const REGULAR_HOUSE_HOSTING_ARR             [] = {};
Configuration::IKey const REGULAR_MARKETPLACE_HOSTING_ARR       [] = { Human::KEY_WORKER_MERCHANT_NOVICE,
                                                                       Human::KEY_WORKER_MERCHANT_ADVANCED };
Configuration::IKey const REGULAR_MINE_HOSTING_ARR              [] = { Human::KEY_WORKER_MINER_NOVICE,
                                                                       Human::KEY_WORKER_MINER_ADVANCED };
Configuration::IKey const REGULAR_QUARRY_HOSTING_ARR            [] = { Human::KEY_WORKER_STONE_MASON_NOVICE,
                                                                       Human::KEY_WORKER_STONE_MASON_ADVANCED };
Configuration::IKey const REGULAR_SAWMILL_HOSTING_ARR           [] = { Human::KEY_WORKER_LUMBERJACK_NOVICE,
                                                                       Human::KEY_WORKER_LUMBERJACK_ADVANCED };
Configuration::IKey const REGULAR_SCHOOL_HOSTING_ARR            [] = { Human::KEY_WORKER_TEACHER_NOVICE,
                                                                       Human::KEY_WORKER_TEACHER_ADVANCED };
Configuration::IKey const REGULAR_STEELWORKS_HOSTING_ARR        [] = { Human::KEY_WORKER_STEELWORKER_NOVICE,
                                                                       Human::KEY_WORKER_STEELWORKER_ADVANCED };
Configuration::IKey const REGULAR_TEMPLE_HOSTING_ARR            [] = {};

Configuration::IKey const SPECIAL_AQUEDUCT_HOSTING_ARR          [] = {};
Configuration::IKey const SPECIAL_BAWDY_HOUSE_HOSTING_ARR       [] = {};
Configuration::IKey const SPECIAL_COMMERCIAL_PORT_HOSTING_ARR   [] = {};
Configuration::IKey const SPECIAL_COURT_HOSTING_ARR             [] = {};
Configuration::IKey const SPECIAL_GRANARY_HOSTING_ARR           [] = {};
Configuration::IKey const SPECIAL_SEWERAGE_HOSTING_ARR          [] = {};

/**
 * @brief Vectors mapping humans to buildings.
 *
 * The vectors describe for which humans is a given building a place of work.
 *
 * @note Do not edit unless buildings are added or removed.
 */
Human::KeyVec const DEFENSIVE_BARBICAN_HOSTING_VEC        (DEFENSIVE_BARBICAN_HOSTING_ARR       , DEFENSIVE_BARBICAN_HOSTING_ARR        + sizeof(DEFENSIVE_BARBICAN_HOSTING_ARR       ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_BATTLEMENTS_HOSTING_VEC     (DEFENSIVE_BATTLEMENTS_HOSTING_ARR    , DEFENSIVE_BATTLEMENTS_HOSTING_ARR     + sizeof(DEFENSIVE_BATTLEMENTS_HOSTING_ARR    ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_CASEMATE_HOSTING_VEC        (DEFENSIVE_CASEMATE_HOSTING_ARR       , DEFENSIVE_CASEMATE_HOSTING_ARR        + sizeof(DEFENSIVE_CASEMATE_HOSTING_ARR       ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_CIRCUMVALLATION_HOSTING_VEC (DEFENSIVE_CIRCUMVALLATION_HOSTING_ARR, DEFENSIVE_CIRCUMVALLATION_HOSTING_ARR + sizeof(DEFENSIVE_CIRCUMVALLATION_HOSTING_ARR) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_DONJON_HOSTING_VEC          (DEFENSIVE_DONJON_HOSTING_ARR         , DEFENSIVE_DONJON_HOSTING_ARR          + sizeof(DEFENSIVE_DONJON_HOSTING_ARR         ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_MACHICOLATION_HOSTING_VEC   (DEFENSIVE_MACHICOLATION_HOSTING_ARR  , DEFENSIVE_MACHICOLATION_HOSTING_ARR   + sizeof(DEFENSIVE_MACHICOLATION_HOSTING_ARR  ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_PORTCULLIS_HOSTING_VEC      (DEFENSIVE_PORTCULLIS_HOSTING_ARR     , DEFENSIVE_PORTCULLIS_HOSTING_ARR      + sizeof(DEFENSIVE_PORTCULLIS_HOSTING_ARR     ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_POSTERN_HOSTING_VEC         (DEFENSIVE_POSTERN_HOSTING_ARR        , DEFENSIVE_POSTERN_HOSTING_ARR         + sizeof(DEFENSIVE_POSTERN_HOSTING_ARR        ) / sizeof(Configuration::IKey));
Human::KeyVec const DEFENSIVE_VIEWING_TOWER_HOSTING_VEC   (DEFENSIVE_VIEWING_TOWER_HOSTING_ARR  , DEFENSIVE_VIEWING_TOWER_HOSTING_ARR   + sizeof(DEFENSIVE_VIEWING_TOWER_HOSTING_ARR  ) / sizeof(Configuration::IKey));

Human::KeyVec const GOLD_ALTAR_OF_WISHES_HOSTING_VEC      (GOLD_ALTAR_OF_WISHES_HOSTING_ARR     , GOLD_ALTAR_OF_WISHES_HOSTING_ARR      + sizeof(GOLD_ALTAR_OF_WISHES_HOSTING_ARR     ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_COMMUNICATION_TOWERS_HOSTING_VEC (GOLD_COMMUNICATION_TOWERS_HOSTING_ARR, GOLD_COMMUNICATION_TOWERS_HOSTING_ARR + sizeof(GOLD_COMMUNICATION_TOWERS_HOSTING_ARR) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_ETERNAL_CALENDAR_HOSTING_VEC     (GOLD_ETERNAL_CALENDAR_HOSTING_ARR    , GOLD_ETERNAL_CALENDAR_HOSTING_ARR     + sizeof(GOLD_ETERNAL_CALENDAR_HOSTING_ARR    ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_HUNTER_OF_METEORS_HOSTING_VEC    (GOLD_HUNTER_OF_METEORS_HOSTING_ARR   , GOLD_HUNTER_OF_METEORS_HOSTING_ARR    + sizeof(GOLD_HUNTER_OF_METEORS_HOSTING_ARR   ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_HUNTER_OF_RAINS_HOSTING_VEC      (GOLD_HUNTER_OF_RAINS_HOSTING_ARR     , GOLD_HUNTER_OF_RAINS_HOSTING_ARR      + sizeof(GOLD_HUNTER_OF_RAINS_HOSTING_ARR     ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_HUNTER_OF_STORMS_HOSTING_VEC     (GOLD_HUNTER_OF_STORMS_HOSTING_ARR    , GOLD_HUNTER_OF_STORMS_HOSTING_ARR     + sizeof(GOLD_HUNTER_OF_STORMS_HOSTING_ARR    ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_HUNTER_OF_WINDS_HOSTING_VEC      (GOLD_HUNTER_OF_WINDS_HOSTING_ARR     , GOLD_HUNTER_OF_WINDS_HOSTING_ARR      + sizeof(GOLD_HUNTER_OF_WINDS_HOSTING_ARR     ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_NECROPOLIS_HOSTING_VEC           (GOLD_NECROPOLIS_HOSTING_ARR          , GOLD_NECROPOLIS_HOSTING_ARR           + sizeof(GOLD_NECROPOLIS_HOSTING_ARR          ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_ORACLE_HOSTING_VEC               (GOLD_ORACLE_HOSTING_ARR              , GOLD_ORACLE_HOSTING_ARR               + sizeof(GOLD_ORACLE_HOSTING_ARR              ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_PORTAL_OF_ELEMENTS_HOSTING_VEC   (GOLD_PORTAL_OF_ELEMENTS_HOSTING_ARR  , GOLD_PORTAL_OF_ELEMENTS_HOSTING_ARR   + sizeof(GOLD_PORTAL_OF_ELEMENTS_HOSTING_ARR  ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_PSIONIC_ACADEMY_HOSTING_VEC      (GOLD_PSIONIC_ACADEMY_HOSTING_ARR     , GOLD_PSIONIC_ACADEMY_HOSTING_ARR      + sizeof(GOLD_PSIONIC_ACADEMY_HOSTING_ARR     ) / sizeof(Configuration::IKey));
Human::KeyVec const GOLD_TOWER_OF_CHAOS_HOSTING_VEC       (GOLD_TOWER_OF_CHAOS_HOSTING_ARR      , GOLD_TOWER_OF_CHAOS_HOSTING_ARR       + sizeof(GOLD_TOWER_OF_CHAOS_HOSTING_ARR      ) / sizeof(Configuration::IKey));

Human::KeyVec const REGULAR_BARRACKS_HOSTING_VEC          (REGULAR_BARRACKS_HOSTING_ARR         , REGULAR_BARRACKS_HOSTING_ARR          + sizeof(REGULAR_BARRACKS_HOSTING_ARR         ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_FARM_HOSTING_VEC              (REGULAR_FARM_HOSTING_ARR             , REGULAR_FARM_HOSTING_ARR              + sizeof(REGULAR_FARM_HOSTING_ARR             ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_FORGE_HOSTING_VEC             (REGULAR_FORGE_HOSTING_ARR            , REGULAR_FORGE_HOSTING_ARR             + sizeof(REGULAR_FORGE_HOSTING_ARR            ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_GUILD_HOSTING_VEC             (REGULAR_GUILD_HOSTING_ARR            , REGULAR_GUILD_HOSTING_ARR             + sizeof(REGULAR_GUILD_HOSTING_ARR            ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_HOUSE_HOSTING_VEC             (REGULAR_HOUSE_HOSTING_ARR            , REGULAR_HOUSE_HOSTING_ARR             + sizeof(REGULAR_HOUSE_HOSTING_ARR            ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_MARKETPLACE_HOSTING_VEC       (REGULAR_MARKETPLACE_HOSTING_ARR      , REGULAR_MARKETPLACE_HOSTING_ARR       + sizeof(REGULAR_MARKETPLACE_HOSTING_ARR      ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_MINE_HOSTING_VEC              (REGULAR_MINE_HOSTING_ARR             , REGULAR_MINE_HOSTING_ARR              + sizeof(REGULAR_MINE_HOSTING_ARR             ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_QUARRY_HOSTING_VEC            (REGULAR_QUARRY_HOSTING_ARR           , REGULAR_QUARRY_HOSTING_ARR            + sizeof(REGULAR_QUARRY_HOSTING_ARR           ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_SAWMILL_HOSTING_VEC           (REGULAR_SAWMILL_HOSTING_ARR          , REGULAR_SAWMILL_HOSTING_ARR           + sizeof(REGULAR_SAWMILL_HOSTING_ARR          ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_SCHOOL_HOSTING_VEC            (REGULAR_SCHOOL_HOSTING_ARR           , REGULAR_SCHOOL_HOSTING_ARR            + sizeof(REGULAR_SCHOOL_HOSTING_ARR           ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_STEELWORKS_HOSTING_VEC        (REGULAR_STEELWORKS_HOSTING_ARR       , REGULAR_STEELWORKS_HOSTING_ARR        + sizeof(REGULAR_STEELWORKS_HOSTING_ARR       ) / sizeof(Configuration::IKey));
Human::KeyVec const REGULAR_TEMPLE_HOSTING_VEC            (REGULAR_TEMPLE_HOSTING_ARR           , REGULAR_TEMPLE_HOSTING_ARR            + sizeof(REGULAR_TEMPLE_HOSTING_ARR           ) / sizeof(Configuration::IKey));

Human::KeyVec const SPECIAL_AQUEDUCT_HOSTING_VEC          (SPECIAL_AQUEDUCT_HOSTING_ARR         , SPECIAL_AQUEDUCT_HOSTING_ARR          + sizeof(SPECIAL_AQUEDUCT_HOSTING_ARR         ) / sizeof(Configuration::IKey));
Human::KeyVec const SPECIAL_BAWDY_HOUSE_HOSTING_VEC       (SPECIAL_BAWDY_HOUSE_HOSTING_ARR      , SPECIAL_BAWDY_HOUSE_HOSTING_ARR       + sizeof(SPECIAL_BAWDY_HOUSE_HOSTING_ARR      ) / sizeof(Configuration::IKey));
Human::KeyVec const SPECIAL_COMMERCIAL_PORT_HOSTING_VEC   (SPECIAL_COMMERCIAL_PORT_HOSTING_ARR  , SPECIAL_COMMERCIAL_PORT_HOSTING_ARR   + sizeof(SPECIAL_COMMERCIAL_PORT_HOSTING_ARR  ) / sizeof(Configuration::IKey));
Human::KeyVec const SPECIAL_COURT_HOSTING_VEC             (SPECIAL_COURT_HOSTING_ARR            , SPECIAL_COURT_HOSTING_ARR             + sizeof(SPECIAL_COURT_HOSTING_ARR            ) / sizeof(Configuration::IKey));
Human::KeyVec const SPECIAL_GRANARY_HOSTING_VEC           (SPECIAL_GRANARY_HOSTING_ARR          , SPECIAL_GRANARY_HOSTING_ARR           + sizeof(SPECIAL_GRANARY_HOSTING_ARR          ) / sizeof(Configuration::IKey));
Human::KeyVec const SPECIAL_SEWERAGE_HOSTING_VEC          (SPECIAL_SEWERAGE_HOSTING_ARR         , SPECIAL_SEWERAGE_HOSTING_ARR          + sizeof(SPECIAL_SEWERAGE_HOSTING_ARR         ) / sizeof(Configuration::IKey));

/**
 * @brief Pairs mapping humans to buildings.
 *
 * The pairs describe for which humans is a given building a place of work.
 *
 * @note Do not edit unless buildings are added or removed.
 */
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_BARBICAN_HOSTING_PAIR        (KEY_DEFENSIVE_BARBICAN       , DEFENSIVE_BARBICAN_HOSTING_VEC       );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_BATTLEMENTS_HOSTING_PAIR     (KEY_DEFENSIVE_BATTLEMENTS    , DEFENSIVE_BATTLEMENTS_HOSTING_VEC    );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_CASEMATE_HOSTING_PAIR        (KEY_DEFENSIVE_CASEMATE       , DEFENSIVE_CASEMATE_HOSTING_VEC       );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_CIRCUMVALLATION_HOSTING_PAIR (KEY_DEFENSIVE_CIRCUMVALLATION, DEFENSIVE_CIRCUMVALLATION_HOSTING_VEC);
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_DONJON_HOSTING_PAIR          (KEY_DEFENSIVE_DONJON         , DEFENSIVE_DONJON_HOSTING_VEC         );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_MACHICOLATION_HOSTING_PAIR   (KEY_DEFENSIVE_MACHICOLATION  , DEFENSIVE_MACHICOLATION_HOSTING_VEC  );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_PORTCULLIS_HOSTING_PAIR      (KEY_DEFENSIVE_PORTCULLIS     , DEFENSIVE_PORTCULLIS_HOSTING_VEC     );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_POSTERN_HOSTING_PAIR         (KEY_DEFENSIVE_POSTERN        , DEFENSIVE_POSTERN_HOSTING_VEC        );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> DEFENSIVE_VIEWING_TOWER_HOSTING_PAIR   (KEY_DEFENSIVE_VIEWING_TOWER  , DEFENSIVE_VIEWING_TOWER_HOSTING_VEC  );

const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_ALTAR_OF_WISHES_HOSTING_PAIR      (KEY_GOLD_ALTAR_OF_WISHES     , GOLD_ALTAR_OF_WISHES_HOSTING_VEC     );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_COMMUNICATION_TOWERS_HOSTING_PAIR (KEY_GOLD_COMMUNICATION_TOWERS, GOLD_COMMUNICATION_TOWERS_HOSTING_VEC);
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_ETERNAL_CALENDAR_HOSTING_PAIR     (KEY_GOLD_ETERNAL_CALENDAR    , GOLD_ETERNAL_CALENDAR_HOSTING_VEC    );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_HUNTER_OF_METEORS_HOSTING_PAIR    (KEY_GOLD_HUNTER_OF_METEORS   , GOLD_HUNTER_OF_METEORS_HOSTING_VEC   );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_HUNTER_OF_RAINS_HOSTING_PAIR      (KEY_GOLD_HUNTER_OF_RAINS     , GOLD_HUNTER_OF_RAINS_HOSTING_VEC     );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_HUNTER_OF_STORMS_HOSTING_PAIR     (KEY_GOLD_HUNTER_OF_STORMS    , GOLD_HUNTER_OF_STORMS_HOSTING_VEC    );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_HUNTER_OF_WINDS_HOSTING_PAIR      (KEY_GOLD_HUNTER_OF_WINDS     , GOLD_HUNTER_OF_WINDS_HOSTING_VEC     );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_NECROPOLIS_HOSTING_PAIR           (KEY_GOLD_NECROPOLIS          , GOLD_NECROPOLIS_HOSTING_VEC          );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_ORACLE_HOSTING_PAIR               (KEY_GOLD_ORACLE              , GOLD_ORACLE_HOSTING_VEC              );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_PORTAL_OF_ELEMENTS_HOSTING_PAIR   (KEY_GOLD_PORTAL_OF_ELEMENTS  , GOLD_PORTAL_OF_ELEMENTS_HOSTING_VEC  );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_PSIONIC_ACADEMY_HOSTING_PAIR      (KEY_GOLD_PSIONIC_ACADEMY     , GOLD_PSIONIC_ACADEMY_HOSTING_VEC     );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> GOLD_TOWER_OF_CHAOS_HOSTING_PAIR       (KEY_GOLD_TOWER_OF_CHAOS      , GOLD_TOWER_OF_CHAOS_HOSTING_VEC      );

const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_BARRACKS_HOSTING_PAIR          (KEY_REGULAR_BARRACKS         , REGULAR_BARRACKS_HOSTING_VEC         );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_FARM_HOSTING_PAIR              (KEY_REGULAR_FARM             , REGULAR_FARM_HOSTING_VEC             );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_FORGE_HOSTING_PAIR             (KEY_REGULAR_FORGE            , REGULAR_FORGE_HOSTING_VEC            );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_GUILD_HOSTING_PAIR             (KEY_REGULAR_GUILD            , REGULAR_GUILD_HOSTING_VEC            );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_HOUSE_HOSTING_PAIR             (KEY_REGULAR_HOUSE            , REGULAR_HOUSE_HOSTING_VEC            );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_MARKETPLACE_HOSTING_PAIR       (KEY_REGULAR_MARKETPLACE      , REGULAR_MARKETPLACE_HOSTING_VEC      );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_MINE_HOSTING_PAIR              (KEY_REGULAR_MINE             , REGULAR_MINE_HOSTING_VEC             );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_QUARRY_HOSTING_PAIR            (KEY_REGULAR_QUARRY           , REGULAR_QUARRY_HOSTING_VEC           );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_SAWMILL_HOSTING_PAIR           (KEY_REGULAR_SAWMILL          , REGULAR_SAWMILL_HOSTING_VEC          );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_SCHOOL_HOSTING_PAIR            (KEY_REGULAR_SCHOOL           , REGULAR_SCHOOL_HOSTING_VEC           );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_STEELWORKS_HOSTING_PAIR        (KEY_REGULAR_STEELWORKS       , REGULAR_STEELWORKS_HOSTING_VEC       );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> REGULAR_TEMPLE_HOSTING_PAIR            (KEY_REGULAR_TEMPLE           , REGULAR_TEMPLE_HOSTING_VEC           );

const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_AQUEDUCT_HOSTING_PAIR          (KEY_SPECIAL_AQUEDUCT         , SPECIAL_AQUEDUCT_HOSTING_VEC         );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_BAWDY_HOUSE_HOSTING_PAIR       (KEY_SPECIAL_BAWDY_HOUSE      , SPECIAL_BAWDY_HOUSE_HOSTING_VEC      );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_COMMERCIAL_PORT_HOSTING_PAIR   (KEY_SPECIAL_COMMERCIAL_PORT  , SPECIAL_COMMERCIAL_PORT_HOSTING_VEC  );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_COURT_HOSTING_PAIR             (KEY_SPECIAL_COURT            , SPECIAL_COURT_HOSTING_VEC            );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_GRANARY_HOSTING_PAIR           (KEY_SPECIAL_GRANARY          , SPECIAL_GRANARY_HOSTING_VEC          );
const std::pair<Configuration::IBuildingKey, Human::KeyVec> SPECIAL_SEWERAGE_HOSTING_PAIR          (KEY_SPECIAL_SEWERAGE         , SPECIAL_SEWERAGE_HOSTING_VEC         );

/**
 * @brief An array mapping humans to buildings.
 *
 * The array describes for which humans is a given building a place of work.
 *
 * @note Do not edit unless buildings are added or removed.
 */
const std::pair<Configuration::IBuildingKey, Human::KeyVec> BUILDING_IS_A_PLACE_OF_WORK_FOR_ARRAY [] = {
    DEFENSIVE_BARBICAN_HOSTING_PAIR,
    DEFENSIVE_BATTLEMENTS_HOSTING_PAIR,
    DEFENSIVE_CASEMATE_HOSTING_PAIR,
    DEFENSIVE_CIRCUMVALLATION_HOSTING_PAIR,
    DEFENSIVE_DONJON_HOSTING_PAIR,
    DEFENSIVE_MACHICOLATION_HOSTING_PAIR,
    DEFENSIVE_PORTCULLIS_HOSTING_PAIR,
    DEFENSIVE_POSTERN_HOSTING_PAIR,
    DEFENSIVE_VIEWING_TOWER_HOSTING_PAIR,

    GOLD_ALTAR_OF_WISHES_HOSTING_PAIR,
    GOLD_COMMUNICATION_TOWERS_HOSTING_PAIR,
    GOLD_ETERNAL_CALENDAR_HOSTING_PAIR,
    GOLD_HUNTER_OF_METEORS_HOSTING_PAIR,
    GOLD_HUNTER_OF_RAINS_HOSTING_PAIR,
    GOLD_HUNTER_OF_STORMS_HOSTING_PAIR,
    GOLD_HUNTER_OF_WINDS_HOSTING_PAIR,
    GOLD_NECROPOLIS_HOSTING_PAIR,
    GOLD_ORACLE_HOSTING_PAIR,
    GOLD_PORTAL_OF_ELEMENTS_HOSTING_PAIR,
    GOLD_PSIONIC_ACADEMY_HOSTING_PAIR,
    GOLD_TOWER_OF_CHAOS_HOSTING_PAIR,

    REGULAR_BARRACKS_HOSTING_PAIR,
    REGULAR_FARM_HOSTING_PAIR,
    REGULAR_FORGE_HOSTING_PAIR,
    REGULAR_GUILD_HOSTING_PAIR,
    REGULAR_HOUSE_HOSTING_PAIR,
    REGULAR_MARKETPLACE_HOSTING_PAIR,
    REGULAR_MINE_HOSTING_PAIR,
    REGULAR_QUARRY_HOSTING_PAIR,
    REGULAR_SAWMILL_HOSTING_PAIR,
    REGULAR_SCHOOL_HOSTING_PAIR,
    REGULAR_STEELWORKS_HOSTING_PAIR,
    REGULAR_TEMPLE_HOSTING_PAIR,

    SPECIAL_AQUEDUCT_HOSTING_PAIR,
    SPECIAL_BAWDY_HOUSE_HOSTING_PAIR,
    SPECIAL_COMMERCIAL_PORT_HOSTING_PAIR,
    SPECIAL_COURT_HOSTING_PAIR,
    SPECIAL_GRANARY_HOSTING_PAIR,
    SPECIAL_SEWERAGE_HOSTING_PAIR
};

/**
 * @brief A map mapping humans to buildings.
 *
 * The map describes for which humans is a given building a place of work.
 *
 * @note Do not edit.
 */
const std::map<Configuration::IBuildingKey, Human::KeyVec> BUILDING_IS_A_PLACE_OF_WORK_FOR(
    BUILDING_IS_A_PLACE_OF_WORK_FOR_ARRAY,
    BUILDING_IS_A_PLACE_OF_WORK_FOR_ARRAY + sizeof(BUILDING_IS_A_PLACE_OF_WORK_FOR_ARRAY) / sizeof(BUILDING_IS_A_PLACE_OF_WORK_FOR_ARRAY[0])
);

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_BUILDINGTOHUMANTRANSLATOR_HPP
