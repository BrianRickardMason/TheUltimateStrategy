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

#ifndef GAMESERVER_COMMON_PERSISTENCEFACADEABSTRACTFACTORYPOSTGRESQL_HPP
#define GAMESERVER_COMMON_PERSISTENCEFACADEABSTRACTFACTORYPOSTGRESQL_HPP

#include <TUSServer/Network/XmlRPCServer/IContext.hpp>
#include <TUSGame/GameServer/Common/IAccessorAbstractFactory.hpp>
#include <TUSGame/GameServer/Common/IPersistenceFacadeAbstractFactory.hpp>

namespace GameServer
{
namespace Common
{

/**
 * @brief The PostgreSQL PersistenceFacadeAbstractFactory.
 */
class PersistenceFacadeAbstractFactoryPostgresql
    : public IPersistenceFacadeAbstractFactory
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_context The context of the server.
     */
    PersistenceFacadeAbstractFactoryPostgresql(
        IContextShrPtr const a_context
    );

    //@{
    /**
     * @brief Creates a persistence facade.
     *
     * @return The newly created persistence facade.
     */
    virtual Achievement::IAchievementPersistenceFacadeShrPtr       createAchievementPersistenceFacade()    const;
    virtual Authentication::IAuthenticationPersistenceFacadeShrPtr createAuthenticationPersistenceFacade() const;
    virtual Authorization::IAuthorizationPersistenceFacadeShrPtr   createAuthorizationPersistenceFacade()  const;
    virtual Building::IBuildingPersistenceFacadeShrPtr             createBuildingPersistenceFacade()       const;
    virtual Epoch::IEpochPersistenceFacadeShrPtr                   createEpochPersistenceFacade()          const;
    virtual Human::IHumanPersistenceFacadeShrPtr                   createHumanPersistenceFacade()          const;
    virtual Land::ILandPersistenceFacadeShrPtr                     createLandPersistenceFacade()           const;
    virtual Resource::IResourcePersistenceFacadeShrPtr             createResourcePersistenceFacade()       const;
    virtual Settlement::ISettlementPersistenceFacadeShrPtr         createSettlementPersistenceFacade()     const;
    virtual User::IUserPersistenceFacadeShrPtr                     createUserPersistenceFacade()           const;
    virtual World::IWorldPersistenceFacadeShrPtr                   createWorldPersistenceFacade()          const;
    //}@

private:
    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief The abstract factory of accessors.
     */
    IAccessorAbstractFactoryShrPtr m_accessor_abstract_factory;
};

} // namespace Common
} // namespace GameServer

#endif // GAMESERVER_COMMON_PERSISTENCEFACADEABSTRACTFACTORYPOSTGRESQL_HPP
