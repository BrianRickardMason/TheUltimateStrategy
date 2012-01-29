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

class ScenarioDeleteSettlementSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioDeleteSettlementSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeleteSettlementRequest("Login", "Password", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeleteSettlementSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DELETE_SETTLEMENT_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeleteSettlementSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDeleteSettlement
    : public IntegrationTest
{
protected:
    ScenarioDeleteSettlement()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeleteSettlementRequest("Login", "Password", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeleteSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DELETE_SETTLEMENT_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeleteSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeleteSettlement, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DELETE_SETTLEMENT_SETTLEMENT_HAS_BEEN_DELETED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDeleteSettlementUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioDeleteSettlementUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(
            mRequestBuilder.buildDeleteSettlementRequest("Login", "BadPassword", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeleteSettlementUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DELETE_SETTLEMENT_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeleteSettlementUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioDeleteSettlementUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioDeleteSettlementUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(
            mRequestBuilder.buildDeleteSettlementRequest("Login2", "Password", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeleteSettlementUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DELETE_SETTLEMENT_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeleteSettlementUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDeleteSettlementEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioDeleteSettlementEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(
            mRequestBuilder.buildDeleteSettlementRequest("Login", "Password", "Settlement"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeleteSettlementEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DELETE_SETTLEMENT_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeleteSettlementEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
