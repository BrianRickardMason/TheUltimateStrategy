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

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Server/include/ConnectionFactory.hpp>
#include <Server/include/Server.hpp>
#include <iostream>

namespace Server
{

Server::Server(
    IContextShrPtr aContext
)
    : mContext(aContext)
{
}

int Server::main(
    std::vector<std::string> const & aArguments
)
{
    startServer();

    return Poco::Util::Application::EXIT_OK;
}

void Server::startServer()
{
    if (not mServerStarted)
    {
        Poco::Net::SocketAddress address("localhost", 2222);
        Poco::Net::ServerSocket socket(address);

        ConnectionFactoryShrPtr connectionFactory(new ConnectionFactory(mContext));

        mServer.reset(new Poco::Net::TCPServer(connectionFactory, socket));

        mServer->start();
        mServerStarted = true;

        waitForTerminationRequest();

        mServer->stop();
    }
    else
    {
        // TODO: Apply Poco::Logger and remove <iostream> usage.
        std::clog << "Server has been started before." << std::endl;
    }
}

} // namespace Server
