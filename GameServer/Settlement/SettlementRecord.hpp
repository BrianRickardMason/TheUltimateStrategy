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

#ifndef GAMESERVER_SETTLEMENT_SETTLEMENTRECORD_HPP
#define GAMESERVER_SETTLEMENT_SETTLEMENTRECORD_HPP

#include "IDSettlement.hpp"
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace GameServer
{
namespace Settlement
{

/**
 * @brief A settlement record.
 */
class SettlementRecord
{
public:
    /**
     * @brief Constructs a settlement record.
     *
     * @param a_land_name     The name of the land.
     * @param a_id_settlement An identifier of the settlement.
     * @param a_name          A name of the settlement.
     */
    SettlementRecord(
        std::string  const   a_land_name,
        IDSettlement const & a_id_settlement,
        std::string  const & a_name
    );

    /**
     * @brief Gets the name of the land.
     *
     * @return The name of the land.
     */
    std::string getLandName() const;

    /**
     * @brief Gets the identifier of the settlement.
     *
     * @return The identifier of the settlement.
     */
    IDSettlement const & getIDSettlement() const;

    /**
     * @brief Gets the name of the settlement.
     *
     * @return The name of the settlement.
     */
    std::string const & getName() const;

private:
    /**
     * @brief The name of the land.
     */
    std::string const m_land_name;

    /**
     * @brief An identifier of the settlement.
     */
    IDSettlement const m_id_settlement;

    /**
     * @brief A name of the settlement.
     */
    std::string const m_name;
};

/**
 * @brief A shared pointer of settlement record.
 */
typedef boost::shared_ptr<SettlementRecord> SettlementRecordShrPtr;

/**
 * @brief A pair of settlement record.
 */
typedef std::pair<IDSettlement, SettlementRecordShrPtr> SettlementRecordPair;

/**
 * @brief A map of settlement record.
 */
typedef std::map<IDSettlement, SettlementRecordShrPtr> SettlementRecordMap;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_SETTLEMENTRECORD_HPP
