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

#include <TUSServer/Network/XmlRPCCommon/Common/MessageWrapper.hpp>
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace Network::XmlRPCCommon::Common;
using namespace std;

// TODO: Refactoring needed!

/**
 * Unit tests of: MessageWrapper::MessageWrapper.
 */
TEST(MessageWrapperTest, MessageWrapper_ValidContent)
{
    // Test commands and assertions.
    ASSERT_NO_THROW(MessageWrapper message_wrapper);

    // Test commands.
    MessageWrapper message_wrapper;

    // Test assertions.
    ASSERT_STREQ("", message_wrapper.getContent().c_str());
}

/**
 * Unit tests of: MessageWrapper::MessageWrapper string based.
 */
TEST(MessageWrapperTest, MessageWrapper_StringBased_EmptyString)
{
    // Preconditions.
    string content;

    // Test commands and assertions.
    ASSERT_NO_THROW(MessageWrapper message_wrapper(content));

    // Test commands.
    MessageWrapper message_wrapper(content);

    // Test assertions.
    ASSERT_STREQ("", message_wrapper.getContent().c_str());
}

TEST(MessageWrapperTest, MessageWrapper_StringBased_NonEmptyString)
{
    // Preconditions.
    string content = "test";

    // Test commands and assertions.
    ASSERT_NO_THROW(MessageWrapper message_wrapper(content));

    // Test commands.
    MessageWrapper message_wrapper(content);

    // Test assertions.
    ASSERT_STREQ("test", message_wrapper.getContent().c_str());
}

/**
 * Unit tests of: MessageWrapper::getContent.
 */
TEST(MessageWrapperTest, getContent_EmptyString)
{
    // Preconditions.
    MessageWrapper message_wrapper("");

    // Test assertions.
    ASSERT_STREQ("", message_wrapper.getContent().c_str());
}

TEST(MessageWrapperTest, getContent_NonEmptyString)
{
    // Preconditions.
    MessageWrapper message_wrapper("test");

    // Test assertions.
    ASSERT_STREQ("test", message_wrapper.getContent().c_str());
}

/**
 * Unit tests of: MessageWrapper::setContent.
 */
TEST(MessageWrapperTest, setContent_EmptyString_ErasingEmpty)
{
    // Preconditions.
    MessageWrapper message_wrapper("");

    // Test commands.
    message_wrapper.setContent("");

    // Test assertions.
    ASSERT_STREQ("", message_wrapper.getContent().c_str());
}

TEST(MessageWrapperTest, setContent_EmptyString_ErasingNonEmpty)
{
    // Preconditions.
    MessageWrapper message_wrapper("test");

    // Test commands.
    message_wrapper.setContent("");

    // Test assertions.
    ASSERT_STREQ("", message_wrapper.getContent().c_str());
}

TEST(MessageWrapperTest, setContent_NonEmptyString_ErasingEmpty)
{
    // Preconditions.
    MessageWrapper message_wrapper("");

    // Test commands.
    message_wrapper.setContent("test");

    // Test assertions.
    ASSERT_STREQ("test", message_wrapper.getContent().c_str());
}

TEST(MessageWrapperTest, setContent_NonEmptyString_ErasingNonEmpty)
{
    // Preconditions.
    MessageWrapper message_wrapper("test");

    // Test commands.
    message_wrapper.setContent("tset");

    // Test assertions.
    ASSERT_STREQ("tset", message_wrapper.getContent().c_str());
}
