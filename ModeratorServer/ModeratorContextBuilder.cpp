
#include <ConsoleFacade.h>

#include "ModeratorContextBuilder.h"
#include "BotConnectionConfiguration.h"
#include "ModeratorServerConfiguration.h"
#include "Credentials.h"

ModeratorContextBuilder::ModeratorContextBuilder()
:
    LOCALHOST("127.0.0.1"),
	DEFAULT_MODERATOR_LOGIN("modbot"),
	DEFAULT_MODERATOR_PASSWORD("modbotpass")
{}

ModeratorContextBuilder::~ModeratorContextBuilder(){}

IModeratorContext::Handle ModeratorContextBuilder::extract() {
    return IModeratorContext::Handle( mContext.release() );
}

ModeratorContext& ModeratorContextBuilder::peek() {
    if(! mContext.get()){
        make();
    }
    return *mContext;
}


void ModeratorContextBuilder::fillDefault() {
    mContext->mBotConnectionConf.reset(new BotConnectionConfiguration());
    mContext->mBotConnectionConf->setServerAddress(LOCALHOST);
    mContext->mBotConnectionConf->setServerPort(2222);
    
    mContext->mServerConf.reset( new ModeratorServerConfiguration());
    mContext->mServerConf->setAddress(LOCALHOST);
    mContext->mServerConf->setPort(3333);
    
    mContext->mConsoleFacade.reset( new ConsoleFacade());
    
    mContext->mModeratorCredentials.reset( 
        new Credentials(DEFAULT_MODERATOR_LOGIN, DEFAULT_MODERATOR_PASSWORD)
    );
}

void ModeratorContextBuilder::make() {
    mContext.reset( new ModeratorContext());
}

