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

#ifndef INTEGRATIONSTRESSTEST_HPP
#define INTEGRATIONSTRESSTEST_HPP

#include "../../GameServer/Persistency/PersistencyPostgresql.hpp"
#include <Poco/Process.h>
#include <boost/assign/list_of.hpp>
#include <boost/thread.hpp>
#include <gmock/gmock.h>

/**
 * @brief A base test class.
 */
class IntegrationStressTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    IntegrationStressTest()
    {
        BOOST_ASSERT(resetDatabase());
    }

    /**
     * @brief Runs a parametrized test.
     *
     * @param a_number_of_server_threads The number of server's threads.
     * @param a_number_of_client_threads The number of client's threads.
     * @param a_thread_iterations        The number of iterations the thread will run.
     * @param a_function                 The function to be passed to the thread.
     */
    void runTest(
        unsigned short int const                                                  a_number_of_server_threads,
        unsigned short int const                                                  a_number_of_client_threads,
        unsigned short int const                                                  a_thread_iterations,
        boost::function<void(unsigned short int const, unsigned short int const)> a_function
    )
    {
        char number_of_server_threads[10];

        BOOST_ASSERT(sprintf(number_of_server_threads, "%d", a_number_of_server_threads) > 0);

        std::string command("../../../../Network/bin/gcc-4.5.2/debug/XmlRPCServer");
        Poco::Process::Args args = boost::assign::list_of("localhost")("2222")(number_of_server_threads);
        Poco::ProcessHandle process_handle = Poco::Process::launch(command, args);
        Poco::ProcessHandle::PID server_pid = process_handle.id();

        synchronizeServerReady();

        typedef boost::shared_ptr<boost::thread> ThreadShrPtr;

        std::vector<ThreadShrPtr> threads;

        // TODO: Use thread group.

        for (unsigned short int i = 0; i < a_number_of_client_threads; ++i)
        {
            ThreadShrPtr thread(new boost::thread(bind(a_function, i, a_thread_iterations)));
            threads.push_back(thread);
        }

        for (unsigned short int i = 0; i < threads.size(); ++i)
        {
            threads[i]->join(); // TODO: Try detach.
        }

        Poco::Process::kill(server_pid);
    }

    /**
     * @brief Synchronize with the server.
     */
    void synchronizeServerReady() const
    {
        // TODO: This have to be asynchronous (triggering).
        usleep(50000);
    }

private:
    /**
     * @brief Sets up a new database.
     *
     * @return True on success, false otherwise.
     */
    bool resetDatabase()
    {
        GameServer::Persistency::IConnectionShrPtr connection = m_persistency.getConnection();
        GameServer::Persistency::ITransactionShrPtr transaction = m_persistency.getTransaction(connection);

        GameServer::Persistency::TransactionPostgresqlShrPtr transaction_postgresql =
            boost::shared_dynamic_cast<GameServer::Persistency::TransactionPostgresql>(transaction);
        pqxx::transaction<> & backbone_transaction = transaction_postgresql->getBackboneTransaction();

        try
        {
            // Clean tables.
            backbone_transaction.exec("DELETE FROM users");
            backbone_transaction.exec("DELETE FROM worlds");

            // Reset sequences.
            backbone_transaction.exec("ALTER SEQUENCE epochs_id_epoch_seq MINVALUE 0 RESTART WITH 1");

            // FIXME: Temporary workaround until ExecutorCreateUser is available.
            backbone_transaction.exec("INSERT INTO users(login, password) VALUES('Login1', 'Password1')");
            backbone_transaction.exec("INSERT INTO users(login, password) VALUES('Login2', 'Password2')");
            backbone_transaction.exec("INSERT INTO users(login, password) VALUES('Login3', 'Password3')");

            // FIXME: Temporary workaround until ExecutorCreateWorld is available.
            backbone_transaction.exec("INSERT INTO worlds(world_name) VALUES('World1')");
            backbone_transaction.exec("INSERT INTO worlds(world_name) VALUES('World2')");
            backbone_transaction.exec("INSERT INTO worlds(world_name) VALUES('World3')");

            // TODO: Improve it (call the ExecutoCreateEpoch instead).
            backbone_transaction.exec("INSERT INTO epochs(world_name) VALUES('World1')");
            backbone_transaction.exec("INSERT INTO epochs(world_name) VALUES('World2')");
            backbone_transaction.exec("INSERT INTO epochs(world_name) VALUES('World3')");

             // TODO: Improve it (call the ExecutoActivateEpoch instead).
            backbone_transaction.exec("UPDATE epochs set active = true WHERE world_name = 'World1'");
            backbone_transaction.exec("UPDATE epochs set active = true WHERE world_name = 'World2'");
            backbone_transaction.exec("UPDATE epochs set active = true WHERE world_name = 'World3'");

            transaction->commit();
            return true;
        }
        catch (std::exception const &)
        {
            transaction->abort();
            return false;
        }
    }

protected:
    /**
     * @brief A persistency.
     */
    GameServer::Persistency::PersistencyPostgresql m_persistency;
};

#endif // INTEGRATIONSTRESSTEST_HPP
