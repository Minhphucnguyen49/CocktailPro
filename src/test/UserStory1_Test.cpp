//
// Created by MP on 17.06.2022.
//
#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "RecipeBook.h"
#include "CocktailPro.h"
#undef protected
#undef private

class UserStory1Test : public ::testing::Test {
 protected:
  CocktailPro * cp;
  Timer * timer;

  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  std::basic_streambuf<char>* orig_cin;
  std::stringstream test_cin;

  virtual void SetUp() {
    std::cout << "Start of " << "UserStory1Test" << std::endl << std::flush;

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    orig_cin = std::cin.rdbuf(test_cin.rdbuf());

    timer = Timer::getInstance();

    test_cout.str("");

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    std::cin.rdbuf(orig_cin);
    delete cp;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    std::cout << "End of " << "UserStory1Test" << std::endl << std::flush;
  }
};

TEST_F(UserStory1Test, deleteRecipe)
{
  cp = new CocktailPro(0, nullptr);
  timer->set_Turbo(100000);
  test_cout.str("");
  std::string output;

  //create Cocktail nr5
  test_cin.str("5\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Ich habe Ihre Bestellung: Caipiroska erhalten.") == std::string::npos);
  bool firstPassed = output.find("Ich habe Ihre Bestellung: Caipiroska erhalten.") == std::string::npos;
  cp->OperatingMode = CocktailPro::NORMAL;
  test_cout.str("");


  //delete 2 recipes
  cp->pMixableRecipeBook->deleteRecipe(1);
  cp->pMixableRecipeBook->deleteRecipe(2);

  //reorder cocktail nr5 to and check if the same cocktail was produced
  test_cin.str("5\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Ich habe Ihre Bestellung: Caipiroska erhalten.") == std::string::npos);
  bool secondPassed = output.find("Ich habe Ihre Bestellung: Caipiroska erhalten.") == std::string::npos;
  cp->OperatingMode = CocktailPro::NORMAL;

  EXPECT_EQ(firstPassed, secondPassed);


}