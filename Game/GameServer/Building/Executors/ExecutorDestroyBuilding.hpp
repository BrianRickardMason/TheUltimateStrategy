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

#ifndef GAME_EXECUTORDESTROYBUILDING_HPP
#define GAME_EXECUTORDESTROYBUILDING_HPP

#include <Game/GameServer/Common/Executor.hpp>
#include <Game/GameServer/Building/Operators/DestroyBuilding/DestroyBuildingOperatorExitCode.hpp>

namespace Game
{

class ExecutorDestroyBuilding
    : public Executor
{
public:
    ExecutorDestroyBuilding(
        Server::IContextShrPtr const a_context
    );

private:
    virtual void logExecutorStart() const;

    virtual bool getParameters(
        Language::ICommand::Handle a_request
    );

    virtual bool processParameters();

    virtual bool authorize(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    virtual bool epochIsActive(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    virtual bool verifyWorldConfiguration(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    virtual Language::ICommand::Handle perform(
        GameServer::Persistence::IPersistenceShrPtr a_persistence
    ) const;

    virtual Language::ICommand::Handle getBasicReply(
        unsigned int const a_status
    ) const;

    Language::ICommand::Handle produceReply(
        GameServer::Building::DestroyBuildingOperatorExitCode const & a_exit_code
    ) const;

    std::string m_value_id_holder_class;
    std::string m_value_volume;
    std::string m_holder_name;
    std::string m_key;

    unsigned int m_id_holder_class;

    GameServer::Common::IDHolder m_id_holder;
    GameServer::Building::Volume m_volume;
};

} // namespace Game

#endif // GAME_EXECUTORDESTROYBUILDING_HPP
