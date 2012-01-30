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

class ScenarioTransportHumanUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "BadPassword", "Settlement1", "Settlement2", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioTransportHumanUnauthorizedToTheSourceSettlement
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanUnauthorizedToTheSourceSettlement()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement2"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login2", "Password", "Land", "Settlement3"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login2", "Password", "Settlement1", "Settlement3", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanUnauthorizedToTheSourceSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanUnauthorizedToTheSourceSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportHumanUnauthorizedToTheDestinationSettlement
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanUnauthorizedToTheDestinationSettlement()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement2"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login2", "Password", "Land", "Settlement3"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login2", "Password", "Settlement3", "Settlement1", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanUnauthorizedToTheDestinationSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanUnauthorizedToTheDestinationSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportHumanEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}

class ScenarioTransportHumanTryingToTransportZeroHumans
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanTryingToTransportZeroHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanTryingToTransportZeroHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanTryingToTransportZeroHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportHumanTryingToTransportZeroHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_HUMAN_TRYING_TO_TRANSPORT_ZERO_HUMANS.c_str(), mCommandReply->getMessage().c_str());
}

// TODO: ScenarioTransportSourceSettlementDoesNotExist.
// TODO: ScenarioTransportDestinationSettlementDoesNotExist.

class ScenarioTransportHumanSettlementsAreNotFromTheSameLand
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanSettlementsAreNotFromTheSameLand()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land1"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login2", "Password", "World", "Land2"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land1", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login2", "Password", "Land2", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login1", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanSettlementsAreNotFromTheSameLand, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanSettlementsAreNotFromTheSameLand, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportHumanNotEnoughHumans
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanNotEnoughHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "1001"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanNotEnoughHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanNotEnoughHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportHumanNotEnoughHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_HUMAN_NOT_ENOUGH_HUMANS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportHumanOneHuman
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanOneHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanOneHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanOneHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportHumanOneHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_HUMAN_HUMAN_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportHumanManyHuman
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanManyHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanManyHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanManyHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportHumanManyHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_HUMAN_HUMAN_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportHumanMaxHuman
    : public IntegrationTest
{
protected:
    ScenarioTransportHumanMaxHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportHumanRequest(
            "Login", "Password", "Settlement1", "Settlement2", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportHumanMaxHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportHumanMaxHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportHumanMaxHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_HUMAN_HUMAN_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}
