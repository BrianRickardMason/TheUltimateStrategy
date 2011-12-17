
#ifndef _MODERATORCONTEXT_H_
#define _MODERATORCONTEXT_H_

#include <memory>

#include "IModeratorContext.h"

class BotConnectionConfiguration;
class ModeratorServerConfiguration;
class ModeratorContextBuilder;

class ModeratorContext: public IModeratorContext{
public:
    ModeratorContext();
    
    virtual const IBotConnectionConfiguration& getBotConnectionConf()const;
    virtual const IModeratorServerConfiguration& getModeratorServerConf()const;
    virtual const Credentials& getModeratorCredentials() const;
    virtual const GeneralConfig& getGeneralConfig() const;
    
    void setModeratorServerConf( std::auto_ptr<ModeratorServerConfiguration> aConf );
    void setBotConnectionConf( std::auto_ptr<BotConnectionConfiguration> aConf );
    void setModeratorCredentials( std::auto_ptr<Credentials> aCredentials );
    
    GeneralConfig& Config();
private:
    friend class ModeratorContextBuilder;
    
    GeneralConfig mGeneralConfig;
    
    std::auto_ptr<ModeratorServerConfiguration> mServerConf;
    std::auto_ptr<BotConnectionConfiguration> mBotConnectionConf;
    
    std::auto_ptr<Credentials> mModeratorCredentials;
};

#endif
