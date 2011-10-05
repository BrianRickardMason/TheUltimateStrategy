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

#ifndef GAMESERVER_EPOCH_EPOCHMANAGER_HPP
#define GAMESERVER_EPOCH_EPOCHMANAGER_HPP

#include "IEpochManager.hpp"
#include "IEpochManagerAccessor.hpp"

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The epoch manager.
 */
class EpochManager
    : public IEpochManager
{
public:
    /**
     * @brief Constructs the epoch manager.
     *
     * @param a_accessor The accessor to be injected.
     */
    EpochManager(
        IEpochManagerAccessorAutPtr a_accessor
    );

    /**
     * @brief Creates the epoch.
     *
     * The epoch must not exist.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createEpoch(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

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
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The epoch, null if not found.
     */
    virtual EpochShrPtr getEpoch(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The epoch, null if not found.
     */
    virtual EpochShrPtr getEpochByLandName(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction   The transaction.
     * @param a_id_settlement The identifier of the settlement.
     *
     * @return The epoch, null if not found.
     */
    virtual EpochShrPtr getEpochByIDSettlement(
        Persistency::ITransactionShrPtr         a_transaction,
        Settlement::IDSettlement        const & a_id_settlement
    ) const;

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
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

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
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

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
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

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
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IEpochManagerAccessorScpPtr m_accessor;
};

/**
 * @brief The auto pointer of the epoch manager.
 */
typedef std::auto_ptr<EpochManager> EpochManagerAutPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_EPOCHMANAGER_HPP
