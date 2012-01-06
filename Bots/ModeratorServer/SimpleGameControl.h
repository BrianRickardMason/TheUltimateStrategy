
#ifndef _SIMPLEGAMECONTROL_H_
#define _SIMPLEGAMECONTROL_H_

#include "IModeratorContext.h"
#include "IModeratorInterface.h"
#include "ModeratorInterface.h"
#include "GeneralConfig.h"

#include <Poco/Thread.h>

#include <iostream>
#include <sstream>

class SimpleGameControl: public Poco::Runnable {
public:
    SimpleGameControl(IModeratorContext::Handle aContext, IBotManager::Handle aBotManager)
    :   
        mContext(aContext), 
        mInterface( new ModeratorInterface(mContext, aBotManager) ),
        mEpochCount(1),
        mTickCount(20),
        mSleepMs(3000),
        mNotify(false) 
    {
        mInterface->setModeratorCredentials(mContext->getModeratorCredentials());
        
        config(mContext->getGeneralConfig());
    }
    
    void config(const GeneralConfig& aConf){
        if(aConf.hasKey("sgc_ticks")){
            mTickCount = aConf.get<unsigned>("sgc_ticks");
        }
        
        if(aConf.hasKey("sgc_epochs")){
            mEpochCount = aConf.get<unsigned>("sgc_epochs");
        }

        if(aConf.hasKey("sgc_sleep")){
            mSleepMs = aConf.get<unsigned>("sgc_sleep");
        }
        
        if(aConf.hasKey("sgc_notify")){
            mNotify = aConf.get<bool>("sgc_notify");
        }
        
        if(aConf.hasKey("sgc_world")){
            mWorldName = aConf.get<std::string>("sgc_world");
        }
    }
    
    void logConf()const{
        std::clog 
            << mSleepMs << " / "
            << mEpochCount << " / "
            << mTickCount << " / "
            << mWorldName << " / "
            << mNotify 
        << std::endl;
    }
    
    virtual void run(){
        //# TODO: Delete the world is needed to be bullet proof.
        mInterface->createWorld(mWorldName);
        mInterface->setCurrentWorld(mWorldName);
        
        //# Control the tournament of X epochs.
        for(unsigned i=0;i<mEpochCount; ++i){
             std::string epoch_name = "epoch";
             
             mInterface->createEpoch(epoch_name);
             mInterface->activateEpoch();
             
            //# Control the epoch of X ticks.
            for(unsigned j=0; j<mTickCount; ++j){
                Poco::Thread::current()->sleep(mSleepMs);
                mInterface->deactivateEpoch();
                mInterface->tickEpoch();
                mInterface->activateEpoch();
                
                if(mNotify){
                    mInterface->notifyTick();
                }
            }
            mInterface->deactivateEpoch();
            mInterface->finishEpoch();
            mInterface->deleteEpoch();
        }   
    }
private:
    IModeratorContext::Handle mContext;
    IModeratorInterface::Handle mInterface;
    
    unsigned mEpochCount;
    unsigned mTickCount;
    unsigned mSleepMs;
    bool mNotify;
    
    std::string mWorldName;
};

#endif
