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

#include <Language/Interface/ICommand.hpp>
#include <boost/noncopyable.hpp>

namespace TUSLanguage
{

// TODO: Refactor me!

class ReplyBuilder
    : boost::noncopyable
{
public:
    /**
     * @brief Builds EchoReply.
     *
     * @param a_code The exit code.
     *
     * @return EchoReply.
     */
    ICommand::SingleHandle buildEchoReply(
        unsigned short int const a_code
    ) const;

    /**
     * @brief Builds ErrorReply.
     *
     * @param a_code The exit code.
     *
     * @return ErrorReply.
     */
    ICommand::SingleHandle buildErrorReply(
        unsigned short int const a_code
    ) const;

    /**
     * @brief Builds CreateLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateLandReply.
     */
    ICommand::SingleHandle buildCreateLandReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds DeleteLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteLandReply.
     */
    ICommand::SingleHandle buildDeleteLandReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds GetLandReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetLandReply.
     */
    ICommand::SingleHandle buildGetLandReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    /**
     * @brief Builds GetLandsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetLandsReply.
     */
    ICommand::SingleHandle buildGetLandsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    /**
     * @brief Builds CreateSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateSettlementReply.
     */
    ICommand::SingleHandle buildCreateSettlementReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds DeleteSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteSettlementReply.
     */
    ICommand::SingleHandle buildDeleteSettlementReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds GetSettlementReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetSettlementReply.
     */
    ICommand::SingleHandle buildGetSettlementReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    /**
     * @brief Builds GetSettlementsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetSettlementsReply.
     */
    ICommand::SingleHandle buildGetSettlementsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    /**
     * @brief Builds BuildBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return BuildBuildingReply.
     */
    ICommand::SingleHandle buildBuildBuildingReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds DestroyBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DestroyBuildingReply.
     */
    ICommand::SingleHandle buildDestroyBuildingReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds GetBuildingReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetBuildingReply.
     */
    ICommand::SingleHandle buildGetBuildingReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    /**
     * @brief Builds GetBuildingsReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetBuildingsReply.
     */
    ICommand::SingleHandle buildGetBuildingsReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    /**
     * @brief Builds DismissHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DismissHumanReply.
     */
    ICommand::SingleHandle buildDismissHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds EngageHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return EngageHumanReply.
     */
    ICommand::SingleHandle buildEngageHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds GetHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetHumanReply.
     */
    ICommand::SingleHandle buildGetHumanReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    /**
     * @brief Builds GetHumansReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetHumansReply.
     */
    ICommand::SingleHandle buildGetHumansReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    /**
     * @brief Builds GetResourceReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetResourceReply.
     */
    ICommand::SingleHandle buildGetResourceReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;

    /**
     * @brief Builds GetResourcesReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_objects The objects.
     *
     * @return GetResourcesReply.
     */
    ICommand::SingleHandle buildGetResourcesReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Objects  const & a_objects
    ) const;

    /**
     * @brief Builds CreateUserReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateUserReply.
     */
    ICommand::SingleHandle buildCreateUserReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds CreateWorldReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateWorldReply.
     */
    ICommand::SingleHandle buildCreateWorldReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds CreateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return CreateEpochReply.
     */
    ICommand::SingleHandle buildCreateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds DeleteEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DeleteEpochReply.
     */
    ICommand::SingleHandle buildDeleteEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds ActivateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return ActivateEpochReply.
     */
    ICommand::SingleHandle buildActivateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds DectivateEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return DectivateEpochReply.
     */
    ICommand::SingleHandle buildDeactivateEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds FinishEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return FinishEpochReply.
     */
    ICommand::SingleHandle buildFinishEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds TickEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TickEpochReply.
     */
    ICommand::SingleHandle buildTickEpochReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds TransportHumanReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TransportHumanReply.
     */
    ICommand::SingleHandle buildTransportHumanReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds TransportResourceReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     *
     * @return TransportResourceReply.
     */
    ICommand::SingleHandle buildTransportResourceReply(
        unsigned short int const a_code,
        std::string        const a_message
    ) const;

    /**
     * @brief Builds GetEpochReply.
     *
     * @param a_code    The exit code.
     * @param a_message The status message.
     * @param a_object  The object.
     *
     * @return GetEpochReply.
     */
    ICommand::SingleHandle buildGetEpochReply(
        unsigned short int const   a_code,
        std::string        const   a_message,
        ICommand::Object   const & a_object
    ) const;
};

} // namespace TUSLanguage

#endif // TUSLANGUAGE_REPLYBUILDER_HPP
