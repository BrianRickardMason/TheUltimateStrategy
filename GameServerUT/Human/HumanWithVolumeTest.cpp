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

#include "../../GameServer/Human/HumanWithVolume.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Common;
using namespace GameServer::Human;

/**
 * @brief A test class.
 */
class HumanWithVolumeTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    HumanWithVolumeTest()
        : m_human_with_volume(Key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED), 4),
          m_model_key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED)
    {
    }

    /**
     * @brief A human with volume to be tested.
     */
    HumanWithVolume m_human_with_volume;

    /**
     * @brief A model key.
     */
    Key m_model_key;
};

TEST_F(HumanWithVolumeTest, HumanWithVolume_BasedOnArguments)
{
    HumanWithVolume human_with_volume(Key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED), 4);

    ASSERT_TRUE(m_model_key == human_with_volume.getKey());
    ASSERT_EQ(4, human_with_volume.getVolume());
}

TEST_F(HumanWithVolumeTest, HumanWithVolume_BasedOnRecord)
{
    HumanWithVolumeRecord human_with_volume_record(IDHolder(ID_HOLDER_CLASS_SETTLEMENT, 22), Key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED), 4);

    HumanWithVolume human_with_volume(human_with_volume_record);

    ASSERT_TRUE(m_model_key == human_with_volume.getKey());
    ASSERT_EQ(4, human_with_volume.getVolume());
}

TEST_F(HumanWithVolumeTest, getKey)
{
    ASSERT_TRUE(m_model_key == m_human_with_volume.getKey());
}

TEST_F(HumanWithVolumeTest, getIDHuman)
{
    ASSERT_TRUE(ID_HUMAN_SOLDIER_HORSEMAN == m_human_with_volume.getIDHuman());
}

TEST_F(HumanWithVolumeTest, getExperience)
{
    ASSERT_TRUE(EXPERIENCE_ADVANCED == m_human_with_volume.getExperience());
}

TEST_F(HumanWithVolumeTest, getVolume)
{
    ASSERT_EQ(4, m_human_with_volume.getVolume());
}
