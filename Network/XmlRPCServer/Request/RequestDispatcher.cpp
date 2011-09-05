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

#include "Executors/Building/ExecutorBuildBuilding.hpp"
#include "Executors/Building/ExecutorDestroyBuilding.hpp"
#include "Executors/Building/ExecutorGetBuilding.hpp"
#include "Executors/Building/ExecutorGetBuildings.hpp"
#include "Executors/Epoch/ExecutorActivateEpoch.hpp"
#include "Executors/Epoch/ExecutorCreateEpoch.hpp"
#include "Executors/Epoch/ExecutorDeactivateEpoch.hpp"
#include "Executors/Epoch/ExecutorDeleteEpoch.hpp"
#include "Executors/Epoch/ExecutorFinishEpoch.hpp"
#include "Executors/Epoch/ExecutorGetEpoch.hpp"
#include "Executors/Epoch/ExecutorTickEpoch.hpp"
#include "Executors/Generic/ExecutorEcho.hpp"
#include "Executors/Generic/ExecutorError.hpp"
#include "Executors/Human/ExecutorDismissHuman.hpp"
#include "Executors/Human/ExecutorEngageHuman.hpp"
#include "Executors/Human/ExecutorGetHuman.hpp"
#include "Executors/Human/ExecutorGetHumans.hpp"
#include "Executors/Land/ExecutorCreateLand.hpp"
#include "Executors/Land/ExecutorDeleteLand.hpp"
#include "Executors/Land/ExecutorGetLandByIDLand.hpp"
#include "Executors/Land/ExecutorGetLandByName.hpp"
#include "Executors/Land/ExecutorGetLandsByIDWorld.hpp"
#include "Executors/Resource/ExecutorGetResource.hpp"
#include "Executors/Resource/ExecutorGetResources.hpp"
#include "Executors/Settlement/ExecutorCreateSettlement.hpp"
#include "Executors/Settlement/ExecutorDeleteSettlement.hpp"
#include "Executors/Settlement/ExecutorGetSettlementByIDLandAndName.hpp"
#include "Executors/Settlement/ExecutorGetSettlementByIDSettlement.hpp"
#include "Executors/Settlement/ExecutorGetSettlementsByIDLand.hpp"
#include "Executors/Transport/ExecutorTransportHuman.hpp"
#include "Executors/Transport/ExecutorTransportResource.hpp"
#include "Executors/Turn/ExecutorTurn.hpp"
#include "Executors/User/ExecutorCreateUser.hpp"
#include "Executors/World/ExecutorCreateWorld.hpp"
#include "RequestDispatcher.hpp"

using namespace Network::XmlRPCCommon::Request;
using namespace Network::XmlRPCServer::Request::Executors;
using namespace boost;

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{

IExecutorShrPtr RequestDispatcher::dispatchRequest(
    RequestShrPtr a_request
) const
{
    if (!a_request)
    {
        return shared_ptr<IExecutor>(new ExecutorError);
    }

    switch (a_request->getIdRequest())
    {
        case REQUEST_ID_ECHO:
            return shared_ptr<IExecutor>(new ExecutorEcho);
        case REQUEST_ID_CREATE_LAND:
            return shared_ptr<IExecutor>(new ExecutorCreateLand);
        case REQUEST_ID_DELETE_LAND:
            return shared_ptr<IExecutor>(new ExecutorDeleteLand);
        case REQUEST_ID_GET_LAND_BY_ID_LAND:
            return shared_ptr<IExecutor>(new ExecutorGetLandByIDLand);
        case REQUEST_ID_GET_LAND_BY_NAME:
            return shared_ptr<IExecutor>(new ExecutorGetLandByName);
        case REQUEST_ID_GET_LANDS_BY_ID_WORLD:
            return shared_ptr<IExecutor>(new ExecutorGetLandsByIDWorld);
        case REQUEST_ID_CREATE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorCreateSettlement);
        case REQUEST_ID_DELETE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorDeleteSettlement);
        case REQUEST_ID_GET_SETTLEMENT_BY_ID_LAND_AND_NAME:
            return shared_ptr<IExecutor>(new ExecutorGetSettlementByIDLandAndName);
        case REQUEST_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorGetSettlementByIDSettlement);
        case REQUEST_ID_GET_SETTLEMENTS_BY_ID_LAND:
            return shared_ptr<IExecutor>(new ExecutorGetSettlementsByIDLand);
        case REQUEST_ID_BUILD_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorBuildBuilding);
        case REQUEST_ID_DESTROY_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorDestroyBuilding);
        case REQUEST_ID_GET_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorGetBuilding);
        case REQUEST_ID_GET_BUILDINGS:
            return shared_ptr<IExecutor>(new ExecutorGetBuildings);
        case REQUEST_ID_DISMISS_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorDismissHuman);
        case REQUEST_ID_ENGAGE_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorEngageHuman);
        case REQUEST_ID_GET_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorGetHuman);
        case REQUEST_ID_GET_HUMANS:
            return shared_ptr<IExecutor>(new ExecutorGetHumans);
        case REQUEST_ID_GET_RESOURCE:
            return shared_ptr<IExecutor>(new ExecutorGetResource);
        case REQUEST_ID_GET_RESOURCES:
            return shared_ptr<IExecutor>(new ExecutorGetResources);
        case REQUEST_ID_CREATE_USER:
            return shared_ptr<IExecutor>(new ExecutorCreateUser);
        case REQUEST_ID_CREATE_WORLD:
            return shared_ptr<IExecutor>(new ExecutorCreateWorld);
        case REQUEST_ID_ACTIVATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorActivateEpoch);
        case REQUEST_ID_CREATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorCreateEpoch);
        case REQUEST_ID_DELETE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorDeleteEpoch);
        case REQUEST_ID_DEACTIVATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorDeactivateEpoch);
        case REQUEST_ID_FINISH_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorFinishEpoch);
        case REQUEST_ID_TICK_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorTickEpoch);
        case REQUEST_ID_GET_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorGetEpoch);
        case REQUEST_ID_TURN:
            return shared_ptr<IExecutor>(new ExecutorTurn);
        case REQUEST_ID_TRANSPORT_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorTransportHuman);
        case REQUEST_ID_TRANSPORT_RESOURCE:
            return shared_ptr<IExecutor>(new ExecutorTransportResource);
        default:
            return shared_ptr<IExecutor>(new ExecutorError);
    }
}

} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
