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

#ifndef GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP
#define GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP

#include <Server/Network/XmlRPCServer/IContext.hpp>
#include <Game/GameServer/Common/IManagerAbstractFactory.hpp>
#include <Game/GameServer/Common/IOperatorAbstractFactory.hpp>
#include <Game/GameServer/Common/IPersistenceFacadeAbstractFactory.hpp>

namespace GameServer
{
namespace Common
{

/**
 * @brief The PostgreSQL OperatorAbstractFactory.
 */
class OperatorAbstractFactoryPostgresql
    : public IOperatorAbstractFactory
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_context The context of the server.
     */
    OperatorAbstractFactoryPostgresql(
        IContextShrPtr const a_context
    );

    //@{
    /**
     * @brief Creates a operator.
     *
     * @return The newly created operator.
     */
    virtual Authentication::IAuthenticateOperatorShrPtr             createAuthenticateOperator()              const;
    virtual Authorization::IAuthorizeUserToHolderOperatorShrPtr     createAuthorizeUserToHolderOperator()     const;
    virtual Authorization::IAuthorizeUserToLandOperatorShrPtr       createAuthorizeUserToLandOperator()       const;
    virtual Authorization::IAuthorizeUserToSettlementOperatorShrPtr createAuthorizeUserToSettlementOperator() const;
    virtual Building::IBuildBuildingOperatorShrPtr                  createBuildBuildingOperator()             const;
    virtual Building::IDestroyBuildingOperatorShrPtr                createDestroyBuildingOperator()           const;
    virtual Building::IGetBuildingOperatorShrPtr                    createGetBuildingOperator()               const;
    virtual Building::IGetBuildingsOperatorShrPtr                   createGetBuildingsOperator()              const;
    virtual Epoch::IActivateEpochOperatorShrPtr                     createActivateEpochOperator()             const;
    virtual Epoch::ICreateEpochOperatorShrPtr                       createCreateEpochOperator()               const;
    virtual Epoch::IDeactivateEpochOperatorShrPtr                   createDeactivateEpochOperator()           const;
    virtual Epoch::IDeleteEpochOperatorShrPtr                       createDeleteEpochOperator()               const;
    virtual Epoch::IFinishEpochOperatorShrPtr                       createFinishEpochOperator()               const;
    virtual Epoch::IGetEpochByLandNameOperatorShrPtr                createGetEpochByLandNameOperator()        const;
    virtual Epoch::IGetEpochBySettlementNameOperatorShrPtr          createGetEpochBySettlementNameOperator()  const;
    virtual Epoch::IGetEpochByWorldNameOperatorShrPtr               createGetEpochByWorldNameOperator()       const;
    virtual Epoch::ITickEpochOperatorShrPtr                         createTickEpochOperator()                 const;
    virtual Human::IDismissHumanOperatorShrPtr                      createDismissHumanOperator()              const;
    virtual Human::IEngageHumanOperatorShrPtr                       createEngageHumanOperator()               const;
    virtual Human::IGetHumanOperatorShrPtr                          createGetHumanOperator()                  const;
    virtual Human::IGetHumansOperatorShrPtr                         createGetHumansOperator()                 const;
    virtual Land::ICreateLandOperatorShrPtr                         createCreateLandOperator()                const;
    virtual Land::IDeleteLandOperatorShrPtr                         createDeleteLandOperator()                const;
    virtual Land::IGetLandOperatorShrPtr                            createGetLandOperator()                   const;
    virtual Land::IGetLandsOperatorShrPtr                           createGetLandsOperator()                  const;
    virtual Resource::IGetResourceOperatorShrPtr                    createGetResourceOperator()               const;
    virtual Resource::IGetResourcesOperatorShrPtr                   createGetResourcesOperator()              const;
    virtual Settlement::ICreateSettlementOperatorShrPtr             createCreateSettlementOperator()          const;
    virtual Settlement::IDeleteSettlementOperatorShrPtr             createDeleteSettlementOperator()          const;
    virtual Settlement::IGetSettlementOperatorShrPtr                createGetSettlementOperator()             const;
    virtual Settlement::IGetSettlementsOperatorShrPtr               createGetSettlementsOperator()            const;
    virtual Transport::ITransportHumanOperatorShrPtr                createTransportHumanOperator()            const;
    virtual Transport::ITransportResourceOperatorShrPtr             createTransportResourceOperator()         const;
    virtual User::ICreateUserOperatorShrPtr                         createCreateUserOperator()                const;
    virtual User::IGetUserOperatorShrPtr                            createGetUserOperator()                   const;
    virtual World::ICreateWorldOperatorShrPtr                       createCreateWorldOperator()               const;
    virtual World::IGetWorldByLandNameOperatorShrPtr                createGetWorldByLandNameOperator()        const;
    //}@

private:
    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;

    /**
     * @brief The abstract factory of persistence facades.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP
