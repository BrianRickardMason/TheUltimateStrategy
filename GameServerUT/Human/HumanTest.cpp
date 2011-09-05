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

#include "../../GameServer/Human/Human.hpp"
#include <gmock/gmock.h>

using namespace GameServer::Human;

/**
 * @brief A test class.
 */
class HumanTest
    : public testing::Test
{
protected:
    /**
     * @brief Constructs a test class.
     */
    HumanTest()
        : m_human(Key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED)),
          m_model_key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED)
    {
    }

    /**
     * @brief A human to be tested.
     */
    Human m_human;

    /**
     * @brief A model key.
     */
    Key m_model_key;
};

TEST_F(HumanTest, Human)
{
    Human human(Key(ID_HUMAN_SOLDIER_HORSEMAN, EXPERIENCE_ADVANCED));

    ASSERT_TRUE(m_model_key == human.getKey());
}

TEST_F(HumanTest, getKey)
{
    ASSERT_TRUE(m_model_key == m_human.getKey());
}

TEST_F(HumanTest, getIDHuman)
{
    ASSERT_TRUE(ID_HUMAN_SOLDIER_HORSEMAN == m_human.getIDHuman());
}

TEST_F(HumanTest, getExperience)
{
    ASSERT_TRUE(EXPERIENCE_ADVANCED == m_human.getExperience());
}
