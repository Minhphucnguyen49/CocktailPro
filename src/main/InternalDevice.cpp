//@(#) InternalDevice.cpp


#include "InternalDevice.h"
/* not used yet
void InternalDevice::setTimer() {

}
*/
InternalDevice::InternalDevice() {
    myTimer = Timer::getInstance();
    this->doinIt = 0;
}

void InternalDevice::putzen() {
  needsCleaning = false;
    //std::cout << "Ich putze mich..." << std::endl;
    //myTimer->sleep(500);
    //std::cout << "Ich bin fertig mit putzen!" << std::endl;
}
