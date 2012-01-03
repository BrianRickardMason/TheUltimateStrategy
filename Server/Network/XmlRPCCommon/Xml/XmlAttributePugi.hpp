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

#ifndef NETWORK_XMLRPCCOMMON_XML_XMLATTRIBUTEPUGI_HPP
#define NETWORK_XMLRPCCOMMON_XML_XMLATTRIBUTEPUGI_HPP

#include <Game/3rdParty/pugixml/src/pugixml.hpp>
#include <Server/Network/XmlRPCCommon/Xml/IXmlAttribute.hpp>

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

/**
 * @brief The pugi xml attribute.
 */
class XmlAttributePugi
    : public IXmlAttribute
{
public:
    /**
     * @brief Constructs the attribute.
     *
     * @param a_xml_attribute The internal pugi xml attribute.
     */
    XmlAttributePugi(
        pugi::xml_attribute a_xml_attribute
    );

    /**
     * @brief Gets the value of the attribute as integer.
     *
     * @return The value.
     */
    virtual int asInt() const;

    /**
     * @brief Gets the value of the attribute as unsigned integer.
     *
     * @return The value.
     */
    virtual unsigned int asUnsignedInt() const;

    /**
     * @brief Gets the value of the attribute.
     *
     * @return The value.
     */
    virtual char const * getValue() const;

    /**
     * @brief Sets the value of the attribute.
     *
     * @param a_value The value of the attribute.
     *
     * @return True on success, false otherwise.
     */
    virtual bool setValue(
        bool a_value
    );

    /**
     * @brief Sets the value of the attribute.
     *
     * @param a_value The value of the attribute.
     *
     * @return True on success, false otherwise.
     */
    virtual bool setValue(
        double a_value
    );

    /**
     * @brief Sets the value of the attribute.
     *
     * @param a_value The value of the attribute.
     *
     * @return True on success, false otherwise.
     */
    virtual bool setValue(
        int a_value
    );

    /**
     * @brief Sets the value of the attribute.
     *
     * @param a_value The value of the attribute.
     *
     * @return True on success, false otherwise.
     */
    virtual bool setValue(
        unsigned int a_value
    );

    /**
     * @brief Sets the value of the attribute.
     *
     * @param a_value The value of the attribute.
     *
     * @return True on success, false otherwise.
     */
    virtual bool setValue(
        char const * a_value
    );

private:
    /**
     * @brief The internal pugi xml attribute.
     */
    pugi::xml_attribute m_xml_attribute;
};

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_XML_XMLATTRIBUTEPUGI_HPP
