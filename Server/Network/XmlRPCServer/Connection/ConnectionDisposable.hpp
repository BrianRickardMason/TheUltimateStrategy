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

#ifndef NETWORK_XMLRPCSERVER_CONNECTION_CONNECTIONDISPOSABLE_HPP
#define NETWORK_XMLRPCSERVER_CONNECTION_CONNECTIONDISPOSABLE_HPP

#include <Server/Network/XmlRPCCommon/Reply/Reply.hpp>
#include <Server/Network/XmlRPCServer/Connection/IConnection.hpp>
#include <Server/Network/XmlRPCServer/IContext.hpp>
#include <Server/Network/XmlRPCServer/Request/IRequestParser.hpp>
#include <Server/Network/XmlRPCServer/Request/RequestHandler.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace Network
{
namespace XmlRPCServer
{
namespace Connection
{

/**
 * @brief Represents a single disposable connection from a client.
 *
 * TODO: Extract common class for the disposable and the sustainable connections.
 */
class ConnectionDisposable
    : public IConnection,
      public boost::enable_shared_from_this<ConnectionDisposable>
{
public:
    /**
     * @brief Constructs a connection with the given io_service.
     *
     * @param a_io_service The given io_service.
     * @param a_context    The context of the server.
     */
    ConnectionDisposable(
        boost::asio::io_service       & a_io_service,
        IContextShrPtr          const   a_context
    );

    /**
     * @brief Gets the socket associated with the connection.
     *
     * @return The socket associated with the connection.
     */
    boost::asio::ip::tcp::socket & getSocket();

    /**
     * @brief Starts the connection.
     */
    void start();

private:
    /**
     * @brief Processes the request.
     */
    void processRequest();

    /**
     * @brief Handles the request.
     *
     * @param a_request A request to be handled.
     */
    void handleRequest(
        XmlRPCCommon::Request::RequestShrPtr a_request
    );

    /**
     * @brief Sends the prepared reply.
     *
     * @param a_reply A reply to be sent.
     */
    void sendReply(
        XmlRPCCommon::Reply::ReplyShrPtr a_reply
    );

    /**
     * @brief Finishes the handling.
     */
    void finishHandling();

private:
    /**
     * @brief A socket for the connection.
     */
    boost::asio::ip::tcp::socket m_socket;

    /**
     * @brief A handler used to process the incoming request.
     */
    Request::RequestHandler m_request_handler;

    /**
     * @brief RequestParser.
     */
    Request::IRequestParserShrPtr m_request_parser;

    /**
     * @brief The message wrapper of the request.
     */
    XmlRPCCommon::Common::MessageWrapperShrPtr m_request_wrapper;

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;
};

} // namespace Connection
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_CONNECTION_CONNECTIONDISPOSABLE_HPP
