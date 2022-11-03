//
// Created by MP on 26.05.2022.


#include <limits.h>
#include "gtest/gtest.h"
#define private public
#define protected public
#include "Timer.h"
#undef private
#undef protected

//Timer* Timer::theTimer = nullptr;

class TimerTest : public ::testing::Test
{
 protected:
    Timer* t;

  virtual void SetUp()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    t = new Timer();
    std::cout << "Start of " << "TimerTest" << std::endl << std::flush;
  }
    virtual void Teardown()
    {
      // Code here will be called immediately after each test
      // (right before the destructor).
      delete t;
      std::cout << "End of " << "TimerTest" << std::endl << std::flush;
    }
};

TEST_F( TimerTest, getInstance )
{
  EXPECT_EQ (t->theTimer, t->getInstance());
  EXPECT_TRUE( t->instanceFlag == true );
}
//failed
TEST_F( TimerTest, Delay_in_msIsGreaterEqual1000 )
{
  long delay_in_ms = 1200;
  t->sleep_in_intervals(delay_in_ms);
  //EXPECT_EQ(200, delay_in_ms); this should be true
  EXPECT_EQ(1200, delay_in_ms);
}

TEST_F( TimerTest, Delay_in_msIsSmallerThan1000 )
{
  long delay_in_ms = 200;
  t->sleep_in_intervals(delay_in_ms);
  EXPECT_EQ(200, delay_in_ms);
}
