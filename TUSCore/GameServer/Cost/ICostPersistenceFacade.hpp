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

#ifndef GAMESERVER_COST_ICOSTPERSISTENCEFACADE_HPP
#define GAMESERVER_COST_ICOSTPERSISTENCEFACADE_HPP

#include "../Persistence/ITransaction.hpp"
#include "../Resource/ResourceSet.hpp"
#include "IDCostType.hpp"
#include <GameServer/Common/KeyHash.hpp>
#include <boost/noncopyable.hpp>
#include <string>

namespace GameServer
{
namespace Cost
{

/**
 * @brief An interface of cost persistence facade.
 */
class ICostPersistenceFacade
    : boost::noncopyable
{
public:
    virtual ~ICostPersistenceFacade(){};

    /**
     * @brief Gets the cost.
     *
     * @param a_transaction  The transaction.
     * @param a_key          A key.
     * @param a_id_cost_type An identifier of the cost type.
     *
     * @return The cost.
     */
    virtual Resource::ResourceSet getCost(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const & a_key,
        IDCostType                      const & a_id_cost_type
    ) const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<ICostPersistenceFacade> ICostPersistenceFacadeShrPtr;

} // namespace Cost
} // namespace GameServer

#endif // GAMESERVER_COST_ICOSTPERSISTENCEFACADE_HPP
