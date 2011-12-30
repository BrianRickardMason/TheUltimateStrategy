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

#ifndef GAMESERVER_EPOCH_ACTIVATEEPOCHOPERATOR_HPP
#define GAMESERVER_EPOCH_ACTIVATEEPOCHOPERATOR_HPP

#include <TUSGame/GameServer/World/IWorldPersistenceFacade.hpp>
#include <TUSGame/GameServer/Epoch/IEpochPersistenceFacade.hpp>
#include <TUSGame/GameServer/Epoch/Operators/ActivateEpoch/IActivateEpochOperator.hpp>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief ActivateEpochOperator.
 */
class ActivateEpochOperator
    : public IActivateEpochOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_epoch_persistence_facade The persistence facade of epochs.
     * @param a_world_persistence_facade The persistence facade of worlds.
     */
    ActivateEpochOperator(
        IEpochPersistenceFacadeShrPtr               a_epoch_persistence_facade,
        World::IWorldPersistenceFacadeShrPtr a_world_persistence_facade
    );

    /**
     * @brief Activates an epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The exit code.
     */
    virtual ActivateEpochOperatorExitCode activateEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    ) const;

private:
    /**
     * @brief The persistence facade of epochs.
     */
    IEpochPersistenceFacadeShrPtr        m_epoch_persistence_facade;

    /**
     * @brief The persistence facade of worlds.
     */
    World::IWorldPersistenceFacadeShrPtr m_world_persistence_facade;
};

/**
 * @brief The auto pointer of ActivateEpochOperator.
 */
typedef std::auto_ptr<ActivateEpochOperator> ActivateEpochOperatorAutPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_ACTIVATEEPOCHOPERATOR_HPP
