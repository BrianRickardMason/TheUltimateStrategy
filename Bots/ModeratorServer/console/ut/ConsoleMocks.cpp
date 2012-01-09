
#include "ConsoleMocks.h"

MockCommand::MockCommand(const ICommand::Params& aParams): ACommand(aParams){}
MockCommand::~MockCommand() {}
MockCommandCreator::MockCommandCreator() {}
MockCommandCreator::~MockCommandCreator() {}
MockCommandFactory::MockCommandFactory() {}
MockCommandFactory::~MockCommandFactory() {}
MockConfigurableCommandFactory::MockConfigurableCommandFactory() {}
MockConfigurableCommandFactory::~MockConfigurableCommandFactory() {}
MockConsole::MockConsole() {}
MockConsole::~MockConsole() {}
MockConsoleInterpreter::MockConsoleInterpreter() {}
MockConsoleInterpreter::~MockConsoleInterpreter() {}
