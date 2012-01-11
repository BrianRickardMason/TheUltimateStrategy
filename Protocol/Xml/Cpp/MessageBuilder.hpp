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

#ifndef TUSPROTOCOL_MESSAGEBUILDER_HPP
#define TUSPROTOCOL_MESSAGEBUILDER_HPP

#include <Protocol/Xml/Cpp/Message.hpp>
#include <boost/noncopyable.hpp>

#include <Poco/AutoPtr.h>
#include <Poco/DOM/DocumentType.h>

namespace TUSProtocol
{

class MessageBuilder
    : boost::noncopyable
{
public:
    /**
     * @brief Ctor.
     */
    MessageBuilder();
    
    /**
     * @brief Initializes the building of a message.
     */
    void makeMessage();

    /**
     * @brief Adds the header.
     *
     * @param a_id The identifier of the message.
     */
    void addHeader(
        unsigned short int const a_id
    );

    /**
     * @brief Adds the header.
     *
     * @param a_id       The identifier of the message.
     * @param a_login    The login of the user, null if user is not set.
     * @param a_password The password of the user, null if user is not set.
     */
    void addHeader(
        unsigned short int const a_id,
        std::string        const a_login,
        std::string        const a_password
    );

    /**
     * @brief Adds the request.
     *
     * @param a_request The name of the request.
     */
    void addRequest(
        std::string const a_request
    );

    /**
     * @brief Adds a parameter.
     *
     * @param a_param_name  The name of the parameter.
     * @param a_param_value The value of the parameter.
     */
    void addParam(
        std::string const a_param_name,
        std::string const a_param_value
    );

    /**
     * @brief Adds the reply.
     */
    void addReply();

    /**
     * @brief Adds the exit code.
     *
     * @param a_code The exit code.
     */
    void addCode(
        std::string const a_code
    );

    /**
     * @brief Adds the message.
     *
     * @param a_message The message.
     */
    void addMessage(
        std::string const a_message
    );

    /**
     * @brief Adds the specific reply.
     *
     * @param a_reply The name of the reply.
     */
    void addSpecificReply(
        std::string const a_reply
    );

    /**
     * @brief Adds an object.
     *
     * @param a_object_name The name of the object.
     * @param a_object      The object.
     */
    void addObject(
        std::string     const   a_object_name,
        Message::Object const & a_object
    );

    /**
     * @brief Adds objects.
     *
     * @param a_objects_name The name of the objects.
     * @param a_object_name  The name of the object.
     * @param a_objects      The objects.
     */
    void addObjects(
        std::string      const   a_objects_name,
        std::string      const   a_object_name,
        Message::Objects const & a_objects
    );

    /**
     * @brief Extracts the message.
     *
     * @return The built message.
     */
    Message::SingleHandle extract();

private:
    /**
     * @brief The document type definition of created messages.
     */
    Poco::AutoPtr<Poco::XML::DocumentType> m_document_type;
    
    /**
    * @brief The document representing the message.
    */
    Message::SingleHandle m_document;

    /**
     * @brief The current node of the document.
     */
    Poco::XML::Node * m_current_node;
public:
    // TODO : refactor this out of here?
    const std::string ROOT_ELEMENT_NAME;
    const std::string DTD_FORMAL_PUBLIC_IDENTIFIER;
    const std::string DTD_FILE_PATH;
};

} // namespace TUSProtocol

#endif // TUSPROTOCOL_MESSAGEBUILDER_HPP
