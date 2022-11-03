#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <list>
#include <string>

/**
 * @class Recipe
 *
 * @brief Recipe manages a collection of recipeSteps
 *
 * A Recipe knows a list of recipeSteps
 * You can ask for the number of recipeSteps, query recipeSteps by index
 * or add a new recipeStep. 
 * You can ask for the name of the recipe or change it
 * You can look at all recipeSteps at onec 
 * 
 */

class Recipe {
private:
    /**
    * This is the list of recipeSteps that the Recipe manages
    */
    std::list<RecipeStep*> m_RecipeStep;

    /**
    * This is the name of the recipe
    */
    std::string m_Name;

public:
    /** @brief Construktor that creates a Recipe
    * @return A pointer to the created Recipe
    *
    * This method creates a blank Recipe.
    * It is created without a name or any recipeSteps
    * After creation it depends on the methods setName and appendStep
    * to get these information and to become usefull
    */
    Recipe();
    
    /** @brief Destructor that deletes the Recipe
    */
    ~Recipe();

    /** @brief Returns the number of recipeSteps
    * @return The number of recipeSteps in the Recipe
    */
    int getNoOfRecipeSteps();

    /** @brief fetches the i-th recipeStep
    * @param [in] i a positive integer for the i-th recipeStep
    * @return A pointer to the requested RecipeStep object, NULL for invalid i
    *
    * This method returns the i-th recipeStep;
    * where i is an integer from 0 to n-1
    * where n is the number of recipeSteps in the Recipe
    */
    RecipeStep * getRecipeStep(unsigned int i);

    /** @brief Returns the name of the Recipe
    * @return The name of the Recipe as string
    */
    std::string getName() const;

    /** @brief Changes the Recipename to its param
    * @param Name a const string reference for the name of the Recipe
    *
    * This method changes the Recipename to its parameter
    */
    void setName(const std::string& Name);

    /** @brief Adds a RecipeStep to the Recipes RecipeStep-list
    * @param z a string for the necessary ingredient
    * @param m a float for the necessary amount
    *
    * This method creates a new RecipeStep object from its parameters in heap and
    * adds a pointer to it to the Recipes RecipeStep-list
    */
    void appendStep(std::string z, float m);

    /** @brief Shows all RecipeSteps at onece
    *
    * This method iterates through all existing RecipeSteps in a Recipe and
     * - after printing the Recipes name - prints all of them
    */
    void browse();

  /**
   * mutiplies al ingredients with factor
   * @param factor value to multiply with
   */
  void changeIngredientsAmount(float factor);

};

#endif
