
#ifndef _IBOTCONNECTION_H_
#define _IBOTCONNECTION_H_

#include <Poco/SharedPtr.h>

class ICloseConnectionListener;

class IBotConnection{
public:
    typedef IBotConnection* Ptr;
    
    virtual void send()=0;
    
    virtual void addCloseConnectionListener(ICloseConnectionListener* aListener)=0;
    virtual void removeCloseConnectionListener(ICloseConnectionListener* aListener)=0;
    
    virtual ~IBotConnection(){}
protected:
    IBotConnection(){}
};

#endif
