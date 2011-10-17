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

#include "../Authentication/AuthenticationPersistenceFacadeFactory.hpp"
#include "../Authorization/AuthorizationPersistenceFacadeFactory.hpp"
#include "../Building/BuildingPersistenceFacadeFactory.hpp"
#include "../Cost/CostManagerFactory.hpp"
#include "../Epoch/EpochPersistenceFacadeFactory.hpp"
#include "../Human/HumanManagerFactory.hpp"
#include "../Land/LandPersistenceFacadeFactory.hpp"
#include "../Property/PropertyManagerFactory.hpp"
#include "../Resource/ResourceManagerFactory.hpp"
#include "../Settlement/SettlementPersistenceFacadeFactory.hpp"
#include "../User/UserPersistenceFacadeFactory.hpp"
#include "../World/WorldPersistenceFacadeFactory.hpp"
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

IAuthenticationPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createAuthenticationPersistenceFacade() const
{
    return IAuthenticationPersistenceFacadeShrPtr(
               AuthenticationPersistenceFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IAuthorizationPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createAuthorizationPersistenceFacade() const
{
    return IAuthorizationPersistenceFacadeShrPtr(
               AuthorizationPersistenceFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IBuildingPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createBuildingPersistenceFacade() const
{
    return IBuildingPersistenceFacadeShrPtr(BuildingPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

ICostManagerShrPtr ManagerAbstractFactoryPostgresql::createCostManager() const
{
    return ICostManagerShrPtr(CostManagerFactory::createCostManager(m_accessor_abstract_factory));
}

IEpochPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createEpochPersistenceFacade() const
{
    return IEpochPersistenceFacadeShrPtr(EpochPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IHumanManagerShrPtr ManagerAbstractFactoryPostgresql::createHumanManager() const
{
    return IHumanManagerShrPtr(HumanManagerFactory::createHumanManager(m_accessor_abstract_factory));
}

ILandPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createLandPersistenceFacade() const
{
    return ILandPersistenceFacadeShrPtr(LandPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IPropertyManagerShrPtr ManagerAbstractFactoryPostgresql::createPropertyManager() const
{
    return IPropertyManagerShrPtr(PropertyManagerFactory::createPropertyManager(m_accessor_abstract_factory));
}

IResourceManagerShrPtr ManagerAbstractFactoryPostgresql::createResourceManager() const
{
    return IResourceManagerShrPtr(ResourceManagerFactory::createResourceManager(m_accessor_abstract_factory));
}

ISettlementPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createSettlementPersistenceFacade() const
{
    return ISettlementPersistenceFacadeShrPtr(SettlementPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IUserPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createUserPersistenceFacade() const
{
    return IUserPersistenceFacadeShrPtr(UserPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IWorldPersistenceFacadeShrPtr ManagerAbstractFactoryPostgresql::createWorldPersistenceFacade() const
{
    return IWorldPersistenceFacadeShrPtr(WorldPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

} // namespace Common
} // namespace GameServer
