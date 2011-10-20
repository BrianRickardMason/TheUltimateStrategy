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

#ifndef GAMESERVER_LAND_ILANDACCESSOR_HPP
#define GAMESERVER_LAND_ILANDACCESSOR_HPP

#include <GameServer/Land/ILandRecord.hpp>
#include <GameServer/Persistence/ITransaction.hpp>
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Land
{

/**
 * @brief The interface of LandAccessor.
 */
class ILandAccessor
    : boost::noncopyable
{
public:
    virtual ~ILandAccessor(){};

    /**
     * @brief Inserts a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_land_name   The name of the land.
     */
    virtual void insertRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_world_name,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Deletes a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    virtual void deleteRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    virtual ILandRecordShrPtr getRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual ILandRecordMap getRecords(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) const = 0;

    /**
     * @brief Gets all records of the lands that belong to a given world.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual ILandRecordMap getRecordsByWorldName(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    virtual void markGranted(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<ILandAccessor>     ILandAccessorAutPtr;
typedef boost::scoped_ptr<ILandAccessor> ILandAccessorScpPtr;
//}@

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_ILANDACCESSOR_HPP
