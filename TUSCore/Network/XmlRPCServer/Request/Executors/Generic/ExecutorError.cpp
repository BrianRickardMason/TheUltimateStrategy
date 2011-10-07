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

#include "ExecutorError.hpp"
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistency;
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

void ExecutorError::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorError.";
}

bool ExecutorError::getParameters(
    RequestShrPtr a_request
)
{
    return true;
}

bool ExecutorError::processParameters()
{
    return true;
}

bool ExecutorError::authenticate(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

bool ExecutorError::getActingUser(
    IPersistencyShrPtr a_persistency
)
{
    return true;
}

bool ExecutorError::authorize(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

bool ExecutorError::epochIsActive(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

bool ExecutorError::verifyWorldConfiguration(
    IPersistencyShrPtr a_persistency
) const
{
    return true;
}

ReplyShrPtr ExecutorError::perform(
    IPersistencyShrPtr a_persistency
) const
{
    return getBasicReply(REPLY_STATUS_OK);
}

ReplyShrPtr ExecutorError::getBasicReply(
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
