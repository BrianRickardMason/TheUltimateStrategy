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

#ifndef NETWORK_XMLRPCSERVER_CONNECTION_ICONNECTION_HPP
#define NETWORK_XMLRPCSERVER_CONNECTION_ICONNECTION_HPP

#include <boost/asio.hpp>

namespace Network
{
namespace XmlRPCServer
{
namespace Connection
{

/**
 * @brief The interface of a connection.
 */
class IConnection
    : boost::noncopyable
{
public:
    /**
     * @brief Gets the socket associated with the connection.
     *
     * @return The socket associated with the connection.
     */
    virtual boost::asio::ip::tcp::socket & getSocket() = 0;

    /**
     * @brief Starts the first asynchronous operation for the connection.
     */
    virtual void start() = 0;

protected:
     /**
      * @brief Destructs the connection.
      */
    virtual ~IConnection(){}
};

/**
 * @brief A shared pointer of the interface of a connection.
 */
typedef boost::shared_ptr<IConnection> IConnectionShrPtr;

} // namespace Connection
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_CONNECTION_ICONNECTION_HPP
