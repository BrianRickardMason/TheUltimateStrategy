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
     * @brief Builds EchoRequest.
     *
     * @return EchoRequest.
     */
    Message::SingleHandle createEchoRequest() const;

    /**
     * @brief Builds ErrorRequest.
     *
     * @return ErrorRequest.
     */
    Message::SingleHandle createErrorRequest() const;

    /**
     * @brief Builds CreateLandRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     * @param a_land_name  The name of the land.
     *
     * @return CreateLandRequest
     */
    Message::SingleHandle createCreateLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds DeleteLandRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return DeleteLandRequest
     */
    Message::SingleHandle createDeleteLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds GetLandRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return GetLandRequest
     */
    Message::SingleHandle createGetLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds GetLandsRequest.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     *
     * @return GetLandsRequest
     */
    Message::SingleHandle createGetLandsRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    /**
     * @brief Builds CreateSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_land_name       The name of the land.
     * @param a_settlement_name The name of the settlement.
     *
     * @return CreateSettlementRequest
     */
    Message::SingleHandle createCreateSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Builds DeleteSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_settlement_name The name of the settlement.
     *
     * @return DeleteSettlementRequest
     */
    Message::SingleHandle createDeleteSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Builds GetSettlementRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_settlement_name The name of the settlement.
     *
     * @return GetSettlementRequest
     */
    Message::SingleHandle createGetSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Builds GetSettlementsRequest.
     *
     * @param a_login     The login of the user.
     * @param a_password  The password of the user.
     * @param a_land_name The name of the land.
     *
     * @return GetSettlementsRequest
     */
    Message::SingleHandle createGetSettlementsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds BuildBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return BuildBuildingRequest
     */
    Message::SingleHandle createBuildBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds DestroyBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return DestroyBuildingRequest
     */
    Message::SingleHandle createDestroyBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds GetBuildingRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_building_key    The key of the building.
     *
     * @return GetBuildingRequest
     */
    Message::SingleHandle createGetBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key
    ) const;

    /**
     * @brief Builds GetBuildingsRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetBuildingsRequest
     */
    Message::SingleHandle createGetBuildingsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Builds DismissHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return DismissHumanRequest
     */
    Message::SingleHandle createDismissHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds EngageHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return EngageHumanRequest
     */
    Message::SingleHandle createEngageHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds GetHumanRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_human_key       The key of the human.
     *
     * @return GetHumanRequest
     */
    Message::SingleHandle createGetHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key
    ) const;

    /**
     * @brief Builds GetHumansRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetHumansRequest
     */
    Message::SingleHandle createGetHumansRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Builds GetResourceRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     * @param a_resource_key    The key of the resource.
     *
     * @return GetResourceRequest
     */
    Message::SingleHandle createGetResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_resource_key
    ) const;

    /**
     * @brief Builds GetResourcesRequest.
     *
     * @param a_login           The login of the user.
     * @param a_password        The password of the user.
     * @param a_id_holder_class The identifier of the class of the holder.
     * @param a_holder_name     The name of the holder.
     *
     * @return GetResourcesRequest
     */
    Message::SingleHandle createGetResourcesRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    /**
     * @brief Builds CreateUserRequest.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     *
     * @return CreateUserRequest
     */
    Message::SingleHandle createCreateUserRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    /**
     * @brief Builds CreateWorldRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return CreateWorldRequest
     */
    Message::SingleHandle createCreateWorldRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds CreateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     * @param a_epoch_name The name of the epoch.
     *
     * @return CreateEpochRequest
     */
    Message::SingleHandle createCreateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_epoch_name
    ) const;

    /**
     * @brief Builds DeleteEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return DeleteEpochRequest
     */
    Message::SingleHandle createDeleteEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds ActivateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return ActivateEpochRequest
     */
    Message::SingleHandle createActivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds DeactivateEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return DeactivateEpochRequest
     */
    Message::SingleHandle createDeactivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds FinishEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return FinishEpochRequest
     */
    Message::SingleHandle createFinishEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds TickEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return TickEpochRequest
     */
    Message::SingleHandle createTickEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds GetEpochRequest.
     *
     * @param a_login      The login of the user.
     * @param a_password   The password of the user.
     * @param a_world_name The name of the world.
     *
     * @return GetEpochRequest
     */
    Message::SingleHandle createGetEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    /**
     * @brief Builds TransportHumanRequest.
     *
     * @param a_login                       The login of the user.
     * @param a_password                    The password of the user.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_human_key                   The key of the human.
     * @param a_volume                      The volume of the human.
     *
     * @return TransportHumanRequest
     */
    Message::SingleHandle createTransportHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds TransportResourceRequest.
     *
     * @param a_login                       The login of the user.
     * @param a_password                    The password of the user.
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_resource_key                The key of the resource.
     * @param a_volume                      The volume of the resource.
     *
     * @return TransportResourceRequest
     */
    Message::SingleHandle createTransportResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_resource_key,
        std::string const a_volume
    ) const;
};

} // namespace TUSProtocol

#endif // TUSPROTOCOL_MESSAGEFACTORY_HPP
