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
// OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include "Command.hpp"
#include "RequestBuilder.hpp"

namespace TUSLang
{

ICommand::SingleHandle RequestBuilder::buildEchoRequest() const
{
	ICommand::SingleHandle command(new Command);
	command->setID(1);
	return command;
}

ICommand::SingleHandle RequestBuilder::buildErrorRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildCreateLandRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDeleteLandRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetLandRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetLandsRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildCreateSettlementRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDeleteSettlementRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetSettlementRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetSettlementsRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildBuildBuildingRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDestroyBuildingRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetBuildingRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetBuildingsRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDismissHumanRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildEngageHumanRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetHumanRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetHumansRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetResourceRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetResourcesRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildCreateUserRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildCreateWorldRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildCreateEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDeleteEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildActivateEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildDeactivateEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildFinishEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildTickEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildGetEpochRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildTransportHumanRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle RequestBuilder::buildTransportResourceRequest() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

} // namespace TUSLang
