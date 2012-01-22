
#ifndef _MODERATORINTERFACE_H_
#define _MODERATORINTERFACE_H_

#include "IModeratorInterface.h"

#include <memory>

#include <Language/Interface/UserRequestBuilder.hpp>
#include <Protocol/Xml/Cpp/LanguageToProtocolTranslator.hpp>
#include <Protocol/Xml/Cpp/ProtocolToLanguageTranslator.hpp>

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
    void sendCommand(
        TUSLanguage::ICommand::Handle& in,
        TUSLanguage::ICommand::Handle& out
    );
    int  executeCommand( TUSLanguage::ICommand::Handle in);

    Credentials::Handle mCredentials;
    std::string mCurrentWorld;
    
    IModeratorContext::Handle mContext;
    IBotManager::Handle mBotManager;
    
    TusCommandBuilder mCmdBuilder;
    
    TUSLanguage::UserRequestBuilder::Handle mReqBuilder;
    Protocol::LanguageToProtocolTranslator::Handle mToProtocol;
    Protocol::ProtocolToLanguageTranslator::Handle mToLanguage;
};

#endif
