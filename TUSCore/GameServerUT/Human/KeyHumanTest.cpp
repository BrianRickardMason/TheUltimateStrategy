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

#include "../../GameServer/Human/Key.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Human;

/**
 * Unit tests of: Key::Key.
 */
TEST(KeyHumanTest, Key_ConstructorsAreEquivalent)
{
    // Test commands.
    Key key_1(ID_HUMAN_SOLDIER_ARCHER, EXPERIENCE_NOVICE);
    Key key_2(1010101);

    // Test assertions.
    ASSERT_TRUE(key_1 == key_2);
}

/**
 * Unit tests of: Key::toHash.
 */
TEST(KeyHumanTest, toHash_BasedOnParameters)
{
    // Test commands.
    Key key(ID_HUMAN_SOLDIER_ARCHER, EXPERIENCE_NOVICE);

    // Test assertions.
    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_HUMAN * 1000000 + 10101 == key.toHash());
}

TEST(KeyHumanTest, toHash_BasedOnHash)
{
    // Preconditions.
    Key key(1010101);

    // Test assertions.
    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_HUMAN * 1000000 + 10101 == key.toHash());
}

TEST(KeyHumanTest, toHash_MaxValues)
{
    IDHuman id_human(4, 14);
    Experience experience(2);

    Key key(id_human, experience);

    ASSERT_TRUE(GameServer::Common::KEY_HASH_MAGIC_VALUE_HUMAN * 1000000 + 41402 == key.toHash());
}
