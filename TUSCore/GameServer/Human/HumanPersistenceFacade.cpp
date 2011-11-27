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

#include <GameServer/Human/HumanPersistenceFacade.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace boost;

namespace GameServer
{
namespace Human
{

HumanPersistenceFacade::HumanPersistenceFacade(
    IContextShrPtr       const a_context,
    IHumanAccessorAutPtr       a_accessor
)
    : m_context(a_context),
      m_accessor(a_accessor)
{
}

void HumanPersistenceFacade::addHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IHumanKey          const & a_key,
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

bool HumanPersistenceFacade::subtractHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IHumanKey          const & a_key,
    Volume             const & a_volume
) const
{
    if (HumanWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key))
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

HumanWithVolumeShrPtr HumanPersistenceFacade::getHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IHumanKey          const & a_key
) const
{
    HumanWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key);

    return record ? make_shared<HumanWithVolume>(m_context, *record) : HumanWithVolumeShrPtr();
}

HumanWithVolumeMap HumanPersistenceFacade::getHumans(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder
) const
{
    return prepareResultGetHumans(m_accessor->getRecords(a_transaction, a_id_holder));
}

HumanWithVolumeMap HumanPersistenceFacade::prepareResultGetHumans(
    HumanWithVolumeRecordMap const & a_records
) const
{
    HumanWithVolumeMap result;

    for (HumanWithVolumeRecordMap::const_iterator it = a_records.begin(); it != a_records.end(); ++it)
    {
        // Verify if pointer is not null.
        if (it->second)
        {
            HumanWithVolumeShrPtr human = make_shared<HumanWithVolume>(m_context, *it->second);
            HumanWithVolumePair pair(it->first, human);
            result.insert(pair);
        }
        // Logic error: a null pointer in the map.
        else
        {
            BOOST_ASSERT(false);
        }
    }

    return result;
}

} // namespace Human
} // namespace GameServer
