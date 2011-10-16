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

#include "IEngageHumanOperator.hpp"

#include "../../../Building/IBuildingManager.hpp"
#include "../../../Cost/ICostManager.hpp"
#include "../../../Human/IHumanManager.hpp"
#include "../../../Property/IPropertyManager.hpp"
#include "../../../Resource/IResourceManager.hpp"

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
     * @brief Constructs the operator.
     *
     * @param a_building_manager The manager of buildings.
     * @param a_cost_manager     The manager of costs.
     * @param a_human_manager    The manager of humans.
     * @param a_property_manager The manager of properties.
     * @param a_resource_manager The manager of resources.
     */
    EngageHumanOperator(
        Building::IBuildingManagerShrPtr a_building_manager,
        Cost::ICostManagerShrPtr         a_cost_manager,
        IHumanManagerShrPtr              a_human_manager,
        Property::IPropertyManagerShrPtr a_property_manager,
        Resource::IResourceManagerShrPtr a_resource_manager
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
        Key                             const & a_key,
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
        Key                             const & a_key,
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
        Key                             const & a_key
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
     * @brief The manager of buildings.
     */
    Building::IBuildingManagerShrPtr m_building_manager;

    /**
     * @brief The manager of costs.
     */
    Cost::ICostManagerShrPtr m_cost_manager;

    /**
     * @brief The manager of humans.
     */
    IHumanManagerShrPtr m_human_manager;

    /**
     * @brief The manager of properties.
     */
    Property::IPropertyManagerShrPtr m_property_manager;

    /**
     * @brief The manager of resources.
     */
    Resource::IResourceManagerShrPtr m_resource_manager;
};

/**
 * @brief The auto pointer of EngageHumanOperator.
 */
typedef std::auto_ptr<EngageHumanOperator> EngageHumanOperatorAutPtr;

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_ENGAGEHUMANOPERATOR_HPP
