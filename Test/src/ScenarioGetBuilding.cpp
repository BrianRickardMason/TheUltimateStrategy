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

class ScenarioGetBuildingSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetBuildingUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login1", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetBuildingManyBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingManyBuildingsExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularsawmill", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_BUILDING_BUILDING_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsObjectWithValidBuildingClass)
{
    ASSERT_STREQ("regular", mCommandReply->getObjects().front().at("buildingclass").c_str());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsObjectWithValidBuildingName)
{
    ASSERT_STREQ("farm", mCommandReply->getObjects().front().at("buildingname").c_str());
}

TEST_F(ScenarioGetBuildingManyBuildingsExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("1", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetBuildingOneBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingOneBuildingsExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_BUILDING_BUILDING_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsObjectWithValidBuildingClass)
{
    ASSERT_STREQ("regular", mCommandReply->getObjects().front().at("buildingclass").c_str());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsObjectWithValidBuildingName)
{
    ASSERT_STREQ("farm", mCommandReply->getObjects().front().at("buildingname").c_str());
}

TEST_F(ScenarioGetBuildingOneBuildingsExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("1", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetBuildingZeroBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingZeroBuildingsExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingZeroBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingZeroBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingZeroBuildingsExist, ReturnsProperMessage)
{
    // TODO: Add GET_BUILDING_BUILDING_HAS_NOT_BEEN_GOT
    ASSERT_STREQ(Game::GET_BUILDING_UNEXPECTED_ERROR.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingZeroBuildingsExist, ReturnsOneObject)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetBuildingUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetBuildingEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
