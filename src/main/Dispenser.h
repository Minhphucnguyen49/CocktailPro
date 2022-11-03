//@(#) Dispenser.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
* @class Dispenser
*
* @brief Klasse dosiert die Inhalte auf die Waage
*
* Die Inhalte werden auf die Waage gegeben (Funktion do It)
 * mit der Funktion update wird solange aktualisiert bis das richtige Gewicht erreicht ist
*
*/
class Dispenser : public InternalDevice, public Observer {
public:
  /** @brief The Construsctor
* @param [g] A float, which shows gramm per time
   * @param [ze] A int, which shows the time unit
   * @param [ninhalt] A String, whicch shows the ingredient
   * @param [wg] The scale to weigh
*
The method creates the additionalDispenser and maps the passed parameters
*/
  Dispenser(int g, int ze, const std::string &ninhalt, Waage * wg);
  /** @brief Checks whether the scale has reached the weight
* The method checks whether the scale has reached the weight and sets doinIt to false if the weight has been reached
*/
  virtual void update();
  /**
   * @brief function with which the dispension is startet
   * @param gramm amount to be dispensed
   * checks if the dispenser itself has enough remaining to dipense
   * if not, handles additional dispensers with same ingredient to dispense
   */
  void doIt(int gramm);
 /**
  * @brief dispensed the amount in parameter
  * @param gramm amount to dispense
  */
  void dispense(int gramm);

/** @brief getter for grams per time
* @return grams per time is returned.
*
* Grams per time is returned.
*/
  int getStueckProZeit() const;

  /**
   * @brief function for adding a duplicate additionalDispenser
   */
  void addDispenser();
  /**
   * @brief overrides putzen() from InternalDevice to check for additional Dispensers
   */
  void putzen() override;

  /**
   * @brief getter for gesamtgewicht
   * @return gesamtgewicht
   */
  int getGesamtgewicht() const;

  /**
   * setter for output
   * @param b value for output
   */
  void setOutput(bool b) {output = b;}
private:

/**
   * grammProZeit
* The number of grams put on the scale per time interval
*/
  int grammProZeit;
/**
 * gesamtgewicht
* The number of grams in the additionalDispenser
*/
  int gesamtgewicht=1000;



/**
* myWaage
* The scale is used for weighing
*/
  Waage * myWaage;

/**
* gewicht
* The weight that should land on the scale
*/
  int gewicht;
/**
* inhalt
* The content to be dosed
*/
  std::string inhalt;
  /**
   * @brief pointer to Dispenser with same content
   */
  Dispenser * additionalDispenser = nullptr;

  /**
   * variable to store wether object can output in doIt();
   */
  bool output = true;

};

#endif
