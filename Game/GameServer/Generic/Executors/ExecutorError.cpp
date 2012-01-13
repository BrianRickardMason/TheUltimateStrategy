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

#include <Game/GameServer/Common/Constants.hpp>
#include <Game/GameServer/Generic/Executors/ExecutorError.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorError::ExecutorError(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorError::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorError.";
}

bool ExecutorError::getParameters(
    TUSLanguage::ICommand::Handle a_request
)
{
    return true;
}

bool ExecutorError::processParameters()
{
    return true;
}

bool ExecutorError::authenticate(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorError::getActingUser(
    IPersistenceShrPtr a_persistence
)
{
    return true;
}

bool ExecutorError::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorError::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorError::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

TUSLanguage::ICommand::Handle ExecutorError::perform(
    IPersistenceShrPtr a_persistence
) const
{
    return getBasicReply(REPLY_STATUS_OK);
}

TUSLanguage::ICommand::Handle ExecutorError::getBasicReply(
    unsigned int const a_status
) const
{
	TUSLanguage::ReplyBuilder reply_builder;

    return reply_builder.buildErrorReply(a_status);
}

} // namespace Game
