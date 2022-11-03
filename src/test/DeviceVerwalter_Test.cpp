#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "DeviceVerwalter.h"
#undef protected
#undef private

#include <sstream>
#include <map>

class DeviceVerwalterTest: public ::testing::Test
{
 protected:
  Timer *timer;
  AvailableIngredients *zv;
  DeviceVerwalter * dv;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "DeviceVerwalterTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    timer = Timer::getInstance();
    timer->set_Turbo(100000);
    zv = new AvailableIngredients();
    dv = new DeviceVerwalter(zv);
    test_cout.str("");
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete zv;
    delete dv;
    //reset the timer's booster to 1
    timer->set_Turbo(1);

    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "DeviceVerwalterTest" << std::endl << std::flush;
  }
};

TEST_F(DeviceVerwalterTest, createDeviceTest){
  dv->createDevices();
  EXPECT_EQ("Cachaca", dv->myDevices->begin()->first);
}

TEST_F(DeviceVerwalterTest, rezeptSchrittTest){
  dv->rezeptSchrittZubereiten("Tequilla", 50);
  std::string output = test_cout.str();

  EXPECT_EQ(!std::string::npos, output.find("Es wurden 50g Tequilla abgefuellt") == std::string::npos);

}