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

#ifndef NETWORK_XMLRPCCOMMON_COMMON_MESSAGEWRAPPER_HPP
#define NETWORK_XMLRPCCOMMON_COMMON_MESSAGEWRAPPER_HPP

#include <Server/Network/XmlRPCCommon/Common/IMessageWrapper.hpp>
#include <boost/asio.hpp>
#include <string>

namespace Network
{
namespace XmlRPCCommon
{
namespace Common
{

/**
 * @brief A wrapper for a message.
 */
class MessageWrapper
    : public IMessageWrapper
{
public:
    /**
     * @brief Constructs the message wrapper.
     */
    MessageWrapper();

    /**
     * @brief Constructs the message wrapper.
     *
     * @param a_content A content of the message.
     */
    explicit MessageWrapper(
        std::string const & a_content
    );

    /**
     * @brief Gets the content of the message.
     *
     * @return The content of the message.
     */
    virtual std::string const getContent() const;

    /**
     * @brief Sets the content of the message.
     *
     * @param a_content A content to be set.
     */
    virtual void setContent(
        std::string const & a_content
    );

    /**
     * @brief A buffer for incoming data.
     */
    boost::asio::streambuf m_buffer;
};

/**
 * @brief A shared pointer of message wrapper.
 */
typedef boost::shared_ptr<MessageWrapper> MessageWrapperShrPtr;

} // namespace Common
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_COMMON_MESSAGEWRAPPER_HPP
