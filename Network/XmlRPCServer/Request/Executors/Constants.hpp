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

#ifndef NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_CONSTANTS_HPP
#define NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_CONSTANTS_HPP

#include <string>

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

/**
 * @brief The contents of the messages.
 */
std::string const METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE = "Even more unexpected error: unknown exit code.";

std::string const BUILD_BUILDING_BUILDING_HAS_BEEN_BUILT           = "Building has been built.";
std::string const BUILD_BUILDING_NOT_ENOUGH_RESOURCES              = "Not enough resources.";
std::string const BUILD_BUILDING_RESOURCES_MISSING_IN_THE_MEANTIME = "Resources missing in the meantime.";
std::string const BUILD_BUILDING_TRYING_TO_BUILD_ZERO_BUILDINGS    = "Trying to build zero buildings.";
std::string const BUILD_BUILDING_UNEXPECTED_ERROR                  = "Unexpected error.";

std::string const DESTROY_BUILDING_BUILDINGS_MISSING_IN_THE_MEANTIME = "Buildings missing in the meantime.";
std::string const DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED       = "Building has been destroyed.";
std::string const DESTROY_BUILDING_NOT_ENOUGH_BUILDINGS              = "Not enough buildings.";
std::string const DESTROY_BUILDING_NOT_ENOUGH_RESOURCES              = "Not enough resources.";
std::string const DESTROY_BUILDING_RESOURCES_MISSING_IN_THE_MEANTIME = "Resources missing in the meantime.";
std::string const DESTROY_BUILDING_THERE_ARE_NO_BUILDINGS            = "There are no buildings.";
std::string const DESTROY_BUILDING_TRYING_TO_DESTROY_ZERO_BUILDINGS  = "Trying to destroy zero buildings.";
std::string const DESTROY_BUILDING_UNEXPECTED_ERROR                  = "Unexpected error.";

std::string const GET_BUILDING_BUILDING_HAS_BEEN_GOT = "Building has been got.";
std::string const GET_BUILDING_UNEXPECTED_ERROR      = "Unexpected error.";

std::string const GET_BUILDINGS_BUILDINGS_HAVE_BEEN_GOT = "Buildings have been got.";
std::string const GET_BUILDINGS_UNEXPECTED_ERROR        = "Buildings have not been got.";

std::string const TRANSPORT_HUMAN_DESTINATION_SETTLEMENT_DOES_NOT_EXIST  = "Destination settlement does not exist.";
std::string const TRANSPORT_HUMAN_HUMAN_HAS_BEEN_TRANSPORTED             = "Human has been transported.";
std::string const TRANSPORT_HUMAN_NOT_ENOUGH_HUMANS                      = "Not enough humans.";
std::string const TRANSPORT_HUMAN_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND = "Settlements are not from the same land.";
std::string const TRANSPORT_HUMAN_SOURCE_SETTLEMENT_DOES_NOT_EXIST       = "Source settlement does not exist.";
std::string const TRANSPORT_HUMAN_TRYING_TO_TRANSPORT_ZERO_HUMANS        = "Trying to transport zero humans.";
std::string const TRANSPORT_HUMAN_UNEXPECTED_ERROR                       = "Unexpected error.";

std::string const TRANSPORT_RESOURCE_DESTINATION_SETTLEMENT_DOES_NOT_EXIST  = "Destination settlement does not exist.";
std::string const TRANSPORT_RESOURCE_NOT_ENOUGH_RESOURCES                   = "Not enough resources.";
std::string const TRANSPORT_RESOURCE_RESOURCE_HAS_BEEN_TRANSPORTED          = "Resource has been transported.";
std::string const TRANSPORT_RESOURCE_SETTLEMENTS_ARE_NOT_FROM_THE_SAME_LAND = "Settlements are not from the same land.";
std::string const TRANSPORT_RESOURCE_SOURCE_SETTLEMENT_DOES_NOT_EXIST       = "Source settlement does not exist.";
std::string const TRANSPORT_RESOURCE_TRYING_TO_TRANSPORT_ZERO_RESOURCES     = "Trying to transport zero resources.";
std::string const TRANSPORT_RESOURCE_UNEXPECTED_ERROR                       = "Unexpected erro.r";

