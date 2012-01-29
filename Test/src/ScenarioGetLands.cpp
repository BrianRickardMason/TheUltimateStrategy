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

class ScenarioGetLandLandsDoNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetLandLandsDoNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandsRequest("Login", "Password"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandLandsDoNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LANDS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandLandsDoNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetLandLandsDoNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_LANDS_LANDS_HAVE_NOT_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioGetLands
    : public IntegrationTest
{
protected:
    ScenarioGetLands()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandsRequest("Login", "Password"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLands, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LANDS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLands, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetLands, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_LANDS_LANDS_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetLands, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetLands, ReturnsObjectWithValidLogin)
{
    ASSERT_STREQ("Login", mCommandReply->getObjects().front().at("login").c_str());
}

TEST_F(ScenarioGetLands, ReturnsObjectWithValidLandName)
{
    ASSERT_STREQ("Land", mCommandReply->getObjects().front().at("land_name").c_str());
}

TEST_F(ScenarioGetLands, ReturnsObjectWithValidWorldName)
{
    ASSERT_STREQ("World", mCommandReply->getObjects().front().at("world_name").c_str());
}

TEST_F(ScenarioGetLands, ReturnsObjectWithValidGrantedField)
{
    ASSERT_STREQ("false", mCommandReply->getObjects().front().at("granted").c_str());
}

class ScenarioGetLandsUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetLandsUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandsRequest("Login", "BadPassword"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandsUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LANDS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandsUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}
