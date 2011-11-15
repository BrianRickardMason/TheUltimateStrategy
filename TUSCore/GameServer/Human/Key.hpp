// Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met;
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

#include <GameServer/Configuration/Configurator/Human/IHuman.hpp>
#include <vector>

namespace GameServer
{
namespace Human
{

//@{
/**
 * @brief The available key.
 */
Configuration::IHumanKey const KEY_SOLDIER_ARCHER_NOVICE       ("soldierarchernovice");
Configuration::IHumanKey const KEY_SOLDIER_ARCHER_ADVANCED     ("soldierarcheradvanced");
Configuration::IHumanKey const KEY_SOLDIER_HORSEMAN_NOVICE     ("soldierhorsemannovice");
Configuration::IHumanKey const KEY_SOLDIER_HORSEMAN_ADVANCED   ("soldierhorsemanadvanced");
Configuration::IHumanKey const KEY_SOLDIER_INFANTRYMAN_NOVICE  ("soldierinfantrymannovice");
Configuration::IHumanKey const KEY_SOLDIER_INFANTRYMAN_ADVANCED("soldierinfantrymanadvanced");

Configuration::IHumanKey const KEY_SORCERER_EARTH_NOVICE       ("sorcerersorcererearthnovice");
Configuration::IHumanKey const KEY_SORCERER_EARTH_ADVANCED     ("sorcerersorcererearthadvanced");
Configuration::IHumanKey const KEY_SORCERER_FIRE_NOVICE        ("sorcerersorcererfirenovice");
Configuration::IHumanKey const KEY_SORCERER_FIRE_ADVANCED      ("sorcerersorcererfireadvanced");
Configuration::IHumanKey const KEY_SORCERER_WATER_NOVICE       ("sorcerersorcererwaternovice");
Configuration::IHumanKey const KEY_SORCERER_WATER_ADVANCED     ("sorcerersorcererwateradvanced");
Configuration::IHumanKey const KEY_SORCERER_WIND_NOVICE        ("sorcerersorcererwindnovice");
Configuration::IHumanKey const KEY_SORCERER_WIND_ADVANCED      ("sorcerersorcererwindadvanced");

Configuration::IHumanKey const KEY_SPY_AGENT_NOVICE            ("spyagentnovice");
Configuration::IHumanKey const KEY_SPY_AGENT_ADVANCED          ("spyagentadvanced");
Configuration::IHumanKey const KEY_SPY_SPY_NOVICE              ("spyspynovice");
Configuration::IHumanKey const KEY_SPY_SPY_ADVANCED            ("spyspyadvanced");
Configuration::IHumanKey const KEY_SPY_THUG_NOVICE             ("spythugnovice");
Configuration::IHumanKey const KEY_SPY_THUG_ADVANCED           ("spythugadvanced");

Configuration::IHumanKey const KEY_WORKER_BLACKSMITH_NOVICE    ("workerblacksmithnovice");
Configuration::IHumanKey const KEY_WORKER_BLACKSMITH_ADVANCED  ("workerblacksmithadvanced");
Configuration::IHumanKey const KEY_WORKER_BREEDER_NOVICE       ("workerbreedernovice");
Configuration::IHumanKey const KEY_WORKER_BREEDER_ADVANCED     ("workerbreederadvanced");
Configuration::IHumanKey const KEY_WORKER_DRUID_NOVICE         ("workerdruidnovice");
Configuration::IHumanKey const KEY_WORKER_DRUID_ADVANCED       ("workerdruidadvanced");
Configuration::IHumanKey const KEY_WORKER_FARMER_NOVICE        ("workerfarmernovice");
Configuration::IHumanKey const KEY_WORKER_FARMER_ADVANCED      ("workerfarmeradvanced");
Configuration::IHumanKey const KEY_WORKER_FISHERMAN_NOVICE     ("workerfishermannovice");
Configuration::IHumanKey const KEY_WORKER_FISHERMAN_ADVANCED   ("workerfishermanadvanced");
Configuration::IHumanKey const KEY_WORKER_JOBLESS_NOVICE       ("workerjoblessnovice");
Configuration::IHumanKey const KEY_WORKER_JOBLESS_ADVANCED     ("workerjoblessadvanced");
Configuration::IHumanKey const KEY_WORKER_LUMBERJACK_NOVICE    ("workerlumberjacknovice");
Configuration::IHumanKey const KEY_WORKER_LUMBERJACK_ADVANCED  ("workerlumberjackadvanced");
Configuration::IHumanKey const KEY_WORKER_MERCHANT_NOVICE      ("workermerchantnovice");
Configuration::IHumanKey const KEY_WORKER_MERCHANT_ADVANCED    ("workermerchantadvanced");
Configuration::IHumanKey const KEY_WORKER_MINER_NOVICE         ("workerminernovice");
Configuration::IHumanKey const KEY_WORKER_MINER_ADVANCED       ("workermineradvanced");
Configuration::IHumanKey const KEY_WORKER_OFFICIAL_NOVICE      ("workerofficialnovice");
Configuration::IHumanKey const KEY_WORKER_OFFICIAL_ADVANCED    ("workerofficialadvanced");
Configuration::IHumanKey const KEY_WORKER_PRIEST_NOVICE        ("workerpriestnovice");
Configuration::IHumanKey const KEY_WORKER_PRIEST_ADVANCED      ("workerpriestadvanced");
Configuration::IHumanKey const KEY_WORKER_STEELWORKER_NOVICE   ("workersteelworkernovice");
Configuration::IHumanKey const KEY_WORKER_STEELWORKER_ADVANCED ("workersteelworkeradvanced");
Configuration::IHumanKey const KEY_WORKER_STONE_MASON_NOVICE   ("workerstonemasonnovice");
Configuration::IHumanKey const KEY_WORKER_STONE_MASON_ADVANCED ("workerstonemasonadvanced");
Configuration::IHumanKey const KEY_WORKER_TEACHER_NOVICE       ("workerteachernovice");
Configuration::IHumanKey const KEY_WORKER_TEACHER_ADVANCED     ("workerteacheradvanced");
//}@

/**
 * @brief The vector of keys.
 */
typedef std::vector<Configuration::IHumanKey> KeyVec;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_KEY_HPP
