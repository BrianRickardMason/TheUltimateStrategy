
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <IConsole.h>

#include "ConsoleInterpreter.h"

class Console: public IConsole {
public:
    Console(std::istream& aInStream, std::ostream& aOutStream, std::ostream& aErrStream, std::ostream& aLogStream);

    virtual void setCommandFactory(ICommandFactory::Handle aFactory);
    
    virtual void run();
    
    virtual void stop();
    
    virtual void interpretLine();
    
    virtual void echo(const std::string& aString);
private:
    std::istream& mInStream;
    std::ostream& mOutStream;
    std::ostream& mErrStream;
    std::ostream& mLogStream;
    
    ConsoleInterpreter mInterpreter;
    ICommandFactory::Handle mCmdFactory;
    
    bool mRun;
    
    void debugCommand(const std::string& cmd, const ICommand::Params& par);
};

#endif

