// Copyright ("C") 2010 and 2011 Marcin Arkadiusz Skrobiranda.
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
// DAMAGES ("INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION")
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT ("INCLUDING NEGLIGENCE OR OTHERWISE") ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#ifndef GAMESERVER_BUILDING_KEY_HPP
#define GAMESERVER_BUILDING_KEY_HPP

#include <GameServer/Configuration/Configurator/Building/IBuilding.hpp>

namespace GameServer
{
namespace Building
{

//@{
/**
 * @brief The available key.
 */
Configuration::IKey const KEY_GOLD_ALTAR_OF_WISHES     ("goldaltarofwishes");
Configuration::IKey const KEY_GOLD_COMMUNICATION_TOWERS("goldcommunicationtowers");
Configuration::IKey const KEY_GOLD_ETERNAL_CALENDAR    ("goldeternalcalendar");
Configuration::IKey const KEY_GOLD_HUNTER_OF_METEORS   ("goldhunterofmeteors");
Configuration::IKey const KEY_GOLD_HUNTER_OF_RAINS     ("goldhuterofrains");
Configuration::IKey const KEY_GOLD_HUNTER_OF_STORMS    ("goldhunterofstorms");
Configuration::IKey const KEY_GOLD_HUNTER_OF_WINDS     ("goldhunterofwinds");
Configuration::IKey const KEY_GOLD_NECROPOLIS          ("goldnecropolis");
Configuration::IKey const KEY_GOLD_ORACLE              ("goldoracle");
Configuration::IKey const KEY_GOLD_PORTAL_OF_ELEMENTS  ("goldportalofelements");
Configuration::IKey const KEY_GOLD_PSIONIC_ACADEMY     ("goldpsionicacademy");
Configuration::IKey const KEY_GOLD_TOWER_OF_CHAOS      ("goldtowerofchaos");

Configuration::IKey const KEY_REGULAR_BARRACKS         ("regularbarracks");
Configuration::IKey const KEY_REGULAR_FARM             ("regularfarm");
Configuration::IKey const KEY_REGULAR_FORGE            ("regularforge");
Configuration::IKey const KEY_REGULAR_GUILD            ("regularguild");
Configuration::IKey const KEY_REGULAR_HOUSE            ("regularhouse");
Configuration::IKey const KEY_REGULAR_MARKETPLACE      ("regularmarketplace");
Configuration::IKey const KEY_REGULAR_MINE             ("regularmine");
Configuration::IKey const KEY_REGULAR_QUARRY           ("regularquarry");
Configuration::IKey const KEY_REGULAR_SAWMILL          ("regularsawmill");
Configuration::IKey const KEY_REGULAR_SCHOOL           ("regularschool");
Configuration::IKey const KEY_REGULAR_STEELWORKS       ("regularsteelworks");
Configuration::IKey const KEY_REGULAR_TEMPLE           ("regulartemple");

Configuration::IKey const KEY_SPECIAL_AQUEDUCT         ("specialaqueduct");
Configuration::IKey const KEY_SPECIAL_BAWDY_HOUSE      ("specialbawdyhouse");
Configuration::IKey const KEY_SPECIAL_COMMERCIAL_PORT  ("specialcommercialport");
Configuration::IKey const KEY_SPECIAL_COURT            ("specialcourt");
Configuration::IKey const KEY_SPECIAL_GRANARY          ("specialgranary");
Configuration::IKey const KEY_SPECIAL_SEWERAGE         ("specialsewerage");
//}@

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_KEY_HPP
