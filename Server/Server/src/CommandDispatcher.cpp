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

#include <Game/GameServer/Building/Executors/ExecutorBuildBuilding.hpp>
#include <Game/GameServer/Building/Executors/ExecutorDestroyBuilding.hpp>
#include <Game/GameServer/Building/Executors/ExecutorGetBuilding.hpp>
#include <Game/GameServer/Building/Executors/ExecutorGetBuildings.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorActivateEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorCreateEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorDeactivateEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorDeleteEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorFinishEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorGetEpoch.hpp>
#include <Game/GameServer/Epoch/Executors/ExecutorTickEpoch.hpp>
#include <Game/GameServer/Generic/Executors/ExecutorEcho.hpp>
#include <Game/GameServer/Generic/Executors/ExecutorError.hpp>
#include <Game/GameServer/Human/Executors/ExecutorDismissHuman.hpp>
#include <Game/GameServer/Human/Executors/ExecutorEngageHuman.hpp>
#include <Game/GameServer/Human/Executors/ExecutorGetHuman.hpp>
#include <Game/GameServer/Human/Executors/ExecutorGetHumans.hpp>
#include <Game/GameServer/Land/Executors/ExecutorCreateLand.hpp>
#include <Game/GameServer/Land/Executors/ExecutorDeleteLand.hpp>
#include <Game/GameServer/Land/Executors/ExecutorGetLand.hpp>
#include <Game/GameServer/Land/Executors/ExecutorGetLands.hpp>
#include <Game/GameServer/Resource/Executors/ExecutorGetResource.hpp>
#include <Game/GameServer/Resource/Executors/ExecutorGetResources.hpp>
#include <Game/GameServer/Settlement/Executors/ExecutorCreateSettlement.hpp>
#include <Game/GameServer/Settlement/Executors/ExecutorDeleteSettlement.hpp>
#include <Game/GameServer/Settlement/Executors/ExecutorGetSettlement.hpp>
#include <Game/GameServer/Settlement/Executors/ExecutorGetSettlements.hpp>
#include <Game/GameServer/Transport/Executors/ExecutorTransportHuman.hpp>
#include <Game/GameServer/Transport/Executors/ExecutorTransportResource.hpp>
#include <Game/GameServer/User/Executors/ExecutorCreateUser.hpp>
#include <Game/GameServer/World/Executors/ExecutorCreateWorld.hpp>
#include <Server/Server/include/CommandDispatcher.hpp>

namespace Server
{

Game::IExecutorShrPtr CommandDispatcher::dispatch(
    TUSLanguage::ICommand::Handle const aCommand,
    IContextShrPtr                const aContext
) const
{
    using namespace Game;
    using namespace TUSLanguage;

    if (!aCommand)
    {
        return IExecutorShrPtr(new ExecutorError(aContext));
    }

    switch (aCommand->getID())
    {
        case ID_COMMAND_ECHO_REQUEST:               return IExecutorShrPtr(new ExecutorEcho(aContext));
        case ID_COMMAND_CREATE_LAND_REQUEST:        return IExecutorShrPtr(new ExecutorCreateLand(aContext));
        case ID_COMMAND_DELETE_LAND_REQUEST:        return IExecutorShrPtr(new ExecutorDeleteLand(aContext));
        case ID_COMMAND_GET_LAND_REQUEST:           return IExecutorShrPtr(new ExecutorGetLand(aContext));
        case ID_COMMAND_GET_LANDS_REQUEST:          return IExecutorShrPtr(new ExecutorGetLands(aContext));
        case ID_COMMAND_CREATE_SETTLEMENT_REQUEST:  return IExecutorShrPtr(new ExecutorCreateSettlement(aContext));
        case ID_COMMAND_DELETE_SETTLEMENT_REQUEST:  return IExecutorShrPtr(new ExecutorDeleteSettlement(aContext));
        case ID_COMMAND_GET_SETTLEMENT_REQUEST:     return IExecutorShrPtr(new ExecutorGetSettlement(aContext));
        case ID_COMMAND_GET_SETTLEMENTS_REQUEST:    return IExecutorShrPtr(new ExecutorGetSettlements(aContext));
        case ID_COMMAND_BUILD_BUILDING_REQUEST:     return IExecutorShrPtr(new ExecutorBuildBuilding(aContext));
        case ID_COMMAND_DESTROY_BUILDING_REQUEST:   return IExecutorShrPtr(new ExecutorDestroyBuilding(aContext));
        case ID_COMMAND_GET_BUILDING_REQUEST:       return IExecutorShrPtr(new ExecutorGetBuilding(aContext));
        case ID_COMMAND_GET_BUILDINGS_REQUEST:      return IExecutorShrPtr(new ExecutorGetBuildings(aContext));
        case ID_COMMAND_DISMISS_HUMAN_REQUEST:      return IExecutorShrPtr(new ExecutorDismissHuman(aContext));
        case ID_COMMAND_ENGAGE_HUMAN_REQUEST:       return IExecutorShrPtr(new ExecutorEngageHuman(aContext));
        case ID_COMMAND_GET_HUMAN_REQUEST:          return IExecutorShrPtr(new ExecutorGetHuman(aContext));
        case ID_COMMAND_GET_HUMANS_REQUEST:         return IExecutorShrPtr(new ExecutorGetHumans(aContext));
        case ID_COMMAND_GET_RESOURCE_REQUEST:       return IExecutorShrPtr(new ExecutorGetResource(aContext));
        case ID_COMMAND_GET_RESOURCES_REQUEST:      return IExecutorShrPtr(new ExecutorGetResources(aContext));
        case ID_COMMAND_CREATE_USER_REQUEST:        return IExecutorShrPtr(new ExecutorCreateUser(aContext));
        case ID_COMMAND_CREATE_WORLD_REQUEST:       return IExecutorShrPtr(new ExecutorCreateWorld(aContext));
        case ID_COMMAND_CREATE_EPOCH_REQUEST:       return IExecutorShrPtr(new ExecutorCreateEpoch(aContext));
        case ID_COMMAND_DELETE_EPOCH_REQUEST:       return IExecutorShrPtr(new ExecutorDeleteEpoch(aContext));
        case ID_COMMAND_ACTIVATE_EPOCH_REQUEST:     return IExecutorShrPtr(new ExecutorActivateEpoch(aContext));
        case ID_COMMAND_DEACTIVATE_EPOCH_REQUEST:   return IExecutorShrPtr(new ExecutorDeactivateEpoch(aContext));
        case ID_COMMAND_FINISH_EPOCH_REQUEST:       return IExecutorShrPtr(new ExecutorFinishEpoch(aContext));
        case ID_COMMAND_TICK_EPOCH_REQUEST:         return IExecutorShrPtr(new ExecutorTickEpoch(aContext));
        case ID_COMMAND_GET_EPOCH_REQUEST:          return IExecutorShrPtr(new ExecutorGetEpoch(aContext));
        case ID_COMMAND_TRANSPORT_HUMAN_REQUEST:    return IExecutorShrPtr(new ExecutorTransportHuman(aContext));
        case ID_COMMAND_TRANSPORT_RESOURCE_REQUEST: return IExecutorShrPtr(new ExecutorTransportResource(aContext));
        default:                                    return IExecutorShrPtr(new ExecutorError(aContext));
    }
}

} // namespace Server
