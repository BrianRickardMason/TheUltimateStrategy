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

#include <TUSServer/Network/XmlRPCCommon/Xml/XmlAttributePugi.hpp>
#include <boost/make_shared.hpp>

using namespace pugi;

namespace Network
{
namespace XmlRPCCommon
{
namespace Xml
{

XmlAttributePugi::XmlAttributePugi(
    xml_attribute a_xml_attribute
)
    : m_xml_attribute(a_xml_attribute)
{
}

int XmlAttributePugi::asInt() const
{
    return m_xml_attribute.as_int();
}

unsigned int XmlAttributePugi::asUnsignedInt() const
{
    return m_xml_attribute.as_uint();
}

char const * XmlAttributePugi::getValue() const
{
    return m_xml_attribute.value();
}

bool XmlAttributePugi::setValue(
    bool a_value
)
{
    return m_xml_attribute.set_value(a_value);
}

bool XmlAttributePugi::setValue(
    double a_value
)
{
    return m_xml_attribute.set_value(a_value);
}

bool XmlAttributePugi::setValue(
    int a_value
)
{
    return m_xml_attribute.set_value(a_value);
}

bool XmlAttributePugi::setValue(
    unsigned int a_value
)
{
    return m_xml_attribute.set_value(a_value);
}

bool XmlAttributePugi::setValue(
    char const * a_value
)
{
    return m_xml_attribute.set_value(a_value);
}

} // namespace Xml
} // namespace XmlRPCCommon
} // namespace Network
