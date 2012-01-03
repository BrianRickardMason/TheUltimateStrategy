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

#include <Server/Network/XmlRPCServer/Request/Executors/Generic/ExecutorEcho.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace Network::XmlRPCCommon::Xml;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

ExecutorEcho::ExecutorEcho(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorEcho::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorEcho.";
}

bool ExecutorEcho::getParameters(
    RequestShrPtr a_request
)
{
    return true;
}

bool ExecutorEcho::processParameters()
{
    return true;
}

bool ExecutorEcho::authenticate(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorEcho::getActingUser(
    IPersistenceShrPtr a_persistence
)
{
    return true;
}

bool ExecutorEcho::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorEcho::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorEcho::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

ReplyShrPtr ExecutorEcho::perform(
    IPersistenceShrPtr a_persistence
) const
{
    return getBasicReply(REPLY_STATUS_OK);
}

ReplyShrPtr ExecutorEcho::getBasicReply(
    unsigned int const a_status
) const
{
    ReplyShrPtr reply = make_shared<Reply>();

    reply->m_xml_document->appendNode("reply")->appendAttribute("id")->setValue(REPLY_ID_ECHO);
    reply->m_xml_document->getNode("reply")->appendNode("status")->appendAttribute("value")->setValue(a_status);

    return reply;
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
