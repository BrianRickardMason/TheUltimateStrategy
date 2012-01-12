
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include <iostream>

#include <IConsole.h>
#include <ConsoleFacade.h>

using namespace Poco;
using namespace std;

void manual(){
    ConsoleFacade c;
    
    std::string subject = "foo bar=blurp meh ra=\"bar bar\" kapow=':D' 'lol' \"rotfl\"";
    Poco::SharedPtr<IConsoleInterpreter> ci(c.createInterpreter());
    
    std::string name;
    ICommand::Params params;

    ci->interpret(subject, name, params);
    
    for(int i=0; i<params.count(); ++i){
        std::clog << i << ": " << params[i] << std::endl;
    }
    
    Poco::SharedPtr<IConsole> con(c.createStandardConsole());
    IConfigurableCommandFactory::Handle ccfh(c.createConfigurableCommandFactory());
    
    ccfh->addCreator( "echo", c.getEchoCmdCreator(*con) );
    
    con->setCommandFactory(ccfh);
    
    con->interpretLine();
}