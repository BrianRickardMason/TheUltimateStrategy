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

#include <Game/GameServer/Land/Operators/CreateLand/CreateLandOperator.hpp>

using namespace GameServer::Persistence;
using namespace GameServer::User;
using namespace GameServer::World;
using namespace std;

namespace GameServer
{
namespace Land
{

CreateLandOperator::CreateLandOperator(
    ILandPersistenceFacadeShrPtr  a_land_persistence_facade,
    IUserPersistenceFacadeShrPtr  a_user_persistence_facade,
    IWorldPersistenceFacadeShrPtr a_world_persistence_facade
)
    : m_land_persistence_facade(a_land_persistence_facade),
      m_user_persistence_facade(a_user_persistence_facade),
      m_world_persistence_facade(a_world_persistence_facade)
{
}

CreateLandOperatorExitCode CreateLandOperator::createLand(
    ITransactionShrPtr       a_transaction,
    string             const a_login,
    string             const a_world_name,
    string             const a_land_name
) const
{
    try
    {
        // Verify if the user exists.
        // TODO: UserPersistenceFacade::getUser.

        // Verify if the world exists.
        if (!m_world_persistence_facade->getWorld(a_transaction, a_world_name))
        {
            return CreateLandOperatorExitCode(CREATE_LAND_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST);
        }

        // Verify if another land of the given name exists.
        if (m_land_persistence_facade->getLand(a_transaction, a_land_name))
        {
            return CreateLandOperatorExitCode(CREATE_LAND_OPERATOR_EXIT_CODE_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS);
        }

        bool const result = m_land_persistence_facade->createLand(a_transaction, a_login, a_world_name, a_land_name);

        return (result) ? CreateLandOperatorExitCode(CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_CREATED)
                        : CreateLandOperatorExitCode(CREATE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_CREATED);
    }
    catch (...)
    {
        return CreateLandOperatorExitCode(CREATE_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

} // namespace Land
} // namespace GameServer
