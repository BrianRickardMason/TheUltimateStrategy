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

class ScenarioGetSettlementsLandDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsLandDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsLandDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsLandDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

// TODO: Should GetObjects throw an exception?

class ScenarioGetSettlementsZeroSettlements
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsZeroSettlements()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsZeroSettlements, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsZeroSettlements, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetSettlementsZeroSettlements, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_NOT_BEEN_GOT.c_str(),
        mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetSettlementsZeroSettlements, ReturnsZeroObjects)
{
    ASSERT_EQ(0, mCommandReply->getObjects().size());
}

class ScenarioGetSettlementsOneSettlement
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsOneSettlement()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_BEEN_GOT.c_str(),
        mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsZeroObjects)
{
    ASSERT_EQ(1, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsObjectWithValidLandName)
{
    ASSERT_STREQ("Land", mCommandReply->getObjects().front().at("land_name").c_str());
}

TEST_F(ScenarioGetSettlementsOneSettlement, ReturnsObjectWithValidSettlementName)
{
    ASSERT_STREQ("Settlement", mCommandReply->getObjects().front().at("settlement_name").c_str());
}

class ScenarioGetSettlementsManySettlements
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsManySettlements()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_SETTLEMENTS_BY_LANDNAME_SETTLEMENTS_HAVE_BEEN_GOT.c_str(),
        mCommandReply->getMessage().c_str());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsZeroObjects)
{
    ASSERT_EQ(2, mCommandReply->getObjects().size());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsFirstObjectWithValidLandName)
{
    ASSERT_STREQ("Land", mCommandReply->getObjects().front().at("land_name").c_str());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsFirstObjectWithValidSettlementName)
{
    ASSERT_STREQ("Settlement1", mCommandReply->getObjects().front().at("settlement_name").c_str());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsSecondObjectWithValidLandName)
{
    ASSERT_STREQ("Land", mCommandReply->getObjects().back().at("land_name").c_str());
}

TEST_F(ScenarioGetSettlementsManySettlements, ReturnsSecondObjectWithValidSettlementName)
{
    ASSERT_STREQ("Settlement2", mCommandReply->getObjects().back().at("settlement_name").c_str());
}

class ScenarioGetSettlementsUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "BadPassword", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioGetSettlementsUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login2", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioGetSettlementsEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioGetSettlementsEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetSettlementsRequest("Login", "Password", "Land"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetSettlementsEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_SETTLEMENTS_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetSettlementsEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
