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

#include <Integration/IntegrationFunctional/Helpers/XmlRPCClient/ClientSynchronous/ClientSynchronous.hpp>
#include <boost/make_shared.hpp>
#include <iostream>

using namespace Network::XmlRPCCommon::Common;
using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace std;

Client::Client(
    io_service       & a_io_service,
    string     const & a_address,
    string     const & a_port
)
    : m_resolver(a_io_service),
      m_socket(a_io_service),
      m_reply_wrapper(new MessageWrapper),
      m_address(a_address),
      m_port(a_port)
{
}

ReplyShrPtr Client::sendRequest(
    RequestShrPtr a_request
)
{
    try
    {
        tcp::resolver::query query(m_address, m_port);
        tcp::resolver::iterator it = m_resolver.resolve(query);
        m_socket.connect(*it);

        write(m_socket, a_request->toWrapper()->m_buffer);
        read_until(m_socket, m_reply_wrapper->m_buffer, "</reply>");

        ReplyShrPtr reply = make_shared<Reply>(m_reply_wrapper);

        m_reply_wrapper.reset(new MessageWrapper) ;

        boost::system::error_code ignored_ec;
        m_socket.close();
        m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);

        return reply;
    }
    catch (boost::system::system_error e)
    {
        std::cout << e.what() << std::endl;
        BOOST_ASSERT(false);
    }
}
