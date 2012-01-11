
#ifndef BOTCONNECTIONFACTORY_H
#define BOTCONNECTIONFACTORY_H

#include <Poco/Net/TCPServerConnectionFactory.h>
#include "BotConnection.h"

typedef Poco::Net::TCPServerConnectionFactoryImpl<BotConnection>  BotConnectionFactory;

#endif
