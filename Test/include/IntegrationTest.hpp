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

#ifndef INTEGRATIONTEST_HPP
#define INTEGRATIONTEST_HPP

#include <Game/GameServer/Persistence/PersistencePostgresql.hpp>
#include <Poco/Process.h>
#include <gtest/gtest.h>

class IntegrationTest
    : public testing::Test
{
protected:
    IntegrationTest()
    {
        BOOST_ASSERT(resetDatabase());

        std::string command("./server");
        Poco::Process::Args args;

        Poco::ProcessHandle processHandle = Poco::Process::launch(command, args);

        mPid = processHandle.id();

        synchronizeServerReady();
    }

    virtual ~IntegrationTest()
    {
        Poco::Process::kill(mPid);
    };

private:
    bool resetDatabase()
    {
        GameServer::Persistence::IConnectionShrPtr connection = mPersistence.getConnection();
        GameServer::Persistence::ITransactionShrPtr transaction = mPersistence.getTransaction(connection);

        GameServer::Persistence::TransactionPostgresqlShrPtr transaction_postgresql =
            boost::shared_dynamic_cast<GameServer::Persistence::TransactionPostgresql>(transaction);
        pqxx::transaction<> & backboneTransaction = transaction_postgresql->getBackboneTransaction();

        try
        {
            // Clean the tables.
            backboneTransaction.exec("DELETE FROM users WHERE moderator = false");
            backboneTransaction.exec("DELETE FROM worlds");
            transaction->commit();
            return true;
        }
        catch (...)
        {
            transaction->abort();
            return false;
        }
    }

    void synchronizeServerReady() const
    {
        // TODO: Make it asynchronous.
        usleep(100000);
    }

protected:
    GameServer::Persistence::PersistencePostgresql mPersistence;

    Poco::ProcessHandle::PID mPid;
};

#endif // INTEGRATIONTEST_HPP
