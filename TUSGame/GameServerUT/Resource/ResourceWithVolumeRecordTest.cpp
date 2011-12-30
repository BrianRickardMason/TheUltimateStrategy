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

#include <TUSGame/GameServer/Resource/Key.hpp>
#include <TUSGame/GameServer/Resource/ResourceWithVolumeRecord.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Common;
using namespace GameServer::Resource;
using namespace std;

/**
 * @brief A test class.
 */
class ResourceWithVolumeRecordTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    ResourceWithVolumeRecordTest()
        : m_id_holder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"),
          m_record(m_id_holder, KEY_RESOURCE_FOOD, 3),
          m_model_key(KEY_RESOURCE_FOOD)
    {
    }

    /**
     * @brief An exemplary id holder.
     */
    IDHolder m_id_holder;

    /**
     * @brief A record to be tested.
     */
    ResourceWithVolumeRecord m_record;

    /**
     * @brief A model key.
     */
    string m_model_key;
};

TEST_F(ResourceWithVolumeRecordTest, ResourceWithVolumeRecord)
{
    ResourceWithVolumeRecord record(m_id_holder, KEY_RESOURCE_FOOD, 3);

    ASSERT_TRUE(m_id_holder == record.getIDHolder());
    ASSERT_TRUE(m_model_key == record.getKey());
    ASSERT_EQ(3, record.getVolume());
}

TEST_F(ResourceWithVolumeRecordTest, getIDHolder)
{
    ASSERT_TRUE(m_id_holder == m_record.getIDHolder());
}

TEST_F(ResourceWithVolumeRecordTest, getKey)
{
    ASSERT_TRUE(m_model_key == m_record.getKey());
}

TEST_F(ResourceWithVolumeRecordTest, getVolume)
{
    ASSERT_EQ(3, m_record.getVolume());
}
