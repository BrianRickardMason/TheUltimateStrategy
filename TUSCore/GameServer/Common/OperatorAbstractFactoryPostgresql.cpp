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

#include <GameServer/Authentication/Operators/Authenticate/AuthenticateOperatorFactory.hpp>
#include <GameServer/Authorization/Operators/AuthorizeUserToHolder/AuthorizeUserToHolderOperatorFactory.hpp>
#include <GameServer/Authorization/Operators/AuthorizeUserToLand/AuthorizeUserToLandOperatorFactory.hpp>
#include <GameServer/Authorization/Operators/AuthorizeUserToSettlement/AuthorizeUserToSettlementOperatorFactory.hpp>
#include <GameServer/Building/Operators/BuildBuilding/BuildBuildingOperatorFactory.hpp>
#include <GameServer/Building/Operators/DestroyBuilding/DestroyBuildingOperatorFactory.hpp>
#include <GameServer/Building/Operators/GetBuilding/GetBuildingOperatorFactory.hpp>
#include <GameServer/Building/Operators/GetBuildings/GetBuildingsOperatorFactory.hpp>
#include <GameServer/Common/ManagerAbstractFactoryPostgresql.hpp>
#include <GameServer/Common/OperatorAbstractFactoryPostgresql.hpp>
#include <GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp>
#include <GameServer/Epoch/Operators/ActivateEpoch/ActivateEpochOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/CreateEpoch/CreateEpochOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/DeactivateEpoch/DeactivateEpochOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/DeleteEpoch/DeleteEpochOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/FinishEpoch/FinishEpochOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/GetEpochByLandName/GetEpochByLandNameOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/GetEpochBySettlementName/GetEpochBySettlementNameOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/GetEpochByWorldName/GetEpochByWorldNameOperatorFactory.hpp>
#include <GameServer/Epoch/Operators/TickEpoch/TickEpochOperatorFactory.hpp>
#include <GameServer/Human/Operators/DismissHuman/DismissHumanOperatorFactory.hpp>
#include <GameServer/Human/Operators/EngageHuman/EngageHumanOperatorFactory.hpp>
#include <GameServer/Human/Operators/GetHuman/GetHumanOperatorFactory.hpp>
#include <GameServer/Human/Operators/GetHumans/GetHumansOperatorFactory.hpp>
#include <GameServer/Land/Operators/CreateLand/CreateLandOperatorFactory.hpp>
#include <GameServer/Land/Operators/DeleteLand/DeleteLandOperatorFactory.hpp>
#include <GameServer/Land/Operators/GetLand/GetLandOperatorFactory.hpp>
#include <GameServer/Land/Operators/GetLands/GetLandsOperatorFactory.hpp>
#include <GameServer/Resource/Operators/GetResource/GetResourceOperatorFactory.hpp>
#include <GameServer/Resource/Operators/GetResources/GetResourcesOperatorFactory.hpp>
#include <GameServer/Settlement/Operators/CreateSettlement/CreateSettlementOperatorFactory.hpp>
#include <GameServer/Settlement/Operators/DeleteSettlement/DeleteSettlementOperatorFactory.hpp>
#include <GameServer/Settlement/Operators/GetSettlement/GetSettlementOperatorFactory.hpp>
#include <GameServer/Settlement/Operators/GetSettlements/GetSettlementsOperatorFactory.hpp>
#include <GameServer/Transport/Operators/TransportHuman/TransportHumanOperatorFactory.hpp>
#include <GameServer/Transport/Operators/TransportResource/TransportResourceOperatorFactory.hpp>
#include <GameServer/User/Operators/CreateUser/CreateUserOperatorFactory.hpp>
#include <GameServer/User/Operators/GetUser/GetUserOperatorFactory.hpp>
#include <GameServer/World/Operators/CreateWorld/CreateWorldOperatorFactory.hpp>
#include <GameServer/World/Operators/GetWorldByLandName/GetWorldByLandNameOperatorFactory.hpp>

using namespace GameServer::Authentication;
using namespace GameServer::Authorization;
using namespace GameServer::Building;
using namespace GameServer::Epoch;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::Transport;
using namespace GameServer::User;
using namespace GameServer::World;

