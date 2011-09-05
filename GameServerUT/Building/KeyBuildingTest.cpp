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

#include "../../GameServer/Building/Key.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Building;

TEST(KeyBuildingTest, Key_ConstructorsAreEquivalent)
{
    IDBuilding id_building(ID_BUILDING_DEFENSIVE_BARBICAN);

    Key key_1(id_building);
    Key key_2(1000101);

    ASSERT_TRUE(key_1 == key_2);
}

TEST(KeyBuildingTest, toHash_BasedOnParameters)
{
    IDBuilding id_building (ID_BUILDING_DEFENSIVE_BARBICAN);

    Key key(id_building);

    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_BUILDING * 1000000 + 101 == key.toHash());
}

TEST(KeyBuildingTest, toHash_BasedOnHash)
{
    Key key(1000101);

    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_BUILDING * 1000000 + 101 == key.toHash());
}

TEST(KeyBuildingTest, toHash_MaxValues)
{
    IDBuilding id_building(2, 12);

    Key key(id_building);

    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_BUILDING * 1000000 + 212 == key.toHash());
}
