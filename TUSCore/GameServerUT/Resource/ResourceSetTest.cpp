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

#include "../../GameServer/Resource/Key.hpp"
#include "../../GameServer/Resource/ResourceSet.hpp"
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace GameServer::Resource;
using namespace boost;
using namespace std;

/**
 * @brief A test class.
 *
 * TODO: Refactor it!
 * TODO: Consider if ResourceSet should not be asserted (if contains all the resources in the map).
 */
class ResourceSetTest
    : public testing::Test
{
protected:
    /**
     * @brief Creates a test class.
     */
    ResourceSetTest()
    {
    }

    /**
     * @brief Compares the resource with expected values.
     *
     * @param a_resource The resource to be compared.
     * @param a_key      An expected key of the resource.
     * @param a_volume   An expected volume of the resource.
     */
    void compareResource(
        ResourceWithVolumeShrPtr         a_resource,
        string                   const & a_key,
        Volume                   const & a_volume
    )
    {
        ASSERT_TRUE(a_key == a_resource->getResource()->getKey());
        ASSERT_EQ(a_volume, a_resource->getVolume());
    }
};

/**
 * Unit tests of: ResourceSet::ResourceSet.
 */
TEST_F(ResourceSetTest, ResourceSet)
{
    ResourceSet resource_set;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

/**
 * Unit tests of: ResourceSet::ResourceSet(map).
 */
TEST_F(ResourceSetTest, ResourceSet_ZeroResources_ByValue)
{
    ResourceWithVolumeMap map;

    ResourceSet resource_set(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, ResourceSet_ZeroResources_ByPointer)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    ResourceSet resource_set(*map);

    delete(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, ResourceSet_OneResource_ByValue)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));

    ResourceSet resource_set(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, ResourceSet_OneResource_ByPointer)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    map->insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));

    ResourceSet resource_set(*map);

    delete(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, ResourceSet_ManyResources_ByValue)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

TEST_F(ResourceSetTest, ResourceSet_ManyResources_ByPointer)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    map->insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map->insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map->insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map->insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map->insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map->insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map->insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(*map);

    delete(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

/**
 * Unit tests of ResourceSet::CopyCtor.
 */
TEST_F(ResourceSetTest, ResourceSet_CopyCtor)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    map->insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map->insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map->insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map->insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map->insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map->insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map->insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet * resource_set_1 = new ResourceSet(*map);

    delete(map);

    ResourceSet resource_set_2 = *resource_set_1;

    delete(resource_set_1);

    ResourceWithVolumeMap resource_map = resource_set_2.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

/**
 * Unit tests of ResourceSet::operator +.
 */
TEST_F(ResourceSetTest, Operator_Addition_DifferentSets)
{
    ResourceWithVolumeMap map_1;
    ResourceWithVolumeMap map_2;

    map_1.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_1.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_1.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_1.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_1.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    map_2.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 10)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 20)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 30)));
    map_2.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 40)));
    map_2.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 50)));
    map_2.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 60)));
    map_2.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 70)));

    ResourceSet resource_set_1(map_1);
    ResourceSet resource_set_2(map_2);
    ResourceSet resource_set_3;

    resource_set_3 = resource_set_1 + resource_set_2;

    ResourceWithVolumeMap resource_map = resource_set_3.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 110);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 220);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 330);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 440);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 550);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 660);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 770);
}

TEST_F(ResourceSetTest, Operator_Addition_TheSameSetWithAssignment)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    resource_set = resource_set + resource_set;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 600);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
}

/**
 * Unit tests of ResourceSet::operator *.
 */
TEST_F(ResourceSetTest, Operator_Multiplication_By0)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set_1(map);
    ResourceSet resource_set_2;

    resource_set_2 = resource_set_1 * 0;

    ResourceWithVolumeMap resource_map = resource_set_2.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, Operator_Multiplication_By1)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set_1(map);
    ResourceSet resource_set_2;

    resource_set_2 = resource_set_1 * 1;

    ResourceWithVolumeMap resource_map = resource_set_2.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

TEST_F(ResourceSetTest, Operator_Multiplication_By2)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set_1(map);
    ResourceSet resource_set_2;

    resource_set_2 = resource_set_1 * 2;

    ResourceWithVolumeMap resource_map = resource_set_2.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 600);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
}

/**
 * Unit tests of: ResourceSet::operator ==.
 */
