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

#ifndef TUSLANGUAGE_REQUESTBUILDER_HPP
#define TUSLANGUAGE_REQUESTBUILDER_HPP

// TODO: Keep the standardized include format.
#include "ICommand.hpp"
#include <boost/noncopyable.hpp>

namespace TUSLanguage
{

// TODO: Refactor me!

class RequestBuilder
    : boost::noncopyable
{
public:
    /**
     * @brief Builds EchoRequest.
     *
     * @return EchoRequest.
     */
    ICommand::SingleHandle buildEchoRequest() const;

    /**
     * @brief Builds ErrorRequest.
     *
     * @return ErrorRequest.
     */
    ICommand::SingleHandle buildErrorRequest() const;

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
    ICommand::SingleHandle buildCreateLandRequest(
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
    ICommand::SingleHandle buildDeleteLandRequest(
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
    ICommand::SingleHandle buildGetLandRequest(
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
    ICommand::SingleHandle buildGetLandsRequest(
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
    ICommand::SingleHandle buildCreateSettlementRequest(
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
    ICommand::SingleHandle buildDeleteSettlementRequest(
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
    ICommand::SingleHandle buildGetSettlementRequest(
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
    ICommand::SingleHandle buildGetSettlementsRequest(
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
    ICommand::SingleHandle buildBuildBuildingRequest(
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
    ICommand::SingleHandle buildDestroyBuildingRequest(
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
    ICommand::SingleHandle buildGetBuildingRequest(
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
    ICommand::SingleHandle buildGetBuildingsRequest(
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
    ICommand::SingleHandle buildDismissHumanRequest(
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
    ICommand::SingleHandle buildEngageHumanRequest(
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
    ICommand::SingleHandle buildGetHumanRequest(
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
    ICommand::SingleHandle buildGetHumansRequest(
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
    ICommand::SingleHandle buildGetResourceRequest(
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
    ICommand::SingleHandle buildGetResourcesRequest(
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
    ICommand::SingleHandle buildCreateUserRequest(
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
    ICommand::SingleHandle buildCreateWorldRequest(
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
    ICommand::SingleHandle buildCreateEpochRequest(
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
    ICommand::SingleHandle buildDeleteEpochRequest(
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
    ICommand::SingleHandle buildActivateEpochRequest(
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
    ICommand::SingleHandle buildDeactivateEpochRequest(
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
    ICommand::SingleHandle buildFinishEpochRequest(
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
    ICommand::SingleHandle buildTickEpochRequest(
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
    ICommand::SingleHandle buildGetEpochRequest(
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
    ICommand::SingleHandle buildTransportHumanRequest(
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
    ICommand::SingleHandle buildTransportResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_resource_key,
        std::string const a_volume
    ) const;
};

} // namespace TUSLanguage

#endif // TUSLANGUAGE_REQUESTBUILDER_HPP
