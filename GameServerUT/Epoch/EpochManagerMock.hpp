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

#ifndef GAMESERVER_EPOCH_EPOCHMANAGERMOCK_HPP
#define GAMESERVER_EPOCH_EPOCHMANAGERMOCK_HPP

#include "../../GameServer/Epoch/IEpochManager.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The mock of the manager of the epochs.
 */
class EpochManagerMock
    : public IEpochManager
{
public:
    /**
     * @brief Creates the epoch.
     *
     * The epoch must not exist.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        createEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Deletes the epoch.
     *
     * The epoch must exist.
     * The epoch must be finished before it is deleted.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        deleteEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return The epoch, null if not found.
     */
    MOCK_CONST_METHOD2(
        getEpoch,
        EpochShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The epoch, null if not found.
     */
    MOCK_CONST_METHOD2(
        getEpochByIDLand,
        EpochShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            Land::IDLand                    const & a_id_land
        )
    );

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_name        The name of the land.
     *
     * @return The epoch, null if not found.
     */
    MOCK_CONST_METHOD2(
        getEpochByLandName,
        EpochShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Gets the epoch of the world.
     *
     * @param a_transaction   The transaction.
     * @param a_id_settlement The identifier of the settlement.
     *
     * @return The epoch, null if not found.
     */
    MOCK_CONST_METHOD2(
        getEpochByIDSettlement,
        EpochShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            Settlement::IDSettlement        const & a_id_settlement
        )
    );

    /**
     * @brief Activates the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        activateEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Deactivates the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must be active.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        deactivateEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Finishes the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        finishEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );

    /**
     * @brief Ticks the epoch.
     *
     * The epoch must exist.
     * The epoch must not be finished.
     * The epoch must not be active.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        tickEpoch,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            World::IDWorld                  const & a_id_world
        )
    );
};

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_EPOCHMANAGERMOCK_HPP
