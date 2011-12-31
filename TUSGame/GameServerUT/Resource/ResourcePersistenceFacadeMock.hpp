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

#ifndef GAMESERVER_RESOURCE_RESOURCEPERSISTENCEFACADEMOCK_HPP
#define GAMESERVER_RESOURCE_RESOURCEPERSISTENCEFACADEMOCK_HPP

#include <TUSGame/GameServer/Resource/IResourcePersistenceFacade.hpp>
#include <gmock/gmock.h>

namespace GameServer
{
namespace Resource
{

/**
 * @brief A mock of resource persistence facade.
 */
class ResourcePersistenceFacadeMock
    : public IResourcePersistenceFacade
{
public:
    /**
     * @brief Adds the resource.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume of the resource.
     */
    MOCK_CONST_METHOD4(
        addResource,
        void(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            std::string                     const & a_key,
            Volume                          const & a_volume
        )
    );

    /**
     * @brief Subtracts the resource.
     *
     * Returns true only if resource was really subtracted.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume of the resource.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD4(
        subtractResource,
        bool(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            std::string                     const & a_key,
            Volume                          const & a_volume
        )
    );

    /**
     * @brief Safely subtracts the resource.
     *
     * If the volume of the resource is lower than the volume to be subtracted then the resource is deleted.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume of the resource.
     */
    MOCK_CONST_METHOD4(
        subtractResourceSafely,
        void(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            std::string                     const & a_key,
            Volume                          const & a_volume
        )
    );

    /**
     * @brief Subtracts the map of resources.
     *
     * Returns true only if the map of resources was really subtracted.
     *
     * @param a_transaction  The transaction.
     * @param a_id_holder    An identifier of the holder.
     * @param a_resource_map A map of resources.
     *
     * @return True on success, false otherwise.
     */
    MOCK_CONST_METHOD3(
        subtractResources,
        bool(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            ResourceWithVolumeMap           const & a_resource_map
        )
    );

    /**
     * @brief Safely subtracts the map of resources.
     *
     * If the volume of the resource is lower than the volume to be subtracted then the resource is deleted.
     *
     * @param a_transaction  The transaction.
     * @param a_id_holder    An identifier of the holder.
     * @param a_resource_map A map of resources.
     */
    MOCK_CONST_METHOD3(
        subtractResourcesSafely,
        void(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            ResourceWithVolumeMap           const & a_resource_map
        )
    );

    /**
     * @brief Gets a resource.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the resource.
     *
     * @return The resource, null if not found.
     */
    MOCK_CONST_METHOD3(
        getResource,
        ResourceWithVolumeShrPtr(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder,
            std::string                     const & a_key
        )
    );

    /**
     * @brief Gets resources.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     *
     * @return A map of resources, an empty map if not found.
     */
    MOCK_CONST_METHOD2(
        getResources,
        ResourceWithVolumeMap(
            Persistence::ITransactionShrPtr         a_transaction,
            Common::IDHolder                const & a_id_holder
        )
    );
};

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_RESOURCEPERSISTENCEFACADEMOCK_HPP
