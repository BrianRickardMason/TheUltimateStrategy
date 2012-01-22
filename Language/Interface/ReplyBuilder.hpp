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

#ifndef LANGUAGE_REPLYBUILDER_HPP
#define LANGUAGE_REPLYBUILDER_HPP

#include <Language/Interface/ICommand.hpp>
#include <boost/noncopyable.hpp>

namespace Language
{

// TODO: Refactor me!

class ReplyBuilder
    : boost::noncopyable
{
public:
    ICommand::Handle buildEchoReply(
        unsigned short int const a_code
    ) const;

    ICommand::Handle buildErrorReply(
        unsigned short int const a_code
    ) const;

    ICommand::Handle buildCreateLandReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildDeleteLandReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetLandReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetLandReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildGetLandsReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetLandsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    ICommand::Handle buildCreateSettlementReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildDeleteSettlementReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetSettlementReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetSettlementReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildGetSettlementsReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetSettlementsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    ICommand::Handle buildBuildBuildingReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildDestroyBuildingReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetBuildingReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetBuildingReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildGetBuildingsReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetBuildingsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    ICommand::Handle buildDismissHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildEngageHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetHumanReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildGetHumansReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetHumansReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    ICommand::Handle buildGetResourceReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetResourceReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildGetResourcesReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetResourcesReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    ICommand::Handle buildCreateUserReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildCreateWorldReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildCreateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildDeleteEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildActivateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildDeactivateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildFinishEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildTickEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildGetEpochReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    ICommand::Handle buildTransportHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    ICommand::Handle buildTransportResourceReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;
};

} // namespace Language

#endif // LANGUAGE_REPLYBUILDER_HPP
