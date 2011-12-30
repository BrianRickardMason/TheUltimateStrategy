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

#ifndef GAMESERVER_CONFIGURATION_RESOURCE_HPP
#define GAMESERVER_CONFIGURATION_RESOURCE_HPP

#include <TUSGame/GameServer/Configuration/Configurator/Resource/IResource.hpp>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief Resource.
 */
class Resource
    : public IResource
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_key  The key of the resource.
     * @param a_name The name of the resource.
     */
    Resource(
        IKey        const a_key,
        std::string const a_name
    );

    /**
     * @brief Gets the key of the resource.
     *
     * @return The key of the resource.
     */
    virtual IKey getKey() const;

    /**
     * @brief Gets the name of the resource.
     *
     * @return The name of the resource.
     */
    virtual std::string getName() const;

private:
    /**
     * @brief The key of the resource.
     */
    IKey const m_key;

    /**
     * @brief The name of the resource.
     */
    std::string const m_name;
};

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_RESOURCE_HPP
