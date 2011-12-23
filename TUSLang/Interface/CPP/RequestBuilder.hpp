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

#ifndef TUSLANG_REQUESTBUILDER_HPP
#define TUSLANG_REQUESTBUILDER_HPP

#include "ICommand.hpp"
#include <boost/noncopyable.hpp>

namespace TUSLang
{

class RequestBuilder
    : boost::noncopyable
{
public:
    //@{
    /**
     * @brief Builds a request.
     */
    ICommand::SingleHandle buildEchoRequest()              const;
    ICommand::SingleHandle buildErrorRequest()             const;
    ICommand::SingleHandle buildCreateLandRequest()        const;
    ICommand::SingleHandle buildDeleteLandRequest()        const;
    ICommand::SingleHandle buildGetLandRequest()           const;
    ICommand::SingleHandle buildGetLandsRequest()          const;
    ICommand::SingleHandle buildCreateSettlementRequest()  const;
    ICommand::SingleHandle buildDeleteSettlementRequest()  const;
    ICommand::SingleHandle buildGetSettlementRequest()     const;
    ICommand::SingleHandle buildGetSettlementsRequest()    const;
    ICommand::SingleHandle buildBuildBuildingRequest()     const;
    ICommand::SingleHandle buildDestroyBuildingRequest()   const;
    ICommand::SingleHandle buildGetBuildingRequest()       const;
    ICommand::SingleHandle buildGetBuildingsRequest()      const;
    ICommand::SingleHandle buildDismissHumanRequest()      const;
    ICommand::SingleHandle buildEngageHumanRequest()       const;
    ICommand::SingleHandle buildGetHumanRequest()          const;
    ICommand::SingleHandle buildGetHumansRequest()         const;
    ICommand::SingleHandle buildGetResourceRequest()       const;
    ICommand::SingleHandle buildGetResourcesRequest()      const;
    ICommand::SingleHandle buildCreateUserRequest()        const;
    ICommand::SingleHandle buildCreateWorldRequest()       const;
    ICommand::SingleHandle buildCreateEpochRequest()       const;
    ICommand::SingleHandle buildDeleteEpochRequest()       const;
    ICommand::SingleHandle buildActivateEpochRequest()     const;
    ICommand::SingleHandle buildDeactivateEpochRequest()   const;
    ICommand::SingleHandle buildFinishEpochRequest()       const;
    ICommand::SingleHandle buildTickEpochRequest()         const;
    ICommand::SingleHandle buildGetEpochRequest()          const;
    ICommand::SingleHandle buildTransportHumanRequest()    const;
    ICommand::SingleHandle buildTransportResourceRequest() const;
    //}@
};

} // namespace TUSLang

#endif // TUSLANG_REQUESTBUILDER_HPP
