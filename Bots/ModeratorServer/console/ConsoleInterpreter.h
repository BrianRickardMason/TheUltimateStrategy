
#ifndef _CONSOLEINTERPRETER_H_
#define _CONSOLEINTERPRETER_H_

#include <sstream>
#include <stdexcept>

#include <Poco/RegularExpression.h>

#include "include/IConsoleInterpreter.h"

class ConsoleInterpreter: public IConsoleInterpreter {
public:
    virtual bool interpret(const std::string& aInput, std::string& outName, ICommand::Params& outParams);

    virtual ~ConsoleInterpreter(){}
    
    ConsoleInterpreter():
        WHITE_SPACE_CHARS(" \t\r\n"),
        TRIM_WS        ("\\s*(\\S.*)"),
        COMMENT_MARK   ('#'),
        COMMAND_ID     ( "\\w+" ),
        PARAMETER_ID   ( "\\w+" ),
        DQUOTED_STRING ( "\"([^\"]*)\"" ),
        SQUOTED_STRING ( "'([^']*)'" ),
        NONWS_STRING   ( "([^=\\s]+)" ),
        PARAMETER_ASSIGN("="),
        PARAMETER_VALUE ( DQUOTED_STRING +"|"+ SQUOTED_STRING +"|"+ NONWS_STRING  ),
        PARAMETER       ( "\\s+(("+ PARAMETER_ID +")\\s*("+ PARAMETER_ASSIGN +")\\s*)?("+ PARAMETER_VALUE +")"  ),
        PARAMETERS      ( "("+ PARAMETER +")*"  ),
        COMMAND         ( "("+ COMMAND_ID +")("+ PARAMETERS +")"  ),
        mTrimWsRe   (TRIM_WS,   0, true),
        mCommandRe  (COMMAND,   0,true),
        mParameterRe(PARAMETER, 0,true)
    {}
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

bool ConsoleInterpreter::interpret(const std::string& aInput, std::string& outName, ICommand::Params& outParams) {
    if (outParams.count()>0) {
        throw std::runtime_error("Params already set");
    }
    
    std::vector <std::string> extracted;
    extracted.reserve(16);
    
    if( ! mTrimWsRe.split(aInput, extracted)){
        return false;
    }
    
    std::string input = extracted[1];
    if (input.empty() || input[0] == COMMENT_MARK) {
        return false;
    }
    
    mCommandRe.split(input, extracted);
    
    outName = extracted[1];
    std::string params = extracted[2];
    
    outParams.addParameter(outName);
    
    size_t offset = 0;
    while (offset < params.size()) {
        mParameterRe.split(params, offset, extracted);
        
        std::string& name  = extracted[2];
        std::string& value = extracted.back();
        
        if (!name.empty()) {
            outParams.addParameter(name, value);
        } else {
            outParams.addParameter(value);
        }

        offset += extracted[0].size();
    }
    
    // left trim params before passing the whole parameter string
    mTrimWsRe.split(params, extracted);
    params = extracted[1];
    
    // size_t firstNonWs = params.find_first_not_of(WHITE_SPACE_CHARS);
    // if(std::string::npos != firstNonWs){
        // params = params.substr(firstNonWs);
    // }
    
    outParams.setParameterString(params);
    return true;
}

#endif
