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

#ifndef GAMESERVER_CONFIGURATION_BUILDING_HPP
#define GAMESERVER_CONFIGURATION_BUILDING_HPP

#include <GameServer/Configuration/Configurator/Building/IBuilding.hpp>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief Building.
 */
class Building
    : public IBuilding
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_key   The key of the building.
     * @param a_class The class of the building.
     * @param a_name  The name of the building.
     */
    Building(
        IBuildingKey const a_key,
        std::string  const a_class,
        std::string  const a_name
    );

    /**
     * @brief Gets the key of the building.
     *
     * @return The key of the building.
     */
    virtual IBuildingKey getKey() const;

    /**
     * @brief Gets the class of the building.
     *
     * @return The class of the building.
     */
    virtual std::string getClass() const;

    /**
     * @brief Gets the name of the building.
     *
     * @return The name of the building.
     */
    virtual std::string getName() const;

private:
    /**
     * @brief The key of the building.
     */
    IBuildingKey const m_key;

    /**
     * @brief The class of the building.
     */
    std::string const m_class;

    /**
     * @brief The name of the building.
     */
    std::string const m_name;
};

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_BUILDING_HPP
