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

#ifndef GAMESERVER_PERSISTENCE_TRANSACTIONPOSTGRESQL_HPP
#define GAMESERVER_PERSISTENCE_TRANSACTIONPOSTGRESQL_HPP

#include "ITransaction.hpp"
#include <pqxx/connection.hxx>
#include <pqxx/transaction.hxx>

namespace GameServer
{
namespace Persistence
{

/**
 * @brief The PostgreSQL transaction.
 */
class TransactionPostgresql
    : public ITransaction
{
public:
    /**
     * @brief Constructs the transaction.
     *
     * @param a_connection The connection that transaction bases upon.
     */
    explicit TransactionPostgresql(
        pqxx::connection & a_connection
    );

    /**
     * @brief Commits the transaction.
     */
    virtual void commit();

    /**
     * @brief Aborts the transaction.
     */
    virtual void abort();

    /**
     * @brief Gets the backbone transaction.
     *
     * @return The backbone transaction.
     */
    pqxx::transaction<> & getBackboneTransaction();

private:
    /**
     * @brief The backbone transaction.
     */
    pqxx::transaction<> m_backbone_transaction;
};

/**
 * @brief The shared pointer of the PostgreSQL transaction.
 */
typedef boost::shared_ptr<TransactionPostgresql> TransactionPostgresqlShrPtr;

} // namespace Persistence
} // namespace GameServer

#endif // GAMESERVER_PERSISTENCE_TRANSACTIONPOSTGRESQL_HPP
