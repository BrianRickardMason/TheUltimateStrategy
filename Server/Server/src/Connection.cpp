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

#include <Game/GameServer/Common/IExecutor.hpp>
#include <Language/Interface/Command.hpp>
#include <Protocol/Xml/Cpp/LanguageToProtocolTranslator.hpp>
#include <Protocol/Xml/Cpp/PayloadToProtocolTranslator.hpp>
#include <Protocol/Xml/Cpp/ProtocolToLanguageTranslator.hpp>
#include <Server/Server/include/CommandDispatcher.hpp>
#include <Server/Server/include/Connection.hpp>

namespace Server
{

Connection::Connection(
    Poco::Net::StreamSocket const & aSocket,
    IContextShrPtr                  aContext
)
    : TCPServerConnection(aSocket),
      mSocketStream(socket()),
      mContext(aContext)
{
}

// TODO: shutdownReceive(), shutdownSend(), shutdown().
// TODO: Remove the hardcoded xml protocol!
void Connection::run()
{
    size_t const BUFFER_SIZE = 2048U;

    // Read the data from the socket.
    int length;
    mSocketStream >> length;

    char buffer[2048];
    mSocketStream.get(&buffer[0], length + 1);

    // Translate the data to the payload.
    std::string content(buffer);
    Protocol::Payload payloadRequest(length, content);

    // Translate the payload to the protocol.
    Protocol::PayloadToProtocolTranslator payloadToProtocolTranslator;
    Protocol::Message::Handle messageRequest = payloadToProtocolTranslator.translate(payloadRequest);

    // Translate the protocol to the language.
    Protocol::ProtocolToLanguageTranslator protocolToLanguageTranslator;
    Language::Command::Handle commandRequest = protocolToLanguageTranslator.translate(messageRequest);

    // Dispatch the command.
    CommandDispatcher commandDispatcher;
    Game::IExecutorShrPtr executor = commandDispatcher.dispatch(commandRequest, mContext);

    // Execute the command.
    Language::Command::Handle commandReply = executor->execute(commandRequest);

    // Translate the language to the protocol.
    Protocol::LanguageToProtocolTranslator languageToProtocolTranslator;
    Protocol::Message::Handle messageReply = languageToProtocolTranslator.translate(commandReply);

    // Translate the protocol to the payload.
    Protocol::Payload payloadReply(messageReply);

    // Write the data to the socket.
    mSocketStream.clear();
    mSocketStream << payloadReply.getLength();
    mSocketStream << payloadReply.getContent();
    mSocketStream.flush();
}

} // namespace Server
