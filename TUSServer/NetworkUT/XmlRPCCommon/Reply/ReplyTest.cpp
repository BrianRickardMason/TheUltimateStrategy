// Copyright (C) 2010 and 2011 Marcin Arkadiusz Skrobiranda.
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

#include <TUSServer/Network/XmlRPCCommon/Reply/Reply.hpp>
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace Network::XmlRPCCommon::Common;
using namespace Network::XmlRPCCommon::Reply;
using namespace boost;
using namespace std;

// TODO: Refactoring needed!

/**
 * Unit tests of: Reply::Reply.
 */
TEST(ReplyTest, Reply)
{
    // Preconditions.
    string content_expected("<?xml version=\"1.0\"?>\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Reply reply);

    // Test commands.
    Reply reply;

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), reply.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Reply::Reply string based.
 */
TEST(ReplyTest, Reply_StringBased_ValidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<reply id=\"1\" />\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Reply reply(content));

    // Test commands.
    Reply reply(content);

    // Test assertions.
    ASSERT_STREQ(content.c_str(), reply.toWrapper()->getContent().c_str());
}

TEST(ReplyTest, Reply_StringBased_InvalidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<reply id=\"1\">\n<reply>\n");
    string content_expected("<?xml version=\"1.0\"?>\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Reply reply(content));

    // Test commands.
    Reply reply(content);

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), reply.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Reply::Reply MessageWrapper based.
 */
TEST(ReplyTest, Reply_MessageWrapperBased_ValidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<reply id=\"1\" />\n");

    MessageWrapperShrPtr message_wrapper = make_shared<MessageWrapper>(content);

    // Test commands and assertions.
    ASSERT_NO_THROW(Reply reply(message_wrapper));

    // Test commands.
    Reply reply(message_wrapper);

    // Test assertions.
    ASSERT_STREQ(content.c_str(), reply.toWrapper()->getContent().c_str());
}

TEST(ReplyTest, Reply_ReplyWrapperBased_InvalidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><reply>");
    string content_expected("<?xml version=\"1.0\"?>\n");

    MessageWrapperShrPtr message_wrapper = make_shared<MessageWrapper>(content);

    // Test commands and assertions.
    ASSERT_NO_THROW(Reply reply(message_wrapper));

    // Test commands.
    Reply reply(message_wrapper);

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), reply.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Reply::getIdReply.
 */
TEST(ReplyTest, getIdReply_PositiveValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(1, reply.getIdReply());
}

TEST(ReplyTest, getIdReply_ZeroValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"0\"></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(0, reply.getIdReply());
}

TEST(ReplyTest, getIdReply_NegativeValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"-1\"></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getIdReply(), InvalidReplyShrPtr);
}

TEST(ReplyTest, getIdReply_ReplyTagDoesNotExist)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getIdReply(), InvalidReplyShrPtr);
}

TEST(ReplyTest, getIdReply_ReplyTagDoesNotHaveIdAttribute)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getIdReply(), InvalidReplyShrPtr);
}

TEST(ReplyTest, getIdReply_IdAttributeIsNotAnInteger)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"notinteger\"></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getIdReply(), InvalidReplyShrPtr);
}

/**
 * Unit tests of: Reply::getParameterValueUnsignedInteger.
 */
TEST(ReplyTest, getParameterValueUnsignedInteger_ExistingParameter_PositiveValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid value=\"1\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(1, reply.getParameterValueUnsignedInteger("userid"));
}

TEST(ReplyTest, getParameterValueUnsignedInteger_ExistingParameter_ZeroValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid value=\"0\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(0, reply.getParameterValueUnsignedInteger("userid"));
}

TEST(ReplyTest, getParameterValueUnsignedInteger_ExistingParameter_NegativeValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid value=\"-1\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueUnsignedInteger("userid"), InvalidReplyShrPtr);
}

TEST(ReplyTest, getParameterValueUnsignedInteger_ExistingParameter_ParameterIsDeclaredAsAnUnsignedIntegerButItsValueIsNotAnUnsignedInteger)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid value=\"notunsignedinteger\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueUnsignedInteger("userid"), InvalidReplyShrPtr);
}

TEST(ReplyTest, getParameterValueUnsignedInteger_ExistingParameter_ParameterDoesNotHaveAValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueUnsignedInteger("userid"), InvalidReplyShrPtr);
}

TEST(ReplyTest, getParameterValueUnsignedInteger_NonExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><userid value=\"1\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueUnsignedInteger("differentuserid"), InvalidReplyShrPtr);
}

/**
 * Unit tests of: Reply::getParameterValueString.
 */
TEST(ReplyTest, getParameterValueString_ExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><name value=\"stringvalue\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_STREQ("stringvalue", reply.getParameterValueString("name").c_str());
}

TEST(ReplyTest, getParameterValueString_ExistingParameter_ParameterDoesNotHaveAValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><name /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueString("name"), InvalidReplyShrPtr);
}

TEST(ReplyTest, getParameterValueString_NonExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><reply id=\"1\"><parameters><name value=\"stringvalue\" /></parameters></reply>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Reply reply(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(reply.getParameterValueString("namenotexistent"), InvalidReplyShrPtr);
}
