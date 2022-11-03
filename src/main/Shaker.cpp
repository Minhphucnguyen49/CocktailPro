//@(#) Shaker.cpp

//Test Kommentar SK

#include "Shaker.h"

Shaker::Shaker() : InternalDevice() {
}

void Shaker::doIt(int time) {
  /** myTimer is a pointer of type Timer     
  * Timer * myTimer; 
  * declared in class InternalDevice.h
  * 
  * Calls function sleep_in_intervals(long milliseconds); in class Timer.h
  */
  needsCleaning = true;
  myTimer->sleep_in_intervals(time * SPEED_FACTOR);
  std::cout << std::endl;
}
