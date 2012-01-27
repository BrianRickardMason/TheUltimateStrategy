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

#include <Game/GameServer/Common/Constants.hpp>
#include <Game/GameServer/Land/Executors/ExecutorDeleteLand.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorDeleteLand::ExecutorDeleteLand(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorDeleteLand::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorDeleteLand.";
}

bool ExecutorDeleteLand::getParameters(
    Language::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_land_name = a_request->getParam("land_name");

    return true;
}

bool ExecutorDeleteLand::processParameters()
{
    return true;
}

bool ExecutorDeleteLand::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Authorization::IAuthorizeUserToLandOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Authorization::AuthorizeUserToLandOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToLand(transaction, m_user->getLogin(), m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorDeleteLand::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Epoch::IGetEpochByLandNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochByLandNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Epoch::GetEpochByLandNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByLandName(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorDeleteLand::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

Language::ICommand::Handle ExecutorDeleteLand::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Land::IDeleteLandOperatorShrPtr land_operator = m_operator_abstract_factory->createDeleteLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Land::DeleteLandOperatorExitCode const exit_code =
            land_operator->deleteLand(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

Language::ICommand::Handle ExecutorDeleteLand::getBasicReply(
    unsigned int const a_status
) const
{
    Language::ReplyBuilder reply_builder;

    return reply_builder.buildDeleteLandReply(a_status);
}

Language::ICommand::Handle ExecutorDeleteLand::produceReply(
    GameServer::Land::DeleteLandOperatorExitCode const & a_exit_code
) const
{
    Language::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Land::DELETE_LAND_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST:
            return reply_builder.buildDeleteLandReply(REPLY_STATUS_OK, DELETE_LAND_LAND_DOES_NOT_EXIST);

        case GameServer::Land::DELETE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_DELETED:
            return reply_builder.buildDeleteLandReply(REPLY_STATUS_OK, DELETE_LAND_LAND_HAS_BEEN_DELETED);

        case GameServer::Land::DELETE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_DELETED:
            return reply_builder.buildDeleteLandReply(REPLY_STATUS_OK, DELETE_LAND_LAND_HAS_NOT_BEEN_DELETED);

        case GameServer::Land::DELETE_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildDeleteLandReply(REPLY_STATUS_OK, DELETE_LAND_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildDeleteLandReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
