//@(#) MixableRecipeBook.cpp


#include "MixableRecipeBook.h"
#include <iostream>
//

void MixableRecipeBook::browse() {
  std::cout << "*********************************************" << std::endl;
  std::cout << "Es gibt " << this->m_Recipe.size() << " Cocktails" << std::endl;

  for (auto i: m_Recipe) {
    std::cout << i.first + 1 << ". ";
    i.second->browse();
    std::cout << std::endl;
  }
  std::cout << "*********************************************" << std::endl;

}

MixableRecipeBook::MixableRecipeBook(AvailableIngredients * zv) : pAvailableIngredients(zv) {

  // Debug *********
  std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
  browse();
  // ******************

  for (int i = 0; i < getNumberOfRecipes(); ++i) {
    //geht rezepte durch
    bool x = true;
    Recipe *r = getRecipe(i);

    for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
      //geht rezeptschritte durch
      std::string gesuchteZutat;

      //vergleicht zurtaten
      gesuchteZutat = r->getRecipeStep(j)->getZutat();
      bool zOk = false;

      for (size_t k = 0; k < pAvailableIngredients->getAnzahlVorhandeneZutaten(); k++) {
        //geht zutaten durch
        if (pAvailableIngredients->getZutat(k) == gesuchteZutat) {
          //wenn gesuchte zutat vorhanden ist abbrechen
          zOk = true;
          break;
        }
      }
      if (!zOk) {
        x = false;
      }
    }
    if (!x) {
      //wenn zutat im rezept nicht vorhanden wird das rezept gelöscht
      deleteRecipe(i);
    }
  }
}
void MixableRecipeBook::multiplyAllIngredients(float factor) {
  for (auto i: m_Recipe) {
    i.second->changeIngredientsAmount(factor);
  }
}