TEST_F(ResourceSetTest, Operator_Relational_Comparison)
{
    ResourceWithVolumeMap resource_map_1,
                          resource_map_2,
                          resource_map_3,
                          resource_map_4;

    ResourceWithVolumeShrPtr resource_with_volume_coal   = make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 10),
                             resource_with_volume_food   = make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 20),
                             resource_with_volume_gold   = make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 30),
                             resource_with_volume_iron   = make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 40),
                             resource_with_volume_mana   = make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 50),
                             resource_with_volume_rock   = make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 60),
                             resource_with_volume_wood_1 = make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 70),
                             resource_with_volume_wood_2 = make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 80);

    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_COAL, resource_with_volume_coal  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_FOOD, resource_with_volume_food  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_GOLD, resource_with_volume_gold  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_IRON, resource_with_volume_iron  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_MANA, resource_with_volume_mana  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_ROCK, resource_with_volume_rock  ));
    resource_map_1.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_WOOD, resource_with_volume_wood_1));

    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_COAL, resource_with_volume_coal  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_FOOD, resource_with_volume_food  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_GOLD, resource_with_volume_gold  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_IRON, resource_with_volume_iron  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_MANA, resource_with_volume_mana  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_ROCK, resource_with_volume_rock  ));
    resource_map_2.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_WOOD, resource_with_volume_wood_2));

    resource_map_3.insert(make_pair<string, ResourceWithVolumeShrPtr>(KEY_RESOURCE_IRON, resource_with_volume_iron));

    ResourceSet resource_set_1(resource_map_1);
    ResourceSet resource_set_2(resource_map_1);
    ResourceSet resource_set_3(resource_map_2);
    ResourceSet resource_set_4(resource_map_3);
    ResourceSet resource_set_5(resource_map_4);

    ASSERT_TRUE (resource_set_1 == resource_set_1);
    ASSERT_TRUE (resource_set_1 == resource_set_2);
    ASSERT_FALSE(resource_set_1 == resource_set_3);
    ASSERT_FALSE(resource_set_1 == resource_set_4);
    ASSERT_FALSE(resource_set_1 == resource_set_5);

    ASSERT_TRUE (resource_set_2 == resource_set_2);
    ASSERT_FALSE(resource_set_2 == resource_set_3);
    ASSERT_FALSE(resource_set_2 == resource_set_4);
    ASSERT_FALSE(resource_set_2 == resource_set_5);

    ASSERT_TRUE (resource_set_3 == resource_set_3);
    ASSERT_FALSE(resource_set_3 == resource_set_4);
    ASSERT_FALSE(resource_set_3 == resource_set_5);

    ASSERT_TRUE (resource_set_4 == resource_set_4);
    ASSERT_FALSE(resource_set_4 == resource_set_5);

    ASSERT_TRUE (resource_set_5 == resource_set_5);
}

/**
 * Unit tests of: ResourceSet::operator >=.
 */
TEST_F(ResourceSetTest, Operator_Relational_GreaterThanEqual_ResourceSetEmpty)
{
    ResourceWithVolumeMap map_1, map_2;

    map_2.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_2.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_2.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_2.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_2.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set_1(map_1), resource_set_2(map_2);

    ASSERT_FALSE(resource_set_1 >= resource_set_2);
}

TEST_F(ResourceSetTest, Operator_Relational_GreaterThanEqual_ResourceSetEqualsOtherResourceSet)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set_1(map), resource_set_2(map);

    ASSERT_TRUE(resource_set_1 >= resource_set_2);
}

TEST_F(ResourceSetTest, Operator_Relational_GreaterThanEqual_ResourceSetLowerThanOtherResourceSet)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_1.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_1.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_1.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_1.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    map_2.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_2.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_2.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_2.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_2.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 701)));

    ResourceSet resource_set_1(map_1), resource_set_2(map_2);

    ASSERT_FALSE(resource_set_1 >= resource_set_2);
}

TEST_F(ResourceSetTest, Operator_Relational_GreaterThanEqual_ResourceSetGreaterThanOtherResourceSet)
{
    ResourceWithVolumeMap map_1, map_2;

    map_1.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_1.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_1.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_1.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_1.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    map_2.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 10)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 20)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 30)));
    map_2.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 40)));
    map_2.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 50)));
    map_2.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 60)));
    map_2.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 70)));

    ResourceSet resource_set_1(map_1), resource_set_2(map_2);

    ASSERT_TRUE(resource_set_1 >= resource_set_2);
}

