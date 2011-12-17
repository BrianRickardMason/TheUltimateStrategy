
#include "ModeratorContextBuilder.h"
#include "BotConnectionConfiguration.h"
#include "ModeratorServerConfiguration.h"
#include "Credentials.h"

IModeratorContext::Handle ModeratorContextBuilder::extract() {
    return IModeratorContext::Handle( mContext.release() );
}

void ModeratorContextBuilder::fillDefault() {
    mContext->mBotConnectionConf.reset(new BotConnectionConfiguration());
    mContext->mServerConf.reset( new ModeratorServerConfiguration());
    
    mContext->mBotConnectionConf->setServerAddress("127.0.0.1");
    mContext->mBotConnectionConf->setServerPort(2222);
    
    mContext->mServerConf->setAddress("127.0.0.1");
    mContext->mServerConf->setPort(3333);
    
    mContext->mModeratorCredentials.reset( new Credentials("modbot", "modbotpass"));
}

void ModeratorContextBuilder::make() {
    mContext.reset( new ModeratorContext);
}

