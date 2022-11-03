//
// Created by MP on 18.06.2022.
//
#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public

#include "Dispenser.h"
#include "Waage.h"
#include "Timer.h"


#undef protected
#undef private

class UserStory2Test : public ::testing::Test {
 protected:
  Dispenser* dispenser;
  Waage* waage;
  Timer * timer;

  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  virtual void SetUp() {
    std::cout << "Start of " << "UserStory2Test" << std::endl << std::flush;

    waage = new Waage;
    dispenser = new Dispenser(5, 1000, "testzutat", waage);
    timer = Timer::getInstance();
    timer->set_Turbo(1000000);

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    test_cout.str("");

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete waage;
    delete dispenser;
    timer->set_Turbo(1);

    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout

    std::cout << "End of " << "UserStory2Test" << std::endl << std::flush;
  }
};

TEST_F(UserStory2Test, restMenge)
{
  dispenser->gesamtgewicht = 1000;
  test_cout.str("");
  dispenser->doIt(100);
  std::string output = test_cout.str();

  EXPECT_EQ(!std::string::npos, output.find("900g") == std::string::npos);

  test_cout.str("");
  dispenser->doIt(90);
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("810g") == std::string::npos);

  dispenser->gesamtgewicht = 1000;

  EXPECT_EXIT(dispenser->doIt(100'000), testing::ExitedWithCode(0), "");
}
