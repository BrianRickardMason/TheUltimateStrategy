
#include "../include/ConsoleFacade.h"

#include <iostream>

#include "Console.h"
#include "EchoCommand.h"
#include "CloseCommand.h"
#include "ConfigurableCommandFactory.h"

IConsole* ConsoleFacade::createStandardConsole(){
    return new Console(std::cin, std::cout, std::cerr, std::clog);
}

IConsole* ConsoleFacade::createConsole(
        std::istream& aInStream, std::ostream& aOutStream, std::ostream& aErrStream, std::ostream& aLogStream){
    return new Console(aInStream, aOutStream, aErrStream, aLogStream);
}


ICommandCreator::SingleHandle ConsoleFacade::getEchoCmdCreator(IConsole& aConsole) {
    return ICommandCreator::SingleHandle(new EchoCommandCreator(aConsole));
}

ICommandCreator::SingleHandle ConsoleFacade::getCloseCmdCreator(IConsole& aConsole){
    return ICommandCreator::SingleHandle(new CloseCommandCreator(aConsole));
}

IConfigurableCommandFactory* ConsoleFacade::createConfigurableCommandFactory(){
    return new ConfigurableCommandFactory();
}

IConsoleInterpreter* ConsoleFacade::createInterpreter(){
    return new ConsoleInterpreter();
}
