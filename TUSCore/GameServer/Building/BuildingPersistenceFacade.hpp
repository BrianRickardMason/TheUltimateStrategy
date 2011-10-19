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

#ifndef GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADE_HPP
#define GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADE_HPP

#include "IBuildingAccessor.hpp"
#include "IBuildingPersistenceFacade.hpp"

namespace GameServer
{
namespace Building
{

/**
 * @brief A building persistence facade.
 */
class BuildingPersistenceFacade
    : public IBuildingPersistenceFacade
{
public:
    /**
     * @brief Constructs the building persistence facade.
     *
     * @param a_accessor An accessor to be injected.
     */
    BuildingPersistenceFacade(
        IBuildingAccessorAutPtr a_accessor
    );

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
    virtual void addBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

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
    virtual bool subtractBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Gets a building.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the building.
     *
     * @return The building, null if not found.
     */
    virtual BuildingWithVolumeShrPtr getBuilding(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const;

    /**
     * @brief Gets buildings.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     *
     * @return A map of buildings, an empty map if not found.
     */
    virtual BuildingWithVolumeMap getBuildings(
        Persistence::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IBuildingAccessorScpPtr m_accessor;
};

/**
 * @brief An auto pointer of building persistence facade.
 */
typedef std::auto_ptr<BuildingPersistenceFacade> BuildingPersistenceFacadeAutPtr;

} // namespace Building
} // namespace GameServer

#endif // GAMESERVER_BUILDING_BUILDINGPERSISTENCEFACADE_HPP
