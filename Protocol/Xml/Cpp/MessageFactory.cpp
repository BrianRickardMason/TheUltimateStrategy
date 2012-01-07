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

#include <Protocol/Xml/Cpp/MessageBuilder.hpp>
#include <Protocol/Xml/Cpp/MessageFactory.hpp>

namespace TUSProtocol
{

Message::SingleHandle MessageFactory::createEchoRequest() const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(1);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createErrorRequest() const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(2);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createCreateLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(3, "Login", "Password");
    message_builder.addRequest("create_land_request");
    message_builder.addParam("world_name", a_world_name);
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDeleteLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(4, "Login", "Password");
    message_builder.addRequest("delete_land_request");
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(5, "Login", "Password");
    message_builder.addRequest("get_land_request");
    message_builder.addParam("land_name", a_land_name);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetLandsRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(6, "Login", "Password");
    message_builder.addRequest("get_lands_request");

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createCreateSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(7);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDeleteSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(8);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(9);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetSettlementsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(10);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createBuildBuildingRequest(
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
    message_builder.addHeader(11);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDestroyBuildingRequest(
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
    message_builder.addHeader(12);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(13);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetBuildingsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(14);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDismissHumanRequest(
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
    message_builder.addHeader(15);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createEngageHumanRequest(
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
    message_builder.addHeader(16);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(17);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetHumansRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(18);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetResourceRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_resource_key
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(19);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetResourcesRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(20);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createCreateUserRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(21);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createCreateWorldRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(22);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createCreateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_epoch_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(23);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDeleteEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(24);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createActivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(25);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createDeactivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(26);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createFinishEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(27);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createTickEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(28);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createGetEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    MessageBuilder message_builder;

    message_builder.makeMessage();
    message_builder.addHeader(29);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createTransportHumanRequest(
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
    message_builder.addHeader(30);

    return message_builder.extract();
}

Message::SingleHandle MessageFactory::createTransportResourceRequest(
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
    message_builder.addHeader(21);

    return message_builder.extract();
}

} // namespace TUSProtocol
