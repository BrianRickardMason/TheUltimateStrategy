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

#ifndef GAMESERVER_HUMAN_GETHUMANOPERATOREXITCODE_HPP
#define GAMESERVER_HUMAN_GETHUMANOPERATOREXITCODE_HPP

#include "../../HumanWithVolume.hpp"

namespace GameServer
{
namespace Human
{

/**
 * @brief Available exit codes.
 */
unsigned short int const GET_HUMAN_OPERATOR_EXIT_CODE_HUMAN_HAS_BEEN_GOT = 1;
unsigned short int const GET_HUMAN_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR   = 2;

/**
 * @brief The exit code of GetHumanOperator.
 */
class GetHumanOperatorExitCode
{
public:
    /**
     * @brief Constructs the exit code.
     *
     * @param a_exit_code The value of the exit code.
     */
    GetHumanOperatorExitCode(
        unsigned short int const a_exit_code
    )
        : m_exit_code(a_exit_code),
          m_human(HumanWithVolumeShrPtr())
    {
    }

    /**
     * @brief Constructs the exit code.
     *
     * @param a_exit_code The value of the exit code.
     * @param a_human     The human.
     */
    GetHumanOperatorExitCode(
        unsigned short int    const a_exit_code,
        HumanWithVolumeShrPtr const a_human
    )
        : m_exit_code(a_exit_code),
          m_human(a_human)
    {
    }

    /**
     * @brief The "ok" method.
     *
     * @return False (a read-only operator).
     */
    bool ok() const
    {
        return false;
    }

    /**
     * @brief The exit code.
     */
    unsigned short int const m_exit_code;

    /**
     * @brief The human.
     */
    HumanWithVolumeShrPtr const m_human;
};

} // namespace Human
} // namespace GameServer

#endif // GAMESERVER_HUMAN_GETHUMANOPERATOREXITCODE_HPP
