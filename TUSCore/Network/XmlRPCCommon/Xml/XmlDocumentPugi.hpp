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

#ifndef NETWORK_XMLRPCCOMMON_XML_XMLDOCUMENTPUGI_HPP
#define NETWORK_XMLRPCCOMMON_XML_XMLDOCUMENTPUGI_HPP

#include <TUSGame/3rdParty/pugixml/src/pugixml.hpp>
#include "IXmlDocument.hpp"

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

/**
 * @brief The pugi xml document.
 */
class XmlDocumentPugi
    : public IXmlDocument
{
public:
    /**
     * @brief Loads the document from a string.
     *
     * @param a_string The string representation.
     *
     * @return True on success, false otherwise.
     */
    virtual bool loadDocument(
        std::string const & a_string
    );

    /**
     * @brief Loads the document from a file.
     *
     * @param a_path The path to the file.
     *
     * @return True on success, false otherwise.
     */
    virtual bool loadDocumentFromFile(
        std::string const a_path
    );

    /**
     * @brief Resets the document.
     */
    virtual void resetDocument();

    /**
     * @brief Appends the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual Network::XmlRPCCommon::Xml::IXmlNodeShrPtr appendNode(
        char const * a_name
    );

    /**
     * @brief Gets the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual Network::XmlRPCCommon::Xml::IXmlNodeShrPtr getNode(
        char const * a_name
    );

    /**
     * @brief Gets the content.
     *
     * @return The content.
     */
    virtual std::string toString() const;

private:
    /**
     * @brief The internal pugi xml document.
     */
    pugi::xml_document m_xml_document;
};

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_XML_XMLDOCUMENTPUGI_HPP
