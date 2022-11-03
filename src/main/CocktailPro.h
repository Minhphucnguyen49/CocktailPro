//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "AvailableIngredients.h"
#include "MixableRecipeBook.h"
#include "BarTender.h"
#include "memory"


/**
 * Gesamtsystem
 *@class CocktailPro
 *
 *@brief start of process
 *
 * creation of devices
 * selection of cocktailnumber
 */
class CocktailPro {
 protected:

 //https://stackoverflow.com/questions/147572/will-the-below-code-cause-memory-leak-in-c
  /**
   * "Minh Phuc" - concluded from the above mentioned link
   * one of the effective approach (avoid leaking data/memory) is to use smart pointer
   * BUT ...
   * It could lead to a great deal of unnecessary workload
   * --> Better to write a destructor T_T
   */

  /*
  * @see object of BarTender
  */
  //std::shared_ptr<BarTender> pBarTender;
  BarTender * pBarTender;// potential of data leak
  /**
  * @see object of DeviceVerwalter
  */
  //std::shared_ptr<DeviceVerwalter> pDeviceVerwalter;
  DeviceVerwalter * pDeviceVerwalter;// potential of data leak
  /**
  * @see object of MixableRecipeBook
  */
  MixableRecipeBook * pMixableRecipeBook;
  /**
  *@see object of AvailableIngredients
  */
  //std::shared_ptr<AvailableIngredients> pAvailableIngredients;
  AvailableIngredients * pAvailableIngredients;// potential of data leak
  /**
   * OpMode enumerator for different operationmodes
   */
  enum OpMode {NORMAL, DEMO, STOP, HAPPYHOUR};

  /**
   * sets initial OpMode to Normal
   */
  OpMode OperatingMode = NORMAL;

  /**
  *@brief userSelection() reads userinput for cocktailselection
  *@return int with userinput
  */
  int userSelection();

  /**
  *@brief same as start() but everything is preselected
  *@see start()
  */
  void demo();

  /** @brief function checks if userinput is in valid range for cocktailselection
   *
   * @param zahl number from userinput
   * @param max number of available cocktails
   * @return -10 on invalid inputs(selection out of range) or the number from userinput
   */
  int validateUserInput(int zahl, int max) const;

 public:
  /**
  *@brief contructror
  *@param argc variable to start debugmode
  *@param turbo parameter for debugsettings
   *
   * initialisation of Devices
  */
  CocktailPro(int argc, char * * turbo);

  /**@brief Destructror
   * to avoid data as well as memory leak
   *
   */
  ~CocktailPro();

  /**
  *@brief startfunction
   * @see reads userinput with userSelection()
   * @see checks input and starts the process in BarTender
  */
  void start();

  /** @brief Copy constructor
   * is recommended since the class contains a pointer to allocated memory.
   * @param other is the right value of the copy
   *
   *
   * We can also use = delete to specify that you don’t want the compiler to generate that function
   * automatically. In another way, = delete means that the compiler will not generate those
   * constructors when declared and this is only allowed on copy constructor and assignment operator.
   */
  CocktailPro(const CocktailPro& other) = delete;






};

#endif
