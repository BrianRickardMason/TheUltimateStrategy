
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
