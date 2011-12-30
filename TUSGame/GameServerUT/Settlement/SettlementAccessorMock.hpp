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

#ifndef GAMESERVER_SETTLEMENT_SETTLEMENTACCESSORMOCK_HPP
#define GAMESERVER_SETTLEMENT_SETTLEMENTACCESSORMOCK_HPP

#include <TUSGame/GameServer/Settlement/ISettlementAccessor.hpp>
#include <gmock/gmock.h>

namespace GameServer
{
namespace Settlement
{

/**
 * @brief A mock of the settlement accessor.
 */
class SettlementAccessorMock
    : public ISettlementAccessor
{
public:
    /**
     * @brief Inserts a settlement record.
     *
     * @param a_transaction     The transaction.
     * @param a_land_name       The name of the land.
     * @param a_settlement_name The name of the settlement.
     */
    MOCK_CONST_METHOD3(
        insertRecord,
        void(
            Persistence::ITransactionShrPtr       a_transaction,
            std::string                     const a_land_name,
            std::string                     const a_settlement_name
        )
    );

    /**
     * @brief Deletes a settlement record.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     */
    MOCK_CONST_METHOD2(
        deleteRecord,
        void(
            Persistence::ITransactionShrPtr       a_transaction,
            std::string                     const a_settlement_name
        )
    );

    /**
     * @brief Gets the record of settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     *
     * @return The record of the settlement, null if not found.
     */
    MOCK_CONST_METHOD2(
        getRecord,
        ISettlementRecordShrPtr(
            Persistence::ITransactionShrPtr       a_transaction,
            std::string                     const a_settlement_name
        )
    );

    /**
     * @brief Gets records of settlement.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return A map of settlement records, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getRecords,
        ISettlementRecordMap(
            Persistence::ITransactionShrPtr       a_transaction,
            std::string                     const a_land_name
        )
    );
};

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_SETTLEMENTACCESSORMOCK_HPP
