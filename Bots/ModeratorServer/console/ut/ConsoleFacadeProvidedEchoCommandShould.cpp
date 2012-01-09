
#include "ConsoleMocks.h"

#include <ConsoleFacade.h>

class ConsoleFacadeProvidedEchoCommandShould : public testing::Test {
protected:
    virtual void SetUp(){
        mConsole = new MockConsole();
        mSubject = mFacade.getEchoCmdCreator(*mConsole);
        
        mParams.addParameter("echo");
    }
    
    ICommandCreator::SingleHandle mSubject;
    
    ICommand::Params mParams;
    
    ConsoleFacade mFacade;
    Poco::SharedPtr<MockConsole> mConsole;
};

TEST_F(ConsoleFacadeProvidedEchoCommandShould, callConsolesEchoOnExecute) {
    using ::testing::_;

    EXPECT_CALL(*mConsole, echo(_)).Times(1);
    
    // action!
    ASSERT_EQ(mSubject->create(mParams)->execute(), 0);
}

TEST_F(ConsoleFacadeProvidedEchoCommandShould, echoTheFirstParameterOnly) {
    using ::testing::_;
    
    mParams.addParameter("1st");
    
    EXPECT_CALL(*mConsole, echo("1st")).Times(1);
    
    // action!
    ASSERT_EQ(mSubject->create(mParams)->execute(), 0);
}

TEST_F(ConsoleFacadeProvidedEchoCommandShould, echoTheParametersString) {
    using ::testing::_;
    
    mParams.addParameter("1st");
    mParams.addParameter("2nd");
    mParams.setParameterString("echo   1st   2nd");
    
    EXPECT_CALL(*mConsole, echo("echo   1st   2nd")).Times(1);
    
    // action!
    ASSERT_EQ(mSubject->create(mParams)->execute(), 0);
}
