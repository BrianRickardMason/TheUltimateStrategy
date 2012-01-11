
#ifndef _IMODERATORCONTEXT_H_
#define _IMODERATORCONTEXT_H_

#include <Poco/SharedPtr.h>

class IBotConnectionConfiguration;
class IModeratorServerConfiguration;
class Credentials;
class ConsoleFacade;

#include "GeneralConfig.h"

class IModeratorContext {
public:
    typedef Poco::SharedPtr<IModeratorContext> Handle;
    
    virtual const IBotConnectionConfiguration& getBotConnectionConf()const = 0;
    virtual const IModeratorServerConfiguration& getModeratorServerConf()const = 0;
    
    virtual const Credentials& getModeratorCredentials()const = 0;
    
    virtual const GeneralConfig& getGeneralConfig()const=0;
    
    virtual ConsoleFacade& getConsoleFacade() = 0;
    
    virtual ~IModeratorContext(){}
protected:
    IModeratorContext(){};
};

#endif
