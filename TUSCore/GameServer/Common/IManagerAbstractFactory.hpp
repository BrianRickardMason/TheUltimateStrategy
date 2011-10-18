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
#include "../Cost/ICostPersistenceFacade.hpp"
#include "../Epoch/IEpochPersistenceFacade.hpp"
#include "../Human/IHumanPersistenceFacade.hpp"
#include "../Land/ILandPersistenceFacade.hpp"
#include "../Property/IPropertyPersistenceFacade.hpp"
#include "../Resource/IResourcePersistenceFacade.hpp"
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
    virtual ~IManagerAbstractFactory(){}

    //@{
    /**
     * @brief Creates a persistence facade.
     *
     * @return The newly created persistence facade.
     */
    virtual Authentication::IAuthenticationPersistenceFacadeShrPtr createAuthenticationPersistenceFacade() const = 0;
    virtual Authorization::IAuthorizationPersistenceFacadeShrPtr   createAuthorizationPersistenceFacade()  const = 0;
    virtual Building::IBuildingPersistenceFacadeShrPtr             createBuildingPersistenceFacade()       const = 0;
    virtual Cost::ICostPersistenceFacadeShrPtr                     createCostPersistenceFacade()           const = 0;
    virtual Epoch::IEpochPersistenceFacadeShrPtr                   createEpochPersistenceFacade()          const = 0;
    virtual Human::IHumanPersistenceFacadeShrPtr                   createHumanPersistenceFacade()          const = 0;
    virtual Land::ILandPersistenceFacadeShrPtr                     createLandPersistenceFacade()           const = 0;
    virtual Property::IPropertyPersistenceFacadeShrPtr             createPropertyPersistenceFacade()       const = 0;
    virtual Resource::IResourcePersistenceFacadeShrPtr             createResourcePersistenceFacade()       const = 0;
    virtual Settlement::ISettlementPersistenceFacadeShrPtr         createSettlementPersistenceFacade()     const = 0;
    virtual User::IUserPersistenceFacadeShrPtr                     createUserPersistenceFacade()           const = 0;
    virtual World::IWorldPersistenceFacadeShrPtr                   createWorldPersistenceFacade()          const = 0;
    //}@
};

/**
 * @brief Typedef of shared pointer.
 */
typedef boost::shared_ptr<IManagerAbstractFactory> IManagerAbstractFactoryShrPtr;

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IMANAGERABSTRACTFACTORY_HPP
