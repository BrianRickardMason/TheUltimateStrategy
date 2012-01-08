
#ifndef _ICONSOLE_H_
#define _ICONSOLE_H_

#include <string>

#include <ICommandFactory.h>

class IConsole {
public:
    virtual ~IConsole(){}
    
    virtual void setCommandFactory(ICommandFactory::Handle aFactory) = 0;
    
    virtual void run() = 0;
    
    virtual void stop() = 0;
    
    virtual void interpretLine() = 0;
    
    virtual void echo(const std::string& aString) = 0;
};

#endif
