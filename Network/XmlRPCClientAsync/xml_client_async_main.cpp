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

#include "Client/Client.hpp"

#include <iostream>

/**
 * @brief A main entry to the XmlRPCClient.
 *
 * TODO: Review the way io_services are being run (I'd rather go for synchronous calls).
 */
int main(
    int    argc,
    char * argv[]
)
{
    try
    {
        if (argc != 3)
        {
            std::cerr << "Usage: XmlRPCClient <address> <port>\n";
            std::cerr << "  For IPv4, try:\n";
            std::cerr << "    XmlRPCClient 0.0.0.0 2222\n";
            std::cerr << "  For IPv6, try:\n";
            std::cerr << "    XmlRPCClient 0::0 2222\n";
            return 1;
        }

        boost::asio::io_service io_service;
        Network::XmlRPCClient::Client::Client client(io_service, argv[1], argv[2]);
        io_service.run();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
