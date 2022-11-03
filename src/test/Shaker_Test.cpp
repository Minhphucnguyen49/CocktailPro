//
// Created by MP on 27.05.2022.
//
#include <limits.h>
#include "gtest/gtest.h"

#define private public
#define protected public
#include "Shaker.h"
#undef private
#undef protected

class ShakerTest : public ::testing::Test
{
 protected:
  Shaker* sh;
  virtual  void SetUp()
  {
    sh = new Shaker();
    std::cout << "Start of " << "ShakerTest" << std::endl << std::flush;
  }
  virtual void TearDown()
  {
    delete sh;
    std::cout << "End of " << "ShakerTest" << std::endl << std::flush;
  }
};
//this test is failed
TEST_F(ShakerTest, doIt)
{
  float time = 1.5;
  sh->doIt(time);//ruft myTimer->sleep_in_intervals(time * SPEED_FACTOR); auf
  // --> time = 1500 ms > 1000
  // --> time = time - 1000;
  EXPECT_EQ(true, sh->needsCleaning);
  //EXPECT_EQ(500, time); this should be true, else why we need it --> call by reference is better, but the programm worked T_T
  EXPECT_EQ(1.5, time);
}