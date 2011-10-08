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

#ifndef GAMESERVER_COST_IDCOSTTYPE_HPP
#define GAMESERVER_COST_IDCOSTTYPE_HPP

namespace GameServer
{
namespace Cost
{

/**
 * @brief The identifier of the cost type.
 */
typedef unsigned short int IDCostType;

/**
 * @brief The identifiers of the cost types for buildings.
 */
const unsigned short int ID_COST_TYPE_BUILDING_BUILD   = 1;
const unsigned short int ID_COST_TYPE_BUILDING_DESTROY = 2;

/**
 * @brief The identifiers of the cost types for humans.
 */
const unsigned short int ID_COST_TYPE_HUMAN_DISMISS = 3;
const unsigned short int ID_COST_TYPE_HUMAN_ENGAGE  = 4;
const unsigned short int ID_COST_TYPE_HUMAN_LIVING  = 5;

} // namespace Cost
} // namespace GameServer

#endif // GAMESERVER_COST_IDCOSTTYPE_HPP