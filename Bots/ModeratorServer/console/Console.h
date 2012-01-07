

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "include/ICommandFactory.h"
#include "ConsoleInterpreter.h"

class Console {
public:
    Console(std::istream& aInStream, std::ostream& aOutStream, std::ostream& aErrStream, std::ostream& aLogStream)
    :
        mInStream(aInStream), mOutStream(aOutStream), mErrStream(aErrStream), mLogStream(aLogStream),
        mRun(false) {
    }

    void setCommandFactory(ICommandFactory::Handle aFactory){
        mCmdFactory = aFactory;
    }
    
    void run() {
        mRun = true;
        while(mRun) {
            interpretLine();
        }
    }
    
    void stop() {
        mRun = false;
    }
    
    void interpretLine(){
        std::string line;
        std::getline(mInStream,line);
    
        std::string cmd;
        ICommand::Params par;
        bool interpreted = mInterpreter.interpret(line, cmd, par);
        
        if(!interpreted) return;
        
        debugCommand(cmd,par);
        
        if(mCmdFactory->knows(cmd)){
            mCmdFactory->createCommand(cmd,par)->execute();
        }
    }
    
    void echo(const std::string& aString){
        mOutStream << aString << std::endl;
    }
private:
    std::istream& mInStream;
    std::ostream& mOutStream;
    std::ostream& mErrStream;
    std::ostream& mLogStream;
    
    ConsoleInterpreter mInterpreter;
    ICommandFactory::Handle mCmdFactory;
    
    bool mRun;
    
    void debugCommand(const std::string& cmd, const ICommand::Params& par) {
        mLogStream << "Command: " << cmd << std::endl;
        mLogStream << "Parameters: " << par.getParameterString() << std::endl;
        
        for(int i=0; i<par.count(); ++i){
            mLogStream << i << ": " << par[i] << std::endl;
        }
        
        std::vector<std::string> p = par.getKeys();
        for(int i=0; i<p.size(); ++i){
            mLogStream << p[i] << ": " << par[p[i]] << std::endl;
        }
    }
};

#endif

