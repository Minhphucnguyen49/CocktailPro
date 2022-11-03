//
// Created by MP on 27.05.2022.
//

#include <limits.h>
#include "gtest/gtest.h"

#define private public
#include "Subject.h"
#undef private

 class SubjectTest : public ::testing::Test
 {
  protected:
   Subject* s;
   virtual  void SetUp()
   {
     s = new Subject();
     std::cout << "Start of " << "SubjectTest" << std::endl << std::flush;
   }
   virtual void TearDown()
   {
     delete s;
     std::cout << "End of " << "SubjectTest" << std::endl << std::flush;
   }
 };

TEST_F( SubjectTest, testAttach)
{
  Observer* o1;
  Observer* o2;
  Observer* o3;

  s->attach(o1);
  s->attach(o2);
  s->attach(o3);

  EXPECT_EQ(o1, s->observers.at(0));
}
/*
TEST_F( SubjectTest, testNotify)
{
  Observer* o1;
  Observer* o2;
  Observer* o3;

  s->attach(o1);
  s->attach(o2);
  s->attach(o3);

  s->notify();
  //How to check for .update()???
}
 */