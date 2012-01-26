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

class ScenarioTickEpochWorldDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioTickEpochWorldDoesNotExist()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpochWorldDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTickEpochWorldDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTickEpochWorldDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TICK_EPOCH_WORLD_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpochEpochDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioTickEpochEpochDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpochEpochDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTickEpochEpochDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTickEpochEpochDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpochEpochFinished
    : public IntegrationTest
{
protected:
    ScenarioTickEpochEpochFinished()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpochEpochFinished, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTickEpochEpochFinished, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTickEpochEpochFinished, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpochEpochIsActive
    : public IntegrationTest
{
protected:
    ScenarioTickEpochEpochIsActive()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpochEpochIsActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTickEpochEpochIsActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTickEpochEpochIsActive, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_IS_ACTIVE.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpoch
    : public IntegrationTest
{
protected:
    ScenarioTickEpoch()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpoch, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioTickEpoch, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioTickEpoch, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_HAS_BEEN_TACK.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpochOneLand
    : public IntegrationTest
{
protected:
    ScenarioTickEpochOneLand()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioTickEpochOneLand, StandsUponTheStress)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
    ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, mCommandReply->getID());
    ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_HAS_BEEN_TACK.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioTickEpochOneLand10Times
    : public IntegrationTest
{
protected:
    ScenarioTickEpochOneLand10Times()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        for (unsigned short int i = 0; i < 10; ++i)
        {
            mCommandReplies.push_back(
                mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"))
            );
        }
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    std::vector<Language::Command::Handle> mCommandReplies;
};

TEST_F(ScenarioTickEpochOneLand10Times, StandsUponTheStress)
{
    for (std::vector<Language::Command::Handle>::const_iterator it = mCommandReplies.begin(); it !=mCommandReplies.end(); ++it)
    {
        ASSERT_EQ(Game::REPLY_STATUS_OK, (*it)->getCode());
        ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, (*it)->getID());
        ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_HAS_BEEN_TACK.c_str(), (*it)->getMessage().c_str());
    }
}

class ScenarioTickEpochOneLand100Times
    : public IntegrationTest
{
protected:
    ScenarioTickEpochOneLand100Times()
    {
        mClient.send(mRequestBuilder.buildCreateUserRequest("Login", "Password"));
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateLandRequest("Login", "Password", "World", "Land"));
        mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
        for (unsigned short int i = 0; i < 100; ++i)
        {
            mCommandReplies.push_back(
                mClient.send(mRequestBuilder.buildTickEpochRequest("modbot", "modbotpass", "World"))
            );
        }
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    std::vector<Language::Command::Handle> mCommandReplies;
};

TEST_F(ScenarioTickEpochOneLand100Times, StandsUponTheStress)
{
    for (std::vector<Language::Command::Handle>::const_iterator it = mCommandReplies.begin(); it !=mCommandReplies.end(); ++it)
    {
        ASSERT_EQ(Game::REPLY_STATUS_OK, (*it)->getCode());
        ASSERT_EQ(Language::ID_COMMAND_TICK_EPOCH_REPLY, (*it)->getID());
        ASSERT_STREQ(Game::TICK_EPOCH_EPOCH_HAS_BEEN_TACK.c_str(), (*it)->getMessage().c_str());
    }
}
