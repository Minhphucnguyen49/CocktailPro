//
// Created by TR on 20.06.2022.
//
#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "AvailableIngredients.h"
#include "Dispenser.h"
#include "DeviceVerwalter.h"
#include "Recipe.h"
#include "BarTender.h"
#include "CocktailPro.h"
#undef protected
#undef private

class Userdemo_P7 : public ::testing::Test {
 protected:
  Timer * timer;

  std::basic_streambuf<char>* orig_cin;
  std::stringstream test_cin;

  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  virtual void SetUp() {
    std::cout << "Start of " << "UserStory4Test\n\n" << std::flush;

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());
    orig_cin = std::cin.rdbuf(test_cin.rdbuf());
    timer = Timer::getInstance();
    timer->set_Turbo(1'000'000);

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout);
    std::cin.rdbuf(orig_cin);
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    std::cout << "End of " << "Userdemo_P7" << std::endl << std::flush;
  }
};

TEST_F(Userdemo_P7, userdemo)
{
  //create AvailableIngredients, replace Ingredients from file
  AvailableIngredients * zv = new AvailableIngredients();
  zv->zutaten->clear();
  zv->zutaten->push_back("Gin");
  zv->zutaten->push_back("Gin");
  zv->zutaten->push_back("Gin");
  zv->zutaten->push_back("Wodka");
  zv->zutaten->push_back("Noilly Prat");
  zv->zutaten->push_back("Noilly Prat");
  zv->zutaten->push_back("Mischen");
  zv->zutaten->push_back("Stampfen");
  zv->zutaten->push_back("Schuetteln");

  //create Deviceverwalter with Testingredients
  DeviceVerwalter *dv = new DeviceVerwalter(zv);

  Recipe *r1 = new Recipe();
  r1->setName("Martini James B");
  r1->appendStep("Gin", 1200);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Noilly Prat", 1);
  r1->appendStep("Schuetteln", 10);

  BarTender *bt = new BarTender(dv);

  std::cout.rdbuf(orig_cout);
  std::cout<<"Cocktail normal zubereiten\n\n";
  bt->cocktailZubereiten(r1);
  std::cout<<"\n\nsetze Wodka Restmenge auf 1\n";
  dynamic_cast<Dispenser *>(dv->myDevices->at("Wodka"))->gesamtgewicht = 1;

  std::cout<<"Cocktailzubereitung mit zu wenig Zutaten\n\n";
  bt->cocktailZubereiten(r1);

  delete zv;
  delete dv;
  delete bt;
  delete r1;
}