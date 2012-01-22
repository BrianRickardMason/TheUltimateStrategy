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

#ifndef PROTOCOL_MESSAGEFACTORY_HPP
#define PROTOCOL_MESSAGEFACTORY_HPP

#include <Protocol/Xml/Cpp/Message.hpp>
#include <boost/noncopyable.hpp>

namespace Protocol
{

class MessageFactory
    : boost::noncopyable
{
public:
    Message::Handle createEchoRequest() const;

    Message::Handle createErrorRequest() const;

    Message::Handle createCreateLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_land_name
    ) const;

    Message::Handle createDeleteLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    Message::Handle createGetLandRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    Message::Handle createGetLandsRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    Message::Handle createCreateSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name,
        std::string const a_settlement_name
    ) const;

    Message::Handle createDeleteSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    Message::Handle createGetSettlementRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name
    ) const;

    Message::Handle createGetSettlementsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_land_name
    ) const;

    Message::Handle createBuildBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    Message::Handle createDestroyBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    Message::Handle createGetBuildingRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_building_key
    ) const;

    Message::Handle createGetBuildingsRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    Message::Handle createDismissHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    Message::Handle createEngageHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    Message::Handle createGetHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_human_key
    ) const;

    Message::Handle createGetHumansRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    Message::Handle createGetResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name,
        std::string const a_resource_key
    ) const;

    Message::Handle createGetResourcesRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_id_holder_class,
        std::string const a_holder_name
    ) const;

    Message::Handle createCreateUserRequest(
        std::string const a_login,
        std::string const a_password
    ) const;

    Message::Handle createCreateWorldRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createCreateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name,
        std::string const a_epoch_name
    ) const;

    Message::Handle createDeleteEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createActivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createDeactivateEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createFinishEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createTickEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createGetEpochRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_world_name
    ) const;

    Message::Handle createTransportHumanRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    Message::Handle createTransportResourceRequest(
        std::string const a_login,
        std::string const a_password,
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_resource_key,
        std::string const a_volume
    ) const;

    Message::Handle createEchoReply(
        std::string const a_code
    ) const;

    Message::Handle createErrorReply(
        std::string const a_code
    ) const;

    Message::Handle createCreateLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createDeleteLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetLandReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetLandReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createGetLandsReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetLandsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    Message::Handle createCreateSettlementReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createDeleteSettlementReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetSettlementReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetSettlementReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createGetSettlementsReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetSettlementsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    Message::Handle createBuildBuildingReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createDestroyBuildingReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetBuildingReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetBuildingReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createGetBuildingsReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetBuildingsReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    Message::Handle createDismissHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createEngageHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetHumanReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createGetHumansReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetHumansReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    Message::Handle createGetResourceReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetResourceReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createGetResourcesReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetResourcesReply(
        std::string      const   a_code,
        std::string      const   a_message,
        Message::Objects const & a_objects
    ) const;

    Message::Handle createCreateUserReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createCreateWorldReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createCreateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createDeleteEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createActivateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createDeactivateEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createFinishEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createTickEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetEpochReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createGetEpochReply(
        std::string     const   a_code,
        std::string     const   a_message,
        Message::Object const & a_object
    ) const;

    Message::Handle createTransportHumanReply(
        std::string const a_code,
        std::string const a_message
    ) const;

    Message::Handle createTransportResourceReply(
        std::string const a_code,
        std::string const a_message
    ) const;
};

} // namespace Protocol

#endif // PROTOCOL_MESSAGEFACTORY_HPP
