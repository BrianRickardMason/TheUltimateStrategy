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

#ifndef GAMESERVER_LAND_ICREATELANDOPERATOR_HPP
#define GAMESERVER_LAND_ICREATELANDOPERATOR_HPP

#include "../../../Epoch/IDEpoch.hpp"
#include "../../../Persistency/ITransaction.hpp"
#include "../../../World/IDWorld.hpp"
#include "CreateLandOperatorExitCode.hpp"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

namespace GameServer
{
namespace Land
{

/**
 * @brief The interface of CreateLandOperator.
 */
class ICreateLandOperator
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs CreateLandOperator.
     */
    virtual ~ICreateLandOperator(){};

    /**
     * @brief Creates a land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_id_world    The identifier of the world.
     * @param a_id_epoch    The identifier of the epoch.
     * @param a_name        The name of the land.
     *
     * @return The exit code.
     */
    virtual CreateLandOperatorExitCode createLand(
        Persistency::ITransactionShrPtr         a_transaction,
        std::string                     const   a_login,
        World::IDWorld                  const & a_id_world,
        Epoch::IDEpoch                  const & a_id_epoch,
        std::string                     const & a_name
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of CreateLandOperator.
 */
typedef boost::shared_ptr<ICreateLandOperator> ICreateLandOperatorShrPtr;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_ICREATELANDOPERATOR_HPP
