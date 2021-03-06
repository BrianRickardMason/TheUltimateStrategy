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

#include <Game/GameServer/Epoch/Operators/FinishEpoch/FinishEpochOperator.hpp>

using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::World;
using namespace std;

namespace GameServer
{
namespace Epoch
{

FinishEpochOperator::FinishEpochOperator(
    IEpochPersistenceFacadeShrPtr a_epoch_persistence_facade,
    ILandPersistenceFacadeShrPtr  a_land_persistence_facade,
    IWorldPersistenceFacadeShrPtr a_world_persistence_facade
)
    : m_epoch_persistence_facade(a_epoch_persistence_facade),
      m_land_persistence_facade(a_land_persistence_facade),
      m_world_persistence_facade(a_world_persistence_facade)
{
}

FinishEpochOperatorExitCode FinishEpochOperator::finishEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    try
    {
        // Verify if the world exists.
        if (!m_world_persistence_facade->getWorld(a_transaction, a_world_name))
        {
            return FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST);
        }

        // Verify if the epoch exists.
        IEpochShrPtr epoch = m_epoch_persistence_facade->getEpoch(a_transaction, a_world_name);

        if (!epoch)
        {
            return FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_DOES_NOT_EXIST);
        }

        // Verify if the epoch has been finished.
        if (epoch->getFinished())
        {
            return FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY);
        }

        // Verify if the epoch is active.
        if (epoch->getActive())
        {
            return FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_IS_ACTIVE);
        }

        bool const result_delete_lands = m_land_persistence_facade->deleteLands(a_transaction, a_world_name);

        bool const result_finish_epoch = m_epoch_persistence_facade->finishEpoch(a_transaction, a_world_name);

        return (result_delete_lands and result_finish_epoch)
               ? FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED)
               : FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_FINISHED);
    }
    catch (...)
    {
        return FinishEpochOperatorExitCode(FINISH_EPOCH_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Epoch
} // namespace GameServer
