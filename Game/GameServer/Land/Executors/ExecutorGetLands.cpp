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
#include <Game/GameServer/Land/Executors/ExecutorGetLands.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorGetLands::ExecutorGetLands(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorGetLands::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorGetLands.";
}

bool ExecutorGetLands::getParameters(
    TUSLanguage::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();

    return true;
}

bool ExecutorGetLands::processParameters()
{
    return true;
}

bool ExecutorGetLands::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorGetLands::epochIsActive(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

bool ExecutorGetLands::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

TUSLanguage::ICommand::Handle ExecutorGetLands::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Land::IGetLandsOperatorShrPtr land_operator = m_operator_abstract_factory->createGetLandsOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Land::GetLandsOperatorExitCode const exit_code =
            land_operator->getLands(transaction, m_user->getLogin());

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

TUSLanguage::ICommand::Handle ExecutorGetLands::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

TUSLanguage::ICommand::Handle ExecutorGetLands::produceReply(
    GameServer::Land::GetLandsOperatorExitCode const & a_exit_code
) const
{
    TUSLanguage::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Land::GET_LANDS_OPERATOR_EXIT_CODE_LANDS_HAVE_BEEN_GOT:
        {
            TUSLanguage::ICommand::Objects lands;

            for (GameServer::Land::ILandMap::const_iterator it = a_exit_code.m_lands.begin();
                 it != a_exit_code.m_lands.end(); ++it)
            {
                // TODO: Translate this automatically!
                TUSLanguage::ICommand::Object land;
                land.insert(std::make_pair("login", it->second->getLogin()));
                land.insert(std::make_pair("world_name", it->second->getWorldName()));
                land.insert(std::make_pair("land_name", it->second->getLandName()));
                std::string granted = it->second->getGranted() ? "true" : "false";
                land.insert(std::make_pair("granted", granted));

                lands.push_back(land);
            }

            return reply_builder.buildGetLandsReply(REPLY_STATUS_OK, GET_LANDS_LANDS_HAVE_BEEN_GOT, lands);
        }

        case GameServer::Land::GET_LANDS_OPERATOR_EXIT_CODE_LANDS_HAVE_NOT_BEEN_GOT:
            return reply_builder.buildGetLandsReply(REPLY_STATUS_OK, GET_LANDS_LANDS_HAVE_NOT_BEEN_GOT);

        case GameServer::Land::GET_LANDS_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildGetLandsReply(REPLY_STATUS_OK, GET_LANDS_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildGetLandsReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
