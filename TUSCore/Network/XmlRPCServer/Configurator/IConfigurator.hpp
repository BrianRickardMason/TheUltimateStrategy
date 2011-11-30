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

#ifndef ICONFIGURATOR_HPP
#define ICONFIGURATOR_HPP

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

/**
 * @brief The interface of Configurator.
 */
class IConfigurator
    : private boost::noncopyable
{
public:
    virtual ~IConfigurator(){};

    /**
     * @brief Gets the configuration.
     *
     * @brief True on success, false otherwise.
     */
    virtual bool configure() = 0;

    /**
     * @brief Gets the host's address.
     *
     * @brief The host's address.
     */
    virtual std::string getHost() const = 0;

    /**
     * @brief Gets the host's port.
     *
     * @brief The host's port.
     */
    virtual std::string getPort() const = 0;

    /**
     * @brief Gets the number of threads.
     *
     * @brief The number of threads.
     */
    virtual unsigned short int getThreads() const = 0;

    /**
     * @brief Gets the logger's priority.
     *
     * @brief The logger's priority.
     */
    virtual int getLoggerPriority() const = 0;

    /**
     * @brief Gets the name of the persistence.
     *
     * @brief The name of the persistence.
     */
    virtual std::string getPersistence() const = 0;

    /**
     * @brief Gets the path to the configuration files.
     *
     * @brief The path to the configuration files.
     */
    virtual std::string getConfigurationPath() const = 0;

    /**
     * @brief Gets the name of the selected configuration.
     *
     * @brief The name of the selected configuration.
     */
    virtual std::string getConfigurationSelected() const = 0;
};

/**
 * @brief A useful typedef.
 */
typedef boost::shared_ptr<IConfigurator> IConfiguratorShrPtr;

#endif // ICONFIGURATOR_HPP
