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

#include "PropertyRecord.hpp"

using namespace std;

using GameServer::Common::KeyHash;

namespace GameServer
{
namespace Property
{

PropertyRecord::PropertyRecord(
    KeyHash       const & a_key_hash,
    IDProperty    const & a_id_property,
    Discriminator const & a_discriminator,
    bool          const   a_value_boolean,
    int           const   a_value_integer,
    string        const & a_value_string
)
    : m_key_hash(a_key_hash),
      m_id_property(a_id_property),
      m_discriminator(a_discriminator),
      m_value_boolean(a_value_boolean),
      m_value_integer(a_value_integer),
      m_value_string(a_value_string)
{
}

KeyHash const & PropertyRecord::getKeyHash() const
{
    return m_key_hash;
}

IDProperty const & PropertyRecord::getIDProperty() const
{
    return m_id_property;
}

Discriminator const & PropertyRecord::getDiscriminator() const
{
    return m_discriminator;
}

bool PropertyRecord::getValueBoolean() const
{
    return m_value_boolean;
}

int PropertyRecord::getValueInteger() const
{
    return m_value_integer;
}

string const & PropertyRecord::getValueString() const
{
    return m_value_string;
}

} // namespace Property
} // namespace GameServer
