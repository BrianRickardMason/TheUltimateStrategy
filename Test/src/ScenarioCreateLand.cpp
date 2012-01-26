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

class ScenarioCreateLand
    : public IntegrationTest
{
protected:
    ScenarioCreateLand()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLand, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLand, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateLand, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_LAND_LAND_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateLandTwoLandsOfDifferentNames
    : public IntegrationTest
{
protected:
    ScenarioCreateLandTwoLandsOfDifferentNames()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land1"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login2", "Password", "World", "Land2"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandTwoLandsOfDifferentNames, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandTwoLandsOfDifferentNames, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateLandTwoLandsOfDifferentNames, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_LAND_LAND_HAS_BEEN_CREATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateLandTwoLandsOfTheSameNameDifferentUsers
    : public IntegrationTest
{
protected:
    ScenarioCreateLandTwoLandsOfTheSameNameDifferentUsers()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land1"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login2", "Password", "World", "Land1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentUsers, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentUsers, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentUsers, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateLandTwoLandsOfTheSameNameTheSameUser
    : public IntegrationTest
{
protected:
    ScenarioCreateLandTwoLandsOfTheSameNameTheSameUser()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land1"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameTheSameUser, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameTheSameUser, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameTheSameUser, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateLandTwoLandsOfTheSameNameDifferentWorlds
    : public IntegrationTest
{
protected:
    ScenarioCreateLandTwoLandsOfTheSameNameDifferentWorlds()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World1"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World2"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World1", "Epoch1"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World2", "Epoch2"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World1"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World2"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World1", "Land1"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login2", "Password", "World2", "Land1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentWorlds, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentWorlds, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioCreateLandTwoLandsOfTheSameNameDifferentWorlds, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::CREATE_LAND_ANOTHER_LAND_OF_THE_GIVEN_NAME_EXISTS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioCreateLandUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioCreateLandUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "BadPassword", "World", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioCreateLandEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioCreateLandEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioCreateLandEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_CREATE_LAND_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioCreateLandEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
