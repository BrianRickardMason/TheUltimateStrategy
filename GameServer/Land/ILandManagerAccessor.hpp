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

#ifndef GAMESERVER_LAND_ILANDMANAGERACCESSOR_HPP
#define GAMESERVER_LAND_ILANDMANAGERACCESSOR_HPP

#include "../Persistency/ITransaction.hpp"
#include "LandRecord.hpp"
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Land
{

/**
 * @brief The interface of LandManagerAccessor.
 */
class ILandManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the accessor.
     */
    virtual ~ILandManagerAccessor(){};

    /**
     * @brief Inserts a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_id_epoch    The identifier of the epoch.
     * @param a_land_name   The name of the land.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        std::string                     const   a_world_name,
        Epoch::IDEpoch                  const & a_id_epoch,
        std::string                     const   a_land_name
    ) const = 0;

    /**
     * @brief Deletes a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr       a_transaction,
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
    virtual LandRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_land_name   The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    virtual LandRecordShrPtr getRecordByLogin(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     * @param a_land_name   The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    virtual LandRecordShrPtr getRecordByWorldName(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name,
        std::string                     const a_land_name
    ) const = 0;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr a_transaction
    ) const = 0;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecordsByLogin(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) const = 0;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecordsByWorldName(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     */
    virtual void markGranted(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;
};

/**
 * @brief The auto pointer of the interface of LandManagerAccessor.
 */
typedef std::auto_ptr<ILandManagerAccessor> ILandManagerAccessorAutPtr;

/**
 * @brief The scoped pointer of the interface of LandManagerAccessor.
 */
typedef boost::scoped_ptr<ILandManagerAccessor> ILandManagerAccessorScpPtr;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_ILANDMANAGERACCESSOR_HPP
