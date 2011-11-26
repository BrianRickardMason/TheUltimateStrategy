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

#include <Network/XmlRPCServer/IContext.hpp>

/**
 * @brief Context.
 */
class Context
    : public IContext
{
public:
    /**
     * @brief Ctor.
     *
     * @param a_host            The host's address.
     * @param a_port            The host's port.
     * @param a_threads         The number of threads.
     * @param a_logger_priority The logger's priority.
     * @param a_persistence     The name of the persistence.
     */
    Context(
        std::string        const a_host,
        std::string        const a_port,
        unsigned short int const a_threads,
        int                const a_logger_priority,
        std::string        const a_persistence
    );

    /**
     * @brief Gets the host's address.
     *
     * @return The host's address.
     */
    virtual std::string getHost() const;

    /**
     * @brief Gets the host's port.
     *
     * @return The host's port.
     */
    virtual std::string getPort() const;

    /**
     * @brief Gets the number of threads.
     *
     * @return The number of threads.
     */
    virtual unsigned short int getThreads() const;

    /**
     * @brief Gets the logger's priority.
     *
     * @return The logger's priority.
     */
    virtual int getLoggerPriority() const;

    /**
     * @brief Gets the name of the persistence.
     *
     * @return The name of the persistence.
     */
    virtual std::string getPersistence() const;

private:
    /**
     * @brief The host's address.
     */
    std::string m_host;

    /**
     * @brief The host's port.
     */
    std::string m_port;

    /**
     * @brief The number of threads.
     */
    unsigned short int m_threads;

    /**
     * @brief The logger's priority.
     */
    int m_logger_priority;

    /**
     * @brief The name of the persistence.
     */
    std::string m_persistence;
};

#endif // CONTEXT_HPP
