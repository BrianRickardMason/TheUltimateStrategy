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

class ScenarioDismissHumanSettlementDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanSettlementDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanSettlementDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanSettlementDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDismissHumanUnauthorized
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanUnauthorized()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login1", "Password"));
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login2", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login1", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login1", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login1", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login2", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanUnauthorized, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanUnauthorized, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHORIZED, mCommandReply->getCode());
}

class ScenarioDismissHumanNotEnoughEngaged
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanNotEnoughEngaged()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "10"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "11"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanNotEnoughEngaged, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanNotEnoughEngaged, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanNotEnoughEngaged, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_NOT_ENOUGH_ENGAGED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanNotEnoughResources
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanNotEnoughResources()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "60"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanNotEnoughResources, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanNotEnoughResources, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanNotEnoughResources, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_NOT_ENOUGH_RESOURCES.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanMaxHumans
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanMaxHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanMaxHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanMaxHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanMaxHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanManyHumans
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanManyHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "40"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanManyHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanManyHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanManyHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanOneHuman
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanOneHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanOneHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanOneHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanOneHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanLastOneHuman
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanLastOneHuman()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanLastOneHuman, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanLastOneHuman, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanLastOneHuman, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_HUMAN_HAS_BEEN_DISMISSED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanLastOneHumanDoubleDismiss
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanLastOneHumanDoubleDismiss()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
        mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanLastOneHumanDoubleDismiss, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanLastOneHumanDoubleDismiss, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanLastOneHumanDoubleDismiss, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_NOT_ENOUGH_ENGAGED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanZeroHumans
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanZeroHumans()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildEngageHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "50"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "0"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanZeroHumans, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanZeroHumans, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanZeroHumans, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_TRYING_TO_DISMISS_ZERO_HUMANS.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanNotDismissable
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanNotDismissable()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerjoblessnovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanNotDismissable, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanNotDismissable, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDismissHumanNotDismissable, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DISMISS_HUMAN_HUMAN_IS_NOT_DISMISSABLE.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDismissHumanUnauthenticated
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanUnauthenticated()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "BadPassword", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanUnauthenticated, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanUnauthenticated, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_UNAUTHENTICATED, mCommandReply->getCode());
}

class ScenarioDismissHumanEpochIsNotActive
    : public IntegrationTest
{
protected:
    ScenarioDismissHumanEpochIsNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildCreateSettlementRequest("Login", "Password", "Land", "Settlement"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildDismissHumanRequest(
            "Login", "Password", "HolderClassSettlement", "Settlement", "workerfishermannovice", "1"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDismissHumanEpochIsNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DISMISS_HUMAN_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDismissHumanEpochIsNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_EPOCH_IS_NOT_ACTIVE, mCommandReply->getCode());
}
