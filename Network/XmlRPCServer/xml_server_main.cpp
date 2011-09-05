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

#include "Server/Server.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace Network::XmlRPCServer::Server;
using namespace boost;
using namespace log4cpp;
using namespace std;

/**
 * @brief A main entry to the XmlRPCServer.
 *
 * TODO: Review the way io_services are being run (I'd rather go for synchronous calls).
 * FIXME: Handle the incoming requests if there are not enough "executors" (queueing, denying, dropping).
 */
int main(
    int    argc,
    char * argv[]
)
{
    try
    {
        // Check command line arguments.
        if (argc != 4)
        {
            cerr << "Usage: XmlRPCServer <address> <port> <threads>\n";
            cerr << "  For IPv4, try:\n";
            cerr << "    XmlRPCServer 0.0.0.0 2222 1\n";
            cerr << "  For IPv6, try:\n";
            cerr << "    XmlRPCServer 0::0 2222 1\n";
            return 1;
        }

        // Setting up Appender, Layout and Category.
        Appender * appender = new OstreamAppender("OstreamAppender", &cout);
        PatternLayout * layout = new log4cpp::PatternLayout();
        layout->setConversionPattern("[%p\t][%d{%Y-%d-%m %H:%M:%S,%l}][%r] - %m%n");
        Category & category = Category::getInstance("Category");

        appender->setLayout(layout);
        category.setAppender(appender);
        category.setPriority(Priority::ALERT);

        // Run server in background thread.
        size_t num_threads = lexical_cast<size_t>(argv[3]);
        Server server(argv[1], argv[2], num_threads);
        thread thread_1(bind(&Server::run, &server));

        // Stop the server.
        thread_1.join();
        server.stop();
    }
    catch (std::exception &e)
    {
        Category::getInstance("Category").errorStream() << "Exception: " << e.what();
    }

    return 0;
}
