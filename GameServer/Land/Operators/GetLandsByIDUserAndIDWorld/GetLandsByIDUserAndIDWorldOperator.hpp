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

#ifndef GAMESERVER_LAND_GETLANDSBYIDUSERANDIDWORLDOPERATOR_HPP
#define GAMESERVER_LAND_GETLANDSBYIDUSERANDIDWORLDOPERATOR_HPP

#include "../../../User/IUserManager.hpp"
#include "../../../World/IWorldManager.hpp"
#include "../../ILandManager.hpp"
#include "IGetLandsByIDUserAndIDWorldOperator.hpp"

namespace GameServer
{
namespace Land
{

/**
 * @brief GetLandsByIDUserAndIDWorldOperator.
 */
class GetLandsByIDUserAndIDWorldOperator
    : public IGetLandsByIDUserAndIDWorldOperator
{
public:
    /**
     * @brief Constructs the operator.
     *
     * @param a_land_manager  The manager of lands.
     * @param a_user_manager  The manager of users.
     * @param a_world_manager The manager of worlds.
     */
    GetLandsByIDUserAndIDWorldOperator(
        ILandManagerShrPtr         a_land_manager,
        User::IUserManagerShrPtr   a_user_manager,
        World::IWorldManagerShrPtr a_world_manager
    );

    /**
     * @brief Gets lands.
     *
     * @param a_transaction The transaction.
     * @param a_id_user     The identifier of the user.
     * @param a_id_world    The identifier of the world.
     *
     * @return The exit code.
     */
    virtual GetLandsByIDUserAndIDWorldOperatorExitCode getLandByIDUserAndIDWorld(
        Persistency::ITransactionShrPtr         a_transaction,
        User::IDUser                    const & a_id_user,
        World::IDWorld                  const & a_id_world
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
 * @brief The auto pointer of GetLandsByIDUserAndIDWorldOperator.
 */
typedef std::auto_ptr<GetLandsByIDUserAndIDWorldOperator> GetLandsByIDUserAndIDWorldOperatorAutPtr;

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_GETLANDSBYIDUSERANDIDWORLDOPERATOR_HPP
