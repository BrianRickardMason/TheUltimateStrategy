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

#include <TUSGame/GameServer/Human/Operators/DismissHuman/DismissHumanOperator.hpp>
#include <TUSGame/GameServer/Resource/Helpers.hpp>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Human
{

DismissHumanOperator::DismissHumanOperator(
    IContextShrPtr                   const a_context,
    IHumanPersistenceFacadeShrPtr          a_human_persistence_facade,
    IResourcePersistenceFacadeShrPtr       a_resource_persistence_facade
)
    : m_context(a_context),
      m_human_persistence_facade(a_human_persistence_facade),
      m_resource_persistence_facade(a_resource_persistence_facade)
{
}

/**
 * TODO: Persistence facades could be grouped together and passed as a one argument. Architecture change may be needed as well.
 * TODO: Check if holder exists.
 */
DismissHumanOperatorExitCode DismissHumanOperator::dismissHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
    Volume             const & a_volume
) const
{
    try
    {
        // Trying to dismiss zero humans.
        if (a_volume == 0)
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_TRYING_TO_DISMISS_ZERO_HUMANS);
        }

        // Human is not dismissable.
        if (!verifyDismissable(a_transaction, a_key))
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_IS_NOT_DISMISSABLE);
        }

        // There are not enough engaged.
        // TODO: Join it with verifyDismissable.
        if (!verifyEngaged(a_transaction, a_id_holder, a_key, a_volume))
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_ENGAGED);
        }

        // Get available resources.
        ResourceWithVolumeMap resource_map = m_resource_persistence_facade->getResources(a_transaction, a_id_holder);

        // Get total cost.
        std::map<IKey, GameServer::Resource::Volume> const & cost_map =
            m_context->getConfiguratorHuman()->getHuman(a_key)->getCostsToDismiss();

        // FIXME: Workaround to get the ResourceWithVolumeMap.
        ResourceWithVolumeMap cost;

        for (std::map<IKey, Volume>::const_iterator it = cost_map.begin(); it != cost_map.end(); ++it)
        {
            ResourceWithVolumeShrPtr resource(new ResourceWithVolume(m_context, it->first, it->second));

            cost[it->first] = resource;
        }

        // Multiply total cost.
        cost = multiply(m_context, cost, a_volume);

        // Check if there is enough resources.
        if (!isFirstGreaterOrEqual(resource_map, cost))
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Subtract the resources.
        bool const result_subtract_resource =
            m_resource_persistence_facade->subtractResources(a_transaction, a_id_holder, cost);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough resources and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_resource)
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME);
        }

        // Subtract the engaged.
        bool const result_subtract_human =
            m_human_persistence_facade->subtractHuman(a_transaction, a_id_holder, a_key, a_volume);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough engaged and trying to subtract them.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_human)
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMANS_MISSING_IN_THE_MEANTIME);
        }

        // Add the jobless.
        // TODO: Consider adding novice and advanced jobless.
        m_human_persistence_facade->addHuman(a_transaction, a_id_holder, KEY_WORKER_JOBLESS_NOVICE, a_volume);

        // Everything went fine.
        return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_DISMISSED);
    }
    catch (...)
    {
        return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

bool DismissHumanOperator::verifyDismissable(
    ITransactionShrPtr         a_transaction,
    IKey               const & a_key
) const
{
    IHumanShrPtr human = m_context->getConfiguratorHuman()->getHuman(a_key);

    BOOST_ASSERT(human);

    return human->isDismissable();
}

bool DismissHumanOperator::verifyEngaged(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    IKey               const & a_key,
    Volume             const & a_volume
) const
{
    // Get the engaged.
    HumanWithVolumeShrPtr engaged = m_human_persistence_facade->getHuman(a_transaction, a_id_holder, a_key);

    // There are no engaged.
    if (!engaged)
    {
        return false;
    }

    return (engaged->getVolume() >= a_volume);
}

} // namespace Human
} // namespace GameServer
