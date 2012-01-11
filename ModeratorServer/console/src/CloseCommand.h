
#ifndef _CLOSECOMMAND_H_
#define _CLOSECOMMAND_H_

// needed for implementing ICommand and ICommandCreator
#include <ICommand.h>
#include <ACommand.h>
#include <ICommandCreator.h>

// needed by the CloseCommand itself
#include "Console.h"

/**
 * Command that echoes the parameters on the console
 */
class CloseCommand: public ACommand {
public:
    CloseCommand(IConsole& aConsole,const ICommand::Params& aParams)
        : ACommand(aParams), mConsole(aConsole){}
    
    virtual int execute()const{
        mConsole.stop();
        return 0;
    }
    
private:
    IConsole& mConsole;
};


class CloseCommandCreator: public ICommandCreator {
public:
    CloseCommandCreator(IConsole& aConsole): mConsole(aConsole){}
    
    virtual ICommand::SingleHandle create(const ICommand::Params& aParams){
        return ICommand::SingleHandle( new CloseCommand(mConsole, aParams) );
    }

    virtual std::string getDescription()const{
        return "closes the console";
    }
private:
    IConsole& mConsole;
};

#endif
