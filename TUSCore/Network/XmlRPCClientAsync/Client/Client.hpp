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

#ifndef NETWORK_XMLRPCSERVER_CLIENT_CLIENT_HPP
#define NETWORK_XMLRPCSERVER_CLIENT_CLIENT_HPP

#include "../../XmlRPCCommon/Common/MessageWrapper.hpp"

namespace Network
{
namespace XmlRPCClient
{
namespace Client
{

/**
 * @brief The top-level class of the client.
 */
class Client
{
public:
    /**
     * @brief Constructs the client to sent to the specified TCP address and port.
     *
     * @param a_io_service The io service.
     * @param a_address    A TCP address of the server.
     * @param a_port       A port of the server.
     */
    Client(
        boost::asio::io_service       & a_io_service,
        std::string             const & a_address,
        std::string             const & a_port
    );

private:
    /**
     * @brief Handles the completion of an asynchronous resolve operation.
     *
     * @param a_error             An error code.
     * @param a_endpoint_iterator An endpoint iterator.
     */
    void handle_resolve(
        boost::system::error_code                const & a_error,
        boost::asio::ip::tcp::resolver::iterator         a_endpoint_iterator
    );

    /**
     * @brief Handles the completion of an asynchronous connect operation.
     *
     * @param a_error             An error code.
     * @param a_endpoint_iterator An endpoint iterator.
     */
    void handle_connect(
        boost::system::error_code                const & a_error,
        boost::asio::ip::tcp::resolver::iterator         a_endpoint_iterator
    );

    /**
     * @brief Handles the completion of an asynchronous write operation.
     *
     * @param a_error An error code.
     */
    void handle_write(
        boost::system::error_code const & a_error
    );

    /**
     * @brief Handles the completion of an asynchronous read operation.
     *
     * @param a_error An error code.
     */
    void handle_read(
        boost::system::error_code const & a_error
    );

    /**
     * @brief A tcp resolver.
     */
    boost::asio::ip::tcp::resolver m_resolver;

    /**
     * @brief A socket for the connection.
     */
    boost::asio::ip::tcp::socket m_socket;

    /**
     * @brief The message wrapper of the request.
     */
    Network::XmlRPCCommon::Common::MessageWrapperShrPtr m_request_wrapper;

    /**
     * @brief The message wrapper of the reply.
     */
    Network::XmlRPCCommon::Common::MessageWrapperShrPtr m_reply_wrapper;
};

} // namespace Client
} // namespace XmlRPCClient
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_CLIENT_CLIENT_HPP
