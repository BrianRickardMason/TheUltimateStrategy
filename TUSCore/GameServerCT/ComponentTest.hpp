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

#ifndef COMPONENTTEST_HPP
#define COMPONENTTEST_HPP

#include "../GameServer/Persistency/PersistencyPostgresql.hpp"
#include <gmock/gmock.h>

/**
 * @brief A base test class.
 */
class ComponentTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    ComponentTest()
    {
        BOOST_ASSERT(resetDatabase());
    }

    /**
     * @brief Destructs the test class.
     */
    virtual ~ComponentTest(){};

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

            transaction->commit();
            return true;
        }
        catch (std::exception const & e)
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

#endif // COMPONENTTEST_HPP
