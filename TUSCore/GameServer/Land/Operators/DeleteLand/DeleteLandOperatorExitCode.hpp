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

#ifndef GAMESERVER_LAND_DELETELANDOPERATOREXITCODE_HPP
#define GAMESERVER_LAND_DELETELANDOPERATOREXITCODE_HPP

namespace GameServer
{
namespace Land
{

/**
 * @brief Available exit codes.
 */
unsigned short int const DELETE_LAND_OPERATOR_EXIT_CODE_LAND_DOES_NOT_EXIST       = 1;
unsigned short int const DELETE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_DELETED     = 2;
unsigned short int const DELETE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_NOT_BEEN_DELETED = 3;
unsigned short int const DELETE_LAND_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR          = 4;

/**
 * @brief The exit code of DeleteLandOperator.
 */
class DeleteLandOperatorExitCode
{
public:
    /**
     * @brief Constructs the exit code.
     *
     * @param a_exit_code The value of the exit code.
     */
    DeleteLandOperatorExitCode(
        unsigned short int const a_exit_code
    )
        : m_exit_code(a_exit_code)
    {
    }

    /**
     * @brief The "ok" method.
     *
     * @return True on success, false otherwise.
     */
    bool ok() const
    {
        return (m_exit_code == DELETE_LAND_OPERATOR_EXIT_CODE_LAND_HAS_BEEN_DELETED) ? true : false;
    }

    /**
     * @brief The exit code.
     */
    unsigned short int const m_exit_code;
};

} // namespace Land
} // namespace GameServer

#endif // GAMESERVER_LAND_DELETELANDOPERATOREXITCODE_HPP
