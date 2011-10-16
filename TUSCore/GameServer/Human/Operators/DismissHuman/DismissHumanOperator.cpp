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

#include "DismissHumanOperator.hpp"

using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace GameServer::Resource;

namespace GameServer
{
namespace Human
{

DismissHumanOperator::DismissHumanOperator(
    ICostManagerShrPtr     a_cost_manager,
    IHumanManagerShrPtr    a_human_manager,
    IPropertyManagerShrPtr a_property_manager,
    IResourceManagerShrPtr a_resource_manager
)
    : m_cost_manager(a_cost_manager),
      m_human_manager(a_human_manager),
      m_property_manager(a_property_manager),
      m_resource_manager(a_resource_manager)
{
}

/**
 * TODO: Managers could be grouped together and passed as a one argument. Architecture change may be needed as well.
 * TODO: Check if holder exists.
 */
DismissHumanOperatorExitCode DismissHumanOperator::dismissHuman(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
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
        ResourceSet resource_set = m_resource_manager->getResources(a_transaction, a_id_holder);

        // Get total cost.
        ResourceSet cost = m_cost_manager->getCost(a_transaction, a_key.toHash(), ID_COST_TYPE_HUMAN_DISMISS);

        // Multiply total cost.
        cost *= a_volume;

        // Check if there is enough resources.
        if (!(resource_set >= cost))
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES);
        }

        // Subtract the resources.
        bool const result_subtract_resource = m_resource_manager->subtractResourceSet(a_transaction, a_id_holder, cost);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough resources and trying to subtract it.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_resource)
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME);
        }

        // Subtract the engaged.
        bool const result_subtract_human = m_human_manager->subtractHuman(a_transaction, a_id_holder, a_key, a_volume);

        // There is a possible situation (in multithreaded application) of a race condition between checking if
        // there is enough engaged and trying to subtract them.
        // As it is not an error (just a result of another action) the appropriate exit code is returned.
        if (!result_subtract_human)
        {
            return DismissHumanOperatorExitCode(DISMISS_HUMAN_OPERATOR_EXIT_CODE_HUMANS_MISSING_IN_THE_MEANTIME);
        }

        // Add the jobless.
        // TODO: Consider adding novice and advanced jobless.
        m_human_manager->addHuman(a_transaction, a_id_holder, KEY_WORKER_JOBLESS_NOVICE, a_volume);

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
    Key                const & a_key
) const
{
    // Check if human is dismissable.
    PropertyBooleanShrPtr dismissable =
        m_property_manager->getPropertyBoolean(a_transaction, a_key.toHash(), ID_PROPERTY_HUMAN_DISMISSABLE);

    return dismissable->getValue();
}

bool DismissHumanOperator::verifyEngaged(
    ITransactionShrPtr         a_transaction,
    IDHolder           const & a_id_holder,
    Key                const & a_key,
    Volume             const & a_volume
) const
{
    // Get the engaged.
    HumanWithVolumeShrPtr engaged = m_human_manager->getHuman(a_transaction, a_id_holder, a_key);

    // There are no engaged.
    if (!engaged)
    {
        return false;
    }

    return (engaged->getVolume() >= a_volume);
}

} // namespace Human
} // namespace GameServer
