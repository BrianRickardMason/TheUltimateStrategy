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

#ifndef ICONTEXT_HPP
#define ICONTEXT_HPP

#include <Network/XmlRPCServer/Configurator/Building/IConfiguratorBuilding.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

/**
 * @brief The interface of Context.
 */
class IContext
    : private boost::noncopyable
{
public:
    virtual ~IContext(){}

    /**
     * @brief Gets the host's address.
     *
     * @return The host's address.
     */
    virtual std::string getHost() const = 0;

    /**
     * @brief Gets the host's port.
     *
     * @return The host's port.
     */
    virtual std::string getPort() const = 0;

    /**
     * @brief Gets the number of threads.
     *
     * @return The number of threads.
     */
    virtual unsigned short int getThreads() const = 0;

    /**
     * @brief Gets the logger's priority.
     *
     * @return The logger's priority.
     */
    virtual int getLoggerPriority() const = 0;

    /**
     * @brief Gets the name of the persistence.
     *
     * @return The name of the persistence.
     */
    virtual std::string getPersistence() const = 0;

    /**
     * @brief Gets ConfiguratorBuilding.
     *
     * @return ConfiguratorBuilding.
     */
    virtual IConfiguratorBuildingShrPtr getConfiguratorBuilding() const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IContext> IContextShrPtr;

#endif // ICONTEXT_HPP
