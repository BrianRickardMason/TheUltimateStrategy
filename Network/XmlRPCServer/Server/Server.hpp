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

#ifndef NETWORK_XMLRPCSERVER_SERVER_SERVER_HPP
#define NETWORK_XMLRPCSERVER_SERVER_SERVER_HPP

#include "../Connection/IConnection.hpp"
#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace Network
{
namespace XmlRPCServer
{
namespace Server
{

/**
 * @brief The top-level class of the server.
 */
class Server
    : private boost::noncopyable
{
public:
    /**
     * @brief Constructs the server to listen on the specified TCP address and port.
     *
     * @param a_address          A TCP address of the server.
     * @param a_port             A port of the server.
     * @param a_thread_pool_size A size of the thread pool.
     */
    Server(
        std::string        const & a_address,
        std::string        const & a_port,
        unsigned short int const   a_thread_pool_size
    );

    /**
     * @brief Runs the server's io_service loop.
     */
    void run();

    /**
     * @brief Stops the server.
     */
    void stop();

private:
    /**
     * @brief Handles the completion of an asynchronous accept operation.
     *
     * @param a_error An error code.
     */
    void handleAccept(
        boost::system::error_code const & a_error
    );

    /**
     * @brief The number of threads that will call io_service::run().
     */
    unsigned short int m_thread_pool_size;

    /**
     * @brief The io_service used to perform asynchronous operations.
     */
    boost::asio::io_service m_io_service;

    /**
     * @brief The acceptor used to listen for incoming connections.
     */
    boost::asio::ip::tcp::acceptor m_acceptor;

    /**
     * @brief The next connection to be accepted.
     */
    Connection::IConnectionShrPtr m_new_connection;

    /**
     * @brief The total number of served connections.
     */
    unsigned long long int m_served;
};

} // namespace Server
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_SERVER_SERVER_HPP
