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

class ScenarioGetEpochWorldDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetEpochWorldDoesNotExist()
    {
        mCommandReply = mClient.send(mRequestBuilder.buildGetEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetEpochWorldDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetEpochWorldDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetEpochWorldDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_EPOCH_WORLD_DOES_NOT_EXIST.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioGetEpochEpochDoesNotExist
    : public IntegrationTest
{
protected:
    ScenarioGetEpochEpochDoesNotExist()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetEpochEpochDoesNotExist, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetEpochEpochDoesNotExist, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetEpochEpochDoesNotExist, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_EPOCH_EPOCH_HAS_NOT_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}

class ScenarioGetEpoch
    : public IntegrationTest
{
protected:
    ScenarioGetEpoch()
    {
        mClient.send(mRequestBuilder.buildCreateWorldRequest("modbot", "modbotpass", "World"));
        mClient.send(mRequestBuilder.buildCreateEpochRequest("modbot", "modbotpass", "World", "Epoch"));
        mCommandReply = mClient.send(mRequestBuilder.buildGetEpochRequest("modbot", "modbotpass", "World"));
    }

    Client mClient;

    Language::RequestBuilder  mRequestBuilder;
    Language::Command::Handle mCommandReply;
};

TEST_F(ScenarioGetEpoch, ReturnsProperID)
{
    ASSERT_EQ(Language::ID_COMMAND_GET_EPOCH_REPLY, mCommandReply->getID());
}

TEST_F(ScenarioGetEpoch, ReturnsProperCode)
{
    ASSERT_EQ(Game::REPLY_STATUS_OK, mCommandReply->getCode());
}

TEST_F(ScenarioGetEpoch, ReturnsProperMessage)
{
    ASSERT_STREQ(Game::GET_EPOCH_EPOCH_HAS_BEEN_GOT.c_str(), mCommandReply->getMessage().c_str());
}
