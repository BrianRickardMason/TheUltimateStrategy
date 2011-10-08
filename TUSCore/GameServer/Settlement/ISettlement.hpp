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

#ifndef GAMESERVER_SETTLEMENT_ISETTLEMENT_HPP
#define GAMESERVER_SETTLEMENT_ISETTLEMENT_HPP

#include "SettlementRecord.hpp"

namespace GameServer
{
namespace Settlement
{

/**
 * @brief The interface of the settlement.
 */
class ISettlement
{
public:
    /**
     * @brief Destructs the interface of the settlement.
     */
    virtual ~ISettlement(){}

    /**
     * @brief Gets the name of the land.
     *
     * @return The name of the land.
     */
    virtual std::string getLandName() const = 0;

    /**
     * @brief Gets the name of the settlement.
     *
     * @return The name of the settlement.
     */
    virtual std::string getSettlementName() const = 0;
};

/**
 * @brief The shared pointer of the interface of the settlement.
 */
typedef boost::shared_ptr<ISettlement> ISettlementShrPtr;

/**
 * @brief The pair of the interface of the settlement.
 */
typedef std::pair<std::string, ISettlementShrPtr> ISettlementPair;

/**
 * @brief The map of the interface of the settlement.
 */
typedef std::map<std::string, ISettlementShrPtr> ISettlementMap;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_ISETTLEMENT_HPP
