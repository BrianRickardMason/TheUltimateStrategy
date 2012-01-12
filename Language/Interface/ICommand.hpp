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

#ifndef TUSLANGUAGE_ICOMMAND_HPP
#define TUSLANGUAGE_ICOMMAND_HPP

#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include <vector>

namespace TUSLanguage
{

unsigned short int const ID_COMMAND_ECHO_REQUEST               = 1;
unsigned short int const ID_COMMAND_ERROR_REQUEST              = 2;
unsigned short int const ID_COMMAND_CREATE_LAND_REQUEST        = 3;
unsigned short int const ID_COMMAND_DELETE_LAND_REQUEST        = 4;
unsigned short int const ID_COMMAND_GET_LAND_REQUEST           = 5;
unsigned short int const ID_COMMAND_GET_LANDS_REQUEST          = 6;
unsigned short int const ID_COMMAND_CREATE_SETTLEMENT_REQUEST  = 7;
unsigned short int const ID_COMMAND_DELETE_SETTLEMENT_REQUEST  = 8;
unsigned short int const ID_COMMAND_GET_SETTLEMENT_REQUEST     = 9;
unsigned short int const ID_COMMAND_GET_SETTLEMENTS_REQUEST    = 10;
unsigned short int const ID_COMMAND_BUILD_BUILDING_REQUEST     = 11;
unsigned short int const ID_COMMAND_DESTROY_BUILDING_REQUEST   = 12;
unsigned short int const ID_COMMAND_GET_BUILDING_REQUEST       = 13;
unsigned short int const ID_COMMAND_GET_BUILDINGS_REQUEST      = 14;
unsigned short int const ID_COMMAND_DISMISS_HUMAN_REQUEST      = 15;
unsigned short int const ID_COMMAND_ENGAGE_HUMAN_REQUEST       = 16;
unsigned short int const ID_COMMAND_GET_HUMAN_REQUEST          = 17;
unsigned short int const ID_COMMAND_GET_HUMANS_REQUEST         = 18;
unsigned short int const ID_COMMAND_GET_RESOURCE_REQUEST       = 19;
unsigned short int const ID_COMMAND_GET_RESOURCES_REQUEST      = 20;
unsigned short int const ID_COMMAND_CREATE_USER_REQUEST        = 21;
unsigned short int const ID_COMMAND_CREATE_WORLD_REQUEST       = 22;
unsigned short int const ID_COMMAND_CREATE_EPOCH_REQUEST       = 23;
unsigned short int const ID_COMMAND_DELETE_EPOCH_REQUEST       = 24;
unsigned short int const ID_COMMAND_ACTIVATE_EPOCH_REQUEST     = 25;
unsigned short int const ID_COMMAND_DEACTIVATE_EPOCH_REQUEST   = 26;
unsigned short int const ID_COMMAND_FINISH_EPOCH_REQUEST       = 27;
unsigned short int const ID_COMMAND_TICK_EPOCH_REQUEST         = 28;
unsigned short int const ID_COMMAND_GET_EPOCH_REQUEST          = 29;
unsigned short int const ID_COMMAND_TRANSPORT_HUMAN_REQUEST    = 30;
unsigned short int const ID_COMMAND_TRANSPORT_RESOURCE_REQUEST = 31;
unsigned short int const ID_COMMAND_ECHO_REPLY                 = 32;
unsigned short int const ID_COMMAND_ERROR_REPLY                = 33;
unsigned short int const ID_COMMAND_CREATE_LAND_REPLY          = 34;
unsigned short int const ID_COMMAND_DELETE_LAND_REPLY          = 35;
unsigned short int const ID_COMMAND_GET_LAND_REPLY             = 36;
unsigned short int const ID_COMMAND_GET_LANDS_REPLY            = 37;
unsigned short int const ID_COMMAND_CREATE_SETTLEMENT_REPLY    = 38;
unsigned short int const ID_COMMAND_DELETE_SETTLEMENT_REPLY    = 39;
unsigned short int const ID_COMMAND_GET_SETTLEMENT_REPLY       = 40;
unsigned short int const ID_COMMAND_GET_SETTLEMENTS_REPLY      = 41;
unsigned short int const ID_COMMAND_BUILD_BUILDING_REPLY       = 42;
unsigned short int const ID_COMMAND_DESTROY_BUILDING_REPLY     = 43;
unsigned short int const ID_COMMAND_GET_BUILDING_REPLY         = 44;
unsigned short int const ID_COMMAND_GET_BUILDINGS_REPLY        = 45;
unsigned short int const ID_COMMAND_DISMISS_HUMAN_REPLY        = 46;
unsigned short int const ID_COMMAND_ENGAGE_HUMAN_REPLY         = 47;
unsigned short int const ID_COMMAND_GET_HUMAN_REPLY            = 48;
unsigned short int const ID_COMMAND_GET_HUMANS_REPLY           = 49;
unsigned short int const ID_COMMAND_GET_RESOURCE_REPLY         = 50;
unsigned short int const ID_COMMAND_GET_RESOURCES_REPLY        = 51;
unsigned short int const ID_COMMAND_CREATE_USER_REPLY          = 52;
unsigned short int const ID_COMMAND_CREATE_WORLD_REPLY         = 53;
unsigned short int const ID_COMMAND_CREATE_EPOCH_REPLY         = 54;
unsigned short int const ID_COMMAND_DELETE_EPOCH_REPLY         = 55;
unsigned short int const ID_COMMAND_ACTIVATE_EPOCH_REPLY       = 56;
unsigned short int const ID_COMMAND_DEACTIVATE_EPOCH_REPLY     = 57;
unsigned short int const ID_COMMAND_FINISH_EPOCH_REPLY         = 58;
unsigned short int const ID_COMMAND_TICK_EPOCH_REPLY           = 59;
unsigned short int const ID_COMMAND_GET_EPOCH_REPLY            = 60;
unsigned short int const ID_COMMAND_TRANSPORT_HUMAN_REPLY      = 61;
unsigned short int const ID_COMMAND_TRANSPORT_RESOURCE_REPLY   = 62;

class ICommand
{
public:
    // TODO: Rename to Handle.
    typedef boost::shared_ptr<ICommand> SingleHandle;
    typedef std::map<std::string, std::string> Object;
    typedef std::vector<Object> Objects;

