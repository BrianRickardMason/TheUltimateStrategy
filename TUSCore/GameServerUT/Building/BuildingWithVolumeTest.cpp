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

#include "../../GameServer/Building/BuildingWithVolume.hpp"
#include <GameServer/Building/Key.hpp>
#include <Network/XmlRPCServer/Context.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Building;
using namespace GameServer::Common;
using namespace GameServer::Configuration;

/**
 * @brief A test class.
 */
class BuildingWithVolumeTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    BuildingWithVolumeTest()
        : m_context(new Context),
          m_building_with_volume(m_context, KEY_DEFENSIVE_BARBICAN, 4),
          m_model_key(KEY_DEFENSIVE_BARBICAN)
    {
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;

    /**
     * @brief A building with volume to be tested.
     */
    BuildingWithVolume m_building_with_volume;

    /**
     * @brief A model key.
     */
    IBuildingKey m_model_key;
};

TEST_F(BuildingWithVolumeTest, BuildingWithVolume_BasedOnArguments)
{
    BuildingWithVolume building_with_volume(m_context, KEY_DEFENSIVE_BARBICAN, 4);

    ASSERT_TRUE(m_model_key == building_with_volume.getBuilding()->getKey());
    ASSERT_EQ(4, building_with_volume.getVolume());
}

TEST_F(BuildingWithVolumeTest, BuildingWithVolume_BasedOnRecord)
{
    BuildingWithVolumeRecord
        building_with_volume_record(IDHolder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"), KEY_DEFENSIVE_BARBICAN, 4);

    BuildingWithVolume building_with_volume(m_context, building_with_volume_record);

    ASSERT_TRUE(m_model_key == building_with_volume.getBuilding()->getKey());
    ASSERT_EQ(4, building_with_volume.getVolume());
}

TEST_F(BuildingWithVolumeTest, getKey)
{
    ASSERT_TRUE(m_model_key == m_building_with_volume.getBuilding()->getKey());
}

TEST_F(BuildingWithVolumeTest, getVolume)
{
    ASSERT_EQ(4, m_building_with_volume.getVolume());
}
