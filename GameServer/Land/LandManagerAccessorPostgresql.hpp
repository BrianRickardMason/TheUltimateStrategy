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

#ifndef GAMESERVER_LAND_LANDMANAGERACCESSORPOSTGRESQL_HPP
#define GAMESERVER_LAND_LANDMANAGERACCESSORPOSTGRESQL_HPP

#include "ILandManagerAccessor.hpp"
#include <pqxx/result.hxx>

namespace GameServer
{
namespace Land
{

/**
 * @brief The PostgreSQL LandManagerAccessor.
 */
class LandManagerAccessorPostgresql
    : public ILandManagerAccessor
{
public:
    /**
     * @brief Inserts a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_id_world    The identifier of the world.
     * @param a_id_epoch    The identifier of the epoch.
     * @param a_name        The name of the land.
     *
     * @return True on success, false otherwise.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        World::IDWorld                  const & a_id_world,
        Epoch::IDEpoch                  const & a_id_epoch,
        std::string                     const & a_name
    ) const;

    /**
     * @brief Deletes a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return True on success, false otherwise.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        IDLand                          const & a_id_land
    ) const;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The record of the land, null if not found.
     */
    virtual LandRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        IDLand                          const & a_id_land
    ) const;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_name        The name of the land.
     *
     * @return The record of the land, null if not found.
     */
    virtual LandRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        std::string                     const & a_name
    ) const;

    /**
     * @brief Gets a record of the land.
     *
     * @param a_transaction The transaction.
     * @param a_name        The name of the land.
     * @param a_id_world    The identifier of the world.
     *
     * @return The record of the land, null if not found.
     */
    virtual LandRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const & a_name,
        World::IDWorld                  const & a_id_world
    ) const;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr a_transaction
    ) const;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr       a_transaction,
        std::string                     const a_login
    ) const;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr         a_transaction,
        World::IDWorld                  const & a_id_world
    ) const;

    /**
     * @brief Gets records of the land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_id_world    The identifier of the world.
     *
     * @return A map of records of the land, an empty map if not found.
     */
    virtual LandRecordMap getRecords(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        World::IDWorld                  const & a_id_world
    ) const;

    /**
     * @brief Marks that land has been given a grant.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     */
    virtual void markGranted(
        Persistency::ITransactionShrPtr         a_transaction,
        IDLand                          const & a_id_land
    ) const;

private:
    /**
     * @brief Prepares the result for getRecord methods.
     *
     * @param a_result A postgresql result.
     *
     * @return A record of the land.
     */
    LandRecordShrPtr prepareResultGetRecord(
        pqxx::result const & a_result
    ) const;

    /**
     * @brief Prepares the result for getRecords methods.
     *
     * @param a_result A postgresql result.
     *
     * @return A map of records of the land.
     */
    LandRecordMap prepareResultGetRecords(
        pqxx::result const & a_result
    ) const;
};

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_LANDMANAGERACCESSORPOSTGRESQL_HPP
