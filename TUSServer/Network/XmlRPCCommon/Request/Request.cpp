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

#include <TUSServer/Network/XmlRPCCommon/Request/Request.hpp>
#include <boost/lexical_cast.hpp>

using namespace Network::XmlRPCCommon::Xml;
using namespace std;

namespace Network
{
namespace XmlRPCCommon
{
namespace Request
{

Request::Request()
{
}

Request::Request(
    string const & a_content
)
{
    setXmlDocument(a_content);
}

Request::Request(
    Network::XmlRPCCommon::Common::MessageWrapperShrPtr a_message_wrapper
)
{
    string string_representation = boost::asio::buffer_cast<const char*>(a_message_wrapper->m_buffer.data());

    setXmlDocument(string_representation);
}

unsigned short int Request::getIdRequest() const
{
    // Verify if a "request" tag exists.
    IXmlNodeShrPtr node = m_xml_document->getNode("request");
    if (!node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "request" tag has an "id" attribute.
    IXmlAttributeShrPtr attribute = node->getAttribute("id");
    if (!attribute)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "id" attribute is an unsigned integer.
    try
    {
        boost::lexical_cast<unsigned int>(attribute->getValue());
    }
    catch (boost::bad_lexical_cast &)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the value of the "id" attribute is positive.
    if (attribute->asInt() < 0)
    {
        throw InvalidRequestShrPtr();
    }

    return attribute->asInt();
}

string Request::getLoginValue() const
{
    // Verify if the "request" node exists.
    IXmlNodeShrPtr request_node = m_xml_document->getNode("request");
    if (!request_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "user" node exists.
    IXmlNodeShrPtr user_node = request_node->getNode("user");
    if (!user_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "login" node exists.
    IXmlNodeShrPtr login_node = user_node->getNode("login");
    if (!login_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "login" node has the "value" attribute.
    IXmlAttributeShrPtr value_attribute = login_node->getAttribute("value");
    if (!value_attribute)
    {
        throw InvalidRequestShrPtr();
    }

    return string(value_attribute->getValue());
}

string Request::getPasswordValue() const
{
    // Verify if the "request" node exists.
    IXmlNodeShrPtr request_node = m_xml_document->getNode("request");
    if (!request_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "user" node exists.
    IXmlNodeShrPtr user_node = request_node->getNode("user");
    if (!user_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "password" node exists.
    IXmlNodeShrPtr password_node = user_node->getNode("password");
    if (!password_node)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the "password" node has the "value" attribute.
    IXmlAttributeShrPtr value_attribute = password_node->getAttribute("value");
    if (!value_attribute)
    {
        throw InvalidRequestShrPtr();
    }

    return string(value_attribute->getValue());
}

unsigned int Request::getParameterValueUnsignedInteger(
    string const & a_name
) const
{
    Network::XmlRPCCommon::Xml::IXmlNodeShrPtr node = verifyIfParameterExists(a_name);

    IXmlAttributeShrPtr attribute = verifyIfParameterHasAValueAtribute(node);

    // Verify if parameter is declared as an unsigned integer and is an unsigned integer.
    try
    {
        boost::lexical_cast<unsigned int>(attribute->getValue());
    }
    catch (boost::bad_lexical_cast &)
    {
        throw InvalidRequestShrPtr();
    }

    // Verify if the value is positive.
    if (attribute->asInt() < 0)
    {
        throw InvalidRequestShrPtr();
    }

    return attribute->asUnsignedInt();
}

string Request::getParameterValueString(
    string const & a_name
) const
{
    IXmlNodeShrPtr node = verifyIfParameterExists(a_name);

    IXmlAttributeShrPtr attribute = verifyIfParameterHasAValueAtribute(node);

    return string(attribute->getValue());
}

IXmlNodeShrPtr Request::verifyIfParameterExists(
    string const & a_name
) const
{
    IXmlNodeShrPtr node_request = m_xml_document->getNode("request");
    if (!node_request)
    {
        throw InvalidRequestShrPtr();
    }

    IXmlNodeShrPtr node_parameters = node_request->getNode("parameters");
    if (!node_parameters)
    {
        throw InvalidRequestShrPtr();
    }

    IXmlNodeShrPtr node_parameter = node_parameters->getNode(a_name.c_str());
    if (!node_parameter)
    {
        throw InvalidRequestShrPtr();
    }

    return node_parameter;
}

IXmlAttributeShrPtr Request::verifyIfParameterHasAValueAtribute(
    IXmlNodeShrPtr a_parameter
) const
{
    IXmlAttributeShrPtr attribute = a_parameter->getAttribute("value");
    if (!attribute)
    {
        throw InvalidRequestShrPtr();
    }

    return attribute;
}

void Request::setXmlDocument(
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

} // namespace Request
} // namespace XmlRPCCommon
} // namespace Network
