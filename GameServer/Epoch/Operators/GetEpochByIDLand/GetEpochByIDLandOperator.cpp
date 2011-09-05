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

#include "GetEpochByIDLandOperator.hpp"

using namespace GameServer::Land;
using namespace GameServer::Persistency;

namespace GameServer
{
namespace Epoch
{

GetEpochByIDLandOperator::GetEpochByIDLandOperator(
    IEpochManagerShrPtr a_epoch_manager,
    ILandManagerShrPtr  a_land_manager
)
    : m_epoch_manager(a_epoch_manager),
      m_land_manager(a_land_manager)
{
}

GetEpochByIDLandOperatorExitCode GetEpochByIDLandOperator::getEpochByIDLand(
    ITransactionShrPtr         a_transaction,
    IDLand             const & a_id_land
) const
{
    try
    {
        // Verify if the land exists.
        if (!m_land_manager->getLand(a_transaction, a_id_land))
        {
            return GetEpochByIDLandOperatorExitCode(GET_EPOCH_BY_IDLAND_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST);
        }

        EpochShrPtr const epoch = m_epoch_manager->getEpochByIDLand(a_transaction, a_id_land);

        return (epoch) ? GetEpochByIDLandOperatorExitCode(GET_EPOCH_BY_IDLAND_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_GOT, epoch)
                       : GetEpochByIDLandOperatorExitCode(GET_EPOCH_BY_IDLAND_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_GOT);
    }
    catch (...)
    {
        return GetEpochByIDLandOperatorExitCode(GET_EPOCH_BY_IDLAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Epoch
} // namespace GameServer
