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

#include "../Achievement/AchievementAccessorPostgresql.hpp"
#include "../Authentication/AuthenticationAccessorPostgresql.hpp"
#include "../Authorization/AuthorizationAccessorPostgresql.hpp"
#include "../Building/BuildingAccessorPostgresql.hpp"
#include "../Cost/CostAccessorPostgresql.hpp"
#include "../Epoch/EpochAccessorPostgresql.hpp"
#include "../Human/HumanAccessorPostgresql.hpp"
#include "../Land/LandAccessorPostgresql.hpp"
#include "../Property/PropertyManagerAccessorPostgresql.hpp"
#include "../Resource/ResourceManagerAccessorPostgresql.hpp"
#include "../Settlement/SettlementManagerAccessorPostgresql.hpp"
#include "../User/UserManagerAccessorPostgresql.hpp"
#include "../World/WorldManagerAccessorPostgresql.hpp"
#include "AccessorAbstractFactoryPostgresql.hpp"

using namespace GameServer::Achievement;
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

IAchievementAccessorAutPtr AccessorAbstractFactoryPostgresql::createAchievementAccessor() const
{
    return IAchievementAccessorAutPtr(new AchievementAccessorPostgresql);
}

IAuthenticationAccessorAutPtr AccessorAbstractFactoryPostgresql::createAuthenticationAccessor() const
{
    return IAuthenticationAccessorAutPtr(new AuthenticationAccessorPostgresql);
}

IAuthorizationAccessorAutPtr AccessorAbstractFactoryPostgresql::createAuthorizationAccessor() const
{
    return IAuthorizationAccessorAutPtr(new AuthorizationAccessorPostgresql);
}

IBuildingAccessorAutPtr AccessorAbstractFactoryPostgresql::createBuildingAccessor() const
{
    return IBuildingAccessorAutPtr(new BuildingAccessorPostgresql);
}

ICostAccessorAutPtr AccessorAbstractFactoryPostgresql::createCostAccessor() const
{
    return ICostAccessorAutPtr(new CostAccessorPostgresql);
}

IEpochAccessorAutPtr AccessorAbstractFactoryPostgresql::createEpochAccessor() const
{
    return IEpochAccessorAutPtr(new EpochAccessorPostgresql);
}

IHumanAccessorAutPtr AccessorAbstractFactoryPostgresql::createHumanAccessor() const
{
    return IHumanAccessorAutPtr(new HumanAccessorPostgresql);
}

ILandAccessorAutPtr AccessorAbstractFactoryPostgresql::createLandAccessor() const
{
    return ILandAccessorAutPtr(new LandAccessorPostgresql);
}

IPropertyManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createPropertyAccessor() const
{
    return IPropertyManagerAccessorAutPtr(new PropertyManagerAccessorPostgresql);
}

IResourceManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createResourceAccessor() const
{
    return IResourceManagerAccessorAutPtr(new ResourceManagerAccessorPostgresql);
}

ISettlementManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createSettlementAccessor() const
{
    return ISettlementManagerAccessorAutPtr(new SettlementManagerAccessorPostgresql);
}

IUserManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createUserAccessor() const
{
    return IUserManagerAccessorAutPtr(new UserManagerAccessorPostgresql);
}

IWorldManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createWorldAccessor() const
{
    return IWorldManagerAccessorAutPtr(new WorldManagerAccessorPostgresql);
}

} // namespace Common
} // namespace GameServer
