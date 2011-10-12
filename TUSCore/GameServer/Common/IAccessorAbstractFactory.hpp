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

#ifndef GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP
#define GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP

#include "../Achievement/IAchievementAccessor.hpp"
#include "../Authentication/IAuthenticationManagerAccessor.hpp"
#include "../Authorization/IAuthorizationManagerAccessor.hpp"
#include "../Building/IBuildingManagerAccessor.hpp"
#include "../Cost/ICostManagerAccessor.hpp"
#include "../Epoch/IEpochManagerAccessor.hpp"
#include "../Human/IHumanManagerAccessor.hpp"
#include "../Land/ILandManagerAccessor.hpp"
#include "../Property/IPropertyManagerAccessor.hpp"
#include "../Resource/IResourceManagerAccessor.hpp"
#include "../Settlement/ISettlementManagerAccessor.hpp"
#include "../User/IUserManagerAccessor.hpp"
#include "../World/IWorldManagerAccessor.hpp"
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
    /**
     * @brief Destructs AccessorAbstractFactory.
     */
    virtual ~IAccessorAbstractFactory(){}

    /**
     * @brief Creates the achievement accessor.
     *
     * @return The newly created achievement accessor.
     */
    virtual Achievement::IAchievementAccessorAutPtr createAchievementAccessor() const = 0;

    /**
     * @brief Creates the authentication accessor.
     *
     * @return The newly created authentication accessor.
     */
    virtual Authentication::IAuthenticationManagerAccessorAutPtr createAuthenticationAccessor() const = 0;

    /**
     * @brief Creates the authorization accessor.
     *
     * @return The newly created authorization accessor.
     */
    virtual Authorization::IAuthorizationManagerAccessorAutPtr createAuthorizationAccessor() const = 0;

    /**
     * @brief Creates the building accessor.
     *
     * @return The newly created building accessor.
     */
    virtual Building::IBuildingManagerAccessorAutPtr createBuildingAccessor() const = 0;

    /**
     * @brief Creates the cost accessor.
     *
     * @return The newly created cost accessor.
     */
    virtual Cost::ICostManagerAccessorAutPtr createCostAccessor() const = 0;

    /**
     * @brief Creates the epoch accessor.
     *
     * @return The newly created epoch accessor.
     */
    virtual Epoch::IEpochManagerAccessorAutPtr createEpochAccessor() const = 0;

    /**
     * @brief Creates the human accessor.
     *
     * @return The newly created human accessor.
     */
    virtual Human::IHumanManagerAccessorAutPtr createHumanAccessor() const = 0;

    /**
     * @brief Creates the land accessor.
     *
     * @return The newly created land accessor.
     */
    virtual Land::ILandManagerAccessorAutPtr createLandAccessor() const = 0;

    /**
     * @brief Creates the property accessor.
     *
     * @return The newly created property accessor.
     */
    virtual Property::IPropertyManagerAccessorAutPtr createPropertyAccessor() const = 0;

    /**
     * @brief Creates the resource accessor.
     *
     * @return The newly created resource accessor.
     */
    virtual Resource::IResourceManagerAccessorAutPtr createResourceAccessor() const = 0;

    /**
     * @brief Creates the settlement accessor.
     *
     * @return The newly created settlement accessor.
     */
    virtual Settlement::ISettlementManagerAccessorAutPtr createSettlementAccessor() const = 0;

    /**
     * @brief Creates the user accessor.
     *
     * @return The newly created user accessor.
     */
    virtual User::IUserManagerAccessorAutPtr createUserAccessor() const = 0;

    /**
     * @brief Creates the world accessor.
     *
     * @return The newly created world accessor.
     */
    virtual World::IWorldManagerAccessorAutPtr createWorldAccessor() const = 0;
};

/**
 * @brief The shared pointer of the interface of AccessorAbstractFactory.
 */
typedef boost::shared_ptr<IAccessorAbstractFactory> IAccessorAbstractFactoryShrPtr;

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IACCESSORABSTRACTFACTORY_HPP
