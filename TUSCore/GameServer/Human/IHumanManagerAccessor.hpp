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

#ifndef GAMESERVER_HUMAN_IHUMANMANAGERACCESSOR_HPP
#define GAMESERVER_HUMAN_IHUMANMANAGERACCESSOR_HPP

#include "../Common/IDHolder.hpp"
#include "../Persistency/ITransaction.hpp"
#include "HumanWithVolumeRecord.hpp"
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Human
{

/**
 * @brief The interface of HumanManagerAccessor.
 */
class IHumanManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the HumanManagerAccessor.
     */
    virtual ~IHumanManagerAccessor(){};

    /**
     * @brief Inserts a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume of the human.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Deletes a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     */
    virtual void deleteRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const = 0;

    /**
     * @brief Gets a human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     *
     * @return The human with volume record, null if not found.
     */
    virtual HumanWithVolumeRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const = 0;

    /**
     * @brief Gets human with volume records by id human.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_id_human    An identifier of the human.
     *
     * @return A map of human with volume records, an empty map if not found.
     */
    virtual HumanWithVolumeRecordMap getRecords(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        IDHuman                         const & a_id_human
    ) const = 0;

    /**
     * @brief Gets human with volume records.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of human with volume records, an empty map if not found.
     */
    virtual HumanWithVolumeRecordMap getRecords(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const = 0;

    /**
     * @brief Increases the volume of human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume to be increased.
     */
    virtual void increaseVolume(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Decreases the volume of human with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the human.
     * @param a_volume      A volume to be decreased.
     */
    virtual void decreaseVolume(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const = 0;
};

/**
 * @brief The auto pointer of the interface of HumanManagerAccessor.
 */
typedef std::auto_ptr<IHumanManagerAccessor> IHumanManagerAccessorAutPtr;

/**
 * @brief The scoped pointer of the interface of HumanManagerAccessor.
 */
typedef boost::scoped_ptr<IHumanManagerAccessor> IHumanManagerAccessorScpPtr;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_IHUMANMANAGERACCESSOR_HPP
