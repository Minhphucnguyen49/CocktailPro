//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

/**
 * @class Mixer
 *
 * @brief Child class from InitialDivice class
 * that overwrites one virtual method "doIt"
 *
 * Simulates the mixing process by waiting for a given amount of time
 */

class Mixer : public InternalDevice {
 private:
  /**
* SPEED_FACTOR
* milliseconds
*/
  static const int SPEED_FACTOR=1000;

 public:

    /** @brief Construktor that creates a Mixer object
    * @return A pointer to the created Mixer
    *
    * This method creates a Mixer object. (Default construktor)
    */
    Mixer();

    /** @brief waits to simulate mixing process
    * @param  time a positive float for the amount of seconds to wait
    *
    * This method waits for the amount of time specified in its parameter to simulate
    * the mixing process
    */
    void doIt(int time);


};

#endif
