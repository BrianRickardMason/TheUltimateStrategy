
#ifndef _CONSOLEMOCKS_H_
#define _CONSOLEMOCKS_H_

#include <gmock/gmock.h>

#include <IConsole.h>

class MockConsole: public IConsole {
public:
    MockConsole();
    virtual ~MockConsole();
    
    MOCK_METHOD1( echo, void(const std::string& aString));
    MOCK_METHOD0( interpretLine, void ());
    MOCK_METHOD0( run, void ());
    MOCK_METHOD1( setCommandFactory, void (ICommandFactory::Handle aFactory));
    MOCK_METHOD0( stop, void ());
};

#include <ACommand.h>

class MockCommand: public ACommand { 
public:
    MockCommand(const Params& aParams);
    
    virtual ~MockCommand();
    
    MOCK_CONST_METHOD0( execute, int());
};

#include <ICommandCreator.h>

class MockCommandCreator: public ICommandCreator {
public:
    MockCommandCreator();
    virtual ~MockCommandCreator();
    
    /**
     * To be wrapped to get the proper API
     */
    MOCK_METHOD1( _create, ICommand* (const ICommand::Params& aParams));
    
    virtual ICommand::SingleHandle create(const ICommand::Params& aParams){
        return ICommand::SingleHandle( _create(aParams) );
    }
    
    MOCK_CONST_METHOD0( getDescription,  std::string () );
};

#include <IConsoleInterpreter.h>

class MockConsoleInterpreter: public IConsoleInterpreter {
public:
    MockConsoleInterpreter();
    virtual ~MockConsoleInterpreter();
    
    MOCK_METHOD3(interpret, bool(const std::string& aInput, std::string& outName, ICommand::Params& outParams));
};

#include <ICommandFactory.h>

class MockCommandFactory: public ICommandFactory {
public:
    MockCommandFactory();
    virtual ~MockCommandFactory();
    
    MOCK_CONST_METHOD0( availableCommands, std::list< std::string > () );
    /**
     * To be wrapped to get auto_ptr in return
     */
    MOCK_METHOD2( _createCommand, ICommand*(const std::string& aName, const ICommand::Params& aParams));
    virtual ICommand::SingleHandle createCommand(const std::string& aName, const ICommand::Params& aParams){
        return ICommand::SingleHandle( _createCommand(aName, aParams) );
    }
    
    MOCK_CONST_METHOD1( describe, std::string (std::string aName) );
    MOCK_CONST_METHOD1( knows, bool (const std::string& aCmdName) );
};

#include <IConfigurableCommandFactory.h>

class MockConfigurableCommandFactory: public IConfigurableCommandFactory {
public:
    MockConfigurableCommandFactory();
    virtual ~MockConfigurableCommandFactory();
    
    MOCK_CONST_METHOD0( availableCommands, std::list< std::string > () );
    /**
     * To be wrapped to get auto_ptr in return
     */
    MOCK_METHOD2( _createCommand, ICommand*(const std::string& aName, const ICommand::Params& aParams));
    virtual ICommand::SingleHandle createCommand(const std::string& aName, const ICommand::Params& aParams){
        return ICommand::SingleHandle( _createCommand(aName, aParams) );
    }
    
    MOCK_CONST_METHOD1( describe, std::string (std::string aName) );
    MOCK_CONST_METHOD1( knows, bool (const std::string& aCmdName) );
    
    MOCK_METHOD2( _addCreator, void (const std::string& aCmdName, ICommandCreator* aCreator));
    virtual void addCreator(const std::string& aCmdName, ICommandCreator::SingleHandle aCreator){
        _addCreator(aCmdName, aCreator.get());
    }
    
    MOCK_METHOD1( _removeCreator, ICommandCreator* (const std::string& aCmdName));
    virtual ICommandCreator::SingleHandle removeCreator(const std::string& aCmdName){
        return ICommandCreator::SingleHandle( _removeCreator(aCmdName) );
    }
};


#endif
