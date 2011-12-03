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

#include <GameServer/Common/IDHolder.hpp>
#include <GameServer/Human/Key.hpp>
#include <GameServer/Human/Human.hpp>
#include <GameServer/Resource/Helpers.hpp>
#include <GameServer/Resource/Key.hpp>
#include <GameServer/Turn/Managers/TurnManager.hpp>
#include <math.h>

using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Human;
using namespace GameServer::Land;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace GameServer::Settlement;
using namespace GameServer::World;

namespace GameServer
{
namespace Turn
{

TurnManager::TurnManager(
    IContextShrPtr                     const a_context,
    IHumanPersistenceFacadeShrPtr            a_human_persistence_facade,
    ILandPersistenceFacadeShrPtr             a_land_persistence_facade,
    IResourcePersistenceFacadeShrPtr         a_resource_persistence_facade,
    ISettlementPersistenceFacadeShrPtr       a_settlement_persistence_facade
)
    : m_context(a_context),
      m_human_persistence_facade(a_human_persistence_facade),
      m_land_persistence_facade(a_land_persistence_facade),
      m_resource_persistence_facade(a_resource_persistence_facade),
      m_settlement_persistence_facade(a_settlement_persistence_facade)
{
}

bool TurnManager::turn(
    ITransactionShrPtr       a_transaction,
    IWorldShrPtr       const a_world
) const
{
    try
    {
        // Get lands that belong to the world.
        ILandMap lands = m_land_persistence_facade->getLands(a_transaction, a_world);

        // Execute turn of every land.
        for (ILandMap::const_iterator it = lands.begin(); it != lands.end(); ++it)
        {
            bool const result = executeTurn(a_transaction, it->second);

            if (!result)
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool TurnManager::executeTurn(
    ITransactionShrPtr       a_transaction,
    ILandShrPtr        const a_land
) const
{
    ISettlementMap settlements = m_settlement_persistence_facade->getSettlements(a_transaction, a_land);

    for (ISettlementMap::iterator it = settlements.begin(); it != settlements.end(); ++it)
    {
        bool const result = executeTurnSettlement(a_transaction, it->second->getSettlementName());

        if (!result)
        {
            return false;
        }
    }

    m_land_persistence_facade->increaseAge(a_transaction, a_land);

    return true;
}

bool TurnManager::executeTurnSettlement(
    ITransactionShrPtr       a_transaction,
    std::string        const a_settlement_name
) const
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    // Correct engagement.
    // TODO: Implement me!

    // Get the available resources.
    ResourceWithVolumeMap const available_resources = m_resource_persistence_facade->getResources(a_transaction, id_holder);

    // Get the cost of living.
    ResourceWithVolumeMap const cost_of_living = getCostOfLiving(a_transaction, a_settlement_name);

    // Verify if famine happened.
    bool const famine_happened = verifyFamine(available_resources, cost_of_living);
    if (famine_happened)
    {
        bool const result = famine(a_transaction, a_settlement_name);

        if (!result)
        {
            return false;
        }
    }

    // Verify if poverty happened.
    bool const poverty_happened = verifyPoverty(available_resources, cost_of_living);
    if (poverty_happened)
    {
        bool const result = poverty(a_transaction, a_settlement_name);

        if (!result)
        {
            return false;
        }
    }

    // Expenses.
    {
        m_resource_persistence_facade->subtractResourcesSafely(a_transaction, id_holder, cost_of_living);
    }

    // Receipts.
    if (verifyReceipts())
    {
        receipts(a_transaction, a_settlement_name);
    }

    // Experience.
    if (!poverty_happened)
    {
        HumanWithVolumeMap const humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

        for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
        {
            // TODO: Use property experienceable.

            Configuration::IKey const key = it->second->getHuman()->getKey();

            if (key == Human::KEY_WORKER_JOBLESS_NOVICE or key == Human::KEY_WORKER_JOBLESS_ADVANCED)
            {
                continue;
            }

            if (it->second->getHuman()->getExperience() == "advanced") // TODO: A nasty hardcode. Fixme!
            {
                continue;
            }

            // TODO: Hardcoded HUMAN_EXPERIENCE_FACTOR.
            Human::Volume const experienced = it->second->getVolume() * 0.1;

            if (experienced)
            {
                IKey key_novice = it->first;
                IKey key_advanced;

                // TODO: A nasty workaround.
                if (key_novice ==  KEY_SOLDIER_ARCHER_NOVICE     ) key_advanced = KEY_SOLDIER_ARCHER_ADVANCED;
                if (key_novice ==  KEY_SOLDIER_HORSEMAN_NOVICE   ) key_advanced = KEY_SOLDIER_HORSEMAN_ADVANCED;
                if (key_novice ==  KEY_SOLDIER_INFANTRYMAN_NOVICE) key_advanced = KEY_SOLDIER_INFANTRYMAN_ADVANCED;

                if (key_novice ==  KEY_SORCERER_EARTH_NOVICE     ) key_advanced = KEY_SORCERER_EARTH_ADVANCED;
                if (key_novice ==  KEY_SORCERER_FIRE_NOVICE      ) key_advanced = KEY_SORCERER_FIRE_ADVANCED;
                if (key_novice ==  KEY_SORCERER_WATER_NOVICE     ) key_advanced = KEY_SORCERER_WATER_ADVANCED;
                if (key_novice ==  KEY_SORCERER_WIND_NOVICE      ) key_advanced = KEY_SORCERER_WIND_ADVANCED;

                if (key_novice ==  KEY_SPY_AGENT_NOVICE          ) key_advanced = KEY_SPY_AGENT_ADVANCED;
                if (key_novice ==  KEY_SPY_SPY_NOVICE            ) key_advanced = KEY_SPY_SPY_ADVANCED;
                if (key_novice ==  KEY_SPY_THUG_NOVICE           ) key_advanced = KEY_SPY_THUG_ADVANCED;

                if (key_novice ==  KEY_WORKER_BLACKSMITH_NOVICE  ) key_advanced = KEY_WORKER_BLACKSMITH_ADVANCED;
                if (key_novice ==  KEY_WORKER_BREEDER_NOVICE     ) key_advanced = KEY_WORKER_BREEDER_ADVANCED;
                if (key_novice ==  KEY_WORKER_DRUID_NOVICE       ) key_advanced = KEY_WORKER_DRUID_ADVANCED;
                if (key_novice ==  KEY_WORKER_FARMER_NOVICE      ) key_advanced = KEY_WORKER_FARMER_ADVANCED;
                if (key_novice ==  KEY_WORKER_FISHERMAN_NOVICE   ) key_advanced = KEY_WORKER_FISHERMAN_ADVANCED;
                if (key_novice ==  KEY_WORKER_JOBLESS_NOVICE     ) key_advanced = KEY_WORKER_JOBLESS_ADVANCED;
                if (key_novice ==  KEY_WORKER_LUMBERJACK_NOVICE  ) key_advanced = KEY_WORKER_LUMBERJACK_ADVANCED;
                if (key_novice ==  KEY_WORKER_MERCHANT_NOVICE    ) key_advanced = KEY_WORKER_MERCHANT_ADVANCED;
                if (key_novice ==  KEY_WORKER_MINER_NOVICE       ) key_advanced = KEY_WORKER_MINER_ADVANCED;
                if (key_novice ==  KEY_WORKER_OFFICIAL_NOVICE    ) key_advanced = KEY_WORKER_OFFICIAL_ADVANCED;
                if (key_novice ==  KEY_WORKER_PRIEST_NOVICE      ) key_advanced = KEY_WORKER_PRIEST_ADVANCED;
                if (key_novice ==  KEY_WORKER_STEELWORKER_NOVICE ) key_advanced = KEY_WORKER_STEELWORKER_ADVANCED;
                if (key_novice ==  KEY_WORKER_STONE_MASON_NOVICE ) key_advanced = KEY_WORKER_STONE_MASON_ADVANCED;
                if (key_novice ==  KEY_WORKER_TEACHER_NOVICE     ) key_advanced = KEY_WORKER_TEACHER_ADVANCED;

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
    if (!famine_happened)
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

ResourceWithVolumeMap TurnManager::getCostOfLiving(
    ITransactionShrPtr       a_transaction,
    std::string        const a_settlement_name
) const
{
    ResourceWithVolumeMap total_cost;

    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

    for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        std::map<IKey, GameServer::Resource::Volume> const & cost_map =
            it->second->getHuman()->getCostsToLive();

        // FIXME: Workaround to get the ResourceWithVolumeMap.
        ResourceWithVolumeMap resources;

        for (std::map<IKey, Volume>::const_iterator itr = cost_map.begin(); itr != cost_map.end(); ++itr)
        {
            ResourceWithVolumeShrPtr resource(new ResourceWithVolume(m_context, itr->first, itr->second));

            resources[itr->first] = resource;
        }

        resources = multiply(m_context, resources, it->second->getVolume());

        total_cost = add(m_context, total_cost, resources);
    }

    return total_cost;
}

bool TurnManager::verifyFamine(
    Resource::ResourceWithVolumeMap const & a_available_resources,
    Resource::ResourceWithVolumeMap const & a_used_resources
) const
{
    Resource::Volume available(0), used(0);

    try
    {
        // FIXME: Code smell - envious class.
        available = a_available_resources.at(KEY_RESOURCE_FOOD)->getVolume();
    }
    catch (...)
    {
    }

    try
    {
        // FIXME: Code smell - envious class.
        used = a_used_resources.at(KEY_RESOURCE_FOOD)->getVolume();
    }
    catch (...)
    {
    }

    return (available < used) ? true : false;
}

bool TurnManager::famine(
    ITransactionShrPtr       a_transaction,
    std::string        const a_settlement_name
) const
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

    for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        // TODO: Hardcoded FAMINE_DEATH_FACTOR.
        Human::Volume died = ceil(it->second->getVolume() * 0.1);

        if (died)
        {
            bool const result =
                m_human_persistence_facade->subtractHuman(
                    a_transaction,
                    id_holder,
                    it->second->getHuman()->getKey(),
                    died
                );

            if (!result)
            {
                return false;
            }
        }
    }

    return true;
}

bool TurnManager::verifyPoverty(
    Resource::ResourceWithVolumeMap const & a_available_resources,
    Resource::ResourceWithVolumeMap const & a_used_resources
) const
{
    Resource::Volume available(0), used(0);

    try
    {
        // FIXME: Code smell - envious class.
        available = a_available_resources.at(KEY_RESOURCE_GOLD)->getVolume();
    }
    catch (...)
    {
    }

    try
    {
        // FIXME: Code smell - envious class.
        used = a_used_resources.at(KEY_RESOURCE_GOLD)->getVolume();
    }
    catch (...)
    {
    }

    return (available < used) ? true : false;
}

bool TurnManager::poverty(
    ITransactionShrPtr       a_transaction,
    std::string        const a_settlement_name
) const
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    HumanWithVolumeMap humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

    for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        // TODO: Hardcoded POVERTY_DISMISS_FACTOR.
        Human::Volume dismissed = ceil(it->second->getVolume() * 0.1);

        if (dismissed)
        {
            bool const result =
                m_human_persistence_facade->subtractHuman(
                    a_transaction,
                    id_holder,
                    it->second->getHuman()->getKey(),
                    dismissed
                );

            if (!result)
            {
                return false;
            }

            m_human_persistence_facade->addHuman(a_transaction, id_holder, KEY_WORKER_JOBLESS_NOVICE, dismissed);
        }
    }

    return true;
}

bool TurnManager::verifyReceipts() const
{
    return true;
}

void TurnManager::receipts(
    ITransactionShrPtr       a_transaction,
    std::string        const a_settlement_name
) const
{
    IDHolder id_holder(ID_HOLDER_CLASS_SETTLEMENT, a_settlement_name);

    HumanWithVolumeMap const humans = m_human_persistence_facade->getHumans(a_transaction, id_holder);

    for (HumanWithVolumeMap::const_iterator it = humans.begin(); it != humans.end(); ++it)
    {
        std::map<Configuration::IKey, std::string>::const_iterator production =
            HUMAN_MAP_PRODUCTION.find(it->second->getHuman()->getKey());

        if (production != HUMAN_MAP_PRODUCTION.end())
        {
            // TODO: Define whether and how to check if volume is greater than 0.
            m_resource_persistence_facade->addResource(
                a_transaction,
                id_holder,
                production->second,
                it->second->getHuman()->getProduction() * it->second->getVolume()
            );
        }
    }
}

} // namespace Turn
} // namespace GameServer
