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

class ScenarioBuildBuildingSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioBuildBuildingUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioBuildBuildingTooManyBuildings
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingTooManyBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "101"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingTooManyBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingTooManyBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioBuildBuildingTooManyBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::BUILD_BUILDING_NOT_ENOUGH_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioBuildBuildingMaxBuildings
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingMaxBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "100"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingMaxBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingMaxBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioBuildBuildingMaxBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::BUILD_BUILDING_BUILDING_HAS_BEEN_BUILT.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioBuildBuildingManyBuildings
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingManyBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "63"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingManyBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingManyBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioBuildBuildingManyBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::BUILD_BUILDING_BUILDING_HAS_BEEN_BUILT.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioBuildBuildingOneBuilding
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingOneBuilding()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingOneBuilding, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingOneBuilding, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioBuildBuildingOneBuilding, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::BUILD_BUILDING_BUILDING_HAS_BEEN_BUILT.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioBuildBuildingZeroBuildings
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingZeroBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingZeroBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingZeroBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioBuildBuildingZeroBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::BUILD_BUILDING_TRYING_TO_BUILD_ZERO_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioBuildBuildingUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioBuildBuildingEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioBuildBuildingEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioBuildBuildingEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_BUILD_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioBuildBuildingEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
