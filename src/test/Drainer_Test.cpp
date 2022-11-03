#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Drainer.h"
#undef protected
#undef private

#include <sstream>

class DrainerTest: public ::testing::Test
{
 protected:
  Timer * timer;
  Drainer * drainer;
  Waage * waage;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "DispenserTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    timer = Timer::getInstance();
    timer->set_Turbo(10000);

    waage = new Waage();
    drainer = new Drainer(1, 250, waage);

  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete waage;
    delete drainer;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "DispenserTest" << std::endl << std::flush;
  }
};

TEST_F(DrainerTest, doItTest){
  drainer->doIt(20);
  EXPECT_EQ(-1, waage->getDelta());
}

TEST_F(DrainerTest, checkWaageTest){
  drainer->checkWaage();
  EXPECT_EQ(0, drainer->doinIt);
}


TEST_F(DrainerTest, updateTest){
  drainer->doIt(20);
  drainer->update();

  EXPECT_EQ(0, drainer->doinIt);

}