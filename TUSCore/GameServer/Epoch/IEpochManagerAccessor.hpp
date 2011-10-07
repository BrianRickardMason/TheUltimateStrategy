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

#ifndef GAMESERVER_EPOCH_IEPOCHMANAGERACCESSOR_HPP
#define GAMESERVER_EPOCH_IEPOCHMANAGERACCESSOR_HPP

#include "../Persistency/ITransaction.hpp"
#include "EpochRecord.hpp"
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>
#include <string>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The interface of the accessor of the manager of the epoch.
 */
class IEpochManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the accessor.
     */
    virtual ~IEpochManagerAccessor(){}

    /**
     * @brief Inserts the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Deletes the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the record of the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world record, null if not found.
     */
    virtual EpochRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Sets the active state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markActive(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Sets the active state to false.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markUnactive(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Marks the finished state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void markFinished(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Increments the number of ticks.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void incrementTicks(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the name of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The name of the world, an empty string if not found.
     */
    virtual std::string getWorldNameOfLand(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets the name of the land of the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement
     *
     * @return The name of the land, an empty string if not found.
     */
    virtual std::string getLandNameOfSettlement(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const = 0;
};

/**
 * @brief The auto pointer of the interface of the accessor of the the manager of the epoch.
 */
typedef std::auto_ptr<IEpochManagerAccessor> IEpochManagerAccessorAutPtr;

/**
 * @brief The scoped pointer of the interface of the accessor of the the manager of the epoch.
 */
typedef boost::scoped_ptr<IEpochManagerAccessor> IEpochManagerAccessorScpPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_IEPOCHMANAGERACCESSOR_HPP
