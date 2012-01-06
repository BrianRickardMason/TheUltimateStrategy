
#ifndef _ICONFIGURABLECOMMANDFACTORY_H_
#define _ICONFIGURABLECOMMANDFACTORY_H_

#include "ICommandFactory.h"
#include "ICommandCreator.h"

class IConfigurableCommandFactory: public ICommandFactory {
public:
    virtual void addCreator(const std::string& aCmdName, ICommandCreator::SingleHandle aCreator) = 0;
    virtual ICommandCreator::SingleHandle removeCreator(const std::string& aCmdName) = 0;
    
    virtual ~IConfigurableCommandFactory(){}
protected:
    IConfigurableCommandFactory(){}
};

#endif
