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

class ScenarioGetHumansSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumansSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetHumansUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetHumansUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetHumansManyHumansExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumansManyHumansExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "10"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_HUMANS_HUMANS_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsTwoObjects)
{
    ASSERT_EQ(2, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsFirstObjectWithValidHumanClass)
{
    ASSERT_STREQ("worker", mCommandReply->getObjects().front().at("humanclass").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsFirstObjectWithValidHumanName)
{
    ASSERT_STREQ("fisherman", mCommandReply->getObjects().front().at("humanname").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsFirstObjectWithValidExperience)
{
    ASSERT_STREQ("novice", mCommandReply->getObjects().front().at("experience").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsFirstObjectWithValidVolume)
{
    ASSERT_STREQ("10", mCommandReply->getObjects().front().at("volume").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsSecondObjectWithValidHumanClass)
{
    ASSERT_STREQ("worker", mCommandReply->getObjects().back().at("humanclass").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsSecondObjectWithValidHumanName)
{
    ASSERT_STREQ("jobless", mCommandReply->getObjects().back().at("humanname").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsSecondObjectWithValidExperience)
{
    ASSERT_STREQ("novice", mCommandReply->getObjects().back().at("experience").c_str());
}

TEST_F(ScenarioGetHumansManyHumansExist, ReturnsSecondObjectWithValidVolume)
{
    ASSERT_STREQ("990", mCommandReply->getObjects().back().at("volume").c_str());
}

class ScenarioGetHumansOneHumanExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumansOneHumanExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_HUMANS_HUMANS_HAVE_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsObjectWithValidHumanClass)
{
    ASSERT_STREQ("worker", mCommandReply->getObjects().front().at("humanclass").c_str());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsObjectWithValidHumanName)
{
    ASSERT_STREQ("jobless", mCommandReply->getObjects().front().at("humanname").c_str());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsObjectWithValidExperience)
{
    ASSERT_STREQ("novice", mCommandReply->getObjects().front().at("experience").c_str());
}

TEST_F(ScenarioGetHumansOneHumanExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("1000", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetHumansZeroHumansExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumansZeroHumansExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement2"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansZeroHumansExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansZeroHumansExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumansZeroHumansExist, ReturnsProperMessage)
{
    // TODO: Add GET_HUMANS_HUMANS_HAVE_NOT_BEEN_GOT
    ASSERT_STREQ(Game::GET_HUMANS_UNEXPECTED_ERROR.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumansZeroHumansExist, ReturnsZeroObjects)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetHumansUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetHumansUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetHumansEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetHumansEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumansRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumansEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMANS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumansEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
