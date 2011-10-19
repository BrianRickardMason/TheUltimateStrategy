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

#ifndef GAMESERVER_EPOCH_TICKEPOCHOPERATOR_HPP
#define GAMESERVER_EPOCH_TICKEPOCHOPERATOR_HPP

#include <GameServer/Epoch/IEpochPersistenceFacade.hpp>
#include <GameServer/Epoch/Operators/TickEpoch/ITickEpochOperator.hpp>
#include <GameServer/Turn/Managers/ITurnManager.hpp>
#include <GameServer/World/IWorldPersistenceFacade.hpp>

namespace GameServer
{
namespace Epoch
{

/**
 * @brief TickEpochOperator.
 */
class TickEpochOperator
    : public ITickEpochOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_epoch_persistence_facade The permission facade of epochs.
     * @param a_world_persistence_facade The persistence facade of worlds.
     * @param a_turn_manager             The manager of turns.
     */
    TickEpochOperator(
        IEpochPersistenceFacadeShrPtr        a_epoch_persistence_facade,
        World::IWorldPersistenceFacadeShrPtr a_world_persistence_facade,
        Turn::ITurnManagerShrPtr             a_turn_manager
    );

    /**
     * @brief Ticks an epoch.
     *
     * @param a_transaction The transaction.
     * @param a_world_name  The name of the world.
     *
     * @return The exit code.
     */
    virtual TickEpochOperatorExitCode tickEpoch(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_world_name
    );

private:
    /**
     * @brief The persistence facade of epochs.
     */
    IEpochPersistenceFacadeShrPtr m_epoch_persistence_facade;

    /**
     * @brief The persistence facade of worlds.
     */
    World::IWorldPersistenceFacadeShrPtr m_world_persistence_facade;

    /**
     * @brief TurnManager.
     */
    Turn::ITurnManagerShrPtr m_turn_manager;
};

/**
 * @brief Typedef of auto pointer.
 */
typedef std::auto_ptr<TickEpochOperator> TickEpochOperatorAutPtr;

} // namespace Epoch
} // namespace GameServer

#endif // GAMESERVER_EPOCH_TICKEPOCHOPERATOR_HPP
