//@(#) Masher.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"
/**
 * @class Masher
*
* @brief Creates timer
*
* Timer is created
*
*/
class Masher : public InternalDevice {
public:
/** @brief Constructor
*
* Constructor of Masher
*/
  Masher();
/** @brief Creates timer
* @param [time] A float used as a time specification
*
* Method creates timer with time in milliseconds times 1000
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
