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

#ifndef GAMESERVER_SETTLEMENT_SETTLEMENTMANAGER_HPP
#define GAMESERVER_SETTLEMENT_SETTLEMENTMANAGER_HPP

#include "ISettlementManager.hpp"
#include "ISettlementManagerAccessor.hpp"

namespace GameServer
{
namespace Settlement
{

/**
 * @brief SettlementManager.
 */
class SettlementManager
    : public ISettlementManager
{
public:
    /**
     * @brief Constructs the settlement manager.
     *
     * @param a_accessor An accessor to be injected.
     */
    SettlementManager(
        ISettlementManagerAccessorAutPtr a_accessor
    );

    /**
     * @brief Creates a settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_land            The land.
     * @param a_settlement_name The name of the settlement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        Land::ILandShrPtr               const a_land,
        std::string                     const a_settlement_name
    ) const;

    /**
     * @brief Deletes a settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deleteSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;

    /**
     * @brief Gets a settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     *
     * @return The settlement, null if not found.
     */
    virtual ISettlementShrPtr getSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;

    /**
     * @brief Gets settlements.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return A map of settlements, an empty map if not found.
     */
    virtual ISettlementMap getSettlements(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

private:
    /**
     * @brief Prepares the result for getSettlement* methods.
     *
     * @param a_record A settlement record.
     *
     * @return A settlement.
     */
    ISettlementShrPtr prepareResultGetSettlement(
        ISettlementRecordShrPtr a_record
    ) const;

    /**
     * @brief Prepares the result for getSettlements* methods.
     *
     * @param a_records A map of settlement records.
     *
     * @return A map of settlements.
     */
    ISettlementMap prepareResultGetSettlements(
        ISettlementRecordMap a_records
    ) const;

    /**
     * @brief An accessor.
     */
    ISettlementManagerAccessorScpPtr m_accessor;
};

/**
 * @brief An auto pointer of settlement manager.
 */
typedef std::auto_ptr<SettlementManager> SettlementManagerAutPtr;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_SETTLEMENTMANAGER_HPP
