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

#ifndef NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_IEXECUTOR_HPP
#define NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_IEXECUTOR_HPP

#include "../../../XmlRPCCommon/Reply/Reply.hpp"
#include "../../../XmlRPCCommon/Request/Request.hpp"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace Network
{
namespace XmlRPCServer
{
namespace Request
{
namespace Executors
{

/**
 * @brief An interface of the executor.
 */
class IExecutor
    : boost::noncopyable
{
public:
    /**
     * @brief Destructs the executor.
     */
    virtual ~IExecutor(){};

    /**
     * @brief Executes the action.
     *
     * @param a_request A request.
     *
     * @return A reply.
     */
    virtual XmlRPCCommon::Reply::ReplyShrPtr execute(
        XmlRPCCommon::Request::RequestShrPtr a_request
    ) = 0;
};

/**
 * @brief A shared pointer of the interface of the executor.
 */
typedef boost::shared_ptr<IExecutor> IExecutorShrPtr;

} // namespace Executors
} // namespace Request
} // namespace XmlRPCServer
} // namespace Network

#endif // NETWORK_XMLRPCSERVER_REQUEST_EXECUTORS_IEXECUTOR_HPP
