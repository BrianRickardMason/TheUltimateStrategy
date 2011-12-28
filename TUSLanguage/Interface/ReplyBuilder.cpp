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
#include "ReplyBuilder.hpp"

namespace TUSLanguage
{

ICommand::SingleHandle ReplyBuilder::buildEchoReply(
    unsigned short int const a_code
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(32);
    command->setCode(a_code);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildErrorReply(
    unsigned short int const a_code
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(33);
    command->setCode(a_code);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildCreateLandReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDeleteLandReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetLandReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetLandsReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildCreateSettlementReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDeleteSettlementReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetSettlementReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetSettlementsReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildBuildBuildingReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDestroyBuildingReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetBuildingReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetBuildingsReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDismissHumanReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildEngageHumanReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetHumanReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetHumansReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetResourceReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetResourcesReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildCreateUserReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildCreateWorldReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildCreateEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDeleteEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildActivateEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildDeactivateEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildFinishEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildTickEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildGetEpochReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildTransportHumanReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

ICommand::SingleHandle ReplyBuilder::buildTransportResourceReply() const
{
    // TODO: Implement me!
    return ICommand::SingleHandle(new Command);
}

} // namespace TUSLanguage
