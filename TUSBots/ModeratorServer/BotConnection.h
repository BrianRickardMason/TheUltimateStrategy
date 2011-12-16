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


#ifndef BOTCONNECTION_H
#define BOTCONNECTION_H

#include "IBotConnection.h"

#include <memory>
#include <list>

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/SharedPtr.h>
#include "IModeratorContext.h"

class IMessageBuffer;

class BotConnection : public Poco::Net::TCPServerConnection, public IBotConnection {
public:
    BotConnection(const Poco::Net::StreamSocket& socket, IModeratorContext::Handle aContext);
    virtual ~BotConnection();
    
    virtual void run();
    
    virtual void addCloseConnectionListener(ICloseConnectionListener* aListener);
    virtual void removeCloseConnectionListener(ICloseConnectionListener* aListener);
    
    /**
     * Send a message to the connected bot
     * 
     * Allows next tick message broadcast
     */
    virtual void send();
private:
    IModeratorContext::Handle mContext;
    
    Poco::Net::SocketStream mSocketStream;
    std::auto_ptr<IMessageBuffer> mMessageBuffer;
    
    std::list<ICloseConnectionListener*> mCloseListeners;
    
    void forwardMessageToServer();
};

#endif // BOTCONNECTION_H
