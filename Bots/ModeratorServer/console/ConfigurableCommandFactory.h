
#ifndef _CONFIGURABLECOMMANDFACTORY_H_
#define _CONFIGURABLECOMMANDFACTORY_H_

#include "include/IConfigurableCommandFactory.h"

class ConfigurableCommandFactory: public IConfigurableCommandFactory {
public:
    ICommand::SingleHandle createCommand(const std::string& aName, const ICommand::Params& aParams);

    virtual std::list<std::string> availableCommands() const;
    virtual std::string describe(std::string aName)const;

    virtual bool knows(const std::string& aCmdName) const;
    
    virtual void addCreator(const std::string& aCmdName, ICommandCreator::SingleHandle aCreator);
    virtual ICommandCreator::SingleHandle removeCreator(const std::string& aCmdName);
        
    virtual ~ConfigurableCommandFactory();
    ConfigurableCommandFactory(){}
protected:
    typedef std::map<std::string, ICommandCreator*> CreatorsMap;
    
    CreatorsMap mCreators;
};

ConfigurableCommandFactory::~ConfigurableCommandFactory() {
    for (CreatorsMap::iterator it = mCreators.begin(); mCreators.end() != it; ++it) {
        delete it->second;
    }
}

ICommand::SingleHandle ConfigurableCommandFactory::createCommand(const std::string& aName, const ICommand::Params& aParams){
    return mCreators.at(aName)->create(aParams);
}

std::list<std::string> ConfigurableCommandFactory::availableCommands() const{
    std::list<std::string> ret;
    
    for ( CreatorsMap::const_iterator it = mCreators.begin(); mCreators.end() != it; ++it) {
        ret.push_back(it->first);
    }
    
    return ret;
}

std::string ConfigurableCommandFactory::describe(std::string aName)const{
    return mCreators.at(aName)->getDescription();
}

void ConfigurableCommandFactory::addCreator(const std::string& aCmdName, ICommandCreator::SingleHandle aCreator){
    ICommandCreator *p( aCreator.release() );
    
    delete mCreators[aCmdName];
    mCreators[aCmdName] = p;
}

ICommandCreator::SingleHandle ConfigurableCommandFactory::removeCreator(const std::string& aCmdName){
    ICommandCreator::SingleHandle h(mCreators.at(aCmdName));
    
    mCreators.erase(aCmdName);
    
    return h;
}

bool ConfigurableCommandFactory::knows(const std::string& aCmdName) const {
    CreatorsMap::const_iterator it = mCreators.find(aCmdName);
    return it != mCreators.end();
}

#endif
