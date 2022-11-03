//@(#) AvailableIngredients.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

#include <iostream>

/**
 * @class AvailableIngredients
 * @brief creates list with all available ingredients
 */
class AvailableIngredients {
 public:
  /**
   * @brief Constructor
   * creates new vector for ingerdients
   * @see calls ZutatenDateiEinlesen(std::string)
   * @see calls browse(void)
   * consoleoutput with all ingerdients
   * adds 2 Stampfen und Mischen to ingredient vector
   */
    AvailableIngredients();
    /**
     * deconstructor
     */
    virtual ~AvailableIngredients();
    /**
     * @brief Copy Constructor
     */
    AvailableIngredients(const AvailableIngredients&) = delete;

    /**
     * @brief consoleoutput of all ingredients
     */
    void browse();

    /**
     * @brief getter for Zutat
     * @param [in] i index in vector
     * @return std::string with name of ingredient
     */
    std::string getZutat(size_t i);
    /**
     * @brief returns number of ingredients
     * @return int number of ingredients
     */
    size_t getAnzahlVorhandeneZutaten();

 private:
  /**
   * @brief vector for storing ingedients
   */
  std::vector<std::string>* zutaten;
  /**
   * @brief variable for debugmode
   */
  //ungenutzte variable/ private, keine getter/setter
  static const bool DEBUG = false;
  /**
   * @brief fills ingredient vector with ingredients for debugmode
   */
   //void DummyZutatenEinfuegen();
  /**
   * @brief reads file containing ingredients
   * @param [in] std::string mit Dateinamen
   */
  virtual void ZutatenDateiEinlesen(std::string &fName);
  /**
   * @brief count of ingredients
   */
   //kann man auch direkt aus zutaen auslesen
   //wird nie genutzt
  size_t anzahlDosierer;

};
/**
 * @brief variable for storing filename
 */
static std::string fileName = "zutaten.txt";
#endif
