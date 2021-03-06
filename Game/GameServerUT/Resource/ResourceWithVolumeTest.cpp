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

#include <Game/GameServer/Resource/Key.hpp>
#include <Game/GameServer/Resource/ResourceWithVolume.hpp>
#include <Server/include/Context.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Common;
using namespace GameServer::Resource;
using namespace std;

/**
 * @brief A test class.
 */
class ResourceWithVolumeTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    ResourceWithVolumeTest()
        : m_context(new Server::Context),
          m_resource_with_volume(m_context, KEY_RESOURCE_COAL, 2),
          m_model_key(KEY_RESOURCE_COAL)
    {
    }

    Server::IContextShrPtr m_context;

    /**
     * @brief A resource with volume to be tested.
     */
    ResourceWithVolume m_resource_with_volume;

    /**
     * @brief A model key.
     */
    string m_model_key;
};

TEST_F(ResourceWithVolumeTest, ResourceWithVolume_BasedOnArguments)
{
    ResourceWithVolume resource_with_volume(m_context, KEY_RESOURCE_COAL, 2);

    ASSERT_TRUE(m_model_key == resource_with_volume.getResource()->getKey());
    ASSERT_EQ(2, resource_with_volume.getVolume());
}

TEST_F(ResourceWithVolumeTest, ResourceWithVolume_BasedOnRecord)
{
    ResourceWithVolumeRecord resource_with_volume_record(IDHolder(ID_HOLDER_CLASS_SETTLEMENT, "Settlement"), KEY_RESOURCE_COAL, 2);

    ResourceWithVolume resource_with_volume(m_context, resource_with_volume_record);

    ASSERT_TRUE(m_model_key == resource_with_volume.getResource()->getKey());
    ASSERT_EQ(2, resource_with_volume.getVolume());
}

TEST_F(ResourceWithVolumeTest, GetResourceResourceIsNotEmpty)
{
    ASSERT_TRUE(m_resource_with_volume.getResource());
}

TEST_F(ResourceWithVolumeTest, getVolume)
{
    ASSERT_EQ(2, m_resource_with_volume.getVolume());
}
