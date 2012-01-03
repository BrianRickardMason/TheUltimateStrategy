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

#include <Server/Network/XmlRPCServer/Context.hpp>
#include <Game/GameServer/Resource/Helpers.hpp>
#include <Game/GameServer/Resource/Key.hpp>
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Resource;
using namespace boost;
using namespace std;

class HelpersTest
    : public testing::Test
{
protected:
    /**
     * @brief Ctor.
     */
    HelpersTest()
        : m_context(new Context)
    {
    }

    /**
     * @brief The context of the server.
     */
    IContextShrPtr m_context;
};


TEST_F(HelpersTest, AreEqualReturnsTrueTwoEmptyMaps)
{
    ResourceWithVolumeMap map_1, map_2;

    ASSERT_TRUE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTheFirstMapEmptyTheSecondMapNonEmpty)
{
    ResourceWithVolumeMap map_1, map_2;

    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTheFirstMapNonEmptyTheSecondMapEmpty)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTwoMapsOfDifferentSizesTheSecondMapIsBigger)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 200)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTwoMapsOfDifferentSizesTheFirstMapIsBigger)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsTrueTwoMapsOfSameSizesBothMapsHaveEqualResources)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_TRUE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTwoMapsOfSameSizesTheFirstMapHasMoreResources)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 201)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, AreEqualReturnsFalseTwoMapsOfSameSizesTheSecondMapHasMoreResources)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 201)));

    ASSERT_FALSE(areEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsTrueTwoEmptyMaps)
{
    ResourceWithVolumeMap map_1, map_2;

    ASSERT_TRUE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsFalseTheFirstMapEmptyTheSecondMapNonEmpty)
{
    ResourceWithVolumeMap map_1, map_2;

    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_FALSE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsTrueTheFirstMapNonEmptyTheSecondMapEmpty)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_TRUE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsTrueOnComparingTwoEqualNonEmptyMaps)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));

    ASSERT_TRUE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsTrueTheFirstMapIsGreater)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 199)));

    ASSERT_TRUE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsTrueTheFirstMapIsGreaterAndHasTwoElements)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 200)));

    ASSERT_TRUE(isFirstGreaterOrEqual(map_1, map_2));
}

TEST_F(HelpersTest, IsFirstGreaterThanEqualReturnsFalseTheSecondMapHasAnElementNotPresentInTheFirstMap)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(m_context, KEY_RESOURCE_GOLD, 200)));

    ASSERT_FALSE(isFirstGreaterOrEqual(map_1, map_2));
}
