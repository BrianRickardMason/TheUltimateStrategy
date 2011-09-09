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

#ifndef GAMESERVER_WORLDCONFIGURATION_IVERIFYTURNOPERATOR_HPP
#define GAMESERVER_WORLDCONFIGURATION_IVERIFYTURNOPERATOR_HPP

#include "../../../World/IWorld.hpp"
#include "VerifyTurnOperatorExitCode.hpp"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace WorldConfiguration
{

/**
 * @brief The interface of VerifyTurnOperator.
 */
class IVerifyTurnOperator
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs VerifyTurnOperator.
     */
    virtual ~IVerifyTurnOperator(){};

    /**
     * @brief Verifies whether the turn can be performed.
     *
     * @param a_world The world.
     *
     * @return The exit code.
     */
    virtual VerifyTurnOperatorExitCode verifyTurn(
        World::IWorldShrPtr a_world
    ) const = 0;
};

/**
 * @brief The shared pointer of the interface of VerifyTurnOperator.
 */
typedef boost::shared_ptr<IVerifyTurnOperator> IVerifyTurnOperatorShrPtr;

} // namespace WorldConfiguration
} // namespace GameServer

#endif // GAMESERVER_WORLDCONFIGURATION_IVERIFYTURNOPERATOR_HPP
