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

#ifndef GAMESERVER_HUMAN_HUMANTOBUILDINGTRANSLATOR_HPP
#define GAMESERVER_HUMAN_HUMANTOBUILDINGTRANSLATOR_HPP

#include <GameServer/Building/Key.hpp>
#include <GameServer/Configuration/Configurator/Building/IBuilding.hpp>
#include <GameServer/Configuration/Configurator/Human/IHuman.hpp>
#include <GameServer/Human/Key.hpp>
#include <Network/XmlRPCServer/IContext.hpp>
#include <map>
#include <vector>

namespace GameServer
{
namespace Human
{

/**
 * @brief HumanToBuildingTranslator.
 */
class HumanToBuildingTranslator
{
public:
    /**
     * @brief Gets a building which is a place of work of a given human.
     *
     * @param a_context The context of the server.
     * @param a_key     A key of the human.
     *
     * @return The building, null if human does not have the place of work.
     */
    Configuration::IBuildingShrPtr getPlaceOfWork(
        IContextShrPtr           const   a_context,
        Configuration::IHumanKey const & a_key
    ) const;
};

/**
 * @brief The arrays of places of work of humans.
 *
 * TODO: Change the name of prefix.
 */
Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_ARCHER_NOVICE_ARRAY          [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_HORSEMAN_NOVICE_ARRAY        [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_INFANTRYMAN_NOVICE_ARRAY     [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_FIRE_NOVICE_ARRAY  [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_EARTH_NOVICE_ARRAY [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_WATER_NOVICE_ARRAY [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_WIND_NOVICE_ARRAY  [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_AGENT_NOVICE_ARRAY               [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_SPY_NOVICE_ARRAY                 [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_THUG_NOVICE_ARRAY                [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_BLACKSMITH_NOVICE_ARRAY       [] = { Building::KEY_REGULAR_FORGE       };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_BREEDER_NOVICE_ARRAY          [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_DRUID_NOVICE_ARRAY            [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_FARMER_NOVICE_ARRAY           [] = { Building::KEY_REGULAR_FARM        };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_FISHERMAN_NOVICE_ARRAY        [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_JOBLESS_NOVICE_ARRAY          [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_LUMBERJACK_NOVICE_ARRAY       [] = { Building::KEY_REGULAR_SAWMILL     };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_MERCHANT_NOVICE_ARRAY         [] = { Building::KEY_REGULAR_MARKETPLACE };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_MINER_NOVICE_ARRAY            [] = { Building::KEY_REGULAR_MINE        };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_OFFICIAL_NOVICE_ARRAY         [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_PRIEST_NOVICE_ARRAY           [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_STEELWORKER_NOVICE_ARRAY      [] = { Building::KEY_REGULAR_STEELWORKS  };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_STONE_MASON_NOVICE_ARRAY      [] = { Building::KEY_REGULAR_QUARRY      };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_TEACHER_NOVICE_ARRAY          [] = { Building::KEY_REGULAR_SCHOOL      };

Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_ARCHER_ADVANCED_ARRAY          [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_HORSEMAN_ADVANCED_ARRAY        [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ADVANCED_ARRAY     [] = { Building::KEY_REGULAR_BARRACKS    };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ADVANCED_ARRAY [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ADVANCED_ARRAY  [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_WATER_ADVANCED_ARRAY [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SORCERER_SORCERER_WIND_ADVANCED_ARRAY  [] = { Building::KEY_REGULAR_GUILD       };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_AGENT_ADVANCED_ARRAY               [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_SPY_ADVANCED_ARRAY                 [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_SPY_THUG_ADVANCED_ARRAY                [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_BLACKSMITH_ADVANCED_ARRAY       [] = { Building::KEY_REGULAR_FORGE       };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_BREEDER_ADVANCED_ARRAY          [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_DRUID_ADVANCED_ARRAY            [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_FARMER_ADVANCED_ARRAY           [] = { Building::KEY_REGULAR_FARM        };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_FISHERMAN_ADVANCED_ARRAY        [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_JOBLESS_ADVANCED_ARRAY          [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_LUMBERJACK_ADVANCED_ARRAY       [] = { Building::KEY_REGULAR_SAWMILL     };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_MERCHANT_ADVANCED_ARRAY         [] = { Building::KEY_REGULAR_MARKETPLACE };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_MINER_ADVANCED_ARRAY            [] = { Building::KEY_REGULAR_MINE        };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_OFFICIAL_ADVANCED_ARRAY         [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_PRIEST_ADVANCED_ARRAY           [] = {                                   };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_STEELWORKER_ADVANCED_ARRAY      [] = { Building::KEY_REGULAR_STEELWORKS  };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_STONE_MASON_ADVANCED_ARRAY      [] = { Building::KEY_REGULAR_QUARRY      };
Configuration::IBuildingKey const PLACES_OF_WORK_WORKER_TEACHER_ADVANCED_ARRAY          [] = { Building::KEY_REGULAR_SCHOOL      };

/**
 * @brief The places of work of humans.
 *
 * TODO: Add typedef.
 * TODO: Instead of + x use sizeof() / sizeof([0]).
 */
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_ARCHER_NOVICE     (PLACES_OF_WORK_SOLDIER_ARCHER_NOVICE_ARRAY         , PLACES_OF_WORK_SOLDIER_ARCHER_NOVICE_ARRAY          + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_HORSEMAN_NOVICE   (PLACES_OF_WORK_SOLDIER_HORSEMAN_NOVICE_ARRAY       , PLACES_OF_WORK_SOLDIER_HORSEMAN_NOVICE_ARRAY        + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_INFANTRYMAN_NOVICE(PLACES_OF_WORK_SOLDIER_INFANTRYMAN_NOVICE_ARRAY    , PLACES_OF_WORK_SOLDIER_INFANTRYMAN_NOVICE_ARRAY     + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_EARTH_NOVICE     (PLACES_OF_WORK_SORCERER_SORCERER_EARTH_NOVICE_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_EARTH_NOVICE_ARRAY + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_FIRE_NOVICE      (PLACES_OF_WORK_SORCERER_SORCERER_FIRE_NOVICE_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_FIRE_NOVICE_ARRAY  + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_WATER_NOVICE     (PLACES_OF_WORK_SORCERER_SORCERER_WATER_NOVICE_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_WATER_NOVICE_ARRAY + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_WIND_NOVICE      (PLACES_OF_WORK_SORCERER_SORCERER_WIND_NOVICE_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_WIND_NOVICE_ARRAY  + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_AGENT_NOVICE          (PLACES_OF_WORK_SPY_AGENT_NOVICE_ARRAY              , PLACES_OF_WORK_SPY_AGENT_NOVICE_ARRAY               + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_SPY_NOVICE            (PLACES_OF_WORK_SPY_SPY_NOVICE_ARRAY                , PLACES_OF_WORK_SPY_SPY_NOVICE_ARRAY                 + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_THUG_NOVICE           (PLACES_OF_WORK_SPY_THUG_NOVICE_ARRAY               , PLACES_OF_WORK_SPY_THUG_NOVICE_ARRAY                + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_BLACKSMITH_NOVICE  (PLACES_OF_WORK_WORKER_BLACKSMITH_NOVICE_ARRAY      , PLACES_OF_WORK_WORKER_BLACKSMITH_NOVICE_ARRAY       + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_BREEDER_NOVICE     (PLACES_OF_WORK_WORKER_BREEDER_NOVICE_ARRAY         , PLACES_OF_WORK_WORKER_BREEDER_NOVICE_ARRAY          + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_DRUID_NOVICE       (PLACES_OF_WORK_WORKER_DRUID_NOVICE_ARRAY           , PLACES_OF_WORK_WORKER_DRUID_NOVICE_ARRAY            + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_FARMER_NOVICE      (PLACES_OF_WORK_WORKER_FARMER_NOVICE_ARRAY          , PLACES_OF_WORK_WORKER_FARMER_NOVICE_ARRAY           + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_FISHERMAN_NOVICE   (PLACES_OF_WORK_WORKER_FISHERMAN_NOVICE_ARRAY       , PLACES_OF_WORK_WORKER_FISHERMAN_NOVICE_ARRAY        + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_JOBLESS_NOVICE     (PLACES_OF_WORK_WORKER_JOBLESS_NOVICE_ARRAY         , PLACES_OF_WORK_WORKER_JOBLESS_NOVICE_ARRAY          + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_LUMBERJACK_NOVICE  (PLACES_OF_WORK_WORKER_LUMBERJACK_NOVICE_ARRAY      , PLACES_OF_WORK_WORKER_LUMBERJACK_NOVICE_ARRAY       + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_MERCHANT_NOVICE    (PLACES_OF_WORK_WORKER_MERCHANT_NOVICE_ARRAY        , PLACES_OF_WORK_WORKER_MERCHANT_NOVICE_ARRAY         + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_MINER_NOVICE       (PLACES_OF_WORK_WORKER_MINER_NOVICE_ARRAY           , PLACES_OF_WORK_WORKER_MINER_NOVICE_ARRAY            + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_OFFICIAL_NOVICE    (PLACES_OF_WORK_WORKER_OFFICIAL_NOVICE_ARRAY        , PLACES_OF_WORK_WORKER_OFFICIAL_NOVICE_ARRAY         + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_PRIEST_NOVICE      (PLACES_OF_WORK_WORKER_PRIEST_NOVICE_ARRAY          , PLACES_OF_WORK_WORKER_PRIEST_NOVICE_ARRAY           + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_STEELWORKER_NOVICE (PLACES_OF_WORK_WORKER_STEELWORKER_NOVICE_ARRAY     , PLACES_OF_WORK_WORKER_STEELWORKER_NOVICE_ARRAY      + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_STONE_MASON_NOVICE (PLACES_OF_WORK_WORKER_STONE_MASON_NOVICE_ARRAY     , PLACES_OF_WORK_WORKER_STONE_MASON_NOVICE_ARRAY      + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_TEACHER_NOVICE     (PLACES_OF_WORK_WORKER_TEACHER_NOVICE_ARRAY         , PLACES_OF_WORK_WORKER_TEACHER_NOVICE_ARRAY          + 1);

const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_ARCHER_ADVANCED     (PLACES_OF_WORK_SOLDIER_ARCHER_ADVANCED_ARRAY         , PLACES_OF_WORK_SOLDIER_ARCHER_ADVANCED_ARRAY          + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_HORSEMAN_ADVANCED   (PLACES_OF_WORK_SOLDIER_HORSEMAN_ADVANCED_ARRAY       , PLACES_OF_WORK_SOLDIER_HORSEMAN_ADVANCED_ARRAY        + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ADVANCED(PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ADVANCED_ARRAY    , PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ADVANCED_ARRAY     + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_EARTH_ADVANCED     (PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ADVANCED_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ADVANCED_ARRAY + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_FIRE_ADVANCED      (PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ADVANCED_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ADVANCED_ARRAY  + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_WATER_ADVANCED     (PLACES_OF_WORK_SORCERER_SORCERER_WATER_ADVANCED_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_WATER_ADVANCED_ARRAY + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SORCERER_WIND_ADVANCED      (PLACES_OF_WORK_SORCERER_SORCERER_WIND_ADVANCED_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_WIND_ADVANCED_ARRAY  + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_AGENT_ADVANCED          (PLACES_OF_WORK_SPY_AGENT_ADVANCED_ARRAY              , PLACES_OF_WORK_SPY_AGENT_ADVANCED_ARRAY               + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_SPY_ADVANCED            (PLACES_OF_WORK_SPY_SPY_ADVANCED_ARRAY                , PLACES_OF_WORK_SPY_SPY_ADVANCED_ARRAY                 + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_SPY_THUG_ADVANCED           (PLACES_OF_WORK_SPY_THUG_ADVANCED_ARRAY               , PLACES_OF_WORK_SPY_THUG_ADVANCED_ARRAY                + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_BLACKSMITH_ADVANCED  (PLACES_OF_WORK_WORKER_BLACKSMITH_ADVANCED_ARRAY      , PLACES_OF_WORK_WORKER_BLACKSMITH_ADVANCED_ARRAY       + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_BREEDER_ADVANCED     (PLACES_OF_WORK_WORKER_BREEDER_ADVANCED_ARRAY         , PLACES_OF_WORK_WORKER_BREEDER_ADVANCED_ARRAY          + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_DRUID_ADVANCED       (PLACES_OF_WORK_WORKER_DRUID_ADVANCED_ARRAY           , PLACES_OF_WORK_WORKER_DRUID_ADVANCED_ARRAY            + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_FARMER_ADVANCED      (PLACES_OF_WORK_WORKER_FARMER_ADVANCED_ARRAY          , PLACES_OF_WORK_WORKER_FARMER_ADVANCED_ARRAY           + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_FISHERMAN_ADVANCED   (PLACES_OF_WORK_WORKER_FISHERMAN_ADVANCED_ARRAY       , PLACES_OF_WORK_WORKER_FISHERMAN_ADVANCED_ARRAY        + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_JOBLESS_ADVANCED     (PLACES_OF_WORK_WORKER_JOBLESS_ADVANCED_ARRAY         , PLACES_OF_WORK_WORKER_JOBLESS_ADVANCED_ARRAY          + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_LUMBERJACK_ADVANCED  (PLACES_OF_WORK_WORKER_LUMBERJACK_ADVANCED_ARRAY      , PLACES_OF_WORK_WORKER_LUMBERJACK_ADVANCED_ARRAY       + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_MERCHANT_ADVANCED    (PLACES_OF_WORK_WORKER_MERCHANT_ADVANCED_ARRAY        , PLACES_OF_WORK_WORKER_MERCHANT_ADVANCED_ARRAY         + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_MINER_ADVANCED       (PLACES_OF_WORK_WORKER_MINER_ADVANCED_ARRAY           , PLACES_OF_WORK_WORKER_MINER_ADVANCED_ARRAY            + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_OFFICIAL_ADVANCED    (PLACES_OF_WORK_WORKER_OFFICIAL_ADVANCED_ARRAY        , PLACES_OF_WORK_WORKER_OFFICIAL_ADVANCED_ARRAY         + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_PRIEST_ADVANCED      (PLACES_OF_WORK_WORKER_PRIEST_ADVANCED_ARRAY          , PLACES_OF_WORK_WORKER_PRIEST_ADVANCED_ARRAY           + 0);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_STEELWORKER_ADVANCED (PLACES_OF_WORK_WORKER_STEELWORKER_ADVANCED_ARRAY     , PLACES_OF_WORK_WORKER_STEELWORKER_ADVANCED_ARRAY      + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_STONE_MASON_ADVANCED (PLACES_OF_WORK_WORKER_STONE_MASON_ADVANCED_ARRAY     , PLACES_OF_WORK_WORKER_STONE_MASON_ADVANCED_ARRAY      + 1);
const std::vector<Configuration::IBuildingKey> PLACES_OF_WORK_WORKER_TEACHER_ADVANCED     (PLACES_OF_WORK_WORKER_TEACHER_ADVANCED_ARRAY         , PLACES_OF_WORK_WORKER_TEACHER_ADVANCED_ARRAY          + 1);

/**
 * @brief An identifier of a human and a vector of building keys pair.
 */
typedef std::pair<Configuration::IHumanKey, std::vector<Configuration::IBuildingKey> > PlaceOfWork;

const PlaceOfWork POW_SOLDIER_ARCHER_NOVICE     (KEY_SOLDIER_ARCHER_NOVICE     , PLACES_OF_WORK_SOLDIER_ARCHER_NOVICE     );
const PlaceOfWork POW_SOLDIER_HORSEMAN_NOVICE   (KEY_SOLDIER_HORSEMAN_NOVICE   , PLACES_OF_WORK_SOLDIER_HORSEMAN_NOVICE   );
const PlaceOfWork POW_SOLDIER_INFANTRYMAN_NOVICE(KEY_SOLDIER_INFANTRYMAN_NOVICE, PLACES_OF_WORK_SOLDIER_INFANTRYMAN_NOVICE);
const PlaceOfWork POW_SORCERER_EARTH_NOVICE     (KEY_SORCERER_EARTH_NOVICE     , PLACES_OF_WORK_SORCERER_EARTH_NOVICE     );
const PlaceOfWork POW_SORCERER_FIRE_NOVICE      (KEY_SORCERER_FIRE_NOVICE      , PLACES_OF_WORK_SORCERER_FIRE_NOVICE      );
const PlaceOfWork POW_SORCERER_WATER_NOVICE     (KEY_SORCERER_WATER_NOVICE     , PLACES_OF_WORK_SORCERER_WATER_NOVICE     );
const PlaceOfWork POW_SORCERER_WIND_NOVICE      (KEY_SORCERER_WIND_NOVICE      , PLACES_OF_WORK_SORCERER_WIND_NOVICE      );
const PlaceOfWork POW_SPY_AGENT_NOVICE          (KEY_SPY_AGENT_NOVICE          , PLACES_OF_WORK_SPY_AGENT_NOVICE          );
const PlaceOfWork POW_SPY_SPY_NOVICE            (KEY_SPY_SPY_NOVICE            , PLACES_OF_WORK_SPY_SPY_NOVICE            );
const PlaceOfWork POW_SPY_THUG_NOVICE           (KEY_SPY_THUG_NOVICE           , PLACES_OF_WORK_SPY_THUG_NOVICE           );
const PlaceOfWork POW_WORKER_BLACKSMITH_NOVICE  (KEY_WORKER_BLACKSMITH_NOVICE  , PLACES_OF_WORK_WORKER_BLACKSMITH_NOVICE  );
const PlaceOfWork POW_WORKER_BREEDER_NOVICE     (KEY_WORKER_BREEDER_NOVICE     , PLACES_OF_WORK_WORKER_BREEDER_NOVICE     );
const PlaceOfWork POW_WORKER_DRUID_NOVICE       (KEY_WORKER_DRUID_NOVICE       , PLACES_OF_WORK_WORKER_DRUID_NOVICE       );
const PlaceOfWork POW_WORKER_FARMER_NOVICE      (KEY_WORKER_FARMER_NOVICE      , PLACES_OF_WORK_WORKER_FARMER_NOVICE      );
const PlaceOfWork POW_WORKER_FISHERMAN_NOVICE   (KEY_WORKER_FISHERMAN_NOVICE   , PLACES_OF_WORK_WORKER_FISHERMAN_NOVICE   );
const PlaceOfWork POW_WORKER_JOBLESS_NOVICE     (KEY_WORKER_JOBLESS_NOVICE     , PLACES_OF_WORK_WORKER_JOBLESS_NOVICE     );
const PlaceOfWork POW_WORKER_LUMBERJACK_NOVICE  (KEY_WORKER_LUMBERJACK_NOVICE  , PLACES_OF_WORK_WORKER_LUMBERJACK_NOVICE  );
const PlaceOfWork POW_WORKER_MERCHANT_NOVICE    (KEY_WORKER_MERCHANT_NOVICE    , PLACES_OF_WORK_WORKER_MERCHANT_NOVICE    );
const PlaceOfWork POW_WORKER_MINER_NOVICE       (KEY_WORKER_MINER_NOVICE       , PLACES_OF_WORK_WORKER_MINER_NOVICE       );
const PlaceOfWork POW_WORKER_OFFICIAL_NOVICE    (KEY_WORKER_OFFICIAL_NOVICE    , PLACES_OF_WORK_WORKER_OFFICIAL_NOVICE    );
const PlaceOfWork POW_WORKER_PRIEST_NOVICE      (KEY_WORKER_PRIEST_NOVICE      , PLACES_OF_WORK_WORKER_PRIEST_NOVICE      );
const PlaceOfWork POW_WORKER_STEELWORKER_NOVICE (KEY_WORKER_STEELWORKER_NOVICE , PLACES_OF_WORK_WORKER_STEELWORKER_NOVICE );
const PlaceOfWork POW_WORKER_STONE_MASON_NOVICE (KEY_WORKER_STONE_MASON_NOVICE , PLACES_OF_WORK_WORKER_STONE_MASON_NOVICE );
const PlaceOfWork POW_WORKER_TEACHER_NOVICE     (KEY_WORKER_TEACHER_NOVICE     , PLACES_OF_WORK_WORKER_TEACHER_NOVICE     );

const PlaceOfWork POW_SOLDIER_ARCHER_ADVANCED     (KEY_SOLDIER_ARCHER_ADVANCED     , PLACES_OF_WORK_SOLDIER_ARCHER_ADVANCED     );
const PlaceOfWork POW_SOLDIER_HORSEMAN_ADVANCED   (KEY_SOLDIER_HORSEMAN_ADVANCED   , PLACES_OF_WORK_SOLDIER_HORSEMAN_ADVANCED   );
const PlaceOfWork POW_SOLDIER_INFANTRYMAN_ADVANCED(KEY_SOLDIER_INFANTRYMAN_ADVANCED, PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ADVANCED);
const PlaceOfWork POW_SORCERER_EARTH_ADVANCED     (KEY_SORCERER_EARTH_ADVANCED     , PLACES_OF_WORK_SORCERER_EARTH_ADVANCED     );
const PlaceOfWork POW_SORCERER_FIRE_ADVANCED      (KEY_SORCERER_FIRE_ADVANCED      , PLACES_OF_WORK_SORCERER_FIRE_ADVANCED      );
const PlaceOfWork POW_SORCERER_WATER_ADVANCED     (KEY_SORCERER_WATER_ADVANCED     , PLACES_OF_WORK_SORCERER_WATER_ADVANCED     );
const PlaceOfWork POW_SORCERER_WIND_ADVANCED      (KEY_SORCERER_WIND_ADVANCED      , PLACES_OF_WORK_SORCERER_WIND_ADVANCED      );
const PlaceOfWork POW_SPY_AGENT_ADVANCED          (KEY_SPY_AGENT_ADVANCED          , PLACES_OF_WORK_SPY_AGENT_ADVANCED          );
const PlaceOfWork POW_SPY_SPY_ADVANCED            (KEY_SPY_SPY_ADVANCED            , PLACES_OF_WORK_SPY_SPY_ADVANCED            );
const PlaceOfWork POW_SPY_THUG_ADVANCED           (KEY_SPY_THUG_ADVANCED           , PLACES_OF_WORK_SPY_THUG_ADVANCED           );
const PlaceOfWork POW_WORKER_BLACKSMITH_ADVANCED  (KEY_WORKER_BLACKSMITH_ADVANCED  , PLACES_OF_WORK_WORKER_BLACKSMITH_ADVANCED  );
const PlaceOfWork POW_WORKER_BREEDER_ADVANCED     (KEY_WORKER_BREEDER_ADVANCED     , PLACES_OF_WORK_WORKER_BREEDER_ADVANCED     );
const PlaceOfWork POW_WORKER_DRUID_ADVANCED       (KEY_WORKER_DRUID_ADVANCED       , PLACES_OF_WORK_WORKER_DRUID_ADVANCED       );
const PlaceOfWork POW_WORKER_FARMER_ADVANCED      (KEY_WORKER_FARMER_ADVANCED      , PLACES_OF_WORK_WORKER_FARMER_ADVANCED      );
const PlaceOfWork POW_WORKER_FISHERMAN_ADVANCED   (KEY_WORKER_FISHERMAN_ADVANCED   , PLACES_OF_WORK_WORKER_FISHERMAN_ADVANCED   );
const PlaceOfWork POW_WORKER_JOBLESS_ADVANCED     (KEY_WORKER_JOBLESS_ADVANCED     , PLACES_OF_WORK_WORKER_JOBLESS_ADVANCED     );
const PlaceOfWork POW_WORKER_LUMBERJACK_ADVANCED  (KEY_WORKER_LUMBERJACK_ADVANCED  , PLACES_OF_WORK_WORKER_LUMBERJACK_ADVANCED  );
const PlaceOfWork POW_WORKER_MERCHANT_ADVANCED    (KEY_WORKER_MERCHANT_ADVANCED    , PLACES_OF_WORK_WORKER_MERCHANT_ADVANCED    );
const PlaceOfWork POW_WORKER_MINER_ADVANCED       (KEY_WORKER_MINER_ADVANCED       , PLACES_OF_WORK_WORKER_MINER_ADVANCED       );
const PlaceOfWork POW_WORKER_OFFICIAL_ADVANCED    (KEY_WORKER_OFFICIAL_ADVANCED    , PLACES_OF_WORK_WORKER_OFFICIAL_ADVANCED    );
const PlaceOfWork POW_WORKER_PRIEST_ADVANCED      (KEY_WORKER_PRIEST_ADVANCED      , PLACES_OF_WORK_WORKER_PRIEST_ADVANCED      );
const PlaceOfWork POW_WORKER_STEELWORKER_ADVANCED (KEY_WORKER_STEELWORKER_ADVANCED , PLACES_OF_WORK_WORKER_STEELWORKER_ADVANCED );
const PlaceOfWork POW_WORKER_STONE_MASON_ADVANCED (KEY_WORKER_STONE_MASON_ADVANCED , PLACES_OF_WORK_WORKER_STONE_MASON_ADVANCED );
const PlaceOfWork POW_WORKER_TEACHER_ADVANCED     (KEY_WORKER_TEACHER_ADVANCED     , PLACES_OF_WORK_WORKER_TEACHER_ADVANCED     );

/**
 * @brief A map of places of work of humans.
 */
const PlaceOfWork PLACES_OF_WORK_ARRAY [] = {
        POW_SOLDIER_ARCHER_NOVICE,
        POW_SOLDIER_HORSEMAN_NOVICE,
        POW_SOLDIER_INFANTRYMAN_NOVICE,
        POW_SORCERER_EARTH_NOVICE,
        POW_SORCERER_FIRE_NOVICE,
        POW_SORCERER_WATER_NOVICE,
        POW_SORCERER_WIND_NOVICE,
        POW_SPY_AGENT_NOVICE,
        POW_SPY_SPY_NOVICE,
        POW_SPY_THUG_NOVICE,
        POW_WORKER_BLACKSMITH_NOVICE,
        POW_WORKER_BREEDER_NOVICE,
        POW_WORKER_DRUID_NOVICE,
        POW_WORKER_FARMER_NOVICE,
        POW_WORKER_FISHERMAN_NOVICE,
        POW_WORKER_JOBLESS_NOVICE,
        POW_WORKER_LUMBERJACK_NOVICE,
        POW_WORKER_MERCHANT_NOVICE,
        POW_WORKER_MINER_NOVICE,
        POW_WORKER_OFFICIAL_NOVICE,
        POW_WORKER_PRIEST_NOVICE,
        POW_WORKER_STEELWORKER_NOVICE,
        POW_WORKER_STONE_MASON_NOVICE,
        POW_WORKER_TEACHER_NOVICE,

        POW_SOLDIER_ARCHER_ADVANCED,
        POW_SOLDIER_HORSEMAN_ADVANCED,
        POW_SOLDIER_INFANTRYMAN_ADVANCED,
        POW_SORCERER_EARTH_ADVANCED,
        POW_SORCERER_FIRE_ADVANCED,
        POW_SORCERER_WATER_ADVANCED,
        POW_SORCERER_WIND_ADVANCED,
        POW_SPY_AGENT_ADVANCED,
        POW_SPY_SPY_ADVANCED,
        POW_SPY_THUG_ADVANCED,
        POW_WORKER_BLACKSMITH_ADVANCED,
        POW_WORKER_BREEDER_ADVANCED,
        POW_WORKER_DRUID_ADVANCED,
        POW_WORKER_FARMER_ADVANCED,
        POW_WORKER_FISHERMAN_ADVANCED,
        POW_WORKER_JOBLESS_ADVANCED,
        POW_WORKER_LUMBERJACK_ADVANCED,
        POW_WORKER_MERCHANT_ADVANCED,
        POW_WORKER_MINER_ADVANCED,
        POW_WORKER_OFFICIAL_ADVANCED,
        POW_WORKER_PRIEST_ADVANCED,
        POW_WORKER_STEELWORKER_ADVANCED,
        POW_WORKER_STONE_MASON_ADVANCED,
        POW_WORKER_TEACHER_ADVANCED
};

const std::map<Configuration::IHumanKey, std::vector<Configuration::IBuildingKey> > PLACES_OF_WORK(
    PLACES_OF_WORK_ARRAY,
    PLACES_OF_WORK_ARRAY + sizeof(PLACES_OF_WORK_ARRAY) / sizeof(PLACES_OF_WORK_ARRAY[0])
);

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANTOBUILDINGTRANSLATOR_HPP
