
#include "TusMessageBuffer.h"

#include <stack>
#include <stdexcept>
#include <iterator>

TusMessageBuffer::TusMessageBuffer(std::string aMessageTagName): 
    START("<"+aMessageTagName), END("</"+aMessageTagName+">"),
    mBuf(),
    mValidMessage(false), 
    mMessageStart(0), 
    mMessageLength(0) 
    {}

void TusMessageBuffer::feed(const TPayload& aBytes){
    std::copy(aBytes.begin(), aBytes.end(), std::ostream_iterator<TPayload::value_type>(mBuf));
};

bool TusMessageBuffer::hasMessage(){
    return (mValidMessage = lookForMessage());
}

IMessageBuffer::TPayload TusMessageBuffer::extractMessage(){
    if(hasMessage()){
        mValidMessage = false;
        
        TPayload ret(mMessageLength);
        
        mBuf.ignore(mMessageStart);
        mBuf.read(&ret[0], mMessageLength);
        mBuf.flush();
        // TODO keeping the buffer small, now all the string is in the buf
        
        return ret;
    }
    else {
        throw std::runtime_error("no valid message on stream");
    }
}

bool TusMessageBuffer::lookForMessage(){
    // maybe we have the message already found
    if(mValidMessage){
        return true;
    }
    
    using std::string;
    #define found(pos) (std::string::npos != pos)
    
    // current state of the ostream buffer
    string state = mBuf.str().substr(mBuf.tellg());
    
    int sPos = state.find(START);
    
    if(!found(sPos)){
        // there is no starting tag even... Exit, stage left!
        return false;
    }
    
    std::stack<int> bracketing;
    
    // push one tag to close, the value is starting point for further searches
    bracketing.push(sPos + START.size());
    
    int ePos = bracketing.top(); // looking for end tag position
    while(! bracketing.empty()){
        int pos = ePos;
        
            ePos = state.find(  END,pos);
        int iPos = state.find(START,pos);
        
        if(!found(ePos)){
            // no end tag in current state even... Exit, stage left!
            return false;
        }
        
        if(found(iPos) && iPos < ePos ){
            // found starting tag between current start and end
            bracketing.push(iPos + START.size()); // push another tag to close
            ePos = bracketing.top();
        }
        else {
            // one tag level is closed
            bracketing.pop();
            ePos += END.size(); // start looking after the closing tag
        }
    }
    
    mMessageStart = sPos;
    mMessageLength = ePos-sPos;
    
    //Exit, stage right!
    return true;
}
