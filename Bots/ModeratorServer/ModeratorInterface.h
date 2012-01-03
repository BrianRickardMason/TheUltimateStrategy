
#ifndef _MODERATORINTERFACE_H_
#define _MODERATORINTERFACE_H_

#include "IModeratorInterface.h"

#include <memory>

#include "TusCommandBuilder.h"
#include "IModeratorContext.h"
#include "BotConnectionManager.h"
#include "IBotManager.h"

class ModeratorInterface: public IModeratorInterface {
public:
    ModeratorInterface(IModeratorContext::Handle aContext, IBotManager::Handle aManager);
    
    virtual int createWorld(const std::string& aWorldName);
    virtual void setCurrentWorld(const std::string& aWorldName);
    
    virtual int activateEpoch();
    virtual int createEpoch(const std::string& aEpochName);
    virtual int deactivateEpoch();
    virtual int deleteEpoch();
    virtual int finishEpoch();
    virtual void setModeratorCredentials(const Credentials& aCredenetials);
    virtual int tickEpoch();
    
    virtual void notifyTick();
private:
    void sendCommand(std::auto_ptr<TusCommand>& in, std::auto_ptr<TusReturnValue>& out );
    int  executeCommand(std::auto_ptr<TusCommand>& in);
    
    std::auto_ptr<TusCommand> prepareWorldCommand(const std::string& aCommandName);
    
    Credentials::Handle mCredentials;
    std::string mCurrentWorld;
    
    IModeratorContext::Handle mContext;
    IBotManager::Handle mBotManager;
    
    TusCommandBuilder mCmdBuilder;
    
};

#endif
