
#include "ModeratorContext.h"

#include "BotConnectionConfiguration.h"
#include "ModeratorServerConfiguration.h"

ModeratorContext::ModeratorContext()
:
    mGeneralConfig()
{

}


const IBotConnectionConfiguration& ModeratorContext::getBotConnectionConf() const {
    return *mBotConnectionConf;
}

const IModeratorServerConfiguration& ModeratorContext::getModeratorServerConf() const {
    return *mServerConf;
}

const Credentials& ModeratorContext::getModeratorCredentials() const{
    return *mModeratorCredentials;
}

const GeneralConfig& ModeratorContext::getGeneralConfig() const{
    return mGeneralConfig;
}


void ModeratorContext::setBotConnectionConf(std::auto_ptr< BotConnectionConfiguration > aConf) {
    mBotConnectionConf = aConf;
}

void ModeratorContext::setModeratorServerConf(std::auto_ptr< ModeratorServerConfiguration > aConf) {
    mServerConf = aConf;
}

void ModeratorContext::setModeratorCredentials(std::auto_ptr< Credentials > aCredentials){
    mModeratorCredentials = aCredentials;
}

GeneralConfig& ModeratorContext::Config() {
    return mGeneralConfig;
}
