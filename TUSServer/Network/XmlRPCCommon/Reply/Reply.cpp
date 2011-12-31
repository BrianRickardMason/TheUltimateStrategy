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
#include <boost/lexical_cast.hpp>

using namespace Network::XmlRPCCommon::Xml;
using namespace std;

namespace Network
{
namespace XmlRPCCommon
{
namespace Reply
{

Reply::Reply()
{
}

Reply::Reply(
    string const & a_content
)
{
    setXmlDocument(a_content);
}

Reply::Reply(
    Common::MessageWrapperShrPtr a_message_wrapper
)
{
    string string_representation = boost::asio::buffer_cast<const char*>(a_message_wrapper->m_buffer.data());

    setXmlDocument(string_representation);
}

unsigned short int const Reply::getIdReply() const
{
    // Verify if a "reply" tag exists.
    IXmlNodeShrPtr node = m_xml_document->getNode("reply");
    if (!node)
    {
        throw InvalidReplyShrPtr();
    }

    // Verify if the "reply" tag has an "id" attribute.
    IXmlAttributeShrPtr attribute = node->getAttribute("id");
    if (!attribute)
    {
        throw InvalidReplyShrPtr();
    }

    // Verify if the "id" attribute is an unsigned integer.
    try
    {
        boost::lexical_cast<unsigned int>(attribute->getValue());
    }
    catch (boost::bad_lexical_cast &)
    {
        throw InvalidReplyShrPtr();
    }

    // Verify if the value of the "id" attribute is positive.
    if (attribute->asInt() < 0)
    {
        throw InvalidReplyShrPtr();
    }

    return attribute->asInt();
}

unsigned int const Reply::getParameterValueUnsignedInteger(
    string const & a_name
) const
{
    IXmlNodeShrPtr node = verifyIfParameterExists(a_name);

    IXmlAttributeShrPtr attribute = verifyIfParameterHasAValueAtribute(node);

    // Verify if parameter is declared as an unsigned integer and is an unsigned integer.
    try
    {
        boost::lexical_cast<unsigned int>(attribute->getValue());
    }
    catch (boost::bad_lexical_cast &)
    {
        throw InvalidReplyShrPtr();
    }

    // Verify if the value is positive.
    if (attribute->asInt() < 0)
    {
        throw InvalidReplyShrPtr();
    }

    return attribute->asUnsignedInt();
}

string const Reply::getParameterValueString(
    string const & a_name
) const
{
    IXmlNodeShrPtr node = verifyIfParameterExists(a_name);

    IXmlAttributeShrPtr attribute = verifyIfParameterHasAValueAtribute(node);

    return string(attribute->getValue());
}

IXmlNodeShrPtr Reply::verifyIfParameterExists(
    string const & a_name
) const
{
    IXmlNodeShrPtr node_reply = m_xml_document->getNode("reply");
    if (!node_reply)
    {
        throw InvalidReplyShrPtr();
    }

    IXmlNodeShrPtr node_parameters = node_reply->getNode("parameters");
    if (!node_parameters)
    {
        throw InvalidReplyShrPtr();
    }

    IXmlNodeShrPtr node_parameter = node_parameters->getNode(a_name.c_str());
    if (!node_parameter)
    {
        throw InvalidReplyShrPtr();
    }

    return node_parameter;
}

IXmlAttributeShrPtr Reply::verifyIfParameterHasAValueAtribute(
    IXmlNodeShrPtr a_parameter
) const
{
    IXmlAttributeShrPtr attribute = a_parameter->getAttribute("value");
    if (!attribute)
    {
        throw InvalidReplyShrPtr();
    }

    return attribute;
}

void Reply::setXmlDocument(
    string const & a_string
)
{
    // Set the xml document.
    bool const result = m_xml_document->loadDocument(a_string);

    if (!result)
    {
        // Rolling back.
        m_xml_document->resetDocument();
    }
}

} // namespace Reply
} // namespace XmlRPCCommon
} // namespace Network
