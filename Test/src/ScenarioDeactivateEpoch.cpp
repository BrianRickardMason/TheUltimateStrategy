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

class ScenarioDeactivateEpochWorldDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioDeactivateEpochWorldDoesNotExist()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeactivateEpochWorldDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DEACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeactivateEpochWorldDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeactivateEpochWorldDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DEACTIVATE_EPOCH_WORLD_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDeactivateEpochEpochDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioDeactivateEpochEpochDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeactivateEpochEpochDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DEACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeactivateEpochEpochDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeactivateEpochEpochDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DEACTIVATE_EPOCH_EPOCH_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDeactivateEpochEpochFinished
    : public IntegrationTest
{
protected:
    ScenarioDeactivateEpochEpochFinished()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildFinishEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeactivateEpochEpochFinished, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DEACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeactivateEpochEpochFinished, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeactivateEpochEpochFinished, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DEACTIVATE_EPOCH_EPOCH_HAS_BEEN_FINISHED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDeactivateEpoch
    : public IntegrationTest
{
protected:
    ScenarioDeactivateEpoch()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mClient.send(mRequestBuilder.buildActivateEpochRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeactivateEpoch, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DEACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeactivateEpoch, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeactivateEpoch, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DEACTIVATE_EPOCH_EPOCH_HAS_BEEN_DEACTIVATED.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioDeactivateEpochEpochNotActive
    : public IntegrationTest
{
protected:
    ScenarioDeactivateEpochEpochNotActive()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildDeactivateEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioDeactivateEpochEpochNotActive, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_DEACTIVATE_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioDeactivateEpochEpochNotActive, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioDeactivateEpochEpochNotActive, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::DEACTIVATE_EPOCH_EPOCH_IS_NOT_ACTIVE.c_str(), mCommandReply->getMessage().c_str());
}