std::string const ACTIVATE_EPOCH_EPOCH_DOES_NOT_EXIST         = "Epoch does not exist.";
std::string const ACTIVATE_EPOCH_EPOCH_HAS_BEEN_ACTIVATED     = "Epoch has been activated.";
std::string const ACTIVATE_EPOCH_EPOCH_HAS_BEEN_FINISHED      = "Epoch has been finished.";
std::string const ACTIVATE_EPOCH_EPOCH_HAS_NOT_BEEN_ACTIVATED = "Epoch has not been activated.";
std::string const ACTIVATE_EPOCH_EPOCH_IS_ACTIVE              = "Epoch is active.";
std::string const ACTIVATE_EPOCH_UNEXPECTED_ERROR             = "Unexpected error.";
std::string const ACTIVATE_EPOCH_WORLD_DOES_NOT_EXIST         = "World does not exist.";

std::string const CREATE_EPOCH_EPOCH_HAS_BEEN_CREATED     = "Epoch has been created.";
std::string const CREATE_EPOCH_EPOCH_HAS_NOT_BEEN_CREATED = "Epoch has not been created.";
std::string const CREATE_EPOCH_UNEXPECTED_ERROR           = "Unexpected error.";
std::string const CREATE_EPOCH_WORLD_DOES_NOT_EXIST       = "World does not exist.";

std::string const DEACTIVATE_EPOCH_EPOCH_DOES_NOT_EXIST           = "Epoch does not exist.";
std::string const DEACTIVATE_EPOCH_EPOCH_HAS_BEEN_DEACTIVATED     = "Epoch has been deactivated.";
std::string const DEACTIVATE_EPOCH_EPOCH_HAS_BEEN_FINISHED        = "Epoch has been finished.";
std::string const DEACTIVATE_EPOCH_EPOCH_HAS_NOT_BEEN_DEACTIVATED = "Epoch has not been deactivated.";
std::string const DEACTIVATE_EPOCH_EPOCH_IS_NOT_ACTIVE            = "Epoch is not active.";
std::string const DEACTIVATE_EPOCH_UNEXPECTED_ERROR               = "Unexpected error.";
std::string const DEACTIVATE_EPOCH_WORLD_DOES_NOT_EXIST           = "World does not exist.";

std::string const DELETE_EPOCH_EPOCH_DOES_NOT_EXIST        = "Epoch does not exist.";
std::string const DELETE_EPOCH_EPOCH_HAS_BEEN_DELETED      = "Epoch has been deleted.";
std::string const DELETE_EPOCH_EPOCH_HAS_NOT_BEEN_DELETED  = "Epoch has not been deleted.";
std::string const DELETE_EPOCH_EPOCH_HAS_NOT_BEEN_FINISHED = "Epoch has not been finished.";
std::string const DELETE_EPOCH_UNEXPECTED_ERROR            = "Unexpected error.";
std::string const DELETE_EPOCH_WORLD_DOES_NOT_EXIST        = "World does not exist.";

std::string const FINISH_EPOCH_EPOCH_DOES_NOT_EXIST               = "Epoch does not exist.";
std::string const FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED            = "Epoch has been finished.";
std::string const FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY = "Epoch has been finished previously.";
std::string const FINISH_EPOCH_EPOCH_HAS_NOT_BEEN_FINISHED        = "Epoch has not been finished.";
std::string const FINISH_EPOCH_EPOCH_IS_ACTIVE                    = "Epoch is active.";
std::string const FINISH_EPOCH_UNEXPECTED_ERROR                   = "Unexpected error.";
std::string const FINISH_EPOCH_WORLD_DOES_NOT_EXIST               = "World does not exist.";

std::string const GET_EPOCH_EPOCH_HAS_BEEN_GOT     = "Epoch has been got.";
std::string const GET_EPOCH_EPOCH_HAS_NOT_BEEN_GOT = "Epoch has not been got.";
std::string const GET_EPOCH_UNEXPECTED_ERROR       = "Unexpected error.";
std::string const GET_EPOCH_WORLD_DOES_NOT_EXIST   = "World does not exist.";

std::string const TICK_EPOCH_EPOCH_DOES_NOT_EXIST    = "Epoch does not exist.";
std::string const TICK_EPOCH_EPOCH_HAS_BEEN_FINISHED = "Epoch has been finished.";
std::string const TICK_EPOCH_EPOCH_HAS_BEEN_TACK     = "Epoch has been tack.";
std::string const TICK_EPOCH_EPOCH_HAS_NOT_BEEN_TACK = "Epoch has not been tack.";
std::string const TICK_EPOCH_EPOCH_IS_ACTIVE         = "Epoch is active.";
std::string const TICK_EPOCH_UNEXPECTED_ERROR        = "Unexpected error.";
std::string const TICK_EPOCH_WORLD_DOES_NOT_EXIST    = "World does not exist.";

