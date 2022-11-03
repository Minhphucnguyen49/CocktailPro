/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : RecipeBook.cpp
 *
 */

#include <algorithm>
#include <iostream>

#include "RecipeBook.h"

RecipeBook::RecipeBook() {
  m_Recipe.clear();
  readRecipes(fileName);
}

bool RecipeBook::readRecipes(std::string &fName) {

  std::fstream file (fName);

  if(file) {

    std::string zeile;

    // 1. Zeile ist Ueberschrift - Einlesen und wegwerfen!
    getline(file, zeile);
    // cout << zeile << endl;

    int counter = 0;

    while (getline(file, zeile)) {
      //      cout << zeile << endl;
      std::istringstream inputString(zeile);

      std::string Name;
      std::string Zutat;
      std::string tempstring;
      float Menge;

      Recipe* r1;

      r1 = new Recipe;

      // Aus istringstream Name einlesen mit Komma als Trennzeichen
      getline(inputString, Name, ';');
      // Weiter einlesen bis zum naechsten Trennzeichen (Zutat)
      r1->setName(Name);
      //cout << "Name: " << Name << endl;

      while (getline(inputString, Zutat, ';') && !Zutat.empty()) {
        // Weiter einlesen bis zum naechsten Trennzeichen (Menge)
        if (getline(inputString, tempstring, ';')) {
          std::istringstream(tempstring) >> Menge;
        }
        r1->appendStep(Zutat, Menge);
        //cout << " Zutat: " << Zutat << " Menge: " << Menge << "\n" << endl;
      }
      m_Recipe.emplace(counter++, r1);
    }

    /* Datei wieder schliessen */
    file.close();
    numberOfRecipies = counter;
    return true;

  } else {
    fillDefaultRecipes();
    return false;
  }
}

RecipeBook::~RecipeBook() {
  m_Recipe.clear();
}

int RecipeBook::getNumberOfRecipes() {
  return numberOfRecipies;
}

Recipe * RecipeBook::getRecipe(int i) {
  if (m_Recipe.find(i) == m_Recipe.end()) return nullptr;
  else {
    return m_Recipe.at(i);
  }
}

bool RecipeBook::deleteRecipe(int i) {
  if (m_Recipe.find(i) == m_Recipe.end()) {
    return false;
  } else {
    m_Recipe.erase(i);
    return true; // Success!
  }
}

void RecipeBook::fillDefaultRecipes(){
  Recipe* r1;
  int counter = 0;
  r1 = new Recipe;
  r1->setName("Caipirinha");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Cachaca", 5);
  r1->appendStep("Mischen", 10);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Margarita");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Tequilla", 4);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Daiquiri");
  r1->appendStep("Limettensaft", 2);
  r1->appendStep("Zuckersirup", 2);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Planters Punch");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Grenadine", 1);
  r1->appendStep("Orangensaft", 8);
  r1->appendStep("Rum braun", 6);
  r1->appendStep("Eis", 100);
  r1->appendStep("Mischen", 20);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Caipiroska");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Wodka", 5);
  r1->appendStep("Mischen", 10);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Caipirissima");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Mischen", 10);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Cuban Island");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Rum weiss", 2);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Eis", 30);
  r1->appendStep("Mischen", 30);
  m_Recipe.emplace(counter++, r1);

  r1 = new Recipe;
  r1->setName("Martini James B");
  r1->appendStep("Gin", 6);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Noilly Prat", 1);
  r1->appendStep("Schuetteln", 10);
  m_Recipe.emplace(counter++, r1);
}