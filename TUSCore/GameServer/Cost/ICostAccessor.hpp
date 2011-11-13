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

#ifndef GAMESERVER_COST_ICOSTACCESSOR_HPP
#define GAMESERVER_COST_ICOSTACCESSOR_HPP

#include "../Common/KeyHash.hpp"
#include "../Persistence/IPersistence.hpp"
#include "CostRecord.hpp"
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <memory>

namespace GameServer
{
namespace Cost
{

/**
 * @brief An interface of cost accessor.
 */
class ICostAccessor
    : boost::noncopyable
{
public:
    virtual ~ICostAccessor(){};

    /**
     * @brief Gets cost records.
     *
     * @param a_transaction  A transaction.
     * @param a_key_hash     A key hash.
     * @param a_id_cost_type An identifier of the type of the cost.
     *
     * @return A map of human with volume records, an empty map if not found.
     */
    virtual CostRecordVec getCosts(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::KeyHash                 const & a_key_hash,
        IDCostType                      const & a_id_cost_type
    ) const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<ICostAccessor> ICostAccessorAutPtr;
typedef boost::scoped_ptr<ICostAccessor> ICostAccessorScpPtr;
//}@

} // namespace Cost
} // namespace GameServer

#endif // GAMESERVER_COST_ICOSTACCESSOR_HPP
