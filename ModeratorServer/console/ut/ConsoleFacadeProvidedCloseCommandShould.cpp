#include "ConsoleMocks.h"

#include <ConsoleFacade.h>

class ConsoleFacadeProvidedCloseCommandShould : public testing::Test {
protected:
    virtual void SetUp(){
        mConsole = new MockConsole();
        mSubject = mFacade.getCloseCmdCreator(*mConsole);
        
        mParams.addParameter("close");
    }
    
    ICommandCreator::SingleHandle mSubject;
    
    ICommand::Params mParams;
    
    ConsoleFacade mFacade;
    Poco::SharedPtr<MockConsole> mConsole;
};

TEST_F(ConsoleFacadeProvidedCloseCommandShould, callStopConsoleOnExecute) {
    using ::testing::_;
    
    EXPECT_CALL(*mConsole, stop()).Times(1);
    
    // action!
    ASSERT_EQ(mSubject->create(mParams)->execute(), 0);
}
