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

#include "../Authentication/AuthenticationPersistencyFacadeFactory.hpp"
#include "../Authorization/AuthorizationManagerFactory.hpp"
#include "../Building/BuildingManagerFactory.hpp"
#include "../Cost/CostManagerFactory.hpp"
#include "../Epoch/EpochManagerFactory.hpp"
#include "../Human/HumanManagerFactory.hpp"
#include "../Land/LandManagerFactory.hpp"
#include "../Property/PropertyManagerFactory.hpp"
#include "../Resource/ResourceManagerFactory.hpp"
#include "../Settlement/SettlementManagerFactory.hpp"
#include "../User/UserManagerFactory.hpp"
#include "../World/WorldManagerFactory.hpp"
#include "AccessorAbstractFactoryPostgresql.hpp"
#include "ManagerAbstractFactoryPostgresql.hpp"

using namespace GameServer::Authentication;
using namespace GameServer::Authorization;
using namespace GameServer::Building;
using namespace GameServer::Cost;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Property;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;

namespace GameServer
{
namespace Common
{

ManagerAbstractFactoryPostgresql::ManagerAbstractFactoryPostgresql()
    : m_accessor_abstract_factory(new AccessorAbstractFactoryPostgresql)
{
}

IAuthenticationPersistencyFacadeShrPtr ManagerAbstractFactoryPostgresql::createAuthenticationPersistencyFacade() const
{
    return IAuthenticationPersistencyFacadeShrPtr(
               AuthenticationPersistencyFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IAuthorizationManagerShrPtr ManagerAbstractFactoryPostgresql::createAuthorizationManager() const
{
    return IAuthorizationManagerShrPtr(AuthorizationManagerFactory::createAuthorizationManager(m_accessor_abstract_factory));
}

IBuildingManagerShrPtr ManagerAbstractFactoryPostgresql::createBuildingManager() const
{
    return IBuildingManagerShrPtr(BuildingManagerFactory::createBuildingManager(m_accessor_abstract_factory));
}

ICostManagerShrPtr ManagerAbstractFactoryPostgresql::createCostManager() const
{
    return ICostManagerShrPtr(CostManagerFactory::createCostManager(m_accessor_abstract_factory));
}

IEpochManagerShrPtr ManagerAbstractFactoryPostgresql::createEpochManager() const
{
    return IEpochManagerShrPtr(EpochManagerFactory::createEpochManager(m_accessor_abstract_factory));
}

IHumanManagerShrPtr ManagerAbstractFactoryPostgresql::createHumanManager() const
{
    return IHumanManagerShrPtr(HumanManagerFactory::createHumanManager(m_accessor_abstract_factory));
}

ILandManagerShrPtr ManagerAbstractFactoryPostgresql::createLandManager() const
{
    return ILandManagerShrPtr(LandManagerFactory::createLandManager(m_accessor_abstract_factory));
}

IPropertyManagerShrPtr ManagerAbstractFactoryPostgresql::createPropertyManager() const
{
    return IPropertyManagerShrPtr(PropertyManagerFactory::createPropertyManager(m_accessor_abstract_factory));
}

IResourceManagerShrPtr ManagerAbstractFactoryPostgresql::createResourceManager() const
{
    return IResourceManagerShrPtr(ResourceManagerFactory::createResourceManager(m_accessor_abstract_factory));
}

ISettlementManagerShrPtr ManagerAbstractFactoryPostgresql::createSettlementManager() const
{
    return ISettlementManagerShrPtr(SettlementManagerFactory::createSettlementManager(m_accessor_abstract_factory));
}

IUserManagerShrPtr ManagerAbstractFactoryPostgresql::createUserManager() const
{
    return IUserManagerShrPtr(UserManagerFactory::createUserManager(m_accessor_abstract_factory));
}

IWorldManagerShrPtr ManagerAbstractFactoryPostgresql::createWorldManager() const
{
    return IWorldManagerShrPtr(WorldManagerFactory::createWorldManager(m_accessor_abstract_factory));
}

} // namespace Common
} // namespace GameServer
