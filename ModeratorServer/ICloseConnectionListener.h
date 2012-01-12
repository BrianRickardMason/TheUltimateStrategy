
#ifndef _ICLOSECONNECTIONLISTENER_H_
#define _ICLOSECONNECTIONLISTENER_H_

class IBotConnection;

class ICloseConnectionListener {
public:
    virtual void handleClosed(const IBotConnection* aConnection)=0;
    
    virtual ~ICloseConnectionListener(){}
protected:
    ICloseConnectionListener(){}
};

#endif
