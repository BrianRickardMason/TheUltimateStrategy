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

#include <TUSGame/GameServer/Epoch/EpochRecord.hpp>

using namespace std;

namespace GameServer
{
namespace Epoch
{

EpochRecord::EpochRecord(
    string       const a_epoch_name,
    string       const a_world_name,
    bool         const a_active,
    bool         const a_finished,
    unsigned int const a_ticks
)
    : m_epoch_name(a_epoch_name),
      m_world_name(a_world_name),
      m_active(a_active),
      m_finished(a_finished),
      m_ticks(a_ticks)
{
}

string EpochRecord::getEpochName() const
{
    return m_epoch_name;
}

string EpochRecord::getWorldName() const
{
    return m_world_name;
}

bool EpochRecord::getActive() const
{
    return m_active;
}

bool EpochRecord::getFinished() const
{
    return m_finished;
}

unsigned int EpochRecord::getTicks() const
{
    return m_ticks;
}

} // namespace Epoch
} // namespace GameServer
