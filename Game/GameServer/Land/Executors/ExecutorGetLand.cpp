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
#include <Game/GameServer/Land/Executors/ExecutorGetLand.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorGetLand::ExecutorGetLand(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorGetLand::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorGetLand.";
}

bool ExecutorGetLand::getParameters(
    TUSLanguage::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_land_name = a_request->getParam("land_name");

    return true;
}

bool ExecutorGetLand::processParameters()
{
    return true;
}

bool ExecutorGetLand::authorize(
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

bool ExecutorGetLand::epochIsActive(
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

bool ExecutorGetLand::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

TUSLanguage::ICommand::Handle ExecutorGetLand::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Land::IGetLandOperatorShrPtr land_operator = m_operator_abstract_factory->createGetLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Land::GetLandOperatorExitCode const exit_code = land_operator->getLand(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

TUSLanguage::ICommand::Handle ExecutorGetLand::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

TUSLanguage::ICommand::Handle ExecutorGetLand::produceReply(
    GameServer::Land::GetLandOperatorExitCode const & a_exit_code
) const
{
    TUSLanguage::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Land::GET_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_GOT:
        {
            // TODO: Translate this automatically!
            TUSLanguage::ICommand::Object land;
            land.insert(std::make_pair("login", a_exit_code.m_land->getLogin()));
            land.insert(std::make_pair("world_name", a_exit_code.m_land->getWorldName()));
            land.insert(std::make_pair("land_name", a_exit_code.m_land->getLandName()));
            std::string granted = a_exit_code.m_land->getGranted() ? "true" : "false";
            land.insert(std::make_pair("granted", granted));
            return reply_builder.buildGetLandReply(REPLY_STATUS_OK, DELETE_LAND_LAND_DOES_NOT_EXIST, land);
        }

        case GameServer::Land::GET_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_GOT:
            return reply_builder.buildGetLandReply(REPLY_STATUS_OK, DELETE_LAND_LAND_HAS_BEEN_DELETED);

        case GameServer::Land::GET_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildGetLandReply(REPLY_STATUS_OK, GET_LAND_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildGetLandReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
