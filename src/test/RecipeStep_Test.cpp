//
// Created by MP on 27.05.2022.
//
#include <limits.h>
#include "gtest/gtest.h"
#define private public
#include "RecipeStep.h"
#undef private

class RecipeStepTest : public ::testing::Test
{
 protected:
  RecipeStep* r;
  virtual  void SetUp()
  {
    r = new RecipeStep();
    std::cout << "Start of " << "RecipeStepTest" << std::endl << std::flush;
  }
  virtual void TearDown()
  {
    delete r;
    std::cout << "End of " << "RecipeStepTest" << std::endl << std::flush;
  }
};
TEST_F(RecipeStepTest, getZutat_const)
{
  EXPECT_EQ(r->m_Zutat, r->getZutat());
}
TEST_F(RecipeStepTest, getMenge_const)
{
  EXPECT_EQ(r->m_Menge, r->getMenge());
}
TEST_F(RecipeStepTest, setZutat)
{
  std::string m_zutat_in = "abc";
  r->setZutat(m_zutat_in);
  EXPECT_TRUE(m_zutat_in == r->m_Zutat);

}
TEST_F(RecipeStepTest, setMenge)
{
  float m_Menge_test = 19;
  r->setMenge(m_Menge_test);
  EXPECT_EQ(m_Menge_test, r->m_Menge);
}
