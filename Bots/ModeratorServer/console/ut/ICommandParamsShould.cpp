
#include "ConsoleMocks.h"

#include <ConsoleFacade.h>

class ICommandParamsShould : public testing::Test {
protected:
    ICommand::Params mSubject;
    
    void prepareFirstNamed(){
        mSubject.addParameter("zero");
        mSubject.addParameter("first","one");
    }
};

TEST_F(ICommandParamsShould, preserveParamsString) {
    mSubject.setParameterString("foo-bar");
    ASSERT_EQ(mSubject.getParameterString(), "foo-bar");
}

TEST_F(ICommandParamsShould, createKeysForUnnamedParameters) {
    mSubject.addParameter("zero");
    mSubject.addParameter("one");
    
    ASSERT_EQ("zero", mSubject.getParameter(0));
    ASSERT_EQ(mSubject.getParameter("_0="), mSubject.getParameter(0));
    
    ASSERT_EQ("one", mSubject.getParameter(1));
    ASSERT_EQ(mSubject.getParameter("_1="), mSubject.getParameter(1));
}

TEST_F(ICommandParamsShould, allowToAccessNamedParameterByIndex) {
    prepareFirstNamed();
    
    ASSERT_EQ("one", mSubject.getParameter(1));
    ASSERT_EQ(mSubject.getParameter("_1="), mSubject.getParameter(1));
    ASSERT_EQ(mSubject.getParameter("first"), mSubject.getParameter(1));
}

TEST_F(ICommandParamsShould, provideGoodParameterCount) {
    prepareFirstNamed();
    
    ASSERT_EQ(2, mSubject.count());
}

TEST_F(ICommandParamsShould, throwOnBadParameterAccess) {
    prepareFirstNamed();
    
    EXPECT_THROW(mSubject[3], std::out_of_range);
}

TEST_F(ICommandParamsShould, throwOnBadKeyAccess) {
    prepareFirstNamed();
    
    EXPECT_THROW(mSubject["foobar"], std::out_of_range);
}
