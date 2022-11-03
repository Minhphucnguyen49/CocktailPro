#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "BarTender.h"
#undef protected
#undef private

#include <sstream>

class BarTenderTest: public ::testing::Test
{
 protected:
  AvailableIngredients *zv;
  BarTender *bt;
  DeviceVerwalter *dv;
  Timer * timer;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "BarTenderTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    timer = Timer::getInstance();
    timer->set_Turbo(10000);
    zv = new AvailableIngredients();
    dv = new DeviceVerwalter(zv);
    bt = new BarTender(dv);
    test_cout.str("");
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete zv;
    delete dv;
    delete bt;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "BarTenderTest" << std::endl << std::flush;
  }
};

TEST_F(BarTenderTest, zubereitungTest){
  test_cout.str("");
  Recipe* r1 = new Recipe;
  r1->setName("Caipirinha");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Cachaca", 5);
  r1->appendStep("Mischen", 10);

  bt->cocktailZubereiten(r1);
  std::string output = test_cout.str();
  //try to find the weight of the cocktail in the output
  EXPECT_EQ(!std::string::npos, output.find("Gesamtgewicht von 200g") == std::string::npos);


}

