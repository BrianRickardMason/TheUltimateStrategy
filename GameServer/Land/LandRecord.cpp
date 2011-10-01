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

#include "LandRecord.hpp"

using namespace GameServer::Epoch;
using namespace GameServer::World;
using namespace std;

namespace GameServer
{
namespace Land
{

LandRecord::LandRecord(
    string  const   a_login,
    IDWorld const & a_id_world,
    IDEpoch const & a_id_epoch,
    IDLand  const & a_id_land,
    string  const & a_name,
    bool            a_granted
)
    : m_login(a_login),
      m_id_world(a_id_world),
      m_id_epoch(a_id_epoch),
      m_id_land(a_id_land),
      m_name(a_name),
      m_granted(a_granted)
{
}

string LandRecord::getLogin() const
{
    return m_login;
}

IDWorld const & LandRecord::getIDWorld() const
{
    return m_id_world;
}

IDEpoch const & LandRecord::getIDEpoch() const
{
    return m_id_epoch;
}

IDLand const & LandRecord::getIDLand() const
{
    return m_id_land;
}

string const & LandRecord::getName() const
{
    return m_name;
}

bool LandRecord::getGranted() const
{
    return m_granted;
}

} // namespace Land
} // namespace GameServer
