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

#include "BehaviourGiveGrant.hpp"

using namespace GameServer::Common;
using namespace GameServer::Human;
using namespace GameServer::Persistency;
using namespace GameServer::Resource;
using namespace std;

namespace GameServer
{
namespace Settlement
{

BehaviourGiveGrant::BehaviourGiveGrant(
    IHumanManagerShrPtr    a_human_manager,
    IResourceManagerShrPtr a_resource_manager
)
    : m_human_manager(a_human_manager),
      m_resource_manager(a_resource_manager)
{
}

bool BehaviourGiveGrant::giveGrant(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    try
    {
        IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

        // Grant humans.
        m_human_manager->addHuman(a_transaction, id_holder, KEY_WORKER_JOBLESS_NOVICE, 1000);

        // Grant resources.
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_COAL), 1000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_FOOD), 10000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_GOLD), 10000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_IRON), 1000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_MANA), 1000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_ROCK), 1000);
        m_resource_manager->addResource(a_transaction, id_holder, Resource::Key(ID_RESOURCE_WOOD), 1000);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

} // namespace Settlement
} // namespace GameServer