/**
 * Unit tests of ResourceSet::operator +=.
 */
TEST_F(ResourceSetTest, Operator_CompoundAssignmentAddition_TheSameSet)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    resource_set += resource_set;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 600);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
}

TEST_F(ResourceSetTest, Operator_CompoundAssignmentAddition_TwoDifferentSets)
{
    ResourceWithVolumeMap map_1;
    ResourceWithVolumeMap map_2;

    map_1.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map_1.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map_1.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map_1.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map_1.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map_1.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map_1.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    map_2.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 10)));
    map_2.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 20)));
    map_2.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 30)));
    map_2.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 40)));
    map_2.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 50)));
    map_2.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 60)));
    map_2.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 70)));

    ResourceSet resource_set_1(map_1);
    ResourceSet resource_set_2(map_2);

    resource_set_1 += resource_set_2;

    ResourceWithVolumeMap resource_map = resource_set_1.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 110);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 220);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 330);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 440);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 550);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 660);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 770);
}

/**
 * Unit tests of ResourceSet::operator *=.
 */
TEST_F(ResourceSetTest, Operator_CompoundAssignmentMultiplication_By0)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    resource_set *= 0;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 0);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, Operator_CompoundAssignmentMultiplication_By1)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    resource_set *= 1;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

TEST_F(ResourceSetTest, Operator_CompoundAssignmentMultiplication_By2)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    resource_set *= 2;

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 200);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 400);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 600);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 800);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 1000);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 1200);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 1400);
}

/**
 * Unit tests of: ResourceSet::getMap.
 */
TEST_F(ResourceSetTest, getMap_OneResource_ByValue)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));

    ResourceSet resource_set(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, getMap_OneResource_ByPointer)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    map->insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));

    ResourceSet resource_set(*map);

    delete(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 0);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 0);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 0);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 0);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 0);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 0);
}

TEST_F(ResourceSetTest, getMap_ManyResources_ByValue)
{
    ResourceWithVolumeMap map;

    map.insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map.insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map.insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map.insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map.insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map.insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map.insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}

TEST_F(ResourceSetTest, getMap_ManyResources_ByPointer)
{
    ResourceWithVolumeMap * map = new ResourceWithVolumeMap;

    map->insert(make_pair(KEY_RESOURCE_COAL, make_shared<ResourceWithVolume>(KEY_RESOURCE_COAL, 100)));
    map->insert(make_pair(KEY_RESOURCE_FOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_FOOD, 200)));
    map->insert(make_pair(KEY_RESOURCE_GOLD, make_shared<ResourceWithVolume>(KEY_RESOURCE_GOLD, 300)));
    map->insert(make_pair(KEY_RESOURCE_IRON, make_shared<ResourceWithVolume>(KEY_RESOURCE_IRON, 400)));
    map->insert(make_pair(KEY_RESOURCE_MANA, make_shared<ResourceWithVolume>(KEY_RESOURCE_MANA, 500)));
    map->insert(make_pair(KEY_RESOURCE_ROCK, make_shared<ResourceWithVolume>(KEY_RESOURCE_ROCK, 600)));
    map->insert(make_pair(KEY_RESOURCE_WOOD, make_shared<ResourceWithVolume>(KEY_RESOURCE_WOOD, 700)));

    ResourceSet resource_set(*map);

    delete(map);

    ResourceWithVolumeMap resource_map = resource_set.getMap();

    ASSERT_FALSE(resource_map.empty());

    // TODO: Get this assertion back.
    // ASSERT_EQ(RESOURCE_VEC.size(), resource_map.size());

    compareResource(resource_map[KEY_RESOURCE_COAL], KEY_RESOURCE_COAL, 100);
    compareResource(resource_map[KEY_RESOURCE_FOOD], KEY_RESOURCE_FOOD, 200);
    compareResource(resource_map[KEY_RESOURCE_GOLD], KEY_RESOURCE_GOLD, 300);
    compareResource(resource_map[KEY_RESOURCE_IRON], KEY_RESOURCE_IRON, 400);
    compareResource(resource_map[KEY_RESOURCE_MANA], KEY_RESOURCE_MANA, 500);
    compareResource(resource_map[KEY_RESOURCE_ROCK], KEY_RESOURCE_ROCK, 600);
    compareResource(resource_map[KEY_RESOURCE_WOOD], KEY_RESOURCE_WOOD, 700);
}
