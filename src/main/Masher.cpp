//@(#) Masher.cpp


#include "Masher.h"

Masher::Masher() : InternalDevice() {
}

void Masher::doIt(int time) {
  needsCleaning = true;
  myTimer->sleep_in_intervals(time * SPEED_FACTOR);
    std::cout << std::endl;
}
