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

#ifndef GAME_CONSTANTS_HPP
#define GAME_CONSTANTS_HPP

#include <string>

namespace Game
{

/**
 * @brief The identifiers of the requests.
 */
unsigned short int const REQUEST_ID_ECHO               =  1;
unsigned short int const REQUEST_ID_ERROR              =  2;

unsigned short int const REQUEST_ID_CREATE_LAND        =  3;
unsigned short int const REQUEST_ID_DELETE_LAND        =  4;
unsigned short int const REQUEST_ID_GET_LAND           =  5;
unsigned short int const REQUEST_ID_GET_LANDS          =  6;

unsigned short int const REQUEST_ID_CREATE_SETTLEMENT  =  7;
unsigned short int const REQUEST_ID_DELETE_SETTLEMENT  =  8;
unsigned short int const REQUEST_ID_GET_SETTLEMENT     =  9;
unsigned short int const REQUEST_ID_GET_SETTLEMENTS    = 10;

unsigned short int const REQUEST_ID_BUILD_BUILDING     = 11;
unsigned short int const REQUEST_ID_DESTROY_BUILDING   = 12;
unsigned short int const REQUEST_ID_GET_BUILDING       = 13;
unsigned short int const REQUEST_ID_GET_BUILDINGS      = 14;

unsigned short int const REQUEST_ID_DISMISS_HUMAN      = 15;
unsigned short int const REQUEST_ID_ENGAGE_HUMAN       = 16;
unsigned short int const REQUEST_ID_GET_HUMAN          = 17;
unsigned short int const REQUEST_ID_GET_HUMANS         = 18;

unsigned short int const REQUEST_ID_GET_RESOURCE       = 19;
unsigned short int const REQUEST_ID_GET_RESOURCES      = 20;

unsigned short int const REQUEST_ID_CREATE_USER        = 21;

unsigned short int const REQUEST_ID_CREATE_WORLD       = 22;

unsigned short int const REQUEST_ID_CREATE_EPOCH       = 23;
unsigned short int const REQUEST_ID_DELETE_EPOCH       = 24;
unsigned short int const REQUEST_ID_ACTIVATE_EPOCH     = 25;
unsigned short int const REQUEST_ID_DEACTIVATE_EPOCH   = 26;
unsigned short int const REQUEST_ID_FINISH_EPOCH       = 27;
unsigned short int const REQUEST_ID_TICK_EPOCH         = 28;
unsigned short int const REQUEST_ID_GET_EPOCH          = 29;

unsigned short int const REQUEST_ID_TRANSPORT_HUMAN    = 30;
unsigned short int const REQUEST_ID_TRANSPORT_RESOURCE = 31;

//@{
/**
 * @brief An identifier of the reply.
 */
unsigned short int const REPLY_ID_ECHO               =  1;
unsigned short int const REPLY_ID_ERROR              =  2;
unsigned short int const REPLY_ID_CREATE_LAND        =  3;
unsigned short int const REPLY_ID_DELETE_LAND        =  4;
unsigned short int const REPLY_ID_GET_LAND           =  5;
unsigned short int const REPLY_ID_GET_LANDS          =  6;
unsigned short int const REPLY_ID_CREATE_SETTLEMENT  =  7;
unsigned short int const REPLY_ID_DELETE_SETTLEMENT  =  8;
unsigned short int const REPLY_ID_GET_SETTLEMENT     =  9;
unsigned short int const REPLY_ID_GET_SETTLEMENTS    = 10;
unsigned short int const REPLY_ID_BUILD_BUILDING     = 11;
unsigned short int const REPLY_ID_DESTROY_BUILDING   = 12;
unsigned short int const REPLY_ID_GET_BUILDING       = 13;
unsigned short int const REPLY_ID_GET_BUILDINGS      = 14;
unsigned short int const REPLY_ID_DISMISS_HUMAN      = 15;
unsigned short int const REPLY_ID_ENGAGE_HUMAN       = 16;
unsigned short int const REPLY_ID_GET_HUMAN          = 17;
unsigned short int const REPLY_ID_GET_HUMANS         = 18;
unsigned short int const REPLY_ID_GET_RESOURCE       = 19;
unsigned short int const REPLY_ID_GET_RESOURCES      = 20;
unsigned short int const REPLY_ID_CREATE_USER        = 21;
unsigned short int const REPLY_ID_CREATE_WORLD       = 22;
unsigned short int const REPLY_ID_CREATE_EPOCH       = 23;
unsigned short int const REPLY_ID_DELETE_EPOCH       = 24;
unsigned short int const REPLY_ID_ACTIVATE_EPOCH     = 25;
unsigned short int const REPLY_ID_DEACTIVATE_EPOCH   = 26;
unsigned short int const REPLY_ID_FINISH_EPOCH       = 27;
unsigned short int const REPLY_ID_TICK_EPOCH         = 28;
unsigned short int const REPLY_ID_GET_EPOCH          = 29;
unsigned short int const REPLY_ID_TRANSPORT_HUMAN    = 30;
unsigned short int const REPLY_ID_TRANSPORT_RESOURCE = 31;
//}@

//@{
/**
 * @brief A status of the reply.
 */
unsigned short int const REPLY_STATUS_SERVER_IS_NOT_LISTENING      =  1;
unsigned short int const REPLY_STATUS_INVALID_REQUEST              =  2;
unsigned short int const REPLY_STATUS_INVALID_RANGE                =  3;
unsigned short int const REPLY_STATUS_UNAUTHENTICATED              =  4;
unsigned short int const REPLY_STATUS_ACTING_USER_HAS_NOT_BEEN_GOT =  5;
unsigned short int const REPLY_STATUS_NON_MODERATOR_FILTERED_OUT   =  6;
unsigned short int const REPLY_STATUS_UNAUTHORIZED                 =  7;
unsigned short int const REPLY_STATUS_EPOCH_IS_NOT_ACTIVE          =  8;
unsigned short int const REPLY_STATUS_ACTION_UNAVAILABLE           =  9;
unsigned short int const REPLY_STATUS_OK                           = 10;
//}@

//@{
/**
 * @brief A content of the message.
 */
std::string const METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE =
    "Even more unexpected error: unknown exit code.";

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

std::string const CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS = "Another land of the given name exists.";
std::string const CREATE_LAND_EPOCH_DOES_NOT_EXIST                  = "Epoch does not exist.";
std::string const CREATE_LAND_LAND_HAS_BEEN_CREATED                 = "Land has been created.";
std::string const CREATE_LAND_LAND_HAS_NOT_BEEN_CREATED             = "Land has not been created.";
std::string const CREATE_LAND_UNEXPECTED_ERROR                      = "Unexpected error.";
std::string const CREATE_LAND_WORLD_DOES_NOT_EXIST                  = "World does not exist.";

std::string const DELETE_LAND_LAND_DOES_NOT_EXIST       = "Land does not exist.";
std::string const DELETE_LAND_LAND_HAS_BEEN_DELETED     = "Land has been deleted.";
std::string const DELETE_LAND_LAND_HAS_NOT_BEEN_DELETED = "Land has not been deleted.";
std::string const DELETE_LAND_UNEXPECTED_ERROR          = "Unexpected error.";

std::string const GET_LAND_LAND_HAS_BEEN_GOT     = "Land has been got.";
std::string const GET_LAND_LAND_HAS_NOT_BEEN_GOT = "Land has not been got.";
std::string const GET_LAND_UNEXPECTED_ERROR      = "Unexpected error.";

std::string const GET_LANDS_LANDS_HAVE_BEEN_GOT     = "Lands have been got.";
std::string const GET_LANDS_LANDS_HAVE_NOT_BEEN_GOT = "Lands have not been got.";
std::string const GET_LANDS_UNEXPECTED_ERROR        = "Unexpected error.";

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

std::string const GET_SETTLEMENT_BY_LANDNAME_AND_NAME_LAND_DOES_NOT_EXIST         = "Land does not exist.";
std::string const GET_SETTLEMENT_BY_LANDNAME_AND_NAME_SETTLEMENT_HAS_BEEN_GOT     = "Settlement has been got.";
std::string const GET_SETTLEMENT_BY_LANDNAME_AND_NAME_SETTLEMENT_HAS_NOT_BEEN_GOT = "Settlement has not been got.";
std::string const GET_SETTLEMENT_BY_LANDNAME_AND_NAME_UNEXPECTED_ERROR            = "Unexpected error.";

std::string const GET_SETTLEMENT_SETTLEMENT_HAS_BEEN_GOT     = "Settlement has been got.";
std::string const GET_SETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_GOT = "Settlement has not been got.";
std::string const GET_SETTLEMENT_UNEXPECTED_ERROR            = "Unexpected error.";

std::string const GET_SETTLEMENTS_BY_LANDNAME_LAND_DOES_NOT_EXIST           = "Land does not exist.";
std::string const GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_BEEN_GOT     = "Settlements have been got.";
std::string const GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_NOT_BEEN_GOT = "Settlements have not been got.";
std::string const GET_SETTLEMENTS_BY_LANDNAME_UNEXPECTED_ERROR              = "Unexpected error.";

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
//}@

} // namespace Game

#endif // GAME_CONSTANTS_HPP
