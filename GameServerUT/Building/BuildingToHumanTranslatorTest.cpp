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

#include "../../GameServer/Building/BuildingToHumanTranslator.hpp"
#include "../../GameServer/Human/Key.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Building;
using namespace GameServer::Human;

/**
 * Unit tests of: BuildingToHumanTranslator::getHumansHostedForWork.
 */
TEST(BuildingToHumanTranslatorTest, getHumansHostedForWork)
{
    // Test commands and assertions.
    IDHumanVec humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_BARBICAN);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_BATTLEMENTS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_CASEMATE);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_CIRCUMVALLATION);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_DONJON);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_MACHICOLATION);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_PORTCULLIS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_POSTERN);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_DEFENSIVE_VIEWING_TOWER);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_ALTAR_OF_WISHES);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_COMMUNICATION_TOWERS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_ETERNAL_CALENDAR);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_HUNTER_OF_METEORS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_HUNTER_OF_RAINS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_HUNTER_OF_STORMS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_HUNTER_OF_WINDS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_NECROPOLIS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_ORACLE);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_PORTAL_OF_ELEMENTS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_PSIONIC_ACADEMY);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_GOLD_TOWER_OF_CHAOS);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_BARRACKS);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_BARRACKS_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_FARM);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_FARM_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_FORGE);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_FORGE_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_GUILD);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_GUILD_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_HOUSE);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_MARKETPLACE);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_MARKETPLACE_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_MINE);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_MINE_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_QUARRY);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_QUARRY_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_SAWMILL);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_SAWMILL_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_SCHOOL);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_SCHOOL_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_STEELWORKS);
    ASSERT_FALSE(humans.empty());
    ASSERT_TRUE(REGULAR_STEELWORKS_HOSTING_VEC == humans);

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_REGULAR_TEMPLE);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_AQUEDUCT);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_BAWDY_HOUSE);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_COMMERCIAL_PORT);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_COURT);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_GRANARY);
    ASSERT_TRUE(humans.empty());

    humans = BuildingToHumanTranslator::getHumansHostedForWork(KEY_SPECIAL_SEWERAGE);
    ASSERT_TRUE(humans.empty());
}
