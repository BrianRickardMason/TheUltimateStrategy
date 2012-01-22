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
#include <Game/GameServer/Settlement/Executors/ExecutorGetSettlement.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorGetSettlement::ExecutorGetSettlement(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorGetSettlement::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorGetSettlement.";
}

bool ExecutorGetSettlement::getParameters(
    Language::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_settlement_name = a_request->getParam("settlement_name");

    return true;
}

bool ExecutorGetSettlement::processParameters()
{
    return true;
}

bool ExecutorGetSettlement::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Authorization::IAuthorizeUserToSettlementOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Authorization::AuthorizeUserToSettlementOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToSettlement(transaction, m_user->getLogin(), m_settlement_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetSettlement::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Epoch::IGetEpochBySettlementNameOperatorShrPtr epoch_operator =
        m_operator_abstract_factory->createGetEpochBySettlementNameOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Epoch::GetEpochBySettlementNameOperatorExitCode const exit_code =
            epoch_operator->getEpochBySettlementName(transaction, m_settlement_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetSettlement::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

Language::ICommand::Handle ExecutorGetSettlement::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Settlement::IGetSettlementOperatorShrPtr settlement_operator =
        m_operator_abstract_factory->createGetSettlementOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Settlement::GetSettlementOperatorExitCode const exit_code =
            settlement_operator->getSettlement(transaction, m_settlement_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

Language::ICommand::Handle ExecutorGetSettlement::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

Language::ICommand::Handle ExecutorGetSettlement::produceReply(
    GameServer::Settlement::GetSettlementOperatorExitCode const & a_exit_code
) const
{
    Language::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Settlement::GET_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_BEEN_GOT:
        {
            // TODO: Translate this automatically!
            Language::ICommand::Object settlement;
            settlement.insert(std::make_pair("land_name", a_exit_code.m_settlement->getLandName()));
            settlement.insert(std::make_pair("settlement_name", a_exit_code.m_settlement->getSettlementName()));
            return reply_builder.buildGetSettlementReply(
                       REPLY_STATUS_OK, GET_SETTLEMENT_SETTLEMENT_HAS_BEEN_GOT, settlement
                   );
        }

        case GameServer::Settlement::GET_SETTLEMENT_OPERATOR_EXIT_CODE_SETTLEMENT_HAS_NOT_BEEN_GOT:
            return reply_builder.buildGetSettlementReply(REPLY_STATUS_OK, GET_SETTLEMENT_SETTLEMENT_HAS_NOT_BEEN_GOT);

        case GameServer::Settlement::GET_SETTLEMENT_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildGetSettlementReply(REPLY_STATUS_OK, GET_SETTLEMENT_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildGetSettlementReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
