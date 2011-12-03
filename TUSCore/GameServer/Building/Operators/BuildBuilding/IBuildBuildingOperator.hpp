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

#ifndef GAMESERVER_BUILDING_IBUILDBUILDINGOPERATOR_HPP
#define GAMESERVER_BUILDING_IBUILDBUILDINGOPERATOR_HPP

#include <GameServer/Building/Operators/BuildBuilding/BuildBuildingOperatorExitCode.hpp>
#include <GameServer/Building/Volume.hpp>
#include <GameServer/Common/IDHolder.hpp>
#include <GameServer/Configuration/Configurator/Building/IBuilding.hpp>
#include <GameServer/Persistence/ITransaction.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace GameServer
{
namespace Building
{

/**
 * @brief The interface of BuildBuildingOperator.
 */
class IBuildBuildingOperator
    : boost::noncopyable
{
public:
    virtual ~IBuildBuildingOperator(){};

    /**
     * @brief Builds a building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the building.
     * @param a_volume      The volume of the building.
     *
     * @returns The exit code.
     */
    virtual BuildBuildingOperatorExitCode buildBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Configuration::IKey             const & a_key,
        Volume                          const & a_volume
    ) const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IBuildBuildingOperator> IBuildBuildingOperatorShrPtr;

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_IBUILSBUILDINGOPERATOR_HPP
