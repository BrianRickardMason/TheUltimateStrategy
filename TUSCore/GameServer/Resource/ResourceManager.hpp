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

#ifndef GAMESERVER_RESOURCE_RESOURCEMANAGER_HPP
#define GAMESERVER_RESOURCE_RESOURCEMANAGER_HPP

#include "IResourceManager.hpp"
#include "IResourceManagerAccessor.hpp"

namespace GameServer
{
namespace Resource
{

/**
 * @brief The resource manager.
 */
class ResourceManager
    : public IResourceManager
{
public:
    /**
     * @brief Constructs the resource manager.
     *
     * @param a_accessor An accessor to be injected.
     */
    ResourceManager(
        IResourceManagerAccessorAutPtr a_accessor
    );

    /**
     * @brief Adds the resource.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   An identifier of the holder.
     * @param a_key         A key of the resource.
     * @param a_volume      A volume of the resource.
     */
    virtual void addResource(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

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
    virtual bool subtractResource(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

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
    virtual void subtractResourceSafely(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key,
        Volume                          const & a_volume
    ) const;

    /**
     * @brief Subtracts the set of resources.
     *
     * Returns true only if the set of resources was really subtracted.
     *
     * @param a_transaction  The transaction.
     * @param a_id_holder    An identifier of the holder.
     * @param a_resource_set A set of resources.
     *
     * @return True on success, false otherwise.
     */
    virtual bool subtractResourceSet(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        ResourceSet                     const & a_resource_set
    ) const;

    /**
     * @brief Safely subtracts the set of resources.
     *
     * If the volume of the resource is lower than the volume to be subtracted then the resource is deleted.
     *
     * @param a_transaction  The transaction.
     * @param a_id_holder    An identifier of the holder.
     * @param a_resource_set A set of resources.
     */
    virtual void subtractResourceSetSafely(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        ResourceSet                     const & a_resource_set
    ) const;

    /**
     * @brief Gets a resource.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     * @param a_key         The key of the resource.
     *
     * @return The resource, null if not found.
     */
    virtual ResourceWithVolumeShrPtr getResource(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder,
        Key                             const & a_key
    ) const;

    /**
     * @brief Gets resources.
     *
     * @param a_transaction The transaction.
     * @param a_id_holder   The identifier of the holder.
     *
     * @return A map of resources, an empty map if not found.
     */
    virtual ResourceSet getResources(
        Persistency::ITransactionShrPtr         a_transaction,
        Common::IDHolder                const & a_id_holder
    ) const;

private:
    /**
     * @brief An accessor.
     */
    IResourceManagerAccessorScpPtr m_accessor;
};

/**
 * @brief An auto pointer of resource manager.
 */
typedef std::auto_ptr<ResourceManager> ResourceManagerAutPtr;

} // namespace Resource
} // namespace GameServer

#endif // GAMESERVER_RESOURCE_RESOURCEMANAGER_HPP