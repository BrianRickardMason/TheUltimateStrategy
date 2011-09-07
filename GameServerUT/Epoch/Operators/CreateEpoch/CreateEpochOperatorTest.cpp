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

#include "../../../../GameServer/Epoch/Operators/CreateEpoch/CreateEpochOperator.hpp"
#include "../../../../GameServer/World/WorldRecord.hpp"
#include "../../../Persistency/TransactionDummy.hpp"
#include "../../../World/WorldManagerMock.hpp"
#include "../../EpochManagerMock.hpp"
#include <boost/make_shared.hpp>

using namespace GameServer::Epoch;
using namespace GameServer::Persistency;
using namespace GameServer::World;
using namespace boost;

using testing::Return;
using testing::Throw;

/**
 * @brief The test class.
 */
class CreateEpochOperatorTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs the test class.
     */
    CreateEpochOperatorTest()
        : m_epoch_manager(new EpochManagerMock),
          m_world_manager(new WorldManagerMock),
          m_id_world_1(1)
    {
    }

    /**
     * @brief The manager of epochs.
     */
    EpochManagerMock * m_epoch_manager;

    /**
     * @brief The manager of worlds.
     */
    WorldManagerMock * m_world_manager;

    /**
     * @brief Test constants: identifiers of worlds.
     */
    IDWorld m_id_world_1;
};

TEST_F(CreateEpochOperatorTest, createEpoch_WorldDoesNotExist)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    EXPECT_CALL(*m_world_manager, getWorld(transaction, m_id_world_1))
    .WillOnce(Return(WorldShrPtr()));

    CreateEpochOperator create_epoch_operator((IEpochManagerShrPtr(m_epoch_manager)),
                                              (IWorldManagerShrPtr(m_world_manager)));

    ASSERT_EQ(CREATE_EPOCH_OPERATOR_EXIT_CODE_WORLD_DOES_NOT_EXIST,
              create_epoch_operator.createEpoch(transaction, m_id_world_1).m_exit_code);
}

TEST_F(CreateEpochOperatorTest, createEpoch_EpochHasBeenCreated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    IWorldRecordShrPtr world_record(new WorldRecord(m_id_world_1, "World1"));

    WorldShrPtr world = make_shared<World>(world_record);

    EXPECT_CALL(*m_world_manager, getWorld(transaction, m_id_world_1))
    .WillOnce(Return(world));

    EXPECT_CALL(*m_epoch_manager, createEpoch(transaction, m_id_world_1))
    .WillOnce(Return(true));

    CreateEpochOperator create_epoch_operator((IEpochManagerShrPtr(m_epoch_manager)),
                                              (IWorldManagerShrPtr(m_world_manager)));

    ASSERT_EQ(CREATE_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_BEEN_CREATED,
              create_epoch_operator.createEpoch(transaction, m_id_world_1).m_exit_code);
}

TEST_F(CreateEpochOperatorTest, createEpoch_EpochHasNotBeenCreated)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    IWorldRecordShrPtr world_record(new WorldRecord(m_id_world_1, "World1"));

    WorldShrPtr world = make_shared<World>(world_record);

    EXPECT_CALL(*m_world_manager, getWorld(transaction, m_id_world_1))
    .WillOnce(Return(world));

    EXPECT_CALL(*m_epoch_manager, createEpoch(transaction, m_id_world_1))
    .WillOnce(Return(false));

    CreateEpochOperator create_epoch_operator((IEpochManagerShrPtr(m_epoch_manager)),
                                              (IWorldManagerShrPtr(m_world_manager)));

    ASSERT_EQ(CREATE_EPOCH_OPERATOR_EXIT_CODE_EPOCH_HAS_NOT_BEEN_CREATED,
              create_epoch_operator.createEpoch(transaction, m_id_world_1).m_exit_code);
}

TEST_F(CreateEpochOperatorTest, createEpoch_UnexpectedError)
{
    ITransactionShrPtr transaction(new TransactionDummy);

    std::exception e;

    EXPECT_CALL(*m_world_manager, getWorld(transaction, m_id_world_1))
    .WillOnce(Throw(e));

    CreateEpochOperator create_epoch_operator((IEpochManagerShrPtr(m_epoch_manager)),
                                              (IWorldManagerShrPtr(m_world_manager)));

    ASSERT_EQ(CREATE_EPOCH_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR,
              create_epoch_operator.createEpoch(transaction, m_id_world_1).m_exit_code);
}
