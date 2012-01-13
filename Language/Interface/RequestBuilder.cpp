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
// OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include <Language/Interface/Command.hpp>
#include <Language/Interface/RequestBuilder.hpp>

namespace TUSLanguage
{

ICommand::Handle RequestBuilder::buildEchoRequest() const
{
    ICommand::Handle command(new Command);
    command->setID(1);
    return command;
}

ICommand::Handle RequestBuilder::buildErrorRequest() const
{
    ICommand::Handle command(new Command);
    command->setID(2);
    return command;
}

ICommand::Handle RequestBuilder::buildCreateLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_land_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(3);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    command->setParam("land_name", a_land_name);
    return command;
}

ICommand::Handle RequestBuilder::buildDeleteLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(4);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("land_name", a_land_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetLandRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(5);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("land_name", a_land_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetLandsRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    ICommand::Handle command(new Command);
    command->setID(6);
    command->setLogin(a_login);
    command->setPassword(a_password);
    return command;
}

ICommand::Handle RequestBuilder::buildCreateSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name,
    std::string const a_settlement_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(7);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("land_name", a_land_name);
    command->setParam("settlement_name", a_settlement_name);
    return command;
}

ICommand::Handle RequestBuilder::buildDeleteSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(8);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("settlement_name", a_settlement_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetSettlementRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(9);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("settlement_name", a_settlement_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetSettlementsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_land_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(10);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("land_name", a_land_name);
    return command;
}

ICommand::Handle RequestBuilder::buildBuildBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(11);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("buildingkey", a_building_key);
    command->setParam("volume", a_volume);
    return command;
}

ICommand::Handle RequestBuilder::buildDestroyBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(12);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("buildingkey", a_building_key);
    command->setParam("volume", a_volume);
    return command;
}

ICommand::Handle RequestBuilder::buildGetBuildingRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_building_key
) const
{
    ICommand::Handle command(new Command);
    command->setID(13);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("buildingkey", a_building_key);
    return command;
}

ICommand::Handle RequestBuilder::buildGetBuildingsRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(14);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    return command;
}

ICommand::Handle RequestBuilder::buildDismissHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(15);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("humankey", a_human_key);
    command->setParam("volume", a_volume);
    return command;
}

ICommand::Handle RequestBuilder::buildEngageHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(16);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("humankey", a_human_key);
    command->setParam("volume", a_volume);
    return command;
}

ICommand::Handle RequestBuilder::buildGetHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_human_key
) const
{
    ICommand::Handle command(new Command);
    command->setID(17);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("humankey", a_human_key);
    return command;
}

ICommand::Handle RequestBuilder::buildGetHumansRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(18);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetResourceRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name,
    std::string const a_resource_key
) const
{
    ICommand::Handle command(new Command);
    command->setID(19);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    command->setParam("resourcekey", a_resource_key);
    return command;
}

ICommand::Handle RequestBuilder::buildGetResourcesRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_id_holder_class,
    std::string const a_holder_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(20);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("idholderclass", a_id_holder_class);
    command->setParam("holder_name", a_holder_name);
    return command;
}

ICommand::Handle RequestBuilder::buildCreateUserRequest(
    std::string const a_login,
    std::string const a_password
) const
{
    ICommand::Handle command(new Command);
    command->setID(21);
    command->setParam("login", a_login);
    command->setParam("password", a_password);
    return command;
}

ICommand::Handle RequestBuilder::buildCreateWorldRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(22);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildCreateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name,
    std::string const a_epoch_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(23);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    command->setParam("epoch_name", a_epoch_name);
    return command;
}

ICommand::Handle RequestBuilder::buildDeleteEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(24);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildActivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(25);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildDeactivateEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(26);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildFinishEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(27);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildTickEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(28);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildGetEpochRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_world_name
) const
{
    ICommand::Handle command(new Command);
    command->setID(29);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("world_name", a_world_name);
    return command;
}

ICommand::Handle RequestBuilder::buildTransportHumanRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name_source,
    std::string const a_settlement_name_destination,
    std::string const a_human_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(30);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("settlement_name_source", a_settlement_name_source);
    command->setParam("settlement_name_destination", a_settlement_name_destination);
    command->setParam("humankey", a_human_key);
    command->setParam("volume", a_volume);
    return command;
}

ICommand::Handle RequestBuilder::buildTransportResourceRequest(
    std::string const a_login,
    std::string const a_password,
    std::string const a_settlement_name_source,
    std::string const a_settlement_name_destination,
    std::string const a_resource_key,
    std::string const a_volume
) const
{
    ICommand::Handle command(new Command);
    command->setID(31);
    command->setLogin(a_login);
    command->setPassword(a_password);
    command->setParam("settlement_name_source", a_settlement_name_source);
    command->setParam("settlement_name_destination", a_settlement_name_destination);
    command->setParam("resourcekey", a_resource_key);
    command->setParam("volume", a_volume);
    return command;
}

} // namespace TUSLanguage
