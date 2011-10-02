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

#ifndef GAMESERVER_LAND_LANDMANAGERACCESSORMOCK_HPP
#define GAMESERVER_LAND_LANDMANAGERACCESSORMOCK_HPP

#include "../../GameServer/Land/ILandManagerAccessor.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Land
{

/**
 * @brief The mock of LandManagerAccessor.
 */
class LandManagerAccessorMock
    : public ILandManagerAccessor
{
public:
    /**
     * @brief Inserts a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_id_epoch    The identifier of the epoch.
     * @param a_name        The name of the land.
     */
    MOCK_CONST_METHOD5(
        insertRecord,
        void(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const   a_login,
            std::string                     const   a_world_name,
            Epoch::IDEpoch                  const & a_id_epoch,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Deletes a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     */
    MOCK_CONST_METHOD2(
        deleteRecord,
        void(
            Persistency::ITransactionShrPtr         a_transaction,
            IDLand                          const & a_id_land
        )
    );

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The record of the land, null if not found.
     */
    MOCK_CONST_METHOD2(
        getRecord,
        LandRecordShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            IDLand                          const & a_id_land
        )
    );

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_name        The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    MOCK_CONST_METHOD3(
        getRecordByLogin,
        LandRecordShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const   a_login,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     * @param a_name        The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    MOCK_CONST_METHOD3(
        getRecordByWorldName,
        LandRecordShrPtr(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const   a_world_name,
            std::string                     const & a_name
        )
    );

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    MOCK_CONST_METHOD1(
        getRecords,
        LandRecordMap(
            Persistency::ITransactionShrPtr a_transaction
        )
    );

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getRecordsByLogin,
        LandRecordMap(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_login
        )
    );

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getRecordsByWorldName,
        LandRecordMap(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    MOCK_CONST_METHOD3(
        getRecords,
        LandRecordMap(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_login,
            std::string                     const a_world_name
        )
    );

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     */
    MOCK_CONST_METHOD2(
        markGranted,
        void(
            Persistency::ITransactionShrPtr         a_transaction,
            IDLand                          const & a_id_land
        )
    );
};

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LANDMANAGERACCESSORMOCK_HPP
