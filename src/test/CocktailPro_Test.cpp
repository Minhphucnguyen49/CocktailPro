#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private

#include <sstream>

class CocktailProTest: public ::testing::Test
{
 protected:

  CocktailPro * cp;
  Timer * timer;

  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  std::basic_streambuf<char>* orig_cin;
  std::stringstream test_cin;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "CocktailProTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    orig_cin = std::cin.rdbuf(test_cin.rdbuf());

    timer = Timer::getInstance();

    test_cout.str("");
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    std::cin.rdbuf(orig_cin);
    delete cp;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "CocktailProTest" << std::endl << std::flush;
  }
};

TEST_F(CocktailProTest, constructorTest) {
  int argc = 0;
  char * argv[] = {NULL};
  cp = new CocktailPro(argc, argv);

  //check if all objects are created
  EXPECT_TRUE(nullptr != cp->pAvailableIngredients);
  EXPECT_TRUE(nullptr != cp->pBarTender);
  EXPECT_TRUE(nullptr != cp->pDeviceVerwalter);
  EXPECT_TRUE(nullptr != cp->pMixableRecipeBook);
  EXPECT_EQ(1, timer->booster);
}

TEST_F(CocktailProTest, constructorDebugTest) {
  int argc = 2;
  char * argv[] = {"2", "-D"};
  cp = new CocktailPro(argc, argv);

  //check if all objects are created
  EXPECT_TRUE(nullptr != cp->pAvailableIngredients);
  EXPECT_TRUE(nullptr != cp->pBarTender);
  EXPECT_TRUE(nullptr != cp->pDeviceVerwalter);
  EXPECT_TRUE(nullptr != cp->pMixableRecipeBook);
  //check if timer and OpMode is set correctly
  EXPECT_EQ(1000, timer->booster);
  EXPECT_TRUE(CocktailPro::DEMO == cp->OperatingMode);

  //check timerspeed for debugmode without fast turbo
  argv[1] = "\0";
  cp = new CocktailPro(argc, argv);
  EXPECT_EQ(10, timer->booster);
}

TEST_F(CocktailProTest, demoTest){
  cp = new CocktailPro(0, nullptr);
  timer->set_Turbo(100000);
  test_cout.str("");

  cp->demo();
  std::string output = test_cout.str();

  EXPECT_EQ(!std::string::npos, output.find("Caipirinha") == std::string::npos);
  EXPECT_EQ(!std::string::npos, output.find("Gesamtgewicht von 200g") == std::string::npos);
}

TEST_F(CocktailProTest, userSelectionTest){
  cp = new CocktailPro(0, nullptr);

  //function returns 1 when user inputs 1 or 6(min or max value)
  test_cin.str("1\n");
  int returnvalue = cp->userSelection();
  EXPECT_EQ(1, returnvalue);

  test_cin.str("6\n");
  returnvalue = cp->userSelection();
  EXPECT_EQ(6, returnvalue);

  //function returns -10 when user inputs 0 or >max value
  test_cin.str("9\n");
  returnvalue = cp->userSelection();
  EXPECT_EQ(-10, returnvalue);

  test_cin.str("0\n");
  returnvalue = cp->userSelection();
  EXPECT_EQ(-10, returnvalue);

  //function returns -20 when user's input == "stophappyhour"
  test_cin.str("stophappyhour\n");
  returnvalue = cp->userSelection();
  EXPECT_EQ(-20, returnvalue);

  test_cin.str("happyhour");
  returnvalue = cp->userSelection();
  EXPECT_EQ(-21, returnvalue);

}

TEST_F(CocktailProTest, validateUserInputTest) {
  cp = new CocktailPro(0, nullptr);

  //test valid inputs
  EXPECT_EQ(1, cp->validateUserInput(1, 6));
  EXPECT_EQ(6, cp->validateUserInput(6, 6));
  //test invalid inputs
  EXPECT_EQ(-10, cp->validateUserInput(0, 6));
  EXPECT_EQ(-10, cp->validateUserInput(7, 6));
}

TEST_F(CocktailProTest, startTest) {
  cp = new CocktailPro(0, nullptr);
  timer->set_Turbo(100000);
  test_cout.str("");
  std::string output;

  //test if we can exit the loop
  test_cin.str("-1\n");
  cp->start();
  EXPECT_TRUE(CocktailPro::STOP == cp->OperatingMode);

  //reset Operatingmode to NORMAL after stop in previous test;
  cp->OperatingMode = CocktailPro::NORMAL;

  //expect the function to create a Caipirinha with weight of 200g
  test_cout.str("");
  test_cin.str("1\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Gesamtgewicht von 200g") == std::string::npos);
  cp->OperatingMode = CocktailPro::NORMAL;

  //expect the function to display errormessage on invalid input
  test_cout.str("");
  test_cin.str("9\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("MEEEP!") == std::string::npos);
  cp->OperatingMode = CocktailPro::NORMAL;

  test_cout.str("");
  test_cin.str("happyhour\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Activiere") == std::string::npos);

  cp->OperatingMode = CocktailPro::HAPPYHOUR;
  test_cout.str("");
  test_cin.str("stophappyhour\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Deactiviere") == std::string::npos);
  cp->OperatingMode = CocktailPro::NORMAL;



  test_cout.str("");
  test_cin.str("3\n-1\n");
  cp->start();
  output = test_cout.str();
  EXPECT_EQ(!std::string::npos, output.find("Rezept Nummer 3 ist nicht verfügbar") == std::string::npos);
  cp->OperatingMode = CocktailPro::NORMAL;
}
