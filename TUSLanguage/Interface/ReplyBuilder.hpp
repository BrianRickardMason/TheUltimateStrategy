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

#ifndef TUSLANGUAGE_REPLYBUILDER_HPP
#define TUSLANGUAGE_REPLYBUILDER_HPP

#include "ICommand.hpp"
#include <boost/noncopyable.hpp>

namespace TUSLanguage
{

class ReplyBuilder
    : boost::noncopyable
{
public:
    //@{
    /**
     * @brief Builds a reply.
     */
    ICommand::SingleHandle buildEchoReply()              const;
    ICommand::SingleHandle buildErrorReply()             const;
    ICommand::SingleHandle buildCreateLandReply()        const;
    ICommand::SingleHandle buildDeleteLandReply()        const;
    ICommand::SingleHandle buildGetLandReply()           const;
    ICommand::SingleHandle buildGetLandsReply()          const;
    ICommand::SingleHandle buildCreateSettlementReply()  const;
    ICommand::SingleHandle buildDeleteSettlementReply()  const;
    ICommand::SingleHandle buildGetSettlementReply()     const;
    ICommand::SingleHandle buildGetSettlementsReply()    const;
    ICommand::SingleHandle buildBuildBuildingReply()     const;
    ICommand::SingleHandle buildDestroyBuildingReply()   const;
    ICommand::SingleHandle buildGetBuildingReply()       const;
    ICommand::SingleHandle buildGetBuildingsReply()      const;
    ICommand::SingleHandle buildDismissHumanReply()      const;
    ICommand::SingleHandle buildEngageHumanReply()       const;
    ICommand::SingleHandle buildGetHumanReply()          const;
    ICommand::SingleHandle buildGetHumansReply()         const;
    ICommand::SingleHandle buildGetResourceReply()       const;
    ICommand::SingleHandle buildGetResourcesReply()      const;
    ICommand::SingleHandle buildCreateUserReply()        const;
    ICommand::SingleHandle buildCreateWorldReply()       const;
    ICommand::SingleHandle buildCreateEpochReply()       const;
    ICommand::SingleHandle buildDeleteEpochReply()       const;
    ICommand::SingleHandle buildActivateEpochReply()     const;
    ICommand::SingleHandle buildDeactivateEpochReply()   const;
    ICommand::SingleHandle buildFinishEpochReply()       const;
    ICommand::SingleHandle buildTickEpochReply()         const;
    ICommand::SingleHandle buildGetEpochReply()          const;
    ICommand::SingleHandle buildTransportHumanReply()    const;
    ICommand::SingleHandle buildTransportResourceReply() const;
    //}@
};

} // namespace TUSLanguage

#endif // TUSLANGUAGE_REPLYBUILDER_HPP
