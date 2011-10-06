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

#ifndef GAMESERVER_SETTLEMENT_SETTLEMENT_HPP
#define GAMESERVER_SETTLEMENT_SETTLEMENT_HPP

#include "SettlementRecord.hpp"

namespace GameServer
{
namespace Settlement
{

/**
 * @brief The settlement.
 */
class Settlement
{
public:
    /**
     * @brief Constructs the settlement.
     *
     * @param a_record A corresponding record.
     */
    explicit Settlement(
        SettlementRecord const & a_record
    );

    /**
     * @brief Gets the name of the land.
     *
     * @return The name of the land.
     */
    std::string getLandName() const;

    /**
     * @brief Gets the name of the settlement.
     *
     * @return The name of the settlement.
     */
    std::string getSettlementName() const;

private:
    /**
     * @brief The name of the land.
     */
    std::string const m_land_name;

    /**
     * @brief The name of the settlement.
     */
    std::string const m_settlement_name;
};

/**
 * @brief A shared pointer of settlement.
 */
typedef boost::shared_ptr<Settlement> SettlementShrPtr;

/**
 * @brief A pair of settlement.
 */
typedef std::pair<std::string, SettlementShrPtr> SettlementPair;

/**
 * @brief A map of settlement.
 */
typedef std::map<std::string, SettlementShrPtr> SettlementMap;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_SETTLEMENT_HPP
