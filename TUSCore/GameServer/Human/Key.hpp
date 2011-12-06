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
Configuration::IKey const KEY_WORKER_BREEDER_NOVICE       ("workerbreedernovice");
Configuration::IKey const KEY_WORKER_BREEDER_ADVANCED     ("workerbreederadvanced");
Configuration::IKey const KEY_WORKER_FARMER_NOVICE        ("workerfarmernovice");
Configuration::IKey const KEY_WORKER_FARMER_ADVANCED      ("workerfarmeradvanced");
Configuration::IKey const KEY_WORKER_FISHERMAN_NOVICE     ("workerfishermannovice");
Configuration::IKey const KEY_WORKER_FISHERMAN_ADVANCED   ("workerfishermanadvanced");
Configuration::IKey const KEY_WORKER_JOBLESS_NOVICE       ("workerjoblessnovice");
Configuration::IKey const KEY_WORKER_JOBLESS_ADVANCED     ("workerjoblessadvanced");
Configuration::IKey const KEY_WORKER_LUMBERJACK_NOVICE    ("workerlumberjacknovice");
Configuration::IKey const KEY_WORKER_LUMBERJACK_ADVANCED  ("workerlumberjackadvanced");
Configuration::IKey const KEY_WORKER_MERCHANT_NOVICE      ("workermerchantnovice");
Configuration::IKey const KEY_WORKER_MERCHANT_ADVANCED    ("workermerchantadvanced");
Configuration::IKey const KEY_WORKER_MINER_NOVICE         ("workerminernovice");
Configuration::IKey const KEY_WORKER_MINER_ADVANCED       ("workermineradvanced");
Configuration::IKey const KEY_WORKER_STEELWORKER_NOVICE   ("workersteelworkernovice");
Configuration::IKey const KEY_WORKER_STEELWORKER_ADVANCED ("workersteelworkeradvanced");
Configuration::IKey const KEY_WORKER_STONE_MASON_NOVICE   ("workerstonemasonnovice");
Configuration::IKey const KEY_WORKER_STONE_MASON_ADVANCED ("workerstonemasonadvanced");
//}@

/**
 * @brief The vector of keys.
 */
typedef std::vector<Configuration::IKey> KeyVec;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_KEY_HPP
