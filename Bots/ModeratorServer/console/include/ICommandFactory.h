
#ifndef _ICOMMANDFACTORY_H_
#define _ICOMMANDFACTORY_H_

#include <Poco/SharedPtr.h>

#include <list>

class ICommandFactory {
public:
    typedef Poco::SharedPtr <ICommandFactory> Handle;

    virtual ICommand::SingleHandle createCommand(const std::string& aName, const ICommand::Params& aParams) = 0;

    virtual std::list<std::string> availableCommands() const = 0;
    virtual std::string describe(std::string aName)const = 0;
    
    virtual bool knows(const std::string& aCmdName) const = 0;
    
    virtual ~ICommandFactory(){}
protected:
    ICommandFactory(){}
};


#endif
