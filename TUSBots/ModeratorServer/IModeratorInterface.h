
#ifndef _IMODERATORINTERFACE_H_
#define _IMODERATORINTERFACE_H_

#include <string>
#include <Poco/SharedPtr.h>

class Credentials;

class IModeratorInterface {
public:
    typedef Poco::SharedPtr<IModeratorInterface> Handle;
    
    virtual void setModeratorCredentials(const Credentials& aCredenetials)=0;
    
    virtual int createWorld(const std::string& aWorldName)=0;
    virtual void setCurrentWorld(const std::string& aWorldName)=0;
    
    virtual int createEpoch(const std::string& aEpochName)=0;
    virtual int activateEpoch()=0;
    virtual int deactivateEpoch()=0;
    virtual int tickEpoch()=0;
    virtual int finishEpoch()=0;
    virtual int deleteEpoch()=0;
    
    virtual void notifyTick()=0;
};

#endif
