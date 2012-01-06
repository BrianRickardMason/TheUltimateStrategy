
#ifndef _ICONSOLEINTERPRETER_H_
#define _ICONSOLEINTERPRETER_H_

#include <string>

#include "ICommand.h"

class IConsoleInterpreter {
public:
    virtual bool interpret(const std::string& aInput, std::string& outName, ICommand::Params& outParams) = 0;
    
    virtual ~IConsoleInterpreter(){}
protected:
    IConsoleInterpreter(){}
};

#endif
