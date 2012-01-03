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

#include <Game/GameServer/Achievement/AchievementPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Authentication/AuthenticationPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Authorization/AuthorizationPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Building/BuildingPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Common/AccessorAbstractFactoryPostgresql.hpp>
#include <Game/GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp>
#include <Game/GameServer/Epoch/EpochPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Human/HumanPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Land/LandPersistenceFacadeFactory.hpp>
#include <Game/GameServer/Resource/ResourcePersistenceFacadeFactory.hpp>
#include <Game/GameServer/Settlement/SettlementPersistenceFacadeFactory.hpp>
#include <Game/GameServer/User/UserPersistenceFacadeFactory.hpp>
#include <Game/GameServer/World/WorldPersistenceFacadeFactory.hpp>

using namespace GameServer::Achievement;
using namespace GameServer::Authentication;
using namespace GameServer::Authorization;
using namespace GameServer::Building;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::User;
using namespace GameServer::World;

namespace GameServer
{
namespace Common
{

PersistenceFacadeAbstractFactoryPostgresql::PersistenceFacadeAbstractFactoryPostgresql(
    IContextShrPtr const a_context
)
    : m_context(a_context),
      m_accessor_abstract_factory(new AccessorAbstractFactoryPostgresql)
{
}

IAchievementPersistenceFacadeShrPtr
PersistenceFacadeAbstractFactoryPostgresql::createAchievementPersistenceFacade() const
{
    return IAchievementPersistenceFacadeShrPtr(
               AchievementPersistenceFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IAuthenticationPersistenceFacadeShrPtr
PersistenceFacadeAbstractFactoryPostgresql::createAuthenticationPersistenceFacade() const
{
    return IAuthenticationPersistenceFacadeShrPtr(
               AuthenticationPersistenceFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IAuthorizationPersistenceFacadeShrPtr
PersistenceFacadeAbstractFactoryPostgresql::createAuthorizationPersistenceFacade() const
{
    return IAuthorizationPersistenceFacadeShrPtr(
               AuthorizationPersistenceFacadeFactory::create(m_accessor_abstract_factory)
           );
}

IBuildingPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createBuildingPersistenceFacade() const
{
    return IBuildingPersistenceFacadeShrPtr(
                BuildingPersistenceFacadeFactory::create(m_context, m_accessor_abstract_factory)
           );
}

IEpochPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createEpochPersistenceFacade() const
{
    return IEpochPersistenceFacadeShrPtr(EpochPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IHumanPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createHumanPersistenceFacade() const
{
    return IHumanPersistenceFacadeShrPtr(
               HumanPersistenceFacadeFactory::create(m_context, m_accessor_abstract_factory)
           );
}

ILandPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createLandPersistenceFacade() const
{
    return ILandPersistenceFacadeShrPtr(LandPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IResourcePersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createResourcePersistenceFacade() const
{
    return IResourcePersistenceFacadeShrPtr(
               ResourcePersistenceFacadeFactory::create(m_context, m_accessor_abstract_factory)
           );
}

ISettlementPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createSettlementPersistenceFacade() const
{
    return ISettlementPersistenceFacadeShrPtr(SettlementPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IUserPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createUserPersistenceFacade() const
{
    return IUserPersistenceFacadeShrPtr(UserPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

IWorldPersistenceFacadeShrPtr PersistenceFacadeAbstractFactoryPostgresql::createWorldPersistenceFacade() const
{
    return IWorldPersistenceFacadeShrPtr(WorldPersistenceFacadeFactory::create(m_accessor_abstract_factory));
}

} // namespace Common
} // namespace GameServer
