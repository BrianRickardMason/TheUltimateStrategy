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

#include <Server/Network/XmlRPCServer/Request/Executors/Building/ExecutorBuildBuilding.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Building/ExecutorDestroyBuilding.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Building/ExecutorGetBuilding.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Building/ExecutorGetBuildings.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorActivateEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorCreateEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorDeactivateEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorDeleteEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorFinishEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorGetEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Epoch/ExecutorTickEpoch.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Generic/ExecutorEcho.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Generic/ExecutorError.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Human/ExecutorDismissHuman.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Human/ExecutorEngageHuman.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Human/ExecutorGetHuman.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Human/ExecutorGetHumans.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Land/ExecutorCreateLand.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Land/ExecutorDeleteLand.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Land/ExecutorGetLand.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Land/ExecutorGetLands.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Resource/ExecutorGetResource.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Resource/ExecutorGetResources.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Settlement/ExecutorCreateSettlement.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Settlement/ExecutorDeleteSettlement.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Settlement/ExecutorGetSettlement.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Settlement/ExecutorGetSettlements.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Transport/ExecutorTransportHuman.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/Transport/ExecutorTransportResource.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/User/ExecutorCreateUser.hpp>
#include <Server/Network/XmlRPCServer/Request/Executors/World/ExecutorCreateWorld.hpp>
#include <Server/Network/XmlRPCServer/Request/RequestDispatcher.hpp>

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
    RequestShrPtr        a_request,
    IContextShrPtr const a_context
) const
{
    if (!a_request)
    {
        return shared_ptr<IExecutor>(new ExecutorError(a_context));
    }

    switch (a_request->getIdRequest())
    {
        case REQUEST_ID_ECHO:
            return shared_ptr<IExecutor>(new ExecutorEcho(a_context));
        case REQUEST_ID_CREATE_LAND:
            return shared_ptr<IExecutor>(new ExecutorCreateLand(a_context));
        case REQUEST_ID_DELETE_LAND:
            return shared_ptr<IExecutor>(new ExecutorDeleteLand(a_context));
        case REQUEST_ID_GET_LAND:
            return shared_ptr<IExecutor>(new ExecutorGetLand(a_context));
        case REQUEST_ID_GET_LANDS:
            return shared_ptr<IExecutor>(new ExecutorGetLands(a_context));
        case REQUEST_ID_CREATE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorCreateSettlement(a_context));
        case REQUEST_ID_DELETE_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorDeleteSettlement(a_context));
        case REQUEST_ID_GET_SETTLEMENT:
            return shared_ptr<IExecutor>(new ExecutorGetSettlement(a_context));
        case REQUEST_ID_GET_SETTLEMENTS:
            return shared_ptr<IExecutor>(new ExecutorGetSettlements(a_context));
        case REQUEST_ID_BUILD_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorBuildBuilding(a_context));
        case REQUEST_ID_DESTROY_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorDestroyBuilding(a_context));
        case REQUEST_ID_GET_BUILDING:
            return shared_ptr<IExecutor>(new ExecutorGetBuilding(a_context));
        case REQUEST_ID_GET_BUILDINGS:
            return shared_ptr<IExecutor>(new ExecutorGetBuildings(a_context));
        case REQUEST_ID_DISMISS_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorDismissHuman(a_context));
        case REQUEST_ID_ENGAGE_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorEngageHuman(a_context));
        case REQUEST_ID_GET_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorGetHuman(a_context));
        case REQUEST_ID_GET_HUMANS:
            return shared_ptr<IExecutor>(new ExecutorGetHumans(a_context));
        case REQUEST_ID_GET_RESOURCE:
            return shared_ptr<IExecutor>(new ExecutorGetResource(a_context));
        case REQUEST_ID_GET_RESOURCES:
            return shared_ptr<IExecutor>(new ExecutorGetResources(a_context));
        case REQUEST_ID_CREATE_USER:
            return shared_ptr<IExecutor>(new ExecutorCreateUser(a_context));
        case REQUEST_ID_CREATE_WORLD:
            return shared_ptr<IExecutor>(new ExecutorCreateWorld(a_context));
        case REQUEST_ID_ACTIVATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorActivateEpoch(a_context));
        case REQUEST_ID_CREATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorCreateEpoch(a_context));
        case REQUEST_ID_DELETE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorDeleteEpoch(a_context));
        case REQUEST_ID_DEACTIVATE_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorDeactivateEpoch(a_context));
        case REQUEST_ID_FINISH_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorFinishEpoch(a_context));
        case REQUEST_ID_TICK_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorTickEpoch(a_context));
        case REQUEST_ID_GET_EPOCH:
            return shared_ptr<IExecutor>(new ExecutorGetEpoch(a_context));
        case REQUEST_ID_TRANSPORT_HUMAN:
            return shared_ptr<IExecutor>(new ExecutorTransportHuman(a_context));
        case REQUEST_ID_TRANSPORT_RESOURCE:
            return shared_ptr<IExecutor>(new ExecutorTransportResource(a_context));
        default:
            return shared_ptr<IExecutor>(new ExecutorError(a_context));
    }
}

} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
