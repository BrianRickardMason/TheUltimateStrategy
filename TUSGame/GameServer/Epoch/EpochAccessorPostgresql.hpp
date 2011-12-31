// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#ifndef GAMESERVER_EPOCH_EPOCHACCESSORPOSTGRESQL_HPP
#define GAMESERVER_EPOCH_EPOCHACCESSORPOSTGRESQL_HPP

#include <TUSGame/GameServer/Epoch/IEpochAccessor.hpp>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The PostgreSQL accessor of the epoch.
 */
class EpochAccessorPostgresql
    : public IEpochAccessor
{
public:
    /**
     * @brief Inserts the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     * @param a_epoch_name  The name of the epoch.
     */
    virtual void insertRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name,
        std::string                     const a_epoch_name
    ) const;

    /**
     * @brief Deletes the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void deleteRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the record of the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world record, null if not found.
     */
    virtual IEpochRecordShrPtr getRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Sets the active state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markActive(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Sets the active state to false.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markUnactive(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Marks the finished state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markFinished(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Increments the number of ticks.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void incrementTicks(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the name of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The name of the world, an empty string if not found.
     */
    virtual std::string getWorldNameOfLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Gets the name of the land of the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement
     *
     * @return The name of the land, an empty string if not found.
     */
    virtual std::string getLandNameOfSettlement(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;
};

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_EPOCHACCESSORPOSTGRESQL_HPP
