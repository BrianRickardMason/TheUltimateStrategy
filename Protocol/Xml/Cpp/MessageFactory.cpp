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

#include <Language/Interface/ICommand.hpp>
#include <Protocol/Xml/Cpp/MessageBuilder.hpp>
#include <Protocol/Xml/Cpp/MessageFactory.hpp>

namespace TUSProtocol
{

Message::Handle MessageFactory::createEchoRequest() const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ECHO_REQUEST);

    return message_builder.extract();
}

Message::Handle MessageFactory::createErrorRequest() const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ERROR_REQUEST);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_LAND_REQUEST, "Login", "Password");
    message_builder.addRequest("create_land_request");
    message_builder.addParam("world_name", a_world_name);
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_LAND_REQUEST, "Login", "Password");
    message_builder.addRequest("delete_land_request");
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LAND_REQUEST, "Login", "Password");
    message_builder.addRequest("get_land_request");
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandsRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LANDS_REQUEST, "Login", "Password");
    message_builder.addRequest("get_lands_request");

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REQUEST, "Login", "Password");
    message_builder.addRequest("create_settlement_request");
    message_builder.addParam("land_name", a_land_name);
    message_builder.addParam("settlement_name", a_settlement_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REQUEST, "Login", "Password");
    message_builder.addRequest("delete_settlement_request");
    message_builder.addParam("settlement_name", a_settlement_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REQUEST, "Login", "Password");
    message_builder.addRequest("get_settlement_request");
    message_builder.addParam("settlement_name", a_settlement_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetSettlementsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REQUEST, "Login", "Password");
    message_builder.addRequest("get_settlements_request");
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createBuildBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_BUILD_BUILDING_REQUEST, "Login", "Password");
    message_builder.addRequest("build_building_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("buildingkey", a_building_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDestroyBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REQUEST, "Login", "Password");
    message_builder.addRequest("destroy_building_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("buildingkey", a_building_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_BUILDING_REQUEST, "Login", "Password");
    message_builder.addRequest("get_building_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("buildingkey", a_building_key);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetBuildingsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_BUILDINGS_REQUEST, "Login", "Password");
    message_builder.addRequest("get_buildings_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDismissHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REQUEST, "Login", "Password");
    message_builder.addRequest("dismiss_human_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("humankey", a_human_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createEngageHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REQUEST, "Login", "Password");
    message_builder.addRequest("engage_human_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("humankey", a_human_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_HUMAN_REQUEST, "Login", "Password");
    message_builder.addRequest("get_human_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("humankey", a_human_key);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetHumansRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_HUMANS_REQUEST, "Login", "Password");
    message_builder.addRequest("get_humans_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetResourceRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_resource_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_RESOURCE_REQUEST, "Login", "Password");
    message_builder.addRequest("get_resource_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);
    message_builder.addParam("resourcekey", a_resource_key);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetResourcesRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_RESOURCES_REQUEST, "Login", "Password");
    message_builder.addRequest("get_resources_request");
    message_builder.addParam("idholderclass", a_id_holder_class);
    message_builder.addParam("holder_name", a_holder_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateUserRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_USER_REQUEST);
    message_builder.addRequest("create_user_request");
    message_builder.addParam("login", a_login);
    message_builder.addParam("password", a_password);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateWorldRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_WORLD_REQUEST, "Login", "Password");
    message_builder.addRequest("create_world_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_epoch_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("create_epoch_request");
    message_builder.addParam("world_name", a_world_name);
    message_builder.addParam("epoch_name", a_epoch_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("delete_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createActivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("activate_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeactivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("deactivate_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createFinishEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_FINISH_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("finish_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createTickEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TICK_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("tick_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_EPOCH_REQUEST, "Login", "Password");
    message_builder.addRequest("get_epoch_request");
    message_builder.addParam("world_name", a_world_name);

    return message_builder.extract();
}

Message::Handle MessageFactory::createTransportHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name_source,
    std::string const a_settlement_name_destination,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REQUEST, "Login", "Password");
    message_builder.addRequest("transport_human_request");
    message_builder.addParam("settlement_name_source", a_settlement_name_source);
    message_builder.addParam("settlement_name_destination", a_settlement_name_destination);
    message_builder.addParam("humankey", a_human_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createTransportResourceRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name_source,
    std::string const a_settlement_name_destination,
    std::string const a_resource_key,
    std::string const a_volume
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REQUEST, "Login", "Password");
    message_builder.addRequest("transport_resource_request");
    message_builder.addParam("settlement_name_source", a_settlement_name_source);
    message_builder.addParam("settlement_name_destination", a_settlement_name_destination);
    message_builder.addParam("resourcekey", a_resource_key);
    message_builder.addParam("volume", a_volume);

    return message_builder.extract();
}

Message::Handle MessageFactory::createEchoReply(
    std::string const a_code
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ECHO_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addSpecificReply("echo_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createErrorReply(
    std::string const a_code
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ERROR_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addSpecificReply("error_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateLandReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_LAND_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("create_land_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteLandReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_LAND_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("delete_land_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LAND_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_land_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LAND_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_land_reply");
    message_builder.addObject("land", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandsReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;
    Message::Objects objects;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LANDS_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_lands_reply");
    message_builder.addObjects("lands", "land", objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetLandsReply(
    std::string      const   a_code,
    std::string      const   a_message,
    Message::Objects const & a_objects
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_LANDS_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_lands_reply");
    message_builder.addObjects("lands", "land", a_objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateSettlementReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_SETTLEMENT_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("create_settlement_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteSettlementReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_SETTLEMENT_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("delete_settlement_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetSettlementReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_SETTLEMENT_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_settlement_reply");
    message_builder.addObject("settlement", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetSettlementsReply(
    std::string      const   a_code,
    std::string      const   a_message,
    Message::Objects const & a_objects
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_SETTLEMENTS_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_settlements_reply");
    message_builder.addObjects("settlements", "settlement", a_objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createBuildBuildingReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_BUILD_BUILDING_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("build_building_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createDestroyBuildingReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DESTROY_BUILDING_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("destroy_building_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetBuildingReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_BUILDING_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_building_reply");
    message_builder.addObject("building", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetBuildingsReply(
    std::string      const   a_code,
    std::string      const   a_message,
    Message::Objects const & a_objects
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_BUILDINGS_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_buildings_reply");
    message_builder.addObjects("buildings", "building", a_objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createDismissHumanReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DISMISS_HUMAN_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("dismiss_human_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createEngageHumanReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ENGAGE_HUMAN_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("engage_human_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetHumanReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_HUMAN_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_human_reply");
    message_builder.addObject("human", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetHumansReply(
    std::string      const   a_code,
    std::string      const   a_message,
    Message::Objects const & a_objects
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_HUMANS_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_humans_reply");
    message_builder.addObjects("humans", "human", a_objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetResourceReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_RESOURCE_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_resource_reply");
    message_builder.addObject("resource", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetResourcesReply(
    std::string      const   a_code,
    std::string      const   a_message,
    Message::Objects const & a_objects
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_RESOURCES_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_resources_reply");
    message_builder.addObjects("resources", "resource", a_objects);

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateUserReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_USER_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("create_user_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateWorldReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_WORLD_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("create_world_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createCreateEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_CREATE_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("create_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeleteEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DELETE_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("delete_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createActivateEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_ACTIVATE_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("activate_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createDeactivateEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_DEACTIVATE_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("deactivate_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createFinishEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_FINISH_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("finish_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createTickEpochReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TICK_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("tick_epoch_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createGetEpochReply(
    std::string     const   a_code,
    std::string     const   a_message,
    Message::Object const & a_object
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_GET_EPOCH_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("get_epoch_reply");
    message_builder.addObject("epoch", a_object);

    return message_builder.extract();
}

Message::Handle MessageFactory::createTransportHumanReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TRANSPORT_HUMAN_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("transport_human_reply");

    return message_builder.extract();
}

Message::Handle MessageFactory::createTransportResourceReply(
    std::string const a_code,
    std::string const a_message
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(TUSLanguage::ID_COMMAND_TRANSPORT_RESOURCE_REPLY);
    message_builder.addReply();
    message_builder.addCode(a_code);
    message_builder.addMessage(a_message);
    message_builder.addSpecificReply("transport_resource_reply");

    return message_builder.extract();
}

} // namespace TUSProtocol
