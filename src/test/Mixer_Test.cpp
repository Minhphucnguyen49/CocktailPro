#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Mixer.h"
#undef protected
#undef private

#include <sstream>

class MixerTest: public ::testing::Test
{
 protected:
  Timer * timer;
  Mixer * mixer;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "MixerTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    timer = Timer::getInstance();
    timer->set_Turbo(10000);

    mixer = new Mixer();

  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete mixer;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "MixerTest" << std::endl << std::flush;
  }
};


TEST_F(MixerTest, doItTest){
  mixer->doIt(20);
  EXPECT_EQ(true, mixer->needsCleaning);
}
