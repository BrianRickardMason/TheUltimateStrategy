
#ifndef _BOTCONNECTIONMANAGER_H_
#define _BOTCONNECTIONMANAGER_H_

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>

#include <list>

#include "BotConnection.h"
#include "ICloseConnectionListener.h"
#include "IModeratorContext.h"

class IBotConnectionCreationListener;

/**
 * Creates new connection, configures them, manages and reports to moderator.
 */
class BotConnectionManager: public Poco::Net::TCPServerConnectionFactory, public ICloseConnectionListener {
public:
    BotConnectionManager(IModeratorContext::Handle aContext);
    
    virtual Poco::Net::TCPServerConnection* createConnection ( const Poco::Net::StreamSocket& socket );

    virtual void handleClosed(const IBotConnection* aConnection);
private:
    IModeratorContext::Handle mContext;
    
    std::list<IBotConnectionCreationListener*> mListeners;
    std::list<const IBotConnection*> mBotConnections;
};

class IBotConnectionCreationListener{
public:
    virtual void handleConnectionCreated(BotConnection::Ptr aConnection) = 0;
};

#endif
