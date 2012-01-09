
#ifndef _ACOMMAND_H_
#define _ACOMMAND_H_

#include "ICommand.h"

class ACommand: public ICommand {
public:
    virtual const std::string& getName()const{
        return mParameters[0];
    }
    virtual const Params& getParams()const{
        return mParameters;
    };
protected:
    ACommand(const Params& aParams)
    : mParameters(aParams){}
    
    const Params mParameters;
};

#endif
