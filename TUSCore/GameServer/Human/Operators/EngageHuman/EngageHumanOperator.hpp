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

#ifndef GAMESERVER_HUMAN_ENGAGEHUMANOPERATOR_HPP
#define GAMESERVER_HUMAN_ENGAGEHUMANOPERATOR_HPP

#include "../../../Building/IBuildingPersistenceFacade.hpp"
#include "../../../Human/IHumanPersistenceFacade.hpp"
#include "../../../Resource/IResourcePersistenceFacade.hpp"
#include "IEngageHumanOperator.hpp"
#include <Network/XmlRPCServer/IContext.hpp>

namespace GameServer
{
namespace Human
{

/**
 * @brief EngageHumanOperator.
 */
class EngageHumanOperator
    : public IEngageHumanOperator
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_context                     The context of the server.
     * @param a_building_persistence_facade The persistence facade of buildings.
     * @param a_human_persistence_facade    The persistence facade of humans.
     * @param a_resource_persistence_facade The persistence facade of resources.
     */
    EngageHumanOperator(
        IContextShrPtr                             const a_context,
        Building::IBuildingPersistenceFacadeShrPtr       a_building_persistence_facade,
        IHumanPersistenceFacadeShrPtr                    a_human_persistence_facade,
        Resource::IResourcePersistenceFacadeShrPtr       a_resource_persistence_facade
    );

    /**
     * @brief Engages a human.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the human.
     * @param a_volume      The volume of the human.
     *
     * @returns The exit code.
     */
    virtual EngageHumanOperatorExitCode engageHuman(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IHumanKey        const & a_key,
        Volume                          const & a_volume
    ) const;

private:
    /**
     * @brief Verifies a dependency of engagement on the building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the human.
     * @param a_volume      The volume of the human.
     *
     * @returns True if the dependency has been fulfilled, false otherwise.
     */
    bool verifyDependencyOfEngagementOnBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IHumanKey        const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Verifies if the human is engageable.
     *
     * @param a_transaction The transaction.
     * @param a_key         The key of the human.
     *
     * @returns True if the human is engageable, false otherwise.
     */
    bool verifyEngageable(
        Persistence::ITransactionShrPtr         a_transaction,
        Configuration::IHumanKey        const & a_key
    ) const;

    /**
     * @brief Verifies if there is enough jobless.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_volume      The volume of the human.
     *
     * @returns True if there is enough jobless, false otherwise.
     */
    bool verifyJobless(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    //@{
    /**
     * @brief A persistence facade.
     */
    Building::IBuildingPersistenceFacadeShrPtr m_building_persistence_facade;
    IHumanPersistenceFacadeShrPtr              m_human_persistence_facade;
    Resource::IResourcePersistenceFacadeShrPtr m_resource_persistence_facade;
    //}@
};

/**
 * @brief A useful typedef.
 */
typedef std::auto_ptr<EngageHumanOperator> EngageHumanOperatorAutPtr;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_ENGAGEHUMANOPERATOR_HPP
