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

#include <Poco/AutoPtr.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/Text.h>
#include <Protocol/Xml/Cpp/MessageBuilder.hpp>
#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>

namespace TUSProtocol
{

void MessageBuilder::makeMessage()
{
    m_document.reset(new Message());

    m_current_node = m_document.get();

    Poco::XML::Element * message = m_document->createElement("message");

    m_current_node = m_current_node->appendChild(message);
}

void MessageBuilder::addHeader(
    unsigned short int const a_id
)
{
    Poco::AutoPtr<Poco::XML::Element> element;
    Poco::AutoPtr<Poco::XML::Text> value;

    element = m_document->createElement("header");
    m_current_node = m_document->documentElement()->appendChild(element);

    try
    {
        value = m_document->createTextNode(boost::lexical_cast<std::string>(a_id));
        element = m_document->createElement("id");
        element->appendChild(value);
        m_current_node->appendChild(element);
    }
    catch (boost::bad_lexical_cast &)
    {
        BOOST_ASSERT_MSG(false, "Invalid lexical cast of the identifier of the message.");
    }
}

void MessageBuilder::addHeader(
    unsigned short int const a_id,
    std::string        const a_login,
    std::string        const a_password
)
{
    Poco::AutoPtr<Poco::XML::Element> element;
    Poco::AutoPtr<Poco::XML::Text> value;

    element = m_document->createElement("header");
    m_current_node = m_document->documentElement()->appendChild(element);

    try
    {
        value = m_document->createTextNode(boost::lexical_cast<std::string>(a_id));
        element = m_document->createElement("id");
        element->appendChild(value);
        m_current_node->appendChild(element);
    }
    catch (boost::bad_lexical_cast &)
    {
        BOOST_ASSERT_MSG(false, "Invalid lexical cast of the identifier of the message.");
    }

    element = m_document->createElement("user");
    m_current_node = m_current_node->appendChild(element);

    value = m_document->createTextNode(a_login);
    element = m_document->createElement("login");
    element->appendChild(value);
    m_current_node->appendChild(element);

    value = m_document->createTextNode(a_password);
    element = m_document->createElement("password");
    element->appendChild(value);
    m_current_node->appendChild(element);
}

void MessageBuilder::addRequest(
    std::string const a_request
)
{
    Poco::AutoPtr<Poco::XML::Element> element;

    element = m_document->createElement("request");
    m_current_node = m_document->documentElement()->appendChild(element);

    element = m_document->createElement(a_request);
    m_current_node = m_current_node->appendChild(element);
}

void MessageBuilder::addParam(
    std::string const a_param_name,
    std::string const a_param_value
)
{
    Poco::AutoPtr<Poco::XML::Element> element;
    Poco::AutoPtr<Poco::XML::Text> value;

    value = m_document->createTextNode(a_param_value);
    element = m_document->createElement(a_param_name);
    element->appendChild(value);
    m_current_node->appendChild(element);
}

Message::SingleHandle MessageBuilder::extract()
{
    return m_document;
}

} // namespace TUSProtocol
