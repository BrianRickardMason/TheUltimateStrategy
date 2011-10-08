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

#ifndef GAMESERVER_LAND_LANDMANAGERMOCK_HPP
#define GAMESERVER_LAND_LANDMANAGERMOCK_HPP

#include "../../GameServer/Land/ILandManager.hpp"
#include <gmock/gmock.h>

namespace GameServer
{
namespace Land
{

/**
 * @brief The mock of LandManager.
 */
class LandManagerMock
    : public ILandManager
{
public:
    /**
     * @brief Creates a land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_id_epoch    An identifier of the epoch.
     * @param a_land_name   The name of the land.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD5(
        createLand,
        bool(
            Persistency::ITransactionShrPtr         a_transaction,
            std::string                     const   a_login,
            std::string                     const   a_world_name,
            Epoch::IDEpoch                  const & a_id_epoch,
            std::string                     const   a_land_name
        )
    );

    /**
     * @brief Deletes a land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD2(
        deleteLand,
        bool(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_land_name
        )
    );

    /**
     * @brief Gets a land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The land, null if not found.
     */
    MOCK_CONST_METHOD2(
        getLand,
        ILandShrPtr(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_land_name
        )
    );

    /**
     * @brief Gets lands.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of lands, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getLands,
        ILandMap(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_login
        )
    );

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    MOCK_CONST_METHOD2(
        markGranted,
        void(
            Persistency::ITransactionShrPtr       a_transaction,
            std::string                     const a_land_name
        )
    );
};

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LANDMANAGERMOCK_HPP
