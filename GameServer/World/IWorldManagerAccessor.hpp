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

#ifndef GAMESERVER_WORLD_IWORLDMANAGERACCESSOR_HPP
#define GAMESERVER_WORLD_IWORLDMANAGERACCESSOR_HPP

#include "../Land/IDLand.hpp"
#include "../Persistency/ITransaction.hpp"
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
 * @brief The interface of the world manager accessor.
 */
class IWorldManagerAccessor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the accessor.
     */
    virtual ~IWorldManagerAccessor(){};

    /**
     * @brief Inserts a world record.
     *
     * @param a_transaction The transaction.
     * @param a_name        The name of the world.
     */
    virtual void insertRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const & a_name
    ) const = 0;

    /**
     * @brief Gets a world record by an identifier of the world.
     *
     * @param a_transaction A transaction.
     * @param a_id_world    The identifier of the world.
     *
     * @return The world record, null if not found.
     */
    virtual IWorldRecordShrPtr getRecord(
        Persistency::ITransactionShrPtr         a_transaction,
        IDWorld                         const & a_id_world
    ) const = 0;

    /**
     * @brief Gets world records.
     *
     * @param a_transaction A transaction.
     *
     * @return A map of world records, an empty map if not found.
     */
    virtual IWorldRecordMap getRecords(
        Persistency::ITransactionShrPtr a_transaction
    ) const = 0;

    /**
     * @brief Gets the identifier of the world of the land.
     *
     * @param a_transaction The transaction.
     * @param a_id_land     The identifier of the land.
     *
     * @return The identifier of the world, 0 if not found.
     */
    virtual IDWorld getIDWorldOfLand(
        Persistency::ITransactionShrPtr         a_transaction,
        Land::IDLand                    const & a_id_land
    ) const = 0;
};

/**
 * @brief An auto pointer of interface of world manager accessor.
 */
typedef std::auto_ptr<IWorldManagerAccessor> IWorldManagerAccessorAutPtr;

/**
 * @brief A scoped pointer of interface of world manager accessor.
 */
typedef boost::scoped_ptr<IWorldManagerAccessor> IWorldManagerAccessorScpPtr;

} // namespace World
} // namespace GameServer

#endif // GAMESERVER_WORLD_IWORLDMANAGERACCESSOR_HPP
