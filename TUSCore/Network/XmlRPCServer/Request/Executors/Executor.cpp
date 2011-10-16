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

#include "../../../../GameServer/Common/OperatorAbstractFactoryPostgresql.hpp"
#include "../../../../GameServer/Persistence/PersistencePostgresql.hpp"
#include "Executor.hpp"

using namespace GameServer::Authentication;
using namespace GameServer::Common;
using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace Network::XmlRPCCommon::Reply;
using namespace Network::XmlRPCCommon::Request;
using namespace Network::XmlRPCCommon::Xml;

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

// TODO: Remove hardcoded persistence.
// TODO: Remove hardcoded operator factory.
Executor::Executor()
    : m_persistence(new PersistencePostgresql),
      m_operator_abstract_factory(new OperatorAbstractFactoryPostgresql)
{
}

ReplyShrPtr Executor::execute(
    RequestShrPtr a_request
)
{
    logExecutorStart();

    if (!serverIsListening())
    {
        return produceReplyServerIsNotListening();
    }

    if (!getParameters(a_request))
    {
        return produceReplyInvalidRequest();
    }

    if (!processParameters())
    {
        return produceReplyInvalidRange();
    }

    if (!authenticate(m_persistence))
    {
        return produceReplyUnauthenticated();
    }

    if (!getActingUser(m_persistence))
    {
        return produceReplyActingUserHasNotBeenGot();
    }

    if (!authorize(m_persistence))
    {
        return produceReplyUnauthorized();
    }

    if (!epochIsActive(m_persistence))
    {
        return produceReplyEpochIsNotActive();
    }

    if (!verifyWorldConfiguration(m_persistence))
    {
        return produceReplyActionUnavailable();
    }

    return perform(m_persistence);
}

bool Executor::serverIsListening() const
{
    return true;
}

bool Executor::authenticate(
    IPersistenceShrPtr a_persistence
) const
{
    IAuthenticateOperatorShrPtr authenticate_operator = m_operator_abstract_factory->createAuthenticateOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        AuthenticateOperatorExitCode const exit_code =
            authenticate_operator->authenticate(transaction, m_login, m_password);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authenticated;
    }
}

bool Executor::getActingUser(
    IPersistenceShrPtr a_persistence
)
{
    IGetUserOperatorShrPtr get_user_operator = m_operator_abstract_factory->createGetUserOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GetUserOperatorExitCode const exit_code = get_user_operator->getUser(transaction, m_login);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        if (!exit_code.m_user)
        {
            return false;
        }
        else
        {
            m_user = exit_code.m_user;

            return true;
        }
    }
}

ReplyShrPtr Executor::produceReplyServerIsNotListening() const
{
    return getBasicReply(REPLY_STATUS_SERVER_IS_NOT_LISTENING);
}

ReplyShrPtr Executor::produceReplyInvalidRequest() const
{
    return getBasicReply(REPLY_STATUS_INVALID_REQUEST);
}

ReplyShrPtr Executor::produceReplyInvalidRange() const
{
    return getBasicReply(REPLY_STATUS_INVALID_RANGE);
}

ReplyShrPtr Executor::produceReplyUnauthenticated() const
{
    return getBasicReply(REPLY_STATUS_UNAUTHENTICATED);
}

ReplyShrPtr Executor::produceReplyActingUserHasNotBeenGot() const
{
    return getBasicReply(REPLY_STATUS_ACTING_USER_HAS_NOT_BEEN_GOT);
}

ReplyShrPtr Executor::produceReplyUnauthorized() const
{
    return getBasicReply(REPLY_STATUS_UNAUTHORIZED);
}

ReplyShrPtr Executor::produceReplyEpochIsNotActive() const
{
    return getBasicReply(REPLY_STATUS_EPOCH_IS_NOT_ACTIVE);
}

ReplyShrPtr Executor::produceReplyActionUnavailable() const
{
    return getBasicReply(REPLY_STATUS_ACTION_UNAVAILABLE);
}

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network
