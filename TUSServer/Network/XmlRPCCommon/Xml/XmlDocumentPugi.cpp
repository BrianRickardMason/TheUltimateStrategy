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

#include "XmlDocumentPugi.hpp"
#include "XmlNodePugi.hpp"
#include <boost/make_shared.hpp>

using namespace boost;
using namespace std;
using namespace pugi;

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

/**
 * @brief A string xml writer.
 */
class XmlStringWriter
    : public xml_writer
{
public:
    /**
     * @brief Writes the xml document to the string.
     *
     * @param a_data The data to be written.
     * @pram  a_size The size of the data.
     */
    virtual void write(
        void   const * a_data,
        size_t         a_size
    )
    {
        m_result += string(static_cast<const char*>(a_data), a_size);
    }

    /**
     * @brief The string result.
     */
    string m_result;
};

bool XmlDocumentPugi::loadDocument(
    string const & a_string
)
{
    xml_parse_result result = m_xml_document.load_buffer(a_string.c_str(), a_string.size());

    return (result) ? true : false;
}

bool XmlDocumentPugi::loadDocumentFromFile(
    string const a_path
)
{
    xml_parse_result result = m_xml_document.load_file(a_path.c_str());

    return (result) ? true : false;
}

void XmlDocumentPugi::resetDocument()
{
    m_xml_document.reset();
}

IXmlNodeShrPtr XmlDocumentPugi::appendNode(
    char const * a_name
)
{
    xml_node xml_node = m_xml_document.append_child(a_name);

    return (xml_node) ? make_shared<XmlNodePugi>(xml_node) : IXmlNodeShrPtr();
}

IXmlNodeShrPtr XmlDocumentPugi::getNode(
    char const * a_name
)
{
    xml_node xml_node = m_xml_document.child(a_name);

    return (xml_node) ? make_shared<XmlNodePugi>(xml_node) : IXmlNodeShrPtr();
}

string XmlDocumentPugi::toString() const
{
    XmlStringWriter writer;

    m_xml_document.save(writer);

    return writer.m_result;
}

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network
