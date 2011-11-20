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

#include "../../GameServer/Common/PersistenceFacadeAbstractFactoryPostgresql.hpp"
#include "../ComponentTest.hpp"
#include <GameServer/Configuration/Configurator/Building/ConfiguratorBuilding.hpp>
#include <GameServer/Configuration/Configurator/Human/ConfiguratorHuman.hpp>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Common;
using namespace GameServer::Configuration;
using namespace GameServer::Cost;
using namespace GameServer::Human;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;

/**
 * @brief A test class.
 */
class CostPersistenceFacadeTest
    : public ComponentTest
{
protected:
    /**
     * @brief Constructs the test class.
     */
    CostPersistenceFacadeTest()
        : m_persistence_facade_abstract_factory(new PersistenceFacadeAbstractFactoryPostgresql),
          m_cost_persistence_facade(m_persistence_facade_abstract_factory->createCostPersistenceFacade())
    {
    }

    /**
     * @brief The abstract factory of persistence facades.
     */
    IPersistenceFacadeAbstractFactoryShrPtr m_persistence_facade_abstract_factory;

    /**
     * @brief A persistence facade used in tests.
     */
    ICostPersistenceFacadeShrPtr m_cost_persistence_facade;
};
