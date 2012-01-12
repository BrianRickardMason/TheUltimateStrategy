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

#ifndef TUSPROTOCOL_MESSAGE_HPP
#define TUSPROTOCOL_MESSAGE_HPP

#include <Poco/DOM/Document.h>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include <vector>

namespace TUSProtocol
{

class Message
    : public Poco::XML::Document
{
public:
    // TODO: Rename to Handle.
    typedef boost::shared_ptr<Message> SingleHandle;
    typedef std::map<std::string, std::string> Object;
    typedef std::vector<Object> Objects;

    /**
     * @brief Ctor.
     *
     * @param a_name_pool The name pool.
     */
    Message(
        Poco::XML::NamePool * a_name_pool = 0
    );

    /**
     * @brief Ctor specifying document type.
     *
     * @param a_document_type The document type definition.
     * @param a_name_poll The name pool
     */
    Message(
        Poco::XML::DocumentType* a_document_type,
        Poco::XML::NamePool* a_name_pool = 0
    );
};

} // namespace TUSProtocol

#endif // TUSPROTOCOL_MESSAGE_HPP
