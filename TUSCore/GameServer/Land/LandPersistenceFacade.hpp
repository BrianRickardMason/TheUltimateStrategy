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

#ifndef GAMESERVER_LAND_LANDPERSISTENCEFACADE_HPP
#define GAMESERVER_LAND_LANDPERSISTENCEFACADE_HPP

#include <GameServer/Land/ILandAccessor.hpp>
#include <GameServer/Land/ILandPersistenceFacade.hpp>

namespace GameServer
{
namespace Land
{

/**
 * @brief LandPersistenceFacade.
 */
class LandPersistenceFacade
    : public ILandPersistenceFacade
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_accessor An accessor to be injected.
     */
    LandPersistenceFacade(
        ILandAccessorAutPtr a_accessor
    );

    /**
     * @brief Creates a land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_name        The name of the land.
     *
     * @return True on success, false otherwise.
     */
    virtual bool createLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_world_name,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Deletes a land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return True on success, false otherwise.
     */
    virtual bool deleteLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Gets a land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The land, null if not found.
     */
    virtual ILandShrPtr getLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

    /**
     * @brief Gets lands.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of lands, an empty map if not found.
     */
    virtual ILandMap getLands(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) const;

    /**
     * @brief Gets all lands that belong to a given world.
     *
     * @param a_transaction The transaction.
     * @param a_world       The world.
     *
     * @return A map of lands, an empty map if not found.
     */
    virtual ILandMap getLands(
        Persistence::ITransactionShrPtr       a_transaction,
        World::IWorldShrPtr             const a_world
    ) const;

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    virtual void markGranted(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const;

private:
    /**
     * @brief Prepares the result for getLand* methods.
     *
     * @param a_record A land record.
     *
     * @return A land.
     */
    ILandShrPtr prepareResultGetLand(
        ILandRecordShrPtr a_record
    ) const;

    /**
     * @brief Prepares the result for getLands* methods.
     *
     * @param a_records A map of land records.
     *
     * @return A map of lands.
     */
    ILandMap prepareResultGetLands(
        ILandRecordMap a_records
    ) const;

    /**
     * @brief An accessor.
     */
    ILandAccessorScpPtr m_accessor;
};

/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<LandPersistenceFacade> LandPersistenceFacadeAutPtr;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LANDPERSISTENCEFACADE_HPP
