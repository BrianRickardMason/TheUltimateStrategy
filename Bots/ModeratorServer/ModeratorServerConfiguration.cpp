
#include "ModeratorServerConfiguration.h"

std::string ModeratorServerConfiguration::getAddress() const {
    return mAddress;
}

unsigned int ModeratorServerConfiguration::getPort() const {
    return mPort;
}

void ModeratorServerConfiguration::setAddress(const std::string& aAddress) {
    mAddress = aAddress;
}

void ModeratorServerConfiguration::setPort(unsigned int aPort){
    mPort = aPort;
}

