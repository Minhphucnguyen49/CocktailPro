//@(#) Shaker.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"

/**
 * @class Shaker
 *
 * @brief Shaker implements the action of mixture
 *
 * It sets time for the Shaker
 * which is an important componant of the mixture machine
 */
class Shaker : public InternalDevice {
public:

    /** @brief Constructor that deploys a Shaker
    * @return A pointer to the created Shaker
    *
    * This method creates a Shaker object.
    * The weird thing (or it should be like that but I haven't understood yet)
    * is that there is no Destructor
    */
    Shaker();

    /** @brief set time of sleep from a given time 
    ** @param [in] time indicates the given time
    * @return void because it does something but not returns anything
    *
    * This method set a sleep time for the Shaker 
    * by calling a function sleep_in_intervals(long milliseconds) defined in class Timer
    */
    void doIt(int time);

private:
  /**
* SPEED_FACTOR
* milliseconds
*/
  static const int SPEED_FACTOR=1000;
};

#endif
