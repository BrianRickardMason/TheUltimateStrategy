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

class ScenarioFinishEpochWorldDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioFinishEpochWorldDoesNotExist()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioFinishEpochWorldDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_FINISH_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioFinishEpochWorldDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioFinishEpochWorldDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::FINISH_EPOCH_WORLD_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioFinishEpochEpochDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioFinishEpochEpochDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioFinishEpochEpochDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_FINISH_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioFinishEpochEpochDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioFinishEpochEpochDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::FINISH_EPOCH_EPOCH_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioFinishEpochEpochFinished
    : public IntegrationTest
{
protected:
    ScenarioFinishEpochEpochFinished()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioFinishEpochEpochFinished, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_FINISH_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioFinishEpochEpochFinished, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioFinishEpochEpochFinished, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED_PREVIOUSLY.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioFinishEpochEpochIsActive
    : public IntegrationTest
{
protected:
    ScenarioFinishEpochEpochIsActive()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioFinishEpochEpochIsActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_FINISH_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioFinishEpochEpochIsActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioFinishEpochEpochIsActive, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::FINISH_EPOCH_EPOCH_IS_ACTIVE.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioFinishEpoch
    : public IntegrationTest
{
protected:
    ScenarioFinishEpoch()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioFinishEpoch, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_FINISH_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioFinishEpoch, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioFinishEpoch, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::FINISH_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str(), mCommandReply->getMessage().c_str());
}
