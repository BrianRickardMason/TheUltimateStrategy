
#include "Console.h"

void Console::debugCommand(const std::string& cmd, const ICommand::Params& par) {
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

Console::Console(std::istream& aInStream, std::ostream& aOutStream, std::ostream& aErrStream, std::ostream& aLogStream)
:
    mInStream(aInStream), mOutStream(aOutStream), mErrStream(aErrStream), mLogStream(aLogStream),
    mRun(false) {
}

void Console::setCommandFactory(ICommandFactory::Handle aFactory){
    mCmdFactory = aFactory;
}

void Console::run() {
    mRun = true;
    while(mRun) {
        interpretLine();
    }
}

void Console::stop() {
    mRun = false;
}

void Console::interpretLine(){
    std::string line;
    std::getline(mInStream,line);

    std::string cmd;
    ICommand::Params par;
    bool interpreted = mInterpreter.interpret(line, cmd, par);
    
    if(!interpreted) return;
    
    debugCommand(cmd,par);
    
    if(mCmdFactory && mCmdFactory->knows(cmd)){
        mCmdFactory->createCommand(cmd,par)->execute();
    }
}

void Console::echo(const std::string& aString){
    mOutStream << aString << std::endl;
}
