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

#ifndef GAMESERVER_COMMON_ACCESSORABSTRACTFACTORYPOSTGRESQL_HPP
#define GAMESERVER_COMMON_ACCESSORABSTRACTFACTORYPOSTGRESQL_HPP

#include "IAccessorAbstractFactory.hpp"

namespace GameServer
{
namespace Common
{

/**
 * @brief The PostgreSQL AccessorAbstractFactory.
 */
class AccessorAbstractFactoryPostgresql
    : public IAccessorAbstractFactory
{
public:
    //@{
    /**
     * @brief Creates an accessor.
     *
     * @return The newly created accessor.
     */
    virtual Achievement::IAchievementAccessorAutPtr            createAchievementAccessor()    const;
    virtual Authentication::IAuthenticationAccessorAutPtr      createAuthenticationAccessor() const;
    virtual Authorization::IAuthorizationAccessorAutPtr        createAuthorizationAccessor()  const;
    virtual Building::IBuildingAccessorAutPtr                  createBuildingAccessor()       const;
    virtual Cost::ICostAccessorAutPtr                          createCostAccessor()           const;
    virtual Epoch::IEpochAccessorAutPtr                        createEpochAccessor()          const;
    virtual Human::IHumanManagerAccessorAutPtr                 createHumanAccessor()          const;
    virtual Land::ILandManagerAccessorAutPtr                   createLandAccessor()           const;
    virtual Property::IPropertyManagerAccessorAutPtr           createPropertyAccessor()       const;
    virtual Resource::IResourceManagerAccessorAutPtr           createResourceAccessor()       const;
    virtual Settlement::ISettlementManagerAccessorAutPtr       createSettlementAccessor()     const;
    virtual User::IUserManagerAccessorAutPtr                   createUserAccessor()           const;
    virtual World::IWorldManagerAccessorAutPtr                 createWorldAccessor()          const;
    //}@
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_ACCESSORABSTRACTFACTORYPOSTGRESQL_HPP
