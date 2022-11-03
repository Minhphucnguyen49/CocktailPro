//
// Created by MP on 27.05.2022.
//

#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!

#define private public
#include "Waage.h"

#undef private

class WaageTest : public ::testing::Test
{
  protected:
  Waage* w;
  virtual void SetUp()
  {
    w = new Waage();
    std::cout << "Start of " << "WaageTest" << std::endl << std::flush;
  }
  virtual void TearDown()
  {
    delete w;
    std::cout << "End of " << "WaageTest" << std::endl << std::flush;

  }
};

TEST_F( WaageTest, testChangeWeight1)
{
  int v = 5;
  int delta = w->deltaweight + v;
  w->changeWeight(v);
  EXPECT_EQ(delta, w->deltaweight);

}

TEST_F( WaageTest, testChangeWeight2)
{
  int v = 0;
  w->changeWeight(v);
  if(w->weight == 0)
  {
    EXPECT_EQ(0, w->weight);
  }
}
TEST_F( WaageTest, testTara)
{
  int t = w->tara();
  EXPECT_EQ(0, w->deltaweight);
  EXPECT_EQ(t, w->deltaweight);
}

TEST_F( WaageTest, getWeight)
{
  EXPECT_EQ(w->deltaweight, w->getWeight());
}
TEST_F( WaageTest, getDelta)
{
  EXPECT_EQ(w->deltaweight, w->getDelta());
}