/*
    Copyright (c) 2011, <copyright holder> <email>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "BotConnection.h"
#include "TusMessageBuffer.h"

#include "ICloseConnectionListener.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include "IBotConnectionConfiguration.h"

BotConnection::BotConnection(const Poco::Net::StreamSocket& aSocket, IModeratorContext::Handle aContext): 
    TCPServerConnection(aSocket),
    mContext(aContext),
    mSocketStream(socket()),
    mMessageBuffer( new TusMessageBuffer("request") ) {

}

BotConnection::~BotConnection(){
    for(std::list<ICloseConnectionListener*>::iterator it = mCloseListeners.begin(); it != mCloseListeners.end(); ++it){
        (*it)->handleClosed(this);
    }
}

void BotConnection::addCloseConnectionListener(ICloseConnectionListener* aListener) {
    if(aListener){
        mCloseListeners.push_back(aListener);
    }
}

void BotConnection::removeCloseConnectionListener(ICloseConnectionListener* aListener) {
    mCloseListeners.remove(aListener);
}

void BotConnection::run() {
    const size_t BUFFER_SIZE = 2048U;
    
    mSocketStream << std::noskipws;
    
    IMessageBuffer::TPayload buf(BUFFER_SIZE);
    
    try{
        while(mSocketStream.good()) {
            // only getline is nicely blocking here?
            mSocketStream.getline(&buf[0], buf.size(), '\n');
            unsigned read = mSocketStream.gcount();
            
            if(read > 0){
                buf[read-1] = '\n'; // change the '\0' to '\n'
                buf.resize(read);
                mMessageBuffer->feed( buf );
                buf.resize(BUFFER_SIZE);
            }
            
            while(mMessageBuffer->hasMessage()){
                forwardMessageToServer();
            }
        }
    }
    catch(std::exception& ex){   
        std::cerr << ex.what() << std::endl;
    }
    catch(...){
        std::cerr << "fubar" <<std::endl;
    }
}

void BotConnection::forwardMessageToServer() {
    Poco::ScopedLock<Poco::Mutex> sendMutex(mSendMutex);
    
    // TODO : move it somewhere else
    Poco::Net::SocketAddress serverAddress(
        mContext->getBotConnectionConf().getServerAddress(),
        mContext->getBotConnectionConf().getServerPort()
    );
    
    // read from socket and forward data to server agent
    IMessageBuffer::TPayload msg = mMessageBuffer->extractMessage();
    
    // receive from server agent and write it to socket
    
    Poco::Net::StreamSocket serverSocket(serverAddress);
    Poco::Net::SocketStream serverStream(serverSocket);
    serverStream << std::noskipws;
    
    typedef std::ostream_iterator<IMessageBuffer::TPayload::value_type> ostr_it;
    typedef std::istream_iterator<IMessageBuffer::TPayload::value_type> istr_it;
   
    std::stringstream tmp;
    tmp << std::noskipws;
// std::cout << "sending: " << std::string(msg.begin(), msg.end()) <<std::endl;

    std::copy(msg.begin(), msg.end(), ostr_it(serverStream));
    serverStream.flush();
    
    mSocketStream << std::nounitbuf;
    std::copy(istr_it(serverStream), istr_it(), ostr_it(tmp));
    std::copy(istr_it(tmp), istr_it(), ostr_it(mSocketStream));
    mSocketStream.flush();
// std::cout << "reply sent: " << tmp.str() << std::endl;
}

void BotConnection::send(const TusIndication& aIndication) {
    typedef std::ostream_iterator<IMessageBuffer::TPayload::value_type> ostr_it;
    
    Poco::ScopedLock<Poco::Mutex> sendMutex(mSendMutex);
    
// std::clog << "bc: " << aIndication << std::endl;
    
    mSocketStream << std::nounitbuf << std::noskipws;
    std::copy(aIndication.begin(), aIndication.end(), ostr_it(mSocketStream));
    mSocketStream.flush();
}

