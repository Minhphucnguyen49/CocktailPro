#include <limits.h>
#include "gtest/gtest.h"

// Using this ugly tweak you make all private elements public!
// But be careful! Some methods are private for good reasons!
// So please use this trick only if you really need it!
#define protected public
#define private public
#include "RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test {
 protected:
  RecipeBook* r;

  virtual void SetUp() {
        r = new RecipeBook();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
        
        r->m_Recipe.clear();// clear all elements in the list
        Recipe* r1;

        r1 = new Recipe;
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
        r->m_Recipe.emplace(0, r1);

        r1 = new Recipe;
        r1->setName("Margarita");
        r1->appendStep("Zitronensaft", 2);
        r->m_Recipe.emplace(1, r1);
    std::cout << "Start of " << "RecipeBookTest" << std::endl << std::flush;
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete r;
    std::cout << "End of " << "RecipeBookTest" << std::endl << std::flush;
  }
};

TEST_F(RecipeBookTest,getNumberOfRecipesReturnsValueOfAttribute){

    EXPECT_EQ(8,r->getNumberOfRecipes());
}

TEST_F(RecipeBookTest,getRecipeReturnsCorrectRecipe){
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Caipirinha");

    rez = r->getRecipe(1);
    EXPECT_EQ(rez->getName(),"Margarita");
}

TEST_F(RecipeBookTest,deleteRecipeRemovesCorrectRecipe){
    EXPECT_FALSE(r->deleteRecipe(-1));
    EXPECT_FALSE(r->deleteRecipe(42));
    EXPECT_FALSE(r->deleteRecipe(2)); 
    
    EXPECT_TRUE(r->deleteRecipe(0));
    //check if its really deleted
    EXPECT_EQ(nullptr, r->getRecipe(0));
}

TEST_F(RecipeBookTest, fillDefaultTest) {
  r->m_Recipe.clear();
  r->fillDefaultRecipes();
  EXPECT_EQ("Caipirinha", r->m_Recipe[0]->getName());
  EXPECT_EQ("Martini James B", r->m_Recipe[7]->getName());

}

TEST_F(RecipeBookTest, readZutaten_Else_test)
{
  std::string wrongFile= "Rezepte_false.csv";
  EXPECT_FALSE(r->readRecipes(wrongFile));
}