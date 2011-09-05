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

#include "Property.hpp"

namespace GameServer
{
namespace Property
{

Property::Property(
    IDProperty const & a_id_property
)
    : m_id_property(a_id_property)
{
}

IDProperty const & Property::getIDProperty() const
{
    return m_id_property;
}

PropertyBoolean::PropertyBoolean(
    PropertyRecordShrPtr a_property_record
)
    : Property(a_property_record->getIDProperty()),
      m_value(a_property_record->getValueBoolean())
{
}

PropertyBoolean::PropertyBoolean(
    IDProperty const & a_id_property,
    bool       const & a_value
)
    : Property(a_id_property),
      m_value(a_value)
{
}

bool const & PropertyBoolean::getValue() const
{
    return m_value;
}

PropertyInteger::PropertyInteger(
    PropertyRecordShrPtr a_property_record
)
    : Property(a_property_record->getIDProperty()),
      m_value(a_property_record->getValueInteger())
{
}

PropertyInteger::PropertyInteger(
    IDProperty const & a_id_property,
    int        const & a_value
)
    : Property(a_id_property),
      m_value(a_value)
{
}

int const & PropertyInteger::getValue() const
{
    return m_value;
}

PropertyString::PropertyString(
    PropertyRecordShrPtr a_property_record
)
    : Property(a_property_record->getIDProperty()),
      m_value(a_property_record->getValueString())
{
}

PropertyString::PropertyString(
    IDProperty  const & a_id_property,
    std::string const & a_value
)
    : Property(a_id_property),
      m_value(a_value)
{
}

std::string const & PropertyString::getValue() const
{
    return m_value;
}

} // namespace Property
} // namespace GameServer
