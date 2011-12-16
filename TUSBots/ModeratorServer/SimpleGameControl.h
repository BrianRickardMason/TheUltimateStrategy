
#ifndef _SIMPLEGAMECONTROL_H_
#define _SIMPLEGAMECONTROL_H_

class SimpleGameControl{
public:
    void run(){
        //# TODO: Delete the world is needed to be bullet proof.
        //interface.createWorld(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

//         # Control the tournament of X epochs.
        for(unsigned i=0;i<mEpochCount; ++i){
//             epoch_name = EPOCH_NAME + repr(epoch)
//             interface.createEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME, epoch_name)
//             interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

//             # Control the epoch of X ticks.
            for(unsigned j=0; j<mTickCount; ++j){
//                 sleep(SLEEP_BETWEEN_TICKS)
//                 interface.deactivateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
//                 interface.tickEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
//                 interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
            }
//             interface.deactivateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
//             interface.finishEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
//             interface.deleteEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
        }   
    }
private:
    unsigned mEpochCount;
    unsigned mTickCount;
};

#endif
