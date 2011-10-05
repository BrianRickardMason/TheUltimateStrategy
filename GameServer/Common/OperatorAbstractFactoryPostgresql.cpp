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

#include "../Authentication/Operators/Authenticate/AuthenticateOperatorFactory.hpp"
#include "../Authorization/Operators/AuthorizeUserToHolder/AuthorizeUserToHolderOperatorFactory.hpp"
#include "../Authorization/Operators/AuthorizeUserToLand/AuthorizeUserToLandOperatorFactory.hpp"
#include "../Authorization/Operators/AuthorizeUserToSettlement/AuthorizeUserToSettlementOperatorFactory.hpp"
#include "../Building/Operators/BuildBuilding/BuildBuildingOperatorFactory.hpp"
#include "../Building/Operators/DestroyBuilding/DestroyBuildingOperatorFactory.hpp"
#include "../Building/Operators/GetBuilding/GetBuildingOperatorFactory.hpp"
#include "../Building/Operators/GetBuildings/GetBuildingsOperatorFactory.hpp"
#include "../Epoch/Operators/ActivateEpoch/ActivateEpochOperatorFactory.hpp"
#include "../Epoch/Operators/CreateEpoch/CreateEpochOperatorFactory.hpp"
#include "../Epoch/Operators/DeactivateEpoch/DeactivateEpochOperatorFactory.hpp"
#include "../Epoch/Operators/DeleteEpoch/DeleteEpochOperatorFactory.hpp"
#include "../Epoch/Operators/FinishEpoch/FinishEpochOperatorFactory.hpp"
#include "../Epoch/Operators/GetEpochByIDSettlement/GetEpochByIDSettlementOperatorFactory.hpp"
#include "../Epoch/Operators/GetEpochByLandName/GetEpochByLandNameOperatorFactory.hpp"
#include "../Epoch/Operators/GetEpochByWorldName/GetEpochByWorldNameOperatorFactory.hpp"
#include "../Epoch/Operators/TickEpoch/TickEpochOperatorFactory.hpp"
#include "../Human/Operators/DismissHuman/DismissHumanOperatorFactory.hpp"
#include "../Human/Operators/EngageHuman/EngageHumanOperatorFactory.hpp"
#include "../Human/Operators/GetHuman/GetHumanOperatorFactory.hpp"
#include "../Human/Operators/GetHumans/GetHumansOperatorFactory.hpp"
#include "../Land/Operators/CreateLand/CreateLandOperatorFactory.hpp"
#include "../Land/Operators/DeleteLand/DeleteLandOperatorFactory.hpp"
#include "../Land/Operators/GetLand/GetLandOperatorFactory.hpp"
#include "../Land/Operators/GetLandsByLoginAndWorldName/GetLandsByLoginAndWorldNameOperatorFactory.hpp"
#include "../Resource/Operators/GetResource/GetResourceOperatorFactory.hpp"
#include "../Resource/Operators/GetResources/GetResourcesOperatorFactory.hpp"
#include "../Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp"
#include "../Settlement/Operators/DeleteSettlement/DeleteSettlementOperatorFactory.hpp"
#include "../Settlement/Operators/GetSettlementByLandNameAndName/GetSettlementByLandNameAndNameOperatorFactory.hpp"
#include "../Settlement/Operators/GetSettlementByIDSettlement/GetSettlementByIDSettlementOperatorFactory.hpp"
#include "../Settlement/Operators/GetSettlements/GetSettlementsOperatorFactory.hpp"
#include "../Transport/Operators/TransportHuman/TransportHumanOperatorFactory.hpp"
#include "../Transport/Operators/TransportResource/TransportResourceOperatorFactory.hpp"
#include "../Turn/Operators/Turn/TurnOperatorFactory.hpp"
#include "../User/Operators/CreateUser/CreateUserOperatorFactory.hpp"
#include "../User/Operators/GetUser/GetUserOperatorFactory.hpp"
#include "../World/Operators/CreateWorld/CreateWorldOperatorFactory.hpp"
#include "../World/Operators/GetWorldByLandName/GetWorldByLandNameOperatorFactory.hpp"
#include "../WorldConfiguration/Operators/VerifyTurn/VerifyTurnOperatorFactory.hpp"
#include "ManagerAbstractFactoryPostgresql.hpp"
#include "OperatorAbstractFactoryPostgresql.hpp"

using namespace GameServer::Authentication;
using namespace GameServer::Authorization;
using namespace GameServer::Building;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace GameServer::Turn;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace GameServer::WorldConfiguration;

