
#ifndef _CONSOLEFACADE_H_
#define _CONSOLEFACADE_H_

#include "IConsole.h"
#include "ICommandCreator.h"
#include "IConfigurableCommandFactory.h"
#include "IConsoleInterpreter.h"

class ConsoleFacade {
public:
    IConsole* createStandardConsole();
    IConsole* createConsole(std::istream& aInStream, std::ostream& aOutStream, std::ostream& aErrStream, std::ostream& aLogStream);

    ICommandCreator::SingleHandle getEchoCmdCreator(IConsole& aConsole);
    ICommandCreator::SingleHandle getCloseCmdCreator(IConsole& aConsole);
    
    IConfigurableCommandFactory* createConfigurableCommandFactory();
    IConsoleInterpreter* createInterpreter();
};

#endif
