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

#ifndef GAMESERVER_HUMAN_IGETHUMANOPERATOR_HPP
#define GAMESERVER_HUMAN_IGETHUMANOPERATOR_HPP

#include "../../../Common/IDHolder.hpp"
#include "../../../Persistence/ITransaction.hpp"
#include "../../Key.hpp"
#include "GetHumanOperatorExitCode.hpp"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Human
{

/**
 * @brief The interface of GetHumanOperator.
 */
class IGetHumanOperator
    : boost::noncopyable
{
public:
    virtual ~IGetHumanOperator(){};

    /**
     * @brief Gets a human.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the human.
     *
     * @return The exit code.
     */
    virtual GetHumanOperatorExitCode getHuman(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of GetHumanOperator.
 */
typedef boost::shared_ptr<IGetHumanOperator> IGetHumanOperatorShrPtr;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_IGETHUMANOPERATOR_HPP