namespace GameServer
{
namespace Common
{

OperatorAbstractFactoryPostgresql::OperatorAbstractFactoryPostgresql()
    : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql)
{
}

IAuthenticateOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthenticateOperator() const
{
    return IAuthenticateOperatorShrPtr(AuthenticateOperatorFactory::createAuthenticateOperator(m_manager_abstract_factory));
}

IAuthorizeUserToHolderOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToHolderOperator() const
{
    return IAuthorizeUserToHolderOperatorShrPtr(AuthorizeUserToHolderOperatorFactory::createAuthorizeUserToHolderOperator(m_manager_abstract_factory));
}

IAuthorizeUserToLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToLandOperator() const
{
    return IAuthorizeUserToLandOperatorShrPtr(AuthorizeUserToLandOperatorFactory::createAuthorizeUserToLandOperator(m_manager_abstract_factory));
}

IAuthorizeUserToSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToSettlementOperator() const
{
    return IAuthorizeUserToSettlementOperatorShrPtr(AuthorizeUserToSettlementOperatorFactory::createAuthorizeUserToSettlementOperator(m_manager_abstract_factory));
}

IBuildBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createBuildBuildingOperator() const
{
    return IBuildBuildingOperatorShrPtr(BuildBuildingOperatorFactory::createBuildBuildingOperator(m_manager_abstract_factory));
}

IDestroyBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createDestroyBuildingOperator() const
{
    return IDestroyBuildingOperatorShrPtr(DestroyBuildingOperatorFactory::createDestroyBuildingOperator(m_manager_abstract_factory));
}

IGetBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetBuildingOperator() const
{
    return IGetBuildingOperatorShrPtr(GetBuildingOperatorFactory::createGetBuildingOperator(m_manager_abstract_factory));
}

IGetBuildingsOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetBuildingsOperator() const
{
    return IGetBuildingsOperatorShrPtr(GetBuildingsOperatorFactory::createGetBuildingsOperator(m_manager_abstract_factory));
}

IActivateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createActivateEpochOperator() const
{
    return IActivateEpochOperatorShrPtr(ActivateEpochOperatorFactory::createActivateEpochOperator(m_manager_abstract_factory));
}

ICreateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateEpochOperator() const
{
    return ICreateEpochOperatorShrPtr(CreateEpochOperatorFactory::createCreateEpochOperator(m_manager_abstract_factory));
}

IDeactivateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeactivateEpochOperator() const
{
    return IDeactivateEpochOperatorShrPtr(DeactivateEpochOperatorFactory::createDeactivateEpochOperator(m_manager_abstract_factory));
}

IDeleteEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteEpochOperator() const
{
    return IDeleteEpochOperatorShrPtr(DeleteEpochOperatorFactory::createDeleteEpochOperator(m_manager_abstract_factory));
}

IFinishEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createFinishEpochOperator() const
{
    return IFinishEpochOperatorShrPtr(FinishEpochOperatorFactory::createFinishEpochOperator(m_manager_abstract_factory));
}

IGetEpochByIDSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochByIDSettlementOperator() const
{
    return IGetEpochByIDSettlementOperatorShrPtr(GetEpochByIDSettlementOperatorFactory::createGetEpochByIDSettlementOperator(m_manager_abstract_factory));
}

IGetEpochByLandNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochByLandNameOperator() const
{
    return IGetEpochByLandNameOperatorShrPtr(GetEpochByLandNameOperatorFactory::createGetEpochByLandNameOperator(m_manager_abstract_factory));
}

IGetEpochByWorldNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochByWorldNameOperator() const
{
    return IGetEpochByWorldNameOperatorShrPtr(GetEpochByWorldNameOperatorFactory::createGetEpochByWorldNameOperator(m_manager_abstract_factory));
}

ITickEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createTickEpochOperator() const
{
    return ITickEpochOperatorShrPtr(TickEpochOperatorFactory::createTickEpochOperator(m_manager_abstract_factory));
}

IDismissHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createDismissHumanOperator() const
{
    return IDismissHumanOperatorShrPtr(DismissHumanOperatorFactory::createDismissHumanOperator(m_manager_abstract_factory));
}

IEngageHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createEngageHumanOperator() const
{
    return IEngageHumanOperatorShrPtr(EngageHumanOperatorFactory::createEngageHumanOperator(m_manager_abstract_factory));
}

IGetHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetHumanOperator() const
{
    return IGetHumanOperatorShrPtr(GetHumanOperatorFactory::createGetHumanOperator(m_manager_abstract_factory));
}

IGetHumansOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetHumansOperator() const
{
    return IGetHumansOperatorShrPtr(GetHumansOperatorFactory::createGetHumansOperator(m_manager_abstract_factory));
}

ICreateLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateLandOperator() const
{
    return ICreateLandOperatorShrPtr(CreateLandOperatorFactory::createCreateLandOperator(m_manager_abstract_factory));
}

IDeleteLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteLandOperator() const
{
    return IDeleteLandOperatorShrPtr( DeleteLandOperatorFactory::createDeleteLandOperator(m_manager_abstract_factory));
}

IGetLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetLandOperator() const
{
    return IGetLandOperatorShrPtr(GetLandOperatorFactory::createGetLandOperator(m_manager_abstract_factory));
}

IGetLandsByLoginAndWorldNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetLandsByLoginAndWorldNameOperator() const
{
    return IGetLandsByLoginAndWorldNameOperatorShrPtr(GetLandsByLoginAndWorldNameOperatorFactory::createGetLandsByLoginAndWorldNameOperator(m_manager_abstract_factory));
}

IGetResourceOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetResourceOperator() const
{
    return IGetResourceOperatorShrPtr(GetResourceOperatorFactory::createGetResourceOperator(m_manager_abstract_factory));
}

IGetResourcesOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetResourcesOperator() const
{
    return IGetResourcesOperatorShrPtr(GetResourcesOperatorFactory::createGetResourcesOperator(m_manager_abstract_factory));
}

ICreateSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateSettlementOperator() const
{
    return ICreateSettlementOperatorShrPtr(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_manager_abstract_factory));
}

IDeleteSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteSettlementOperator() const
{
    return IDeleteSettlementOperatorShrPtr(DeleteSettlementOperatorFactory::createDeleteSettlementOperator(m_manager_abstract_factory));
}

IGetSettlementByLandNameAndNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetSettlementByLandNameAndNameOperator() const
{
    return IGetSettlementByLandNameAndNameOperatorShrPtr(GetSettlementByLandNameAndNameOperatorFactory::createGetSettlementByLandNameAndNameOperator(m_manager_abstract_factory));
}

IGetSettlementByIDSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetSettlementByIDSettlementOperator() const
{
    return IGetSettlementByIDSettlementOperatorShrPtr(GetSettlementByIDSettlementOperatorFactory::createGetSettlementByIDSettlementOperator(m_manager_abstract_factory));
}

IGetSettlementsOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetSettlementsOperator() const
{
    return IGetSettlementsOperatorShrPtr(GetSettlementsOperatorFactory::createGetSettlementsOperator(m_manager_abstract_factory));
}

ITransportHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createTransportHumanOperator() const
{
    return ITransportHumanOperatorShrPtr(TransportHumanOperatorFactory::createTransportHumanOperator(m_manager_abstract_factory));
}

ITransportResourceOperatorShrPtr OperatorAbstractFactoryPostgresql::createTransportResourceOperator() const
{
    return ITransportResourceOperatorShrPtr(TransportResourceOperatorFactory::createTransportResourceOperator(m_manager_abstract_factory));
}

ITurnOperatorShrPtr OperatorAbstractFactoryPostgresql::createTurnOperator() const
{
    return ITurnOperatorShrPtr(TurnOperatorFactory::createTurnOperator(m_manager_abstract_factory));
}

ICreateUserOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateUserOperator() const
{
    return ICreateUserOperatorShrPtr(CreateUserOperatorFactory::createCreateUserOperator(m_manager_abstract_factory));
}

IGetUserOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetUserOperator() const
{
    return IGetUserOperatorShrPtr(GetUserOperatorFactory::createGetUserOperator(m_manager_abstract_factory));
}

ICreateWorldOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateWorldOperator() const
{
    return ICreateWorldOperatorShrPtr(CreateWorldOperatorFactory::createCreateWorldOperator(m_manager_abstract_factory));
}

IGetWorldByLandNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetWorldByLandNameOperator() const
{
    return IGetWorldByLandNameOperatorShrPtr(GetWorldByLandNameOperatorFactory::createGetWorldByLandNameOperator(m_manager_abstract_factory));
}

IVerifyTurnOperatorShrPtr OperatorAbstractFactoryPostgresql::createVerifyTurnOperator() const
{
    return IVerifyTurnOperatorShrPtr(VerifyTurnOperatorFactory::createVerifyTurnOperator(m_manager_abstract_factory));
}

} // namespace Common
} // namespace GameServer
