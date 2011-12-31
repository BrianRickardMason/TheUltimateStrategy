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

#ifndef NETWORK_XMLRPCCOMMON_XML_IXMLDOCUMENT_HPP
#define NETWORK_XMLRPCCOMMON_XML_IXMLDOCUMENT_HPP

#include <TUSServer/Network/XmlRPCCommon/Xml/IXmlNode.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

/**
 * @brief The interface of the xml document.
 */
class IXmlDocument
{
public:
    /**
     * @brief Destructs the xml document.
     */
    virtual ~IXmlDocument(){};

    /**
     * @brief Loads the document from a string.
     *
     * @param a_string The string representation.
     *
     * @return True on success, false otherwise.
     */
    virtual bool loadDocument(
        std::string const & a_string
    ) = 0;

    /**
     * @brief Loads the document from a file.
     *
     * @param a_path The path to the file.
     *
     * @return True on success, false otherwise.
     */
    virtual bool loadDocumentFromFile(
        std::string const a_path
    ) = 0;

    /**
     * @brief Resets the document.
     */
    virtual void resetDocument() = 0;

    /**
     * @brief Appends the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual Network::XmlRPCCommon::Xml::IXmlNodeShrPtr appendNode(
        char const * a_name
    ) = 0;

    /**
     * @brief Gets the node.
     *
     * @param a_name The name of the node.
     *
     * @return The node on success, null otherwise.
     */
    virtual Network::XmlRPCCommon::Xml::IXmlNodeShrPtr getNode(
        char const * a_name
    ) = 0;

    /**
     * @brief Gets the content.
     *
     * @return The content.
     */
    virtual std::string toString() const = 0;
};

/**
 * @brief The shared pointer of interface of the xml document.
 */
typedef boost::shared_ptr<IXmlDocument> IXmlDocumentShrPtr;

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_XML_IXMLDOCUMENT_HPP
