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

#include "BuildingManager.hpp"

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace boost;

namespace GameServer
{
namespace Building
{

BuildingManager::BuildingManager(
    IBuildingManagerAccessorAutPtr a_accessor
)
    : m_accessor(a_accessor)
{
}

void BuildingManager::addBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    if (m_accessor->getRecord(a_transaction, a_id_holder, a_key))
    {
        m_accessor->increaseVolume(a_transaction, a_id_holder, a_key, a_volume);
    }
    else
    {
        m_accessor->insertRecord(a_transaction, a_id_holder, a_key, a_volume);
    }
}

bool BuildingManager::subtractBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    if (BuildingWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key))
    {
        if (record->getVolume() > a_volume)
        {
            m_accessor->decreaseVolume(a_transaction, a_id_holder, a_key, a_volume);

            return true;
        }
        else if (record->getVolume() == a_volume)
        {
            m_accessor->deleteRecord(a_transaction, a_id_holder, a_key);

            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

BuildingWithVolumeShrPtr BuildingManager::getBuilding(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key
) const
{
    BuildingWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key);

    return record ? make_shared<BuildingWithVolume>(*record) : BuildingWithVolumeShrPtr();
}

BuildingWithVolumeMap BuildingManager::getBuildings(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder
) const
{
    BuildingWithVolumeMap result;

    BuildingWithVolumeRecordMap records = m_accessor->getRecords(a_transaction, a_id_holder);

    for (BuildingWithVolumeRecordMap::iterator it = records.begin(); it != records.end(); ++it)
    {
        if (it->second)
        {
            BuildingWithVolumeShrPtr building = make_shared<BuildingWithVolume>(*it->second);
            BuildingWithVolumePair pair(it->first, building);
            result.insert(pair);
        }
    }

    return result;
}

} // namespace Building
} // namespace GameServer
