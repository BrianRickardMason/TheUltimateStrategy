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

#ifndef GAMESERVER_RESOURCE_GETRESOURCESOPERATOR_HPP
#define GAMESERVER_RESOURCE_GETRESOURCESOPERATOR_HPP

#include <Game/GameServer/Resource/IResourcePersistenceFacade.hpp>
#include <Game/GameServer/Resource/Operators/GetResources/IGetResourcesOperator.hpp>

namespace GameServer
{
namespace Resource
{

/**
 * @brief GetResourcesOperator.
 */
class GetResourcesOperator
    : public IGetResourcesOperator
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_resource_persistence_facade The persistence facade of resources.
     */
    GetResourcesOperator(
        IResourcePersistenceFacadeShrPtr a_resource_persistence_facade
    );

    /**
     * @brief Gets resources.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     *
     * @return The exit code.
     */
    virtual GetResourcesOperatorExitCode getResources(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const;

private:
    /**
     * @brief Persistence facades.
     */
    IResourcePersistenceFacadeShrPtr m_resource_persistence_facades;
};

/**
 * @brief Typedef of auto pointer.
 */
typedef std::auto_ptr<GetResourcesOperator> GetResourcesOperatorAutPtr;

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_GETRESOURCESOPERATOR_HPP
