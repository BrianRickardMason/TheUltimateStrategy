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

class ScenarioGetLandLandDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetLandLandDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandLandDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandLandDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetLand
    : public IntegrationTest
{
protected:
    ScenarioGetLand()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLand, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLand, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetLand, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_LAND_LAND_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetLand, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetLand, ReturnsObjectWithValidLogin)
{
    ASSERT_STREQ("Login", mCommandReply->getObjects().front().at("login").c_str());
}

TEST_F(ScenarioGetLand, ReturnsObjectWithValidLandName)
{
    ASSERT_STREQ("Land", mCommandReply->getObjects().front().at("land_name").c_str());
}

TEST_F(ScenarioGetLand, ReturnsObjectWithValidWorldName)
{
    ASSERT_STREQ("World", mCommandReply->getObjects().front().at("world_name").c_str());
}

TEST_F(ScenarioGetLand, ReturnsObjectWithValidGrantedField)
{
    ASSERT_STREQ("false", mCommandReply->getObjects().front().at("granted").c_str());
}

class ScenarioGetLandUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetLandUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandRequest("Login", "BadPassword", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetLandUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetLandUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandRequest("Login2", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetLandEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetLandEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetLandRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetLandEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetLandEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
