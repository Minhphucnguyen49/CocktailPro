//@(#) MixableRecipeBook.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "AvailableIngredients.h"

#include <iostream>
#include <fstream>
#include <string>

/**

* @class MixableRecipeBook
*
* @brief Shows recipes
*
 *  Knows and Shows the mixable recipies
*
*/
class MixableRecipeBook : public RecipeBook {
public:
  /** @brief Constructor for MixableRecipeBook
 */
  explicit MixableRecipeBook(AvailableIngredients * ze);
  /** @brief Durch die Rezepte suchen.
 *
 * The function outputs the number of recipes and the recipes
 */
    void browse();

    /**
     * @brief multiplies all ingredients in all recipies by factor
     * @param factor value to multiply with
     */
    void multiplyAllIngredients(float factor);

private:
  /**
* Zutatenverwalter
*/
    AvailableIngredients * pAvailableIngredients{};
  /**
* Alle rezepte
*/
    std::vector<Recipe *> rezepte;
};

#endif
