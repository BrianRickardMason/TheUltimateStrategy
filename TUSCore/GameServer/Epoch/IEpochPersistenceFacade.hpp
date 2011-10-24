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

#ifndef GAMESERVER_EPOCH_IEPOCHPERSISTENCEFACADE_HPP
#define GAMESERVER_EPOCH_IEPOCHPERSISTENCEFACADE_HPP

#include "../Persistence/ITransaction.hpp"
#include "Epoch.hpp"
#include <boost/noncopyable.hpp>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The interface of the epoch persistence facade.
 */
class IEpochPersistenceFacade
    : boost::noncopyable
{
public:
    virtual ~IEpochPersistenceFacade(){}

    /**
     * @brief Creates the epoch.
     *
     * The epoch must not exist.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     * @param a_epoch_name  The name of the epoch.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name,
        std::string                     const a_epoch_name
    ) const = 0;

    /**
     * @brief Deletes the epoch.
     *
     * The epoch must exist.
     * The epoch must be finished before it is deleted.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deleteEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The epoch, null if not found.
     */
    virtual IEpochShrPtr getEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The epoch, null if not found.
     */
    virtual IEpochShrPtr getEpochByLandName(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     *
     * @return The epoch, null if not found.
     */
    virtual IEpochShrPtr getEpochBySettlementName(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const = 0;

    /**
     * @brief Activates the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool activateEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Deactivates the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must be active.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deactivateEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Finishes the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool finishEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Ticks the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool tickEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of the epoch persistence facade.
 */
typedef boost::shared_ptr<IEpochPersistenceFacade> IEpochPersistenceFacadeShrPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_IEPOCHPERSISTENCEFACADE_HPP
