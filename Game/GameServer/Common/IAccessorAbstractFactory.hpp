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

#ifndef GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP
#define GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP

#include <Game/GameServer/Achievement/IAchievementAccessor.hpp>
#include <Game/GameServer/Authentication/IAuthenticationAccessor.hpp>
#include <Game/GameServer/Authorization/IAuthorizationAccessor.hpp>
#include <Game/GameServer/Building/IBuildingAccessor.hpp>
#include <Game/GameServer/Epoch/IEpochAccessor.hpp>
#include <Game/GameServer/Human/IHumanAccessor.hpp>
#include <Game/GameServer/Land/ILandAccessor.hpp>
#include <Game/GameServer/Resource/IResourceAccessor.hpp>
#include <Game/GameServer/Settlement/ISettlementAccessor.hpp>
#include <Game/GameServer/User/IUserAccessor.hpp>
#include <Game/GameServer/World/IWorldAccessor.hpp>
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Common
{

/**
 * @brief The interface of AccessorAbstractFactory.
 */
class IAccessorAbstractFactory
{
public:
    virtual ~IAccessorAbstractFactory(){}

    //@{
    /**
     * @brief Creates an accessor.
     *
     * @return The newly created accessor.
     */
    virtual Achievement::IAchievementAccessorAutPtr       createAchievementAccessor()    const = 0;
    virtual Authentication::IAuthenticationAccessorAutPtr createAuthenticationAccessor() const = 0;
    virtual Authorization::IAuthorizationAccessorAutPtr   createAuthorizationAccessor()  const = 0;
    virtual Building::IBuildingAccessorAutPtr             createBuildingAccessor()       const = 0;
    virtual Epoch::IEpochAccessorAutPtr                   createEpochAccessor()          const = 0;
    virtual Human::IHumanAccessorAutPtr                   createHumanAccessor()          const = 0;
    virtual Land::ILandAccessorAutPtr                     createLandAccessor()           const = 0;
    virtual Resource::IResourceAccessorAutPtr             createResourceAccessor()       const = 0;
    virtual Settlement::ISettlementAccessorAutPtr         createSettlementAccessor()     const = 0;
    virtual User::IUserAccessorAutPtr                     createUserAccessor()           const = 0;
    virtual World::IWorldAccessorAutPtr                   createWorldAccessor()          const = 0;
    //}@
};

/**
 * @brief Typedef of shared pointer.
 */
typedef boost::shared_ptr<IAccessorAbstractFactory> IAccessorAbstractFactoryShrPtr;

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP