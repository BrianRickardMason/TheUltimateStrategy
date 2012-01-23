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

class ScenarioCreateWorld
    : public IntegrationTest
{
protected:
    ScenarioCreateWorld()
    {
        Language::Command::Handle request = mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World");
        mCommandReply = mClient.send(request);
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateWorld, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_WORLD_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateWorld, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateWorld, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_WORLD_WORLD_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateWorldNonModeratorFilteredOut
    : public IntegrationTest
{
protected:
    ScenarioCreateWorldNonModeratorFilteredOut()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateWorldRequest("Login", "Password", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateWorldNonModeratorFilteredOut, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_WORLD_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateWorldNonModeratorFilteredOut, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_NON_MODERATOR_FILTERED_OUT, mCommandReply->getCode());
}

class ScenarioCreateWorldInvalidPasswordOfTheModerator
    : public IntegrationTest
{
protected:
    ScenarioCreateWorldInvalidPasswordOfTheModerator()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpasswrong", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateWorldInvalidPasswordOfTheModerator, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_WORLD_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateWorldInvalidPasswordOfTheModerator, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}
