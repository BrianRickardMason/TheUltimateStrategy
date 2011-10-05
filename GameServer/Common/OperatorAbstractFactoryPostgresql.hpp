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

#ifndef GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP
#define GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP

#include "IManagerAbstractFactory.hpp"
#include "IOperatorAbstractFactory.hpp"

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
     * @brief Constructs the PostgreSQL OperatorAbstractFactory.
     */
    OperatorAbstractFactoryPostgresql();

    /**
     * @brief Creates the authentication operator.
     *
     * @return The newly created authentication operator.
     */
    virtual Authentication::IAuthenticateOperatorShrPtr createAuthenticateOperator() const;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToHolderOperatorShrPtr createAuthorizeUserToHolderOperator() const;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToLandOperatorShrPtr createAuthorizeUserToLandOperator() const;

    /**
     * @brief Creates the authorization operator.
     *
     * @return The newly created authorization operator.
     */
    virtual Authorization::IAuthorizeUserToSettlementOperatorShrPtr createAuthorizeUserToSettlementOperator() const;

    /**
     * @brief Creates the build building operator.
     *
     * @return The newly created build building operator.
     */
    virtual Building::IBuildBuildingOperatorShrPtr createBuildBuildingOperator() const;

    /**
     * @brief Creates the destroy building operator.
     *
     * @return The newly created destroy building operator.
     */
    virtual Building::IDestroyBuildingOperatorShrPtr createDestroyBuildingOperator() const;

    /**
     * @brief Creates the get building operator.
     *
     * @return The newly created get building operator.
     */
    virtual Building::IGetBuildingOperatorShrPtr createGetBuildingOperator() const;

    /**
     * @brief Creates the get buildings operator.
     *
     * @return The newly created get buildings operator.
     */
    virtual Building::IGetBuildingsOperatorShrPtr createGetBuildingsOperator() const;

    /**
     * @brief Creates the activate epoch operator.
     *
     * @return The newly created activate epoch operator.
     */
    virtual Epoch::IActivateEpochOperatorShrPtr createActivateEpochOperator() const;

    /**
     * @brief Creates the create epoch operator.
     *
     * @return The newly created create epoch operator.
     */
    virtual Epoch::ICreateEpochOperatorShrPtr createCreateEpochOperator() const;

    /**
     * @brief Creates the deactivate epoch operator.
     *
     * @return The newly created deactivate epoch operator.
     */
    virtual Epoch::IDeactivateEpochOperatorShrPtr createDeactivateEpochOperator() const;

    /**
     * @brief Creates the delete epoch operator.
     *
     * @return The newly created delete epoch operator.
     */
    virtual Epoch::IDeleteEpochOperatorShrPtr createDeleteEpochOperator() const;

    /**
     * @brief Creates the finish epoch operator.
     *
     * @return The newly created finish epoch operator.
     */
    virtual Epoch::IFinishEpochOperatorShrPtr createFinishEpochOperator() const;

    /**
     * @brief Creates the get epoch by id settlement operator.
     *
     * @return The newly created get epoch by id settlement operator.
     */
    virtual Epoch::IGetEpochByIDSettlementOperatorShrPtr createGetEpochByIDSettlementOperator() const;

    /**
     * @brief Creates the get epoch by land name operator.
     *
     * @return The newly created get epoch by land name operator.
     */
    virtual Epoch::IGetEpochByLandNameOperatorShrPtr createGetEpochByLandNameOperator() const;

    /**
     * @brief Creates the get epoch by world name operator.
     *
     * @return The newly created get epoch by world name operator.
     */
    virtual Epoch::IGetEpochByWorldNameOperatorShrPtr createGetEpochByWorldNameOperator() const;

    /**
     * @brief Creates the tick epoch operator.
     *
     * @return The newly created tick epoch operator.
     */
    virtual Epoch::ITickEpochOperatorShrPtr createTickEpochOperator() const;

    /**
     * @brief Creates the dismiss human operator.
     *
     * @return The newly created dismiss human operator.
     */
    virtual Human::IDismissHumanOperatorShrPtr createDismissHumanOperator() const;

    /**
     * @brief Creates the engage human operator.
     *
     * @return The newly created engage human operator.
     */
    virtual Human::IEngageHumanOperatorShrPtr createEngageHumanOperator() const;

    /**
     * @brief Creates the get human operator.
     *
     * @return The newly created get human operator.
     */
    virtual Human::IGetHumanOperatorShrPtr createGetHumanOperator() const;

    /**
     * @brief Creates the get humans operator.
     *
     * @return The newly created get humans operator.
     */
    virtual Human::IGetHumansOperatorShrPtr createGetHumansOperator() const;

    /**
     * @brief Creates the create land operator.
     *
     * @return The newly created create land operator.
     */
    virtual Land::ICreateLandOperatorShrPtr createCreateLandOperator() const;

    /**
     * @brief Creates the delete land operator.
     *
     * @return The newly created delet land operator.
     */
    virtual Land::IDeleteLandOperatorShrPtr createDeleteLandOperator() const;

    /**
     * @brief Creates the get land operator.
     *
     * @return The newly created get land operator.
     */
    virtual Land::IGetLandOperatorShrPtr createGetLandOperator() const;

    /**
     * @brief Creates the get lands by login and world name operator.
     *
     * @return The newly created get lands by login and world name operator.
     */
    virtual Land::IGetLandsByLoginAndWorldNameOperatorShrPtr createGetLandsByLoginAndWorldNameOperator() const;

    /**
     * @brief Creates the get resource operator.
     *
     * @return The newly created get resource operator.
     */
    virtual Resource::IGetResourceOperatorShrPtr createGetResourceOperator() const;

    /**
     * @brief Creates the get resources operator.
     *
     * @return The newly created get resources operator.
     */
    virtual Resource::IGetResourcesOperatorShrPtr createGetResourcesOperator() const;

    /**
     * @brief Creates the create settlement operator.
     *
     * @return The newly created create settlement operator.
     */
    virtual Settlement::ICreateSettlementOperatorShrPtr createCreateSettlementOperator() const;

    /**
     * @brief Creates the delete settlement operator.
     *
     * @return The newly created delete settlement operator.
     */
    virtual Settlement::IDeleteSettlementOperatorShrPtr createDeleteSettlementOperator() const;

    /**
     * @brief Creates the get settlement by land name and name operator.
     *
     * @return The newly created get settlement by land name and name operator.
     */
    virtual Settlement::IGetSettlementByLandNameAndNameOperatorShrPtr createGetSettlementByLandNameAndNameOperator() const;

    /**
     * @brief Creates the get settlement by id settlement operator.
     *
     * @return The newly created get settlement by id settlement operator.
     */
    virtual Settlement::IGetSettlementByIDSettlementOperatorShrPtr createGetSettlementByIDSettlementOperator() const;

    /**
     * @brief Creates the get settlements operator.
     *
     * @return The newly created get settlements operator.
     */
    virtual Settlement::IGetSettlementsOperatorShrPtr createGetSettlementsOperator() const;

    /**
     * @brief Creates the transport human operator.
     *
     * @return The newly created transport human operator.
     */
    virtual Transport::ITransportHumanOperatorShrPtr createTransportHumanOperator() const;

    /**
     * @brief Creates the transport resource operator.
     *
     * @return The newly created transport resource operator.
     */
    virtual Transport::ITransportResourceOperatorShrPtr createTransportResourceOperator() const;

    /**
     * @brief Creates the turn operator.
     *
     * @return The newly created turn operator.
     */
    virtual Turn::ITurnOperatorShrPtr createTurnOperator() const;

    /**
     * @brief Creates the create user operator.
     *
     * @return The newly created create user operator.
     */
    virtual User::ICreateUserOperatorShrPtr createCreateUserOperator() const;

    /**
     * @brief Creates the get user operator.
     *
     * @return The newly created get user operator.
     */
    virtual User::IGetUserOperatorShrPtr createGetUserOperator() const;

    /**
     * @brief Creates the create world operator.
     *
     * @return The newly created create world operator.
     */
    virtual World::ICreateWorldOperatorShrPtr createCreateWorldOperator() const;

    /**
     * @brief Creates the get world by land name operator.
     *
     * @return The newly created get world by land name operator.
     */
    virtual World::IGetWorldByLandNameOperatorShrPtr createGetWorldByLandNameOperator() const;

    /**
     * @brief Creates the verify turn operator.
     *
     * @return The newly created verify turn operator.
     */
    virtual WorldConfiguration::IVerifyTurnOperatorShrPtr createVerifyTurnOperator() const;

private:
    /**
     * @brief The abstract factory of managers.
     */
    IManagerAbstractFactoryShrPtr m_manager_abstract_factory;
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_OPERATORABSTRACTFACTORYPOSTGRESQL_HPP
