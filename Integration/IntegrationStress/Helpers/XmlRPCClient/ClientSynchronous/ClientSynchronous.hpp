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

#ifndef CLIENTSYNCHRONOUS_HPP
#define CLIENTSYNCHRONOUS_HPP

#include <Integration/IntegrationCommon/Helpers/XmlRPCClient/ClientSynchronous/IClientSynchronous.hpp>

/**
 * @brief The top-level class of the client.
 */
class Client
    : public IClient
{
public:
    /**
     * @brief Constructs the client.
     *
     * @param a_io_service An io service.
     * @param a_address    A TCP address of the server.
     * @param a_port       A port of the server.
     */
    Client(
        boost::asio::io_service       & a_io_service,
        std::string             const & a_address,
        std::string             const & a_port
    );

    /**
     * @brief Sends a request and awaits for a reply.
     *
     * @param a_request The request to be processed.
     *
     * @return The reply.
     */
    virtual Network::XmlRPCCommon::Reply::ReplyShrPtr sendRequest(
        Network::XmlRPCCommon::Request::RequestShrPtr a_request
    );

private:
    /**
     * @brief A tcp resolver.
     */
    boost::asio::ip::tcp::resolver m_resolver;

    /**
     * @brief A socket for the connection.
     */
    boost::asio::ip::tcp::socket m_socket;

    /**
     * @brief The message wrapper of the reply.
     */
    Network::XmlRPCCommon::Common::MessageWrapperShrPtr m_reply_wrapper;

    /**
     * @brief The address of a server.
     */
    std::string m_address;

    /**
     * @brief The port of a server.
     */
    std::string m_port;
};

#endif // CLIENTSYNCHRONOUS_HPP
