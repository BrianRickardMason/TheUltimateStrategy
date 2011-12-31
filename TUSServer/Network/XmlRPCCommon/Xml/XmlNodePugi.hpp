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

#ifndef NETWORK_XMLRPCCOMMON_XML_XMLNODEPUGI_HPP
#define NETWORK_XMLRPCCOMMON_XML_XMLNODEPUGI_HPP

#include <TUSGame/3rdParty/pugixml/src/pugixml.hpp>
#include <TUSServer/Network/XmlRPCCommon/Xml/IXmlNode.hpp>

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

/**
 * @brief The pugi xml node.
 */
class XmlNodePugi
    : public IXmlNode
{
public:
    /**
     * @brief Constructs the node.
     *
     * @param a_xml_node The internal pugi xml node.
     */
    XmlNodePugi(
        pugi::xml_node a_xml_node
    );

    /**
     * @brief Appends the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual IXmlNodeShrPtr appendNode(
        char const * a_name
    );

    /**
     * @brief Appends the attribute.
     *
     * @param a_name The name of the attribute.
     *
     * @return The attribute on success, null otherwise.
     */
    virtual IXmlAttributeShrPtr appendAttribute(
        char const * a_name
    );

    /**
     * @brief Gets the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual IXmlNodeShrPtr getNode(
        char const * a_name
    ) const;

    /**
     * @brief Gets the attribute.
     *
     * @param a_name The name of the attribute.
     *
     * @return The attribute on success, null otherwise.
     */
    virtual IXmlAttributeShrPtr getAttribute(
        char const * a_name
    ) const;

private:
    /**
     * @brief The internal pugi xml node.
     */
    pugi::xml_node m_xml_node;
};

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_XML_XMLNODEPUGI_HPP
