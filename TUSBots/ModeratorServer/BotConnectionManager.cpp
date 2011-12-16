
#include "BotConnectionManager.h"

#include "BotConnection.h"

BotConnectionManager::BotConnectionManager(IModeratorContext::Handle aContext)
    :   mContext(aContext){
}


Poco::Net::TCPServerConnection* BotConnectionManager::createConnection(const Poco::Net::StreamSocket& socket) {
    BotConnection* ret = new BotConnection(socket, mContext);
    
    ret->addCloseConnectionListener(this);
    
    mBotConnections.push_back( ret );
    
    return ret;
}

void BotConnectionManager::handleClosed(const IBotConnection* aConnection) {
    mBotConnections.remove(aConnection);
}

