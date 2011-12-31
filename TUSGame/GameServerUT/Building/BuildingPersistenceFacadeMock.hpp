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

#ifndef GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADEMOCK_HPP
#define GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADEMOCK_HPP

#include <TUSGame/GameServer/Building/IBuildingPersistenceFacade.hpp>
#include <gmock/gmock.h>

namespace GameServer
{
namespace Building
{

/**
 * @brief A mock of building persistence facade.
 */
class BuildingPersistenceFacadeMock
    : public IBuildingPersistenceFacade
{
public:
    /**
     * @brief Adds the building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     * @param a_volume      A volume of the building.
     *
     * TODO: Add @throw information.
     */
    MOCK_CONST_METHOD4(
        addBuilding,
        void(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            Configuration::IKey             const & a_key,
            Volume                          const & a_volume
        )
    );

    /**
     * @brief Subtracts the building.
     *
     * Returns true only if building was really subtracted.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     * @param a_volume      A volume of the building.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD4(
        subtractBuilding,
        bool(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            Configuration::IKey             const & a_key,
            Volume                          const & a_volume
        )
    );

    /**
     * @brief Gets a building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the building.
     *
     * @return The building, null if not found.
     */
    MOCK_CONST_METHOD3(
        getBuilding,
        BuildingWithVolumeShrPtr(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            Configuration::IKey             const & a_key
        )
    );

    /**
     * @brief Gets buildings.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     *
     * @return A map of buildings, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getBuildings,
        BuildingWithVolumeMap(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder
        )
    );
};

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADEMOCK_HPP
