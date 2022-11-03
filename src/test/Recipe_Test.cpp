#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Recipe.h"
#undef protected
#undef private

#include <sstream>

class RecipeTest: public ::testing::Test
{
 protected:
  Recipe * recipe;
  std::basic_streambuf<char>* orig_cout;
  std::stringstream test_cout;

  void SetUp() override
  {
    // Check whether cout works normal - otherwise you will get very strange errors
    // if someone else made a mistake when redirecting cout
    std::cout << "Start of " << "RecipeTest" << std::endl << std::flush;

    // redirect cout to my test_cout stream for testing
    // and store orig cout for restoring after test (!!!do not forget to restore!!!)

    orig_cout = std::cout.rdbuf(test_cout.rdbuf());

    recipe = new Recipe();

  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(orig_cout); // redirect cout back to standard cout
    delete recipe;
    // Check whether cout works normal again - otherwise the next one using cout
    // will get very strange behavior
    std::cout << "End of " << "RecipeTest" << std::endl << std::flush;
  }
};

TEST_F(RecipeTest, getNoOfRecipeStepsTest) {
  recipe->appendStep("Zucker", 12);
  EXPECT_EQ(1, recipe->getNoOfRecipeSteps());
}

TEST_F(RecipeTest, getRecipeStepTest){
  recipe->appendStep("Eis", 12);
  EXPECT_EQ("Eis",  recipe->getRecipeStep(0)->getZutat());
}

TEST_F(RecipeTest, getNameTest){
  recipe->setName("Test");
  EXPECT_EQ("Test", recipe->getName());
}

TEST_F(RecipeTest, setNameTest){
  recipe->setName("Test");
  EXPECT_EQ("Test", recipe->m_Name);
}

TEST_F(RecipeTest, browseTest){
}

TEST_F(RecipeTest, appendStepTest){
  recipe->appendStep("Eis", 12);
  EXPECT_EQ("Eis",  recipe->getRecipeStep(0)->getZutat());
}

TEST_F(RecipeTest, doubleIngrdientsTest) {
  recipe->appendStep("Zutat", 10);
  recipe->appendStep("Mischen", 10);
  recipe->appendStep("Stampfen", 20);
  recipe->appendStep("Schuetteln", 30);
  recipe->changeIngredientsAmount(2);
  EXPECT_EQ(20, recipe->getRecipeStep(0)->getMenge());
  EXPECT_EQ(10, recipe->getRecipeStep(1)->getMenge());
  EXPECT_EQ(20, recipe->getRecipeStep(2)->getMenge());
  EXPECT_EQ(30, recipe->getRecipeStep(3)->getMenge());
}