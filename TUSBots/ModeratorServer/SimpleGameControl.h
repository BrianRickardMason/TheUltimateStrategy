
#ifndef _SIMPLEGAMECONTROL_H_
#define _SIMPLEGAMECONTROL_H_

#include "IModeratorContext.h"
#include "IModeratorInterface.h"
#include "ModeratorInterface.h"
#include <Poco/Thread.h>

class SimpleGameControl{
public:
    SimpleGameControl(IModeratorContext::Handle aContext, IBotManager::Handle aBotManager)
    :   mContext(aContext), mInterface( new ModeratorInterface(mContext, aBotManager) ) {
        mInterface->setModeratorCredentials(mContext->getModeratorCredentials());
        mEpochCount = 1;
        mTickCount = 20;
    }
    
    void run(){
        //# TODO: Delete the world is needed to be bullet proof.
        mInterface->createWorld("World");
        mInterface->setCurrentWorld("World");
        
        //# Control the tournament of X epochs.
        for(unsigned i=0;i<mEpochCount; ++i){
             std::string epoch_name = "epoch";
             
             mInterface->createEpoch(epoch_name);
             mInterface->activateEpoch();
             
            //# Control the epoch of X ticks.
            for(unsigned j=0; j<mTickCount; ++j){
                Poco::Thread::current()->sleep(1250/*ms*/);
                mInterface->deactivateEpoch();
                mInterface->tickEpoch();
                mInterface->activateEpoch();
                
                mInterface->notifyTick();
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
};

#endif
