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

class ScenarioGetResourcesSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetResourcesUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetResourcesMaxResourcesExist
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesMaxResourcesExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_RESOURCES_RESOURCES_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsTwoObjects)
{
    ASSERT_EQ(6, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsFirstObjectWithValidResourceName)
{
    ASSERT_STREQ("coal", mCommandReply->getObjects().front().at("resourcename").c_str());
}

TEST_F(ScenarioGetResourcesMaxResourcesExist, ReturnsFirstObjectWithValidVolume)
{
    ASSERT_STREQ("1000", mCommandReply->getObjects().front().at("volume").c_str());
}

// TODO: Add the rest of the verification.

// TODO: ScenarioGetResourcesManyResourcesExist
// TODO: ScenarioGetResourcesOneResourceExist

class ScenarioGetResourcesZeroResourcesExist
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesZeroResourcesExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement2"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesZeroResourcesExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesZeroResourcesExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetResourcesZeroResourcesExist, ReturnsProperMessage)
{
    // TODO: Add GET_RESOURCES_RESOURCES_HAVE_NOT_BEEN_GOT
    ASSERT_STREQ(Game::GET_RESOURCES_UNEXPECTED_ERROR.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetResourcesZeroResourcesExist, ReturnsZeroObjects)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetResourcesUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetResourcesEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetResourcesEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetResourcesRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetResourcesEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_RESOURCES_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetResourcesEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
