//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>

/**
 * @class Timer
 *
 * @brief Timer controls time of the machine
 *
 * 
 */
class Timer {
 public:

  /** @brief sets Turbo from a given value
  * @param [in] turbo a integer - input of this method
  * @return nothing
  *
  * This method assigns the given turbo to the attribute booster
  */
  void set_Turbo(int turbo);

  /** @brief returns thetimer = new Timer();
  * @return A pointer of type Timer
  *
  * This method returns a pointer to object Timer
  */
  static Timer * getInstance();

  /**
   * 	~Timer( )
   *     {
   *         instanceFlag = false;
   *     };
   */

  /** @brief
  * @param [in] milliseconds
  *
  */
  void sleep_in_intervals(long milliseconds);

  /** @brief
  * @param [in] delay_in_ms
  *
  */
  void sleep(long delay_in_ms);


 private:

  /**
 * This is for a particular purpose
 * but I do not know it, apart from being set to true
 * in every case
 *
 */
  static bool instanceFlag;

  /**
  * This is a static pointer of type Timer
  *
  */
  static Timer * theTimer;

  /**
  * This is booster - to do what?
  *
  */
  int booster;

  /**
  * This is a private constructor
  * it initialises attribute booster with value 1
  *
  */
  Timer() : booster(1) {
  };

};

#endif
