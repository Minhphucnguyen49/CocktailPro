/*
 * File       : Mixer.cpp
 *
 */
#include "Mixer.h"

Mixer::Mixer() : InternalDevice() {

}

void Mixer::doIt(int time) {
  needsCleaning = true;
  myTimer->sleep_in_intervals(time * SPEED_FACTOR);
    std::cout << std::endl;
}
