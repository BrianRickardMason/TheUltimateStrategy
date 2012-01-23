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

#include <Game/GameServer/Common/Constants.hpp>
#include <Language/Interface/RequestBuilder.hpp>
#include <Test/include/Client.hpp>
#include <Test/include/IntegrationTest.hpp>

class UserCommandScenarioCreateUser
    : public IntegrationTest
{
protected:
    UserCommandScenarioCreateUser()
    {
        Language::Command::Handle commandRequest = mRequestBuilder.buildCreateUserRequest("Login", "Password");
        mCommandReply = mClient.send(commandRequest);
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(UserCommandScenarioCreateUser, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_USER_REPLY, mCommandReply->getID());
}

TEST_F(UserCommandScenarioCreateUser, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(UserCommandScenarioCreateUser, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_USER_USER_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class UserCommandScenarioCreateTwoUsersOfTheSameLogin
    : public IntegrationTest
{
protected:
    UserCommandScenarioCreateTwoUsersOfTheSameLogin()
    {
        Language::Command::Handle commandRequest = mRequestBuilder.buildCreateUserRequest("Login", "Password");
        mClient.send(commandRequest);
        mCommandReply = mClient.send(commandRequest);
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(UserCommandScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_USER_REPLY, mCommandReply->getID());
}

TEST_F(UserCommandScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(UserCommandScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_USER_USER_DOES_EXIST.c_str(), mCommandReply->getMessage().c_str());
}
