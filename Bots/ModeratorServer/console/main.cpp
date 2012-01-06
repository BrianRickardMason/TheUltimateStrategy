
#include <algorithm>
#include <iterator>
#include <iostream>

#include <Poco/RegularExpression.h>

#include "ConsoleInterpreter.h"
#include "Console.h"

#include "ConfigurableCommandFactory.h"

using namespace Poco;
using namespace std;

class ACommand: public ICommand {
public:
    virtual const std::string& getName()const{
        return mParameters[0];
    }
    virtual const Params& getParams()const{
        return mParameters;
    };
protected:
    ACommand(const Params& aParams)
    : mParameters(aParams){}
    
    const Params mParameters;
};

class EchoCommand: public ACommand {
public:
    EchoCommand(Console& aConsole,const ICommand::Params& aParams)
        : 
            ACommand(aParams), mConsole(aConsole){
    }
    
    virtual int execute()const{
        if(mParameters.count() == 2){
            mConsole.echo(mParameters[1]);
        } else {
            mConsole.echo(mParameters.getParameterString());
        }
        return 0;
    }
    
private:
    Console& mConsole;
};


class EchoCommandCreator: public ICommandCreator {
public:
    EchoCommandCreator(Console& aConsole): mConsole(aConsole){}
    
    virtual ICommand::SingleHandle create(const ICommand::Params& aParams){
        return ICommand::SingleHandle( new EchoCommand(mConsole, aParams) );
    }

    virtual std::string getDescription()const{
        return "displays message";
    }
private:
    Console& mConsole;
};

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