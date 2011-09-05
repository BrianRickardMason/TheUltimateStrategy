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

#ifndef GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOREXITCODE_HPP
#define GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOREXITCODE_HPP

#include "../../BuildingWithVolume.hpp"

namespace GameServer
{
namespace Building
{

/**
 * @brief Available exit codes.
 */
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDINGS_MISSING_IN_THE_MEANTIME = 1;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED       = 2;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_BUILDINGS              = 3;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_NOT_ENOUGH_RESOURCES              = 4;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_RESOURCES_MISSING_IN_THE_MEANTIME = 5;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_THERE_ARE_NO_BUILDINGS            = 6;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_TRYING_TO_DESTROY_ZERO_BUILDINGS  = 7;
unsigned short int const DESTROY_BUILDING_OPERATOR_EXIT_CODE_UNEXPECTED_ERROR                  = 8;

/**
 * @brief The exit code of DestroyBuildingOperator.
 */
class DestroyBuildingOperatorExitCode
{
public:
    /**
     * @brief Constructs the exit code.
     *
     * @param a_exit_code The value of the exit code.
     */
    DestroyBuildingOperatorExitCode(
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
        return (m_exit_code == DESTROY_BUILDING_OPERATOR_EXIT_CODE_BUILDING_HAS_BEEN_DESTROYED) ? true : false;
    }

    /**
     * @brief The exit code.
     */
    unsigned short int const m_exit_code;
};

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_DESTROYBUILDINGOPERATOREXITCODE_HPP
