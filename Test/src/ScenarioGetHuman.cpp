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

class ScenarioGetHumanSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumanSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetHumanUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetHumanUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetHumanManyHumansExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumanManyHumansExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "10"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_HUMAN_HUMAN_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsObjectWithValidHumanClass)
{
    ASSERT_STREQ("worker", mCommandReply->getObjects().front().at("humanclass").c_str());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsObjectWithValidHumanName)
{
    ASSERT_STREQ("fisherman", mCommandReply->getObjects().front().at("humanname").c_str());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsObjectWithValidExperience)
{
    ASSERT_STREQ("novice", mCommandReply->getObjects().front().at("experience").c_str());
}

TEST_F(ScenarioGetHumanManyHumansExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("10", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetHumanOneHumanExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumanOneHumanExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerjoblessnovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_HUMAN_HUMAN_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsOneObject)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsObjectWithValidHumanClass)
{
    ASSERT_STREQ("worker", mCommandReply->getObjects().front().at("humanclass").c_str());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsObjectWithValidHumanName)
{
    ASSERT_STREQ("jobless", mCommandReply->getObjects().front().at("humanname").c_str());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsObjectWithValidExperience)
{
    ASSERT_STREQ("novice", mCommandReply->getObjects().front().at("experience").c_str());
}

TEST_F(ScenarioGetHumanOneHumanExist, ReturnsObjectWithValidVolume)
{
    ASSERT_STREQ("1000", mCommandReply->getObjects().front().at("volume").c_str());
}

class ScenarioGetHumanZeroHumansExist
    : public IntegrationTest
{
protected:
    ScenarioGetHumanZeroHumansExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement2", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanZeroHumansExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanZeroHumansExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetHumanZeroHumansExist, ReturnsProperMessage)
{
    // TODO: Add GET_HUMAN_HUMAN_HAS_NOT_BEEN_GOT
    ASSERT_STREQ(Game::GET_HUMAN_UNEXPECTED_ERROR.c_str(), mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetHumanZeroHumansExist, ReturnsZeroObjects)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetHumanUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetHumanUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetHumanEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetHumanEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetHumanEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetHumanEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
