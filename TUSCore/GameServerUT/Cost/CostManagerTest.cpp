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

#include "../../GameServer/Cost/CostManager.hpp"
#include "../../GameServer/Resource/Resource.hpp"
#include "../Persistence/TransactionDummy.hpp"
#include "CostManagerAccessorMock.hpp"

using namespace GameServer::Common;
using namespace GameServer::Cost;
using namespace GameServer::Persistence;
using namespace GameServer::Resource;
using namespace boost;

using testing::Return;
using testing::Throw;

/**
 * @brief A test class.
 */
class CostManagerTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    CostManagerTest()
        : m_cost_record_coal(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_COAL, 100)),
          m_cost_record_food(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_FOOD, 200)),
          m_cost_record_gold(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_GOLD, 300)),
          m_cost_record_iron(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_IRON, 400)),
          m_cost_record_mana(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_MANA, 500)),
          m_cost_record_rock(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_ROCK, 600)),
          m_cost_record_wood(make_shared<CostRecord>(1, ID_COST_TYPE_BUILDING_BUILD, ID_RESOURCE_WOOD, 700))
    {
        m_cost_record_vector.push_back(m_cost_record_coal);
        m_cost_record_vector.push_back(m_cost_record_food);
        m_cost_record_vector.push_back(m_cost_record_gold);
        m_cost_record_vector.push_back(m_cost_record_iron);
        m_cost_record_vector.push_back(m_cost_record_mana);
        m_cost_record_vector.push_back(m_cost_record_rock);
        m_cost_record_vector.push_back(m_cost_record_wood);
    }

    /**
     * @brief Test constants cost record shared pointers.
     */
    CostRecordShrPtr m_cost_record_coal,
                     m_cost_record_food,
                     m_cost_record_gold,
                     m_cost_record_iron,
                     m_cost_record_mana,
                     m_cost_record_rock,
                     m_cost_record_wood;

    /**
     * @brief Test constants cost record vector.
     */
    CostRecordVec m_cost_record_vector;
};

TEST_F(CostManagerTest, CostManager)
{
    ICostManagerAccessorAutPtr accessor(new CostManagerAccessorMock);

    ASSERT_NO_THROW(CostManager manager(accessor));
}

TEST_F(CostManagerTest, getCost_Success)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    CostManagerAccessorMock * mock = new CostManagerAccessorMock;

    EXPECT_CALL(*mock, getCosts(transaction, 1, 2))
    .WillOnce(Return(m_cost_record_vector));

    ICostManagerAccessorAutPtr accessor(mock);

    CostManager manager(accessor);

    // Test commands.
    ResourceSet resource_set = manager.getCost(transaction, 1, 2);

    // Test assertions.
    ResourceWithVolumeMap resource_map = resource_set.getMap();
    ASSERT_EQ(NUMBER_OF_RESOURCE_TYPES, resource_map.size());

    unsigned short int i(0);
    for (ResourceWithVolumeMap::iterator it = resource_map.begin(); it != resource_map.end(); ++it, ++i)
    {
        ASSERT_EQ(100 * (i + 1), it->second->getVolume());
    }
}

TEST_F(CostManagerTest, getCost_Failure_GetCostThrows)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    CostManagerAccessorMock * mock = new CostManagerAccessorMock;

    std::exception e;

    EXPECT_CALL(*mock, getCosts(transaction, 1, 2))
    .WillOnce(Throw(e));

    ICostManagerAccessorAutPtr accessor(mock);

    CostManager manager(accessor);

    // Test commands and assertions.
    ASSERT_THROW(ResourceSet resource_set = manager.getCost(transaction, 1, 2), std::exception);
}
