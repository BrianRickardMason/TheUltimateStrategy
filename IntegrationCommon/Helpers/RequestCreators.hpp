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

#ifndef REQUESTCREATORS_HPP
#define REQUESTCREATORS_HPP

#include "../../Network/XmlRPCCommon/Request/Request.hpp"
#include <string>

/**
 * @brief Creates a request "echo".
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestEcho();

/**
 * @brief Creates a request "create user".
 *
 * @param a_login    The login of a user.
 * @param a_password The password of a user.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestCreateUser(
    std::string const & a_login,
    std::string const & a_password
);

/**
 * @brief Creates a request "create world".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_name     The name of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestCreateWorld(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    std::string  const & a_name
);

/**
 * @brief Creates a request "create epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestCreateEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "delete epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDeleteEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "get epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "activate epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestActivateEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "deactivate epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDeactivateEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "finish epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestFinishEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "tick epoch".
 *
 * @param a_id_user  The identifier of the user.
 * @param a_password The password of the user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestTickEpoch(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "create land".
 *
 * @param a_id_user  An identifier of the user.
 * @param a_password The password of a user.
 * @param a_id_world An identifier of the world.
 * @param a_id_epoch The identifier of the epoch.
 * @param a_name     A name of the land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestCreateLand(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world,
    unsigned int const   a_id_epoch,
    std::string  const & a_name
);

/**
 * @brief Creates a request "delete land".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_land  The identifier of a land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDeleteLand(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_land
);

/**
 * @brief Creates a request "get land by id land".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_land  The identifier of a land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetLandByIDLand(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_land
);

/**
 * @brief Creates a request "get land by name".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_name     The name of a land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetLandByName(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    std::string  const & a_name
);

/**
 * @brief Creates a request "get lands by id world".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_world The identifier of the world.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetLandsByIDWorld(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_world
);

/**
 * @brief Creates a request "create settlement".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_land  The identifier of a land.
 * @param a_name     The name of the settlement.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestCreateSettlement(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_land,
    std::string  const & a_name
);

/**
 * @brief Deletes a request "delete settlement".
 *
 * @param a_id_user       The identifier of a user.
 * @param a_password      The password of a user.
 * @param a_id_settlement The identifier of a settlement.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDeleteSettlement(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_settlement
);

/**
 * @brief Creates a request "get settlement by id land and name".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_land  The identifier of a land.
 * @param a_name     The name of a settlement.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetSettlementByIDLandAndName(
    unsigned int const a_id_user,
    std::string  const & a_password,
    unsigned int const a_id_land,
    std::string  const & a_name
);

/**
 * @brief Creates a request "get settlement by id settlement".
 *
 * @param a_id_user       The identifier of a user.
 * @param a_password      The password of a user.
 * @param a_id_settlement The identifier of a settlement.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetSettlementByIDSettlement(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_settlement
);

/**
 * @brief Creates a request "get settlements".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of a user.
 * @param a_id_land  The identifier of a land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetSettlements(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_land
);

/**
 * @brief Creates a request "build building".
 *
 * @param a_id_user           The identifier of a user.
 * @param a_password          The password of the user.
 * @param a_id_holder_class   The identifier of the class of a holder.
 * @param a_id_holder         The identifier of a holder.
 * @param a_id_building_class The identifier of the class of a building.
 * @param a_id_building       The identifier of a building.
 * @param a_volume            The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestBuildBuilding(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_building_class,
    unsigned int const   a_id_building,
    unsigned int const   a_volume
);

/**
 * @brief Creates a request "destroy building".
 *
 * @param a_id_user           The identifier of a user.
 * @param a_password          The password of the user.
 * @param a_id_holder_class   The identifier of the class of a holder.
 * @param a_id_holder         The identifier of a holder.
 * @param a_id_building_class The identifier of the class of a building.
 * @param a_id_building       The identifier of a building.
 * @param a_volume            The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDestroyBuilding(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_building_class,
    unsigned int const   a_id_building,
    unsigned int const   a_volume
);

/**
 * @brief Creates a request "get building".
 *
 * @param a_id_user           The identifier of a user.
 * @param a_password          The password of the user.
 * @param a_id_holder_class   The identifier of the class of a holder.
 * @param a_id_holder         The identifier of a holder.
 * @param a_id_building_class The identifier of the class of a building.
 * @param a_id_building       The identifier of a building.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetBuilding(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_building_class,
    unsigned int const   a_id_building
);

/**
 * @brief Creates a request "get buildings".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetBuildings(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder
);

/**
 * @brief Creates a request "engage human".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 * @param a_id_human_class  The identifier of the class of a human.
 * @param a_id_human        The identifier of a human.
 * @param a_volume          The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestEngageHuman(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_human_class,
    unsigned int const   a_id_human,
    unsigned int const   a_volume
);

/**
 * @brief Creates a request "dismiss human".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 * @param a_id_human_class  The identifier of the class of a human.
 * @param a_id_human        The identifier of a human.
 * @param a_experience      The experience of a human.
 * @param a_volume          The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestDismissHuman(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_human_class,
    unsigned int const   a_id_human,
    unsigned int const   a_experience,
    unsigned int const   a_volume
);

/**
 * @brief Creates a request "get human".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 * @param a_id_human_class  The identifier of the class of a human.
 * @param a_id_human        The identifier of a human.
 * @param a_experience      The experience of a human.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetHuman(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_human_class,
    unsigned int const   a_id_human,
    unsigned int const   a_experience
);

/**
 * @brief Creates a request "get humans".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetHumans(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder
);

/**
 * @brief Creates a request "get resource".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 * @parma a_id_resource     The identifier of a resource.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetResource(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder,
    unsigned int const   a_id_resource
);

/**
 * @brief Creates a request "get resources".
 *
 * @param a_id_user         The identifier of a user.
 * @param a_password        The password of the user.
 * @param a_id_holder_class The identifier of the class of a holder.
 * @param a_id_holder       The identifier of a holder.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestGetResources(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_holder_class,
    unsigned int const   a_id_holder
);

/**
 * @brief Creates a request "turn".
 *
 * @param a_id_user  The identifier of a user.
 * @param a_password The password of the user.
 * @param a_id_land  The identifier of a land.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestTurn(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_land
);

/**
 * @brief Creates a request "transport human".
 *
 * @param a_id_user                   The identifier of the user.
 * @param a_password                  The password of the user.
 * @param a_id_settlement_source      The identifier of the source settlement.
 * @param a_id_settlement_destination The identifier of the destination settlement.
 * @param a_id_human_class            The identifier of the class of the human.
 * @param a_id_human                  The identifier of the human.
 * @param a_experience                The experience of the human.
 * @param a_volume                    The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestTransportHuman(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_settlement_source,
    unsigned int const   a_id_settlement_destination,
    unsigned int const   a_id_human_class,
    unsigned int const   a_id_human,
    unsigned int const   a_experience,
    unsigned int const   a_volume
);

/**
 * @brief Creates a request "transport resource".
 *
 * @param a_id_user                   The identifier of the user.
 * @param a_password                  The password of the user.
 * @param a_id_settlement_source      The identifier of the source settlement.
 * @param a_id_settlement_destination The identifier of the destination settlement.
 * @param a_id_resource               The identifier of the resource.
 * @param a_volume                    The volume.
 *
 * @return The created request.
 */
Network::XmlRPCCommon::Request::RequestShrPtr createRequestTransportResource(
    unsigned int const   a_id_user,
    std::string  const & a_password,
    unsigned int const   a_id_settlement_source,
    unsigned int const   a_id_settlement_destination,
    unsigned int const   a_id_resource,
    unsigned int const   a_volume
);

#endif // REQUESTCREATORS_HPP
