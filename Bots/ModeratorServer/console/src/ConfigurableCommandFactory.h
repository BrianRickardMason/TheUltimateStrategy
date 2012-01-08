
#ifndef _CONFIGURABLECOMMANDFACTORY_H_
#define _CONFIGURABLECOMMANDFACTORY_H_

#include <IConfigurableCommandFactory.h>

class ConfigurableCommandFactory: public IConfigurableCommandFactory {
public:
    ICommand::SingleHandle createCommand(const std::string& aName, const ICommand::Params& aParams);

    virtual std::list<std::string> availableCommands() const;
    virtual std::string describe(std::string aName)const;

    virtual bool knows(const std::string& aCmdName) const;
    
    virtual void addCreator(const std::string& aCmdName, ICommandCreator::SingleHandle aCreator);
    virtual ICommandCreator::SingleHandle removeCreator(const std::string& aCmdName);
        
    virtual ~ConfigurableCommandFactory();
    ConfigurableCommandFactory();
protected:
    typedef std::map<std::string, ICommandCreator*> CreatorsMap;
    
    CreatorsMap mCreators;
};

#endif
