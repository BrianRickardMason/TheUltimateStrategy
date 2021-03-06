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

class ScenarioCreateUser
    : public IntegrationTest
{
protected:
    ScenarioCreateUser()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateUser, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_USER_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateUser, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateUser, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_USER_USER_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateTwoUsersOfDifferentLogins
    : public IntegrationTest
{
protected:
    ScenarioCreateTwoUsersOfDifferentLogins()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password1"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password2"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateTwoUsersOfDifferentLogins, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_USER_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateTwoUsersOfDifferentLogins, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateTwoUsersOfDifferentLogins, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_USER_USER_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateTwoUsersOfTheSameLogin
    : public IntegrationTest
{
protected:
    ScenarioCreateTwoUsersOfTheSameLogin()
    {
        Language::Command::Handle request = mRequestBuilder.buildCreateUserRequest("Login", "Password");
        mClient.send(request);
        mCommandReply = mClient.send(request);
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_USER_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateTwoUsersOfTheSameLogin, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_USER_USER_DOES_EXIST.c_str(), mCommandReply->getMessage().c_str());
}
