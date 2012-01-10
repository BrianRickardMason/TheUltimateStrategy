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

#include <Protocol/Xml/Cpp/LanguageToProtocolTranslator.hpp>
#include <Protocol/Xml/Cpp/MessageFactory.hpp>
#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

namespace TUSProtocol
{

// TODO: Consider removing lexical cast.

Message::SingleHandle LanguageToProtocolTranslator::translate(
    TUSLanguage::ICommand::SingleHandle a_command
) const
{
    MessageFactory message_factory;

    switch (a_command->getID())
    {
        case TUSLanguage::ID_COMMAND_ECHO_REQUEST:
            return message_factory.createEchoRequest();

        case TUSLanguage::ID_COMMAND_ERROR_REQUEST:
            return message_factory.createErrorRequest();

        case TUSLanguage::ID_COMMAND_CREATE_LAND_REQUEST:
            return message_factory.createCreateLandRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name"),
                       a_command->getParam("land_name")
                   );

        case TUSLanguage::ID_COMMAND_DELETE_LAND_REQUEST:
            return message_factory.createDeleteLandRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("land_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_LAND_REQUEST:
            return message_factory.createGetLandRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("land_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_LANDS_REQUEST:
            return message_factory.createGetLandsRequest(
                       a_command->getLogin(),
                       a_command->getPassword()
                   );

        case TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REQUEST:
            return message_factory.createCreateSettlementRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("land_name"),
                       a_command->getParam("settlement_name")
                   );

        case TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REQUEST:
            return message_factory.createDeleteSettlementRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("settlement_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REQUEST:
            return message_factory.createGetSettlementRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("settlement_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REQUEST:
            return message_factory.createGetSettlementsRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("land_name")
                   );

        case TUSLanguage::ID_COMMAND_BUILD_BUILDING_REQUEST:
            return message_factory.createBuildBuildingRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("buildingkey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REQUEST:
            return message_factory.createDestroyBuildingRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("buildingkey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_GET_BUILDING_REQUEST:
            return message_factory.createGetBuildingRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("buildingkey")
                   );

        case TUSLanguage::ID_COMMAND_GET_BUILDINGS_REQUEST:
            return message_factory.createGetBuildingsRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name")
                   );

        case TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REQUEST:
            return message_factory.createDismissHumanRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("humankey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REQUEST:
            return message_factory.createEngageHumanRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("humankey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_GET_HUMAN_REQUEST:
            return message_factory.createGetHumanRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("humankey")
                   );

        case TUSLanguage::ID_COMMAND_GET_HUMANS_REQUEST:
            return message_factory.createGetHumansRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_RESOURCE_REQUEST:
            return message_factory.createGetResourceRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name"),
                       a_command->getParam("resourcekey")
                   );

        case TUSLanguage::ID_COMMAND_GET_RESOURCES_REQUEST:
            return message_factory.createGetResourcesRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("idholderclass"),
                       a_command->getParam("holder_name")
                   );

        case TUSLanguage::ID_COMMAND_CREATE_USER_REQUEST:
            return message_factory.createCreateUserRequest(
                       a_command->getParam("login"),
                       a_command->getParam("password")
                   );

        case TUSLanguage::ID_COMMAND_CREATE_WORLD_REQUEST:
            return message_factory.createCreateWorldRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_CREATE_EPOCH_REQUEST:
            return message_factory.createCreateEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name"),
                       a_command->getParam("epoch_name")
                   );

        case TUSLanguage::ID_COMMAND_DELETE_EPOCH_REQUEST:
            return message_factory.createDeleteEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REQUEST:
            return message_factory.createActivateEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REQUEST:
            return message_factory.createDeactivateEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_FINISH_EPOCH_REQUEST:
            return message_factory.createFinishEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_TICK_EPOCH_REQUEST:
            return message_factory.createTickEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_GET_EPOCH_REQUEST:
            return message_factory.createGetEpochRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("world_name")
                   );

        case TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REQUEST:
            return message_factory.createTransportHumanRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("settlement_name_source"),
                       a_command->getParam("settlement_name_destination"),
                       a_command->getParam("humankey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REQUEST:
            return message_factory.createTransportResourceRequest(
                       a_command->getLogin(),
                       a_command->getPassword(),
                       a_command->getParam("settlement_name_source"),
                       a_command->getParam("settlement_name_destination"),
                       a_command->getParam("resourcekey"),
                       a_command->getParam("volume")
                   );

        case TUSLanguage::ID_COMMAND_ECHO_REPLY:
            return message_factory.createEchoReply(
                       boost::lexical_cast<std::string>(a_command->getCode())
                   );

        case TUSLanguage::ID_COMMAND_ERROR_REPLY:
            return message_factory.createErrorReply(
                       boost::lexical_cast<std::string>(a_command->getCode())
                   );

        case TUSLanguage::ID_COMMAND_CREATE_LAND_REPLY:
            return message_factory.createCreateLandReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_DELETE_LAND_REPLY:
            return message_factory.createDeleteLandReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_GET_LAND_REPLY:
            return message_factory.createGetLandReply(
                    boost::lexical_cast<std::string>(a_command->getCode()),
                        a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_GET_LANDS_REPLY:
            return message_factory.createGetLandsReply(
                    boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects()
                   );

        case TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REPLY:
            return message_factory.createCreateSettlementReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REPLY:
            return message_factory.createDeleteSettlementReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REPLY:
            return message_factory.createGetSettlementReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REPLY:
            return message_factory.createGetSettlementsReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects()
                   );

        case TUSLanguage::ID_COMMAND_BUILD_BUILDING_REPLY:
            return message_factory.createBuildBuildingReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REPLY:
            return message_factory.createDestroyBuildingReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_GET_BUILDING_REPLY:
            return message_factory.createGetBuildingReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_GET_BUILDINGS_REPLY:
            return message_factory.createGetBuildingsReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects()
                   );

        case TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REPLY:
            return message_factory.createDismissHumanReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REPLY:
            return message_factory.createEngageHumanReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_GET_HUMAN_REPLY:
            return message_factory.createGetHumanReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_GET_HUMANS_REPLY:
            return message_factory.createGetHumansReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects()
                   );

        case TUSLanguage::ID_COMMAND_GET_RESOURCE_REPLY:
            return message_factory.createGetResourceReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_GET_RESOURCES_REPLY:
            return message_factory.createGetResourcesReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects()
                   );

        case TUSLanguage::ID_COMMAND_CREATE_USER_REPLY:
            return message_factory.createCreateUserReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_CREATE_WORLD_REPLY:
            return message_factory.createCreateWorldReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_CREATE_EPOCH_REPLY:
            return message_factory.createCreateEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_DELETE_EPOCH_REPLY:
            return message_factory.createDeleteEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REPLY:
            return message_factory.createActivateEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REPLY:
            return message_factory.createDeactivateEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_FINISH_EPOCH_REPLY:
            return message_factory.createFinishEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_TICK_EPOCH_REPLY:
            return message_factory.createTickEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_GET_EPOCH_REPLY:
            return message_factory.createGetEpochReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage(),
                       a_command->getObjects().front()
                   );

        case TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REPLY:
            return message_factory.createTransportHumanReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        case TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REPLY:
            return message_factory.createTransportResourceReply(
                       boost::lexical_cast<std::string>(a_command->getCode()),
                       a_command->getMessage()
                   );

        default:
            BOOST_ASSERT_MSG(false, "Invalid command ID.");
    }
}

} // namespace TUSProtocol
