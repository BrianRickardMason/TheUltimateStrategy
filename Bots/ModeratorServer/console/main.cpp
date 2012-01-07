
#include <iostream>

#include "ConsoleInterpreter.h"
#include "Console.h"

#include "ConfigurableCommandFactory.h"
#include "EchoCommand.h"

using namespace Poco;
using namespace std;

int main(){
    
    std::string subject = "foo bar=blurp meh ra=\"bar bar\" kapow=':D' 'lol' \"rotfl\"";
    ConsoleInterpreter ci;
    
    std::string name;
    ICommand::Params params;

    ci.interpret(subject, name, params);
    
    for(int i=0; i<params.count(); ++i){
        std::clog << i << ": " << params[i] << std::endl;
    }
    
    Console con(cin,cout,cerr,clog);
    
    ConfigurableCommandFactory *ccf = new ConfigurableCommandFactory;
    ICommandFactory::Handle ccfh(ccf);
    
    ccf->addCreator( "echo", ICommandCreator::SingleHandle(new EchoCommandCreator(con)) );
    
    con.setCommandFactory(ccfh);
    
    con.interpretLine();
    
    return 0;
}