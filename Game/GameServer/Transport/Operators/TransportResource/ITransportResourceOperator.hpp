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

#ifndef GAMESERVER_TRANSPORT_ITRANSPORTRESOURCEOPERATOR_HPP
#define GAMESERVER_TRANSPORT_ITRANSPORTRESOURCEOPERATOR_HPP

#include <Game/GameServer/Persistence/ITransaction.hpp>
//#include <Game/GameServer/Resource/Key.hpp>
#include <Game/GameServer/Resource/Volume.hpp>
#include <Game/GameServer/Transport/Operators/TransportResource/TransportResourceOperatorExitCode.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

namespace GameServer
{
namespace Transport
{

/**
 * @brief The interface of TransportResourceOperator.
 */
class ITransportResourceOperator
    : boost::noncopyable
{
public:
    virtual ~ITransportResourceOperator(){};

    /**
     * @brief Transports a resource from one settlement to another.
     *
     * @param a_transaction                 The transaction.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_key                         The key of the resource.
     * @param a_volume                      The volume of the resource.
     *
     * @returns The exit code.
     */
    virtual TransportResourceOperatorExitCode transportResource(
        Persistence::ITransactionShrPtr         a_transaction,
        std::string                     const   a_settlement_name_source,
        std::string                     const   a_settlement_name_destination,
        std::string                     const   a_key,
        Resource::Volume                const & a_volume
    ) const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<ITransportResourceOperator> ITransportResourceOperatorShrPtr;

} // namespace Transport
} // namespace GameServer

#endif // GAMESERVER_TRANSPORT_ITRANSPORTRESOURCEOPERATOR_HPP
