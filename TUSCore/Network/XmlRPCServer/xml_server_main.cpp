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

#include <Network/XmlRPCServer/Configurator.hpp>
#include <Network/XmlRPCServer/Server/Server.hpp>
#include <Network/XmlRPCServer/Context.hpp>
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
 * @brief The server itself.
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
        // Default values of properties.
        string             host        = "localhost";
        string             port        = "2222";
        unsigned short int threads     = 1;
        int                priority    = Priority::ALERT;
        string             persistence = "postgresql";

        // Try to get the properties from the command line.
        if (argc > 1)
        {
            // Check command line arguments.
            if (argc != 4)
            {
                cerr << "Usage with parameters: server <host> <port> <threads>" << endl;
                cerr << "  For IPv4, try:" << endl;
                cerr << "    XmlRPCServer 0.0.0.0 2222 1" << endl;
                cerr << "  For IPv6, try:" << endl;
                cerr << "    XmlRPCServer 0::0 2222 1" << endl;
                return 1;
            }

            // Get the properties.
            host     = argv[1];
            port     = argv[2];
            threads  = lexical_cast<unsigned short int>(argv[3]);
        }
        // Try to get the properties from the configuration file.
        else
        {
            // Get the properties.
            host        = CONFIGURATOR.getHost();
            port        = CONFIGURATOR.getPort();
            threads     = CONFIGURATOR.getThreads();
            priority    = CONFIGURATOR.getLoggerPriority();
            persistence = CONFIGURATOR.getPersistence();
        }

        // Set up Appender, Layout and Category.
        Appender * appender = new OstreamAppender("OstreamAppender", &cout);
        PatternLayout * layout = new log4cpp::PatternLayout();
        layout->setConversionPattern("[%p\t][%d{%Y-%d-%m %H:%M:%S,%l}][%r] - %m%n");
        Category & category = Category::getInstance("Category");
        appender->setLayout(layout);
        category.setAppender(appender);
        category.setPriority(priority);

        // Create the context.
        IContextShrPtr context(new Context(host, port, threads, priority, persistence));

        // Run the server in a background thread.
        Server server(host, port, threads, context);
        thread thread_1(bind(&Server::run, &server));

        // Stop the server.
        thread_1.join();
        server.stop();
    }
    catch (std::exception & e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "This should never happen." << endl;
    }

    return 0;
}
