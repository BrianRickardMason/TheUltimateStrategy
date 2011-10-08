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

#include "../Authentication/AuthenticationManagerAccessorPostgresql.hpp"
#include "../Authorization/AuthorizationManagerAccessorPostgresql.hpp"
#include "../Building/BuildingManagerAccessorPostgresql.hpp"
#include "../Cost/CostManagerAccessorPostgresql.hpp"
#include "../Epoch/EpochManagerAccessorPostgresql.hpp"
#include "../Human/HumanManagerAccessorPostgresql.hpp"
#include "../Land/LandManagerAccessorPostgresql.hpp"
#include "../Property/PropertyManagerAccessorPostgresql.hpp"
#include "../Resource/ResourceManagerAccessorPostgresql.hpp"
#include "../Settlement/SettlementManagerAccessorPostgresql.hpp"
#include "../User/UserManagerAccessorPostgresql.hpp"
#include "../World/WorldManagerAccessorPostgresql.hpp"
#include "AccessorAbstractFactoryPostgresql.hpp"

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

IAuthenticationManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createAuthenticationAccessor() const
{
    return IAuthenticationManagerAccessorAutPtr(new AuthenticationManagerAccessorPostgresql);
}

IAuthorizationManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createAuthorizationAccessor() const
{
    return IAuthorizationManagerAccessorAutPtr(new AuthorizationManagerAccessorPostgresql);
}

IBuildingManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createBuildingAccessor() const
{
    return IBuildingManagerAccessorAutPtr(new BuildingManagerAccessorPostgresql);
}

ICostManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createCostAccessor() const
{
    return ICostManagerAccessorAutPtr(new CostManagerAccessorPostgresql);
}

IEpochManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createEpochAccessor() const
{
    return IEpochManagerAccessorAutPtr(new EpochManagerAccessorPostgresql);
}

IHumanManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createHumanAccessor() const
{
    return IHumanManagerAccessorAutPtr(new HumanManagerAccessorPostgresql);
}

ILandManagerAccessorAutPtr AccessorAbstractFactoryPostgresql::createLandAccessor() const
{
    return ILandManagerAccessorAutPtr(new LandManagerAccessorPostgresql);
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