    virtual ~ICommand(){}

    /**
     * @brief Gets the identifier of the command.
     *
     * @return The identifier of the command.
     */
    virtual unsigned short int getID() const = 0;

    /**
     * @brief Sets the identifier of the command.
     *
     * @param a_id The identifier of the command.
     */
    virtual void setID(
        unsigned short int const a_id
    ) = 0;

    /**
     * @brief Gets the login of the user.
     *
     * @return The login of the user, an empty string if not set.
     */
    virtual std::string getLogin() const = 0;

    /**
     * @brief Sets the login of the user.
     *
     * @param a_login The login of the user.
     */
    virtual void setLogin(
        std::string const a_login
    ) = 0;

    /**
     * @brief Gets the password of the user.
     *
     * @return The password of the user, an empty string if not set.
     */
    virtual std::string getPassword() const = 0;

    /**
     * @brief Sets the password of the user.
     *
     * @param a_password The password of the user.
     */
    virtual void setPassword(
        std::string const a_password
    ) = 0;

    /**
     * @brief Gets the value of the parameter.
     *
     * @param a_param_name The name of the parameter.
     *
     * @return The value of the parameter.
     *
     * @throw std::out_of_range If no such parameter is present.
     */
    virtual std::string getParam(
        std::string const a_param_name
    ) const = 0;

    /**
     * @brief Sets the parameter.
     *
     * @param a_param_name  The name of the parameter.
     * @param a_param_value The value of the parameter.
     */
    virtual void setParam(
        std::string const a_param_name,
        std::string const a_param_value
    ) = 0;

    /**
     * @brief Gets the exit code of the command.
     *
     * @return The exit code of the command, 0 if not set.
     */
    virtual unsigned short int getCode() const = 0;

    /**
     * @brief Sets the exit code of the command.
     *
     * @param a_code The exit code of the command.
     */
    virtual void setCode(
        unsigned short int const a_code
    ) = 0;

    /**
     * @brief Gets the status message of the command.
     *
     * @return The status message of the command, an empty string if not found.
     */
    virtual std::string getMessage() const = 0;

    /**
     * @brief Sets the status message of the command.
     *
     * @param a_message The status message of the command.
     */
    virtual void setMessage(
        std::string const a_message
    ) = 0;

    /**
     * @brief Gets the objects.
     *
     * @return The objects.
     */
    virtual Objects const & getObjects() const = 0;

    /**
     * @brief Adds an object.
     *
     * @param a_object The object.
     */
    virtual void addObject(
        Object const & a_object
    ) = 0;
};

} // namespace TUSLanguage

#endif // TUSLANGUAGE_ICOMMAND_HPP
