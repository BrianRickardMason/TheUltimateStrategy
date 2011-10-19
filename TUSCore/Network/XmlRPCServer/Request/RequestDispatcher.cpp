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

#include <Network/XmlRPCServer/Request/Executors/Building/ExecutorBuildBuilding.hpp>
#include <Network/XmlRPCServer/Request/Executors/Building/ExecutorDestroyBuilding.hpp>
#include <Network/XmlRPCServer/Request/Executors/Building/ExecutorGetBuilding.hpp>
#include <Network/XmlRPCServer/Request/Executors/Building/ExecutorGetBuildings.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorActivateEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorCreateEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorDeactivateEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorDeleteEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorFinishEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorGetEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Epoch/ExecutorTickEpoch.hpp>
#include <Network/XmlRPCServer/Request/Executors/Generic/ExecutorEcho.hpp>
#include <Network/XmlRPCServer/Request/Executors/Generic/ExecutorError.hpp>
#include <Network/XmlRPCServer/Request/Executors/Human/ExecutorDismissHuman.hpp>
#include <Network/XmlRPCServer/Request/Executors/Human/ExecutorEngageHuman.hpp>
#include <Network/XmlRPCServer/Request/Executors/Human/ExecutorGetHuman.hpp>
#include <Network/XmlRPCServer/Request/Executors/Human/ExecutorGetHumans.hpp>
#include <Network/XmlRPCServer/Request/Executors/Land/ExecutorCreateLand.hpp>
#include <Network/XmlRPCServer/Request/Executors/Land/ExecutorDeleteLand.hpp>
#include <Network/XmlRPCServer/Request/Executors/Land/ExecutorGetLand.hpp>
#include <Network/XmlRPCServer/Request/Executors/Land/ExecutorGetLands.hpp>
#include <Network/XmlRPCServer/Request/Executors/Resource/ExecutorGetResource.hpp>
#include <Network/XmlRPCServer/Request/Executors/Resource/ExecutorGetResources.hpp>
#include <Network/XmlRPCServer/Request/Executors/Settlement/ExecutorCreateSettlement.hpp>
#include <Network/XmlRPCServer/Request/Executors/Settlement/ExecutorDeleteSettlement.hpp>
#include <Network/XmlRPCServer/Request/Executors/Settlement/ExecutorGetSettlement.hpp>
#include <Network/XmlRPCServer/Request/Executors/Settlement/ExecutorGetSettlements.hpp>
#include <Network/XmlRPCServer/Request/Executors/Transport/ExecutorTransportHuman.hpp>
#include <Network/XmlRPCServer/Request/Executors/Transport/ExecutorTransportResource.hpp>
#include <Network/XmlRPCServer/Request/Executors/Turn/ExecutorTurn.hpp>
#include <Network/XmlRPCServer/Request/Executors/User/ExecutorCreateUser.hpp>
#include <Network/XmlRPCServer/Request/Executors/World/ExecutorCreateWorld.hpp>
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
        case REQUEST_ID_GET_LAND:
            return shared_ptr<IExecutor>(new ExecutorGetLand);
        case REQUEST_ID_GET_LANDS:
            return shared_ptr<IExecutor>(new ExecutorGetLands);
        case REQUEST_ID_CREATE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorCreateSettlement);
        case REQUEST_ID_DELETE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorDeleteSettlement);
        case REQUEST_ID_GET_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorGetSettlement);
        case REQUEST_ID_GET_SETTLEMENTS:
            return shared_ptr<IExecutor>(new ExecutorGetSettlements);
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
