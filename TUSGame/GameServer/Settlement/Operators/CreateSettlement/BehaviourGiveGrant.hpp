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

#ifndef GAMESERVER_SETTLEMENT_BEHAVIOURGIVEGRANT_HPP
#define GAMESERVER_SETTLEMENT_BEHAVIOURGIVEGRANT_HPP

#include <TUSGame/GameServer/Human/IHumanPersistenceFacade.hpp>
#include <TUSGame/GameServer/Resource/IResourcePersistenceFacade.hpp>
#include <TUSGame/GameServer/Settlement/Operators/CreateSettlement/IBehaviourGiveGrant.hpp>

namespace GameServer
{
namespace Settlement
{

/**
 * @brief BehaviourGiveGrant.
 */
class BehaviourGiveGrant
    : public IBehaviourGiveGrant
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_human_persistence_facade    The persistence facade of humans.
     * @param a_resource_persistence_facade The persistence facade of resources.
     */
    BehaviourGiveGrant(
        Human::IHumanPersistenceFacadeShrPtr       a_human_persistence_facade,
        Resource::IResourcePersistenceFacadeShrPtr a_resource_persistence_facade
    );

    /**
     * @brief Gives the grant to the settlement.
     *
     * @param a_transaction     The transaction.
     * @param a_settlement_name The name of the settlement.
     *
     * @return True on success, false otherwise.
     */
    virtual bool giveGrant(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_settlement_name
    ) const;

private:
    //@{
    /**
     * @brief Persistence facades.
     */
    Human::IHumanPersistenceFacadeShrPtr       m_human_persistence_facade;
    Resource::IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    //}@
};

/**
 * @brief The auto pointer of BehaviourGiveGrant.
 */
typedef std::auto_ptr<BehaviourGiveGrant> BehaviourGiveGrantAutPtr;

} // namespace Settlement
} // namespace GameServer

#endif // GAMESERVER_SETTLEMENT_BEHAVIOURGIVEGRANT_HPP
