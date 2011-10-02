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

#ifndef GAMESERVER_EPOCH_EPOCHMANAGERACCESSORMOCK_HPP
#define GAMESERVER_EPOCH_EPOCHMANAGERACCESSORMOCK_HPP

#include "../../GameServer/Epoch/IEpochManagerAccessor.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief The mock of the accessor of the manager of the epochs.
 */
class EpochManagerAccessorMock
    : public IEpochManagerAccessor
{
public:
    /**
     * @brief Inserts the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        insertRecord,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Deletes the record of the epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        deleteRecord,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Gets the record of the epoch of the world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world record, null if not found.
     */
    MOCK_CONST_METHOD2(
        getRecord,
        EpochRecordShrPtr(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Sets the active state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        markActive,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Sets the active state to false.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        markUnactive,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Marks the finished state to true.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        markFinished,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Increments the number of ticks.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    MOCK_CONST_METHOD2(
        incrementTicks,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Gets the name of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The name of the world, an empty string if not found.
     */
    MOCK_CONST_METHOD2(
        getWorldNameOfLand,
        std::string(
            Persistency::ITransactionShrPtr         a_transaction,
            Land::IDLand                    const & a_id_land
        )
    );

    /**
     * @brief Gets the name of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_name        The name of the land.
     *
     * @return The name of the world, an empty string if not found.
     */
    MOCK_CONST_METHOD2(
        getWorldNameOfLand,
        std::string(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Gets the identifier of the land of the settlement.
     *
     * @param a_transaction   The transaction.
     * @param a_id_settlement The identifier of the settlement
     *
     * @return The identifier of the land, 0 if not found.
     */
    MOCK_CONST_METHOD2(
        getIDLandOfSettlement,
        Land::IDLand(
            Persistency::ITransactionShrPtr         a_transaction,
            Settlement::IDSettlement        const & a_id_settlement
        )
    );
};

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_EPOCHMANAGERACCESSORMOCK_HPP
