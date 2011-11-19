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

#ifndef GAMESERVER_CONFIGURATION_HUMAN_HPP
#define GAMESERVER_CONFIGURATION_HUMAN_HPP

#include <GameServer/Configuration/Configurator/Human/IHuman.hpp>

namespace GameServer
{
namespace Configuration
{

/**
 * @brief Human.
 */
class Human
    : public IHuman
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_key         The key of the human.
     * @param a_class       The class of the human.
     * @param a_experience  The experience of the human.
     * @param a_name        The name of the human.
     * @param a_dismissable Defines whether human can be dismissed.
     * @param a_engageable  Defines whether human can be engaged.
     * @param a_production  The number of units of a resource produced per turn.
     */
    Human(
        IHumanKey    const a_key,
        std::string  const a_class,
        std::string  const a_name,
        std::string  const a_experience,
        bool         const a_dismissable,
        bool         const a_engageable,
        unsigned int const a_production
    );

    /**
     * @brief Gets the key of the human.
     *
     * @return The key of the human.
     */
    virtual IHumanKey getKey() const;

    /**
     * @brief Gets the class of the human.
     *
     * @return The class of the human.
     */
    virtual std::string getClass() const;

    /**
     * @brief Gets the name of the human.
     *
     * @return The name of the human.
     */
    virtual std::string getName() const;

    /**
     * @brief Gets the experience of the human.
     *
     * @return The experience of the human.
     */
    virtual std::string getExperience() const;

    /**
     * @brief Checks whether a human can be dismissed.
     *
     * @return True if human can be dismissed, false otherwise.
     */
    virtual bool isDismissable() const;

    /**
     * @brief Checks whether a human can be engaged.
     *
     * @return True if human can be engaged, false otherwise.
     */
    virtual bool isEngageable() const;

    /**
     * @brief Defines the number of units of a resource produced per turn.
     *
     * @return The number of units of a resource produced per turn.
     */
    virtual unsigned int getProduction() const;

private:
    /**
     * @brief The key of the human.
     */
    IHumanKey const m_key;

    /**
     * @brief The class of the human.
     */
    std::string const m_class;

    /**
     * @brief The name of the human.
     */
    std::string const m_name;

    /**
     * @brief The experience of the human.
     */
    std::string const m_experience;

    /**
     * @brief Defines whether a human can be dismissed.
     */
    bool const m_dismissable;

    /**
     * @brief Defines whether a human can be engaged.
     */
    bool const m_engageable;

    /**
     * @brief The number of units of a resource produced per turn.
     */
    unsigned int const m_production;
};

} // namespace Configuration
} // namespace GameServer

#endif // GAMESERVER_CONFIGURATION_HUMAN_HPP