std::string const GET_HUMAN_HUMAN_HAS_BEEN_GOT = "Human has been got.";
std::string const GET_HUMAN_UNEXPECTED_ERROR   = "Unexpected error.";

std::string const GET_HUMANS_HUMANS_HAVE_BEEN_GOT = "Humans have been got.";
std::string const GET_HUMANS_UNEXPECTED_ERROR     = "Humans have not been got.";

std::string const CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_BELONGS_TO_THE_USER = "Another land of the given name belongs to the user.";
std::string const CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS_IN_THE_WORLD = "Another land of the given name exists in the world.";
std::string const CREATE_LAND_EPOCH_DOES_NOT_EXIST                               = "Epoch does not exist.";
std::string const CREATE_LAND_LAND_HAS_BEEN_CREATED                              = "Land has been created.";
std::string const CREATE_LAND_LAND_HAS_NOT_BEEN_CREATED                          = "Land has not been created.";
std::string const CREATE_LAND_UNEXPECTED_ERROR                                   = "Unexpected error.";
std::string const CREATE_LAND_WORLD_DOES_NOT_EXIST                               = "World does not exist.";

std::string const DELETE_LAND_LAND_DOES_NOT_EXIST       = "Land does not exist.";
std::string const DELETE_LAND_LAND_HAS_BEEN_DELETED     = "Land has been deleted.";
std::string const DELETE_LAND_LAND_HAS_NOT_BEEN_DELETED = "Land has not been deleted.";
std::string const DELETE_LAND_UNEXPECTED_ERROR          = "Unexpected error.";

std::string const GET_LAND_BY_IDLAND_LAND_HAS_BEEN_GOT     = "Land has been got.";
std::string const GET_LAND_BY_IDLAND_LAND_HAS_NOT_BEEN_GOT = "Land has not been got.";
std::string const GET_LAND_BY_IDLAND_UNEXPECTED_ERROR      = "Unexpected error.";

std::string const GET_LAND_BY_LOGIN_AND_NAME_LAND_HAS_BEEN_GOT     = "Land has been got.";
std::string const GET_LAND_BY_LOGIN_AND_NAME_LAND_HAS_NOT_BEEN_GOT = "Land has not been got.";
std::string const GET_LAND_BY_LOGIN_AND_NAME_UNEXPECTED_ERROR      = "Unexpected error.";

std::string const GET_LANDS_BY_LOGIN_AND_WORLDNAME_LANDS_HAVE_BEEN_GOT     = "Lands have been got.";
std::string const GET_LANDS_BY_LOGIN_AND_WORLDNAME_LANDS_HAVE_NOT_BEEN_GOT = "Lands have not been got.";
std::string const GET_LANDS_BY_LOGIN_AND_WORLDNAME_UNEXPECTED_ERROR        = "Unexpected error.";
std::string const GET_LANDS_BY_LOGIN_AND_WORLDNAME_WORLD_DOES_NOT_EXIST    = "World does not exist.";

std::string const GET_RESOURCE_RESOURCE_HAS_BEEN_GOT = "Resource has been got.";
std::string const GET_RESOURCE_UNEXPECTED_ERROR      = "Unexpected error.";

std::string const GET_RESOURCES_RESOURCES_HAVE_BEEN_GOT = "Resources have been got.";
std::string const GET_RESOURCES_UNEXPECTED_ERROR        = "Unexpected error.";

std::string const CREATE_SETTLEMENT_LAND_DOES_NOT_EXIST             = "Land does not exist.";
std::string const CREATE_SETTLEMENT_SETTLEMENT_DOES_EXIST           = "Settlement does exist.";
std::string const CREATE_SETTLEMENT_SETTLEMENT_HAS_BEEN_CREATED     = "Settlement has been created.";
std::string const CREATE_SETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_CREATED = "Settlement has not been created.";
std::string const CREATE_SETTLEMENT_UNEXPECTED_ERROR                = "Unexpected error.";

std::string const DELETE_SETTLEMENT_SETTLEMENT_DOES_NOT_EXIST       = "Settlement does not exist.";
std::string const DELETE_SETTLEMENT_SETTLEMENT_HAS_BEEN_DELETED     = "Settlement has been deleted.";
std::string const DELETE_SETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_DELETED = "Settlement has not been deleted.";
std::string const DELETE_SETTLEMENT_UNEXPECTED_ERROR                = "Unexpected error.";

