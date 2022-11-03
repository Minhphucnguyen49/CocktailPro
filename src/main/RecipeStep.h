#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 *
 * @brief RecipeStep implements a specific recipe
 *
 * A RecipeStep is a series of steps that can be used to produce a desired Cocktail
 */
class RecipeStep {
 private:
    /**
   * This is a string of one ingredient that will be used to make a cocktail
   */
    std::string m_Zutat;

   /**
   * This float variable will be used to save a needed amount of each ingredient  
   */
    float m_Menge;

 public:
    /** @brief Constructor that creates a RecipeStep
    * void indicates explicitly that there is no parameter in this method
    * @return A pointer to the created RecipeStep
    *
    * This method creates a RecipeStep.
    * It uses temporarily an object of the class Initialisierer
    * to initialize the list of recipes. After that the
    * Initialisierer is destroyed.
    */
    RecipeStep();

    /** @brief Destructor that deletes the RecipeStep
    */
    ~RecipeStep();

    /** @brief returns m_Zutat
    * void indicates explicitly that there is no parameter in this method
    * @return A string of the ingredient
    *
    * This method is constant which means that 
    * it promises not to alter any members of the class
    */
    std::string getZutat() const;

    /** @brief returns m_Menge
    * void indicates explicitly that there is no parameter in this method
    * @return A float of the required amount of ingredient
    *
    * This method is constant which means that 
    * it promises not to alter any members of the class
    */
    float getMenge() const;

    /** @brief sets the ingredient with a given one
    * @param [in] zutat is the input (the given ingredient) of this method
    * @return void because it is a setter
    *
    */
    void setZutat(std::string zutat);

    /** @brief sets the amount of ingredient with a given one
    * @param [in] m_Menge is the input (the given amount) of this method 
    * @return void because it is a setter
    *
    */
    void setMenge(float m_Menge);

};
#endif
