#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <iostream>

#include <map>
#include <string>

#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook manages a collection of recipes
 *
 * A RecipeBook knows a list of recipes
 * You can ask for the number of recipes, query recipes by index
 * or delete a recipe
 *
 */
class RecipeBook {
 protected:
  /**
    * This is the list of recipes that the RecipeBook manages
    *
    */
  std::map<int, Recipe *> m_Recipe;

  private:
    /**
     *  file where recipies are stored
     */
     std::string fileName = "Rezepte.csv";
     int numberOfRecipies;

  public:
    /** @brief Construktor that creates a RecipeBook
    * @return A pointer to the created RecipeBook
    *
    * This method creates a RecipeBook.
    * It uses temporarily an object of the class Initialisierer
    * to initialize the list of recipes. After that the
    * Initialisierer is destroyed.
    */
    RecipeBook();

    /** @brief Destructor that deletes the RecipeBook
    */
    virtual ~RecipeBook();

    /** @brief Returns the number of recipes
    * @return The number of recipes in the RecipeBook
    */
    int getNumberOfRecipes();

    /** @brief fetches the i-th recipe
    * @param [in] i a positive integer for the i-th recipe
    * @return A pointer to the requested recipe object, NULL for invalid i
    *
    * This method returns the i-th recipe;
    * where i is an integer from 0 to n-1
    * where n is the number of recipes in the RecipeBook
    */
    Recipe * getRecipe(int i);

    /** @brief Deletes the i-th recipe from the RecipeBook
    * @param [in] i a positive integer for the i-th recipe
    * @return Boolean that indicates whether the deletion was successful
    *
    * This method deletes the i-th recipe from the RecipeBook.
    * And returns true if the deletion was successful (valid i).
    * For values of i that are invalid (i <0 or i>=n) the function return false.
    */
    bool deleteRecipe(int i);

    /**
     * @brief reads Rezepte.csv and fills the RecipeBook
     */
  //void readRecipes();
  bool readRecipes(std::string &fName);

  /**
   * This method fills recipe manually incase the reading data of recept.csv fails
   */
  void fillDefaultRecipes();
};

#endif
