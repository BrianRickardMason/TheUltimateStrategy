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

#include <GameServer/Human/HumanToBuildingTranslator.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Building;
using namespace GameServer::Configuration;
using namespace GameServer::Human;

/**
 * @brief The test class of HumanToBuildingTranslator.
 */
class HumanToBuildingTranslatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Ctor.
     */
    HumanToBuildingTranslatorTest()
        : m_context(new Context)
    {
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief Test constants: the translator used in tests.
     */
    HumanToBuildingTranslator m_translator;
};

TEST_F(HumanToBuildingTranslatorTest, GetPlaceOfWorkReturnsProperValues)
{
    IBuildingShrPtr building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_ARCHER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_ARCHER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_HORSEMAN_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_HORSEMAN_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_INFANTRYMAN_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SOLDIER_INFANTRYMAN_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_BARRACKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_EARTH_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_EARTH_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_FIRE_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_FIRE_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_WATER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_WATER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_WIND_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SORCERER_WIND_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_GUILD == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_AGENT_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_AGENT_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_SPY_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_SPY_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_THUG_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_SPY_THUG_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_BLACKSMITH_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_FORGE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_BLACKSMITH_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_FORGE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_BREEDER_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_BREEDER_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_DRUID_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_DRUID_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_FARMER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_FARM == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_FARMER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_FARM == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_FISHERMAN_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_FISHERMAN_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_JOBLESS_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_JOBLESS_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_LUMBERJACK_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_SAWMILL == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_LUMBERJACK_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_SAWMILL == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_MERCHANT_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_MARKETPLACE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_MERCHANT_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_MARKETPLACE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_MINER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_MINE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_MINER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_MINE == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_OFFICIAL_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_OFFICIAL_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_PRIEST_ADVANCED);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_PRIEST_NOVICE);
    ASSERT_FALSE(building);

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_STEELWORKER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_STEELWORKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_STEELWORKER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_STEELWORKS == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_STONE_MASON_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_QUARRY == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_STONE_MASON_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_QUARRY == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_TEACHER_ADVANCED);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_SCHOOL == building->getKey());

    building = m_translator.getPlaceOfWork(m_context, KEY_WORKER_TEACHER_NOVICE);
    ASSERT_TRUE(building);
    ASSERT_TRUE(KEY_REGULAR_SCHOOL == building->getKey());
}
