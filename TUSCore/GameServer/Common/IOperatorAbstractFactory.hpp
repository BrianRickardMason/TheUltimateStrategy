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

#ifndef GAMESERVER_COMMON_IOPERATORABSTRACTFACTORY_HPP
#define GAMESERVER_COMMON_IOPERATORABSTRACTFACTORY_HPP

#include "../Authentication/Operators/Authenticate/IAuthenticateOperator.hpp"
#include "../Authorization/Operators/AuthorizeUserToHolder/IAuthorizeUserToHolderOperator.hpp"
#include "../Authorization/Operators/AuthorizeUserToLand/IAuthorizeUserToLandOperator.hpp"
#include "../Authorization/Operators/AuthorizeUserToSettlement/IAuthorizeUserToSettlementOperator.hpp"
#include "../Building/Operators/BuildBuilding/IBuildBuildingOperator.hpp"
#include "../Building/Operators/DestroyBuilding/IDestroyBuildingOperator.hpp"
#include "../Building/Operators/GetBuilding/IGetBuildingOperator.hpp"
#include "../Building/Operators/GetBuildings/IGetBuildingsOperator.hpp"
#include "../Epoch/Operators/ActivateEpoch/IActivateEpochOperator.hpp"
#include "../Epoch/Operators/CreateEpoch/ICreateEpochOperator.hpp"
#include "../Epoch/Operators/DeactivateEpoch/IDeactivateEpochOperator.hpp"
#include "../Epoch/Operators/DeleteEpoch/IDeleteEpochOperator.hpp"
#include "../Epoch/Operators/FinishEpoch/IFinishEpochOperator.hpp"
#include "../Epoch/Operators/GetEpochByLandName/IGetEpochByLandNameOperator.hpp"
#include "../Epoch/Operators/GetEpochBySettlementName/IGetEpochBySettlementNameOperator.hpp"
#include "../Epoch/Operators/GetEpochByWorldName/IGetEpochByWorldNameOperator.hpp"
#include "../Epoch/Operators/TickEpoch/ITickEpochOperator.hpp"
#include "../Human/Operators/DismissHuman/IDismissHumanOperator.hpp"
#include "../Human/Operators/EngageHuman/IEngageHumanOperator.hpp"
#include "../Human/Operators/GetHuman/IGetHumanOperator.hpp"
#include "../Human/Operators/GetHumans/IGetHumansOperator.hpp"
#include "../Land/Operators/CreateLand/ICreateLandOperator.hpp"
#include "../Land/Operators/DeleteLand/IDeleteLandOperator.hpp"
#include "../Land/Operators/GetLand/IGetLandOperator.hpp"
#include "../Land/Operators/GetLands/IGetLandsOperator.hpp"
#include "../Resource/Operators/GetResource/IGetResourceOperator.hpp"
#include "../Resource/Operators/GetResources/IGetResourcesOperator.hpp"
#include "../Settlement/Operators/CreateSettlement/ICreateSettlementOperator.hpp"
#include "../Settlement/Operators/DeleteSettlement/IDeleteSettlementOperator.hpp"
#include "../Settlement/Operators/GetSettlement/IGetSettlementOperator.hpp"
#include "../Settlement/Operators/GetSettlements/IGetSettlementsOperator.hpp"
#include "../Transport/Operators/TransportHuman/ITransportHumanOperator.hpp"
#include "../Transport/Operators/TransportResource/ITransportResourceOperator.hpp"
#include "../User/Operators/CreateUser/ICreateUserOperator.hpp"
#include "../User/Operators/GetUser/IGetUserOperator.hpp"
#include "../World/Operators/CreateWorld/ICreateWorldOperator.hpp"
#include "../World/Operators/GetWorldByLandName/IGetWorldByLandNameOperator.hpp"
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Common
{

/**
 * @brief The interface of OperatorAbstractFactory.
 */
class IOperatorAbstractFactory
{
public:
    virtual ~IOperatorAbstractFactory(){}

    /**
     * @brief Creates the authentication operator.
     *
     * @return The newly created authentication operator.
     */
    virtual Authentication::IAuthenticateOperatorShrPtr createAuthenticateOperator() const = 0;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToHolderOperatorShrPtr createAuthorizeUserToHolderOperator() const = 0;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToLandOperatorShrPtr createAuthorizeUserToLandOperator() const = 0;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToSettlementOperatorShrPtr createAuthorizeUserToSettlementOperator() const = 0;

    /**
     * @brief Creates the build building operator.
     *
     * @return The newly created build building operator.
     */
    virtual Building::IBuildBuildingOperatorShrPtr createBuildBuildingOperator() const = 0;

    /**
     * @brief Creates the destroy building operator.
     *
     * @return The newly created destroy building operator.
     */
    virtual Building::IDestroyBuildingOperatorShrPtr createDestroyBuildingOperator() const = 0;

    /**
     * @brief Creates the get building operator.
     *
     * @return The newly created get building operator.
     */
    virtual Building::IGetBuildingOperatorShrPtr createGetBuildingOperator() const = 0;

    /**
     * @brief Creates the get buildings operator.
     *
     * @return The newly created get buildings operator.
     */
    virtual Building::IGetBuildingsOperatorShrPtr createGetBuildingsOperator() const = 0;

    /**
     * @brief Creates the activate epoch operator.
     *
     * @return The newly created activate epoch operator.
     */
    virtual Epoch::IActivateEpochOperatorShrPtr createActivateEpochOperator() const = 0;

    /**
     * @brief Creates the create epoch operator.
     *
     * @return The newly created create epoch operator.
     */
    virtual Epoch::ICreateEpochOperatorShrPtr createCreateEpochOperator() const = 0;

    /**
     * @brief Creates the deactivate epoch operator.
     *
     * @return The newly created deactivate epoch operator.
     */
    virtual Epoch::IDeactivateEpochOperatorShrPtr createDeactivateEpochOperator() const = 0;

    /**
     * @brief Creates the delete epoch operator.
     *
     * @return The newly created delete epoch operator.
     */
    virtual Epoch::IDeleteEpochOperatorShrPtr createDeleteEpochOperator() const = 0;

    /**
     * @brief Creates the finish epoch operator.
     *
     * @return The newly created finish epoch operator.
     */
    virtual Epoch::IFinishEpochOperatorShrPtr createFinishEpochOperator() const = 0;

    /**
     * @brief Creates the get epoch by land name operator.
     *
     * @return The newly created get epoch by land name operator.
     */
    virtual Epoch::IGetEpochByLandNameOperatorShrPtr createGetEpochByLandNameOperator() const = 0;

    /**
     * @brief Creates the get epoch by settlement name operator.
     *
     * @return The newly created get epoch by settlement name operator.
     */
    virtual Epoch::IGetEpochBySettlementNameOperatorShrPtr createGetEpochBySettlementNameOperator() const = 0;

    /**
     * @brief Creates the get epoch by world name operator.
     *
     * @return The newly created get epoch by world name operator.
     */
    virtual Epoch::IGetEpochByWorldNameOperatorShrPtr createGetEpochByWorldNameOperator() const = 0;

    /**
     * @brief Creates the tick epoch operator.
     *
     * @return The newly created tick epoch operator.
     */
    virtual Epoch::ITickEpochOperatorShrPtr createTickEpochOperator() const = 0;

    /**
     * @brief Creates the dismiss human operator.
     *
     * @return The newly created dismiss human operator.
     */
    virtual Human::IDismissHumanOperatorShrPtr createDismissHumanOperator() const = 0;

    /**
     * @brief Creates the engage human operator.
     *
     * @return The newly created engage human operator.
     */
    virtual Human::IEngageHumanOperatorShrPtr createEngageHumanOperator() const = 0;

    /**
     * @brief Creates the get human operator.
     *
     * @return The newly created get human operator.
     */
    virtual Human::IGetHumanOperatorShrPtr createGetHumanOperator() const = 0;

    /**
     * @brief Creates the get humans operator.
     *
     * @return The newly created get humans operator.
     */
    virtual Human::IGetHumansOperatorShrPtr createGetHumansOperator() const = 0;

    /**
     * @brief Creates the create land operator.
     *
     * @return The newly created create land operator.
     */
    virtual Land::ICreateLandOperatorShrPtr createCreateLandOperator() const = 0;

    /**
     * @brief Creates the delete land operator.
     *
     * @return The newly created delet land operator.
     */
    virtual Land::IDeleteLandOperatorShrPtr createDeleteLandOperator() const = 0;

    /**
     * @brief Creates the get land operator.
     *
     * @return The newly created get land operator.
     */
    virtual Land::IGetLandOperatorShrPtr createGetLandOperator() const = 0;

    /**
     * @brief Creates the get lands operator.
     *
     * @return The newly created get lands operator.
     */
    virtual Land::IGetLandsOperatorShrPtr createGetLandsOperator() const = 0;

    /**
     * @brief Creates the get resource operator.
     *
     * @return The newly created get resource operator.
     */
    virtual Resource::IGetResourceOperatorShrPtr createGetResourceOperator() const = 0;

    /**
     * @brief Creates the get resources operator.
     *
     * @return The newly created get resources operator.
     */
    virtual Resource::IGetResourcesOperatorShrPtr createGetResourcesOperator() const = 0;

    /**
     * @brief Creates the create settlement operator.
     *
     * @return The newly created create settlement operator.
     */
    virtual Settlement::ICreateSettlementOperatorShrPtr createCreateSettlementOperator() const = 0;

    /**
     * @brief Creates the delete settlement operator.
     *
     * @return The newly created delete settlement operator.
     */
    virtual Settlement::IDeleteSettlementOperatorShrPtr createDeleteSettlementOperator() const = 0;

    /**
     * @brief Creates the get settlement operator.
     *
     * @return The newly created get settlement operator.
     */
    virtual Settlement::IGetSettlementOperatorShrPtr createGetSettlementOperator() const = 0;

    /**
     * @brief Creates the get settlements operator.
     *
     * @return The newly created get settlements operator.
     */
    virtual Settlement::IGetSettlementsOperatorShrPtr createGetSettlementsOperator() const = 0;

    /**
     * @brief Creates the transport human operator.
     *
     * @return The newly created transport human operator.
     */
    virtual Transport::ITransportHumanOperatorShrPtr createTransportHumanOperator() const = 0;

    /**
     * @brief Creates the transport resource operator.
     *
     * @return The newly created transport resource operator.
     */
    virtual Transport::ITransportResourceOperatorShrPtr createTransportResourceOperator() const = 0;

    /**
     * @brief Creates the create user operator.
     *
     * @return The newly created create user operator.
     */
    virtual User::ICreateUserOperatorShrPtr createCreateUserOperator() const = 0;

    /**
     * @brief Creates the get user operator.
     *
     * @return The newly created get user operator.
     */
    virtual User::IGetUserOperatorShrPtr createGetUserOperator() const = 0;

    /**
     * @brief Creates the create world operator.
     *
     * @return The newly created create world operator.
     */
    virtual World::ICreateWorldOperatorShrPtr createCreateWorldOperator() const = 0;

    /**
     * @brief Creates the get world by land name operator.
     *
     * @return The newly created get world by land name operator.
     */
    virtual World::IGetWorldByLandNameOperatorShrPtr createGetWorldByLandNameOperator() const = 0;
};

//@{
/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IOperatorAbstractFactory> IOperatorAbstractFactoryShrPtr;
//}@

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IOPERATORABSTRACTFACTORY_HPP
