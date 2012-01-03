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

#include <Game/GameServer/Resource/ResourcePersistenceFacade.hpp>

using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace boost;
using namespace std;

namespace GameServer
{
namespace Resource
{

ResourcePersistenceFacade::ResourcePersistenceFacade(
    IContextShrPtr          const a_context,
    IResourceAccessorAutPtr       a_accessor
)
    : m_context(a_context),
      m_accessor(a_accessor)
{
}

void ResourcePersistenceFacade::addResource(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    string             const & a_key,
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

bool ResourcePersistenceFacade::subtractResource(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    string             const & a_key,
    Volume             const & a_volume
) const
{
    if (a_volume == 0)
    {
        return true;
    }

    if (ResourceWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key))
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

void ResourcePersistenceFacade::subtractResourceSafely(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    string             const & a_key,
    Volume             const & a_volume
) const
{
    if (a_volume == 0)
    {
        return;
    }

    if (ResourceWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key))
    {
        if (record->getVolume() > a_volume)
        {
            m_accessor->decreaseVolume(a_transaction, a_id_holder, a_key, a_volume);
        }
        else
        {
            m_accessor->deleteRecord(a_transaction, a_id_holder, a_key);
        }
    }
}

bool ResourcePersistenceFacade::subtractResources(
    ITransactionShrPtr            a_transaction,
    IDHolder              const & a_id_holder,
    ResourceWithVolumeMap const & a_resource_map
) const
{
    for (ResourceWithVolumeMap::const_iterator it = a_resource_map.begin(); it != a_resource_map.end(); ++it)
    {
        // TODO: Envious class.
        bool result =
            subtractResource(a_transaction, a_id_holder, it->second->getResource()->getKey(), it->second->getVolume());

        if (!result)
        {
            return false;
        }
    }

    return true;
}

void ResourcePersistenceFacade::subtractResourcesSafely(
    ITransactionShrPtr            a_transaction,
    IDHolder              const & a_id_holder,
    ResourceWithVolumeMap const & a_resource_map
) const
{
    for (ResourceWithVolumeMap::const_iterator it = a_resource_map.begin(); it != a_resource_map.end(); ++it)
    {
        // TODO: Envious class.
        subtractResourceSafely(a_transaction, a_id_holder, it->second->getResource()->getKey(), it->second->getVolume());
    }
}

ResourceWithVolumeShrPtr ResourcePersistenceFacade::getResource(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    string             const & a_key
) const
{
    ResourceWithVolumeRecordShrPtr record = m_accessor->getRecord(a_transaction, a_id_holder, a_key);

    return record ? make_shared<ResourceWithVolume>(m_context, *record) : ResourceWithVolumeShrPtr();
}

ResourceWithVolumeMap ResourcePersistenceFacade::getResources(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder
) const
{
    ResourceWithVolumeMap resource_map;

    ResourceWithVolumeRecordMap records = m_accessor->getRecords(a_transaction, a_id_holder);

    for (ResourceWithVolumeRecordMap::iterator it = records.begin(); it != records.end(); ++it)
    {

        if (it->second)
        {

            ResourceWithVolumeShrPtr resource = make_shared<ResourceWithVolume>(m_context, *it->second);
            ResourceWithVolumePair pair(it->first, resource);
            resource_map.insert(pair);
        }
    }

    return resource_map;
}

} // namespace Resource
} // namespace GameServer
