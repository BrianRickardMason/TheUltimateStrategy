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

#include "TickEpochOperator.hpp"
#include "BehaviourTickEpochAbstractFactory.hpp"

using namespace GameServer::Persistency;
using namespace GameServer::World;
using namespace std;

namespace GameServer
{
namespace Epoch
{

TickEpochOperator::TickEpochOperator(
    IEpochManagerShrPtr a_epoch_manager,
    IWorldManagerShrPtr a_world_manager
)
    : m_epoch_manager(a_epoch_manager),
      m_world_manager(a_world_manager)
{
}

TickEpochOperatorExitCode TickEpochOperator::tickEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
)
{
    try
    {
        // Verify if the world exists.
    	IWorldShrPtr world = m_world_manager->getWorld(a_transaction, a_world_name);

        if (!world)
        {
            return TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST);
        }

        // Set the behaviour.
        m_behaviour_tick_epoch =
        	BehaviourTickEpochAbstractFactory::createBehaviourTickEpoch(m_epoch_manager, world);

        // Verify if the epoch exists.
        EpochShrPtr epoch = m_epoch_manager->getEpoch(a_transaction, a_world_name);

        if (!epoch)
        {
            return TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_EPOCH_DOES_NOT_EXIST);
        }

        // Verify if the epoch has been finished.
        if (epoch->getFinished())
        {
            return TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED);
        }

        // Verify if the epoch is active.
        if (epoch->getActive())
        {
            return TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_EPOCH_IS_ACTIVE);
        }

        bool const result = m_behaviour_tick_epoch->tickEpoch(a_transaction, world);

        return (result) ? TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_TACK)
                        : TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_TACK);
    }
    catch (...)
    {
        return TickEpochOperatorExitCode(TICK_EPOCH_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Epoch
} // namespace GameServer
