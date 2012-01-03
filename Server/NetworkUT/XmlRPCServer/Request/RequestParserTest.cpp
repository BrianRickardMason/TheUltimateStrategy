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

#include <Server/Network/XmlRPCCommon/Common/MessageWrapper.hpp>
#include <Server/Network/XmlRPCServer/Request/RequestParser.hpp>
#include <gmock/gmock.h>

using namespace std;

/**
 * @brief A test class.
 */
class RequestParserTest
    : public testing::Test
{
protected:
    /**
     * @brief A request parser.
     */
    Network::XmlRPCServer::Request::RequestParser m_request_parser;
};

/**
 * Unit tests of: RequestParser::parse.
 */
TEST_F(RequestParserTest, parse_ValidRequest)
{
    // Preconditions.
    string command("<?xml version=\"1.0\"?><request id=\"1\"></request>");

    Network::XmlRPCCommon::Common::MessageWrapperShrPtr message_wrapper(new Network::XmlRPCCommon::Common::MessageWrapper);
    message_wrapper->m_buffer.sputn(command.c_str(), command.size());

    // TODO: Ensure content is valid.

    // Test commands and assertions.
    ASSERT_TRUE(m_request_parser.parse(message_wrapper));
}

TEST_F(RequestParserTest, parse_InvalidRequest)
{
    // Preconditions.
    string command("<?xml version=\"1.0\"?><request id=\"1\"><request>");

    Network::XmlRPCCommon::Common::MessageWrapperShrPtr message_wrapper(new Network::XmlRPCCommon::Common::MessageWrapper);
    message_wrapper->m_buffer.sputn(command.c_str(), command.size());

    // TODO: Ensure content is valid.

    // Test commands and assertions.
    ASSERT_TRUE(m_request_parser.parse(message_wrapper));
}
