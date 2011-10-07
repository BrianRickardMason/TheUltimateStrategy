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

#include "../../GameServer/Human/HumanToBuildingTranslator.hpp"
#include "../../GameServer/Human/Human.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Building;
using namespace GameServer::Human;

/**
 * @brief A test class.
 *
 * TODO: Building operator== could be useful.
 * TODO: Refactoring needed. Buildings can be collected to a vector and then compared (one implementation of comparison).
 */
class HumanToBuildingTranslatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    HumanToBuildingTranslatorTest()
    {
    }

    /**
     * @brief A translator to be tested.
     */
    HumanToBuildingTranslator m_translator;
};

/**
 * Unit tests of: HumanToBuildingTranslator::getPlaceOfWork based on key.
 */
TEST_F(HumanToBuildingTranslatorTest, getPlaceOfWork_BasedOnKey)
{
    // Test commands and assertions.
    BuildingShrPtr building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_ADVANCED.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_NOVICE.getKey());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_ADVANCED.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_NOVICE.getKey());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());
}

/**
 * Unit tests of: HumanToBuildingTranslator::getPlaceOfWork based on identifiers.
 */
TEST_F(HumanToBuildingTranslatorTest, getPlaceOfWork_BasedOnIdentifiers)
{
    // Test commands and assertions.
    BuildingShrPtr building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_ADVANCED.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_NOVICE.getIDHuman());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_ADVANCED.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_NOVICE.getIDHuman());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());
}

/**
 * Unit tests of: HumanToBuildingTranslator::getPlaceOfWork based on key hash.
 */
TEST_F(HumanToBuildingTranslatorTest, getPlaceOfWork_BasedOnKeyHash)
{
    // Test commands and assertions.
    BuildingShrPtr building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_ARCHER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_HORSEMAN_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SOLDIER_INFANTRYMAN_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_BARRACKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_EARTH_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_FIRE_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WATER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SORCERER_WIND_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_GUILD == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_AGENT_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_SPY_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_SPY_THUG_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BLACKSMITH_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FORGE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_BREEDER_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_DRUID_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FARMER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_FARM == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_FISHERMAN_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_JOBLESS_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_LUMBERJACK_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SAWMILL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MERCHANT_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MARKETPLACE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_MINER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_MINE == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_OFFICIAL_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_ADVANCED.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_PRIEST_NOVICE.getKey().toHash());
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STEELWORKER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_STEELWORKS == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_STONE_MASON_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_QUARRY == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_ADVANCED.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());

    building = m_translator.getPlaceOfWork(HUMAN_WORKER_TEACHER_NOVICE.getKey().toHash());
    ASSERT_TRUE(building);
    ASSERT_TRUE(ID_BUILDING_REGULAR_SCHOOL == building->getIDBuilding());
}
