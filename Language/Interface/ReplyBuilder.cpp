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
#include <Language/Interface/ReplyBuilder.hpp>

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

ICommand::SingleHandle ReplyBuilder::buildCreateLandReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(34);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDeleteLandReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(35);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetLandReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(36);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetLandsReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Objects  const & a_objects
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(37);
    command->setCode(a_code);
    command->setMessage(a_message);
    for (ICommand::Objects::const_iterator it = a_objects.begin(); it != a_objects.end(); ++it)
    {
        command->addObject((*it));
    }
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildCreateSettlementReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(38);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDeleteSettlementReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(39);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetSettlementReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(40);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetSettlementsReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Objects  const & a_objects
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(41);
    command->setCode(a_code);
    command->setMessage(a_message);
    for (ICommand::Objects::const_iterator it = a_objects.begin(); it != a_objects.end(); ++it)
    {
        command->addObject((*it));
    }
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildBuildBuildingReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(42);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDestroyBuildingReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(43);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetBuildingReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(44);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetBuildingsReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Objects  const & a_objects
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(45);
    command->setCode(a_code);
    command->setMessage(a_message);
    for (ICommand::Objects::const_iterator it = a_objects.begin(); it != a_objects.end(); ++it)
    {
        command->addObject((*it));
    }
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDismissHumanReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(46);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildEngageHumanReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(47);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetHumanReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(48);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetHumansReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Objects  const & a_objects
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(49);
    command->setCode(a_code);
    command->setMessage(a_message);
    for (ICommand::Objects::const_iterator it = a_objects.begin(); it != a_objects.end(); ++it)
    {
        command->addObject((*it));
    }
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetResourceReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(50);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetResourcesReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Objects  const & a_objects
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(51);
    command->setCode(a_code);
    command->setMessage(a_message);
    for (ICommand::Objects::const_iterator it = a_objects.begin(); it != a_objects.end(); ++it)
    {
        command->addObject((*it));
    }
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildCreateUserReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(52);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildCreateWorldReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(53);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildCreateEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(54);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDeleteEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(55);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildActivateEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(56);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildDeactivateEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(57);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildFinishEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(58);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildTickEpochReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(59);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildGetEpochReply(
    unsigned short int const   a_code,
    std::string        const   a_message,
    ICommand::Object   const & a_object
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(60);
    command->setCode(a_code);
    command->setMessage(a_message);
    command->addObject(a_object);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildTransportHumanReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(61);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

ICommand::SingleHandle ReplyBuilder::buildTransportResourceReply(
    unsigned short int const a_code,
    std::string        const a_message
) const
{
    ICommand::SingleHandle command(new Command);
    command->setID(62);
    command->setCode(a_code);
    command->setMessage(a_message);
    return command;
}

} // namespace TUSLanguage
