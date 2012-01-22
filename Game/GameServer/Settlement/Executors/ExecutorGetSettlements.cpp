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
#include <Game/GameServer/Settlement/Executors/ExecutorGetSettlements.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorGetSettlements::ExecutorGetSettlements(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorGetSettlements::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorGetSettlements.";
}

bool ExecutorGetSettlements::getParameters(
    TUSLanguage::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_land_name = a_request->getParam("land_name");

    return true;
}

bool ExecutorGetSettlements::processParameters()
{
    return true;
}

bool ExecutorGetSettlements::authorize(
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

bool ExecutorGetSettlements::epochIsActive(
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

bool ExecutorGetSettlements::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

TUSLanguage::ICommand::Handle ExecutorGetSettlements::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Settlement::IGetSettlementsOperatorShrPtr settlement_operator =
        m_operator_abstract_factory->createGetSettlementsOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Settlement::GetSettlementsOperatorExitCode const exit_code =
            settlement_operator->getSettlements(transaction, m_land_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

TUSLanguage::ICommand::Handle ExecutorGetSettlements::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

TUSLanguage::ICommand::Handle ExecutorGetSettlements::produceReply(
    GameServer::Settlement::GetSettlementsOperatorExitCode const & a_exit_code
) const
{
    TUSLanguage::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Settlement::GET_SETTLEMENTS_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST:
            return reply_builder.buildGetSettlementsReply(REPLY_STATUS_OK,
                       GET_SETTLEMENTS_BY_LANDNAME_LAND_DOES_NOT_EXIST);

        case GameServer::Settlement::GET_SETTLEMENTS_OPERATOR_EXIT_CODE_SETTLEMENTS_HAVE_BEEN_GOT:
        {
            TUSLanguage::ICommand::Objects settlements;

            for (GameServer::Settlement::ISettlementMap::const_iterator it = a_exit_code.m_settlements.begin();
                 it != a_exit_code.m_settlements.end(); ++it)
            {
                // TODO: Translate this automatically!
                TUSLanguage::ICommand::Object settlement;
                settlement.insert(std::make_pair("land_name", it->second->getLandName()));
                settlement.insert(std::make_pair("settlement_name", it->second->getSettlementName()));
                settlements.push_back(settlement);
            }

            return reply_builder.buildGetSettlementsReply(REPLY_STATUS_OK,
                       GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_BEEN_GOT, settlements);
        }

        case GameServer::Settlement::GET_SETTLEMENTS_OPERATOR_EXIT_CODE_SETTLEMENTS_HAVE_NOT_BEEN_GOT:
            return reply_builder.buildGetSettlementsReply(REPLY_STATUS_OK,
                       GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_NOT_BEEN_GOT);

        case GameServer::Settlement::GET_SETTLEMENTS_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildGetSettlementsReply(REPLY_STATUS_OK,
                       GET_SETTLEMENTS_BY_LANDNAME_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildGetSettlementsReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
