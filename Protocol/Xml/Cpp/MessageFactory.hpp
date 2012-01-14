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

#ifndef TUSPROTOCOL_MESSAGEFACTORY_HPP
#define TUSPROTOCOL_MESSAGEFACTORY_HPP

#include <Protocol/Xml/Cpp/Message.hpp>
#include <boost/noncopyable.hpp>

namespace TUSProtocol
{

class MessageFactory
    : boost::noncopyable
{
public:
    /**
     * @brief Creates EchoRequest.
     *
     * @return EchoRequest.
     */
    Message::Handle createEchoRequest() const;

    /**
     * @brief Creates ErrorRequest.
     *
     * @return ErrorRequest.
     */
    Message::Handle createErrorRequest() const;

    /**
     * @brief Creates CreateLandRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     * @param a_land_name  The name of the land.
     *
     * @return CreateLandRequest.
     */
    Message::Handle createCreateLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_land_name
    ) const;

    /**
     * @brief Creates DeleteLandRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return DeleteLandRequest.
     */
    Message::Handle createDeleteLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Creates GetLandRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return GetLandRequest.
     */
    Message::Handle createGetLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Creates GetLandsRequest.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     *
     * @return GetLandsRequest.
     */
    Message::Handle createGetLandsRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    /**
     * @brief Creates CreateSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_land_name       The name of the land.
     * @param a_settlement_name The name of the settlement.
     *
     * @return CreateSettlementRequest.
     */
    Message::Handle createCreateSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Creates DeleteSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_settlement_name The name of the settlement.
     *
     * @return DeleteSettlementRequest.
     */
    Message::Handle createDeleteSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Creates GetSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_settlement_name The name of the settlement.
     *
     * @return GetSettlementRequest.
     */
    Message::Handle createGetSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Creates GetSettlementsRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return GetSettlementsRequest.
     */
    Message::Handle createGetSettlementsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Creates BuildBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return BuildBuildingRequest.
     */
    Message::Handle createBuildBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates DestroyBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return DestroyBuildingRequest.
     */
    Message::Handle createDestroyBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates GetBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     *
     * @return GetBuildingRequest.
     */
    Message::Handle createGetBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key
    ) const;

    /**
     * @brief Creates GetBuildingsRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetBuildingsRequest.
     */
    Message::Handle createGetBuildingsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Creates DismissHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return DismissHumanRequest.
     */
    Message::Handle createDismissHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates EngageHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return EngageHumanRequest.
     */
    Message::Handle createEngageHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates GetHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     *
     * @return GetHumanRequest.
     */
    Message::Handle createGetHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key
    ) const;

    /**
     * @brief Creates GetHumansRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetHumansRequest.
     */
    Message::Handle createGetHumansRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Creates GetResourceRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_resource_key    The key of the resource.
     *
     * @return GetResourceRequest.
     */
    Message::Handle createGetResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_resource_key
    ) const;

    /**
     * @brief Creates GetResourcesRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetResourcesRequest.
     */
    Message::Handle createGetResourcesRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Creates CreateUserRequest.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     *
     * @return CreateUserRequest.
     */
    Message::Handle createCreateUserRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    /**
     * @brief Creates CreateWorldRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return CreateWorldRequest.
     */
    Message::Handle createCreateWorldRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates CreateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     * @param a_epoch_name The name of the epoch.
     *
     * @return CreateEpochRequest.
     */
    Message::Handle createCreateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_epoch_name
    ) const;

    /**
     * @brief Creates DeleteEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return DeleteEpochRequest.
     */
    Message::Handle createDeleteEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates ActivateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return ActivateEpochRequest.
     */
    Message::Handle createActivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates DeactivateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return DeactivateEpochRequest.
     */
    Message::Handle createDeactivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates FinishEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return FinishEpochRequest.
     */
    Message::Handle createFinishEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates TickEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return TickEpochRequest.
     */
    Message::Handle createTickEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates GetEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return GetEpochRequest.
     */
    Message::Handle createGetEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Creates TransportHumanRequest.
     *
     * @param a_login                       The login of the user.
     * @param a_password                    The password of the user.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_human_key                   The key of the human.
     * @param a_volume                      The volume of the human.
     *
     * @return TransportHumanRequest.
     */
    Message::Handle createTransportHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates TransportResourceRequest.
     *
     * @param a_login                       The login of the user.
     * @param a_password                    The password of the user.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_resource_key                The key of the resource.
     * @param a_volume                      The volume of the resource.
     *
     * @return TransportResourceRequest.
     */
    Message::Handle createTransportResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_resource_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Creates EchoReply.
     *
     * @param a_code The exit code.
     *
     * @return EchoReply.
     */
    Message::Handle createEchoReply(
        std::string const a_code
    ) const;

    /**
     * @brief Creates ErrorReply.
     *
     * @param a_code The exit code.
     *
     * @return ErrorReply.
     */
    Message::Handle createErrorReply(
        std::string const a_code
    ) const;

    /**
     * @brief Creates CreateLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateLandReply.
     */
    Message::Handle createCreateLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates DeleteLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteLandReply.
     */
    Message::Handle createDeleteLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return GetLandReply.
     */
    Message::Handle createGetLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetLandReply.
     */
    Message::Handle createGetLandReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates GetLandsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return GetLandsReply.
     */
    Message::Handle createGetLandsReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetLandsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetLandsReply.
     */
    Message::Handle createGetLandsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    /**
     * @brief Creates CreateSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateSettlementReply.
     */
    Message::Handle createCreateSettlementReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates DeleteSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteSettlementReply.
     */
    Message::Handle createDeleteSettlementReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetSettlementReply.
     */
    Message::Handle createGetSettlementReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates GetSettlementsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetSettlementsReply.
     */
    Message::Handle createGetSettlementsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    /**
     * @brief Creates BuildBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return BuildBuildingReply.
     */
    Message::Handle createBuildBuildingReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates DestroyBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DestroyBuildingReply.
     */
    Message::Handle createDestroyBuildingReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetBuildingReply.
     */
    Message::Handle createGetBuildingReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates GetBuildingsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetBuildingsReply.
     */
    Message::Handle createGetBuildingsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    /**
     * @brief Creates DismissHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DismissHumanReply.
     */
    Message::Handle createDismissHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates EngageHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return EngageHumanReply.
     */
    Message::Handle createEngageHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetHumanReply.
     */
    Message::Handle createGetHumanReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates GetHumansReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetHumansReply.
     */
    Message::Handle createGetHumansReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    /**
     * @brief Creates GetResourceReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetResourceReply.
     */
    Message::Handle createGetResourceReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates GetResourcesReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetResourcesReply.
     */
    Message::Handle createGetResourcesReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    /**
     * @brief Creates CreateUserReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateUserReply.
     */
    Message::Handle createCreateUserReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates CreateWorldReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateWorldReply.
     */
    Message::Handle createCreateWorldReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates CreateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateEpochReply.
     */
    Message::Handle createCreateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates DeleteEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteEpochReply.
     */
    Message::Handle createDeleteEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates ActivateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return ActivateEpochReply.
     */
    Message::Handle createActivateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates DectivateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DectivateEpochReply.
     */
    Message::Handle createDeactivateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates FinishEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return FinishEpochReply.
     */
    Message::Handle createFinishEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates TickEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TickEpochReply.
     */
    Message::Handle createTickEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates GetEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetEpochReply.
     */
    Message::Handle createGetEpochReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    /**
     * @brief Creates TransportHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TransportHumanReply.
     */
    Message::Handle createTransportHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    /**
     * @brief Creates TransportResourceReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TransportResourceReply.
     */
    Message::Handle createTransportResourceReply(
        std::string const a_code,
        std::string const a_message
    ) const;
};

} // namespace TUSProtocol

#endif // TUSPROTOCOL_MESSAGEFACTORY_HPP
