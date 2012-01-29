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

class ScenarioDestroyBuildingSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDestroyBuildingUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingUnauthorized()
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
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDestroyBuildingDifferentBuilding
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingDifferentBuilding()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularsawmill", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingDifferentBuilding, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingDifferentBuilding, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingDifferentBuilding, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_THERE_ARE_NO_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingNotEnoughBuildings
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingNotEnoughBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "2"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingNotEnoughBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingNotEnoughBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingNotEnoughBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_NOT_ENOUGH_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingNotEnoughResources
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingNotEnoughResources()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "60"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "50"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingNotEnoughResources, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingNotEnoughResources, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingNotEnoughResources, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_NOT_ENOUGH_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingMaxBuildings
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingMaxBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "50"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingMaxBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingMaxBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingMaxBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingManyBuildings
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingManyBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "40"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingManyBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingManyBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingManyBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingOneBuilding
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingOneBuilding()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingOneBuilding, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingOneBuilding, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingOneBuilding, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingLastOneBuilding
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingLastOneBuilding()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingLastOneBuilding, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingLastOneBuilding, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingLastOneBuilding, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_BUILDING_HAS_BEEN_DESTROYED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingLastOneBuildingDoubleDestroy
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingLastOneBuildingDoubleDestroy()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingLastOneBuildingDoubleDestroy, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingLastOneBuildingDoubleDestroy, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingLastOneBuildingDoubleDestroy, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_THERE_ARE_NO_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingZeroBuildings
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingZeroBuildings()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingZeroBuildings, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingZeroBuildings, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDestroyBuildingZeroBuildings, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DESTROY_BUILDING_TRYING_TO_DESTROY_ZERO_BUILDINGS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDestroyBuildingUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildBuildBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioDestroyBuildingEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioDestroyBuildingEpochIsNotActive()
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
        mCommandReply = mClient.send(mRequestBuilder.buildDestroyBuildingRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "regularfarm", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDestroyBuildingEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DESTROY_BUILDING_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDestroyBuildingEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
