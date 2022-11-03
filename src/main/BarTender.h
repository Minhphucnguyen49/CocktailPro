//@(#) BarTender.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

/**
 * Gesamtsystem
 *@class BarTender
 *
 *@brief prepares recipesteps and hands them to DeviceVerwalter
 */
class BarTender {
public:
  /**
  *@brief constructor
  */
  explicit BarTender(DeviceVerwalter * dv);
  /**
   * @brief prepares recipesteps and hands them to DeviceVerwalter
   * @param rzpt pointer to Recipe object
   * @return true
   *
   * console output to user
   * separation of recipe into steps
   * @see handing of recipestep to DeviceVerwalter
   * cleanup of devices
   */
  bool cocktailZubereiten(Recipe * rzpt);

private:
  /**
   * @brief @see pointer to DeviceVerwalter object
   */
  DeviceVerwalter * myDeviceVerwalter;


};

#endif
