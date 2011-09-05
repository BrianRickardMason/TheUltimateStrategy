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

#ifndef GAMESERVER_COMMON_MANAGERABSTRACTFACTORYPOSTGRESQL_HPP
#define GAMESERVER_COMMON_MANAGERABSTRACTFACTORYPOSTGRESQL_HPP

#include "IAccessorAbstractFactory.hpp"
#include "IManagerAbstractFactory.hpp"

namespace GameServer
{
namespace Common
{

/**
 * @brief The PostgreSQL ManagerAbstractFactory.
 */
class ManagerAbstractFactoryPostgresql
    : public IManagerAbstractFactory
{
public:
    /**
     * @brief Constructs the PostgreSQL ManagerAbstractFactory.
     */
    ManagerAbstractFactoryPostgresql();

    /**
     * @brief Creates the authentication manager.
     *
     * @return The newly created authentication manager.
     */
    virtual Authentication::IAuthenticationManagerShrPtr createAuthenticationManager() const;

    /**
     * @brief Creates the authorization manager.
     *
     * @return The newly created authorization manager.
     */
    virtual Authorization::IAuthorizationManagerShrPtr createAuthorizationManager() const;

    /**
     * @brief Creates the building manager.
     *
     * @return The newly created building manager.
     */
    virtual Building::IBuildingManagerShrPtr createBuildingManager() const;

    /**
     * @brief Creates the cost manager.
     *
     * @return The newly created cost manager.
     */
    virtual Cost::ICostManagerShrPtr createCostManager() const;

    /**
     * @brief Creates the epoch manager.
     *
     * @return The newly created epoch manager.
     */
    virtual Epoch::IEpochManagerShrPtr createEpochManager() const;

    /**
     * @brief Creates the human manager.
     *
     * @return The newly created human manager.
     */
    virtual Human::IHumanManagerShrPtr createHumanManager() const;

    /**
     * @brief Creates the land manager.
     *
     * @return The newly created land manager.
     */
    virtual Land::ILandManagerShrPtr createLandManager() const;

    /**
     * @brief Creates the property manager.
     *
     * @return The newly created property manager.
     */
    virtual Property::IPropertyManagerShrPtr createPropertyManager() const;

    /**
     * @brief Creates the resource manager.
     *
     * @return The newly created resource manager.
     */
    virtual Resource::IResourceManagerShrPtr createResourceManager() const;

    /**
     * @brief Creates the settlement manager.
     *
     * @return The newly created settlement manager.
     */
    virtual Settlement::ISettlementManagerShrPtr createSettlementManager() const;

    /**
     * @brief Creates the user manager.
     *
     * @return The newly created user manager.
     */
    virtual User::IUserManagerShrPtr createUserManager() const;

    /**
     * @brief Creates the world manager.
     *
     * @return The newly created world manager.
     */
    virtual World::IWorldManagerShrPtr createWorldManager() const;

private:
    /**
     * @brief The abstract factory of accessors.
     */
    IAccessorAbstractFactoryShrPtr m_accessor_abstract_factory;
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_MANAGERABSTRACTFACTORYPOSTGRESQL_HPP
