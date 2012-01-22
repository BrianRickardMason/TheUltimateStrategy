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
#include <Game/GameServer/Land/Executors/ExecutorCreateLand.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorCreateLand::ExecutorCreateLand(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorCreateLand::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorCreateLand.";
}

bool ExecutorCreateLand::getParameters(
    Language::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_world_name = a_request->getParam("world_name");
    m_land_name = a_request->getParam("land_name");

    return true;
}

bool ExecutorCreateLand::processParameters()
{
    return true;
}

bool ExecutorCreateLand::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorCreateLand::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Epoch::IGetEpochByWorldNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochByWorldNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Epoch::GetEpochByWorldNameOperatorExitCode const exit_code =
            epoch_operator->getEpochByWorldName(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorCreateLand::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

Language::ICommand::Handle ExecutorCreateLand::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Land::ICreateLandOperatorShrPtr land_operator = m_operator_abstract_factory->createCreateLandOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Land::CreateLandOperatorExitCode const exit_code =
            land_operator->createLand(transaction, m_user->getLogin(), m_world_name, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

Language::ICommand::Handle ExecutorCreateLand::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

Language::ICommand::Handle ExecutorCreateLand::produceReply(
    GameServer::Land::CreateLandOperatorExitCode const & a_exit_code
) const
{
    Language::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Land::CREATE_LAND_OPERATOR_EXIT_CODE_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK, CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS);

        case GameServer::Land::CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_CREATED:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK, CREATE_LAND_LAND_HAS_BEEN_CREATED);

        case GameServer::Land::CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_CREATED:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK, CREATE_LAND_LAND_HAS_NOT_BEEN_CREATED);

        case GameServer::Land::CREATE_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK, CREATE_LAND_UNEXPECTED_ERROR);

        case GameServer::Land::CREATE_LAND_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK, CREATE_LAND_WORLD_DOES_NOT_EXIST);

        default:
            return reply_builder.buildCreateLandReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
