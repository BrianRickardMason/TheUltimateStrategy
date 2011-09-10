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

#ifndef NETWORK_XMLRPCCOMMON_REQUEST_REQUEST_HPP
#define NETWORK_XMLRPCCOMMON_REQUEST_REQUEST_HPP

#include "../Common/Message.hpp"

#include "InvalidRequest.hpp"

namespace Network
{
namespace XmlRPCCommon
{
namespace Request
{

/**
 * @brief The identifiers of the requests.
 */
unsigned short int const REQUEST_ID_ECHO                               =  1;
unsigned short int const REQUEST_ID_ERROR                              =  2;

unsigned short int const REQUEST_ID_CREATE_LAND                        =  3;
unsigned short int const REQUEST_ID_DELETE_LAND                        =  4;
unsigned short int const REQUEST_ID_GET_LAND_BY_ID_LAND                =  5;
unsigned short int const REQUEST_ID_GET_LAND_BY_NAME                   =  6;
unsigned short int const REQUEST_ID_GET_LANDS_BY_ID_WORLD              =  7;

unsigned short int const REQUEST_ID_CREATE_SETTLEMENT                  =  8;
unsigned short int const REQUEST_ID_DELETE_SETTLEMENT                  =  9;
unsigned short int const REQUEST_ID_GET_SETTLEMENT_BY_ID_LAND_AND_NAME =  0;
unsigned short int const REQUEST_ID_GET_SETTLEMENT_BY_ID_SETTLEMENT    = 11;
unsigned short int const REQUEST_ID_GET_SETTLEMENTS_BY_ID_LAND         = 12;

unsigned short int const REQUEST_ID_BUILD_BUILDING                     = 13;
unsigned short int const REQUEST_ID_DESTROY_BUILDING                   = 14;
unsigned short int const REQUEST_ID_GET_BUILDING                       = 15;
unsigned short int const REQUEST_ID_GET_BUILDINGS                      = 16;

unsigned short int const REQUEST_ID_DISMISS_HUMAN                      = 17;
unsigned short int const REQUEST_ID_ENGAGE_HUMAN                       = 18;
unsigned short int const REQUEST_ID_GET_HUMAN                          = 19;
unsigned short int const REQUEST_ID_GET_HUMANS                         = 20;

unsigned short int const REQUEST_ID_GET_RESOURCE                       = 21;
unsigned short int const REQUEST_ID_GET_RESOURCES                      = 22;

unsigned short int const REQUEST_ID_CREATE_USER                        = 23;

unsigned short int const REQUEST_ID_CREATE_WORLD                       = 24;

unsigned short int const REQUEST_ID_TURN                               = 25;

unsigned short int const REQUEST_ID_CREATE_EPOCH                       = 26;
unsigned short int const REQUEST_ID_DELETE_EPOCH                       = 27;
unsigned short int const REQUEST_ID_ACTIVATE_EPOCH                     = 28;
unsigned short int const REQUEST_ID_DEACTIVATE_EPOCH                   = 29;
unsigned short int const REQUEST_ID_FINISH_EPOCH                       = 30;
unsigned short int const REQUEST_ID_TICK_EPOCH                         = 31;
unsigned short int const REQUEST_ID_GET_EPOCH                          = 32;

unsigned short int const REQUEST_ID_TRANSPORT_HUMAN                    = 33;
unsigned short int const REQUEST_ID_TRANSPORT_RESOURCE                 = 34;

/**
 * @brief A request class.
 */
class Request
    : public Common::Message
{
public:
    /**
     * @brief Constructs the request.
     */
    Request();

    /**
     * @brief Constructs the request.
     *
     * @param a_content A content of the request.
     */
    explicit Request(
        std::string const & a_content
    );

    /**
     * @brief Constructs the request.
     *
     * @param a_message_wrapper A message wrapper.
     */
    explicit Request(
        Network::XmlRPCCommon::Common::MessageWrapperShrPtr a_message_wrapper
    );

    /**
     * @brief Gets the identifier of the request.
     *
     * @return The identifier of the request.
     *
     * @throws InvalidRequestShrPtr When any of the following:
     *           - the "request" tag does not exist,
     *           - the "request" tag does not have the "id" attribute,
     *           - the "id" attribute is not an integer,
     *           - the value of the "id" attribute is negative
     *         is true.
     */
    unsigned short int const getIdRequest() const;

    /**
     * @brief Gets the value of the identifier of the user.
     *
     * @return The value of the identifier of the user.
     *
     * @throws InvalidRequestShrPtr When the value of the identifier of the user cannot be determined.
     */
    unsigned int getIDUserValue() const;

    /**
     * @brief Gets the value of the password of the user.
     *
     * @return The value of the password of the user.
     *
     * @throws InvalidRequestShrPtr When the value of the password of the user cannot be determined.
     */
    std::string getPasswordValue() const;

    /**
     * @brief Gets the value of the unsigned integer parameter by name.
     *
     * @param a_name The name of the parameter.
     *
     * @return The value of the unsigned integer parameter.
     *
     * @throws InvalidRequestShrPtr When any of the following:
     *           - the parameter does not exist,
     *           - the parameter is not declared as an unsigned integer,
     *           - the parameter does not have a value,
     *           - the parameter is declared as an unsigned integer and its value's type is not an unsigned integer,
     *           - the value is negative
     *         is true.
     */
    unsigned int const getParameterValueUnsignedInteger(
        std::string const & a_name
    ) const;

    /**
     * @brief Gets the value of the string parameter by name.
     *
     * @param a_name The name of the parameter.
     *
     * @return The value of the string parameter.
     *
     * @throws InvalidRequestShrPtr When any of the following:
     *           - the parameter does not exist,
     *           - the parameter is not declared as an string,
     *           - the parameter does not have a value
     *         is true.
     */
    std::string const getParameterValueString(
        std::string const & a_name
    ) const;

private:
    /**
     * @brief Verifies if parameter of given name exists.
     *
     * @param a_name The name of the parameter.
     *
     * @return A node representing the parameter.
     *
     * @throws InvalidRequestShrPtr If the parameter does not exist.
     */
    Xml::IXmlNodeShrPtr verifyIfParameterExists(
        std::string const & a_name
    ) const;

    /**
     * @brief Verifies if parameter has a "value" attribute.
     *
     * @param a_parameter A node representing the parameter.
     *
     * @return The "value" attribute.
     *
     * @throws InvalidRequestShrPtr If the parameter does not have the "value" attribute.
     */
    Xml::IXmlAttributeShrPtr verifyIfParameterHasAValueAtribute(
        Xml::IXmlNodeShrPtr a_parameter
    ) const;

    /**
     * @brief Sets the xml document basing on string.
     *
     * @param a_string A string representation of the xml document.
     */
    void setXmlDocument(
        std::string const & a_string
    );
};

/**
 * @brief A shared pointer of request.
 */
typedef boost::shared_ptr<Request> RequestShrPtr;

} // namespace Request
} // namespace XmlRPCCommon
} // namespace Network

#endif // NETWORK_XMLRPCCOMMON_REQUEST_REQUEST_HPP
