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
#include <Game/GameServer/Building/Executors/ExecutorDestroyBuilding.hpp>
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

ExecutorDestroyBuilding::ExecutorDestroyBuilding(
    Server::IContextShrPtr const a_context
)
    : Executor(a_context)
{
}

void ExecutorDestroyBuilding::logExecutorStart() const
{
// TODO: Replace with Poco::Logger. Category::getInstance("Category").infoStream() << "Starting the ExecutorDestroyBuilding.";
}

bool ExecutorDestroyBuilding::getParameters(
    Language::ICommand::Handle a_request
)
{
    m_login = a_request->getLogin();
    m_password = a_request->getPassword();
    m_value_id_holder_class = a_request->getParam("idholderclass");
    m_holder_name = a_request->getParam("holder_name");
    m_key = a_request->getParam("buildingkey");
    m_value_volume = a_request->getParam("volume");

    return true;
}

bool ExecutorDestroyBuilding::processParameters()
{
    try
    {
        m_id_holder_class = boost::lexical_cast<unsigned int>(m_value_id_holder_class);
        m_volume = boost::lexical_cast<unsigned int>(m_volume);

        m_id_holder.assign(m_id_holder_class, m_holder_name);

        return true;
    }
    catch (std::range_error)
    {
        return false;
    }
}

bool ExecutorDestroyBuilding::authorize(
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

bool ExecutorDestroyBuilding::epochIsActive(
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

bool ExecutorDestroyBuilding::verifyWorldConfiguration(
    IPersistenceShrPtr a_persistence
) const
{
    return true;
}

Language::ICommand::Handle ExecutorDestroyBuilding::perform(
    IPersistenceShrPtr a_persistence
) const
{
    GameServer::Building::IDestroyBuildingOperatorShrPtr destroy_building_operator =
        m_operator_abstract_factory->createDestroyBuildingOperator();

    // The transaction lifetime.
    {
        IConnectionShrPtr connection = a_persistence->getConnection();
        ITransactionShrPtr transaction = a_persistence->getTransaction(connection);

        GameServer::Building::DestroyBuildingOperatorExitCode const exit_code =
            destroy_building_operator->destroyBuilding(transaction, m_id_holder, m_key, m_volume);

        if (exit_code.ok())
        {
            transaction->commit();
        }

        return produceReply(exit_code);
    }
}

Language::ICommand::Handle ExecutorDestroyBuilding::getBasicReply(
    unsigned int const a_status
) const
{
    Language::ReplyBuilder reply_builder;

    return reply_builder.buildDestroyBuildingReply(a_status);
}

Language::ICommand::Handle ExecutorDestroyBuilding::produceReply(
    GameServer::Building::DestroyBuildingOperatorExitCode const & a_exit_code
) const
{
    Language::ReplyBuilder reply_builder;

    switch (a_exit_code.m_exit_code)
    {
        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDINGS_MISSING_IN_THE_MEANTIME:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK,
                       DESTROY_BUILDING_BUILDINGS_MISSING_IN_THE_MEANTIME);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK,
                       DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK, DESTROY_BUILDING_NOT_ENOUGH_BUILDINGS);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK, DESTROY_BUILDING_NOT_ENOUGH_RESOURCES);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK, DESTROY_BUILDING_NOT_ENOUGH_RESOURCES);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK, DESTROY_BUILDING_THERE_ARE_NO_BUILDINGS);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK,
                       DESTROY_BUILDING_TRYING_TO_DESTROY_ZERO_BUILDINGS);

        case GameServer::Building::DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR:
            return reply_builder.buildDestroyBuildingReply(REPLY_STATUS_OK, DESTROY_BUILDING_UNEXPECTED_ERROR);

        default:
            return reply_builder.buildBuildBuildingReply(REPLY_STATUS_OK,
                       METAMESSAGE_EVEN_MORE_UNEXPECTED_ERROR_UNKNOWN_EXIT_CODE);
    }
}

} // namespace Game
