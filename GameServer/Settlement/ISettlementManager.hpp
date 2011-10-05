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

#ifndef GAMESERVER_SETTLEMENT_ISETTLEMENTMANAGER_HPP
#define GAMESERVER_SETTLEMENT_ISETTLEMENTMANAGER_HPP

#include "../Persistency/ITransaction.hpp"
#include "Settlement.hpp"
#include <boost/noncopyable.hpp>

namespace GameServer
{
namespace Settlement
{

/**
 * @brief The interface of SettlementManager.
 */
class ISettlementManager
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the manager.
     */
    virtual ~ISettlementManager(){};

    /**
     * @brief Creates a settlement.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of a land.
     * @param a_name        The name of the settlement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name,
        std::string                     const a_name
    ) const = 0;

    /**
     * @brief Deletes a settlement.
     *
     * @param a_transaction   The transaction.
     * @param a_id_settlement An identifier of the settlement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deleteSettlement(
        Persistency::ITransactionShrPtr         a_transaction,
        IDSettlement                    const & a_id_settlement
    ) const = 0;

    /**
     * @brief Gets a settlement.
     *
     * @param a_transaction   The transaction.
     * @param a_id_settlement The identifier of the settlement.
     *
     * @return The settlement, null if not found.
     */
    virtual SettlementShrPtr getSettlement(
        Persistency::ITransactionShrPtr         a_transaction,
        IDSettlement                    const & a_id_settlement
    ) const = 0;

    /**
     * @brief Gets a settlement.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     * @param a_name        The name of the settlement.
     *
     * @return The settlement, null if not found.
     */
    virtual SettlementShrPtr getSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name,
        std::string                     const a_name
    ) const = 0;

    /**
     * @brief Gets settlements.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of settlements, an empty map if not found.
     */
    virtual SettlementMap getSettlements(
        Persistency::ITransactionShrPtr a_transaction
    ) const = 0;

    /**
     * @brief Gets settlements.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return A map of settlements, an empty map if not found.
     */
    virtual SettlementMap getSettlements(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of SettlementManager.
 */
typedef boost::shared_ptr<ISettlementManager> ISettlementManagerShrPtr;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_ISETTLEMENTMANAGER_HPP
