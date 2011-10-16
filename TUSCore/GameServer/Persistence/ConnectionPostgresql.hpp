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

#ifndef GAMESERVER_PERSISTENCE_CONNECTIONPOSTGRESQL_HPP
#define GAMESERVER_PERSISTENCE_CONNECTIONPOSTGRESQL_HPP

#include "IConnection.hpp"
#include <pqxx/connection.hxx>

namespace GameServer
{
namespace Persistence
{

/**
 * @brief The PostgreSQL connection.
 */
class ConnectionPostgresql
    : public IConnection
{
public:
    /**
     * @brief Constructs the connection.
     */
    ConnectionPostgresql();

    /**
     * @brief Gets the backbone connection.
     *
     * @return The backbone connection.
     */
    pqxx::connection & getBackboneConnection();

private:
    /**
     * @brief The backbone connection.
     */
    pqxx::connection m_backbone_connection;
};

/**
 * @brief The shared pointer of the PostgreSQL connection.
 */
typedef boost::shared_ptr<ConnectionPostgresql> ConnectionPostgresqlShrPtr;

} // namespace Persistence
} // namespace GameServer

#endif // GAMESERVER_PERSISTENCE_CONNECTIONPOSTGRESQL_HPP
