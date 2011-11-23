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

#include "../Connection/ConnectionDisposable.hpp"
#include "Server.hpp"
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <log4cpp/Category.hh>

using namespace log4cpp;
using namespace std;

namespace Network
{
namespace XmlRPCServer
{
namespace Server
{

Server::Server(
    string             const a_address,
    string             const a_port,
    unsigned short int const a_thread_pool_size,
    IContextShrPtr     const a_context
)
    : m_thread_pool_size(a_thread_pool_size),
      m_io_service(a_thread_pool_size),
      m_acceptor(m_io_service),
      m_new_connection(new Connection::ConnectionDisposable(m_io_service, m_context)),
      m_served(0),
      m_context(a_context)
{
    boost::asio::ip::tcp::resolver resolver(m_io_service);
    boost::asio::ip::tcp::resolver::query query(a_address, a_port);
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
    m_acceptor.open(endpoint.protocol());
    m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    m_acceptor.bind(endpoint);
    m_acceptor.listen();

    // Start accept asynchronously.
    Category::getInstance("Category").debugStream() << "Starting to accept asynchronously.";

    // TODO: Should start to accept after all the threads (from Server::run()) are running.
    m_acceptor.async_accept(
        m_new_connection->getSocket(),
        boost::bind(
            &Server::handleAccept,
            this,
            boost::asio::placeholders::error
        )
    );
}

void Server::run()
{
    typedef boost::shared_ptr<boost::thread> ThreadShrPtr;

    // Create a pool of threads to be used by the io_service.
    vector<ThreadShrPtr> threads;

    // Start the threads.
    Category::getInstance("Category").debugStream() << "Starting the threads.";

    for (unsigned short int i = 0; i < m_thread_pool_size; ++i)
    {
        Category::getInstance("Category").debugStream() << "Thread #" << i << " started.";
        ThreadShrPtr thread(new boost::thread(boost::bind(&boost::asio::io_service::run, &m_io_service)));
        threads.push_back(thread);
    }

    // Wait for all threads in the pool to exit.
    Category::getInstance("Category").debugStream() << "Waiting for all threads in the pool to exit.";

    for (unsigned short int i = 0; i < threads.size(); ++i)
    {
        threads[i]->join();
        Category::getInstance("Category").debugStream() << "Thread #" << i << " exited.";
    }
}

void Server::stop()
{
    Category::getInstance("Category").debugStream() << "Stopping the server.";

    m_io_service.stop();
}

void Server::handleAccept(
    boost::system::error_code const & a_error
)
{
    m_served++;

    Category::getInstance("Category").debugStream() << "Handling accept #" << m_served << ".";

    if (!a_error)
    {
        m_new_connection->start();
        m_new_connection.reset(new Connection::ConnectionDisposable(m_io_service, m_context));
        m_acceptor.async_accept(
            m_new_connection->getSocket(),
            boost::bind(
                &Server::handleAccept,
                this,
                boost::asio::placeholders::error
            )
        );
    }
}

} // namespace Server
} // namespace XmlRPCServer
} // namespace Network
