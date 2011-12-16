
#ifndef _TUSMESSAGEBUFFER_H_
#define _TUSMESSAGEBUFFER_H_

#include "IMessageBuffer.h"

#include <string>
#include <sstream>

class TusMessageBuffer: public IMessageBuffer {
public:
    TusMessageBuffer(std::string aMessageTagName);
    
    virtual void feed(const TPayload& aBytes);
    
    virtual bool hasMessage();
    
    virtual TPayload extractMessage();
private:
    const std::string START;
    const std::string END;
        
    std::stringstream mBuf;
    
    bool mValidMessage;
    unsigned mMessageStart;
    unsigned mMessageLength;
    
    bool lookForMessage();
};

#endif
