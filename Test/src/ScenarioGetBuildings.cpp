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

class ScenarioGetBuildingsSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetBuildingsUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsUnauthorized()
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
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetBuildingsManyBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsManyBuildingsExist()
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
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularsawmill", "2"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_BUILDINGS_BUILDINGS_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsTwoObjects)
{
    ASSERT_EQ(2, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsFirstObjectWithValidBuildingClass)
{
    ASSERT_STREQ("regular", mCommandReply->getObjects().front().at("buildingclass").c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsFirstObjectWithValidBuildingName)
{
    ASSERT_STREQ("farm", mCommandReply->getObjects().front().at("buildingname").c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsFirstObjectWithValidVolume)
{
    ASSERT_STREQ("1", mCommandReply->getObjects().front().at("volume").c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsSecondObjectWithValidBuildingClass)
{
    ASSERT_STREQ("regular", mCommandReply->getObjects().back().at("buildingclass").c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsSecondObjectWithValidBuildingName)
{
    ASSERT_STREQ("sawmill", mCommandReply->getObjects().back().at("buildingname").c_str());
}

TEST_F(ScenarioGetBuildingsManyBuildingsExist, ReturnsSecondObjectWithValidVolume)
{
    ASSERT_STREQ("2", mCommandReply->getObjects().back().at("volume").c_str());
}

class ScenarioGetBuildingsOneBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsOneBuildingsExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_BUILDINGS_BUILDINGS_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsObjectWithValidBuildingClass)
{
    ASSERT_STREQ("regular", mCommandReply->getObjects().front().at("buildingclass").c_str());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsObjectWithValidBuildingName)
{
    ASSERT_STREQ("farm", mCommandReply->getObjects().front().at("buildingname").c_str());
}

TEST_F(ScenarioGetBuildingsOneBuildingsExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("1", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetBuildingsZeroBuildingsExist
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsZeroBuildingsExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsZeroBuildingsExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsZeroBuildingsExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetBuildingsZeroBuildingsExist, ReturnsProperMessage)
{
    // TODO: Add GET_BUILDINGS_BUILDINGS_HAVE_NOT_BEEN_GOT
    ASSERT_STREQ(Game::GET_BUILDINGS_UNEXPECTED_ERROR.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetBuildingsZeroBuildingsExist, ReturnsOneObject)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetBuildingsUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetBuildingsEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetBuildingsEpochIsNotActive()
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
        mCommandReply = mClient.send(mRequestBuilder.buildGetBuildingsRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetBuildingsEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_BUILDINGS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetBuildingsEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
