//@(#) Masher.cpp

#include "gtest/gtest.h"

#define protected public
#define private public
#include "Masher.h"
#undef protected
#undef private

#include <sstream>
class MasherTest: public ::testing::Test {
 protected:
Timer * myTimer;
Masher * masher;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;
  void SetUp() override {

    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "MasherTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)
    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    myTimer = Timer::getInstance();
    myTimer->set_Turbo(10000);

    masher = new Masher();

  }


    virtual void TearDown()
    {
      // Code here will be called immediately after each test
      // (right before the destructor).
      std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
      delete masher;
      //reset the timer's booster to 1
      myTimer->set_Turbo(1);
      // Check whether cout works normal again - otherwise the next one using cout
      // will get very strange behavior
      std::cout << "End of " << "MasherTest" << std::endl << std::flush;
    }
  };

TEST_F(MasherTest, doItTest){
  masher->doIt(20);
  EXPECT_EQ(true, masher->needsCleaning);
}

