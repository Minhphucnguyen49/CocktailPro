
#include <algorithm>
#include <utility>

#include "RecipeStep.h"

/**
 * Konstruktor 
 *  
 */
RecipeStep::RecipeStep()
:m_Zutat(""),m_Menge(0) {

}

RecipeStep::~RecipeStep() = default;

std::string RecipeStep::getZutat() const {
    return m_Zutat;
}

float RecipeStep::getMenge() const {
    return m_Menge;
}

void RecipeStep::setZutat(std::string zutat) {
    this->m_Zutat = std::move(zutat);
}

void RecipeStep::setMenge(float m_Menge_in) {
    this->m_Menge = m_Menge_in;
}
