// Copyright (C) 2010, 2011 and 2012 Marcin Arkadiusz Skrobiranda.
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

#ifndef GAMESERVER_RESOURCE_IRESOURCEACCESSOR_HPP
#define GAMESERVER_RESOURCE_IRESOURCEACCESSOR_HPP

#include <Game/GameServer/Common/IDHolder.hpp>
#include <Game/GameServer/Persistence/ITransaction.hpp>
#include <Game/GameServer/Resource/ResourceWithVolumeRecord.hpp>
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Resource
{

/**
 * @brief The interface of ResourceAccessor.
 */
class IResourceAccessor
    : boost::noncopyable
{
public:
    virtual ~IResourceAccessor(){};

    /**
     * @brief Inserts a resource with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume of the resource.
     *
     * @return True on success, false otherwise.
     */
    virtual void insertRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        std::string                     const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Deletes a resource with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     *
     * @return True on success, false otherwise.
     */
    virtual void deleteRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        std::string                     const & a_key
    ) const = 0;

    /**
     * @brief Gets a resource with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     *
     * @return The resource with volume record, null if not found.
     */
    virtual ResourceWithVolumeRecordShrPtr getRecord(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        std::string                     const & a_key
    ) const = 0;

    /**
     * @brief Gets resource with volume records.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of resource with volume records, an empty map if not found.
     */
    virtual ResourceWithVolumeRecordMap getRecords(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const = 0;

    /**
     * @brief Increases the volume of resource with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume to be increased.
     *
     * @return True on success, false otherwise.
     */
    virtual void increaseVolume(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        std::string                     const & a_key,
        Volume                          const & a_volume
    ) const = 0;

    /**
     * @brief Decreases the volume of resource with volume record.
     *
     * @param a_transaction A transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume to be decreased.
     *
     * @return True on success, false otherwise.
     */
    virtual void decreaseVolume(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        std::string                     const & a_key,
        Volume                          const & a_volume
    ) const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<IResourceAccessor> IResourceAccessorAutPtr;
typedef boost::scoped_ptr<IResourceAccessor> IResourceAccessorScpPtr;
//}@

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_IRESOURCEACCESSOR_HPP
