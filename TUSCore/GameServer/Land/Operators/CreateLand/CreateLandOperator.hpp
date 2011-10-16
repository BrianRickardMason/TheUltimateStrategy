// Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
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

#ifndef GAMESERVER_LAND_CREATELANDOPERATOR_HPP
#define GAMESERVER_LAND_CREATELANDOPERATOR_HPP

#include "../../../User/IUserManager.hpp"
#include "../../../World/IWorldManager.hpp"
#include "../../ILandManager.hpp"
#include "ICreateLandOperator.hpp"

namespace GameServer
{
namespace Land
{

/**
 * @brief CreateLandOperator.
 */
class CreateLandOperator
    : public ICreateLandOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_land_manager  The manager of lands.
     * @param a_user_manager  The manager of users.
     * @param a_world_manager The manager of worlds.
     */
    CreateLandOperator(
        ILandManagerShrPtr         a_land_manager,
        User::IUserManagerShrPtr   a_user_manager,
        World::IWorldManagerShrPtr a_world_manager
    );

    /**
     * @brief Creates a land.
     *
     * @param a_transaction The transaction.
     * @param a_login       The login of the user.
     * @param a_world_name  The name of the world.
     * @param a_land_name   The name of the land.
     *
     * @return The exit code.
     */
    virtual CreateLandOperatorExitCode createLand(
        Persistence::ITransactionShrPtr       a_transaction,
        std::string                     const a_login,
        std::string                     const a_world_name,
        std::string                     const a_land_name
    ) const;

private:
    /**
     * @brief The manager of lands.
     */
    ILandManagerShrPtr m_land_manager;

    /**
     * @brief The manager of users.
     */
    User::IUserManagerShrPtr m_user_manager;

    /**
     * @brief The manager of worlds.
     */
    World::IWorldManagerShrPtr m_world_manager;
};

/**
 * @brief The auto pointer of CreateLandOperator.
 */
typedef std::auto_ptr<CreateLandOperator> CreateLandOperatorAutPtr;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_CREATELANDOPERATOR_HPP
