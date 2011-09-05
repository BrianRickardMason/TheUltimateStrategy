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

#include "../Building/Building.hpp"
#include "Key.hpp"
#include <map>
#include <vector>

namespace GameServer
{
namespace Human
{

/**
 * @brief A "human to building" translator.
 *
 * TODO: Move configuration to xml after successful proof of concept on HumanOperator::engageHuman().
 */
class HumanToBuildingTranslator
{
public:
    /**
     * @brief Gets a building which is a place of work of a given human.
     *
     * @param a_key A key of the human.
     *
     * @return The building, null if human does not have the place of work.
     */
    Building::BuildingShrPtr getPlaceOfWork(
        Key const & a_key
    ) const;

    /**
     * @brief Gets a building which is a place of work of a given human.
     *
     * @param a_id_human An identifier of the human.
     *
     * @return The building, null if human does not have the place of work.
     */
    Building::BuildingShrPtr getPlaceOfWork(
        IDHuman const & a_id_human
    ) const;

    /**
     * @brief Gets a building which is a place of work of a given human.
     *
     * @param a_key A key hash of the human.
     *
     * @return The building, null if human does not have the place of work.
     */
    Building::BuildingShrPtr getPlaceOfWork(
        Common::KeyHash const & a_key_hash
    ) const;

private:
    /**
     * @brief Gets a building which is a place of work of a given human.
     *
     * @param a_id_human An identifier of the human.
     *
     * @return The building, null if human does not have the place of work.
     */
    Building::BuildingShrPtr doGetPlaceOfWork(
        IDHuman const & a_id_human
    ) const;
};

/**
 * @brief The arrays of places of work of humans.
 *
 * TODO: Change the name of prefix.
 */
const Building::Key PLACES_OF_WORK_SOLDIER_ARCHER_ARRAY            [] = { Building::KEY_REGULAR_BARRACKS    };
const Building::Key PLACES_OF_WORK_SOLDIER_HORSEMAN_ARRAY          [] = { Building::KEY_REGULAR_BARRACKS    };
const Building::Key PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ARRAY       [] = { Building::KEY_REGULAR_BARRACKS    };
const Building::Key PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ARRAY   [] = { Building::KEY_REGULAR_GUILD       };
const Building::Key PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ARRAY    [] = { Building::KEY_REGULAR_GUILD       };
const Building::Key PLACES_OF_WORK_SORCERER_SORCERER_WATER_ARRAY   [] = { Building::KEY_REGULAR_GUILD       };
const Building::Key PLACES_OF_WORK_SORCERER_SORCERER_WIND_ARRAY    [] = { Building::KEY_REGULAR_GUILD       };
const Building::Key PLACES_OF_WORK_SPY_AGENT_ARRAY                 [] = {                                   };
const Building::Key PLACES_OF_WORK_SPY_SPY_ARRAY                   [] = {                                   };
const Building::Key PLACES_OF_WORK_SPY_THUG_ARRAY                  [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_BLACKSMITH_ARRAY         [] = { Building::KEY_REGULAR_FORGE       };
const Building::Key PLACES_OF_WORK_WORKER_BREEDER_ARRAY            [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_DRUID_ARRAY              [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_FARMER_ARRAY             [] = { Building::KEY_REGULAR_FARM        };
const Building::Key PLACES_OF_WORK_WORKER_FISHERMAN_ARRAY          [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_JOBLESS_ARRAY            [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_LUMBERJACK_ARRAY         [] = { Building::KEY_REGULAR_SAWMILL     };
const Building::Key PLACES_OF_WORK_WORKER_MERCHANT_ARRAY           [] = { Building::KEY_REGULAR_MARKETPLACE };
const Building::Key PLACES_OF_WORK_WORKER_MINER_ARRAY              [] = { Building::KEY_REGULAR_MINE        };
const Building::Key PLACES_OF_WORK_WORKER_OFFICIAL_ARRAY           [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_PRIEST_ARRAY             [] = {                                   };
const Building::Key PLACES_OF_WORK_WORKER_STEELWORKER_ARRAY        [] = { Building::KEY_REGULAR_STEELWORKS  };
const Building::Key PLACES_OF_WORK_WORKER_STONE_MASON_ARRAY        [] = { Building::KEY_REGULAR_QUARRY      };
const Building::Key PLACES_OF_WORK_WORKER_TEACHER_ARRAY            [] = { Building::KEY_REGULAR_SCHOOL      };

/**
 * @brief The places of work of humans.
 *
 * TODO: Add typedef.
 * TODO: Instead of + x use sizeof() / sizeof([0]).
 */
const std::vector<Building::Key> PLACES_OF_WORK_SOLDIER_ARCHER     (PLACES_OF_WORK_SOLDIER_ARCHER_ARRAY         , PLACES_OF_WORK_SOLDIER_ARCHER_ARRAY          + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SOLDIER_HORSEMAN   (PLACES_OF_WORK_SOLDIER_HORSEMAN_ARRAY       , PLACES_OF_WORK_SOLDIER_HORSEMAN_ARRAY        + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SOLDIER_INFANTRYMAN(PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ARRAY    , PLACES_OF_WORK_SOLDIER_INFANTRYMAN_ARRAY     + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SORCERER_EARTH     (PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_EARTH_ARRAY + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SORCERER_FIRE      (PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_FIRE_ARRAY  + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SORCERER_WATER     (PLACES_OF_WORK_SORCERER_SORCERER_WATER_ARRAY, PLACES_OF_WORK_SORCERER_SORCERER_WATER_ARRAY + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SORCERER_WIND      (PLACES_OF_WORK_SORCERER_SORCERER_WIND_ARRAY , PLACES_OF_WORK_SORCERER_SORCERER_WIND_ARRAY  + 1);
const std::vector<Building::Key> PLACES_OF_WORK_SPY_AGENT          (PLACES_OF_WORK_SPY_AGENT_ARRAY              , PLACES_OF_WORK_SPY_AGENT_ARRAY               + 0);
const std::vector<Building::Key> PLACES_OF_WORK_SPY_SPY            (PLACES_OF_WORK_SPY_SPY_ARRAY                , PLACES_OF_WORK_SPY_SPY_ARRAY                 + 0);
const std::vector<Building::Key> PLACES_OF_WORK_SPY_THUG           (PLACES_OF_WORK_SPY_THUG_ARRAY               , PLACES_OF_WORK_SPY_THUG_ARRAY                + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_BLACKSMITH  (PLACES_OF_WORK_WORKER_BLACKSMITH_ARRAY      , PLACES_OF_WORK_WORKER_BLACKSMITH_ARRAY       + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_BREEDER     (PLACES_OF_WORK_WORKER_BREEDER_ARRAY         , PLACES_OF_WORK_WORKER_BREEDER_ARRAY          + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_DRUID       (PLACES_OF_WORK_WORKER_DRUID_ARRAY           , PLACES_OF_WORK_WORKER_DRUID_ARRAY            + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_FARMER      (PLACES_OF_WORK_WORKER_FARMER_ARRAY          , PLACES_OF_WORK_WORKER_FARMER_ARRAY           + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_FISHERMAN   (PLACES_OF_WORK_WORKER_FISHERMAN_ARRAY       , PLACES_OF_WORK_WORKER_FISHERMAN_ARRAY        + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_JOBLESS     (PLACES_OF_WORK_WORKER_JOBLESS_ARRAY         , PLACES_OF_WORK_WORKER_JOBLESS_ARRAY          + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_LUMBERJACK  (PLACES_OF_WORK_WORKER_LUMBERJACK_ARRAY      , PLACES_OF_WORK_WORKER_LUMBERJACK_ARRAY       + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_MERCHANT    (PLACES_OF_WORK_WORKER_MERCHANT_ARRAY        , PLACES_OF_WORK_WORKER_MERCHANT_ARRAY         + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_MINER       (PLACES_OF_WORK_WORKER_MINER_ARRAY           , PLACES_OF_WORK_WORKER_MINER_ARRAY            + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_OFFICIAL    (PLACES_OF_WORK_WORKER_OFFICIAL_ARRAY        , PLACES_OF_WORK_WORKER_OFFICIAL_ARRAY         + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_PRIEST      (PLACES_OF_WORK_WORKER_PRIEST_ARRAY          , PLACES_OF_WORK_WORKER_PRIEST_ARRAY           + 0);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_STEELWORKER (PLACES_OF_WORK_WORKER_STEELWORKER_ARRAY     , PLACES_OF_WORK_WORKER_STEELWORKER_ARRAY      + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_STONE_MASON (PLACES_OF_WORK_WORKER_STONE_MASON_ARRAY     , PLACES_OF_WORK_WORKER_STONE_MASON_ARRAY      + 1);
const std::vector<Building::Key> PLACES_OF_WORK_WORKER_TEACHER     (PLACES_OF_WORK_WORKER_TEACHER_ARRAY         , PLACES_OF_WORK_WORKER_TEACHER_ARRAY          + 1);

/**
 * @brief An identifier of a human and a vector of building keys pair.
 */
typedef std::pair<IDHuman, std::vector<Building::Key> > PlaceOfWork;

const PlaceOfWork POW_SOLDIER_ARCHER     (ID_HUMAN_SOLDIER_ARCHER     , PLACES_OF_WORK_SOLDIER_ARCHER     );
const PlaceOfWork POW_SOLDIER_HORSEMAN   (ID_HUMAN_SOLDIER_HORSEMAN   , PLACES_OF_WORK_SOLDIER_HORSEMAN   );
const PlaceOfWork POW_SOLDIER_INFANTRYMAN(ID_HUMAN_SOLDIER_INFANTRYMAN, PLACES_OF_WORK_SOLDIER_INFANTRYMAN);
const PlaceOfWork POW_SORCERER_EARTH     (ID_HUMAN_SORCERER_EARTH     , PLACES_OF_WORK_SORCERER_EARTH     );
const PlaceOfWork POW_SORCERER_FIRE      (ID_HUMAN_SORCERER_FIRE      , PLACES_OF_WORK_SORCERER_FIRE      );
const PlaceOfWork POW_SORCERER_WATER     (ID_HUMAN_SORCERER_WATER     , PLACES_OF_WORK_SORCERER_WATER     );
const PlaceOfWork POW_SORCERER_WIND      (ID_HUMAN_SORCERER_WIND      , PLACES_OF_WORK_SORCERER_WIND      );
const PlaceOfWork POW_SPY_AGENT          (ID_HUMAN_SPY_AGENT          , PLACES_OF_WORK_SPY_AGENT          );
const PlaceOfWork POW_SPY_SPY            (ID_HUMAN_SPY_SPY            , PLACES_OF_WORK_SPY_SPY            );
const PlaceOfWork POW_SPY_THUG           (ID_HUMAN_SPY_THUG           , PLACES_OF_WORK_SPY_THUG           );
const PlaceOfWork POW_WORKER_BLACKSMITH  (ID_HUMAN_WORKER_BLACKSMITH  , PLACES_OF_WORK_WORKER_BLACKSMITH  );
const PlaceOfWork POW_WORKER_BREEDER     (ID_HUMAN_WORKER_BREEDER     , PLACES_OF_WORK_WORKER_BREEDER     );
const PlaceOfWork POW_WORKER_DRUID       (ID_HUMAN_WORKER_DRUID       , PLACES_OF_WORK_WORKER_DRUID       );
const PlaceOfWork POW_WORKER_FARMER      (ID_HUMAN_WORKER_FARMER      , PLACES_OF_WORK_WORKER_FARMER      );
const PlaceOfWork POW_WORKER_FISHERMAN   (ID_HUMAN_WORKER_FISHERMAN   , PLACES_OF_WORK_WORKER_FISHERMAN   );
const PlaceOfWork POW_WORKER_JOBLESS     (ID_HUMAN_WORKER_JOBLESS     , PLACES_OF_WORK_WORKER_JOBLESS     );
const PlaceOfWork POW_WORKER_LUMBERJACK  (ID_HUMAN_WORKER_LUMBERJACK  , PLACES_OF_WORK_WORKER_LUMBERJACK  );
const PlaceOfWork POW_WORKER_MERCHANT    (ID_HUMAN_WORKER_MERCHANT    , PLACES_OF_WORK_WORKER_MERCHANT    );
const PlaceOfWork POW_WORKER_MINER       (ID_HUMAN_WORKER_MINER       , PLACES_OF_WORK_WORKER_MINER       );
const PlaceOfWork POW_WORKER_OFFICIAL    (ID_HUMAN_WORKER_OFFICIAL    , PLACES_OF_WORK_WORKER_OFFICIAL    );
const PlaceOfWork POW_WORKER_PRIEST      (ID_HUMAN_WORKER_PRIEST      , PLACES_OF_WORK_WORKER_PRIEST      );
const PlaceOfWork POW_WORKER_STEELWORKER (ID_HUMAN_WORKER_STEELWORKER , PLACES_OF_WORK_WORKER_STEELWORKER );
const PlaceOfWork POW_WORKER_STONE_MASON (ID_HUMAN_WORKER_STONE_MASON , PLACES_OF_WORK_WORKER_STONE_MASON );
const PlaceOfWork POW_WORKER_TEACHER     (ID_HUMAN_WORKER_TEACHER     , PLACES_OF_WORK_WORKER_TEACHER     );

/**
 * @brief A map of places of work of humans.
 */
const PlaceOfWork PLACES_OF_WORK_ARRAY [] = {
    POW_SOLDIER_ARCHER,
    POW_SOLDIER_HORSEMAN,
    POW_SOLDIER_INFANTRYMAN,
    POW_SORCERER_EARTH,
    POW_SORCERER_FIRE,
    POW_SORCERER_WATER,
    POW_SORCERER_WIND,
    POW_SPY_AGENT,
    POW_SPY_SPY,
    POW_SPY_THUG,
    POW_WORKER_BLACKSMITH,
    POW_WORKER_BREEDER,
    POW_WORKER_DRUID,
    POW_WORKER_FARMER,
    POW_WORKER_FISHERMAN,
    POW_WORKER_JOBLESS,
    POW_WORKER_LUMBERJACK,
    POW_WORKER_MERCHANT,
    POW_WORKER_MINER,
    POW_WORKER_OFFICIAL,
    POW_WORKER_PRIEST,
    POW_WORKER_STEELWORKER,
    POW_WORKER_STONE_MASON,
    POW_WORKER_TEACHER
};

const std::map<IDHuman, std::vector<Building::Key> > PLACES_OF_WORK(
    PLACES_OF_WORK_ARRAY,
    PLACES_OF_WORK_ARRAY + sizeof(PLACES_OF_WORK_ARRAY) / sizeof(PLACES_OF_WORK_ARRAY[0])
);

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_HUMANTOBUILDINGTRANSLATOR_HPP
