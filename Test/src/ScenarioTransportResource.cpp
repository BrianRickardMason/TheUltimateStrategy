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

class ScenarioTransportResourceUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "BadPassword", "Settlement1", "Settlement2", "coal", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioTransportResourceUnauthorizedToTheSourceSettlement
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceUnauthorizedToTheSourceSettlement()
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
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login2", "Password", "Settlement1", "Settlement3", "coal", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceUnauthorizedToTheSourceSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceUnauthorizedToTheSourceSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportResourceUnauthorizedToTheDestinationSettlement
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceUnauthorizedToTheDestinationSettlement()
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
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login2", "Password", "Settlement3", "Settlement1", "coal", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceUnauthorizedToTheDestinationSettlement, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceUnauthorizedToTheDestinationSettlement, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportResourceEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}

class ScenarioTransportResourceTryingToTransportZeroResources
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceTryingToTransportZeroResources()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceTryingToTransportZeroResources, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceTryingToTransportZeroResources, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportResourceTryingToTransportZeroResources, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_RESOURCE_TRYING_TO_TRANSPORT_ZERO_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

// TODO: ScenarioTransportSourceSettlementDoesNotExist.
// TODO: ScenarioTransportDestinationSettlementDoesNotExist.

class ScenarioTransportResourceSettlementsAreNotFromTheSameLand
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceSettlementsAreNotFromTheSameLand()
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
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login1", "Password", "Settlement1", "Settlement2", "coal", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceSettlementsAreNotFromTheSameLand, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceSettlementsAreNotFromTheSameLand, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioTransportResourceNotEnoughResources
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceNotEnoughResources()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "1001"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceNotEnoughResources, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceNotEnoughResources, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportResourceNotEnoughResources, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_RESOURCE_NOT_ENOUGH_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportResourceOneResource
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceOneResource()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceOneResource, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceOneResource, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportResourceOneResource, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_RESOURCE_RESOURCE_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportResourceManyResource
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceManyResource()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "484"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceManyResource, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceManyResource, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportResourceManyResource, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_RESOURCE_RESOURCE_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTransportResourceMaxResource
    : public IntegrationTest
{
protected:
    ScenarioTransportResourceMaxResource()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement1"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement2"));
        mCommandReply = mClient.send(mRequestBuilder.buildTransportResourceRequest(
            "Login", "Password", "Settlement1", "Settlement2", "coal", "1000"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTransportResourceMaxResource, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TRANSPORT_RESOURCE_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTransportResourceMaxResource, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTransportResourceMaxResource, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TRANSPORT_RESOURCE_RESOURCE_HAS_BEEN_TRANSPORTED.c_str(), mCommandReply->getMessage().c_str());
}
