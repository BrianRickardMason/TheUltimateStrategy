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

class ScenarioActivateEpochWorldDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioActivateEpochWorldDoesNotExist()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioActivateEpochWorldDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioActivateEpochWorldDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioActivateEpochWorldDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ACTIVATE_EPOCH_WORLD_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioActivateEpochEpochDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioActivateEpochEpochDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioActivateEpochEpochDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioActivateEpochEpochDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioActivateEpochEpochDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ACTIVATE_EPOCH_EPOCH_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioActivateEpochEpochFinished
    : public IntegrationTest
{
protected:
    ScenarioActivateEpochEpochFinished()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioActivateEpochEpochFinished, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioActivateEpochEpochFinished, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioActivateEpochEpochFinished, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ACTIVATE_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioActivateEpochEpochActive
    : public IntegrationTest
{
protected:
    ScenarioActivateEpochEpochActive()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioActivateEpochEpochActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioActivateEpochEpochActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioActivateEpochEpochActive, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ACTIVATE_EPOCH_EPOCH_IS_ACTIVE.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioActivateEpoch
    : public IntegrationTest
{
protected:
    ScenarioActivateEpoch()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioActivateEpoch, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_ACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioActivateEpoch, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioActivateEpoch, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::ACTIVATE_EPOCH_EPOCH_HAS_BEEN_ACTIVATED.c_str(), mCommandReply->getMessage().c_str());
}
