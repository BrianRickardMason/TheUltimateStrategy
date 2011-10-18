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

#ifndef GAMESERVER_COMMON_IMANAGERABSTRACTFACTORY_HPP
#define GAMESERVER_COMMON_IMANAGERABSTRACTFACTORY_HPP

#include "../Authentication/IAuthenticationPersistenceFacade.hpp"
#include "../Authorization/IAuthorizationPersistenceFacade.hpp"
#include "../Building/IBuildingPersistenceFacade.hpp"
#include "../Cost/ICostManager.hpp"
#include "../Epoch/IEpochPersistenceFacade.hpp"
#include "../Human/IHumanPersistenceFacade.hpp"
#include "../Land/ILandPersistenceFacade.hpp"
#include "../Property/IPropertyManager.hpp"
#include "../Resource/IResourceManager.hpp"
#include "../Settlement/ISettlementPersistenceFacade.hpp"
#include "../User/IUserPersistenceFacade.hpp"
#include "../World/IWorldPersistenceFacade.hpp"
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Common
{

/**
 * @brief The interface of ManagerAbstractFactory.
 */
class IManagerAbstractFactory
{
public:
    /**
     * @brief Destructs ManagerAbstractFactory.
     */
    virtual ~IManagerAbstractFactory(){}

    /**
     * @brief Creates the authentication persistence facade.
     *
     * @return The newly created authentication persistence facade.
     */
    virtual Authentication::IAuthenticationPersistenceFacadeShrPtr createAuthenticationPersistenceFacade() const = 0;

    /**
     * @brief Creates the authorization persistence facade.
     *
     * @return The newly created authorization persistence facade.
     */
    virtual Authorization::IAuthorizationPersistenceFacadeShrPtr createAuthorizationPersistenceFacade() const = 0;

    /**
     * @brief Creates the building persistence facade.
     *
     * @return The newly created building persistence facade.
     */
    virtual Building::IBuildingPersistenceFacadeShrPtr createBuildingPersistenceFacade() const = 0;

    /**
     * @brief Creates the cost manager.
     *
     * @return The newly created cost manager.
     */
    virtual Cost::ICostManagerShrPtr createCostManager() const = 0;

    /**
     * @brief Creates the epoch persistence facade.
     *
     * @return The newly created epoch persistence facade.
     */
    virtual Epoch::IEpochPersistenceFacadeShrPtr createEpochPersistenceFacade() const = 0;

    /**
     * @brief Creates the human persistence facade.
     *
     * @return The newly created human persistence facade.
     */
    virtual Human::IHumanPersistenceFacadeShrPtr createHumanPersistenceFacade() const = 0;

    /**
     * @brief Creates the land persistence facade.
     *
     * @return The newly created land persistence facade.
     */
    virtual Land::ILandPersistenceFacadeShrPtr createLandPersistenceFacade() const = 0;

    /**
     * @brief Creates the property manager.
     *
     * @return The newly created property manager.
     */
    virtual Property::IPropertyManagerShrPtr createPropertyManager() const = 0;

    /**
     * @brief Creates the resource manager.
     *
     * @return The newly created resource manager.
     */
    virtual Resource::IResourceManagerShrPtr createResourceManager() const = 0;

    /**
     * @brief Creates the settlement persistence facade.
     *
     * @return The newly created settlement persistence facade.
     */
    virtual Settlement::ISettlementPersistenceFacadeShrPtr createSettlementPersistenceFacade() const = 0;

    /**
     * @brief Creates the user persistence facade.
     *
     * @return The newly created user persistence facade.
     */
    virtual User::IUserPersistenceFacadeShrPtr createUserPersistenceFacade() const = 0;

    /**
     * @brief Creates the world persistence facade.
     *
     * @return The newly created world persistence facade.
     */
    virtual World::IWorldPersistenceFacadeShrPtr createWorldPersistenceFacade() const = 0;
};

/**
 * @brief The shared pointer of the interface of ManagerAbstractFactory.
 */
typedef boost::shared_ptr<IManagerAbstractFactory> IManagerAbstractFactoryShrPtr;

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IMANAGERABSTRACTFACTORY_HPP
