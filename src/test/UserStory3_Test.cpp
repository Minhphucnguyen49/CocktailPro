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
#include "BarTender.h"
#include "DeviceVerwalter.h"
#include "InternalDevice.h"
#include "AvailableIngredients.h"
#include "Recipe.h"


#undef protected
#undef private

class UserStory3Test : public ::testing::Test {
 protected:

  Timer * timer;
  AvailableIngredients* availableIngredients;
  DeviceVerwalter* deviceVerwalter;
  BarTender* barTender;
  Recipe* recipe;

  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  virtual void SetUp() {
    std::cout << "Start of " << "UserStory3Test" << std::endl << std::flush;

    timer = Timer::getInstance();
    timer->set_Turbo(1000000);
    availableIngredients = new AvailableIngredients();
    availableIngredients->zutaten->clear();
    availableIngredients->zutaten->push_back("Test");
    availableIngredients->zutaten->push_back("Mischen");
    availableIngredients->zutaten->push_back("Stampfen");
    availableIngredients->zutaten->push_back("Schuetteln");

    availableIngredients->anzahlDosierer = availableIngredients->zutaten->size();
    deviceVerwalter = new DeviceVerwalter(availableIngredients);


    barTender = new BarTender(deviceVerwalter);

    recipe = new Recipe();

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    test_cout.str("");
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).

    delete recipe;
    delete barTender;
    delete deviceVerwalter;
    delete availableIngredients;

    timer->set_Turbo(1);

    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    std::cout << "End of " << "UserStory2Test" << std::endl << std::flush;
  }
};

TEST_F(UserStory3Test, restMengeZutaten)
{
  recipe->appendStep("Test",500);
  test_cout.str("");
  barTender->cocktailZubereiten(recipe);
  std::string output = test_cout.str();


  EXPECT_EQ(!std::string::npos, output.find("Rezeptschritt") == std::string::npos);
test_cout.str("");

  barTender->cocktailZubereiten(recipe);
  barTender->cocktailZubereiten(recipe);
output = test_cout.str();
EXPECT_EQ(!std::string::npos, output.find("Nicht mischbar!") == std::string::npos);

}
