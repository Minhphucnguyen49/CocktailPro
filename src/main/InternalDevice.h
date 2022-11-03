//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**

* @class InternalDevice
*
* @brief  Abstraction of dosers and processing units
*
* Cleaning process is probably started here
*
*/
class InternalDevice {
public:
  /** @brief Doin it

* Nothing happens
*/
    virtual void doIt(int value) = 0;
   /** @brief this is where the cleaning process should take place

* Nothing happens
*/
   virtual void putzen();

private:
  /** @brief the timer is to be set here

* Nothing is happening yet
*/
    //void setTimer();//not used yet


public:
  /** @brief Konstruktor

* Konstruktor
*/
    InternalDevice();
    /**
     * @brief getterfunction
     * @return value of needsCleaning
     */
    bool wasUsed(){return needsCleaning;};
protected:
  /**
Timeunit,is not used yet
*/
    int zeiteinheit = 0;
/**
* doinIt, is not used yet
*/
    bool doinIt = false;
/**
* Timer, is not used yet
*/
    Timer * myTimer;
    /**
     * @brief value to track if a device needs to be cleaned
     *
     * needs to be set true in doIt(), so the device is cleaned
     * is set false in InternalDevice::putzen()
     */
    bool needsCleaning = false;

};

#endif