namespace GameServer
{
namespace Common
{

OperatorAbstractFactoryPostgresql::OperatorAbstractFactoryPostgresql(
    IContextShrPtr const a_context
)
    : m_manager_abstract_factory(new ManagerAbstractFactoryPostgresql),
      m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
      m_context(a_context)
{
}

IAuthenticateOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthenticateOperator() const
{
    return IAuthenticateOperatorShrPtr(AuthenticateOperatorFactory::createAuthenticateOperator(m_persistence_facade_abstract_factory));
}

IAuthorizeUserToHolderOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToHolderOperator() const
{
    return IAuthorizeUserToHolderOperatorShrPtr(AuthorizeUserToHolderOperatorFactory::createAuthorizeUserToHolderOperator(m_persistence_facade_abstract_factory));
}

IAuthorizeUserToLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToLandOperator() const
{
    return IAuthorizeUserToLandOperatorShrPtr(AuthorizeUserToLandOperatorFactory::createAuthorizeUserToLandOperator(m_persistence_facade_abstract_factory));
}

IAuthorizeUserToSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createAuthorizeUserToSettlementOperator() const
{
    return IAuthorizeUserToSettlementOperatorShrPtr(AuthorizeUserToSettlementOperatorFactory::createAuthorizeUserToSettlementOperator(m_persistence_facade_abstract_factory));
}

IBuildBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createBuildBuildingOperator() const
{
    return IBuildBuildingOperatorShrPtr(BuildBuildingOperatorFactory::createBuildBuildingOperator(m_persistence_facade_abstract_factory));
}

IDestroyBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createDestroyBuildingOperator() const
{
    return IDestroyBuildingOperatorShrPtr(DestroyBuildingOperatorFactory::createDestroyBuildingOperator(m_persistence_facade_abstract_factory));
}

IGetBuildingOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetBuildingOperator() const
{
    return IGetBuildingOperatorShrPtr(GetBuildingOperatorFactory::createGetBuildingOperator(m_persistence_facade_abstract_factory));
}

IGetBuildingsOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetBuildingsOperator() const
{
    return IGetBuildingsOperatorShrPtr(GetBuildingsOperatorFactory::createGetBuildingsOperator(m_persistence_facade_abstract_factory));
}

IActivateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createActivateEpochOperator() const
{
    return IActivateEpochOperatorShrPtr(ActivateEpochOperatorFactory::createActivateEpochOperator(m_persistence_facade_abstract_factory));
}

ICreateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateEpochOperator() const
{
    return ICreateEpochOperatorShrPtr(CreateEpochOperatorFactory::createCreateEpochOperator(m_persistence_facade_abstract_factory));
}

IDeactivateEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeactivateEpochOperator() const
{
    return IDeactivateEpochOperatorShrPtr(DeactivateEpochOperatorFactory::createDeactivateEpochOperator(m_persistence_facade_abstract_factory));
}

IDeleteEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteEpochOperator() const
{
    return IDeleteEpochOperatorShrPtr(DeleteEpochOperatorFactory::createDeleteEpochOperator(m_persistence_facade_abstract_factory));
}

IFinishEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createFinishEpochOperator() const
{
    return IFinishEpochOperatorShrPtr(FinishEpochOperatorFactory::createFinishEpochOperator(m_persistence_facade_abstract_factory));
}

IGetEpochByLandNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochByLandNameOperator() const
{
    return IGetEpochByLandNameOperatorShrPtr(GetEpochByLandNameOperatorFactory::createGetEpochByLandNameOperator(m_persistence_facade_abstract_factory));
}

IGetEpochBySettlementNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochBySettlementNameOperator() const
{
    return IGetEpochBySettlementNameOperatorShrPtr(GetEpochBySettlementNameOperatorFactory::createGetEpochBySettlementNameOperator(m_persistence_facade_abstract_factory));
}

IGetEpochByWorldNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetEpochByWorldNameOperator() const
{
    return IGetEpochByWorldNameOperatorShrPtr(GetEpochByWorldNameOperatorFactory::createGetEpochByWorldNameOperator(m_persistence_facade_abstract_factory));
}

ITickEpochOperatorShrPtr OperatorAbstractFactoryPostgresql::createTickEpochOperator() const
{
    return ITickEpochOperatorShrPtr(
               TickEpochOperatorFactory::createTickEpochOperator(
                    m_manager_abstract_factory,
                    m_persistence_facade_abstract_factory
               )
           );
}

IDismissHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createDismissHumanOperator() const
{
    return IDismissHumanOperatorShrPtr(DismissHumanOperatorFactory::createDismissHumanOperator(m_persistence_facade_abstract_factory));
}

IEngageHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createEngageHumanOperator() const
{
    return IEngageHumanOperatorShrPtr(EngageHumanOperatorFactory::createEngageHumanOperator(m_persistence_facade_abstract_factory));
}

IGetHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetHumanOperator() const
{
    return IGetHumanOperatorShrPtr(GetHumanOperatorFactory::createGetHumanOperator(m_persistence_facade_abstract_factory));
}

IGetHumansOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetHumansOperator() const
{
    return IGetHumansOperatorShrPtr(GetHumansOperatorFactory::createGetHumansOperator(m_persistence_facade_abstract_factory));
}

ICreateLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateLandOperator() const
{
    return ICreateLandOperatorShrPtr(CreateLandOperatorFactory::createCreateLandOperator(m_persistence_facade_abstract_factory));
}

IDeleteLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteLandOperator() const
{
    return IDeleteLandOperatorShrPtr( DeleteLandOperatorFactory::createDeleteLandOperator(m_persistence_facade_abstract_factory));
}

IGetLandOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetLandOperator() const
{
    return IGetLandOperatorShrPtr(GetLandOperatorFactory::createGetLandOperator(m_persistence_facade_abstract_factory));
}

IGetLandsOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetLandsOperator() const
{
    return IGetLandsOperatorShrPtr(GetLandsOperatorFactory::createGetLandsOperator(m_persistence_facade_abstract_factory));
}

IGetResourceOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetResourceOperator() const
{
    return IGetResourceOperatorShrPtr(GetResourceOperatorFactory::createGetResourceOperator(m_persistence_facade_abstract_factory));
}

IGetResourcesOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetResourcesOperator() const
{
    return IGetResourcesOperatorShrPtr(GetResourcesOperatorFactory::createGetResourcesOperator(m_persistence_facade_abstract_factory));
}

ICreateSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateSettlementOperator() const
{
    return ICreateSettlementOperatorShrPtr(CreateSettlementOperatorFactory::createCreateSettlementOperator(m_persistence_facade_abstract_factory));
}

IDeleteSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createDeleteSettlementOperator() const
{
    return IDeleteSettlementOperatorShrPtr(DeleteSettlementOperatorFactory::createDeleteSettlementOperator(m_persistence_facade_abstract_factory));
}

IGetSettlementOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetSettlementOperator() const
{
    return IGetSettlementOperatorShrPtr(GetSettlementOperatorFactory::createGetSettlementOperator(m_persistence_facade_abstract_factory));
}

IGetSettlementsOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetSettlementsOperator() const
{
    return IGetSettlementsOperatorShrPtr(GetSettlementsOperatorFactory::createGetSettlementsOperator(m_persistence_facade_abstract_factory));
}

ITransportHumanOperatorShrPtr OperatorAbstractFactoryPostgresql::createTransportHumanOperator() const
{
    return ITransportHumanOperatorShrPtr(TransportHumanOperatorFactory::createTransportHumanOperator(m_persistence_facade_abstract_factory));
}

ITransportResourceOperatorShrPtr OperatorAbstractFactoryPostgresql::createTransportResourceOperator() const
{
    return ITransportResourceOperatorShrPtr(TransportResourceOperatorFactory::createTransportResourceOperator(m_persistence_facade_abstract_factory));
}

ICreateUserOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateUserOperator() const
{
    return ICreateUserOperatorShrPtr(CreateUserOperatorFactory::createCreateUserOperator(m_persistence_facade_abstract_factory));
}

IGetUserOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetUserOperator() const
{
    return IGetUserOperatorShrPtr(GetUserOperatorFactory::createGetUserOperator(m_persistence_facade_abstract_factory));
}

ICreateWorldOperatorShrPtr OperatorAbstractFactoryPostgresql::createCreateWorldOperator() const
{
    return ICreateWorldOperatorShrPtr(CreateWorldOperatorFactory::createCreateWorldOperator(m_persistence_facade_abstract_factory));
}

IGetWorldByLandNameOperatorShrPtr OperatorAbstractFactoryPostgresql::createGetWorldByLandNameOperator() const
{
    return IGetWorldByLandNameOperatorShrPtr(GetWorldByLandNameOperatorFactory::createGetWorldByLandNameOperator(m_persistence_facade_abstract_factory));
}

} // namespace Common
} // namespace GameServer
