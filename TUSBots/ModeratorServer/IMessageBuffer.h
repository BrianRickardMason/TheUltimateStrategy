
#ifndef _IMESSAGEBUFFER_H_
#define _IMESSAGEBUFFER_H_

#include <vector>

class IMessageBuffer {
public:
    typedef std::vector<char> TPayload;
    
    virtual ~IMessageBuffer(){}
    
    virtual void feed(const TPayload&)=0;
    
    virtual bool hasMessage()=0;
    
    virtual TPayload extractMessage()=0;
protected:
    IMessageBuffer(){}
};

#endif
