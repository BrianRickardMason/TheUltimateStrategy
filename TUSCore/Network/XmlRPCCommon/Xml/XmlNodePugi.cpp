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

#include "XmlAttributePugi.hpp"
#include "XmlNodePugi.hpp"
#include <boost/make_shared.hpp>

using namespace boost;
using namespace pugi;

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

XmlNodePugi::XmlNodePugi(
    xml_node a_xml_node
)
    : m_xml_node(a_xml_node)
{
}

IXmlNodeShrPtr XmlNodePugi::appendNode(
    char const * a_name
)
{
    xml_node xml_node = m_xml_node.append_child(a_name);

    return (xml_node) ? make_shared<XmlNodePugi>(xml_node) : IXmlNodeShrPtr();
}

IXmlAttributeShrPtr XmlNodePugi::appendAttribute(
    char const * a_name
)
{
    xml_attribute xml_attribute = m_xml_node.append_attribute(a_name);

    return (xml_attribute) ? make_shared<XmlAttributePugi>(xml_attribute) : IXmlAttributeShrPtr();
}

IXmlNodeShrPtr XmlNodePugi::getNode(
    char const * a_name
) const
{
    xml_node xml_node = m_xml_node.child(a_name);

    return (xml_node) ? make_shared<XmlNodePugi>(xml_node) : IXmlNodeShrPtr();
}

IXmlAttributeShrPtr XmlNodePugi::getAttribute(
    char const * a_name
) const
{
    xml_attribute xml_attribute = m_xml_node.attribute(a_name);

    return (xml_attribute) ? make_shared<XmlAttributePugi>(xml_attribute) : IXmlAttributeShrPtr();
}

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network