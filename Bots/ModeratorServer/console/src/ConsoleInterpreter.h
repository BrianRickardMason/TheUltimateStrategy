
#ifndef _CONSOLEINTERPRETER_H_
#define _CONSOLEINTERPRETER_H_

#include <sstream>
#include <stdexcept>

#include <Poco/RegularExpression.h>

#include <IConsoleInterpreter.h>

class ConsoleInterpreter: public IConsoleInterpreter {
public:
    virtual bool interpret(const std::string& aInput, std::string& outName, ICommand::Params& outParams);

    virtual ~ConsoleInterpreter();
    
    ConsoleInterpreter();
protected:
    const std::string WHITE_SPACE_CHARS;
    const std::string TRIM_WS;
    const char COMMENT_MARK;
    
    const std::string COMMAND_ID;
    const std::string PARAMETER_ID;
    
    const std::string DQUOTED_STRING;
    const std::string SQUOTED_STRING;
    const std::string NONWS_STRING;
    const std::string PARAMETER_VALUE;
    const std::string PARAMETER_ASSIGN;
    
    const std::string PARAMETER;
    const std::string PARAMETERS;
    
    /// (\w+)((\s+((\w+)\s*(=)\s*)?("([^"]*)"|'([^']*)'|([^=\s]+)))+)
    const std::string COMMAND;
    
    const Poco::RegularExpression mTrimWsRe;
    const Poco::RegularExpression mCommandRe;
    const Poco::RegularExpression mParameterRe;
};

#endif
