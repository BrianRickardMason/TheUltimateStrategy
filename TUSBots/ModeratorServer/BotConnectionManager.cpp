
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
    mBotConnections.remove(const_cast<IBotConnection*>(aConnection));
}

void BotConnectionManager::broadcast(const TusIndication& aIndication) {
    std::list <IBotConnection*> :: iterator it;
    for( it = mBotConnections.begin(); mBotConnections.end() != it; ++it) {
        (*it)->send(aIndication);
    }
}
