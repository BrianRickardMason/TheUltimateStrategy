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

#ifndef ICONFIGURATORBASE_HPP
#define ICONFIGURATORBASE_HPP

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

/**
 * @brief The interface of ConfiguratorBase.
 */
class IConfiguratorBase
    : private boost::noncopyable
{
public:
    virtual ~IConfiguratorBase(){};

    /**
     * @brief Gets the configuration.
     *
     * @return True on success, false otherwise.
     */
    virtual bool configure() = 0;

    /**
     * @brief Gets the famine death factor.
     *
     * @return The value of the famine death factor in percents.
     */
    virtual unsigned short int getFamineDeathFactor() const = 0;

    /**
     * @brief Gets the human experience factor.
     *
     * @return The value of the human experience factor in percents.
     */
    virtual unsigned short int getHumanExperienceFactor() const = 0;

    /**
     * @brief Gets the human reproduce factor.
     *
     * @return The value of the human reproduce factor in percents.
     */
    virtual unsigned short int getHumanReproduceFactor() const = 0;

    /**
     * @brief Gets the poverty dismiss factor.
     *
     * @return The value of the poverty dismiss factor in percents.
     */
    virtual unsigned short int getPovertyDismissFactor() const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IConfiguratorBase> IConfiguratorBaseShrPtr;

#endif // ICONFIGURATORBASE_HPP