std::string const GET_SETTLEMENT_BY_IDLAND_AND_NAME_LAND_DOES_NOT_EXIST         = "Land does not exist.";
std::string const GET_SETTLEMENT_BY_IDLAND_AND_NAME_SETTLEMENT_HAS_BEEN_GOT     = "Settlement has been got.";
std::string const GET_SETTLEMENT_BY_IDLAND_AND_NAME_SETTLEMENT_HAS_NOT_BEEN_GOT = "Settlement has not been got.";
std::string const GET_SETTLEMENT_BY_IDLAND_AND_NAME_UNEXPECTED_ERROR            = "Unexpected error.";

std::string const GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_BEEN_GOT     = "Settlement has been got.";
std::string const GET_SETTLEMENT_BY_IDSETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_GOT = "Settlement has not been got.";
std::string const GET_SETTLEMENT_BY_IDSETTLEMENT_UNEXPECTED_ERROR            = "Unexpected error.";

std::string const GET_SETTLEMENTS_BY_IDLAND_LAND_DOES_NOT_EXIST           = "Land does not exist.";
std::string const GET_SETTLEMENTS_BY_IDLAND_SETTLEMENTS_HAVE_BEEN_GOT     = "Settlements have been got.";
std::string const GET_SETTLEMENTS_BY_IDLAND_SETTLEMENTS_HAVE_NOT_BEEN_GOT = "Settlements have not been got.";
std::string const GET_SETTLEMENTS_BY_IDLAND_UNEXPECTED_ERROR              = "Unexpected error.";

std::string const TURN_LAND_DOES_NOT_EXIST         = "Land does not exist.";
std::string const TURN_TURN_HAS_BEEN_PERFORMED     = "Turn has been performed.";
std::string const TURN_TURN_HAS_NOT_BEEN_PERFORMED = "Turn has not been performed.";
std::string const TURN_UNEXPECTED_ERROR            = "Unexpected error.";

std::string const CREATE_USER_UNEXPECTED_ERROR          = "Unexpected error.";
std::string const CREATE_USER_USER_DOES_EXIST           = "User does exist.";
std::string const CREATE_USER_USER_HAS_BEEN_CREATED     = "User has been created.";
std::string const CREATE_USER_USER_HAS_NOT_BEEN_CREATED = "User has not been created.";

std::string const CREATE_WORLD_UNEXPECTED_ERROR           = "Unexpected error.";
std::string const CREATE_WORLD_WORLD_DOES_EXIST           = "World does exist.";
std::string const CREATE_WORLD_WORLD_HAS_BEEN_CREATED     = "World has been created.";
std::string const CREATE_WORLD_WORLD_HAS_NOT_BEEN_CREATED = "World has not been created.";

std::string const DISMISS_HUMAN_HUMANS_MISSING_IN_THE_MEANTIME    = "Humans missing in the meantime.";
std::string const DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED          = "Human has been dismissed.";
std::string const DISMISS_HUMAN_HUMAN_IS_NOT_DISMISSABLE          = "Human is not dismissable.";
std::string const DISMISS_HUMAN_NOT_ENOUGH_ENGAGED                = "Not enough engaged.";
std::string const DISMISS_HUMAN_NOT_ENOUGH_RESOURCES              = "Not enough resources.";
std::string const DISMISS_HUMAN_RESOURCES_MISSING_IN_THE_MEANTIME = "Resources missing in the meantime.";
std::string const DISMISS_HUMAN_TRYING_TO_DISMISS_ZERO_HUMANS     = "Trying to dimiss zero humans.";
std::string const DISMISS_HUMAN_UNEXPECTED_ERROR                  = "Unexpected error.";

std::string const ENGAGE_HUMAN_HUMAN_HAS_BEEN_ENGAGED            = "Human has been engaged.";
std::string const ENGAGE_HUMAN_HUMAN_IS_NOT_ENGAGEABLE           = "Human is not engageable.";
std::string const ENGAGE_HUMAN_JOBLESS_MISSING_IN_THE_MEANTIME   = "Jobless missing in the meantime.";
std::string const ENGAGE_HUMAN_NOT_ENOUGH_BUILDINGS              = "Not enough buildings.";
std::string const ENGAGE_HUMAN_NOT_ENOUGH_JOBLESS                = "Not enough jobless.";
std::string const ENGAGE_HUMAN_NOT_ENOUGH_RESOURCES              = "Not enough resources.";
std::string const ENGAGE_HUMAN_RESOURCES_MISSING_IN_THE_MEANTIME = "Resources missing in the meantime";
std::string const ENGAGE_HUMAN_TRYING_TO_ENGAGE_ZERO_HUMANS      = "Trying to engage zero humans.";
std::string const ENGAGE_HUMAN_UNEXPECTED_ERROR                  = "Unexpected error.";

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_CONSTANTS_HPP
