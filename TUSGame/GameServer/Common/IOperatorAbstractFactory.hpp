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
// THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS >AS IS> AND
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

#include <TUSGame/GameServer/Authentication/Operators/Authenticate/IAuthenticateOperator.hpp>
#include <TUSGame/GameServer/Authorization/Operators/AuthorizeUserToHolder/IAuthorizeUserToHolderOperator.hpp>
#include <TUSGame/GameServer/Authorization/Operators/AuthorizeUserToLand/IAuthorizeUserToLandOperator.hpp>
#include <TUSGame/GameServer/Authorization/Operators/AuthorizeUserToSettlement/IAuthorizeUserToSettlementOperator.hpp>
#include <TUSGame/GameServer/Building/Operators/BuildBuilding/IBuildBuildingOperator.hpp>
#include <TUSGame/GameServer/Building/Operators/DestroyBuilding/IDestroyBuildingOperator.hpp>
#include <TUSGame/GameServer/Building/Operators/GetBuilding/IGetBuildingOperator.hpp>
#include <TUSGame/GameServer/Building/Operators/GetBuildings/IGetBuildingsOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/ActivateEpoch/IActivateEpochOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/CreateEpoch/ICreateEpochOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/DeactivateEpoch/IDeactivateEpochOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/DeleteEpoch/IDeleteEpochOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/FinishEpoch/IFinishEpochOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/GetEpochByLandName/IGetEpochByLandNameOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/GetEpochBySettlementName/IGetEpochBySettlementNameOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/GetEpochByWorldName/IGetEpochByWorldNameOperator.hpp>
#include <TUSGame/GameServer/Epoch/Operators/TickEpoch/ITickEpochOperator.hpp>
#include <TUSGame/GameServer/Human/Operators/DismissHuman/IDismissHumanOperator.hpp>
#include <TUSGame/GameServer/Human/Operators/EngageHuman/IEngageHumanOperator.hpp>
#include <TUSGame/GameServer/Human/Operators/GetHuman/IGetHumanOperator.hpp>
#include <TUSGame/GameServer/Human/Operators/GetHumans/IGetHumansOperator.hpp>
#include <TUSGame/GameServer/Land/Operators/CreateLand/ICreateLandOperator.hpp>
#include <TUSGame/GameServer/Land/Operators/DeleteLand/IDeleteLandOperator.hpp>
#include <TUSGame/GameServer/Land/Operators/GetLand/IGetLandOperator.hpp>
#include <TUSGame/GameServer/Land/Operators/GetLands/IGetLandsOperator.hpp>
#include <TUSGame/GameServer/Resource/Operators/GetResource/IGetResourceOperator.hpp>
#include <TUSGame/GameServer/Resource/Operators/GetResources/IGetResourcesOperator.hpp>
#include <TUSGame/GameServer/Settlement/Operators/CreateSettlement/ICreateSettlementOperator.hpp>
#include <TUSGame/GameServer/Settlement/Operators/DeleteSettlement/IDeleteSettlementOperator.hpp>
#include <TUSGame/GameServer/Settlement/Operators/GetSettlement/IGetSettlementOperator.hpp>
#include <TUSGame/GameServer/Settlement/Operators/GetSettlements/IGetSettlementsOperator.hpp>
#include <TUSGame/GameServer/Transport/Operators/TransportHuman/ITransportHumanOperator.hpp>
#include <TUSGame/GameServer/Transport/Operators/TransportResource/ITransportResourceOperator.hpp>
#include <TUSGame/GameServer/User/Operators/CreateUser/ICreateUserOperator.hpp>
#include <TUSGame/GameServer/User/Operators/GetUser/IGetUserOperator.hpp>
#include <TUSGame/GameServer/World/Operators/CreateWorld/ICreateWorldOperator.hpp>
#include <TUSGame/GameServer/World/Operators/GetWorldByLandName/IGetWorldByLandNameOperator.hpp>
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

    //@{
    /**
     * @brief Creates a operator.
     *
     * @return The newly created operator.
     */
    virtual Authentication::IAuthenticateOperatorShrPtr             createAuthenticateOperator()              const = 0;
    virtual Authorization::IAuthorizeUserToHolderOperatorShrPtr     createAuthorizeUserToHolderOperator()     const = 0;
    virtual Authorization::IAuthorizeUserToLandOperatorShrPtr       createAuthorizeUserToLandOperator()       const = 0;
    virtual Authorization::IAuthorizeUserToSettlementOperatorShrPtr createAuthorizeUserToSettlementOperator() const = 0;
    virtual Building::IBuildBuildingOperatorShrPtr                  createBuildBuildingOperator()             const = 0;
    virtual Building::IDestroyBuildingOperatorShrPtr                createDestroyBuildingOperator()           const = 0;
    virtual Building::IGetBuildingOperatorShrPtr                    createGetBuildingOperator()               const = 0;
    virtual Building::IGetBuildingsOperatorShrPtr                   createGetBuildingsOperator()              const = 0;
    virtual Epoch::IActivateEpochOperatorShrPtr                     createActivateEpochOperator()             const = 0;
    virtual Epoch::ICreateEpochOperatorShrPtr                       createCreateEpochOperator()               const = 0;
    virtual Epoch::IDeactivateEpochOperatorShrPtr                   createDeactivateEpochOperator()           const = 0;
    virtual Epoch::IDeleteEpochOperatorShrPtr                       createDeleteEpochOperator()               const = 0;
    virtual Epoch::IFinishEpochOperatorShrPtr                       createFinishEpochOperator()               const = 0;
    virtual Epoch::IGetEpochByLandNameOperatorShrPtr                createGetEpochByLandNameOperator()        const = 0;
    virtual Epoch::IGetEpochBySettlementNameOperatorShrPtr          createGetEpochBySettlementNameOperator()  const = 0;
    virtual Epoch::IGetEpochByWorldNameOperatorShrPtr               createGetEpochByWorldNameOperator()       const = 0;
    virtual Epoch::ITickEpochOperatorShrPtr                         createTickEpochOperator()                 const = 0;
    virtual Human::IDismissHumanOperatorShrPtr                      createDismissHumanOperator()              const = 0;
    virtual Human::IEngageHumanOperatorShrPtr                       createEngageHumanOperator()               const = 0;
    virtual Human::IGetHumanOperatorShrPtr                          createGetHumanOperator()                  const = 0;
    virtual Human::IGetHumansOperatorShrPtr                         createGetHumansOperator()                 const = 0;
    virtual Land::ICreateLandOperatorShrPtr                         createCreateLandOperator()                const = 0;
    virtual Land::IDeleteLandOperatorShrPtr                         createDeleteLandOperator()                const = 0;
    virtual Land::IGetLandOperatorShrPtr                            createGetLandOperator()                   const = 0;
    virtual Land::IGetLandsOperatorShrPtr                           createGetLandsOperator()                  const = 0;
    virtual Resource::IGetResourceOperatorShrPtr                    createGetResourceOperator()               const = 0;
    virtual Resource::IGetResourcesOperatorShrPtr                   createGetResourcesOperator()              const = 0;
    virtual Settlement::ICreateSettlementOperatorShrPtr             createCreateSettlementOperator()          const = 0;
    virtual Settlement::IDeleteSettlementOperatorShrPtr             createDeleteSettlementOperator()          const = 0;
    virtual Settlement::IGetSettlementOperatorShrPtr                createGetSettlementOperator()             const = 0;
    virtual Settlement::IGetSettlementsOperatorShrPtr               createGetSettlementsOperator()            const = 0;
    virtual Transport::ITransportHumanOperatorShrPtr                createTransportHumanOperator()            const = 0;
    virtual Transport::ITransportResourceOperatorShrPtr             createTransportResourceOperator()         const = 0;
    virtual User::ICreateUserOperatorShrPtr                         createCreateUserOperator()                const = 0;
    virtual User::IGetUserOperatorShrPtr                            createGetUserOperator()                   const = 0;
    virtual World::ICreateWorldOperatorShrPtr                       createCreateWorldOperator()               const = 0;
    virtual World::IGetWorldByLandNameOperatorShrPtr                createGetWorldByLandNameOperator()        const = 0;
    //}@
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IOperatorAbstractFactory> IOperatorAbstractFactoryShrPtr;

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_IOPERATORABSTRACTFACTORY_HPP
