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

#ifndef GAMESERVER_BUILDING_IBUILDINGMANAGERACCESSOR_HPP
#define GAMESERVER_BUILDING_IBUILDINGMANAGERACCESSOR_HPP

#include "../Common/IDHolder.hpp"
#include "../Persistency/ITransaction.hpp"
#include "BuildingWithVolumeRecord.hpp"
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Building
{

/**
 * @brief An interface of building manager accessor.
 */
class IBuildingManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the accessor.
     */
    virtual ~IBuildingManagerAccessor(){};

    /**
     * @brief Inserts a building with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     * @param a_volume      A volume of the building.
     *
     * @return True on success, false otherwise.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Deletes a building with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     *
     * @return True on success, false otherwise.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const = 0;

    /**
     * @brief Gets a building with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     *
     * @return The building with volume record, null if not found.
     */
    virtual BuildingWithVolumeRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const = 0;

    /**
     * @brief Gets building with volume records.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of building with volume records, an empty map if not found.
     */
    virtual BuildingWithVolumeRecordMap getRecords(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const = 0;

    /**
     * @brief Increases the volume of building with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     * @param a_volume      A volume to be increased.
     *
     * @return True on success, false otherwise.
     */
    virtual void increaseVolume(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Decreases the volume of building with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     * @param a_volume      A volume to be decreased.
     *
     * @return True on success, false otherwise.
     */
    virtual void decreaseVolume(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;
};

/**
 * @brief An auto pointer of interface of building manager accessor.
 */
typedef std::auto_ptr<IBuildingManagerAccessor> IBuildingManagerAccessorAutPtr;

/**
 * @brief A scoped pointer of interface of building manager accessor.
 */
typedef boost::scoped_ptr<IBuildingManagerAccessor> IBuildingManagerAccessorScpPtr;

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_IBUILDINGMANAGERACCESSOR_HPP
