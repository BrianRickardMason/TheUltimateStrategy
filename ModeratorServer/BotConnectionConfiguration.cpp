
#include "BotConnectionConfiguration.h"

std::string BotConnectionConfiguration::getServerAddress() const{
    return mServerAddress;
}

unsigned int BotConnectionConfiguration::getServerPort() const{
    return mServerPort;
}

void BotConnectionConfiguration::setServerAddress(const std::string& aAddress) {
    mServerAddress = aAddress;
}

void BotConnectionConfiguration::setServerPort(unsigned int aPort) {
    mServerPort = aPort;
}

