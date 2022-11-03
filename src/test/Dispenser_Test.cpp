#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Dispenser.h"
#undef protected
#undef private

#include <sstream>

class DispenserTest: public ::testing::Test
{
 protected:
  Timer * timer;
  Dispenser * dispenser;
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
    dispenser = new Dispenser(1, 250, "Testzutat", waage);

  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete waage;
    delete dispenser;
    //reset the timer's booster to 1
    timer->set_Turbo(1);
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "DispenserTest" << std::endl << std::flush;
  }
};

TEST_F(DispenserTest, doItTest){
  dispenser->addDispenser();
  dispenser->doIt(700);
  EXPECT_EQ(700, waage->getWeight());

  dispenser->doIt(500);
  EXPECT_EQ(1200, waage->getWeight());
  EXPECT_EQ(200, waage->getDelta());

}

TEST_F(DispenserTest, stueckProZeitTest){
  EXPECT_EQ(1, dispenser->getStueckProZeit());
}

TEST_F(DispenserTest, updateTest){
  dispenser->dispense(20);
  dispenser->update();

  EXPECT_EQ(false, dispenser->doinIt);

}

TEST_F(DispenserTest, addDispenserTest) {
  EXPECT_EQ(true, dispenser->additionalDispenser == nullptr);
  dispenser->addDispenser();
  EXPECT_EQ(false, dispenser->additionalDispenser == nullptr);
  EXPECT_EQ(dispenser->inhalt, dispenser->additionalDispenser->inhalt);
}

TEST_F(DispenserTest, getGesamtgewichtTest) {
  dispenser->addDispenser();
  EXPECT_EQ(2000, dispenser->getGesamtgewicht());

}

TEST_F(DispenserTest, putzenTest) {
  Dispenser * dispenserPutzen = new Dispenser(1, 250, "Testzutat", waage);
  dispenserPutzen->addDispenser();

  //only use first dispenser
  dispenserPutzen->doIt(10);
  EXPECT_EQ(true, dispenserPutzen->needsCleaning);
  EXPECT_EQ(false, dispenserPutzen->additionalDispenser->needsCleaning);
  dispenserPutzen->putzen();
  EXPECT_EQ(false, dispenserPutzen->needsCleaning);
  EXPECT_EQ(false, dispenserPutzen->additionalDispenser->needsCleaning);

  //use both dispensers
  dispenserPutzen->doIt(1000);
  EXPECT_EQ(true, dispenserPutzen->needsCleaning);
  EXPECT_EQ(true, dispenserPutzen->additionalDispenser->needsCleaning);
  dispenserPutzen->putzen();
  EXPECT_EQ(false, dispenserPutzen->needsCleaning);
  EXPECT_EQ(false, dispenserPutzen->additionalDispenser->needsCleaning);

  //only use second dispenser
  dispenserPutzen->doIt(10);
  EXPECT_EQ(false, dispenserPutzen->needsCleaning);
  EXPECT_EQ(true, dispenserPutzen->additionalDispenser->needsCleaning);
  dispenserPutzen->putzen();
  EXPECT_EQ(false, dispenserPutzen->needsCleaning);
  EXPECT_EQ(false, dispenserPutzen->additionalDispenser->needsCleaning);

  delete dispenserPutzen;
}

TEST_F(DispenserTest, dispenseTest) {
  dispenser->dispense(100);
  EXPECT_EQ(true, dispenser->needsCleaning);
  EXPECT_EQ(900, dispenser->gesamtgewicht);
  EXPECT_EQ(100, waage->getWeight());

}