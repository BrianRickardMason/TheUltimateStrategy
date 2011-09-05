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

#include "ConnectionDisposable.hpp"

#include "../../XmlRPCCommon/Request/Request.hpp"
#include "../Request/RequestParser.hpp"
#include <boost/bind.hpp>
#include <log4cpp/Category.hh>

using namespace log4cpp;
using namespace std;

namespace Network
{
namespace XmlRPCServer
{
namespace Connection
{

ConnectionDisposable::ConnectionDisposable(
    boost::asio::io_service & a_io_service
)
    : m_socket(a_io_service),
      m_request_parser(new Request::RequestParser),
      m_request_wrapper(new XmlRPCCommon::Common::MessageWrapper)
{
}

boost::asio::ip::tcp::socket & ConnectionDisposable::getSocket()
{
    return m_socket;
}

void ConnectionDisposable::start()
{
    Category::getInstance("Category").infoStream() << "Starting the connection.";

    try
    {
        boost::asio::read_until(m_socket, m_request_wrapper->m_buffer, "</request>");
    }
    catch (boost::system::system_error e)
    {
        Category::getInstance("Category").errorStream() << "An error occurred while reading from socket.";
        Category::getInstance("Category").errorStream() << e.what();
    }

    processRequest();
}

void ConnectionDisposable::processRequest()
{
    Category::getInstance("Category").infoStream() << "Processing the request.";

    try
    {
        XmlRPCCommon::Request::RequestShrPtr request = m_request_parser->parse(m_request_wrapper);

        m_request_wrapper.reset(new XmlRPCCommon::Common::MessageWrapper);

        handleRequest(request);
    }
    catch (boost::shared_ptr<Network::XmlRPCCommon::Request::InvalidRequest>)
    {
        Category::getInstance("Category").errorStream() << "An error occurred while parsing the request.";
    }

}

void ConnectionDisposable::handleRequest(
    XmlRPCCommon::Request::RequestShrPtr a_request
)
{
    Category::getInstance("Category").infoStream() << "Handling the request.";

    // Handle the request.
    XmlRPCCommon::Reply::ReplyShrPtr reply = m_request_handler.handleRequest(a_request);

    if (reply)
    {
        sendReply(reply);
    }
    else
    {
        Category::getInstance("Category").errorStream() << "An error occurred while handling the request.";
    }
}

void ConnectionDisposable::sendReply(
    XmlRPCCommon::Reply::ReplyShrPtr a_reply
)
{
    Category::getInstance("Category").infoStream() << "Sending the reply.";

    try
    {
        boost::asio::write(m_socket, a_reply->toWrapper()->m_buffer);
    }
    catch (boost::system::system_error e)
    {
        Category::getInstance("Category").errorStream() << "An error occurred while sending the reply.";
        Category::getInstance("Category").errorStream() << e.what();
    }

    finishHandling();
}

void ConnectionDisposable::finishHandling()
{
    Category::getInstance("Category").infoStream() << "Closing the connection.";

    // Initiate graceful connection closure.
    boost::system::error_code ignored_ec;
    m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
}

} // namespace Connection
} // namespace XmlRPCServer
} // namespace Network
