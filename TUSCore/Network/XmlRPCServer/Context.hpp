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

#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <TUSCore/Network/XmlRPCServer/IContext.hpp>

/**
 * @brief Context.
 */
class Context
    : public IContext
{
public:
    /**
     * @brief Ctor.
     */
    Context();

    /**
     * @brief Gets Configurator.
     *
     * @return Configurator.
     */
    virtual IConfiguratorShrPtr getConfigurator() const;

    /**
     * @brief Gets ConfiguratorBase.
     *
     * @return ConfiguratorBase.
     */
    virtual IConfiguratorBaseShrPtr getConfiguratorBase() const;

    /**
     * @brief Gets ConfiguratorBuilding.
     *
     * @return ConfiguratorBuilding.
     */
    virtual IConfiguratorBuildingShrPtr getConfiguratorBuilding() const;

    /**
     * @brief Gets ConfiguratorHuman.
     *
     * @return ConfiguratorHuman.
     */
    virtual IConfiguratorHumanShrPtr getConfiguratorHuman() const;

    /**
     * @brief Gets ConfiguratorResource.
     *
     * @return ConfiguratorResource.
     */
    virtual IConfiguratorResourceShrPtr getConfiguratorResource() const;

private:
    /**
     * @brief Configurator.
     */
    IConfiguratorShrPtr const m_configurator;

    /**
     * @brief ConfiguratorBase.
     */
    IConfiguratorBaseShrPtr const m_configurator_base;

    /**
     * @brief ConfiguratorBuilding.
     */
    IConfiguratorBuildingShrPtr const m_configurator_building;

    /**
     * @brief ConfiguratorHuman.
     */
    IConfiguratorHumanShrPtr const m_configurator_human;

    /**
     * @brief ConfiguratorResource.
     */
    IConfiguratorResourceShrPtr const m_configurator_resource;
};

#endif // CONTEXT_HPP
