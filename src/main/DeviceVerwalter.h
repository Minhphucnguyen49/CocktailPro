//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "AvailableIngredients.h"
#include "Dispenser.h"
#include "Mixer.h"
#include "Masher.h"
#include "Shaker.h"
#include "Drainer.h"
#include "Waage.h"

/*
 * Befuellt die Dispenser, verwaltet die Interne Hardware
 *  
 */
/**
 * @class DeviceVerwalter
 *
 * @brief DeviceVerwalter manages the internal hardware components
 *
 * A DeviceVerwalter knows all devices, the available ingredients
 *
 */
class DeviceVerwalter {
 private:
  /** @brief Changes pAvailableIngredients to its param
  * @param ze a pointer to a AvailableIngredients object that contains all available ingredients
  *
  * This method changes pAvailableIngredients to its parameter
  */
  void setZutatenVerwalter(AvailableIngredients * ze);

  /**
  * This is the used mixer
  */
  Mixer * myMixer;

  /**
  * This is the used masher
  */
  Masher * myStampfer;

  /**
  * This is the used shaker
  */
  Shaker * mySchuettler;

  /**
  * These are the avalable ingredients
  */
  AvailableIngredients * myZutatenVerwalter;

  /**
  * This is the used scale
  */
  Waage * theWaage;

  /** @brief  creates new objects for all devices and saves
*             them in pairs with a keyword in the map "myDevices"
  *
  * creates one new objects for Mixer,Masher,Shaker,Waage,Drainer
  * creates one new Dispenser object for every ingredient
  * saves all new device objects in map "myDevices" with keyword
  * (for Dispenser the ingredient name is the keyword)
  */
  void createDevices();

 public:
    /** @brief Constructor that creates a DeviceVerwalter
    * @param ze a pointer to a AvailableIngredients object
    * @return A pointer to the created DeviceVerwalter
    *
    * This method creates a blank DeviceVerwalter.
    * It sets the private pAvailableIngredients to its parameter ze
    * It calls the createDevices method
    */
    explicit DeviceVerwalter(AvailableIngredients * ze);


    /** @brief calls doIt-function in the Dispenser that is necessary for the given ingredient
    * @param zutat a string with the name of the ingredient
    * @param menge a float for the amount of the ingredient
    *
    * This method finds the right Dispenser for the griven ingredient (zutat)
    * and calls its doIt-function with the amount (menge) as parameter
    * [special case: "Limettenstuecke"]
    */
    void rezeptSchrittZubereiten(std::string zutat, float menge);

    /**
    * This is the used drainer
    */
    Drainer * myEntleerer;

    /**
    * These are the used devices and their keywords
    */
    std::map<std::string, InternalDevice*>* myDevices;

};

#endif
