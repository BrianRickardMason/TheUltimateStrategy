
#include "ModeratorContext.h"

#include "BotConnectionConfiguration.h"
#include "ModeratorServerConfiguration.h"

const IBotConnectionConfiguration& ModeratorContext::getBotConnectionConf() const {
    return *mBotConnectionConf;
}

const IModeratorServerConfiguration& ModeratorContext::getModeratorServerConf() const {
    return *mServerConf;
}

void ModeratorContext::setBotConnectionConf(std::auto_ptr< BotConnectionConfiguration > aConf) {
    mBotConnectionConf = aConf;
}

void ModeratorContext::setModeratorServerConf(std::auto_ptr< ModeratorServerConfiguration > aConf) {
    mServerConf = aConf;
}

