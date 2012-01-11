
#include <sstream>

#include "ConsoleMocks.h"

#include <ConsoleFacade.h>

class ConsoleFacadeShould : public testing::Test {
protected:
    ConsoleFacade mSubject;
};

TEST_F(ConsoleFacadeShould, createNonZeroStandardConsole) {
    std::auto_ptr<IConsole> con(mSubject.createStandardConsole());
    
    ASSERT_TRUE(0 != con.get());
}

TEST_F(ConsoleFacadeShould, createNonZeroConsole) {
    std::stringstream in,out;
    std::auto_ptr<IConsole> con(mSubject.createConsole(in, out, out, out));
    
    ASSERT_TRUE(0 != con.get());
}

TEST_F(ConsoleFacadeShould, createNonZeroInterpreter) {
    std::auto_ptr<IConsoleInterpreter> t(mSubject.createInterpreter());
    
    ASSERT_TRUE(0 != t.get());
}

TEST_F(ConsoleFacadeShould, createNonZeroFactory) {
    std::auto_ptr<IConfigurableCommandFactory> t(mSubject.createConfigurableCommandFactory());
    ASSERT_TRUE(0 != t.get());
}

TEST_F(ConsoleFacadeShould, createNonZeroEchoCommandCreator) {
    MockConsole con;
    ICommandCreator::SingleHandle t(mSubject.getEchoCmdCreator(con));
    ASSERT_TRUE(0 != t.get());
}

TEST_F(ConsoleFacadeShould, createNonZeroCloseCommandCreator) {
    MockConsole con;
    ICommandCreator::SingleHandle t(mSubject.getCloseCmdCreator(con));
    ASSERT_TRUE(0 != t.get());
}
