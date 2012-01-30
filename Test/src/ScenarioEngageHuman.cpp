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

class ScenarioEngageHumanSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioEngageHumanUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

// TODO: ScenarioEngageHumanNotEnoughJobless.

class ScenarioEngageHumanNotEnoughResources
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanNotEnoughResources()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "60"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanNotEnoughResources, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanNotEnoughResources, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanNotEnoughResources, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_NOT_ENOUGH_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanNotEnoughBuildings
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanNotEnoughBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfarmernovice", "11"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanNotEnoughBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanNotEnoughBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanNotEnoughBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_NOT_ENOUGH_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanMaxHumans
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanMaxHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "100"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanMaxHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanMaxHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanMaxHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_HUMAN_HAS_BEEN_ENGAGED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanManyHumans
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanManyHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "63"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanManyHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanManyHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanManyHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_HUMAN_HAS_BEEN_ENGAGED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanOneHuman
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanOneHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanOneHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanOneHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanOneHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_HUMAN_HAS_BEEN_ENGAGED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanZeroHumans
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanZeroHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanZeroHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanZeroHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanZeroHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_TRYING_TO_ENGAGE_ZERO_HUMANS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanNotEngageable
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanNotEngageable()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanNotEngageable, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanNotEngageable, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioEngageHumanNotEngageable, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ENGAGE_HUMAN_HUMAN_IS_NOT_ENGAGEABLE.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioEngageHumanUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioEngageHumanEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioEngageHumanEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioEngageHumanEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ENGAGE_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioEngageHumanEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
