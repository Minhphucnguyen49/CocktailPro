/*
 * File       : Recipe.cpp
 *
 */
#include <algorithm>
#include <iostream>
#include <utility>

#include "Recipe.h"

Recipe::Recipe() {
    m_RecipeStep.clear();
    m_Name = "";          //Recipe objekt wird zunächst mit "leerem" namens-string erstellt
}

Recipe::~Recipe() = default;

int Recipe::getNoOfRecipeSteps() {
  return m_RecipeStep.size();
}

RecipeStep * Recipe::getRecipeStep(unsigned int i) {
    if (i > m_RecipeStep.size()) return nullptr;
    else {
        std::list<RecipeStep*>::iterator p; // Iterator
        advance(p = m_RecipeStep.begin(), i); // p zeigt jetzt auf das i-te Element
        return (*p); // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
    }
}

std::string Recipe::getName() const {
    return m_Name;
}

void Recipe::setName(const std::string& Name) {
    this->m_Name = Name;
}

void Recipe::browse() {
    std::cout << m_Name << ": ";
    for (int i = 0; i< this->getNoOfRecipeSteps(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << getRecipeStep(i)->getZutat();
    }
}

void Recipe::appendStep(std::string z, float m) {
    RecipeStep* t;
    t = new RecipeStep; //neues RecipeStep objekt wird erstellt
    //std::string zRef = z;
    t->setZutat(std::move(z));
    t->setMenge(m);
    m_RecipeStep.push_back(t);
}
void Recipe::changeIngredientsAmount(float factor) {
  for (auto i: m_RecipeStep) {
    std::string zutat = i->getZutat();
    if (zutat != "Schuetteln" && zutat != "Mischen" && zutat != "Stampfen")
      i->setMenge(i->getMenge()*factor);
  }
}
