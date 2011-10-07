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

#ifndef GAMESERVER_HUMAN_IDHUMAN_HPP
#define GAMESERVER_HUMAN_IDHUMAN_HPP

#include "../Common/ConstrainedPair.hpp"
#include <vector>

namespace GameServer
{
namespace Human
{

/**
 * @brief The identifier of a human.
 */
typedef Common::ConstrainedPair<Common::RangedPairUnsignedShortIntPolicy<1, 3, 1, 4, 1, 3, 1, 14> > IDHuman;

/**
 * @brief The available classes of a human.
 */
unsigned short int const ID_HUMAN_CLASS_SOLDIER (1);
unsigned short int const ID_HUMAN_CLASS_SORCERER(2);
unsigned short int const ID_HUMAN_CLASS_SPY     (3);
unsigned short int const ID_HUMAN_CLASS_WORKER  (4);

const IDHuman ID_HUMAN_SOLDIER_ARCHER     (1, 1);
const IDHuman ID_HUMAN_SOLDIER_HORSEMAN   (1, 2);
const IDHuman ID_HUMAN_SOLDIER_INFANTRYMAN(1, 3);

const IDHuman ID_HUMAN_SORCERER_EARTH     (2, 1);
const IDHuman ID_HUMAN_SORCERER_FIRE      (2, 2);
const IDHuman ID_HUMAN_SORCERER_WATER     (2, 3);
const IDHuman ID_HUMAN_SORCERER_WIND      (2, 4);

const IDHuman ID_HUMAN_SPY_AGENT          (3, 1);
const IDHuman ID_HUMAN_SPY_SPY            (3, 2);
const IDHuman ID_HUMAN_SPY_THUG           (3, 3);

const IDHuman ID_HUMAN_WORKER_BLACKSMITH  (4, 1);
const IDHuman ID_HUMAN_WORKER_BREEDER     (4, 2);
const IDHuman ID_HUMAN_WORKER_DRUID       (4, 3);
const IDHuman ID_HUMAN_WORKER_FARMER      (4, 4);
const IDHuman ID_HUMAN_WORKER_FISHERMAN   (4, 5);
const IDHuman ID_HUMAN_WORKER_JOBLESS     (4, 6);
const IDHuman ID_HUMAN_WORKER_LUMBERJACK  (4, 7);
const IDHuman ID_HUMAN_WORKER_MERCHANT    (4, 8);
const IDHuman ID_HUMAN_WORKER_MINER       (4, 9);
const IDHuman ID_HUMAN_WORKER_OFFICIAL    (4, 10);
const IDHuman ID_HUMAN_WORKER_PRIEST      (4, 11);
const IDHuman ID_HUMAN_WORKER_STEELWORKER (4, 12);
const IDHuman ID_HUMAN_WORKER_STONE_MASON (4, 13);
const IDHuman ID_HUMAN_WORKER_TEACHER     (4, 14);

/**
 * @brief The vector of identifiers of a human.
 */
typedef std::vector<IDHuman> IDHumanVec;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_IDHUMAN_HPP
