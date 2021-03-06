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

#include <Game/GameServer/Epoch/EpochPersistenceFacade.hpp>

using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Epoch
{

EpochPersistenceFacade::EpochPersistenceFacade(
    IEpochAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

bool EpochPersistenceFacade::createEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name,
    string             const a_epoch_name
) const
{
    try
    {
        m_accessor->insertRecord(a_transaction, a_world_name, a_epoch_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool EpochPersistenceFacade::deleteEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochShrPtr epoch = getEpoch(a_transaction, a_world_name);

    if (!epoch)
    {
        return false;
    }

    if (!epoch->getFinished())
    {
        return false;
    }

    try
    {
        m_accessor->deleteRecord(a_transaction, a_world_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

IEpochShrPtr EpochPersistenceFacade::getEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochRecordShrPtr record = m_accessor->getRecord(a_transaction, a_world_name);

    return record ? IEpochShrPtr(new Epoch(record)) : IEpochShrPtr();
}

IEpochShrPtr EpochPersistenceFacade::getEpochByLandName(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    string world_name = m_accessor->getWorldNameOfLand(a_transaction, a_land_name);

    return getEpoch(a_transaction, world_name);
}

IEpochShrPtr EpochPersistenceFacade::getEpochBySettlementName(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    string land_name = m_accessor->getLandNameOfSettlement(a_transaction, a_settlement_name);

    return getEpochByLandName(a_transaction, land_name);
}

bool EpochPersistenceFacade::activateEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochShrPtr epoch = getEpoch(a_transaction, a_world_name);

    if (!epoch)
    {
        return false;
    }

    if (epoch->getFinished())
    {
        return false;
    }

    if (epoch->getActive())
    {
        return false;
    }

    try
    {
        m_accessor->markActive(a_transaction, a_world_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool EpochPersistenceFacade::deactivateEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochShrPtr epoch = getEpoch(a_transaction, a_world_name);

    if (!epoch)
    {
        return false;
    }

    if (epoch->getFinished())
    {
        return false;
    }

    if (!epoch->getActive())
    {
        return false;
    }

    try
    {
        m_accessor->markUnactive(a_transaction, a_world_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool EpochPersistenceFacade::finishEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochShrPtr epoch = getEpoch(a_transaction, a_world_name);

    if (!epoch)
    {
        return false;
    }

    if (epoch->getFinished())
    {
        return false;
    }

    if (epoch->getActive())
    {
        return false;
    }

    try
    {
        m_accessor->markFinished(a_transaction, a_world_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool EpochPersistenceFacade::tickEpoch(
    ITransactionShrPtr       a_transaction,
    string             const a_world_name
) const
{
    IEpochShrPtr epoch = getEpoch(a_transaction, a_world_name);

    if (!epoch)
    {
        return false;
    }

    if (epoch->getFinished())
    {
        return false;
    }

    if (epoch->getActive())
    {
        return false;
    }

    try
    {
        m_accessor->incrementTicks(a_transaction, a_world_name);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

} // namespace Epoch
} // namespace GameServer
