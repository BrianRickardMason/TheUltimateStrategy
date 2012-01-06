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

#include <Poco/DOM/Element.h>
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
    Poco::XML::Element * element;

    element = m_document->createElement("header");
    m_current_node = m_document->documentElement()->appendChild(element);

    element = m_document->createElement("id");
    try
    {
        element->setNodeValue(boost::lexical_cast<std::string>(a_id));
    }
    catch (boost::bad_lexical_cast &)
    {
        BOOST_ASSERT_MSG(false, "Invalid lexical cast of the identifier of the message.");
    }
    m_current_node->appendChild(element);
}

Message::SingleHandle MessageBuilder::extract()
{
    return m_document;
}

} // namespace TUSProtocol
