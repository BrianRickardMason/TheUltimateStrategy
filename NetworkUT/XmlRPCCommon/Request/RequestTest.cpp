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

#include "../../../Network/XmlRPCCommon/Request/Request.hpp"
#include <boost/make_shared.hpp>
#include <gmock/gmock.h>

using namespace Network::XmlRPCCommon::Common;
using namespace Network::XmlRPCCommon::Request;
using namespace boost;
using namespace std;

// TODO: Refactoring needed!

/**
 * Unit tests of: Request::Request.
 */
TEST(RequestTest, Request)
{
    // Preconditions.
    string content_expected("<?xml version=\"1.0\"?>\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Request request);

    // Test commands.
    Request request;

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), request.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Request::Request string based.
 */
TEST(RequestTest, Request_StringBased_ValidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<request id=\"1\" />\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Request request(content));

    // Test commands.
    Request request(content);

    // Test assertions.
    ASSERT_STREQ(content.c_str(), request.toWrapper()->getContent().c_str());
}

TEST(RequestTest, Request_StringBased_InvalidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<request id=\"1\">\n<request>\n");
    string content_expected("<?xml version=\"1.0\"?>\n");

    // Test commands and assertions.
    ASSERT_NO_THROW(Request request(content));

    // Test commands.
    Request request(content);

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), request.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Request::Request MessageWrapper based.
 */
TEST(RequestTest, Request_MessageWrapperBased_ValidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>\n<request id=\"1\" />\n");

    MessageWrapperShrPtr message_wrapper = make_shared<MessageWrapper>(content);

    // Test commands and assertions.
    ASSERT_NO_THROW(Request request(message_wrapper));

    // Test commands.
    Request request(message_wrapper);

    // Test assertions.
    ASSERT_STREQ(content.c_str(), request.toWrapper()->getContent().c_str());
}

TEST(RequestTest, Request_MessageWrapperBased_InvalidContent)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><request>");
    string content_expected("<?xml version=\"1.0\"?>\n");

    MessageWrapperShrPtr message_wrapper = make_shared<MessageWrapper>(content);

    // Test commands and assertions.
    ASSERT_NO_THROW(Request request(message_wrapper));

    // Test commands.
    Request request(message_wrapper);

    // Test assertions.
    ASSERT_STREQ(content_expected.c_str(), request.toWrapper()->getContent().c_str());
}

/**
 * Unit tests of: Request::getIdRequest.
 */
TEST(RequestTest, getIdRequest_PositiveValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(1, request.getIdRequest());
}

TEST(RequestTest, getIdRequest_ZeroValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"0\"></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(0, request.getIdRequest());
}

TEST(RequestTest, getIdRequest_NegativeValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"-1\"></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getIdRequest(), InvalidRequestShrPtr);
}

TEST(RequestTest, getIdRequest_RequestTagDoesNotExist)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getIdRequest(), InvalidRequestShrPtr);
}

TEST(RequestTest, getIdRequest_RequestTagDoesNotHaveIdAttribute)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getIdRequest(), InvalidRequestShrPtr);
}

TEST(RequestTest, getIdRequest_IdAttributeIsNotAnInteger)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"notinteger\"></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getIdRequest(), InvalidRequestShrPtr);
}

/**
 * Unit tests of: Request::getParameterValueUnsignedInteger.
 */
TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_PositiveValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" value=\"1\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(1, request.getParameterValueUnsignedInteger("userid"));
}

TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_ZeroValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" value=\"0\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_EQ(0, request.getParameterValueUnsignedInteger("userid"));
}

TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_NegativeValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" value=\"-1\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueUnsignedInteger("userid"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_ParameterIsNotDeclaredAsAnUnsignedInteger)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"string\" value=\"1\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueUnsignedInteger("userid"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_ParameterIsDeclaredAsAnUnsignedIntegerButItsValueIsNotAnUnsignedInteger)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" value=\"notunsignedinteger\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueUnsignedInteger("userid"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueUnsignedInteger_ExistingParameter_ParameterDoesNotHaveAValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueUnsignedInteger("userid"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueUnsignedInteger_NonExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><userid type=\"unsigned integer\" value=\"1\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueUnsignedInteger("differentuserid"), InvalidRequestShrPtr);
}

/**
 * Unit tests of: Request::getParameterValueString.
 */
TEST(RequestTest, getParameterValueString_ExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><name type=\"string\" value=\"stringvalue\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_STREQ("stringvalue", request.getParameterValueString("name").c_str());
}

TEST(RequestTest, getParameterValueString_ExistingParameter_ParameterIsNotDeclaredAsAString)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><name type=\"notstring\" value=\"stringvalue\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueString("name"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueString_ExistingParameter_ParameterDoesNotHaveAValue)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><name type=\"string\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueString("name"), InvalidRequestShrPtr);
}

TEST(RequestTest, getParameterValueString_NonExistingParameter)
{
    // Preconditions.
    string content("<?xml version=\"1.0\"?><request id=\"1\"><parameters><name type=\"string\" value=\"stringvalue\" /></parameters></request>");

    MessageWrapperShrPtr message_wrapper(new MessageWrapper);
    message_wrapper->setContent(content);

    Request request(message_wrapper);

    // Test commands and assertions.
    ASSERT_THROW(request.getParameterValueString("namenotexistent"), InvalidRequestShrPtr);
}
