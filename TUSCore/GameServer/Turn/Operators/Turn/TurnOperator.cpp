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

#include "../../../Common/IDHolder.hpp"
#include "TurnOperator.hpp"

using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Property;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace std;

namespace GameServer
{
namespace Turn
{

TurnOperator::TurnOperator(
    ICostManagerShrPtr                 a_cost_manager,
    IHumanPersistenceFacadeShrPtr      a_human_persistence_facade,
    ILandPersistenceFacadeShrPtr       a_land_persistence_facade,
    IPropertyManagerShrPtr             a_property_manager,
    IResourceManagerShrPtr             a_resource_manager,
    ISettlementPersistenceFacadeShrPtr a_settlement_persistence_facade
)
    : m_cost_manager(a_cost_manager),
      m_human_persistence_facade(a_human_persistence_facade),
      m_land_persistence_facade(a_land_persistence_facade),
      m_property_manager(a_property_manager),
      m_resource_manager(a_resource_manager),
      m_settlement_persistence_facade(a_settlement_persistence_facade)
{
}

TurnOperatorExitCode TurnOperator::turn(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    try
    {
        // Verify if the land exists.
        if (!m_land_persistence_facade->getLand(a_transaction, a_land_name))
        {
            return TurnOperatorExitCode(TURN_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST);
        }

        bool const result = executeTurn(a_transaction, a_land_name);

        return (result) ? TurnOperatorExitCode(TURN_OPERATOR_EXIT_CODE_TURN_HAS_BEEN_PERFORMED)
                        : TurnOperatorExitCode(TURN_OPERATOR_EXIT_CODE_TURN_HAS_NOT_BEEN_PERFORMED);
    }
    catch (...)
    {
        return TurnOperatorExitCode(TURN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR);
    }
}

bool TurnOperator::executeTurn(
    ITransactionShrPtr       a_transaction,
    string             const a_land_name
) const
{
    ILandShrPtr land = m_land_persistence_facade->getLand(a_transaction, a_land_name);

    if (!land)
    {
        return false;
    }

    ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(a_transaction, land);

    for (ISettlementMap::iterator it = settlements.begin(); it != settlements.end(); ++it)
    {
        bool const result = executeTurnSettlement(a_transaction, it->second->getSettlementName());

        if (!result)
        {
            return false;
        }
    }

    return true;
}

bool TurnOperator::executeTurnSettlement(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    // Correct engagement.
    // TODO: Implement me!

    // Get the available resources.
    ResourceSet available_resources = m_resource_manager->getResources(a_transaction, id_holder);

    // Get the cost of living.
    ResourceSet cost_of_living = getCostOfLiving(a_transaction, a_settlement_name);

    // Verify famine.
    // FIXME: Code smell: envious class.
    if (available_resources.getMap().at(KEY_RESOURCE_FOOD)->getVolume() < cost_of_living.getMap().at(KEY_RESOURCE_FOOD)->getVolume())
    {
        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // TODO: Hardcoded FAMINE_DEATH_FACTOR.
            Human::Volume died = it->second->getVolume() * 0.1;

            if (died)
            {
                bool const result =
                    m_human_persistence_facade->subtractHuman(a_transaction, id_holder, it->second->getKey(), died);

                if (!result)
                {
                    return false;
                }
            }
        }
    }

    // Verify poverty.
    // FIXME: Code smell: envious class.
    if (available_resources.getMap().at(KEY_RESOURCE_GOLD)->getVolume() < cost_of_living.getMap().at(KEY_RESOURCE_GOLD)->getVolume())
    {
        HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // TODO: Hardcoded POVERTY_DISMISS_FACTOR.
            Human::Volume dismissed = it->second->getVolume() * 0.1;

            if (dismissed)
            {
                bool const result = m_human_persistence_facade->subtractHuman(
                                        a_transaction,
                                        id_holder,
                                        it->second->getKey(),
                                        dismissed
                                    );

                if (!result)
                {
                    return false;
                }

                m_human_persistence_facade->addHuman(a_transaction, id_holder, KEY_WORKER_JOBLESS_NOVICE, dismissed);
            }
        }
    }

    // Expenses.
    {
        m_resource_manager->subtractResourceSetSafely(a_transaction, id_holder, cost_of_living);
    }

    // Receipts.
    {
        HumanWithVolumeMap const humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            map<IDHuman, Resource::Key>::const_iterator production = HUMAN_MAP_PRODUCTION.find(it->second->getIDHuman());

            if (production != HUMAN_MAP_PRODUCTION.end())
            {
                PropertyIntegerShrPtr const produced = m_property_manager->getPropertyInteger(a_transaction, it->first.toHash(), ID_PROPERTY_HUMAN_PRODUCTION);

                BOOST_ASSERT(produced->getValue() > 0);

                m_resource_manager->addResource(a_transaction, id_holder, production->second, produced->getValue());
            }
        }
    }

    // Experience.
    {
        HumanWithVolumeMap const humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // TODO: Use property experienceable.

            IDHuman const id_human = it->second->getIDHuman();

            if (id_human == ID_HUMAN_WORKER_JOBLESS)
            {
                continue;
            }

            if (it->second->getExperience() == EXPERIENCE_ADVANCED)
            {
                continue;
            }

            // TODO: Hardcoded HUMAN_EXPERIENCE_FACTOR.
            Human::Volume const experienced = it->second->getVolume() * 0.1;

            if (experienced)
            {
                Human::Key const key_novice(id_human, EXPERIENCE_NOVICE);
                Human::Key const key_advanced(id_human, EXPERIENCE_ADVANCED);

                m_human_persistence_facade->addHuman(a_transaction, id_holder, key_advanced, experienced);

                bool const result = m_human_persistence_facade->subtractHuman(
                                        a_transaction,
                                        id_holder,
                                        key_novice,
                                        experienced
                                    );

                if (!result)
                {
                    return false;
                }
            }
        }
    }

    // Reproduce.
    {
        HumanWithVolumeMap const humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // TODO: Use property reproduceable.

            // TODO: Hardcoded HUMAN_REPRODUCE_FACTOR.
            // TODO: Random choosing if reproduction happened (if the uint result of volume * HUMAN_REPRODUCE_FACTOR < 1).
            Human::Volume const reproduced = it->second->getVolume() * 0.1;

            if (reproduced)
            {
                m_human_persistence_facade->addHuman(a_transaction, id_holder, KEY_WORKER_JOBLESS_NOVICE, reproduced);
            }
        }
    }

    return true;
}

ResourceSet TurnOperator::getCostOfLiving(
    ITransactionShrPtr       a_transaction,
    string             const a_settlement_name
) const
{
    ResourceSet total_cost;

    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

    for (HumanWithVolumeMap::iterator it = humans.begin(); it != humans.end(); ++it)
    {
        ResourceSet human_cost = m_cost_manager->getCost(a_transaction, it->second->getKey().toHash(), ID_COST_TYPE_HUMAN_LIVING);

        human_cost *= it->second->getVolume();

        total_cost += human_cost;
    }

    return total_cost;
}

} // namespace Turn
} // namespace GameServer
