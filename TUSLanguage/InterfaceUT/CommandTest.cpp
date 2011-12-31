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

#include <TUSLanguage/Interface/Command.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

class CommandTest
    : public ::testing::Test
{
protected:
    /**
     * @brief The command to be tested.
     */
    TUSLanguage::Command m_command;
};

TEST_F(CommandTest, CtorDoesNotThrow)
{
    ASSERT_NO_THROW(TUSLanguage::Command::SingleHandle command(new TUSLanguage::Command));
}

TEST_F(CommandTest, GetIDReturnsProperInitialValue)
{
    ASSERT_EQ(0, m_command.getID());
}

TEST_F(CommandTest, SetIDSetsProperValue)
{
    m_command.setID(22);
    ASSERT_EQ(22, m_command.getID());
}

TEST_F(CommandTest, GetLoginReturnsProperInitialValue)
{
    ASSERT_STREQ("", m_command.getLogin().c_str());
}

TEST_F(CommandTest, SetLoginSetsProperValue)
{
    m_command.setLogin("Login");
    ASSERT_STREQ("Login", m_command.getLogin().c_str());
}

TEST_F(CommandTest, GetPasswordReturnsProperInitialValue)
{
    ASSERT_STREQ("", m_command.getPassword().c_str());
}

TEST_F(CommandTest, SetPasswordSetsProperValue)
{
    m_command.setPassword("Password");
    ASSERT_STREQ("Password", m_command.getPassword().c_str());
}

TEST_F(CommandTest, GetParamThrowsIfParamDoesNotExist)
{
    ASSERT_THROW(m_command.getParam("non_existent"), std::out_of_range);
}

TEST_F(CommandTest, GetParamReturnsPropverValueOfParam)
{
    m_command.setParam("existent", "value");
    ASSERT_STREQ("value", m_command.getParam("existent").c_str());
}

TEST_F(CommandTest, GetCodeReturnsProperInitialValue)
{
    ASSERT_EQ(0, m_command.getCode());
}

TEST_F(CommandTest, SetCodeSetsProperValue)
{
    m_command.setCode(44);
    ASSERT_EQ(44, m_command.getCode());
}

TEST_F(CommandTest, GetMessageReturnsProperInitialValue)
{
    ASSERT_STREQ("", m_command.getMessage().c_str());
}

TEST_F(CommandTest, SetMessageSetsProperValue)
{
    m_command.setMessage("Message");
    ASSERT_STREQ("Message", m_command.getMessage().c_str());
}

TEST_F(CommandTest, GetObjectsReturnsProperInitialValue)
{
    ASSERT_TRUE(m_command.getObjects().empty());
}

TEST_F(CommandTest, GetObjectsReturnsProperObjects)
{
    TUSLanguage::ICommand::Object land;
    land.insert(std::make_pair("login", "Login"));
    land.insert(std::make_pair("world_name", "World"));
    land.insert(std::make_pair("land_name", "Land"));
    land.insert(std::make_pair("granted", "false"));
    m_command.addObject(land);
    TUSLanguage::ICommand::Objects objects = m_command.getObjects();
    for (TUSLanguage::ICommand::Objects::const_iterator it = objects.begin(); it != objects.end(); ++it)
    {
        ASSERT_STREQ("Login", (*it).at("login").c_str());
        ASSERT_STREQ("World", (*it).at("world_name").c_str());
        ASSERT_STREQ("Land", (*it).at("land_name").c_str());
        ASSERT_STREQ("false", (*it).at("granted").c_str());
    }
}

TEST_F(CommandTest, AddObjectInsertsObjectProperly)
{
    TUSLanguage::ICommand::Object land;
    land.insert(std::make_pair("login", "Login"));
    land.insert(std::make_pair("world_name", "World"));
    land.insert(std::make_pair("land_name", "Land"));
    land.insert(std::make_pair("granted", "false"));
    m_command.addObject(land);
    ASSERT_FALSE(m_command.getObjects().empty());
}
