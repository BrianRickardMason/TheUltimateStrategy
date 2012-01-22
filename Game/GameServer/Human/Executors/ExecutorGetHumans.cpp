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
#include <Game/GameServer/Human/Executors/ExecutorGetHumans.hpp>
#include <Language/Interface/ReplyBuilder.hpp>
#include <boost/make_shared.hpp>
#include <boost/lexical_cast.hpp>
#include <log4cpp/Category.hh>

using namespace GameServer::Persistence;
using namespace boost;
using namespace log4cpp;
using namespace std;

namespace Game
{

ExecutorGetHumans::ExecutorGetHumans(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorGetHumans::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorGetHumans.";
}

bool ExecutorGetHumans::getParameters(
    Language::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_value_id_holder_class = a_request->getParam("idholderclass");
    m_holder_name = a_request->getParam("holder_name");

    return true;
}

bool ExecutorGetHumans::processParameters()
{
    try
    {
        m_id_holder_class = boost::lexical_cast<unsigned int>(m_value_id_holder_class);

        m_id_holder.assign(m_id_holder_class, m_holder_name);

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorGetHumans::authorize(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Authorization::IAuthorizeUserToHolderOperatorShrPtr authorize_operator =
        m_operator_abstract_factory->createAuthorizeUserToHolderOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Authorization::AuthorizeUserToHolderOperatorExitCode const exit_code =
            authorize_operator->authorizeUserToHolder(transaction, m_user->getLogin(), m_id_holder);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_authorized;
    }
}

bool ExecutorGetHumans::epochIsActive(
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
            epoch_operator->getEpochBySettlementName(transaction, m_holder_name);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return exit_code.m_epoch ? exit_code.m_epoch->getActive() : false;
    }
}

bool ExecutorGetHumans::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

Language::ICommand::Handle ExecutorGetHumans::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Human::IGetHumansOperatorShrPtr dismiss_human_operator =
        m_operator_abstract_factory->createGetHumansOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Human::GetHumansOperatorExitCode const exit_code =
            dismiss_human_operator->getHumans(transaction, m_id_holder);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

Language::ICommand::Handle ExecutorGetHumans::getBasicReply(
    unsigned int const a_status
) const
{
    // FIXME: Remove this method!
    BOOST_ASSERT_MSG(false, "Should never be called!");
}

Language::ICommand::Handle ExecutorGetHumans::produceReply(
    GameServer::Human::GetHumansOperatorExitCode const & a_exit_code
) const
{
    Language::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Human::GET_HUMANS_OPERATOR_EXIT_CODE_HUMANS_HAVE_BEEN_GOT:
        {
            Language::ICommand::Objects humans;

            for (GameServer::Human::HumanWithVolumeMap::const_iterator it = a_exit_code.m_humans.begin();
                 it != a_exit_code.m_humans.end(); ++it)
            {
                // TODO: Translate this automatically!
                Language::ICommand::Object human;
                human.insert(std::make_pair("humanclass", it->second->getHuman()->getClass()));
                human.insert(std::make_pair("humanname", it->second->getHuman()->getName()));
                human.insert(std::make_pair("experience", it->second->getHuman()->getExperience()));
                human.insert(std::make_pair("volume",
                    boost::lexical_cast<std::string>(it->second->getVolume())));
                humans.push_back(human);
            }

            return reply_builder.buildGetHumansReply(REPLY_STATUS_OK, GET_HUMANS_HUMANS_HAVE_BEEN_GOT, humans);
        }

        case GameServer::Human::GET_HUMANS_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildGetHumansReply(REPLY_STATUS_OK, GET_HUMANS_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildGetHumansReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
