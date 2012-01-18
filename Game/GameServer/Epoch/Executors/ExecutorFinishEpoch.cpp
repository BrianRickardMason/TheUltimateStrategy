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
#include <Game/GameServer/Epoch/Executors/ExecutorFinishEpoch.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorFinishEpoch::ExecutorFinishEpoch(
    IContextShrPtr a_context
)
    : Executor(a_context)
{
}

void ExecutorFinishEpoch::logExecutorStart() const
{
    Category::getInstance("Category").infoStream() << "Starting the ExecutorFinishEpoch.";
}

bool ExecutorFinishEpoch::getParameters(
    TUSLanguage::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_world_name = a_request->getParam("world_name");

    return true;
}

bool ExecutorFinishEpoch::processParameters()
{
    return true;
}

bool ExecutorFinishEpoch::filterOutNonModerator() const
{
    return m_user->isModerator();
}

bool ExecutorFinishEpoch::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorFinishEpoch::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorFinishEpoch::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

TUSLanguage::ICommand::Handle ExecutorFinishEpoch::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Epoch::IFinishEpochOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createFinishEpochOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Epoch::FinishEpochOperatorExitCode const exit_code =
            epoch_operator->finishEpoch(transaction, m_world_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

TUSLanguage::ICommand::Handle ExecutorFinishEpoch::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

TUSLanguage::ICommand::Handle ExecutorFinishEpoch::produceReply(
    GameServer::Epoch::FinishEpochOperatorExitCode const & a_exit_code
) const
{
    TUSLanguage::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_DOES_NOT_EXIST:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_EPOCH_DOES_NOT_EXIST);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK,
                       FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_FINISHED:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_EPOCH_HAS_NOT_BEEN_FINISHED);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_EPOCH_IS_ACTIVE:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_EPOCH_IS_ACTIVE);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_UNEXPECTED_ERROR);

        case GameServer::Epoch::FINISH_EPOCH_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST:
            return reply_builder.buildFinishEpochReply(REPLY_STATUS_OK, FINISH_EPOCH_WORLD_DOES_NOT_EXIST);

        default:
            return reply_builder.buildActivateEpochReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game