//@(#) Drainer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"
/**
* @class Drainer
*
* @brief Empties the scale until a certain weight is reached
*
* The contents are taken off the scale (do it function)
 * the update function is used until the correct weight is reached

*
*/
class Drainer : public InternalDevice, public Observer {
public:
  /** @brief Constructor of Class
* @param [g] The float indicates the grams per time
   * @param [ze] Shows the Time Unit
   * @param [wg] Scale
*
* The values are assigned in the constructor
*/
    Drainer(float g, int ze, Waage * wg);
  /** @brief Standard constructor
*
* Constructor without parameters
*/
    ~Drainer();
  /** @brief Checks whether the scale has reached the weight
* @return Nothing is returned
*
* The method checks whether the scale has reached the weight
* and sets doinIt to 0 if the weight has been reached
*/
    void update();
/** @brief Sets the variable DoinIt to 1 and fills it in according to grams per time and time unit
* @param [nvalue] Wird dem Wert Value zugeordnet
*
* The scale is emptied until doinIt is set to 0
 */
    void doIt(int nvalue);

private:
  /**
 * gramm Pro Zeit
* The number of grams put on the scale per time interval
*/
    float grammProZeit;
/**
* Waage
* The scale is used for weighing
*/
    Waage * myWaage;
/**
* Value
* Has no specific function in this class
*/
    float value;
  /** @brief Checks the Waage
* @return nothing
*
* Checks if the weight form the Scale
*/
  void checkWaage();
};

#endif
