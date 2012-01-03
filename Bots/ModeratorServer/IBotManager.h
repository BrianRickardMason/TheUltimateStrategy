
#ifndef _IBOTMANAGER_H_
#define _IBOTMANAGER_H_

#include <Poco/SharedPtr.h>

#include "TusCommandBuilder.h"

class IBotManager {
public:
    typedef Poco::SharedPtr<IBotManager> Handle;
    
    virtual void broadcast(const TusIndication&) = 0;
    
    virtual ~IBotManager(){};
protected:
    IBotManager(){}
};

#endif
