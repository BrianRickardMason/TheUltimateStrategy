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

#include "Client.hpp"

#include "../../XmlRPCCommon/Request/Request.hpp"
#include <boost/bind.hpp>
#include <iostream>
#include <string>

using namespace boost::asio::ip;
using namespace std;

namespace Network
{
namespace XmlRPCClient
{
namespace Client
{

Client::Client(
    boost::asio::io_service       & a_io_service,
    string                  const & a_address,
    string                  const & a_port
)
    : m_resolver(a_io_service),
      m_socket(a_io_service),
      m_request_wrapper(new XmlRPCCommon::Common::MessageWrapper),
      m_reply_wrapper(new XmlRPCCommon::Common::MessageWrapper)
{
    // Prepare the request.
    // TODO: Add a constant for a request identifier.
    string content1  = "<?xml version=\"1.0\"?>";
           content1 += "<request id=\"2\">";
           content1 +=     "<parameters>";
           content1 +=         "<userid value=\"1\" />";
           content1 +=         "<name value=\"Land1\" />";
           content1 +=     "</parameters>";
           content1 += "</request>";

    // TODO: Add a constant for a request identifier.
    string content2  = "<?xml version=\"1.0\"?>";
           content2 += "<request id=\"1\">";
           content2 +=     "<parameters />";
           content2 += "</request>";

    m_request_wrapper->setContent(content2);

    tcp::resolver::query query(a_address, a_port);

    m_resolver.async_resolve(
        query,
        boost::bind(
            &Client::handle_resolve,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::iterator
        )
    );
}

void Client::handle_resolve(
    boost::system::error_code const & a_error,
    tcp::resolver::iterator           a_endpoint_iterator
)
{
    if (!a_error)
    {
        // Attempt a connection to the first endpoint in the list. Each endpoint
        // will be tried until we successfully establish a connection.
        tcp::endpoint endpoint = *a_endpoint_iterator;
        m_socket.async_connect(
            endpoint,
            boost::bind(
                &Client::handle_connect,
                this,
                boost::asio::placeholders::error,
                ++a_endpoint_iterator
            )
        );
    }
    else
    {
        cout << "Error: " << a_error.message() << "\n";
    }
}

void Client::handle_connect(
    boost::system::error_code const & a_error,
    tcp::resolver::iterator           a_endpoint_iterator
)
{
    if (!a_error)
    {
        // The connection was successful. Send the request.
        boost::asio::async_write(
            m_socket,
            m_request_wrapper->m_buffer,
            boost::bind(
                &Client::handle_write,
                this,
                boost::asio::placeholders::error
            )
        );
    }
    else if (a_endpoint_iterator != tcp::resolver::iterator())
    {
        // The connection failed. Try the next endpoint in the list.
        m_socket.close();
        tcp::endpoint endpoint = *a_endpoint_iterator;
        m_socket.async_connect(
            endpoint,
            boost::bind(
                &Client::handle_connect,
                this,
                boost::asio::placeholders::error,
                ++a_endpoint_iterator
            )
        );
    }
    else
    {
        cout << "Error: " << a_error.message() << "\n";
    }
}

void Client::handle_write(
    boost::system::error_code const & a_error
)
{
    if (!a_error)
    {
        boost::asio::async_read_until(
            m_socket,
            m_reply_wrapper->m_buffer,
            "</reply>",
            boost::bind(
                &Client::handle_read,
                this,
                boost::asio::placeholders::error));
    }
    else
    {
        cout << "Error: " << a_error.message() << "\n";
    }
}

void Client::handle_read(
    boost::system::error_code const & a_error
)
{
    if (!a_error)
    {
        // Initiate graceful connection closure.
        boost::system::error_code ignored_ec;
        m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
    }

    // No new asynchronous operations are started.
    // This means that all shared_ptr references to the connection object will disappear and the object will be
    // destroyed automatically after this handler returns. The connection class's destructor closes the socket.
}

} // namespace Client
} // namespace XmlRPCClient
} // namespace Network
