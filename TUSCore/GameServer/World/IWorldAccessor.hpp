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

#ifndef GAMESERVER_WORLD_IWORLDACCESSOR_HPP
#define GAMESERVER_WORLD_IWORLDACCESSOR_HPP

#include "../Persistence/ITransaction.hpp"
#include "IWorldRecord.hpp"
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>
#include <string>

namespace GameServer
{
namespace World
{

/**
 * @brief The interface of the world accessor.
 */
class IWorldAccessor
    : boost::noncopyable
{
public:
    virtual ~IWorldAccessor(){};

    /**
     * @brief Inserts a world record.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     */
    virtual void insertRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets a world record.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The world record, null if not found.
     */
    virtual IWorldRecordShrPtr getRecord(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const = 0;

    /**
     * @brief Gets world records.
     *
     * @param a_transaction The transaction.
     *
     * @return A map of world records, an empty map if not found.
     */
    virtual IWorldRecordMap getRecords(
        Persistence::ITransactionShrPtr a_transaction
    ) const = 0;

    /**
     * @brief Gets the name of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_land_name   The name of the land.
     *
     * @return The name of the world, an empty string if not found.
     */
    virtual std::string getWorldNameOfLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_land_name
    ) const = 0;
};

/**
 * @brief Typedef of auto pointer.
 */
typedef std::auto_ptr<IWorldAccessor> IWorldAccessorAutPtr;

/**
 * @brief Typedef of scoped pointer.
 */
typedef boost::scoped_ptr<IWorldAccessor> IWorldAccessorScpPtr;

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_IWORLDACCESSOR_HPP
